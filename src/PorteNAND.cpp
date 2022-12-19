/**
 * @file PorteNAND.cpp
 * @brief fichier PorteNAND.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "PorteNAND.h"

using namespace std;

PorteNAND::PorteNAND(){
}

PorteNAND::~PorteNAND(){
}

PorteNAND::PorteNAND(std::string nand_name):Composant(nand_name){}

void PorteNAND::propagation(std::queue<Evenement> *s, int time){
    char n_stimuli;
    if(this->netIn[0]->getNetEtat()=='1' && this->netIn[1]->getNetEtat()=='1'){
        n_stimuli = '0';
    }
    else{
        n_stimuli = '1';
    }
    cout<<"Je suis dans la propa AND"<<endl;
    Evenement a(time,this->netOut[0],n_stimuli);
    s->push(a);
}
