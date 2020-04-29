#pragma once
#include "Chest.h"



void Chest::Update(sf::RenderWindow& window)
{
	sf::RectangleShape inventoryBackground(sf::Vector2f(75, 50));
	inventoryBackground.setFillColor(sf::Color::Cyan);
	inventoryBackground.setPosition(xPos, yPos);
	window.draw(inventoryBackground);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		isOpen = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		isOpen = false;
	}	
	if (isOpen) {
		Chest::displayInventory(window, 3, length / 3); //Row is always 3	
	}
}

void Chest::displayInventory(sf::RenderWindow& window, int rows, int cols)
{
	sf::RectangleShape inventoryBackground(sf::Vector2f(INVENTORY_BACKGROUND_LENGTH_HEIGHT, INVENTORY_BACKGROUND_LENGTH_HEIGHT));
	inventoryBackground.setFillColor(sf::Color::Cyan);

	int posX = (900 / 2);
	int posY = (900 / 2);
	inventoryBackground.setPosition(posX, posY);
	window.draw(inventoryBackground);

	printCells(window, posX, posY, rows, cols);
}

void Chest::setRandItems(Chest chest) {
	int totalItemsToArray = (rand() % length) + 1;
	int item = 0;
	Items thing;
	for (int i = 0; i < totalItemsToArray; i++) {
		item = thing.getRandItem();
		chest.add(i, item);
	}
}