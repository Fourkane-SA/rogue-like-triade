#include <SFML/Graphics.hpp>
#include <time.h>
#include "BarreDeVie.h"
#include "Obstacle.h"
#include "Personnage.h"
#include "Projectile.h"
#include "Collision.h"
#include <iostream>
using namespace std;

Personnage::Personnage()
//constructeur de base
{

    attaquePerso.clear();
    listeObjetPerso.clear();
}

void Personnage::initPersonnage(unsigned char choix,const sf::Vector2i& dimensionPersoFenetre) //entre D,E ou T
//initialisation du personnage
{
	switch(choix) //valeures arbitraires et non définitives 	
    {
		case 'D': //personnage degat
		{
            dimensionPerso = sf::Vector2i(64, 64);

            pointsVieMaxPerso=5;
            pointsViePerso=pointsVieMaxPerso;

            degatsAttaquePerso=6;

            vitesseAttaquePerso=50000;

            vitesseDeplacementPerso=3;
            invincibilitePerso=false;

            break;
 		}

 		case 'E': //personnage equilibre
 		{
            dimensionPerso = sf::Vector2i(64, 64);

            pointsVieMaxPerso=10;
            pointsViePerso=pointsVieMaxPerso;

            degatsAttaquePerso=5;

            vitesseAttaquePerso=75000;

            vitesseDeplacementPerso=4;

            break;
 		}

 		case 'T': //perosnnage tank
 		{
            dimensionPerso = sf::Vector2i(64, 64);

            pointsVieMaxPerso=15;
            pointsViePerso=pointsVieMaxPerso;

            degatsAttaquePerso=3;

            vitesseAttaquePerso=100000;

            vitesseDeplacementPerso=3;

            break;
		}
    }

    texturePerso.loadFromFile("data/images/skeletron.png");

    positionPerso = sf::Vector2i(   416 - dimensionPerso.x/2, 
                                    416 - dimensionPerso.y/2);

    animationPerso = sf::Vector2i(1, 8);

    intervalleAttaquePerso=clock()+vitesseAttaquePerso;

    barreDeViePerso = new BarreDeVie;
    barreDeViePerso->initBarreDeVie(dimensionPersoFenetre,pointsVieMaxPerso);

    invincibilitePerso=false;
    dureeInvincibilitePerso = 250000;
    intervalleInvincibilitePerso=clock()+dureeInvincibilitePerso;

    spritePerso.setTexture(texturePerso);
    spritePerso.setTextureRect(sf::IntRect( positionPerso.x, 
                                            positionPerso.y, 
                                            dimensionPerso.x, 
                                            dimensionPerso.y));

    rectCollisionPerso = new RectangleCollision(positionPerso.x+16, 
                                                positionPerso.y+24, 
                                                32, 48);  
}

void Personnage::setPositionPerso(const sf::Vector2i& newPosition)
//affecte une nouvelle position au personnage
{
    positionPerso = newPosition;
}

sf::Vector2i Personnage::getPositionPerso()
//renvoie la position du personnage
{
	return positionPerso;
}

void Personnage::setDimensionPerso(const sf::Vector2i& newDimension)
//change les dimensions du personnage
{
    dimensionPerso = newDimension;
}

sf::Vector2i Personnage::getDimensionPerso()
//renvoie les dimension du personnage
{
	return dimensionPerso;
}

RectangleCollision* Personnage::getRectCollisionPerso()
//retourne un rectangle de collision
{
	return rectCollisionPerso;
}

unsigned int Personnage:: getDegatsPersonnage()
{
    return degatsAttaquePerso;
}

void Personnage:: setInvincibilite(int duree)
{
    invincibilitePerso = true;
    intervalleInvincibilitePerso = clock() + duree;
}

void Personnage::ajoutObjetPerso(Object* objetSalle)
{
    pointsVieMaxPerso+=objetSalle->objetVie;
    pointsViePerso+=objetSalle->objetVie;
    degatsAttaquePerso+=objetSalle->objetAttaque;
    vitesseAttaquePerso+=objetSalle->objetVitesseAttaque;
    vitesseDeplacementPerso+=objetSalle->objetVitesseDeplacement;
}

void Personnage::addProjectile(const char directionDonnee)
{
    Projectile* nouveauProjectile = new Projectile;
    nouveauProjectile->initProjectile(  positionPerso, 
                                        dimensionPerso, 
                                        directionDonnee);

    attaquePerso.push_back(nouveauProjectile);
}

bool Personnage::gestionProjectile(RectangleCollision* other)
{
    bool touche = false;

    for(size_t i = 0; i < attaquePerso.size(); i++)
    {
        if( attaquePerso[i]->getRectCollisionProjectile()->checkCollision(*other) ||
            (   attaquePerso[i]->getPositionProjectile()->x < 0 ||
                attaquePerso[i]->getPositionProjectile()->x > 832 ) ||
            (   attaquePerso[i]->getPositionProjectile()->y < 0 || 
                attaquePerso[i]->getPositionProjectile()->y > 832 ) )
        {
            touche = true;
            delete(attaquePerso[i]);
            attaquePerso.erase(attaquePerso.begin() + i);
        }
    }

    return touche;
}

