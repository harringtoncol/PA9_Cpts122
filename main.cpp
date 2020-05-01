/*
Cole Harrington
Lance Stupfel
Ryan McKee
Shira Feinberg
PA-9 Scary Maze Game
Cpts 122
5/1/2020
*/

#include "map.h"
#include "Display.h"

int main(int argc, char const* argv[])
{
  srand(time(NULL));

  //prints out the local and public ip addresses of the server.
  //Currently only works on lan
  std::cout << sf::IpAddress::getLocalAddress() << std::endl;
  //std::cout << sf::IpAddress::getPublicAddress() << std::endl;

  //default port is 52000, first command line argument is the modified port number
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

  //connects to 2 clients
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

  //char arrays for sending and receiving data
  char dataIn[100];
  char dataOut[3000];
  //for some reason packets don't send properly without \n at the end
  dataOut[2999] = '\n';

  std::size_t received;
  
  //creates a map with players 1 and 2 using clients 1 and 2
  Map map(&client1, &client2);

  //determines if a close signal is sent from a client
  int close;
  //Game Loop
  do
  {
    // updates positions from clients and determines if either client closed
    close = map.update();

    //packages the map into a char array
    map.sendMap(dataOut);

    //sends a close signal to both clients if necessary
    dataOut[1700] = close;

    //sends info back to client
    if (client1.send(dataOut, 3000) != sf::Socket::Done)
    {
      // error...
    }
    //sends info back to client
    if (client2.send(dataOut, 3000) != sf::Socket::Done)
    {
      // error...
    }
  }
  while (!close);
  return 0;
}
