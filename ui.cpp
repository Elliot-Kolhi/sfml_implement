#include "ui.hpp"


Ui::Ui(sf::Font& font)
{
	
	sf::Vector2f pauseButtonPos(635.f, 7.f);
	sf::Vector2f pauseButtonSize(70.f, 35.f);
	std::string pauseBtnText = "Pause";

	int textPixelSize = 24;

	sf::Vector2f resetButtonPos(735.f, 7.f);
	sf::Vector2f resetButtonSize(70.f, 35.f);
	std::string resetBtnText = "Reset";

	_pauseButton = Button(_font, pauseBtnText, pauseButtonPos, pauseButtonSize, textPixelSize);
	_resetButton = Button(_font, resetBtnText, resetButtonPos, resetButtonSize, textPixelSize);

	_slider = Slider();
	_font = font;

	_sliderText.setFont(_font);
	_sliderMinText.setFont(_font);
	_sliderMaxText.setFont(_font);
	_scoreMainText.setFont(_font);
	_scoreLeftText.setFont(_font);
	_scoreRightText.setFont(_font);
	_epochMainText.setFont(_font);
	_epochNumberText.setFont(_font);
	_epsilonMainText.setFont(_font);
	_epsilonNumberText.setFont(_font);
	_learningRateMainText.setFont(_font);
	_learningRateNumberText.setFont(_font);
	_yBallText.setFont(_font);
	_yBatText.setFont(_font);

	_plotLegend.setFont(_font);
	_upText.setFont(_font);
	_downText.setFont(_font);
	_sleepText.setFont(_font);


	_sliderText.setString("Delay");
	_sliderMinText.setString("Min");
	_sliderMaxText.setString("Max");
	_scoreMainText.setString("Score");
	_scoreLeftText.setString("0");
	_scoreRightText.setString("0");
	_epochMainText.setString("Epoch");
	_epochNumberText.setString("0");
	_epsilonMainText.setString("Epsilon");
	_epsilonNumberText.setString("0");
	_learningRateMainText.setString("Learning rate");
	_learningRateNumberText.setString("0");
	_yBallText.setString("Ball y");
	_yBatText.setString("Bat y");
	
	_plotLegend.setString("Legend");
	_upText.setString("Up");
	_downText.setString("Down");
	_sleepText.setString("Sleep");


	// Text sizes in pixels
	_sliderText.setCharacterSize(24);
	_sliderMinText.setCharacterSize(24);
	_sliderMaxText.setCharacterSize(24);
	_scoreMainText.setCharacterSize(72);
	_scoreLeftText.setCharacterSize(72);
	_scoreRightText.setCharacterSize(72);
	_epochMainText.setCharacterSize(24);
	_epochNumberText.setCharacterSize(24);
	_epsilonMainText.setCharacterSize(24);
	_epsilonNumberText.setCharacterSize(24);
	_learningRateMainText.setCharacterSize(24);
	_learningRateNumberText.setCharacterSize(24);
	_yBallText.setCharacterSize(24);
	_yBatText.setCharacterSize(24);
	
	_plotLegend.setCharacterSize(24);
	_upText.setCharacterSize(24);
	_downText.setCharacterSize(24);
	_sleepText.setCharacterSize(24);

	// Text colors
	_sliderText.setColor(sf::Color::Red);
	_sliderMinText.setColor(sf::Color::Red);
	_sliderMaxText.setColor(sf::Color::Red);
	_scoreMainText.setColor(sf::Color::Red);
	_scoreLeftText.setColor(sf::Color::Blue);
	_scoreRightText.setColor(sf::Color::Blue);
	_epochMainText.setColor(sf::Color::Blue);
	_epochNumberText.setColor(sf::Color::Blue);
	_epsilonMainText.setColor(sf::Color::Blue);
	_epsilonNumberText.setColor(sf::Color::Blue);
	_learningRateMainText.setColor(sf::Color::Blue);
	_learningRateNumberText.setColor(sf::Color::Blue);
	_yBallText.setColor(sf::Color::Red);
	_yBatText.setColor(sf::Color::Red);

	_plotLegend.setColor(sf::Color::Blue);
	_upText.setColor(sf::Color::Red);
	_downText.setColor(sf::Color::Red);
	_sleepText.setColor(sf::Color::Red);

	// Text locations	
	_sliderText.setPosition(sf::Vector2f(800.f, 350.f));
	_sliderMinText.setPosition(sf::Vector2f(760.f, 400.f));
	_sliderMaxText.setPosition(sf::Vector2f(840.f, 400.f));
	_scoreMainText.setPosition(sf::Vector2f(250.f, 370.f));
	_scoreLeftText.setPosition(sf::Vector2f(80.f, 370.f));
	_scoreRightText.setPosition(sf::Vector2f(500.f, 370.f));
	_yBatText.setPosition(sf::Vector2f(120.f, 670.f));
	_yBallText.setPosition(sf::Vector2f(5.f, 540.f));
	
	_plotLegend.setPosition(sf::Vector2f(440.f, 470.f));
	_upText.setPosition(sf::Vector2f(465.f, 490.f));
	_downText.setPosition(sf::Vector2f(465.f, 510.f));
	_sleepText.setPosition(sf::Vector2f(465.f, 530.f));

	_epochMainText.setPosition(		sf::Vector2f(635.f, 35.f));
	_epochNumberText.setPosition(		sf::Vector2f(770.f, 35.f));
	_epsilonMainText.setPosition(		sf::Vector2f(635.f, 70.f));
	_epsilonNumberText.setPosition(		sf::Vector2f(770.f, 70.f));
	_learningRateMainText.setPosition(	sf::Vector2f(635.f, 105.f));
	_learningRateNumberText.setPosition(	sf::Vector2f(770.f, 105.f));
	

	// Backgrounds
	_scoreBg = sf::RectangleShape(sf::Vector2f(620.f, 55.f));
	_scoreBg.setPosition(sf::Vector2f(0.f, 400.f));
	_scoreBg.setFillColor(sf::Color(20.f, 10.f, 35.f));

	_qTableBg = sf::RectangleShape(sf::Vector2f(620.f, 300.f));
	_qTableBg.setPosition(sf::Vector2f(0.f, 455.f));
	_qTableBg.setFillColor(sf::Color(15.f, 8.f, 25.f));

	_upTile = sf::RectangleShape(sf::Vector2f(20.f, 20.f));
	_downTile = sf::RectangleShape(sf::Vector2f(20.f, 20.f));
	_sleepTile = sf::RectangleShape(sf::Vector2f(20.f, 20.f));

	_upTile.setPosition(sf::Vector2f(440.f, 500.f));
	_downTile.setPosition(sf::Vector2f(440.f, 520.f));
	_sleepTile.setPosition(sf::Vector2f(440.f, 540.f));

	_upTile.setFillColor(sf::Color(0.f, 130.f, 0.f));
	_downTile.setFillColor(sf::Color(254.f, 130.f, 0.f));
	_sleepTile.setFillColor(sf::Color(127.f, 130.f, 0.f));

}


