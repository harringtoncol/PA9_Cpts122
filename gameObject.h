#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define WIDTH 40
#define HEIGHT 40

#include <iostream>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>

enum Obstacle
{
  AIR,
  WALL
};

class GameObject
{
protected:
  int speed;
  sf::Vector2f pos;
public:
  GameObject(sf::Vector2f p);
  sf::Vector2f getPos();
  bool checkCollisionUp(int map[40][40]);
  bool checkCollisionDown(int map[40][40]);
  bool checkCollisionLeft(int map[40][40]);
  bool checkCollisionRight(int map[40][40]);
  void move(int x, int y);
  void setPos(int x, int y);
};

#endif
