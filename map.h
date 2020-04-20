#define WIDTH 40
#define HEIGHT 40

#pragma once
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <string>

enum Obstacle
{
  AIR,
  WALL
};

class Map
{
  protected:
    int map[WIDTH][HEIGHT];
  public:
    Map();
    void displayMap(sf::RenderWindow &window);
    bool checkCollisionUp(sf::Vector2f &pPos);
    bool checkCollisionDown(sf::Vector2f &pPos);
    bool checkCollisionLeft(sf::Vector2f &pPos);
    bool checkCollisionRight(sf::Vector2f &pPos);
};
