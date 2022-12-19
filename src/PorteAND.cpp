/**
 * @file PorteAND.cpp
 * @brief fichier PorteAND.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "PorteAND.h"

using namespace std;

PorteAND::PorteAND(){
}

PorteAND::~PorteAND(){
}


PorteAND::PorteAND(std::string and_name)
    :Composant(and_name){}

void PorteAND::propagation(std::queue<Evenement> *s, int time){
    char n_stimuli;
    if(this->netIn[0]->getNetEtat()=='1' && this->netIn[1]->getNetEtat()=='1'){
        n_stimuli = '1';
    }
    else{
        n_stimuli = '0';
    }
    cout<<"Je suis dans la propa AND"<<endl;
    Evenement a(time,this->netOut[0],n_stimuli);
    s->push(a);
}
