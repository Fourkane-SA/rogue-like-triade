#include "Obstacle.h"
#include "Collision.h"
#include <string.h>
#include <SFML/Graphics.hpp>
#include <iostream>

Obstacle::Obstacle(){}

RectangleCollision* Obstacle:: getRectCollisionObstacle()
{
    return rectCollisionObstacle;
}

bool Obstacle:: getFranchissableObstacle()
{
    return franchissableObstacle;
}

unsigned int Obstacle:: getDegatsObstacle()
{
    return degatsObstacle;
}


void Obstacle::initObstacle(char typeObstacle, const sf::Vector2i& position)
{
    switch(typeObstacle)
    {
        case 'S': // Sol
        {
            degatsObstacle=0;
            franchissableObstacle=true;
            destructibleObstacle=false;
            textureObstacle.loadFromFile("data/images/floor.png");

            break;
        }
        
        case 'M': // Mur
        {
            degatsObstacle=0;
            franchissableObstacle=false;
            destructibleObstacle=false;
            textureObstacle.loadFromFile("data/images/wall.png");

            break;
        }
        
        case 'P': // Piege
        {
            degatsObstacle=2;
            franchissableObstacle=true;
            destructibleObstacle=false;  
            textureObstacle.loadFromFile("data/images/trap.png");

            break;
        }
    }

    positionObstacle = sf::Vector2i(position.x*64,
                                    position.y*64);
                                    
    rectCollisionObstacle = new RectangleCollision( positionObstacle.x,
                                                    positionObstacle.y,
                                                    64, 64);

    spriteObstacle.setTexture(textureObstacle);
    spriteObstacle.setPosition(sf::Vector2f(positionObstacle));
    rectCollisionObstacle->setPositionRectangleCollision(positionObstacle);
}

void Obstacle:: renduObstacle(sf::RenderWindow& window)
{
    window.draw(spriteObstacle);
    rectCollisionObstacle->renduRectangleCollision(window);
}
