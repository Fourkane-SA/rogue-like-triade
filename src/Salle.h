#pragma once

#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Etage.h"
#include "Obstacle.h"
#include "Objet.h"
#include "Etage.h"
#include "Monstre.h"

class Etage;

class Salle
{
    private:

        /**
        @brief La position de la salle
        */
        sf::Vector2i positionSalle;

        /**
        @brief Un tableau 2D représentant les elements de la salle (objets, monstres, murs)
        */
        char elementSalle [13][13];

        /**
        Un booléen permettant vrai si le joueur a déjà visité la salle
        */
        bool visite;

        /**
        @brief Un tableau dynamique contenant tous les obstacles (murs, sols, pieges) de la salle
        */
        std::vector<Obstacle*> tabObstacleSalle;

        /**
        @brief Un tableau dynamique contenant tous les monstres de la salle
        */
        std::vector<Monstre*> tabMonstreSalle;

        /**
        @brief L'objet de la salle dans le cas où on est dans une salle objet
        */
        Object* objetSalle;

    public:

        /**
        @brief Constructeur par défaut de la Salle
        */
        Salle();

        /**
        @brief Accesseur de la position du Personnage
        */
        sf::Vector2i getPositionSalle();

        /**
        @brief Compte le nombre de voisins de la Salle

        @param x La position en x de la Salle
        @param y La position en y de la Salle
        */
        int voisinsSalle(int x, int y);

        /**
        @brief Initialise la salle
        
        @param e L'étage du jeu
        @param ySalle La position en y de la Salle
        @param xSalle La position en x de la Salle
        @param type Le type de Salle
        */
        void initSalle(Etage* e, int ySalle, int xSalle, int type);

        /**
        @brief Mets à jour la salle

        @param personnage Le joueur
        @param e L'étage du jeu 
        */
        void miseAJourSalle(Personnage* personnage, Etage* e);

        /**
        @brief Affiche le jeu

        @param window La fenetre de jeu
        */
        void renduSalle(sf::RenderWindow& window);

        /**
        @brief Affiche la Salle sur la console
        */
        void afficherConsole();

        /**
        @brief Mutateur : Mets visite à vrai

        Permettre de mettre à vrai visite lorsque le joueur l'a visité
        */
        void setVisite();

        /**
        @brief Mutateur de visite

        @return Retourne vrai si la salle a été visité
        */
        bool getVisite();
        
        /**
        @brief Destructeur de la Salle

        Libère la mémoire
        */
        ~Salle();
};
