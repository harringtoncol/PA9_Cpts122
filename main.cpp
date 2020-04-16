#include "map.h"

int main(int argc, char const* argv[])
{
    srand(time(NULL));
    //Declare variables
    float dx, dy, speed = 5;
    dx = 0;
    dy = 0;
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
        //Input detection
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            dx = speed;
            dy = speed;
        }
	bool A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
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
        while (window.pollEvent(event)) {
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
