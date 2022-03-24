#include <SFML/Graphics.hpp>
#include <iostream>

#include "Objet.h"
#include "Collision.h"
 
using namespace std;


Object::Object() 
{
	rectCollisionObjet = nullptr;
}

void Object::initObjet( int x, int y) 
{
	int hazard = rand()%4;

	if(hazard == 0)
	{
		objetVie=5;
		objetAttaque=1;
		objetVitesseAttaque= 2000;
		objetVitesseDeplacement=0;

		textureObjet.loadFromFile("data/images/objet1.png");
	}

	if(hazard  == 1)
	{
		objetVie=2;
		objetAttaque=1;
		objetVitesseAttaque=0;
		objetVitesseDeplacement=3;

		textureObjet.loadFromFile("data/images/objet2.png");
	}

	if(hazard  == 2)
	{
		objetVie=0;
		objetAttaque=0;
		objetVitesseAttaque=-5000;
		objetVitesseDeplacement=0;

		textureObjet.loadFromFile("data/images/objet3.png");
	}

	if(hazard  == 3)
	{
		objetVie=0;
		objetAttaque=3;
		objetVitesseAttaque=0;
		objetVitesseDeplacement=0;

		textureObjet.loadFromFile("data/images/objet4.png");	
	}

	dimensionObjet = sf::Vector2i(32, 32);
	positionObjet = sf::Vector2i(x + dimensionObjet.x/2, y + dimensionObjet.y/2);

	rectCollisionObjet = new RectangleCollision(positionObjet.x,
                                                positionObjet.y,
                                            	dimensionObjet.x,
												dimensionObjet.y);

	
	spriteObjet.setTexture(textureObjet);
	spriteObjet.setPosition(sf::Vector2f(positionObjet));
    rectCollisionObjet->setPositionRectangleCollision(positionObjet);
}

sf::Vector2i Object::getPosition()
{
	return positionObjet;
}

sf::Vector2i Object::getSize()
{
	return dimensionObjet;
}

RectangleCollision* Object::getRectCollisionObjet() 
{
	return rectCollisionObjet;
}

void Object::renduObjet(sf::RenderWindow& window) 
{
	window.draw(spriteObjet);
	rectCollisionObjet->renduRectangleCollision(window);
}

Object::~Object()
{ 
	delete rectCollisionObjet;
}
