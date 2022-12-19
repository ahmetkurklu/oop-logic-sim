/**
 * @file Evenement.h
 * @brief fichier Evenement.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef EVENEMENT_H
#define EVENEMENT_H

#include<string>
#include"Net.h"

/**
 * @brief class Evenement utilisé pour construire un event
 */
class Evenement
{
    public:
        //Constructeur
        Evenement();
        Evenement(int e_time,Net *e_net,char e_stimuli);

        //get
        int getEventTime();
        Net * getEventNet();
        char getEventStimuli();
        //Set
        void setEventTime(int e_time);
        void setEventNet(Net *e_net);
        void setEventStimuli(char e_stimuli);

        void afficherEvenement();

        virtual ~Evenement();

        friend std::ostream& operator<<(std::ostream& flux, const Evenement & ev); //Operateur <<

    private:
        int eventTime;
        Net *eventNet;
        char eventStimuli;
};

#endif // EVENEMENT_H
