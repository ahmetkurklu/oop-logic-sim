/**
 * @file PorteNOR.h
 * @brief fichier PorteNOR.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef PORTENOR_H
#define PORTENOR_H

#include<iostream>
#include<string>
#include"Composant.h"
#include"Evenement.h"
#include"Net.h"
#include <queue>

/**
 * @brief class PorteNOR utilisé pour construire une porte NOR
 * @see class Composant
 */
class PorteNOR : public Composant{
    public:
        PorteNOR();
        PorteNOR(std::string nor_name);
        virtual ~PorteNOR();
        void propagation(std::queue<Evenement> *s, int time);
};

#endif // PORTENOR_H
