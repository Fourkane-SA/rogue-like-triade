#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Salle.h"
#include "Collision.h"
#include "Personnage.h"

class Etage
{
    private:

        
        /**
        @brief position de la salle actuelle
        */
        sf::Vector2i positionSalleActuEtage;

        /**
        @brief Un tableau de salles représentant l'étage
        */
        Salle* tabSallesEtage[10][10];

        /**
        @brief Le nombre de salle de l'étage
        */
        int nombreSalleEtage;

        /**
        @brief Un booléen vrai si le niveau est terminé
        */
        bool finNiveau;

    public:
        /**
        @brief Un tableau 2D d'entiers représentant l'étage

        Ce tableau représente les salles de l'étage.
        Si la valeur est de 0, il n'y a pas de salle.
        Si la valeur est de 1, il y a la salle de départ.
        Si la valeur est de 2, il y a une salle normale.
        Si la valeur est de 3, il y a une salle objet.
        Si la valeur est de 4, il y a la salle de boss.
        */
        int patternEtage[10][10];

        
        /**
        @brief Constructeur par défaut de la classe
        
        Vide les 2 tableaux 2D de l'étage
        */
        Etage();

        /**
        @brief Destructeur par défaut

        Libère la mémoire
        */
        ~Etage();

        /**
        @brief Retourne un booléen vérifiant si la salle est libre

        @param x La position en x de l'emplacement a vérifier
        @param y La position en y de l'emplacement a vérifier
        @return Retourne vrai si l'emplacement n'a qu'un seul voisin
        */
        bool salleLibreEtage(const int& x, const int& y);

        /**
        @brief Genere un étage

        Remplis le tableau 2D d'entiers pour générer un étage
        */
        void generationPatternEtage();

        /**
        @brief Charge les salles d'un étage

        Permet de créer une salle lorsque la valeur généré dans le tableau 2D d'entiers n'est pas nulle
        */
        void chargeEtage();

        /**
        @brief Charge la salle actuelle

        @param x La position en x de la salle a charger
        @param y La position en y de la salle a charger
        */
        void chargeSalleEtage(int x, int y);

        /**
        @brief Mets à jour l'étage
        
        @param personnage Le joueur
        */
        void miseAJourEtage(Personnage* personnage);

        /**
        @brief Affiche l'étage

        @param window La fenetre de jeu
        */
        void renduEtage(sf::RenderWindow& window);

        /**
        @brief Affiche sur la console l'étage
        */
        void afficherConsole();

        /**
        @brief affiche la map

        @param window La fenetre de jeu
        */
        void renduMap(sf::RenderWindow& window);

        /**
        @brief Accesseur de la position de la salle actuelle
        */
        sf::Vector2i getPositionSalleActu();

        /**
        @brief Mutateur de la position de la salle actuelle
        */
        void setFinNiveau();
        /**
        @brief Accesseur du booléen de fin de niveau

        @return Retourne le booléen finNiveau
        */
        bool getFinNiveau();
};