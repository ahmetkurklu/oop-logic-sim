/**
 * @file PorteOR.h
 * @brief fichier PorteOR.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef PORTEOR_H
#define PORTEOR_H

#include<iostream>
#include<string>
#include"Composant.h"
#include"Evenement.h"
#include"Net.h"
#include <queue>

/**
 * @brief class PorteOR utilisé pour construire une porte OR
 * @see class Composant
 */
class PorteOR : public Composant{
    public:
        PorteOR();
        PorteOR(std::string or_name);
        virtual ~PorteOR();
        void propagation(std::queue<Evenement> *s, int time);
};

#endif // PORTEOR_H
