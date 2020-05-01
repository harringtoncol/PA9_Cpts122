#include "player.h"

//Updates where the user is and checks if player can move without collisions
int Player::update(int map[40][40])
{
  char dataIn[100];
  std::size_t received;
  //receive input from the client
  if (client->receive(dataIn, 100, received) != sf::Socket::Done)
  {
    // error...
  }
  bool W = dataIn[0];
  bool A = dataIn[1];
  bool S = dataIn[2];
  bool D = dataIn[3];
  bool Q = dataIn[4];
  bool I = dataIn[5];
  //The following if loops check if it is valid to move without collisions
  if (A && !D)
    if (!checkCollisionLeft(map))
      pos.x -= speed;
  if (D && !A)
    if (!checkCollisionRight(map))
      pos.x += speed;
  if (W && !S)
    if (!checkCollisionUp(map))
      pos.y -= speed;
  if (S && !W)
    if (!checkCollisionDown(map))
      pos.y += speed;
  //returns 1 if the client closes the connection
  if (Q)
    return 1;
  return 0;
}
