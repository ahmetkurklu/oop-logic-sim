/**
 * @file Evenement.cpp
 * @brief fichier Evenement.cpp
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#include "Evenement.h"
#include<iostream>

using namespace std;

Evenement::Evenement(){
}

Evenement::Evenement(int e_time,Net *e_net,char e_stimuli){
    eventTime = e_time;
    eventStimuli = e_stimuli;
    eventNet = e_net;
}

//Get
int Evenement::getEventTime(){
    return eventTime;
}

Net* Evenement::getEventNet(){
    return eventNet;
}
char Evenement::getEventStimuli(){
    return eventStimuli;
}
//Set
void Evenement::setEventTime(int e_time){
    eventTime = e_time;
}
void Evenement::setEventNet(Net *e_net){
    eventNet = e_net;
}
void Evenement::setEventStimuli(char e_stimuli){
    eventStimuli = e_stimuli;
}

void Evenement::afficherEvenement(){
    cout<<"Event("<<eventTime<<",Net("<<eventNet->getNetId()<<","<<eventNet->getNetEtat()<<"),"<<eventStimuli<<")"<<endl;
}

std::ostream& operator<<(std::ostream& flux, const Evenement& ev){
    flux << "Event(" << ev.eventTime << "," << ev.eventNet << "," << ev.eventStimuli << ")";
    return flux;
}


Evenement::~Evenement(){
}
