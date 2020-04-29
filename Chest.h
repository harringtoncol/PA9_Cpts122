#pragma once
#include "Inventory.h"
class Chest : public Inventory
{
private: 
	bool isOpen;
	bool isChestToHotBar;
public: 
	Chest(int arrSize = 0) : Inventory(arrSize) {
		return;
	}
	Chest(int arrSize, int renderLayer) :Inventory(arrSize, renderLayer) {
		return;
	}
	int xPos;
	int yPos;
	void Update(sf::RenderWindow& window);
	void displayInventory(sf::RenderWindow& window, int rows, int cols);
	void setRandItems(Chest chest);
};

