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

  public:
  explicit MyCanvas(QWidget *parent, const QPoint& position, const QSize& size);

  signals:

  public slots:
};

#endif
