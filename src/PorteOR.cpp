/**
 * @file PorteOR.cpp
 * @brief fichier PorteOR.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "PorteOR.h"

using namespace std;

PorteOR::PorteOR()
{
    //ctor
}

PorteOR::~PorteOR()
{
    //dtor
}

PorteOR::PorteOR(std::string or_name)
    :Composant(or_name){}

void PorteOR::propagation(std::queue<Evenement> *s, int time){
    char n_stimuli;
    if(this->netIn[0]->getNetEtat()=='0' && this->netIn[1]->getNetEtat()=='0'){
        n_stimuli = '0';
    }
    else{
        n_stimuli = '1';
    }
    cout<<"Je suis dans la propa OR"<<endl;
    Evenement a(time,this->netOut[0],n_stimuli);
    s->push(a);
}
