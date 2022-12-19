/**
 * @file main.cpp
 * @brief fichier main
 * @author Groupe 4
 * @bug On passe tous les circuits sauf le 11
 */
/*Include*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <istream>
#include <iterator>
#include <queue>

/*Classes*/
#include "Composant.h"
#include "Net.h"
#include "Evenement.h"
#include "Input.h"
#include "Output.h"
#include "PorteNOT.h"
#include "PorteAND.h"
#include "PorteNAND.h"
#include "PorteOR.h"
#include "PorteNOR.h"
#include "PorteXOR.h"
#include "PorteNAND3.h"


using namespace std;

/**
* @brief Fonction qui regarde dans le vector de net si le net existe deja et le renvoi sinon cree un nouveau net et le renvoi
* @return retourne le net
*/
/*Fonction qui regarde dans le vector de net si le net existe deja et le renvoi sinon cree un nouveau net et le renvoi*/
Net * retourneNet(vector<Net*> * nets , string netId){
    Net * a =NULL;
    for (unsigned i = 0; i<nets->size(); i++){
        if(nets->at(i)->getNetId() == netId){
            a = nets->at(i);
        }
    }
    if(a == NULL){
        a = new Net(netId,'U');
        nets->push_back(a);
    }
    return a;
}

/**
* @brief Fonction qui permet de lire le fichier .cir
* @return retourne une queue de vecteur contenant les infos du .cir
*/
/*Fonction qui permet de lire le fichier .cir*/
queue<vector<string> > lecturecir(string nomfichier){
    queue<vector<string> > IN;
    ifstream File("Simu/"+nomfichier+".cir", ios::in);
    if (File.is_open()){
        //net noeud; // Inutile ?
        string mot;
        while (!File.eof()){
            getline(File,mot,'\n');
            stringstream ss(mot);
            istream_iterator<string> begin(ss);
            istream_iterator<string> end;
            vector<string> vstrings(begin, end);
            IN.push(vstrings);
        }
    }
    File.close();
    return IN;
}

/**
* @brief Fonction qui affiche le contenu du fichier .cir
*/
/*Fonction qui affiche le contenu du fichier .cir*/
void afficheFichierCir(queue<vector<string> > v){
    queue<vector<string> > v_copy = v;
    vector<string> temp;
    while (!v_copy.empty()){
        temp = v_copy.front();
        for (unsigned i = 0; i<temp.size(); i++){
            cout << temp[i] << ' ';
        }
        cout << endl;
        v_copy.pop();
    }
}

/**
* @brief Fonction qui affiche queue contenant les informations du fichier .cir
*/
/*Fonction qui affiche queue contenant les informations du fichier .cir*/
void afficheQueue(queue<Evenement> q){
    Evenement ev_temp;
    queue<Evenement> Q_IO_copy;
    Q_IO_copy = q;
    while (!Q_IO_copy.empty()){
        ev_temp = Q_IO_copy.front();
        cout << ev_temp << endl;
        Q_IO_copy.pop();
    }
}

/**
* @brief Fonction qui lit et affiche le contenu d'un .stm
* @return retourne les stimulis dans une chaine de caractère
*/
/*Fonction qui lit et affiche le contenu d'un .stm*/
string lecturestimuli(string fichier){
    string res;
    ifstream File("Simu/"+fichier+".stm", ios::in);
    if (File.is_open()){
        int i = 0;
        string mot;
        while (!File.eof()){
            getline(File,mot);
        }
        while (mot[i]!='\0'){
            if (mot[i] == '-'){
                res += '1';
            }
            else {
                res += '0';
            }
            i++;
        }
    }
    return res;
}

/**
* @brief Creation de la pile d'evenement I/O
* @return retourne la pile d'evenement I/O
*/
/*Creation de la pile d'evenement I/O*/
queue<Evenement> creationPileIO(queue<vector<string> > v,vector<Net*> * inputNets,string fichier){
    queue<vector<string> > v_copy = v;
    string res;
    vector<string> stimuli;
    vector<string> temp;
    vector<Net*> nets;
    queue<Evenement> Q_IO;

    int j = 0;
    int time = 0;
    while(!v_copy.empty()){
        temp = v_copy.front();
        if (temp[2] == "INPUT"){
            res = lecturestimuli(fichier+'_'+temp[0]);
            stimuli.push_back(res);
            Net * n = retourneNet(inputNets,temp[1]);
            nets.push_back(n);
        }
        v_copy.pop();
    }
    //-------------------------Gestion de la pile des I/O---------------------
    j = 0;
    time = 0;
    while (stimuli[0][j]!='\0'){
        for (unsigned i = 0; i<stimuli.size(); i++){
            Q_IO.push(Evenement(time,nets[i],stimuli[i][j]));
        }
        j++;
        time += 1000;
    }
    return Q_IO;
}

