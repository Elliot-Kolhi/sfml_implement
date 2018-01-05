#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "qsfmlcanvas.h"

class MyCanvas : public QSFMLCanvas
{
  Q_OBJECT
  private:
  void onInit();
  void onUpdate();

  sf::Texture mTexture;
  sf::Sprite mSprite;
  sf::Image mImage;
  sf::Vector2f v1;
  sf::Vector2f _max_boundry;
  float _r = 10.0f;
  float _gridsize = 10.0f;
  float _length = 10.0f;
  sf::Vector2f _position;
  sf::Vector2f _velocity;

  public:
  explicit MyCanvas(QWidget *parent, const QPoint& position, const QSize& size);

  signals:

  public slots:
};

#endif
