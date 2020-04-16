/* This file has its own main method and map class. Will be split up later.
 * If unable to move, you started inside a randomly generated blue square. Re run the program to get free
 */
#define WIDTH 40
#define HEIGHT 40

#include <stdio.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <string>

enum Obstacle
{
  AIR,
  WALL
};

class Map
{
  private:
    int map[WIDTH][HEIGHT];
  public:
    Map()
    {
      for (int i = 0; i < WIDTH; ++i)
        for (int j = 0; j < HEIGHT; ++j)
	  map[i][j] = (rand() % 15) == 0;
    }
    void displayMap(sf::RenderWindow &window)
    {
      sf::RectangleShape wall(sf::Vector2f(10, 10));
      wall.setFillColor(sf::Color::Blue);
      for (int i = 0; i < WIDTH; ++i)
        for (int j = 0; j < HEIGHT; ++j)
	  if (map[i][j] == 1)
	  {
	    wall.setPosition(i * 10, j * 10);
	    window.draw(wall);
	  }
    }
    bool checkCollisionUp(sf::Vector2f &pPos)
    {
      int x1 = (int) ((pPos.x + 5) / 10);
      int x2 = (int) pPos.x / 10;
      int y1 = (int) ((pPos.y + 5) / 10);
      if (y1 > 0)
      {
        if (x1 != x2)
	{
          if (map[x1][y1 - 1] != WALL && map[x2][y1 - 1] != WALL)
	    return false;
	}
        else if (map[x1][y1 - 1] != WALL)
	  return false;
      }
      return true;
    }
    bool checkCollisionDown(sf::Vector2f &pPos)
    {
      int x1 = (int) ((pPos.x + 5) / 10);
      int x2 = (int) pPos.x / 10;
      int y1 = (int) pPos.y / 10;
      if (y1 < HEIGHT - 1)
      {
        if (x1 != x2)
	{
          if (map[x1][y1 + 1] != WALL && map[x2][y1 + 1] != WALL)
	    return false;
	}
        else if (map[x1][y1 + 1] != WALL)
	  return false;
      }
      return true;
    }
    bool checkCollisionLeft(sf::Vector2f &pPos)
    {
      int x1 = (int) ((pPos.x + 5) / 10);
      int y1 = (int) ((pPos.y + 5) / 10);
      int y2 = (int) pPos.y / 10;
      if (x1 > 0)
      {
        if (y1 != y2)
	{
          if (map[x1 - 1][y1] != WALL && map[x1 - 1][y2] != WALL)
	    return false;
	}
        else if (map[x1 - 1][y1] != WALL)
	  return false;
      }
      return true;
    }
    bool checkCollisionRight(sf::Vector2f &pPos)
    {
      int x1 = (int) pPos.x / 10;
      int y1 = (int) ((pPos.y + 5) / 10);
      int y2 = (int) pPos.y / 10;
      if (x1 < WIDTH - 1)
      {
        if (y1 != y2)
	{
          if (map[x1 + 1][y1] != WALL && map[x1 + 1][y2] != WALL)
	    return false;
	}
        else if (map[x1 + 1][y1] != WALL)
	  return false;
      }
      return true;
    }
};

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
    sf::RectangleShape wall(sf::Vector2f(10, 10));
    player.setFillColor(sf::Color::White);
    player.setPosition(200, 200);
    wall.setFillColor(sf::Color::Red);
    wall.setPosition(100, 100);

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
        window.draw(wall);
   
        window.display();
    }
    return 0;
}