void Ui::draw(sf::RenderWindow& window)
{
	// Backgrounds
	window.draw(_scoreBg);
	window.draw(_qTableBg);

	window.draw(_upTile);
	window.draw(_downTile);
	window.draw(_sleepTile);


	_slider.draw(window);

	// Draw info texts

	// Slider
	window.draw(_sliderText);
	window.draw(_sliderMinText);
	window.draw(_sliderMaxText);

	// Scoreboard
	window.draw(_scoreMainText);
	window.draw(_scoreLeftText);
	window.draw(_scoreRightText);

	window.draw(_epochMainText);
	window.draw(_epochNumberText);
	window.draw(_epsilonMainText);
	window.draw(_scoreRightText);
	window.draw(_epsilonNumberText);
	window.draw(_learningRateMainText);
	window.draw(_learningRateNumberText);
	window.draw(_yBallText);
	window.draw(_yBatText);

	window.draw(_plotLegend);
	window.draw(_upText);
	window.draw(_downText);
	window.draw(_sleepText);



	// Buttons
	_pauseButton.draw(window);
	_resetButton.draw(window);

}

void Ui::passClickEvent(sf::Vector2f mousePos)
{
	if (_slider.isClicked(mousePos)) {
		_slider.setDragged(true);
	}
	else if (_pauseButton.isClicked(mousePos) && _doPause == false) {
		_doPause = true;
	}
	else if (_pauseButton.isClicked(mousePos) && _doPause == true) {
		_doPause = false;
	}
	else if (_resetButton.isClicked(mousePos) &&  _doReset == false) {
		_doReset = true;
	}
	else if (_doReset == true) {
		_doReset = false;
	}

}

void Ui::passReleaseEvent(sf::Vector2f mousePos)
{
	// TEMP commented away. UNCOMMENT for debug
	//printf("%f %f\n", mousePos.x, mousePos.y);
	if (_slider.isDragged()) {
		_slider.setDragged(false);
	}
	
	if (_doReset == true) {
		_doReset = false;
	}
}

void Ui::passMoveEvent(sf::Vector2f mousePos)
{	
	// TEMP commented away. UNCOMMENT for debug
	//printf("%f %f\n", mousePos.x, mousePos.y);
	if (_slider.isDragged()) {
		_slider.moveHandle(mousePos.x);
	}
}

float Ui::getSliderPosition(void) {
	return _slider.getHandlePosition();
}



void Ui::setPlayerScores(int leftPlayerScore, int rightPlayerScore) {
	_scoreLeftText.setString(std::to_string(leftPlayerScore));
	_scoreRightText.setString(std::to_string(rightPlayerScore));
}

bool Ui::pollPauseButton(void) {
	return _doPause;
}

bool Ui::pollResetButton(void) {
	return _doReset;
}

void Ui::setEpochText(int epochNumber) {
	_epochNumberText.setString(std::to_string(epochNumber));
}

void Ui::setEpsilonText(float epsilon) {
	// NOTE epsilon is _greedy_ -> converges to 1
	_epsilonNumberText.setString(std::to_string(1.f-epsilon));
}


void Ui::setLearningRateText(float learningRate) {
	_learningRateNumberText.setString(std::to_string(learningRate));
}