/**
* @brief Fonction qui reconstruit le circuit de composant à partir de notre queue contenu les infos du .cir
*/
/*Fonction qui reconstruit le circuit de composant à partir de notre queue contenu les infos du .cir*/
void creeComposant(queue<vector<string>> V, vector<Composant*> * comps,vector<Composant*> * compsOut, vector<Net*> * inputNets,vector<Net*> * nets){
    queue<vector<string> > v_copy = V;
    vector<string> temp;

    while (!v_copy.empty()){
        temp = v_copy.front();
        if(!temp.empty()){ // Le cas ou le vecteur n'est pas vide pour ne pas prendre en compte les retour a la ligne stocker
            if(temp.back() == "INPUT"){
                Net *a = retourneNet(nets,temp[1]);         //Cree le net pour le composant
                inputNets->push_back(a);                    //Ajout le net au input principale du circuit pour faciliter les evenement
                Composant * c1 = new Input(temp[0]);        //cree le composant input
                c1->compAddOutput(a);                       //ajoute le net a en output du composant input
                comps->push_back(c1);                       //ajoute le composant a la liste des composants du circuit
            }
            else if(temp.back() == "OUTPUT"){
                Net *a = retourneNet(nets,temp[1]);
                //outputNets->push_back(a);
                Composant * c1 = new Output(temp[0]);
                c1->compAddInput(a);
                comps->push_back(c1);
                compsOut->push_back(c1);
            }
            else if(temp.back() == "NOT"){
                Composant *c1 = new PorteNOT(temp[0]);
                Net *a = retourneNet(nets,temp[1]);
                Net *b = retourneNet(nets,temp[2]);
                c1->compAddInput(a);
                c1->compAddOutput(b);
                comps->push_back(c1);
            }
            else if(temp.back() == "AND"){
                Composant *c1 = new PorteAND(temp[0]);
                Net *a = retourneNet(nets,temp[1]);
                Net *b = retourneNet(nets,temp[2]);
                Net *c = retourneNet(nets,temp[3]);
                c1->compAddInput(a);
                c1->compAddInput(b);
                c1->compAddOutput(c);
                comps->push_back(c1);
            }
            else if(temp.back() == "NAND"){
                Composant *c1 = new PorteNAND(temp[0]);
                Net *a = retourneNet(nets,temp[1]);
                Net *b = retourneNet(nets,temp[2]);
                Net *c = retourneNet(nets,temp[3]);
                c1->compAddInput(a);
                c1->compAddInput(b);
                c1->compAddOutput(c);
                comps->push_back(c1);
            }
            else if(temp.back() == "OR"){
                Composant *c1 = new PorteOR(temp[0]);
                Net *a = retourneNet(nets,temp[1]);
                Net *b = retourneNet(nets,temp[2]);
                Net *c = retourneNet(nets,temp[3]);
                c1->compAddInput(a);
                c1->compAddInput(b);
                c1->compAddOutput(c);
                comps->push_back(c1);
            }
            else if(temp.back() == "NOR"){
                Composant *c1 = new PorteNOR(temp[0]);
                Net *a = retourneNet(nets,temp[1]);
                Net *b = retourneNet(nets,temp[2]);
                Net *c = retourneNet(nets,temp[3]);
                c1->compAddInput(a);
                c1->compAddInput(b);
                c1->compAddOutput(c);
                comps->push_back(c1);
            }
            else if(temp.back() == "XOR"){
                Composant *c1 = new PorteXOR(temp[0]);
                Net *a = retourneNet(nets,temp[1]);
                Net *b = retourneNet(nets,temp[2]);
                Net *c = retourneNet(nets,temp[3]);
                c1->compAddInput(a);
                c1->compAddInput(b);
                c1->compAddOutput(c);
                comps->push_back(c1);
            }
            else if(temp.back() == "NAND3"){
                Composant *c1 = new PorteNAND3(temp[0]);
                Net *a = retourneNet(nets,temp[1]);
                Net *b = retourneNet(nets,temp[2]);
                Net *c = retourneNet(nets,temp[3]);
                Net *d = retourneNet(nets,temp[4]);
                c1->compAddInput(a);
                c1->compAddInput(b);
                c1->compAddInput(c);
                c1->compAddOutput(d);
                comps->push_back(c1);
            }
        }
        v_copy.pop();
    }
}

/**
* @brief Fonction qui recherche dans notre vecteur de composant le composant à partir d'une net
*/
/*Fonction qui recherche dans notre vecteur de composant le composant à partir d'une net*/
void chercherComposant(vector<Net*> v_net,vector<Composant*> *comps , vector<Composant*> *tmp ){

    for(unsigned i = 0; i<comps->size();i++){
        for(unsigned j = 0;j<comps->at(i)->getNetIn().size();j++){
            for(unsigned k = 0; k<v_net.size();k++){
                if(comps->at(i)->getNetIn().at(j)->getNetId() == v_net[k]->getNetId()){
                    Composant *a = comps->at(i);
                    tmp->push_back(a);
                }
            }
        }
    }

    //Suppr doublons
    sort(tmp->begin(),tmp->end());
    tmp->erase(unique(tmp->begin(),tmp->end()),tmp->end());
}

