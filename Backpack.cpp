#include "Backpack.h"

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
	inventoryBackground.setFillColor(sf::Color::Magenta);

	int posX = 450;
	int posY = 450;
	inventoryBackground.setPosition(posX, posY);
	window.draw(inventoryBackground);

	printCells(window, posX, posY, rows, cols);
}