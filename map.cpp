#include "map.h"

Map::Map()
{
  for (int i = 0; i < WIDTH; ++i)
    for (int j = 0; j < HEIGHT; ++j)
      map[i][j] = (rand() % 15) == 0 ? WALL : AIR;
}
Map::Map(int renderLayer) : GameObject(renderLayer) {
    for (int i = 0; i < WIDTH; ++i)
        for (int j = 0; j < HEIGHT; ++j)
            map[i][j] = (rand() % 15) == 0 ? WALL : AIR;

        Chest newChest(9,1);
        newChest.xPos = (rand() % WIDTH);
        newChest.yPos = (rand() % HEIGHT);
        map[newChest.xPos][newChest.yPos] = CHEST;
        chest = newChest;
        chest.setRandItems(chest);
}
void Map::displayMap(sf::RenderWindow &window)
{
  sf::RectangleShape wall(sf::Vector2f(30, 30));
  wall.setFillColor(sf::Color::Blue);
 
  for (int i = 0; i < WIDTH; ++i)
    for (int j = 0; j < HEIGHT; ++j)
      if (map[i][j] == WALL)
      {
        wall.setPosition(i * 30, j * 30);
	window.draw(wall);
      }
      else if (map[i][j] == CHEST) {
          chest.Update(window);
      }
}
void Map::Update(sf::RenderWindow& window) {
    displayMap(window);
}
bool Map::checkCollisionUp(sf::Vector2f &pPos)
{
  int x1 = (int) ((pPos.x + 5) / 10);
  int x2 = (int) pPos.x / 10;
  int y1 = (int) ((pPos.y + 5) / 10);
  if (y1 > 0)
  {
    if (x1 != x2)
    {
      if (map[x1][y1 - 1] != WALL && map[x2][y1 - 1] != WALL)
        return false;
    }
      else if (map[x1][y1 - 1] != WALL)
        return false;
  }
  return true;
}
bool Map::checkCollisionDown(sf::Vector2f &pPos)
{
  int x1 = (int) ((pPos.x + 5) / 10);
  int x2 = (int) pPos.x / 10;
  int y1 = (int) pPos.y / 10;
  if (y1 < HEIGHT - 1)
  {
    if (x1 != x2)
    {
      if (map[x1][y1 + 1] != WALL && map[x2][y1 + 1] != WALL)
        return false;
    }
    else if (map[x1][y1 + 1] != WALL)
      return false;
  }
  return true;
}
bool Map::checkCollisionLeft(sf::Vector2f &pPos)
{
  int x1 = (int) ((pPos.x + 5) / 10);
  int y1 = (int) ((pPos.y + 5) / 10);
  int y2 = (int) pPos.y / 10;
  if (x1 > 0)
  {
    if (y1 != y2)
    {
      if (map[x1 - 1][y1] != WALL && map[x1 - 1][y2] != WALL)
         return false;
    }
    else if (map[x1 - 1][y1] != WALL)
      return false;
  }
 return true;
}
bool Map::checkCollisionRight(sf::Vector2f &pPos)
{
  int x1 = (int) pPos.x / 10;
  int y1 = (int) ((pPos.y + 5) / 10);
  int y2 = (int) pPos.y / 10;
  if (x1 < WIDTH - 1)
  {
    if (y1 != y2)
    {
      if (map[x1 + 1][y1] != WALL && map[x1 + 1][y2] != WALL)
        return false;
    }
    else if (map[x1 + 1][y1] != WALL)
      return false;
  }
  return true;
}
