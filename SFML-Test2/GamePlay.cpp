#include "GamePlay.h"
#include <iostream>
#include <ctime>

GamePlay::GamePlay()
{
	srand(time(NULL));
	
	_state = STATE_GAME::PLAY;
	_pause = false;

	for (size_t i = 0; i < 5; i++)
	{
		switch (rand() % 2)
		{
		case 0:
			o[i] = new Obstacle;
			break;
		case 1:
			o[i] = new ObstacleRed;
			break;
		}
	}
	
	for (auto obs : o)
	{	
		float x = rand() % 500 + 1;
		float y = rand() % 500 + 1;
		obs->setShape(x, y);
	}
}

void GamePlay::cmd()
{
	if(!_pause)
	{
		p.cmd(); //Pelota
		
		// Obstacle
		for (auto obs : o)
		{
			obs -> cmd();
		}


		
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
		for (auto obs : o) 
		{
			obs -> update();
		}

		//Colisiones
		collider();
	}
}

void GamePlay::draw(sf::RenderWindow& window)
{
	window.draw(p.getDraw()); //Pelota
	
	for (auto obs : o)
	{
		window.draw(obs -> getDraw());
	}

}

void GamePlay::collider()
{
	for (auto obs : o)
	{

		if (p.getLastPosition().y + p.getDraw().getGlobalBounds().height <= obs -> getDraw().getGlobalBounds().top
			&& p.getDraw().getGlobalBounds().intersects(obs -> getDraw().getGlobalBounds())
			&& p.getSpeed() < 0) // Arriba
		{
			p.setFloor(p.getDraw().getPosition().x, obs -> getDraw().getGlobalBounds().top - p.getDraw().getGlobalBounds().height);
		}

		if (p.getDraw().getGlobalBounds().intersects(obs -> getDraw().getGlobalBounds()))
		{
			if (p.getLastPosition().x < p.getDraw().getPosition().x) // izquierda
			{
				p.setFloor(obs -> getDraw().getGlobalBounds().left - p.getDraw().getGlobalBounds().width, p.getDraw().getPosition().y);
			}
			else if (p.getLastPosition().x > p.getDraw().getPosition().x) // derecha
			{
				p.setFloor(obs -> getDraw().getGlobalBounds().left + obs -> getDraw().getGlobalBounds().width, p.getDraw().getPosition().y);
			}
		}
		
	}
}
