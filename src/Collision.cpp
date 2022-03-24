#include "Collision.h"
#include "Objet.h"

RectangleCollision::RectangleCollision() 
//constructeur de la hitbox en focntion de la taille de l'objet ?
{
    positionRectCollision = sf::Vector2i(0, 0);
    dimentionRectCollision = sf::Vector2f(0, 0);
    visible = true;

    formeRectCollision.setOutlineColor(sf::Color::Black);// couleur du rectangle de collission
    formeRectCollision.setOutlineThickness(1.0f);//epaisseur du rectangle de collision
    formeRectCollision.setFillColor(sf::Color(0, 0, 0, 0)); //opacité et couleur du rectagle opacité = 0 = transparent
}

RectangleCollision::RectangleCollision(int x, int y, float width, float height) 
//constructeur avec choix de la hitbox
{
    positionRectCollision = sf::Vector2i(x, y);
    dimentionRectCollision = sf::Vector2f(std::max(0.0f, width), std::max(0.0f, height));
    formeRectCollision.setFillColor(sf::Color(0, 0, 0, 0));
}

void RectangleCollision::setPositionRectangleCollision(const sf::Vector2i& newPosition)
{
    positionRectCollision = newPosition;
}

bool RectangleCollision::checkCollision(const RectangleCollision& other)
// renvoie vrai si collision
{
    if( positionRectCollision.x + dimentionRectCollision.x >= other.positionRectCollision.x && 
        positionRectCollision.x <= other.positionRectCollision.x + other.dimentionRectCollision.x && 
        positionRectCollision.y + dimentionRectCollision.y >= other.positionRectCollision.y && 
        positionRectCollision.y <= other.positionRectCollision.y + other.dimentionRectCollision.y) 
    {
        return true;
    }

    return false;
}

void RectangleCollision::checkCollisionAngles(const RectangleCollision& other, bool &hg, bool& hd, bool &bg, bool &bd)
{
    if( positionRectCollision.x >= other.positionRectCollision.x && 
        positionRectCollision.x <= other.positionRectCollision.x + other.dimentionRectCollision.x && 
        positionRectCollision.y >= other.positionRectCollision.y && 
        positionRectCollision.y <= other.positionRectCollision.y + other.dimentionRectCollision.y)//Haut Gauche
    {
        hg=true;
    }

    if( positionRectCollision.x + dimentionRectCollision.x >= other.positionRectCollision.x && 
        positionRectCollision.x + dimentionRectCollision.x <= other.positionRectCollision.x + other.dimentionRectCollision.x && 
        positionRectCollision.y >= other.positionRectCollision.y && 
        positionRectCollision.y <= other.positionRectCollision.y + other.dimentionRectCollision.y)//Haut Droite
    {
        hd=true;
    }

    if( positionRectCollision.x >= other.positionRectCollision.x && 
        positionRectCollision.x <= other.positionRectCollision.x + other.dimentionRectCollision.x &&
        positionRectCollision.y + dimentionRectCollision.y >= other.positionRectCollision.y && 
        positionRectCollision.y + dimentionRectCollision.y <= other.positionRectCollision.y + other.dimentionRectCollision.y)//Bas Gauche
    {
        bg=true;
    }

    if( positionRectCollision.x + dimentionRectCollision.x >= other.positionRectCollision.x && 
        positionRectCollision.x + dimentionRectCollision.x <= other.positionRectCollision.x + other.dimentionRectCollision.x &&
        positionRectCollision.y + dimentionRectCollision.y >= other.positionRectCollision.y && 
        positionRectCollision.y + dimentionRectCollision.y <= other.positionRectCollision.y + other.dimentionRectCollision.y)//Bas Droite
    {
        bd=true;
    }
}


void RectangleCollision::renduRectangleCollision(sf::RenderWindow& window) 
//affiche le rectangle de collision
{
    formeRectCollision.setPosition(sf::Vector2f(positionRectCollision));
    formeRectCollision.setSize(dimentionRectCollision);
    window.draw(formeRectCollision);
}