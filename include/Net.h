/**
 * @file Net.h
 * @brief fichier Net.h
 * @author Groupe 4
 * @bug Aucun bug dans ce fichier
 */
#ifndef NET_H
#define NET_H

#include<string>
#include<iostream>
#include<vector>

/**
 * @brief class Net utilisé pour construire un net
 */
class Net
{
    public:
        Net();
        Net(std::string n_id,char n_etat);
        //get
        std::string getNetId();
        char getNetEtat();
        //Set
        void setNetId(std::string n_id);
        void setNetEtat(char n_etat);

        friend std::ostream& operator<<(std::ostream& flux, const Net* noeud); //Operateur <<

        virtual ~Net();

    private:
        std::string netId;
        char netEtat;

};

#endif // NET_H
