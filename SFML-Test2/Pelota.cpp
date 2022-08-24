#include "Pelota.h"
#include <iostream>

Pelota::Pelota()
{
    _shape.setFillColor(sf::Color::Magenta);
    _shape.setRadius(20.0f);
    _shape.setPosition(350.0f, 200.0f);
	_state = STATE::IDLE;
	_speed_jump = 0.0f;
}

void Pelota::cmd()
{
     _move.x = _move.y = 0;

    if (_state == Pelota::IDLE)
    {
		
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            _state = STATE::WALK_FRONT;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            _state = STATE::WALK_BACK;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _state = STATE::JUMP;
            _speed_jump = 20.0f;
        }
    }

}

void Pelota::update()
{
    switch (_state)
    {
    case Pelota::IDLE:
        //Personaje quieto. Respiración.
        break;
    case Pelota::WALK_FRONT:
        _move.x = 5;
        _state = STATE::IDLE;
        break;
    case Pelota::WALK_BACK:
        _move.x = -4;
        _state = STATE::IDLE;
        break;
    case Pelota::JUMP:
        _state = STATE::IDLE;
        break;
    }
	
	//GRAVITY
    _speed_jump -= 1.0f; 
    _move.y -= _speed_jump;
    move(_move.x, _move.y);
}

sf::CircleShape& Pelota::getDraw()
{
    return _shape;
}

void Pelota::setFloor(float x, float y)
{
    _state = STATE::IDLE;
    _speed_jump = 0;
	_shape.setPosition(x, y);
}

void Pelota::loseSpeed()
{
	_speed_jump = 0;
	
}

float Pelota::getSpeed()
{
    return _speed_jump;
}

void Pelota::move(float x, float y)
{
    _last_position = _shape.getPosition();
    _shape.move(x, y);
}

sf::Vector2f Pelota::getLastPosition()
{
    return _last_position;
}

