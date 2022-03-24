#pragma once

#include <SFML/Graphics.hpp>
#include "Collision.h"

class Projectile
{
	private:
    	
        /**
        @brief La position du projectile
        */
        sf::Vector2i positionProjectile;

        /**
        @brief La dimension du projectile
        */
        sf::Vector2i dimensionProjectile;

        /**
        @brief La texture du projectile
        */
        sf::Texture textureProjectile;

        /**
        @brief Le sprite du projectile
        */
        sf::Sprite  spriteProjectile;

        /**
        @brief Le rectangle de collision du projectile
        */
        RectangleCollision* rectCollisionProjectile;

        /**
        @brief La direction du projectile
        */
        char directionProjectile;

        /**
        @brief La vitesse du projectile
        */
        unsigned int vitesseProjectile;

    public :

        /**
        @brief Initialise le projectille

        @param positionPersonnage La position du personnage
        @param dimensionPersonnage La dimension du personnage
        @param directionDonnee La direction du projectile
        */
        void initProjectile(const sf::Vector2i& positionPersonnage, const sf::Vector2i& dimensionPersonnage, const char directionDonnee);

        /**
        @brief Accesseur de la position du projectile

        @return Retourne la position du projectile
        */
        sf::Vector2i* getPositionProjectile();

        /**
        @brief Accesseur du rectangle de collision du projectile

        @return Retourne le rectangle de collison du projectile
        */
        RectangleCollision* getRectCollisionProjectile();

        /**
        @brief Gere Le deplacement du projectile

        Fait avancer le projectile dans sa direction
        */
        void deplacementProjectile();

        /**
        @brief Affiche le projectile

        @param window La fenetre de jeu
        */
        void renduProjectile(sf::RenderWindow& window);
};