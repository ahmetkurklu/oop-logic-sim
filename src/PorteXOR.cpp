/**
 * @file PorteAND.cpp
 * @brief fichier PorteAND.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "PorteXOR.h"

using namespace std;

PorteXOR::PorteXOR(){
}

PorteXOR::~PorteXOR(){
}


PorteXOR::PorteXOR(std::string xor_name)
    :Composant(xor_name){}

void PorteXOR::propagation(std::queue<Evenement> *s, int time){
    char n_stimuli;
    if(this->netIn[0]->getNetEtat()=='0' && this->netIn[1]->getNetEtat()=='0' ) {
        n_stimuli = '0';
    }
    else if(this->netIn[0]->getNetEtat()=='1' && this->netIn[1]->getNetEtat()=='1' ) {
        n_stimuli = '0';
    }
    else if(this->netIn[0]->getNetEtat()=='1' && this->netIn[1]->getNetEtat()=='0' ) {
        n_stimuli = '1';
    }
    else if(this->netIn[0]->getNetEtat()=='0' && this->netIn[1]->getNetEtat()=='1' ) {
        n_stimuli = '1';
    }
    cout<<"Je suis dans la propa XOR"<<endl;
    Evenement a(time,this->netOut[0],n_stimuli);
    s->push(a);
}
