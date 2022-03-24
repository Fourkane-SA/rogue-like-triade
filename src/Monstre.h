#pragma once

#include <string.h>
#include "Collision.h"
#include <SFML/Graphics.hpp>

class Monstre
{
    private:
        /**
        @brief La position du monstre
        */
        sf::Vector2i positionMonstre;

        /**
        @brief La vélocité du monstre
        */
        sf::Vector2i velociteMonstre;

        /**
        @brief La dimension du monstre
        */
        sf::Vector2i dimensionMonstre;

        /**
        @brief Le nombre de points de vie du monstre
        */
        int pointsVieMonstre;
        
        /**
        @brief Le nombre de degats de l'attaque du monstre
        */
        unsigned int degatsAttaqueMonstre;

        /**
        @brief La vitesse d'attaque du monstre
        */
        unsigned int vitesseAttaqueMonstre;

        /**
        @brief La vitesse de deplacement du monstre
        */
        unsigned int vitesseDeplacementMonstre;

        /**
        @brief La texture du monstre
        */
        sf::Texture textureMonstre;

        /**
        @brief Le sprite du monstre
        */
        sf::Sprite spriteMonstre;

        /**
        @brief Le rectangle de collision du monstre

        Correspond au contour du monstre
        */
        RectangleCollision* rectCollisionMonstre;

    public:

        /**
        @brief Constructeur par défaut du monstre
        */
        Monstre();

        /**
        @brief Accesseur du rectangle de collision

        @return Retourne le rectangle de collision
        */
        RectangleCollision* getRectangleCollisionMonstre();

        /**
        @brief Accesseur des PV du monstre
        */
        int getVieMonstre();

        /**
        @brief Accesseur des degats du monstre
        */
        unsigned int getDegatsMonstre();

        /**
        @brief Accesseur de la position du monstre
        */
        sf::Vector2i* getPositionMonstre();

        /**
        @brief Initialise un monstre

        Initialise le monstre avec le type en paramètre, et la position en parametre
        @param typeMonstre Type du monstre à initialiser
        @param position Position initiale du monstre
        */
        void initMonstre(std::string typeMonstre, sf::Vector2i position);

        /**
        @brief Mets a jour la position du monstre

        Le monstre se rapproche du personnage
        @param positionPersonnage La position du personnage
        */
        void miseAJourMonstre(const sf::Vector2i& positionPersonnage);
        /**
        @brief permet d'eviter la collision entre les monstre

        @param autre Un autre monstre au contact avec ce monstre 
        */
        void collisionEntreMonstre(Monstre* autre);
        
        /**
        @brief Diminue les PV du monstre

        @param degats les degats du joueurs
        */
        void monstreEstTouche(int degats);

        /**
        @brief Affiche le monstre

        @param window la fenetre de jeu
        */
        void renduMonstre(sf::RenderWindow& window);

        ~Monstre();
};
