#include "Etage.h"
#include "Salle.h"
#include "Objet.h"
#include "Etage.h"
#include <math.h>
#include <iostream>
using namespace std;

Salle::Salle() 
{
    positionSalle = sf::Vector2i(0, 0);

    for(int y=0; y<13; y++)
    {
        for(int x=0; x<13; x++)
        {
            elementSalle[x][y]='X';
        }
    }

    objetSalle = nullptr;
    tabObstacleSalle.clear();
    tabMonstreSalle.clear();
}

sf::Vector2i Salle::getPositionSalle()
{
    return positionSalle;
}

int Salle::voisinsSalle(int x, int y)
{
    int voisinsSalle=0;

    if( elementSalle[x-1][y]=='M' || 
        elementSalle[x-1][y]=='P')
    {
        voisinsSalle++;
    }

    if( elementSalle[x+1][y]=='M' || 
        elementSalle[x-1][y]=='P')
    {
        voisinsSalle++;
    }

    if( elementSalle[x][y-1]=='M' || 
        elementSalle[x-1][y]=='P')
    {
        voisinsSalle++;
    }

    if( elementSalle[x][y+1]=='M' || 
        elementSalle[x-1][y]=='P')
    {
        voisinsSalle++;
    }

    return voisinsSalle;
}

void Salle::initSalle(Etage* e, int ySalle, int xSalle, int type)
{
    visite = (type == 1);//Initialise a vrai si la salle est la salle de départ

    int xrand,yrand;

    int n;//Nombre de murs en plus des contours et de 4 murs

    for(int y=0; y<13; y++)
    {
        for(int x=0; x<13; x++)
        {
            if(x==0 || x==12 || y==0 || y==12)
            {
                elementSalle[x][y]='M';
            } 

            else 
            {
                elementSalle[x][y]='S';
            }
        }
    }

    if(type==2)
    {
        for(int y=2; y<8; y+=5)
        {
            for(int x=2; x<8; x+=5)
            {
                xrand=rand()%4+x;
                yrand=rand()%4+y;
                elementSalle[xrand][yrand]='M';
            }
        }
        
        n = rand()%15+5;

        while(n >0)
        {
            do
            {
                xrand=(int)rand()%9+2;
                yrand=(int)rand()%9+2;//2-8
            }
            while(elementSalle[xrand][yrand]!='S' || voisinsSalle(xrand,yrand)==0);

            elementSalle[xrand][yrand]='M';
            n--;
        }

        for(int y=2; y<=10; y++)
        {
            for(int x=2; x<=10; x++)
            {
                if(voisinsSalle(x, y)>2)
                {
                    elementSalle[x][y]='M';
                }
            }
        }

        int nbMonstreSalle = rand()%3 + 2;

        for(int i = 0; i<nbMonstreSalle; i++)
        {
            Monstre* ptrMonstre = new Monstre();

            do
            {
                xrand=(int)rand()%9+2;
                yrand=(int)rand()%9+2;//2-10
            }
            while(elementSalle[xrand][yrand]!='S');

            ptrMonstre->initMonstre("Monstre", sf::Vector2i(   xrand *64,
                                                            yrand *64));
            tabMonstreSalle.push_back(ptrMonstre);
        }
    }
    
    if(type ==  3)
    {
        objetSalle = new Object;
        objetSalle->initObjet(384,384);
    }
    
    if(type == 4)
    {
        for(int i=0; i<2; i++)
        {
            elementSalle[2][2+i] ='P';
            elementSalle[2+i][2] ='P';

            elementSalle[2][10-i] ='P';
            elementSalle[2+i][10] ='P';

            elementSalle[10][2+i] ='P';
            elementSalle[10-i][2] ='P';
            
            elementSalle[10][10-i] ='P';
            elementSalle[10-i][10] ='P';
        }
        
        Monstre* ptrBoss = new Monstre();
        ptrBoss->initMonstre("Boss", sf::Vector2i(384, 384));
        tabMonstreSalle.push_back(ptrBoss);

    }

    for(int y=0; y<13; y++) //boucle finale à revoir pour opti
    {
        for(int x=0; x<13; x++)
        {
            Obstacle* ptrObstacle = new Obstacle;
            ptrObstacle->initObstacle(  elementSalle[x][y],
                                        sf::Vector2i(x, y));
            
            tabObstacleSalle.push_back(ptrObstacle);
        }
    }
}

