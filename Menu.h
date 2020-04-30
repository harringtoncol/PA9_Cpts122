#pragma once
#include<SFML/Graphics.hpp>
#include <string>

class Menu
{
private: 
	sf::Font font;
	sf::Text text;
public: 
	Menu();
	void printMenu(sf::RenderWindow& window);
	void printOptions(sf::RenderWindow& window);
	void printInstructions(sf::RenderWindow& window);
	int checkInput();
};

