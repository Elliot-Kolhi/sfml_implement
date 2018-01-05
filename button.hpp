#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "uielement.hpp"

class Button : public UIElement {
public:
	

	Button(void);
	Button(sf::Font& font, std::string text, sf::Vector2f buttonPos, sf::Vector2f buttonSize, int textPixelSize);
	

	virtual void draw(sf::RenderWindow& window);

	bool isClicked(sf::Vector2f pos);

private:
	sf::RectangleShape 	_button;
	sf::Text		_text;
};

#endif //BUTTON_HPP
