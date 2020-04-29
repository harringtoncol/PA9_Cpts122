#include "map.h"
#include <SFML/Network.hpp>

int main(int argc, char const* argv[])
{
  srand(time(NULL));

  //prints out the local and public ip addresses of the server.
  //Currently only works on lan
  std::cout << sf::IpAddress::getLocalAddress() << std::endl;
  //std::cout << sf::IpAddress::getPublicAddress() << std::endl;
  //default port is 52000, first argument is the modified port value

  //is fine without arguments most of the time
  int port = 52000;
  sf::TcpListener listener;
  if (argc > 1)
    port = atoi(argv[1]);
  // bind the listener to a port
  if (listener.listen(port) != sf::Socket::Done)
  {
    // error...
  }

  // accept a new connection
  sf::TcpSocket client;
  if (listener.accept(client) != sf::Socket::Done)
  {
    // error...
  }

  char dataIn[100];
  char dataOut[100] = "Hello Client\n";
  std::size_t received;

  //Declare variables
  float speed = 5;
  Map map;
  //Create Window
  sf::RenderWindow window(sf::VideoMode(400, 400), "Pong SFML C++");
  window.setFramerateLimit(30);

  //Create a rectangle to represent the player
  sf::RectangleShape player(sf::Vector2f(10, 10));
  player.setFillColor(sf::Color::White);
  player.setPosition(200, 200);

  //Game Loop
  while (window.isOpen())
  {
    sf::Vector2f pPos = player.getPosition();

    //receive input from the client
    if (client.receive(dataIn, 100, received) != sf::Socket::Done)
    {
      // error...
    }
    //return info back to client
    if (client.send(dataOut, 100) != sf::Socket::Done)
    {
      // error...
    }
    bool W = dataIn[0];
    bool A = dataIn[1];
    bool S = dataIn[2];
    bool D = dataIn[3];
    if (A && !D)
      if (!map.checkCollisionLeft(pPos))
        player.move(-speed, 0);
    pPos = player.getPosition();
    if (D && !A)
      if (!map.checkCollisionRight(pPos))
        player.move(speed, 0);
    pPos = player.getPosition();
    if (W && !S)
      if (!map.checkCollisionUp(pPos))
        player.move(0, -speed);
    pPos = player.getPosition();
    if (S && !W)
      if (!map.checkCollisionDown(pPos))
        player.move(0, speed);
    pPos = player.getPosition();

    //Check if the window was closed
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) window.close();
    }

    //Render
    window.clear();

    map.displayMap(window);
    window.draw(player);

    window.display();
  }
  return 0;
}
