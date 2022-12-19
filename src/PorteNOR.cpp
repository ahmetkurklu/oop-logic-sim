/**
 * @file PorteNOR.cpp
 * @brief fichier PorteNOR.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "PorteNOR.h"
using namespace std;

PorteNOR::PorteNOR(){
}

PorteNOR::~PorteNOR(){
}

PorteNOR::PorteNOR(std::string nor_name):Composant(nor_name){}

void PorteNOR::propagation(std::queue<Evenement> *s, int time){
    char n_stimuli;
    if(this->netIn[0]->getNetEtat()=='0' && this->netIn[1]->getNetEtat()=='0'){
        n_stimuli = '1';
    }
    else{
        n_stimuli = '0';
    }
    cout<<"Je suis dans la propa NOR"<<endl;
    Evenement a(time,this->netOut[0],n_stimuli);
    s->push(a);
}
