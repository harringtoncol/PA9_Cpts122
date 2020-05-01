#include "map.h"

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
  sf::TcpSocket client1;
  if (listener.accept(client1) != sf::Socket::Done)
  {
    // error...
  }
  std::cout << "Client 1 connected" << std::endl;
  // accept a new connection
  sf::TcpSocket client2;
  if (listener.accept(client2) != sf::Socket::Done)
  {
    // error...
  }
  std::cout << "Client 2 connected" << std::endl;
  char dataIn[100];
  char dataOut[3000];
  dataOut[2999] = '\n';

  std::size_t received;
  Ghosts ghost;
  Map map(&client1, &client2, &ghost);
  int close;
  //Game Loop
  do
  {
    //determines if either client closed
    close = map.update();
    map.sendMap(dataOut);
    //return info back to client
    dataOut[1700] = close;
    if (client1.send(dataOut, 3000) != sf::Socket::Done)
    {
      // error...
    }
    //return info back to client
    if (client2.send(dataOut, 3000) != sf::Socket::Done)
    {
      // error...
    }
  }
  while (!close);
  return 0;
}
