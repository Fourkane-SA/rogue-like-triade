#include <string.h>
#include "Monstre.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Monstre::Monstre() {}

RectangleCollision* Monstre::getRectangleCollisionMonstre()
{
	return rectCollisionMonstre;
}

int Monstre::getVieMonstre()
{
	return pointsVieMonstre;
}

unsigned int Monstre:: getDegatsMonstre()
{
	return degatsAttaqueMonstre;
}

sf::Vector2i* Monstre:: getPositionMonstre()
{
	return &positionMonstre;
}

void Monstre:: initMonstre(std::string typeMonstre, sf::Vector2i position)
{
    if(typeMonstre.compare("Monstre") == 0)
	{
        pointsVieMonstre=30;
        degatsAttaqueMonstre=2;
        vitesseAttaqueMonstre=0.5f;
        vitesseDeplacementMonstre=3;
		dimensionMonstre = sf::Vector2i(64, 64);
		textureMonstre.loadFromFile("data/images/monster1.png");
	}

	if(typeMonstre.compare("Boss") == 0)
	{
		pointsVieMonstre=150;
        degatsAttaqueMonstre=7;
        vitesseAttaqueMonstre=0.5f;
        vitesseDeplacementMonstre=2;
		dimensionMonstre = sf::Vector2i(128, 128);
		textureMonstre.loadFromFile("data/images/boss.png");
	}

	positionMonstre=position;
	velociteMonstre=sf::Vector2i(0,0);
	spriteMonstre.setTexture(textureMonstre);
	spriteMonstre.setPosition(sf::Vector2f(positionMonstre));
	rectCollisionMonstre = new RectangleCollision(	positionMonstre.x,
													positionMonstre.y,
													dimensionMonstre.x,
													dimensionMonstre.y);

	rectCollisionMonstre->setPositionRectangleCollision(positionMonstre);
}

void Monstre:: miseAJourMonstre(const sf::Vector2i& positionPersonnage)
{

	if(	positionMonstre.x < positionPersonnage.x)
	{
		positionMonstre.x+=vitesseDeplacementMonstre;
		velociteMonstre.x=-vitesseDeplacementMonstre;
	}
	else if(positionMonstre.x > positionPersonnage.x)
	{
		positionMonstre.x-=vitesseDeplacementMonstre;
		velociteMonstre.x=vitesseDeplacementMonstre;
	}

	if(positionMonstre.y < positionPersonnage.y)
	{
		positionMonstre.y+=vitesseDeplacementMonstre;
		velociteMonstre.y=-vitesseDeplacementMonstre;
	}
	else if(positionMonstre.y > positionPersonnage.y)
	{
		positionMonstre.y-=vitesseDeplacementMonstre;
		velociteMonstre.y=vitesseDeplacementMonstre;
	}
	
	spriteMonstre.setPosition(sf::Vector2f(positionMonstre));
	rectCollisionMonstre->setPositionRectangleCollision(positionMonstre);
}

void Monstre:: collisionEntreMonstre(Monstre* autre)
{
	positionMonstre.x += velociteMonstre.x;
	positionMonstre.y += velociteMonstre.y;

	autre->positionMonstre.x -= velociteMonstre.x;
	autre->positionMonstre.y -= velociteMonstre.y;
}

void Monstre:: monstreEstTouche(int degats)
{
    pointsVieMonstre-=degats;
}

void Monstre:: renduMonstre(sf::RenderWindow& window)
{
 	window.draw(spriteMonstre);
	rectCollisionMonstre->renduRectangleCollision(window);
}

Monstre:: ~Monstre()
{
	delete rectCollisionMonstre;
}
