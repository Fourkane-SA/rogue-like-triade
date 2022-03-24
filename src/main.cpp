#include <map>
#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "Etage.h"

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(832, 832), "TriLand", sf::Style::Close);
    window.setFramerateLimit(60);
    
    char choixPerso ='X';
    Jeu* jeu = new Jeu;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || 
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            if(choixPerso =='X')
            {
                sf::Texture textureEcranD;
                textureEcranD.loadFromFile("data/images/demarrage.png");

                sf::Sprite spriteEcranD(textureEcranD);
                spriteEcranD.setPosition(0,0);

                while(choixPerso == 'X')
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
                    {
                        choixPerso = 'T';
                    }

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                    {
                        choixPerso = 'E';
                    }

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        choixPerso = 'D';
                    }

                    window.clear();
                    window.draw(spriteEcranD);
                    window.display();
                }

                jeu->initJeu(choixPerso,'1');
            }
        }

        jeu->miseAJourJeu();
        window.clear();
        jeu->renduJeu(window);
        window.display();
    }

    delete jeu;
    return 0;
}
