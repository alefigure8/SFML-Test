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
		JUMP,
		AIR
	};
	
	sf::CircleShape _shape;
	STATE _state;
	float _speed_jump;
	float _speed_forward;
	float _speed_backward;
	char _keyRelease;
	sf::Vector2f _last_position;
	sf::Vector2f _move;
	char last_key;
	float buffer_speed;
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

	void setState(bool state);
};
