#include <iostream>
#include "Etage.h"
#include "Salle.h"
#include "Collision.h"
#include "Personnage.h"

using namespace std;

Etage::Etage()
{
    positionSalleActuEtage = sf::Vector2i(0, 0);
    nombreSalleEtage = 25;
    for(int y=0; y<10; y++)
    {
        for(int x=0; x<10; x++)
        {
            patternEtage[x][y]= 0;
            if(tabSallesEtage[x][y]!= nullptr)
            {
                tabSallesEtage[x][y]=nullptr;
            }
        }
    }
    finNiveau = false;
}

bool Etage::salleLibreEtage(const int& x, const int& y)
{
    int voisins=0;

    if(x>1)
    {
        if(patternEtage[x-1][y]!=0)
        {
            voisins++;
        }
    }

    if(x<10)
    {
        if(patternEtage[x+1][y]!=0)
        {
            voisins++;
        }
    }

    if(y>1)
    {
        if(patternEtage[x][y-1]!=0)
        {
            voisins++;
        }
    }

    if(y<10)
    {
        if(patternEtage[x][y+1]!=0)
        {
            voisins++;
        }
    }

    return (voisins==1);
}

void Etage::generationPatternEtage()
{
    int x;
    int y;

    //Création de la salle de départ
    x = (rand()%8) +1;
    y = (rand()%8) +1;
    patternEtage[x][y]=1;
    positionSalleActuEtage.x=x;
    positionSalleActuEtage.y=y;
    
    //Création des salles "normales"
    for(int i=1; i<nombreSalleEtage-2; i++)
    {
        do
        {
            x = (rand()%8) +1;
            y = (rand()%8) +1;

        } while(patternEtage[x][y]!=0 || !salleLibreEtage(x,y));

        patternEtage[x][y]=2;
    }

    //Création de la salle objet
    do
    {
        x = (rand()%8) +1;
        y = (rand()%8) +1;

    } while(patternEtage[x][y]!=0 || !salleLibreEtage(x,y));

    patternEtage[x][y]=3;

    //Création de la salle de boss
    do
    {
        x = (rand()%8) +1;
        y = (rand()%8) +1;

    } while(patternEtage[x][y]!=0 || !salleLibreEtage(x,y));

    patternEtage[x][y]=4;
}

void Etage::chargeEtage() 
{
    for(int y=0; y<10; y++)
    {
        for(int x=0; x<10; x++)
        {
            if(patternEtage[x][y]!=0)
            {
                Salle* ptrSalle = new Salle();
                ptrSalle->initSalle(this, x, y,patternEtage[x][y]);
                tabSallesEtage[x][y] = ptrSalle;
            }
        }
    }
}

void Etage::chargeSalleEtage(int x, int y)
//charge la nouvelle salle actuel
{
    bool trouve = false;

    for(Salle* salle : *tabSallesEtage) 
    {
        if(salle->getPositionSalle().x == x && salle->getPositionSalle().y == y)
        {
            positionSalleActuEtage = sf::Vector2i(x, y);
            trouve = true;
            break;
        }
    }

    if(trouve) 
    {
        std::cout << "Salle trouvée à cette position\n";
    } 
    else std::cout << "Pas de salle trouvée à cette position\n";
}

void Etage::miseAJourEtage(Personnage* personnage)
//charge la salle actuel
{
    if(personnage->getPositionPerso().y + personnage->getDimensionPerso().y >832)
    {
        positionSalleActuEtage.y++;
        personnage->setPositionPerso(sf::Vector2i(  (832 - personnage->getDimensionPerso().x)/2,
                                                    74));

        personnage->videProjectile();
        personnage->setInvincibilite(500000);

        tabSallesEtage[positionSalleActuEtage.x][positionSalleActuEtage.y]->setVisite();
    }
    else if (personnage->getPositionPerso().y < 0)
    {
        positionSalleActuEtage.y--;
        personnage->setPositionPerso(sf::Vector2i(  (832 - personnage->getDimensionPerso().x)/2,
                                                    758-personnage->getDimensionPerso().y));

        personnage->videProjectile();
        personnage->setInvincibilite(500000);

        tabSallesEtage[positionSalleActuEtage.x][positionSalleActuEtage.y]->setVisite();
    }
    else if (personnage->getPositionPerso().x<0)
    {
        positionSalleActuEtage.x--;
        personnage->setPositionPerso(sf::Vector2i(  758 - personnage->getDimensionPerso().x,
                                                    (832 - personnage->getDimensionPerso().y)/2));

        personnage->videProjectile();
        personnage->setInvincibilite(500000);

        tabSallesEtage[positionSalleActuEtage.x][positionSalleActuEtage.y]->setVisite();
    }
    else if (personnage->getPositionPerso().x + personnage->getDimensionPerso().x > 832)
    {
        positionSalleActuEtage.x++;
        personnage->setPositionPerso(sf::Vector2i(  74,
                                                    (832 - personnage->getDimensionPerso().y)/2));

        personnage->videProjectile();
        personnage->setInvincibilite(500000);

        tabSallesEtage[positionSalleActuEtage.x][positionSalleActuEtage.y]->setVisite();
    }

    personnage->miseAJourPerso();
    tabSallesEtage[positionSalleActuEtage.x][positionSalleActuEtage.y]->miseAJourSalle(personnage,this);
}

void Etage::renduEtage(sf::RenderWindow& window)
//affichage de la salle
{
    if(tabSallesEtage[positionSalleActuEtage.x][positionSalleActuEtage.y]!= nullptr)
    {
        tabSallesEtage[positionSalleActuEtage.x][positionSalleActuEtage.y]->renduSalle(window);
        
    } 
    else
    {
        cout << "Erreur La salle n'a pas été créée" << endl;
    }
    renduMap(window);
}

void Etage::afficherConsole(){
    for(int y=0; y<10; y++)
    {
        for(int x=0; x<10; x++)
        {
            cout << patternEtage[x][y] << " ";
        }
        cout << endl;
    }
}

Etage::~Etage()
//destructeur par defaut
{
    for(int y=0; y<10; y++)
    {
        for(int x=0; x<10; x++)
        {
            if(tabSallesEtage[x][y] != nullptr)
            {
                delete tabSallesEtage[x][y];
            }
        }
    }
}

void Etage::renduMap(sf::RenderWindow& window){
    sf::CircleShape cercle(64);
    cercle.setFillColor(sf::Color(0,0,0,50));
    window.draw(cercle);
    sf::RectangleShape rectangle (sf::Vector2f(6.4,6.4));
    rectangle.setOrigin(3.2,3.2);
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(patternEtage[i][j]!=0 && tabSallesEtage[i][j]->getVisite()){
                if(positionSalleActuEtage == sf::Vector2i(i,j)){
                    rectangle.setFillColor(sf::Color(255,0,0));
                }
                else {
                    rectangle.setFillColor(sf::Color(255,255,255));
                }
                rectangle.setPosition(32+i*6.4,32+j*6.4);
                window.draw(rectangle);
            }
        }
    }
}

sf::Vector2i Etage::getPositionSalleActu()
{
    return positionSalleActuEtage;
}

void Etage::setFinNiveau()
{
    finNiveau = true;
}

bool Etage::getFinNiveau()
{
    return finNiveau;
}