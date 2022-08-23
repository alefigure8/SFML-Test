#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay()
{
	_state = STATE_GAME::PLAY;
	_pause = false;
}

void GamePlay::cmd()
{
	if(!_pause)
	{
		p.cmd(); //Pelota
		o.cmd(); //Obstaculo
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_state = STATE_GAME::PAUSE;
			_pause = true;
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_state = STATE_GAME::PLAY;
			_pause = false;
		}
	}
}

void GamePlay::update()
{
	if (_state == STATE_GAME::PLAY)
	{
		//Pelota
		p.update();

		//Suelo pelota
		if (p.getDraw().getPosition().y > 500) { // SUELO = 500
			p.setFloor(p.getDraw().getPosition().x, 500);
		}
		
		//Obstaculo
		o.update();

		//Colisiones
		collider();
	}
}

void GamePlay::draw(sf::RenderWindow& window)
{
	window.draw(p.getDraw()); //Pelota
	window.draw(o.getDraw()); //Obstaculo
}

void GamePlay::collider()
{
	if (p.getLastPosition().y + p.getDraw().getGlobalBounds().height <= o.getDraw().getGlobalBounds().top 
		&& p.getDraw().getGlobalBounds().intersects(o.getDraw().getGlobalBounds()) 
		&& p.getSpeed() < 0)
	{
		p.setFloor(p.getDraw().getPosition().x, o.getDraw().getGlobalBounds().top - p.getDraw().getGlobalBounds().height);
	}
}
