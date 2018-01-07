#include "mycanvas.h"
#include <unistd.h>
#include <QMessageBox>

MyCanvas::MyCanvas(MainWindow *parent, const QPoint& position, const QSize& size) :
QSFMLCanvas(parent, position, size)
{
}

void MyCanvas::resetField()
{
    /*
    Upon field reset,
    1) Initialize the bat positions
    2) Initialize the ball position and velocity
    */

    for (auto& player : _agents) {
        player.resetBat();
        player.step(_ball.getPosition().y);
    }

    _ball.reset();
    _isPaused = false;
}

void MyCanvas::resetApp()
{
    resetField();
    for (auto& player : _agents) {
        player.resetQMatrix();
        player.resetPolicy();
    }
}

void MyCanvas::is_paused()
{
    _isPaused = !_isPaused;
}

void MyCanvas::is_reset()
{
    resetField();
    for (auto& player : _agents) {
        player.resetQMatrix();
        player.resetPolicy();
    }
    for (auto& player : _agents) {
        player.resetBat();
        player.step(_ball.getPosition().y);
    }

    _ball.reset();

    _stepNumber = 0;
}

void MyCanvas::change_delay(int val)
{
    _delay = val*1000;
    //std::string str = std::to_string(_delay);
    //QString qstr = QString::fromStdString(str);
    //QMessageBox::information(this,"hi",qstr);
}

void MyCanvas::onInit()
{
  this->setFramerateLimit(240);
  /* put pic.png in your Build-Debug*** directory so that the program can find it*/
  mTexture.loadFromFile("pic.png");
  mSprite.setTexture(mTexture);
  gridSize = 20;

  fieldBounds = sf::Vector2f(600.f, 400.f);

  _xBallMin = 0.f;
  _xBallMax = fieldBounds.x + (float)gridSize;
  _yBallMax = fieldBounds.y;
  _delayMin = 10;
  _delayMax = 100000;


  initPosition = sf::Vector2f(fieldBounds.x / 2.0, fieldBounds.y / 2.0);
  initVelocity = sf::Vector2f((float)gridSize,(float)gridSize);

  batLength = 5;
  worldHeight = (int)fieldBounds.y / gridSize;

  _ball = Ball(fieldBounds, gridSize, gridSize, (float)batLength * gridSize, initPosition, initVelocity);

  agent1 = Agent(sf::Vector2f(gridSize, fieldBounds.y / 2.0), sf::Vector2f((float)gridSize, (float)(batLength) * gridSize), (float)gridSize, worldHeight, 0);
  agent2 = Agent(sf::Vector2f(fieldBounds.x - gridSize, fieldBounds.y / 2.0), sf::Vector2f((float)gridSize, (float)(batLength) * gridSize), (float)gridSize, worldHeight, 1);

  _agents.push_back(agent1);
  _agents.push_back(agent2);
  _stepNumber = 0;
  }

void MyCanvas::onUpdate()
{
  sf::RenderWindow::clear(sf::Color(0, 0, 0));
  sf::CircleShape shape(50);
  shape.setFillColor(sf::Color(100, 250, 50));
  shape.setPosition(v1);
  this->draw(mSprite);
  draw(shape);
  sf::RectangleShape background(sf::Vector2f(_xBallMax,_yBallMax));
  background.setFillColor(sf::Color(60.f,60.f,60.f));
  draw(background);
  if (_isPaused == false) {
      v1.x += 0.1f;
      _ball.step(_agents[0].getPosition(), _agents[1].getPosition());
      for (auto& player : _agents) {
          player.step(_ball.getPosition().y);

          /*

          UNCOMMENT for debug prints

          if (_playerScore[0] % 100 == 0)
          {
              player.printMatrix();
          }
          */
      }

      ++_stepNumber;
      if ((int)_ball.getPosition().x <= (int)_xBallMin - 20)
      {
          _isPaused = true;

          ++_playerScore[1];
          emit setScore2(_playerScore[1]);

          // TEMP commented away. UNCOMMENT for debug
          //printf("Left player loses! Score %d - %d\n", _playerScore[0], _playerScore[1]);
          //_ui.setPlayerScores(_playerScore[0],_playerScore[1]);
          resetField();
      }
      else if ((int)_ball.getPosition().x >= (int)_xBallMax)
      {
          _isPaused = true;

          ++_playerScore[0];
          emit setScore1(_playerScore[0]);

          // TEMP commented away. UNCOMMENT for debug
          //printf("Right player loses! Score %d - %d\n", _playerScore[0], _playerScore[1]);
          //_ui.setPlayerScores(_playerScore[0],_playerScore[1]);
          resetField();
      }

  }
  _ball.draw(this);

  for (auto& player : _agents) {

      player.draw(this);

  }
  emit setEpochText(_stepNumber);

  LearningRate = (double)_agents[0].getLearningRate();
  emit setLearningRateText(LearningRate);

  Epsilon = (double)(_agents[0].getEpsilon());
  emit setEpsilonText(Epsilon);

  usleep(_delay);
}
