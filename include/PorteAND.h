/**
 * @file PorteAND.h
 * @brief fichier PorteAND.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef PORTEAND_H
#define PORTEAND_H

#include<iostream>
#include<string>
#include"Composant.h"
#include"Evenement.h"
#include"Net.h"
#include <queue>

/**
 * @brief class PorteAND utilisé pour construire une porte AND
 * @see class Composant
 */
class PorteAND : public Composant{
    public:
        PorteAND();
        PorteAND(std::string and_name);
        virtual ~PorteAND();

        void propagation(std::queue<Evenement> *s, int time);
};

#endif // PORTEAND_H
