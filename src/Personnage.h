#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string.h>
#include <time.h>
#include "BarreDeVie.h"
#include "Obstacle.h"
#include "Objet.h"
#include "Collision.h"
#include "Projectile.h"

class Personnage
{
    private:

        
        /**
        @brief position du personnage
        */
        sf::Vector2i positionPerso;

        /**
        @brief La dimension du personnage
        */
        sf::Vector2i dimensionPerso;

        /**
        @brief La vélocité du personnage
        */
        sf::Vector2i velocitePerso;

        /**
        @brief Vecteur indiquant la position de l'animation du personnage
        */
        sf::Vector2i animationPerso;

        /**
        @brief La barre de vie du personnage
        */
        BarreDeVie* barreDeViePerso;

        /**
        @brief Le rectangle de collision du personnage
        */
        RectangleCollision* rectCollisionPerso;

        /**
        @brief La texture du personnage
        */
        sf::Texture texturePerso;

        /**
        @brief Le sprite du personnage
        */
        sf::Sprite spritePerso;

        /**
        @brief Un tableau dynamique des attaques du personnage
        */
        std::vector <Projectile*> attaquePerso;

        /**
        @brief Le nombre de points de vie max du personnage
        */
        int pointsVieMaxPerso;

        /**
        @brief Le nombre de points de vie du personnage
        */
        int pointsViePerso;

        /**
        @brief Le degat d'attaque du personnage
        */
        unsigned int degatsAttaquePerso;

        /**
        @brief La vitesse d'attaque du personnage
        */
        unsigned int vitesseAttaquePerso;

        /**
        @brief Le temps d'attente entre deux attaques du personnage
        */
        clock_t intervalleAttaquePerso;

        /**
        @brief La vitesse de deplacement du personnage
        */
        unsigned int vitesseDeplacementPerso;

        /**
        @brief Un booléen permettant de savoir si le personnage peut recevoir des dégats
        */
        bool invincibilitePerso;

        /**
        @brief La durée de l'invincibilité du personnage
        */
        unsigned int dureeInvincibilitePerso;
        
        clock_t intervalleInvincibilitePerso;

        /**
        @brief La liste des objets du personnage
        */
        std::vector <Object*> listeObjetPerso;


    public:

        /**
        @brief Le constructeur par défaut du personnage
        */
        Personnage();

        /**
        @brief Initialise le personnage

        @param choix Un charactere représentant le personnage a generer
        @param dimensionPersoFenetre La dimension du personnage
        */
        void initPersonnage(unsigned char choix,const sf::Vector2i& dimensionPersoFenetre); //entre D,E ou T

        /**
        @brief Mutateur de la position du personnage

        @param newPosition La nouvelle position du personnage
        */
        void setPositionPerso(const sf::Vector2i& newPosition);

        /**
        @brief Accesseur de la position du personnage

        @return Retourne la position du personnage
        */
        sf::Vector2i getPositionPerso();

        /**
        @brief Mutateur de la dimension du personnage

        @param newDimension La nouvelle dimension du personnage
        */
        void setDimensionPerso(const sf::Vector2i& newDimension);

        /**
        @brief Accesseur de la dimension du personnage

        @return Retourne la dimension du personnage
        */
        sf::Vector2i getDimensionPerso();

        /**
        @brief Accesseur du rectangle de collision du personnnage

        @return Retourne le rectangle de collision du personnage
        */
        RectangleCollision* getRectCollisionPerso();

        /**
        @brief Accesseur de degats du personnage

        @return Retourne les dégats du personnage
        */
        unsigned int getDegatsPersonnage();

        /**
        @brief Mutateur de l'invincibilité

        Active l'invincibilité pendant une durée mis en paramètre
        @param duree La durée de l'invincibilité
        */ 
        void setInvincibilite(int duree);

        /**
        @brief Ajoute un objet au personnage

        @param objetSalle L'objet à rajouter
        */
        void ajoutObjetPerso(Object* objetSalle);

        /**
        @brief Ajoute un projectille

        Ajoute un projectille de la direction mis en paramètre
        @param directionDonnee La direction de l'attaque
        */
        void addProjectile(const char directionDonnee);

        /**
        @brief Detecte si une attaque du personnage est au collision avec un rectangle de collision

        Permet de detruire les projectilles au contact avec un objet/monstre.
        @param other Un rectangle de collision
        @return Retourne vrai si un projectille est au contact avec l'objet/monstre en paramètre
        */
        bool gestionProjectile(RectangleCollision* other) ;

        /**
        @brief Vide tous les projectiles du personnage
        */
        void videProjectile();

        /**
        @brief Diminue les points de vie du personnage

        Le personnage pert des points de vie s'il n'est pas invincible,
        et il est ensuite invincible pendant une courte durée
        @param degats Le nombre de points de vie a retirer
        */
        void persoEstTouche(int degats);

        /**
        @brief Met à jour le personnage

        Gère les déplacements et les attaques du personnage.
        */
        void miseAJourPerso();

        /**
        @brief Affecte l'effet de l'obstacle sur le personnage

        @param obstacle L'obstacle
        */
        void effetCollisionPerso(Obstacle* obstacle);

        /**
        @brief Evite au personnage de traverser le mur

        @param hg Un booléen représentant le contact avec le côté supérieur gauche
        @param hd Un booléen représentant le contact avec le côté supérieur droit
        @param bg Un booléen représentant le contact avec le côté inférieur gauche
        @param bd Un booléen représentant le contact avec le côté inférieur droit
        */
        void collisionMur(bool& hg, bool& hd, bool& bg, bool& bd);

        /**
        @brief Affiche le personnage

        @param window La fenetre de jeu
        */
        void renduPerso(sf::RenderWindow& window);

        /**
        @brief Accesseur du points de vie du personnage

        @return Retourn le nombre de points de vie du personnage
        */
        int getPointsViePerso();
    
        /**
        @brief Destructeur de la classe

        Libère la mémoire
        */
        ~Personnage();
};