void Personnage::videProjectile()
{
    for(size_t i = 0; i < attaquePerso.size(); i++)
    {
        delete(attaquePerso[i]);
    }

    attaquePerso.clear();
}

void Personnage::miseAJourPerso()
//met a jour le personnage
{
    ///////////////////////////////////////////////////////////////////////////
    //Deplacement

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        positionPerso.y -= vitesseDeplacementPerso;
        animationPerso.x++;
        animationPerso.y = 8;

        velocitePerso.y = 2*vitesseDeplacementPerso;
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        positionPerso.y += vitesseDeplacementPerso;
        animationPerso.x++;
        animationPerso.y = 8 + 2;

        velocitePerso.y = -2*vitesseDeplacementPerso;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) 
    {
        positionPerso.x -= vitesseDeplacementPerso;
        animationPerso.x++;
        animationPerso.y = 8 + 1;

        velocitePerso.x = 2*vitesseDeplacementPerso;
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    {
        positionPerso.x += vitesseDeplacementPerso;
        animationPerso.x++;
        animationPerso.y = 8 + 3;

        velocitePerso.x = -2*vitesseDeplacementPerso;
    } 

    if(animationPerso.x > 8) 
    {
        animationPerso.x = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    //Attaque

    if(clock()>=intervalleAttaquePerso)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            addProjectile('H');
            intervalleAttaquePerso=clock() + vitesseAttaquePerso;
        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            addProjectile('B');
            intervalleAttaquePerso=clock() + vitesseAttaquePerso;
        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            addProjectile('G');
            intervalleAttaquePerso=clock() + vitesseAttaquePerso;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            addProjectile('D');
            intervalleAttaquePerso=clock() + vitesseAttaquePerso;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //Invincibilite

    if(invincibilitePerso && clock()>=intervalleInvincibilitePerso)
    {
        invincibilitePerso=false;
    }

    ///////////////////////////////////////////////////////////////////////////
    
    spritePerso.setTextureRect(sf::IntRect( animationPerso.x * 64, 
                                            animationPerso.y * 64, 
                                            dimensionPerso.x, 
                                            dimensionPerso.y));

    spritePerso.setPosition(sf::Vector2f(positionPerso));
    rectCollisionPerso->setPositionRectangleCollision(positionPerso + sf::Vector2i(16,14));

    barreDeViePerso->miseAJourBarreDeVie(pointsVieMaxPerso, pointsViePerso);

    for(Projectile* p : attaquePerso)
    {
        p->deplacementProjectile();
    }
}

void Personnage::persoEstTouche(int degats)
{
    if(!invincibilitePerso)
    {
        pointsViePerso-=degats;
        invincibilitePerso = true;
        intervalleInvincibilitePerso = clock() + dureeInvincibilitePerso;
    }
}

void Personnage::effetCollisionPerso(Obstacle* obstacle)
//affect l'efet de l'obstacle sur le personnage
{ 
    if(!invincibilitePerso && obstacle->getDegatsObstacle() !=0 )
    {
        pointsViePerso-= obstacle->getDegatsObstacle();
        invincibilitePerso = true;
        intervalleInvincibilitePerso = clock() + dureeInvincibilitePerso;
    }
}

void Personnage::collisionMur(bool& hg, bool& hd, bool& bg, bool& bd)
//evite le personnage de traverser le mur
{ 
    if(hg ^ hd ^ bg ^ bd)
    {
        if(hg)
        {
            if(velocitePerso.x>0)
            {
                bg=true;
            }
            else if(velocitePerso.y>0)
            {
                hd=true;
            }
        } 
        else if(hd)
        {
            if(velocitePerso.x<0)
            {
                bd=true;
            }
            else if(velocitePerso.y>0)
            {
                hg=true;
            } 
        }
        else if(bg)
        {
            if(velocitePerso.x>0)
            {
                hg=true;
            }
            else if(velocitePerso.y<0)
            {
                bd=true;
            }  
        }
        else if(bd)
        {
            if(velocitePerso.x<0)
            {
                hd=true;
            }
            else if(velocitePerso.y<0)
            {
                bg=true;
            } 
        }
    }

    if((hg && bg) || (hd && bd))
    {
        positionPerso.x += velocitePerso.x;
    }
    
    if((hg && hd) || (bg && bd))
    {
        positionPerso.y += velocitePerso.y;
    }
}

void Personnage::renduPerso(sf::RenderWindow& window)
//affiche le personnage 
{
    for(Projectile* p : attaquePerso)
    {
        p->renduProjectile(window);
    }

    rectCollisionPerso->renduRectangleCollision(window);
    barreDeViePerso->affichageBarreDeVie(window);
	window.draw(spritePerso);
}

Personnage::~Personnage()
{
    if(barreDeViePerso!= nullptr) delete barreDeViePerso;
    if(rectCollisionPerso!= nullptr) delete rectCollisionPerso;
}

int Personnage::getPointsViePerso()
{
    return pointsViePerso;
}