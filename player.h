#ifndef PLAYER_H
#define PLAYER_H
#include "gameObject.h"

class Player : public GameObject
{
private:
  sf::TcpSocket *client;
public:
  Player(sf::Vector2f p, sf::TcpSocket *c) : GameObject(p)
  {
    client = c;
    speed = 5;
  }
  int update(int map[40][40]);
};

#endif
