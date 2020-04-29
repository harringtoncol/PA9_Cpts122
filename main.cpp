#include<SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include <iostream>
#include "PlayerManager.h"
#include "GameObject.h"
#include "map.h"
#include "BasicZombie.h"
#include <time.h>


int main(int argc, char const* argv[]) {
    //Create Window
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Dungeon crawler C++");
    window.setFramerateLimit(30);

    
	
    Utility ut;
    Map map(1);
    PlayerManager playerManager(&map);
    int i = rand() % 6 + 1;
    i = 7;
    printf("%d", i);
   
        BasicZombie* zombie1,*zombie2, *zombie3, *zombie4, *zombie5, *zombie6;
        zombie1 = new BasicZombie(playerManager.currentPlayer);
        if (i > 1)
       zombie2 = new BasicZombie(playerManager.currentPlayer);
    if (i > 2)
         zombie3 = new BasicZombie(playerManager.currentPlayer);
    if (i > 3)
        zombie4 = new BasicZombie(playerManager.currentPlayer);
    if (i > 4)
        zombie5 = new BasicZombie(playerManager.currentPlayer);
    if (i > 5)
         zombie6 = new BasicZombie(playerManager.currentPlayer);




    //Game Loop
    while (window.isOpen() && playerManager.currentPlayer->alive()) {
        //Check if the window was closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        //Render
        window.clear(sf::Color::Green);
      
            for (int i = 0; i < GameObject::GameObjects.size(); i++)
            {

                std::cout << GameObject::GameObjects[i]->position.x << "  " << GameObject::GameObjects.size() << std::endl;
                GameObject::GameObjects[i]->Update(window);
            }

       
      //  map.displayMap(window);
        window.display();
    }


    std::cout << "can we write things here?" << endl;
    return 0;
}
