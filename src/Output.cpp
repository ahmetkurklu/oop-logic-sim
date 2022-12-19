/**
 * @file Output.cpp
 * @brief fichier Output.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "Output.h"

using namespace std;

Output::Output(){
}

Output::Output(std::string output_name)
    :Composant(output_name){
}

void Output::propagation(queue<Evenement> *s, int time){
    if(netIn.at(0)->getNetEtat() == '1'){
        out.push_back('-');
    }
    else{
        out.push_back('_');
    }
}


void Output::ecrireOUT(string nomFichier){

    string nom = "Simu/"+nomFichier + "_" + composantId+ ".prb";
    ofstream file;
    file.open(nom);

    for(unsigned i=0;i<out.size();i++){
        file<< out[i];
    }
    file.close();

}

Output::~Output(){
}
