#include "ball.hpp"
#include <random>

Ball::Ball()
{
}


Ball::Ball(sf::Vector2f max_boundry, float r, float gridsize, float length, sf::Vector2f position, sf::Vector2f velocity)
{
	_max_boundry = max_boundry;
	_r = r;
	_gridsize = gridsize;
	_length = length;
	_position = position;
	_velocity = velocity;
	
	_initPos = _position;
	_initVel = _velocity;
	
}

void Ball::step(sf::Vector2f paddle1_position, sf::Vector2f paddle2_position)
{
	sf::Vector2f past_position1(0.f,0.f);
	sf::Vector2f past_position2(0.f,0.f);
	float inherit_velocity1 = 0.f;
	float inherit_velocity2 = 0.f;	

	if (paddle1_position.y - past_position1.y < 0)
	{
		inherit_velocity1 = -_gridsize;	
	}
	else if (paddle1_position.y - past_position1.y > 0)
	{
		inherit_velocity1 = _gridsize;	
	}
	else
	{
		inherit_velocity1 = 0;
	}

	if (paddle2_position.y - past_position2.y < 0)
	{
		inherit_velocity2 = -_gridsize;	
	}
	else if (paddle2_position.y - past_position2.y > 0)
	{
		inherit_velocity2 = _gridsize;	
	}
	else
	{
		inherit_velocity2 = 0;
	}

	sf::Vector2f paddle_velocity(0.f, 0.f);

	// Temp variable to help things...
    //float paddleWidth = _gridsize;

	// Collision with the floor (note that y grows "down"!)
	if ( (_position.y + _r) >= _max_boundry.y )
	{
		_position.y = _max_boundry.y - _r;
		_velocity.y = -_velocity.y;
	}

	// Collision with the roof (note that y grows "down"!)
	if ( _position.y <= 0)
	{
		_position.y = 0;
		_velocity.y = -_velocity.y;
	}


	// We're not moving there yet...
	sf::Vector2f newPos = _position + _velocity;

	// TEMP commented away. UNCOMMENT for debug
	//printf("%f %f Here I am!\n", newPos.x, newPos.y);
	
	
	
	// First: collision check
	if ((int)newPos.x == (int)paddle1_position.x && (int)newPos.y >= (int)paddle1_position.y && (int)newPos.y < (int)paddle1_position.y + (int)_length)
	{
		// Collision with paddle one (left)

		// Three cases: straight, skew and corners
				
		_velocity.x *= -1;
		if(_velocity.y + inherit_velocity1 <= _gridsize && _velocity.y + inherit_velocity1 >= -_gridsize)
		{
		_velocity.y += inherit_velocity1;
		}
		newPos = _position + _velocity;
		
	}
	else if ((int)newPos.x == (int)paddle2_position.x && (int)newPos.y >= (int)paddle2_position.y && (int)newPos.y < (int)paddle2_position.y + (int)_length)
	{
		// Collision with paddle two (right)

		// Three cases: straight, skew and corners
		_velocity.x *= -1;
		if(_velocity.y + inherit_velocity2 <= _gridsize && _velocity.y + inherit_velocity2 >= -_gridsize)
		{
		_velocity.y += inherit_velocity2;
		}
		newPos = _position + _velocity;
	}

	_position = newPos;


	past_position1 = paddle1_position;
	past_position2 = paddle2_position;


}

void Ball::draw(MyCanvas* window)
{
	sf::RectangleShape ball(sf::Vector2f(_r, _r));	
	ball.setPosition(_position);
    window->draw(ball);
}

sf::Vector2f Ball::getPosition()
{
	return _position;
}


//reset ball with random velocity
void Ball::reset()
{
	_position = _initPos;
	
	int randx = rand() % 2; 
	int randy = rand() % 3;

	if (randx == 0) {
		_velocity.x = _gridsize;
	}
	else if (randx == 1) {
		_velocity.x = -_gridsize;
	}



	if (randy == 0) {
		_velocity.y = _gridsize;
	}
	else if (randy == 1) {
		_velocity.y = 0.f;
	}
	else if (randy == 2) {
		_velocity.y = -_gridsize;
	}

	//_velocity = _initVel;
}
