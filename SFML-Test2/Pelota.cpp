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
    _move.x = 0;
    _move.y = 0;
	
    if (_state == Pelota::IDLE)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            _state = STATE::WALK_FRONT;
            _speed_forward = 5.0f;
            last_key = 'D';


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                _state = STATE::JUMP;
                _speed_jump = 15.0f;
                _speed_forward = 12.0f;
                buffer_speed = 0.0f;
                last_key = 'D';

            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            _state = STATE::WALK_BACK;
            _speed_backward = -5.0f;
            last_key = 'A';


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                _state = STATE::JUMP;
                _speed_jump = 15.0f;
                _speed_backward = -12.0f;
                buffer_speed = 0.0f;
                last_key = 'A';
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            buffer_speed += 0.5f;
            std::cout << buffer_speed << std::endl;
            last_key = 'W';
        }

        if (last_key == 'W' && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _state = STATE::JUMP;
			
            if (buffer_speed < 20.0f && buffer_speed > 2.0f) {
				
                if (buffer_speed < 10.0f) {
                    _speed_jump = 15.0f;
					
                }
                else
                {
			        _speed_jump = buffer_speed;
                }
            }
            else if (buffer_speed < 2.0f)
            {
                buffer_speed = 0;
            }
            else
            {
				_speed_jump = 20.0f;
            }
			
			buffer_speed = 0.0f;
            last_key = 'D';
        }

    }
 

}

void Pelota::update()
{
    //switch (_state)
    //{
    //case Pelota::IDLE:
    //    break;
    //case Pelota::WALK_FRONT:
    //    //std::cout << "Walk front" << std::endl;
    //    //_move.x = 5;
    //    //_state = STATE::IDLE;
    //    break;
    //case Pelota::WALK_BACK:
    //    //std::cout << "Walk back" << std::endl;
    //    //_move.x = -4;
    //    //_state = STATE::IDLE;
    //    break;
    //case Pelota::JUMP:
    //    break;
    //}
	
	//FRENO
    _speed_forward -= 0.5f;
    if (_speed_forward > 0)
    {
        _move.x = _speed_forward;
    }

    _speed_backward += 0.5f;
    if (_speed_backward < 0)
    {
        _move.x = _speed_backward;
    } 
	
	//GRAVEDAD
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
	_speed_backward = 0;
	_speed_forward = 0;
	_move.x = 0;
	_move.y = 0;
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

void Pelota::setState(bool state)
{
    if (state)
        _state = Pelota::JUMP;
    else
        _state = Pelota::IDLE;
}