/**
* @brief Fonction d'affichage des chronogrammes
*/
/*Fonction d'affichage des chronogrammes*/
void affichage(queue<vector<string>> V,vector<Composant*> *compsOut ,string fichier){
    queue<vector<string> > v_copy = V;
    vector<string> temp;
    vector<string> resultat;
    string str;

    while (!v_copy.empty()){
        temp = v_copy.front();
        if(!temp.empty()){
            if(temp.back() == "INPUT"){
                str = "\t "+temp[0]+"  : ";

                ifstream File("Simu/"+fichier+"_"+temp[0]+".stm", ios::in);

                if (File.is_open()){
                    string mot;
                    while (!File.eof()){
                        getline(File,mot);
                    }
                str = str + mot;
                resultat.push_back(str);
                }
            }
        }
        v_copy.pop();
    }

    for(unsigned i =0;i<compsOut->size();i++){
        str = "\t "+compsOut->at(i)->getCompId()+" : ";
        ifstream File("Simu/"+fichier+"_"+compsOut->at(i)->getCompId()+".prb", ios::in);
        if (File.is_open()){
            string mot;
            while (!File.eof()){
                getline(File,mot);
            }
        str = str + mot;
        resultat.push_back(str);
        }
    }



    for(unsigned i = 0;i<resultat.size();i++){
        cout<<resultat[i]<<endl;
    }

}


/*------------------------------------MAIN----------------------------------------*/
int main(int argc, char *argv[]){
    /*Création des variables*/
    queue<vector<string> > v; //Queue contenant tous les élem du .cir
    vector<Composant*> *comps = new vector<Composant*>; //Porte de notre circuit
    vector<Composant*> *compsOut = new vector<Composant*>; //Porte de sortie => utile pour écrire dans les fichiers de sortie
    vector<Net*> * inputNets = new vector<Net *>; //Nets d'entrée de notre circuit
    vector<Net*> * nets = new vector<Net *>; //Ttes les nets de notre circuit
    queue<Evenement> Q_IO; //Queue I/O
    string fichier;
    if (argc == 2){
        fichier = argv[1];
    }
    else{
        //Demande à l'ulisateur de donné le nom du fichier
        cout << "Donnez le nom du fichier :" << endl;
        cin >> fichier;
    }
    cout << "----------------------------.CIR----------------------------------" << endl;
    v = lecturecir(fichier);
    //---------------------------Affichage de la queue (.cir)-----------------------
    afficheFichierCir(v);
    //Creation des composant a partir du fichier .cir
    creeComposant(v,comps,compsOut,inputNets,nets);
    //-----------------------Affichage fichiers stimuli + Q_IO----------------------
    cout << "----------------------------QUEUE IO----------------------------------" << endl;
    Q_IO = creationPileIO(v,inputNets,fichier);
    //Affichage Q
    afficheQueue(Q_IO);
    //------------------------------PARTIE Q SIMU-----------------------------------
    cout << "----------------------------QUEUE SIM----------------------------------" << endl;
    queue<Evenement> * Q_sim = new queue<Evenement>;//Pile event simulation
    vector<Net*> v_net;
    int reftime = 0;
    int cpt = 0;
    int time = 1;
    //Pseudo-code du sujet
    while(!Q_IO.empty()){ // tant que pile d'evenement I/O non vide
        cout << "###########################" << reftime << "##############################" << endl;
        while(Q_IO.front().getEventTime() == reftime){ // place dans la pile des évenements de simu event avec mm ref temporelle que I/O
            Q_sim->push(Q_IO.front());
            Q_IO.pop();
        }
        cpt = 0;
        time = 0;
        while (!Q_sim->empty()){
            cout << "-----------Event" << cpt << "-------------" << endl;
            cout << Q_sim->front();
            //MODIF VAL NOEUD
            Net *n(Q_sim->front().getEventNet() );
            n->setNetEtat(Q_sim->front().getEventStimuli());
            Q_sim->front().setEventNet(n);
            cout << "=>" << Q_sim->front()<<endl;
            v_net.push_back(n);
            Q_sim->pop();
            if(Q_sim->empty()){ //Dans ce if on rempli Q_sim avec les event +1 après propagation
                time+=1;
                //chercher le composant
                vector<Composant*> *a = new vector<Composant*>;
                chercherComposant(v_net,comps,a);
                for(unsigned i = 0;i<a->size();i++){
                    cout << "------------------PROPA-------------------" << endl;
                    a->at(i)->propagation(Q_sim, reftime + time);
                }
                cpt ++;
                v_net.clear(); //On efface notre vecteur de net pour la prochaine itération
            }
        }
        reftime += 1000;
    }

    /*---------Creation des fichier sortie--------------*/
    cout << "----------------------------CHRONOGRAMME----------------------------------" << endl;
    for(unsigned i = 0;i<compsOut->size();i++){
        compsOut->at(i)->ecrireOUT(fichier);
    }
    //------------Affichage des chronogrammes--------------
    affichage(v,compsOut,fichier);

    /*Destruction des objets*/
    delete(Q_sim);
    delete(comps);
    delete(inputNets);
    delete(compsOut);
    delete(nets);

    return 0;
}

