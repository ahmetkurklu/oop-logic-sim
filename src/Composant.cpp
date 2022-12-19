/**
 * @file Composant.cpp
 * @brief fichier Composant.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "Composant.h"

using namespace std;

Composant::Composant(){
}

//Constructeur
Composant::Composant(string c_id){
    composantId = c_id;
}

Composant::~Composant(){
}

//Fonction qui affiche le nom du composant et les net en entrée sortie
void Composant::afficherComposant(){

    cout<<"\t\tCOMPOSANT:"<<composantId<<endl;
    cout<<"NOM ENTREE\t\tETAT"<<endl;
    for(unsigned i = 0;i<netIn.size();i++){
        cout<<netIn.at(i)->getNetId()<<"\t\t\t"<<netIn.at(i)->getNetEtat()<<endl;
    }

    cout<<"NOM SORTIE \t\tETAT"<<endl;
    for(unsigned i = 0;i<netOut.size();i++){
        cout<<netOut.at(i)->getNetId()<<"\t\t\t"<<netOut.at(i)->getNetEtat()<<endl;
    }
    cout<<"\t\tFIN COMPOSANT"<<endl;
}


vector<Net*> Composant::getNetOut(){
    return netOut;
}

vector<Net*> Composant::getNetIn(){
    return netIn;
}

//Ajoute un net en Entree
void Composant::compAddInput(Net *a){
    netIn.push_back(a);
}

//Ajoute un net en sortie
void Composant::compAddOutput(Net *a){
    netOut.push_back(a);
}

string Composant::getCompId(){
    return composantId;
}

bool Composant::operator==(const Composant * n){
    if (this->composantId == n->composantId){
        return 1;
    }
    else{
        return 0;
    }
}

void Composant::propagation(queue<Evenement> *s, int time){
    cout<<"Je suis dans composant"<<endl;
}

void Composant::ecrireOUT(std::string nomFichier){
}



