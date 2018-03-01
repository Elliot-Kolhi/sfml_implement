#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "qsfmlcanvas.h"
#include "ball.hpp"
#include "agent.hpp"
#include "mainwindow.h"

class MyCanvas : public QSFMLCanvas
{
  Q_OBJECT
  private:
  void resetField();
  void resetApp();
  void onInit();
  void onUpdate();


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

  int           _delay;
  int			_delayMin;
  int			_delayMax;

  int           _stepNumber;
  float         LearningRate;
  float         Epsilon;

  public:
  explicit MyCanvas(MainWindow *parent, const QPoint& position, const QSize& size);

  signals:
    void setEpochText(int Epoch);
    void setEpsilonText(double Epsilon);
    void setLearningRateText(double LearningRate);
    void setScore1(int Score1);
    void setScore2(int Score2);

  public slots:
    void is_paused();
    void is_reset();
    void change_delay(int val);
};

#endif
