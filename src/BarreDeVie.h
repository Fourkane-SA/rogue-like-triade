#pragma once

#include <SFML/Graphics.hpp>

struct Couleur
{
    /**
    @brief La composante rouge de la couleur
    */
    unsigned char rouge;
    /**
    @brief La composante verte de la couleur
    */
    unsigned char vert;
};

class BarreDeVie
{
    private :

        /**
        @brief La position de la barre de vie
        */
        sf::Vector2f positionBarreDeVie;

        /**
        @brief La dimension de la barre de vie
        */
        sf::Vector2f dimensionBarreDeVie;
        
        /**
        @brief Le nombre de points de vie max du joueur
        */
        float vieMaxBarreDeVie;

        /**
        @brief Le nombre de points de vie actuel du joueur
        */
        float vieBarreDeVie;

        /**
        @brief La couleur de la barre de vie (du rouge et du vert)
        */
        Couleur couleurBarreDeVie;

        sf::RectangleShape videBarreDeVie;
        sf::RectangleShape pleinBarreDeVie;
        sf::RectangleShape separationBarreDeVie;

    public:

        /**
        @brief Initialise la barre de vie

        Initialisze la barre de vie en la remplissant entièrement avec le nombre de vie mis en paramètre
        @param dimensionFenetre La dimension de la fenetre
        @param vieMax La vie max du personnage
        */
        void initBarreDeVie(const sf::Vector2i& dimensionFenetre, const int& vieMax);

        /**
        @brief Mets à jour la barre de vie
        
        Permet de mettre à jour la barre de vie avec les paramètres
        @param vieMax La vie maximale du joueur
        @param vieActu La vie actuelle du joueur
        */
        void miseAJourBarreDeVie(const int& vieMax, const int& vieActu);
        /**
        @brief Affiche la barre de vie

        @param window La fenetre de jeu
        */
        void affichageBarreDeVie(sf::RenderWindow& window);
};