void Salle::miseAJourSalle(Personnage* personnage, Etage* e)
{
    if(tabMonstreSalle.size() ==0)
    {
        if(e->patternEtage[e->getPositionSalleActu().x][e->getPositionSalleActu().y]==4)
        {
            e->setFinNiveau();
        }
        else
        {
            sf::Vector2i pos = e->getPositionSalleActu();
            bool modif = false;
            if(e->patternEtage[pos.x-1][pos.y]!=0 && elementSalle[0][6]!='S')
            {
                elementSalle[0][6]='S';
                modif = true;
            }
            
            if(e->patternEtage[pos.x+1][pos.y]!=0 && elementSalle[12][6]!='S')
            {
                elementSalle[12][6]='S';
                modif = true;
            }
            if(e->patternEtage[pos.x][pos.y-1]!=0 && elementSalle[6][0]!='S')
            {
                elementSalle[6][0]='S';
                modif = true;
            }
            if(e->patternEtage[pos.x][pos.y+1]!=0 && elementSalle[6][12]!='S')
            {
                elementSalle[6][12]='S';
                modif = true;
            }
            if(modif)
            {
                tabObstacleSalle.clear();
                for(int y=0; y<13; y++) //boucle finale à revoir pour opti
                {
                    for(int x=0; x<13; x++)
                    {
                        Obstacle* ptrObstacle = new Obstacle;
                        ptrObstacle->initObstacle(  elementSalle[x][y],
                                                    sf::Vector2i(x, y));
                        
                        tabObstacleSalle.push_back(ptrObstacle);
                    }
                }
            }
        }      
    }

    bool hg = false;
    bool hd = false;
    bool bg = false;
    bool bd = false;

    for(Obstacle* obs : tabObstacleSalle)
    {
        if(obs->getFranchissableObstacle())
        {
            if(personnage->getRectCollisionPerso()->checkCollision(*obs->getRectCollisionObstacle()))
            {
                personnage->effetCollisionPerso(obs);
            }
        }
        else
        {
            personnage->gestionProjectile(obs->getRectCollisionObstacle());

            if(personnage->getRectCollisionPerso()->checkCollision(*obs->getRectCollisionObstacle()))
            {
                personnage->getRectCollisionPerso()->checkCollisionAngles(*obs->getRectCollisionObstacle(), hg, hd, bg, bd);
            }
        }
    }

    personnage->collisionMur(hg, hd, bg, bd);

    size_t i=0;
    for(Monstre* monstre : tabMonstreSalle)
    {
        monstre->miseAJourMonstre(personnage->getPositionPerso());
        
        for(Monstre* monstre1 : tabMonstreSalle)
        {
            if(monstre->getRectangleCollisionMonstre()->checkCollision(*monstre1->getRectangleCollisionMonstre()))
            {
                monstre->collisionEntreMonstre(monstre1);
            }
        }

        if( personnage->gestionProjectile(monstre->getRectangleCollisionMonstre()))
        {
            monstre->monstreEstTouche(personnage->getDegatsPersonnage());
            if(monstre->getVieMonstre() < 1)
            {
                delete(tabMonstreSalle[i]);
                tabMonstreSalle.erase(tabMonstreSalle.begin() + i);
            }
        }
        i++;

        if(personnage->getRectCollisionPerso()->checkCollision(*monstre->getRectangleCollisionMonstre()))
        {
            personnage->persoEstTouche(monstre->getDegatsMonstre());
        }
    }

    if( objetSalle != nullptr &&
        personnage->getRectCollisionPerso()->checkCollision(*objetSalle->getRectCollisionObjet()))
    {
        personnage->ajoutObjetPerso(objetSalle);

        delete objetSalle;
        objetSalle = nullptr;
    }
}

void Salle::renduSalle(sf::RenderWindow& window)
{
    afficherConsole();

    for(Obstacle* obs : tabObstacleSalle)
    {
        obs->renduObstacle(window);
    }

    for(Monstre* monstre : tabMonstreSalle)
    {
        monstre->renduMonstre(window);
    }

    if(objetSalle != nullptr) objetSalle->renduObjet(window);
}

Salle::~Salle() 
{
    for(Monstre* m : tabMonstreSalle)
    {
        free(m);
    }
    objetSalle = nullptr;
    tabMonstreSalle.clear();
}

void Salle::afficherConsole()
{
    for(int y=0; y<13; y++)
    {
        for(int x=0; x<13; x++)
        {
            cout << elementSalle[x][y] << " ";
        }
        cout << endl;
    }
}

void Salle::setVisite()
{
    visite=true;
}

bool Salle::getVisite(){
    return visite;
}