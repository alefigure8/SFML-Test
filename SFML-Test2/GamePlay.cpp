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
		o2.cmd(); //Obstaculo
		
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
		o2.update();

		//Colisiones
		collider();
	}
}

void GamePlay::draw(sf::RenderWindow& window)
{
	window.draw(p.getDraw()); //Pelota
	window.draw(o.getDraw()); //Obstaculo
	window.draw(o2.getDraw()); //Obstaculo
}

void GamePlay::collider()
{
		
	if (p.getLastPosition().y + p.getDraw().getGlobalBounds().height <= o.getDraw().getGlobalBounds().top 
		&& p.getDraw().getGlobalBounds().intersects(o.getDraw().getGlobalBounds())
		&& p.getSpeed() < 0) // Arriba
	{
		p.setFloor(p.getDraw().getPosition().x, o.getDraw().getGlobalBounds().top - p.getDraw().getGlobalBounds().height);
	}

	if (p.getDraw().getGlobalBounds().intersects(o.getDraw().getGlobalBounds()))
	{
		if (p.getLastPosition().x < p.getDraw().getPosition().x) // izquierda
		{
			p.setFloor(o.getDraw().getGlobalBounds().left - p.getDraw().getGlobalBounds().width, p.getDraw().getPosition().y);
			p.setState(true);
		}
		else if (p.getLastPosition().x > p.getDraw().getPosition().x) // derecha
		{
			p.setFloor(o.getDraw().getGlobalBounds().left + o.getDraw().getGlobalBounds().width, p.getDraw().getPosition().y);
			p.setState(true);
		}
	
	}

	if (p.getLastPosition().y + p.getDraw().getGlobalBounds().height <= o2.getDraw().getGlobalBounds().top
		&& p.getDraw().getGlobalBounds().intersects(o2.getDraw().getGlobalBounds())
		&& p.getSpeed() < 0) // Arriba
	{
		p.setFloor(p.getDraw().getPosition().x, o2.getDraw().getGlobalBounds().top - p.getDraw().getGlobalBounds().height);
	}

	if (p.getDraw().getGlobalBounds().intersects(o2.getDraw().getGlobalBounds()))
	{
		if (p.getLastPosition().x < p.getDraw().getPosition().x) // izquierda
		{
			p.setFloor(o2.getDraw().getGlobalBounds().left - p.getDraw().getGlobalBounds().width, p.getDraw().getPosition().y);
		}
		else if (p.getLastPosition().x > p.getDraw().getPosition().x) // derecha
		{
			p.setFloor(o2.getDraw().getGlobalBounds().left + o2.getDraw().getGlobalBounds().width, p.getDraw().getPosition().y);
		}

	}
	
}
