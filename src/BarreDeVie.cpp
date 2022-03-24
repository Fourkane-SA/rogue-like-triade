#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#include "BarreDeVie.h"

void BarreDeVie:: initBarreDeVie(const sf::Vector2i& dimensionFenetre, const int& vieMax)
{
    dimensionBarreDeVie = sf::Vector2f(24.f,float(dimensionFenetre.y/2 - 96.f));
    positionBarreDeVie = sf::Vector2f(  dimensionFenetre.x-dimensionBarreDeVie.x-20.f,
                                        32.f);

    vieMaxBarreDeVie = vieMax;
    vieBarreDeVie = vieMaxBarreDeVie;
 
    couleurBarreDeVie.rouge = -255*(vieBarreDeVie/vieMaxBarreDeVie)+255;
    couleurBarreDeVie.vert = 255-couleurBarreDeVie.rouge;

    videBarreDeVie.setSize(dimensionBarreDeVie);
    videBarreDeVie.setPosition(positionBarreDeVie);
    videBarreDeVie.setOutlineColor(sf::Color(0,0,0));
    videBarreDeVie.setOutlineThickness(3.f);
    videBarreDeVie.setFillColor(sf::Color(100,100,100));

    pleinBarreDeVie.setSize(dimensionBarreDeVie);
    pleinBarreDeVie.setPosition(positionBarreDeVie);
    pleinBarreDeVie.setFillColor(sf::Color( int(couleurBarreDeVie.rouge),
                                            int(couleurBarreDeVie.vert),
                                            0));

    separationBarreDeVie.setSize(sf::Vector2f(  dimensionBarreDeVie.x,
                                                3.f));
    separationBarreDeVie.setFillColor(sf::Color(0,0,0));
}

void BarreDeVie:: miseAJourBarreDeVie(const int& vieMax, const int& vieActu)
{
    vieMaxBarreDeVie = vieMax;
    vieBarreDeVie = vieActu;

    couleurBarreDeVie.rouge = -255*(vieBarreDeVie/vieMaxBarreDeVie)+255;
    couleurBarreDeVie.vert = 255-couleurBarreDeVie.rouge;

    pleinBarreDeVie.setSize(sf::Vector2f(   dimensionBarreDeVie.x,
                                            vieBarreDeVie*(dimensionBarreDeVie.y/vieMaxBarreDeVie)));

    pleinBarreDeVie.setPosition(sf::Vector2f(   positionBarreDeVie.x,
                                                positionBarreDeVie.y+(vieMaxBarreDeVie-vieBarreDeVie)*(dimensionBarreDeVie.y/vieMaxBarreDeVie))); //pareil
    
    pleinBarreDeVie.setFillColor(sf::Color( int(couleurBarreDeVie.rouge),
                                            int(couleurBarreDeVie.vert),
                                            0));
}

void BarreDeVie:: affichageBarreDeVie(sf::RenderWindow& window) //attention vie négative
{
    if(vieBarreDeVie>0)
    {
        window.draw(videBarreDeVie);
        window.draw(pleinBarreDeVie);

        for(int i = 1; i < vieMaxBarreDeVie; i++)
        {
            separationBarreDeVie.setPosition(sf::Vector2f(  positionBarreDeVie.x,
                                                            positionBarreDeVie.y+i*(dimensionBarreDeVie.y/vieMaxBarreDeVie)));
            window.draw(separationBarreDeVie);
        }
    }
}
