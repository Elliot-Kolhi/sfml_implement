#include "slider.hpp"

Slider::Slider()
{
	//printf("Constructor of slider!\n");

	_rail.setPosition(sf::Vector2f(760.f, 390.f));
	_handle.setPosition(sf::Vector2f(810.f, 385.f));

	_rail.setFillColor(sf::Color(255,255,255));
	_handle.setFillColor(sf::Color::Green);

	_rail.setSize(sf::Vector2f(100.f, 5.f));
	_handle.setSize(sf::Vector2f(10.f, 20.f));


	_isDragged = false;

}

void Slider::draw(sf::RenderWindow& window)
{
	//printf("draw");
	window.draw(_rail);
	window.draw(_handle);
}

bool Slider::isClicked(sf::Vector2f pos) {
	sf::FloatRect boundingBox = _handle.getGlobalBounds();

	if (boundingBox.contains(pos))
	{
	    return true;
	}
	return false;
}

bool Slider::isDragged(void) {
	return _isDragged;
}

void Slider::setDragged(bool dragged) {
	_isDragged = dragged;
}

void Slider::moveHandle(float xPos) {

	auto pos = _handle.getPosition();
	pos.x = xPos;

	if (xPos >= _rail.getPosition().x && xPos <= _rail.getPosition().x + _rail.getSize().x) {
		_handle.setPosition(pos);
	}
}

float Slider::getHandlePosition(void) {
	return ((_handle.getPosition().x - _rail.getPosition().x) / (_rail.getSize().x));
}
