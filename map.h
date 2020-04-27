#define WIDTH 450
#define HEIGHT 450

#pragma once
#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"

enum Obstacle
{
  AIR,
  WALL
};

class Map : public GameObject
{
  protected:
    int map[WIDTH][HEIGHT];
  public:
    Map();
    Map(int renderLayer);
    void displayMap(sf::RenderWindow &window);
    void Update(sf::RenderWindow& window) override;
    bool checkCollisionUp(sf::Vector2f &pPos);
    bool checkCollisionDown(sf::Vector2f &pPos);
    bool checkCollisionLeft(sf::Vector2f &pPos);
    bool checkCollisionRight(sf::Vector2f &pPos);
};
