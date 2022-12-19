/**
 * @file Composant.h
 * @brief fichier Composant.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef COMPOSANT_H
#define COMPOSANT_H

#include<vector>
#include<string>
#include"Net.h"
#include"Evenement.h"
#include<queue>

/**
 * @brief class  mère : Composant utilisé pour constuire un composant
 */
class Composant
{
    public:
        /*Constructeur*/
        Composant();
        Composant(std::string c_id);

        void compAddInput(Net *a);
        void compAddOutput(Net *a);

        void afficherComposant();

        /*Getteur*/
        std::string getCompId();
        std::vector<Net*> getNetOut();
        std::vector<Net*> getNetIn();


        bool operator==(const Composant * n);


        virtual void propagation(std::queue<Evenement> *s, int time);
        virtual void ecrireOUT(std::string nomFichier);

        virtual ~Composant(); //Destructeur

    protected:
        std::string composantId;
        std::vector<Net*> netOut;
        std::vector<Net*> netIn;
};

#endif // COMPOSANT_H
