#ifndef SLIDER_HPP
#define SLIDER_HPP

#include "uielement.hpp"

class Slider : public UIElement {
public:
	Slider(void);
	virtual void draw(sf::RenderWindow& window);


	bool isClicked(sf::Vector2f pos);
	bool isDragged(void);
	
	void setDragged(bool dragged);
	
	void moveHandle(float xPos);

	float getHandlePosition(void);




private:
	sf::RectangleShape 	_rail;
	sf::RectangleShape 	_handle;
	bool			_isDragged;
};

#endif //SLIDER_HPP
