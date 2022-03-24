#include "jeu.h"
#include "Personnage.h"
#include "Objet.h"
#include "Obstacle.h"
#include "Etage.h"
#include "Salle.h"
#include "Projectile.h"
#include "Monstre.h"

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

Jeu::Jeu()
{
    etageActuJeu=nullptr;
    personnageJeu=nullptr;
}

void Jeu::initJeu(const char& choix, unsigned char niveau)
{
    if(niveau != 1)
    {
        delete personnageJeu;
        delete etageActuJeu;
    }

    personnageJeu = new Personnage;
    typePerso = choix;
    personnageJeu->initPersonnage(choix,sf::Vector2i(832,832));
    etageActuJeu = new Etage;
    etageActuJeu->generationPatternEtage();
    etageActuJeu->chargeEtage();
    etageActuJeu->afficherConsole();
    numeroEtageJeu = niveau;
}

void Jeu::miseAJourJeu()
{
    if(personnageJeu->getPointsViePerso() > 0 && numeroEtageJeu < '4')
    {
        personnageJeu->miseAJourPerso();
        etageActuJeu->miseAJourEtage(personnageJeu);
    }
    if(etageActuJeu->getFinNiveau())
    {
        numeroEtageJeu++;
        initJeu(typePerso,numeroEtageJeu);
    }
    
}

void Jeu::renduJeu(sf::RenderWindow& window)
{
    sf::Text text;
    sf::Font font;
    // Load it from a file
    if (!font.loadFromFile("data/polices/arial.ttf"))
    {
        cout << "Erreur de police" << endl;
    }
    
    
    text.setFont(font);
    if(personnageJeu->getPointsViePerso() > 0)
    {
        cout << numeroEtageJeu << endl;
        if(numeroEtageJeu < '4')
        {
            etageActuJeu->renduEtage(window);
            personnageJeu->renduPerso(window);
            text.setString("Niveau : "+sf::String((char)numeroEtageJeu));
            text.setCharacterSize(24);
            text.setOrigin(text.getLocalBounds().width,text.getLocalBounds().height);
            text.setPosition(832-text.getLocalBounds().width,text.getLocalBounds().height +15);
            window.draw(text);
        }
        else
        {
            text.setString("VICTOIRE");
            text.setCharacterSize(24);
            text.setOrigin(text.getLocalBounds().width/2,text.getLocalBounds().height/12);
            text.setPosition(416,416);
            window.draw(text);
        }
    }
    else
    {
        text.setString("GAME OVER");
        text.setCharacterSize(24);
        text.setOrigin(text.getLocalBounds().width/2,text.getLocalBounds().height/12);
        text.setPosition(416,416);
        window.draw(text);
    }
}
