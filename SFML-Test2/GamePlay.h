#pragma once
#include <SFML/Graphics.hpp>
#include "Pelota.h"
#include "Obstacle.h"

class GamePlay
{
private:
	enum STATE_GAME
	{
		PLAY,
		PAUSE,
		WIN,
		LOSE
	};
	
	Pelota p;
	Obstacle o;
	bool _pause;
	STATE_GAME _state;
public:
	GamePlay();
	void cmd();
	void update();
	void draw(sf::RenderWindow& window);
	
	void collider();
};

