#include "agent.hpp"
#include "random"


Agent::Agent(sf::Vector2f position, sf::Vector2f batSize, float gridSize, int worldHeight, int id)
{
	_id = id;

	_position = position;
	_batSize = batSize;
	_gridSize = gridSize;
	_worldHeight = worldHeight;
	_initPosition = position;
	 
	int nActions = 3;
	float learningRate = 0.95f;
	float discountFactor = 0.8f;
    float epsilon = 0.5f;

	// TEMP commented away. UNCOMMENT for debug
	//printf("Bat %d %d World %d\n", (int)_batSize.x / (int)gridSize, (int)_batSize.y / (int)gridSize, worldHeight);

	_policy = QLearning((int)_batSize.y / gridSize, worldHeight, nActions, learningRate, discountFactor, epsilon);

	_initPol = _policy;

	_policy.initRewardFunction(100.f, 0.f, -100.f);
	_policy.initQMatrix();


	// Initialize the drawable shape.
	_shape = sf::RectangleShape(_batSize);
	_shape.setPosition(_position);
	_shape.setFillColor(sf::Color::Green);

	// Print rewardfunction;
	// TEMP commented away. UNCOMMENT for debug
	//Agent::printReward();
}


void Agent::resetBat()
{
	_position.y = _initPosition.y;
	_shape.setPosition(_initPosition);
}

void Agent::resetQMatrix()
{
	_policy.initQMatrix();
}


void Agent::resetPolicy()
{
	_policy = _initPol;
	_policy.initRewardFunction(100.f, 0.f, -100.f);
	_policy.initQMatrix();
}

void Agent::draw(sf::RenderWindow& window)
{
	_shape.setPosition(_position);
	window.draw(_shape);


/*
    // Each agent is responsible for its own Q-tables

	// 1) Get Q-table entries

	// 2) Choose optimal action

	// 3) Draw current tile with appropriate color


}
*/

	auto& qValues = _policy.getQMatrix();

	sf::Vector2f tileSize(10.f,10.f);

	sf::Vector2f tableOrigin;
	if (_id == 0) {
		tableOrigin = sf::Vector2f(55.f, 460.f);
	}
	else {
		tableOrigin = sf::Vector2f(255.f, 460.f);
	}

	sf::RectangleShape tile(tileSize);
	sf::Color color(0.f,130.f,0.f);


	// Draw the stuff on a matrix:
	// y dim "bat" _worldHeight - ((int)_batSize.y / _gridSize) + 1
	// x dim "ball" _worldHeight

	// In our case, 20*16 matrix

	int ySize = _worldHeight;
	int xSize = _worldHeight - ((int)_batSize.y / _gridSize) + 1;

	int nBatStates = _worldHeight - ((int)_batSize.y / (int)_gridSize) + 1;
	//int currentState = batState + ballState * nBatStates;

	for (int i = 0; i < xSize; ++i) {
		for (int j = 0; j < ySize; ++j) {

			int state = i + j * nBatStates;
			int optimalAction = _policy.getOptAction(qValues[state]);

			color.r = 127.f * optimalAction;

			tile.setFillColor(color);
			tile.setPosition(tableOrigin + sf::Vector2f(i* tileSize.x, (ySize-j)* tileSize.y));
			window.draw(tile);
		}
	}

}

void Agent::step(float yBall)
{
    // This adjusts yBall to take into account that the bat's center position is currently at the top of the bat - not the optimal way to do it but it works.
    yBall = yBall >= (int)_batSize.y/(2*(int)_gridSize) ? yBall - (int)_batSize.y/(2*(int)_gridSize) : yBall;
	int currentState = getCurrentState(yBall);
	int newAction = _policy.chooseAction(currentState);


	if (newAction == 0 && _position.y >= _gridSize) {
		// Up
		// TEMP commented away. UNCOMMENT for debug
		//printf("Go up!\n");
		_position += sf::Vector2f(0.f, -_gridSize);
	}
	else if (newAction == 1) {
		// Do nothing
	}
	else if (newAction == 2 && _position.y <= (float)_worldHeight * _gridSize - _batSize.y - _gridSize) {
		// Down
		// TEMP commented away. UNCOMMENT for debug
		//printf("Go down!\n");
		_position += sf::Vector2f(0.f, _gridSize);
	}


	int newState = getCurrentState(yBall);
	_policy.updateQMatrix(newAction, currentState, newState);
	
	if (_stepIdx % 100 == 0) {
        _policy.exponentialDecay(0, 0.95); // reduce epsilon
        _policy.exponentialDecay(1, 0.95); // reduce learningRate
		// TEMP commented away. UNCOMMENT for debug
		//_policy.printQMatrix(_policy.getQMatrix());
	}

	++_stepIdx;
}

sf::Vector2f Agent::getPosition()
{
	return _position;
}


void Agent::printReward()
{
	_policy.printRewardFunction(_policy.getRewardFunction());
}


void Agent::printMatrix()
{
	_policy.printQMatrix(_policy.getQMatrix());
}

int Agent::getCurrentState(float yBall)
{
	// The discrete states are 2-dimensional:
	// - ball y
	// - bat y

	// We encode this information into a 1d vector
	// First we need to know the dimensions of the world...

	// Amount of states for the bat
	int nBatStates = _worldHeight - ((int)_batSize.y / (int)_gridSize) + 1;

	// Amount of states for the ball
	int nBallStates = _worldHeight;


	// Bat current state
	int batState = (int)_position.y / (int)_gridSize;

	// Ball current state
	int ballState = (int)yBall / (int)_gridSize;

	
	//printf("nBatStates: %d nBallStates: %d Bat %d Ball %d\n", nBatStates, nBallStates, batState, ballState);
	
	// We decide that "x" is Bat and "y" is Ball
	// Now each 2D state is (batState, ballState) using the variables declared earlier
	// To change 2D state into 1D state, we have to use the following algorithm:

	int currentState = batState + ballState * nBatStates;

	//printf("%d %d p %f %f\n", currentState, newAction, _position.y, (float)_worldHeight * _gridSize - _batSize.y - _gridSize);	


	return currentState;
}

float Agent::getEpsilon(void) {
	return _policy.getEpsilon();
}

float Agent::getLearningRate(void) {
	return _policy.getLearningRate();
}

