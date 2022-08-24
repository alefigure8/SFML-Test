#include "ObstacleRed.h"
#include <SFML/Graphics.hpp>


ObstacleRed::ObstacleRed()
{
	getShape().setFillColor(sf::Color::Red);
	getShape().setPosition(350, 300);
}
