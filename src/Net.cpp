/**
 * @file Net.cpp
 * @brief fichier Net.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "Net.h"


using namespace std;

Net::Net(){
    netEtat = 'U';
    netId = " ";
}


//Constructeur
Net::Net(string n_id,char n_etat){
    netEtat = n_etat;
    netId = n_id;
}
 //Get
string Net::getNetId(){
    return netId;
}
char Net::getNetEtat(){
    return netEtat;
}

//Set
void Net::setNetId(string n_id){
    netId = n_id;
}
void Net::setNetEtat(char n_etat){
    netEtat = n_etat;
}

ostream& operator<<(std::ostream& flux, const Net * noeud){
    flux << "NET(" << noeud->netId << "," << noeud->netEtat << ")"; // << std::endl
    return flux;
}

Net::~Net(){
}
