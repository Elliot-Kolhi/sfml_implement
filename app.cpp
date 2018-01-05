#include "app.hpp"

#include <unistd.h>

App::App(sf::Font& font) : _ui(Ui(font))
{
	_isPaused = false;	// Is the game paused?

	// How many tiles and what is their size (Note that sfml window has some size...)
	int gridSize = 20;

	// How many tiles the bat lengths is
	int batLength = 5;

	// Fieldbounds
	sf::Vector2f fieldBounds(600.f, 400.f);
	sf::Vector2f initPosition(fieldBounds.x / 2.0,fieldBounds.y / 2.0);

	_xBallMin = 0.f;
	_xBallMax = fieldBounds.x + (float)gridSize;
	_yBallMax = fieldBounds.y;

	sf::Vector2f worldSize(_xBallMin, _xBallMax);
	int worldHeight = (int)fieldBounds.y / gridSize;

	Agent agent1(sf::Vector2f(gridSize, fieldBounds.y / 2.0), sf::Vector2f((float)gridSize, (float)(batLength) * gridSize), (float)gridSize, worldHeight, 0);
	Agent agent2(sf::Vector2f(fieldBounds.x - gridSize, fieldBounds.y / 2.0), sf::Vector2f((float)gridSize, (float)(batLength) * gridSize), (float)gridSize, worldHeight, 1);
	_agents.push_back(agent1);
	_agents.push_back(agent2);

	

	sf::Vector2f initVelocity((float)gridSize,(float)gridSize);
	_ball = Ball(fieldBounds, gridSize, gridSize, (float)batLength * gridSize, initPosition, initVelocity);


	// The slider will interpolate between these two values
	_delayMin = 10;
	_delayMax = 100000;

	_stepNumber = 0;

}

void App::updateGame()
{

	_isPaused = _ui.pollPauseButton();	
	bool isReset = _ui.pollResetButton();

	// If game is running, update all objects
	if (_isPaused == false) {

		for (auto& player : _agents) {		
			player.step(_ball.getPosition().y);

			/*

			UNCOMMENT for debug prints

			if (_playerScore[0] % 100 == 0)
			{
				player.printMatrix();
			}
			*/
		}
		
		_ball.step(_agents[0].getPosition(), _agents[1].getPosition());

		++_stepNumber;

		if (isReset == true) 
		{
			resetApp();
			isReset = false;
		}
	}

		// Check if ball out of bounds!

	if ((int)_ball.getPosition().x <= (int)_xBallMin - 20)
	{	
		_isPaused = true;

		++_playerScore[1];
		// TEMP commented away. UNCOMMENT for debug
		//printf("Left player loses! Score %d - %d\n", _playerScore[0], _playerScore[1]);
		_ui.setPlayerScores(_playerScore[0],_playerScore[1]);
		resetField();
	}
	else if ((int)_ball.getPosition().x >= (int)_xBallMax)
	{
		_isPaused = true;
		++_playerScore[0];
		// TEMP commented away. UNCOMMENT for debug
		//printf("Right player loses! Score %d - %d\n", _playerScore[0], _playerScore[1]);
		_ui.setPlayerScores(_playerScore[0],_playerScore[1]);
		resetField();
	}

	// Delay of x microseconds = x/1000 milliseconds
	usleep((_delayMax - _delayMin)*_ui.getSliderPosition() + _delayMin);


	_ui.setEpochText(_stepNumber);
	_ui.setEpsilonText(_agents[0].getEpsilon());
	_ui.setLearningRateText(_agents[0].getLearningRate());

}

void App::drawObjects(sf::RenderWindow& window)
{

	// Draw grey background for the game field...
	sf::RectangleShape background(sf::Vector2f(_xBallMax,_yBallMax));
	background.setFillColor(sf::Color(60.f,60.f,60.f));	
	window.draw(background);	


	_ui.draw(window);

	for (auto& player : _agents) {
		
		player.draw(window);

	}
	
	_ball.draw(window);
	
	
	
}

void App::passClickEvent(sf::Vector2f mousePos)
{
	_ui.passClickEvent(mousePos);
}

void App::passReleaseEvent(sf::Vector2f mousePos)
{
	_ui.passReleaseEvent(mousePos);
}

void App::passMoveEvent(sf::Vector2f mousePos)
{
	_ui.passMoveEvent(mousePos);
}



void App::resetField()
{
	/*
	Upon field reset,
	1) Initialize the bat positions
	2) Initialize the ball position and velocity
	*/

	for (auto& player : _agents) {
		// TODO some reset function
		player.resetBat();
		player.step(_ball.getPosition().y);
	}

	_ball.reset();
	_isPaused = false;
}

	/*
	Upon app reset,
	1) Initialize the bat positions
	2) Initialize the ball position and velocity
	3) Initialize the bat QMatrix
	4) Initialize policy
	*/
void App::resetApp()
{
	resetField();
	for (auto& player : _agents) {
		player.resetQMatrix();
		player.resetPolicy();
	}
}