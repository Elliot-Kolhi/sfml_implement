#ifndef UIELEMENT_HPP
#define UIELEMENT_HPP

#include <SFML/Graphics.hpp>


class UIElement {

public:
	UIElement();
	virtual void draw(sf::RenderWindow& window) = 0;

};

#endif //UIELEMENT_HPP
