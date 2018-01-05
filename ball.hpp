#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "mycanvas.h"

class Ball
{

public:

	Ball(sf::Vector2f max_boundry, float r, float gridsize, float length, sf::Vector2f position, sf::Vector2f velocity);
    Ball();

	/*
	This function moves the ball as per physics:

	Position is changed with respect to velocity and angle
	Stepsize indicates how much along the derivative we move
	Idea is about same as Euler: https://en.wikipedia.org/wiki/Backward_Euler_method 
	*/
	void step(sf::Vector2f paddle1_position, sf::Vector2f paddle2_position);


	/*
	Draws the ball as a primitive (rectangle)

	TODO Set the rectangle origin to ball position
	otherwise the origin is at top-left corner
	
	input argument: window
	the window that the drawing is happening on
	*/
    void draw(MyCanvas *window);

	//returns ball position
	sf::Vector2f getPosition();

	void reset();


private:

	// Position (x,y)
	sf::Vector2f 	_position;

	// Velocity (x,y)
	sf::Vector2f 	_velocity;


	// Initial position and velocity
	// After reset these values will be used
	sf::Vector2f 	_initPos;
	sf::Vector2f 	_initVel;



	// Drawable size
	sf::Vector2f 	_size;

	//x and y max boundry
	sf::Vector2f	_max_boundry;

	//radius of ball
	float _r;

	float _gridsize;

	float _length;

};

#endif // BALL_HPP
