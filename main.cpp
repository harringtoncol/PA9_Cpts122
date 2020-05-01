#pragma once
#include<SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <time.h>
#include "Display.h"

using namespace std;


int main(int argc, char const* argv[]) {
    //Create Window
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Dungeon crawler C++");
    window.setFramerateLimit(30);    
    
    Menu menu; 
    sf::Clock clock; 
    sf::Time elapsed;

    int k = 0;
    //Game Loop
    while (window.isOpen()) {
        //Check if the window was closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
      
        if (k == 0) {
            
            displayMenu(menu, window, clock, elapsed);
            window.clear(sf::Color::Green);

            k++;    
      }

            

        //Render
        window.clear(sf::Color::Green);
       
        if (k == 1) {
            elapsed = clock.restart();
            k++;
        }
        displayTimer(window, clock, elapsed, 500,500);


        window.display();
    }


    std::cout << "can we write things here?" << endl;
    return 0;
}
