/**
 * @file PortXOR.h
 * @brief fichier PorteAND.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef PORTEXOR_H
#define PORTEXOR_H

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
class PorteXOR : public Composant{
    public:
        PorteXOR();
        PorteXOR(std::string xor_name);
        virtual ~PorteXOR();

        void propagation(std::queue<Evenement> *s, int time);
};

#endif // PORTEAND_H
