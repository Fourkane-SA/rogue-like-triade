#include "Projectile.h"
#include "Collision.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

void Projectile::initProjectile(const sf::Vector2i& positionPersonnage, const sf::Vector2i& dimensionPersonnage, const char directionDonnee)
{
    if(!textureProjectile.loadFromFile("data/images/projectile.png"))
    {
        cout<<"La texture du projectile n'est pas chargée"<<endl;
    }

    dimensionProjectile = sf::Vector2i(10,10); //arbitraire
    vitesseProjectile = 10; //arbitraire
    spriteProjectile.setTexture(textureProjectile);
    directionProjectile = directionDonnee;

    sf::Vector2i centrePersonnage = sf::Vector2i(   positionPersonnage.x+(dimensionPersonnage.x/2)-(dimensionProjectile.x/2),
                                                    positionPersonnage.y+(dimensionPersonnage.y/2)-(dimensionProjectile.y/2));
    int distanceApparition = 25; //arbitraire
    
    switch(directionProjectile)
	{
		case 'H':
        {
            positionProjectile = sf::Vector2i(  centrePersonnage.x,
                                                centrePersonnage.y-distanceApparition);
            break;
        }

        case 'B':
        {
            positionProjectile = sf::Vector2i(  centrePersonnage.x,
                                                centrePersonnage.y+distanceApparition);
            break;
        }

        case 'G':
        {
            positionProjectile = sf::Vector2i(  centrePersonnage.x-distanceApparition,
                                                centrePersonnage.y);
            break;
        }

        case 'D':
        {
            positionProjectile = sf::Vector2i(  centrePersonnage.x+distanceApparition,
                                                centrePersonnage.y);
            break;
        }
    }

    rectCollisionProjectile = new RectangleCollision (  positionProjectile.x,
                                                        positionProjectile.y,
                                                        dimensionProjectile.x,
                                                        dimensionProjectile.y);

    spriteProjectile.setPosition(sf::Vector2f(positionProjectile));
}

sf::Vector2i* Projectile::getPositionProjectile()
{
    return &positionProjectile;
}

RectangleCollision* Projectile::getRectCollisionProjectile()
{
    return rectCollisionProjectile;
}

void Projectile::deplacementProjectile()
{
    switch(directionProjectile)
    {
        case 'H':
        {
            positionProjectile.y-= vitesseProjectile;
            break;
        }

        case 'B':
        {
            positionProjectile.y+= vitesseProjectile;
            break;
        }

        case 'G':
        {
            positionProjectile.x-= vitesseProjectile;
            break;  
        }

        case 'D':
        {
            positionProjectile.x+= vitesseProjectile;
            break; 
        }
    }

    rectCollisionProjectile->setPositionRectangleCollision(positionProjectile);
    spriteProjectile.setPosition(sf::Vector2f(positionProjectile));
}

void Projectile::renduProjectile(sf::RenderWindow& window)
//affiche le projectile
{
    rectCollisionProjectile->renduRectangleCollision(window);
	window.draw(spriteProjectile);
}
