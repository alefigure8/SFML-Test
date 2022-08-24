#include "Obstacle.h"

sf::RectangleShape& Obstacle::getShape()
{
	return _shape;
}

Obstacle::Obstacle()
{
	_shape.setPosition(350, 450);
	_shape.setSize({ 100, 30 });
}

void Obstacle::cmd()
{
}

void Obstacle::update()
{
}

sf::RectangleShape& Obstacle::getDraw()
{
	return _shape;
}
