#include <iostream>
#include <SFML/Network.hpp>

int main()
{
  sf::TcpSocket socket;
  sf::Socket::Status status = socket.connect("10.0.0.16", 53000);
  if (status != sf::Socket::Done)
  {
    // error...
  }
  char data[100] = "Hello World";

  // TCP socket:
  if (socket.send(data, 100) != sf::Socket::Done)
  {
    // error...
  }
}
