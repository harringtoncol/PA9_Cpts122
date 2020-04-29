#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
  sf::TcpSocket socket;
  //default ip adderss, enter a different one as first argument if necessary, or recompile. second argument is port. otherwise is just fine running with no arguments
  std::string ipAddress = "10.0.0.206";
  int port = 52000;
  if (argc > 1)
    ipAddress = argv[1];
  if (argc > 2)
    port = atoi(argv[2]);

  sf::Socket::Status status = socket.connect(ipAddress, port);
  if (status != sf::Socket::Done)
  {
    // error...
  }

  //data must end in a \n, or the packet doesn't seem to send properly.
  //It would instead be sent in the next packet containing a a newline
  char dataOut[100] = "\n\n\n\n\n\n\n";
  char dataIn[100];
  std::size_t received;
  //format of data - w a s d q i
  do
  {
    dataOut[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    dataOut[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    dataOut[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    dataOut[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    dataOut[4] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    dataOut[5] = sf::Keyboard::isKeyPressed(sf::Keyboard::I);
    //send input to server
    if (socket.send(dataOut, 100) != sf::Socket::Done)
    {
      // error...
    }
    //receive info back from server
    if (socket.receive(dataIn, 100, received) != sf::Socket::Done)
    {
      // error...
    }
  }
  while (dataOut[4] != 1);
}
