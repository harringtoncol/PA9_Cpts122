#include <iostream>
#include <SFML/Network.hpp>

int main()
{
  std::cout << sf::IpAddress::getLocalAddress() << std::endl;
  std::cout << sf::IpAddress::getPublicAddress() << std::endl;
  sf::TcpListener listener;

  // bind the listener to a port
  if (listener.listen(53000) != sf::Socket::Done)
  {
    // error...
  }

  // accept a new connection
  sf::TcpSocket client;
  if (listener.accept(client) != sf::Socket::Done)
  {
    // error...
  }
  char data[100];
  std::size_t received;

  // TCP socket:
  if (client.receive(data, 100, received) != sf::Socket::Done)
  {
    // error...
  }
  std::cout << "Received " << received << " bytes" << std::endl;
  std::cout << data << std::endl;
}
