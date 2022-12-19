/**
 * @file PorteNAND.h
 * @brief fichier PorteNAND.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef PORTENAND3_H
#define PORTENAND3_H

#include<iostream>
#include<string>
#include"Composant.h"
#include"Evenement.h"
#include"Net.h"
#include <queue>

/**
 * @brief class PorteNAND utilisé pour construire une porte NAND
 * @see class Composant
 */
class PorteNAND3 : public Composant{
    public:
        PorteNAND3();
        PorteNAND3(std::string nand3_name);
        virtual ~PorteNAND3();
        void propagation(std::queue<Evenement> *s, int time);
};

#endif // PORTENAND_H
