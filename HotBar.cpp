#include "HotBar.h"


HotBar::HotBar(int arrSize)
{
	arr = new int[arrSize];
	length = arrSize;
	clear(); //Zeros out the arrIsEmpty
}

void HotBar::Update(sf::RenderWindow& window)
{
	HotBar::displayInventory(window, 1, 3);
}

void HotBar::displayInventory(sf::RenderWindow& window, int rows, int cols)
{
	sf::RectangleShape inventoryBackground(sf::Vector2f(INVENTORY_BACKGROUND_LENGTH_HEIGHT, (CELL_LENGTH_HEIGHT + 10)));
	inventoryBackground.setFillColor(sf::Color::Magenta);

	int posX = 450;
	int posY = 900;
	inventoryBackground.setPosition(posX, posY);
	window.draw(inventoryBackground);

	printCells(window, posX, posY, rows, cols);
}