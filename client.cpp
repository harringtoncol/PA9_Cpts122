#include "map.h"
#include "Display.h"

int main(int argc, char *argv[])
{
  sf::TcpSocket socket;
  //default ip adderess, enter a different one as first argument if necessary, or recompile
  //second argument is port (default is 52000)
  //otherwise is just fine running with no arguments
  std::string ipAddress = "10.0.0.206";
  int port = 52000;
  if (argc > 1)
    ipAddress = argv[1];
  if (argc > 2)
    port = atoi(argv[2]);

  //connects to the server
  sf::Socket::Status status = socket.connect(ipAddress, port);
  if (status != sf::Socket::Done)
  {
    // error...
  }
  std::cout << "Waiting for other client to connect" << std::endl;

  //creates a blank map with players and ghost (only used to display)
  Map map(NULL, NULL);

  //Create Window
  sf::RenderWindow window(sf::VideoMode(400, 400), "Maze Game");
  window.setFramerateLimit(30);

  //data must end in a \n, or the packet doesn't seem to send properly.
  //It would instead be sent in the next packet containing a a newline

  //format of data - w a s d q i
  char dataOut[100] = "\n\n\n\n\n\n\n";
  char dataIn[3000];

  std::size_t received;

  //only read keyboard input if the window is selected
  bool focus = true;
  //determines if the close signal has been received from the server
  int close = 0;
  do
  {
    dataOut[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::W) && focus;
    dataOut[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::A) && focus;
    dataOut[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::S) && focus;
    dataOut[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::D) && focus;
    //sends the close call to the server
    dataOut[4] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && focus || !window.isOpen();
    dataOut[5] = sf::Keyboard::isKeyPressed(sf::Keyboard::I) && focus;
    //send input to server
    if (socket.send(dataOut, 100) != sf::Socket::Done)
    {
      // error...
    }
    //receive map info back from server
    if (socket.receive(dataIn, 3000, received) != sf::Socket::Done)
    {
      // error...
    }
    //determines if the client needs to close
    close = dataIn[1700];

    //populates the map
    map.extractMap(dataIn);

    //determines if the window is focused or closed
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) window.close();
      if(event.type == sf::Event::GainedFocus)
        focus = true;
      if(event.type == sf::Event::LostFocus)
        focus = false;
    }

    //Render
    window.clear();

    //displays the map
    map.displayMap(window);

    //Check if the window was closed
    window.display();
  }
  while (dataOut[4] != 1 && window.isOpen() && !close);
  // disconnects if window is closed or either client presses q
  return 0;
}

