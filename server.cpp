#include <iostream>
#include <SFML/Network.hpp>

int main(int argc, char *argv[])
{
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
  do
  {
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

    //print out keyboard inputs
    for (int i = 0; i < 6; ++i)
      std::cout << (char) (dataIn[i] + '0');
    std::cout << std::endl;
  }
  while (dataIn[4] != 1);
}
