#include<SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "PlayerManager.h"
#include "GameObject.h"



int main(int argc, char const* argv[]) {

    //Create Window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Pong SFML C++");
    window.setFramerateLimit(30);

	PlayerManager playerManager;

    //Game Loop
    while (window.isOpen()) {
        //Check if the window was closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        //Render
        window.clear();
		
		for (int i = 0; i < GameObject::GameObjects.size(); i++)
		{
			GameObject::GameObjects[i]->Update(window);
		}
		
        window.display();
    }
    return 0;
}
