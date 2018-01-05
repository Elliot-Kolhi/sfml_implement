#include "button.hpp"

Button::Button() {
}

Button::Button(sf::Font& font, std::string text, sf::Vector2f buttonPos, sf::Vector2f buttonSize, int textPixelSize)
{
	_text.setFont(font);
	_text.setString(text);
	_text.setCharacterSize(textPixelSize);

	_button.setPosition(buttonPos);
	_text.setPosition(buttonPos + sf::Vector2f((float)textPixelSize / 5.f,0.f));

	_button.setFillColor(sf::Color(10.f, 100.f, 30.f));
	_text.setColor(sf::Color::Green);

	_button.setSize(buttonSize);

}



void Button::draw(sf::RenderWindow& window)
{
	window.draw(_button);
	window.draw(_text);
}

bool Button::isClicked(sf::Vector2f pos) {
	sf::FloatRect boundingBox = _button.getGlobalBounds();

	if (boundingBox.contains(pos))
	{
	    return true;
	}
	return false;
}

