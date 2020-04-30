#pragma once
#include<SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Menu.h"

using namespace std;

void displayMenu(Menu menu, sf::RenderWindow& window);


int main(int argc, char const* argv[]) {
    //Create Window
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Dungeon crawler C++");
    window.setFramerateLimit(30);    
    
    Menu menu; 

    int k = 0;
    //Game Loop
    while (window.isOpen()) {
        //Check if the window was closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
      
        if (k == 0) {
            
            displayMenu(menu, window);

            window.clear(sf::Color::Green);
        
            k++;
      }

            

        //Render
        window.clear(sf::Color::Green);
       
      //  map.displayMap(window);
        window.display();
    }


    std::cout << "can we write things here?" << endl;
    return 0;
}

void displayMenu(Menu menu, sf::RenderWindow &window)
{
    bool isMenuOpen = true;
    menu.printMenu(window);
    window.display();
    while (isMenuOpen) {
        int opt = menu.checkInput();
        if (opt > 0 && opt < 4) {
            if (opt == 1) break;
            else if (opt == 2) {
                menu.printInstructions(window);
                window.display();
                bool isRulesOpen = true;
                while (isRulesOpen) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        isRulesOpen = false;
                    }
                }
                menu.printMenu(window);
                window.display();
            }
            else if (opt == 3) window.close();
        }
    }
}
