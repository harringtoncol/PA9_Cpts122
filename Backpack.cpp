#include "Backpack.h"

Backpack::Backpack(int arrSize)
{
	arr = new int[arrSize];
	length = arrSize;
	clear(); //Zeros out the arrIsEmpty
}

void Backpack::Update(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		isOpen = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		isOpen = false;
	}
	if (isOpen) {
		Backpack::displayInventory(window, 3, length / 3); //Row is always 3	
	}
}

void Backpack::displayInventory(sf::RenderWindow& window, int rows, int cols)
{
	sf::RectangleShape inventoryBackground(sf::Vector2f(INVENTORY_BACKGROUND_LENGTH_HEIGHT, INVENTORY_BACKGROUND_LENGTH_HEIGHT));
	inventoryBackground.setFillColor(sf::Color::Blue);

	int posX = (900 / 2);
	int posY = (900 / 2);
	inventoryBackground.setPosition(posX, posY);
	window.draw(inventoryBackground);

	printCells(window, posX, posY, rows, cols);
}