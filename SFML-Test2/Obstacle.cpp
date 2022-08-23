#include "Obstacle.h"

Obstacle::Obstacle()
{
	_shape.setPosition(350, 320);
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
