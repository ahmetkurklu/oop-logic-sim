/**
 * @file PorteNAND.h
 * @brief fichier PorteNAND.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef PORTENAND_H
#define PORTENAND_H

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
class PorteNAND : public Composant{
    public:
        PorteNAND();
        PorteNAND(std::string nand_name);
        virtual ~PorteNAND();
        void propagation(std::queue<Evenement> *s, int time);
};

#endif // PORTENAND_H
