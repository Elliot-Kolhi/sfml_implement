#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>

#include "agent.hpp"
#include "ball.hpp"
#include "ui.hpp"

#include <vector>

class App
{

public:

	App(sf::Font& font);


	/*
	Plays one "tick" of the game:
	- Checks if game is paused or running
	- Checks is the ball is in either goal or not
	-> Adds points to the players accordingly
	- Moves all objects according to the policies and physics
	
	-> Ball moves towards its velocity
	-> Check ball collision with the bat
	--> If ball collides with bat its direction is changed
	
	-> Bats ask the policy what's the best move and move accordingly
	*/
	void updateGame();


	// Calls separate private draw functions
	void drawObjects(sf::RenderWindow& window);

	void passClickEvent(sf::Vector2f mousePos);
	void passReleaseEvent(sf::Vector2f mousePos);
	void passMoveEvent(sf::Vector2f mousePos);

private:


	/*
	This function is called after either player makes a "goal"
	
	Sets the ball to middle,
	resets ball speed
	Sets both player bats to middle position

	*/ 
	void resetField();

	void resetApp();

	/*
	The private draw functions:
	- Draw players (two rectangles located at player (x,y) coords)
	- Draw ball (rectangle at (x,y) coord of the ball)
	- Draw UI
	-> Scoreboard
	-> Interactive elements such as buttons and sliders
	-> Graphs
	-> Tables
	*/

	void drawUI();


	std::vector<Agent>	_agents;

	Ball			_ball;

	Ui			_ui;

	// Game options
	bool			_isPaused;
	int			_playerScore[2] = {0,0};


	float			_xBallMin;
	float			_xBallMax;
	float           	_yBallMax;

	int			_delayMin;
	int			_delayMax;

	int			_stepNumber;

};

#endif // APP_HPP
