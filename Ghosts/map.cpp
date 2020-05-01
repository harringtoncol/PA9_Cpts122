#include "map.h"

Map::Map(sf::TcpSocket* client1, sf::TcpSocket* client2, Ghosts *g)
{
    ghost = g;
  for (int i = 0; i < WIDTH; ++i)
    for (int j = 0; j < HEIGHT; ++j)
      map[i][j] = (rand() % 15) == 0 ? WALL : AIR;
  p1 = new Player(sf::Vector2f(200, 200), client1);
  p2 = new Player(sf::Vector2f(200, 200), client2);
}
int Map::update()
{
   int i = ghost->update(p1->getPos(), p2->getPos());
   std::cout << i;
  //returns 1 if either client closes the connection
  if (p1->update(map) || p2->update(map))
    return 1;
  return 0;
  
}
void Map::displayMap(sf::RenderWindow &window)
{
   
  sf::RectangleShape wall(sf::Vector2f(10, 10));
  wall.setFillColor(sf::Color::Blue);
  for (int i = 0; i < WIDTH; ++i)
    for (int j = 0; j < HEIGHT; ++j)
      if (map[i][j] == WALL)
      {
        wall.setPosition(i * 10, j * 10);
	window.draw(wall);
      }
  sf::RectangleShape ghosts(sf::Vector2f(20, 20));
  ghosts.setFillColor(sf::Color::Red);
  ghosts.setPosition(ghost->getPos());
  window.draw(ghosts);
  sf::RectangleShape player(sf::Vector2f(10, 10));
  player.setFillColor(sf::Color::White);
  player.setPosition(p1->getPos());
  window.draw(player);
  player.setPosition(p2->getPos());
  window.draw(player);
}
void Map::sendMap(char dataOut[3000])
{
  for (int i = 0; i < WIDTH; ++i)
    for (int j = 0; j < HEIGHT; ++j)
      dataOut[i * 40 + j] = (char) map[i][j];
  int *index = (int *) (dataOut + 1600);
  *(index + 0) = p1->getPos().x;
  *(index + 1) = p1->getPos().y;
  *(index + 2) = p2->getPos().x;
  *(index + 3) = p2->getPos().y;
  *(index + 4) = ghost->getPos().x;
  *(index + 5) = ghost->getPos().y;
}
void Map::extractMap(char dataIn[3000])
{
  for (int i = 0; i < WIDTH; ++i)
    for (int j = 0; j < HEIGHT; ++j)
      map[i][j] = (int) dataIn[i * 40 + j];
  sf::Vector2f pos;
  int *index = (int *) (dataIn + 1600);
  p1->setPos(*(index + 0), *(index + 1));
  p2->setPos(*(index + 2), *(index + 3));
  ghost->setPos(*(index+4), *(index + 5));
}
