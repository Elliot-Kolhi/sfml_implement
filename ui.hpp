#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>
#include "qlearning.hpp"
#include "agent.hpp"


#include "slider.hpp"
#include "button.hpp"



class Ui
{


/*
UI or User Interface is a class that draws several visual components on the screen
- Buttons
- Sliders
- Plots
- Info textboxes
- Visualizations of matrices etc
*/

public:

	Ui(sf::Font& font);
	
	
	void draw(sf::RenderWindow& window);


	void passClickEvent(sf::Vector2f mousePos);
	void passReleaseEvent(sf::Vector2f mousePos);
	void passMoveEvent(sf::Vector2f mousePos);

	float getSliderPosition(void);

	void setPlayerScores(int leftPlayerScore, int rightPlayerScore);

	bool pollPauseButton(void);
	bool pollResetButton(void);

	void setEpochText(int epochNumber);
	void setEpsilonText(float epsilon);
	void setLearningRateText(float learningRate);


private:

	Slider		_slider;
	Button		_pauseButton;
	Button		_resetButton;
	bool		_doPause = false;
	bool		_doReset = false;


	// TODO other buttons needed?
	// -> debug prints on/off
	// -> fwd/fast mode?


	sf::Font 	_font;

	sf::Text	_sliderText;
	sf::Text	_sliderMinText;
	sf::Text	_sliderMaxText;

	sf::Text	_scoreMainText;
	sf::Text	_scoreLeftText;
	sf::Text	_scoreRightText;

	sf::Text	_epochMainText;
	sf::Text	_epochNumberText;

	sf::Text	_epsilonMainText;
	sf::Text	_epsilonNumberText;

	sf::Text	_learningRateMainText;
	sf::Text	_learningRateNumberText;

	sf::Text	_yBallText;
	sf::Text	_yBatText;

	sf::RectangleShape _scoreBg;
	sf::RectangleShape _qTableBg;

	sf::Text	_plotLegend;
	sf::Text	_upText;
	sf::Text	_downText;
	sf::Text	_sleepText;

	sf::RectangleShape _upTile;
	sf::RectangleShape _downTile;
	sf::RectangleShape _sleepTile;

};



#endif // UI_HPP
