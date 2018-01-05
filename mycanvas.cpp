#include "mycanvas.h"
#include "ball.hpp"


MyCanvas::MyCanvas(QWidget *parent, const QPoint& position, const QSize& size) :
QSFMLCanvas(parent, position, size)
{
}

void MyCanvas::onInit()
{
  /* put pic.png in your Build-Debug*** directory so that the program can find it*/
  mTexture.loadFromFile("pic.png");
  mSprite.setTexture(mTexture);
  }

void MyCanvas::onUpdate()
{
    Ball	_ball;
    _ball = Ball(_max_boundry, _r, _gridsize, _length, _position, _velocity);
  sf::RenderWindow::clear(sf::Color(0, 0, 0));
  sf::CircleShape shape(50);
  shape.setFillColor(sf::Color(100, 250, 50));
  shape.setPosition(v1);
  this->draw(mSprite);
  draw(shape);
  _ball.draw(this);
  v1.x += 0.1f;

}
