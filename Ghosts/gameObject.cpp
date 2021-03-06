#include "gameObject.h"

GameObject::GameObject(sf::Vector2f p)
{
  pos = p;
  speed = 0;
}
sf::Vector2f GameObject::getPos()
{
  return pos;
}
void GameObject::move(int x, int y)
{
  pos.x += x;
  pos.y += y;
}
void GameObject::setPos(int x, int y)
{
  pos.x = x;
  pos.y = y;
}
bool GameObject::checkCollisionUp(int map[40][40])
{
  int x1 = (int) ((pos.x + 5) / 10);
  int x2 = (int) pos.x / 10;
  int y1 = (int) ((pos.y + 5) / 10);
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
bool GameObject::checkCollisionDown(int map[40][40])
{
  int x1 = (int) ((pos.x + 5) / 10);
  int x2 = (int) pos.x / 10;
  int y1 = (int) pos.y / 10;
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
bool GameObject::checkCollisionLeft(int map[40][40])
{
  int x1 = (int) ((pos.x + 5) / 10);
  int y1 = (int) ((pos.y + 5) / 10);
  int y2 = (int) pos.y / 10;
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
bool GameObject::checkCollisionRight(int map[40][40])
{
  int x1 = (int) pos.x / 10;
  int y1 = (int) ((pos.y + 5) / 10);
  int y2 = (int) pos.y / 10;
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
