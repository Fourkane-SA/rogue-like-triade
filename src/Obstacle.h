#pragma once

#include <string.h>
#include <SFML/Graphics.hpp>
#include "Collision.h"


class Obstacle
{
    private:

        /**
        @brief Position de l'obstacle
        */
        sf::Vector2i positionObstacle;

        /**
        @brief Degats de l'obstacle
        */
        unsigned int degatsObstacle;

        /**
        @brief Un booléen indiquant si l'obstacle est franchissable
        */
        bool franchissableObstacle;

        /**
        @brief Un booléen indiquant si l'obstacle est destructible
        */
        bool destructibleObstacle;

        /**
        @brief La texture de l'obstacle
        */

        sf::Texture textureObstacle;
        /**
        @brief La texture de l'obstacle
        */
        sf::Sprite spriteObstacle;
        
        /**
        @brief Le rectangle de collision de l'obstacle
        */
		RectangleCollision* rectCollisionObstacle;

    public :

        /**
        @brief Le constructeur de l'obstacle
        */
        Obstacle();

        /**
        @brief accesseur du booléen franchissable

        @return Retourne le booléen franchissable
        */
        bool getFranchissableObstacle();

        /**
        @brief Accesseur du rectangle de collission

        @return Retourne le rectangle de collision
        */
        RectangleCollision* getRectCollisionObstacle();

        /**
        @brief Accesseur du degat de l'obstacle

        @return Retourne les dégats de l'obstacle
        */
        unsigned int getDegatsObstacle();

        /**
        @brief Initialise l'obstacle

        Initialise l'obstacle avec son type et sa position en parametre
        @param typeObstacle Le type de l'obstacle
        @param position La position de l'obstacle
        */
        void initObstacle(char typeObstacle, const sf::Vector2i& position);

        /**
        @brief Affiche l'obstacle

        @param window La fenetre de l'écran
        */
        void renduObstacle(sf::RenderWindow& window);
};
