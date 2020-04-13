#include<SFML/Graphics.hpp>
#include<string>

int main(int argc, char const* argv[]) {
    //Declare variables
    float dx, dy, speed = 5;
    dx = 0;
    dy = 0;

    //Create Window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Pong SFML C++");
    window.setFramerateLimit(30);

    //Create a rectangle to represent the player
    sf::RectangleShape player(sf::Vector2f(10, 10));
    player.setFillColor(sf::Color::White);
    player.setPosition(200, 200);

    //Game Loop
    while (window.isOpen()) {
        sf::Vector2f pPos = player.getPosition();
        //Input detection
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            dx = speed;
            dy = speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            if (pPos.x > 0)
                player.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if (pPos.x < 400 - 10)
                player.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            if(pPos.y > 0)
            player.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            if(pPos.y < 400-10)
            player.move(0, speed);
        //Check if the window was closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        //Render
        window.clear();
      
        window.draw(player);
   
        window.display();
    }
    return 0;
}
