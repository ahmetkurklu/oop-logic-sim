/**
 * @file PorteNOT.h
 * @brief fichier PorteNOT.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef PORTENOT_H
#define PORTENOT_H

#include<string>
#include"Composant.h"
#include"Evenement.h"
#include"Net.h"
#include <queue>

/**
 * @brief class PorteNOT utilisé pour construire une porte NOT
 * @see class Composant
 */
class PorteNOT : public Composant{
    public:
        PorteNOT();
        PorteNOT(std::string not_name);
        void propagation(std::queue<Evenement> *s, int time);
        virtual ~PorteNOT();
};

#endif // PORTENOT_H
