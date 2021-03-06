#ifndef MAP_H
#define MAP_H

#include "player.h"
#include "Ghosts.h"

class Map
{
  private:
    int map[WIDTH][HEIGHT];
    Player *p1;
    Player *p2;
    Ghosts* ghost;
  public:
    Map(sf::TcpSocket *client1, sf::TcpSocket *client2);
    int update();
    void displayMap(sf::RenderWindow &window);
    void sendMap(char dataOut[3000]);
    void extractMap(char dataIn[3000]);
};

#endif
