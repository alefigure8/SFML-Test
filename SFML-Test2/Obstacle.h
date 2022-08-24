#pragma once
#include <SFML/Graphics.hpp>

class Obstacle
{
private:
	sf::RectangleShape _shape;
protected:
	sf::RectangleShape& getShape();
public:
	Obstacle();
	void cmd();
	void update();
	sf::RectangleShape& getDraw();
	
};

