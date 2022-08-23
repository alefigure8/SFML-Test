#include <SFML/graphics.hpp>
#include "GamePlay.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(60);

	GamePlay gp;
	
    while (window.isOpen())
    {
		
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
        gp.cmd();
        gp.update();
	
        window.clear(sf::Color(150,150,150));
        gp.draw(window);
        window.display();
    }

    return 0;
}