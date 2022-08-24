#pragma once
#include <SFML/Graphics.hpp>
class Pelota
{
private:
	enum STATE
	{
		IDLE,
		WALK_FRONT,
		WALK_BACK,
		JUMP
	};
	
	sf::CircleShape _shape;
	STATE _state;
	float _speed_jump;
	char _keyRelease;
	sf::Vector2f _last_position;
	sf::Vector2f _move;
public:
	Pelota();
	void cmd();
	void update();
	sf::CircleShape& getDraw();

	void setFloor(float x, float y);
	void loseSpeed();

	float getSpeed();

	void move(float x, float y);
	sf::Vector2f getLastPosition();
};
