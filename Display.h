#pragma once
#include<SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <time.h>
#include "Menu.h"


void displayMenu(Menu menu, sf::RenderWindow& window, sf::Clock clock, sf::Time elapsed);
void displayTimer(sf::RenderWindow& window, sf::Clock clock, sf::Time elapsed, int posX, int posY);
void displayWinner(sf::RenderWindow& window, int gameTime, bool isWinner, int posX, int posY);