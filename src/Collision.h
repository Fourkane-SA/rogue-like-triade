#pragma once

#include <SFML/Graphics.hpp>

class RectangleCollision
{
    public:

        
        /**
        @brief position du rectangle de collision
        */
        sf::Vector2i positionRectCollision;
        /**
        @brief dimension du rectangle de collision
        */
        sf::Vector2f dimentionRectCollision;
        /**
        @brief Contours du rectangle de collision
        */
        sf::RectangleShape formeRectCollision;
        bool visible;

        
        /**
        @brief Constructeur par défaut du rectangle de collision

        Initialise un rectangle avec position et dimension nul
        */
        RectangleCollision();

        /**
        @brief Constructeur du rectangle de collision

        Initialise le rectangle de collision avec les parametres
        @param x La position en x du rectangle
        @param y La position en y du rectangle
        @param width La largeur du rectangle
        @param height La hauteur du rectangle
        */
        RectangleCollision(int x, int y, float width, float height);

        /**
        @brief Mutateur de la position

        Mofidie la position du rectangle de collision avec le vecteur en paramètre
        @param newPosition Nouvelle position du personnnage
        */
        void setPositionRectangleCollision(const sf::Vector2i& newPosition);
        
        /**
        @brief Verifie s'il y a collision avec un autre rectangle de collision
        
        @param other Un autre rectangle de collision
        @return Vrai s'il y a collision
        */
        bool checkCollision (const RectangleCollision& other);

        /**
        @brief Verifie s'il y a une collision pour chaque angle

        @param other Un autre rectangle de collision
        @param hg un booléen qui sera vrai si collision dans l'angle supérieur gauche
        @param hd un booléen qui sera vrai si collision dans l'angle supérieur droit
        @param bg un booléen qui sera vrai si collision dans l'angle inférieur gauche
        @param bd un booléen qui sera vrai si collision dans l'angle inférieur droit
        */
        void checkCollisionAngles(const RectangleCollision& other, bool &hg, bool& hd, bool &bg, bool &bd);

        /**
        @brief affiche le rectangle de collision
        
        @param window la fenetre de jeu
        */
        void renduRectangleCollision(sf::RenderWindow& window);
};
