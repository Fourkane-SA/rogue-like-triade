#pragma once

#include <string.h>
#include <SFML/Graphics.hpp>

#include "Collision.h"

class Object
{
	private:

		/**
		@brief La position de l'objet
		*/
		sf::Vector2i positionObjet;

		/**
		@brief la dimension de l'objet
		*/
		sf::Vector2i dimensionObjet;

		/**
		@brief La texture de l'objet
		*/
		sf::Texture textureObjet;
		/**
		@brief Le sprite de l'objet
		*/
		sf::Sprite spriteObjet;

		/**
		@brief Le rectangle de collision de l'objet
		*/
		RectangleCollision* rectCollisionObjet;

	public:

		/**
		@brief Les PV de l'objet
		*/
		int objetVie;

		/**
		@brief Bonus d'attaque de l'objet
		*/
		unsigned int objetAttaque;

		/**
		@brief Bonus de vitesse d'attaque de l'objet
		*/
		unsigned int objetVitesseAttaque;

		/**
		@brief Bonus de vitesse de deplacement
		*/
		unsigned int objetVitesseDeplacement;

		/**
		@brief constructeur par défaut de la classe

		Vide les pointeurs
		*/
		Object();

		/**
		@brief Initialise un objet au hasard aux positions en parametre

		@param x position en x de l'objet à initialiser
		@param y position en y de l'objet à initialiser 
		*/
		void initObjet(int x, int y);

		/**
		@brief Accesseur de la position

		@return Retourne la position de l'objet
		*/
		sf::Vector2i getPosition();

		/**
		@brief accesseur de la taille

		@return Retourne la taille de l'objet
		*/
		sf::Vector2i getSize();
		
		/**
		@brief accesseur du rectangle de collission de l'objet

		@return Retourne le rectangle de collision
		*/
		RectangleCollision* getRectCollisionObjet();
		
		/**
		@brief Affiche l'objet

		@param window La fenetre du jeu
		*/
		void renduObjet(sf::RenderWindow& window);

		~Object();
};
