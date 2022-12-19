/**
 * @file Output.h
 * @brief fichier Output.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef OUTPUT_H
#define OUTPUT_H

#include"Composant.h"
#include<string>
#include<queue>
#include<fstream>

/**
 * @brief class Output utilisé pour construire un composant Output
 * @see class Composant
 */
class Output: public Composant{
    public:
        Output();
        Output(std::string output_name);
        void propagation(std::queue<Evenement> *s, int time);
        void ecrireOUT(std::string nomFichier);
        virtual ~Output();
    private:
        std::vector<char> out;
};

#endif // OUTPUT_H
