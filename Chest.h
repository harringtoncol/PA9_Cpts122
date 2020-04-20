#pragma once
#include "Inventory.h"
class Chest : public Inventory
{
private: 
	bool isOpen;
	bool isChestToHotBar;
public: 
	Chest(int arrSize) :Inventory(arrSize) {
		return;
	}
	void Update(sf::RenderWindow& window);
	void displayInventory(sf::RenderWindow& window, int rows, int cols);
	void setRandItems(Chest chest);
};

