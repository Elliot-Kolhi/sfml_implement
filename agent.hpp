#ifndef AGENT_HPP
#define AGENT_HPP

#include <SFML/Graphics.hpp>
#include "qlearning.hpp"


class Agent
{

public:
	Agent(sf::Vector2f position, sf::Vector2f batSize, float gridSize, int worldHeight, int id);

	
	/*
	1) Draw the agent as rectangle
	2) Draw the q-tables
	*/
	void draw(sf::RenderWindow& window);

	/*
	This function "asks" the QLearning policy what is the next action
	for current state and moves accordingly
	*/
	void step(float yBall);


	void printReward();
	void printMatrix();
	
	sf::Vector2f getPosition();

	float getEpsilon(void);
	float getLearningRate(void);

	void resetBat();

	int _id;
	void resetQMatrix();
	void resetPolicy();
	

private:

	sf::Vector2f		_initPosition;
	sf::Vector2f		_position;
	sf::Vector2f		_batSize;
	float			_gridSize;
	
	int			_worldHeight;

	// Qlearning object that the agent may ask moves from
	QLearning 		_policy;
	QLearning 		_initPol;


	sf::RectangleShape	_shape;

	int			getCurrentState(float yBall);

	int			_stepIdx = 0;	// TEMP DEBUG

};

#endif // AGENT_HPP
