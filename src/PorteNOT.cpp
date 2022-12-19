/**
 * @file PorteNOT.cpp
 * @brief fichier PorteNOT.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "PorteNOT.h"

using namespace std;

PorteNOT::PorteNOT(){
}

PorteNOT::PorteNOT(string not_name):Composant(not_name){
}

void PorteNOT::propagation(queue<Evenement> *s, int time){
    char n_stimuli;
    if(this->netIn[0]->getNetEtat() == '0'){
        n_stimuli = '1';
    }
    else{
        n_stimuli = '0';
    }
    cout<<"Je suis dans la propa NOT"<<endl;
    Evenement a(time,this->netOut[0],n_stimuli);
    s->push(a);

}


PorteNOT::~PorteNOT(){
}
