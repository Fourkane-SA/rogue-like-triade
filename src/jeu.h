#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#include "jeu.h"
#include "Personnage.h"
#include "Objet.h"
#include "Obstacle.h"
#include "Etage.h"
#include "Salle.h"
#include "Projectile.h"
#include "Monstre.h"

class Jeu
{
    private:

        /**
        @brief Personnage du jeu
        */
        Personnage* personnageJeu;
        
        /**
        @brief Etage actuel du jeu
        */
        Etage* etageActuJeu;

        /**
        @brief Niveau de jeu
        */
        unsigned char numeroEtageJeu;

        /**
        @brief Type de personnage
        */
        char typePerso;

    public:

        /**
        @brief Initialisation d'un étage du jeu

        Initialise un étage du jeu en générant l'étage, et en créant le personnage
        @param choix Un charactère représentant le type de personnage
        @param niveau Un charactère représentant le niveau actuel du jeu
        */
        void initJeu(const char& choix, unsigned char niveau) ;

        /**
        @brief Constructeur par défaut

        Mets les pointeurs personnage et étage à nullptr
        */
        Jeu();

        /**
        @brief Mets à jour le jeu

        Appelle les fonctions mettant à jour le personnage, la salle et mets à jour l'étage.
        */
        void miseAJourJeu();

        /**
        @brief Affiche le jeu

        Appelle les fonctions d'affichage de la salle, la minimap, le personnage et l'écran de victoire/défaite
        @param window la fenetre du jeu
        */
        void renduJeu(sf::RenderWindow& window);
};
