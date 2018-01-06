#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "qsfmlcanvas.h"
#include "ball.hpp"
#include "agent.hpp"

class MyCanvas : public QSFMLCanvas
{
  Q_OBJECT
  private:
  void resetField();
  void onInit();
  void onUpdate();

  sf::Texture mTexture;
  sf::Sprite mSprite;
  sf::Image mImage;
  sf::Vector2f v1;

  sf::Vector2f fieldBounds;
  sf::Vector2f initPosition;
  sf::Vector2f initVelocity;
  int gridSize;
  int batLength;
  int worldHeight;
  sf::Vector2f _position;
  sf::Vector2f _velocity;

  Agent agent1;
  Agent agent2;
  Ball _ball;

  std::vector<Agent>	_agents;

  bool			_isPaused;

  int			_playerScore[2] = {0,0};

  float			_xBallMin;
  float			_xBallMax;
  float         _yBallMax;

  int			_delayMin;
  int			_delayMax;
  int           _stepNumber;

  public:
  explicit MyCanvas(QWidget *parent, const QPoint& position, const QSize& size);

  signals:

  public slots:
};

#endif
