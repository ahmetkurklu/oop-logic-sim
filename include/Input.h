/**
 * @file Input.h
 * @brief fichier Input.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef INPUT_H
#define INPUT_H

#include"Composant.h"
#include<string>
#include"Evenement.h"

/**
 * @brief class Input utilisé pour construire un composant Input
 * @see class Composant
 */
class Input : public Composant{
    public:
        Input();
        Input(std::string input_name);
        virtual ~Input();
};

#endif // INPUT_H
