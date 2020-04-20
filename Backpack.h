#pragma once
#include "Inventory.h"
class Backpack : public Inventory
{
private:
	bool isOpen;
	bool isBackpackToHotBar;
public:
	Backpack(int arrSize) :Inventory(arrSize) {
		return;
	}
	void Update(sf::RenderWindow& window);
	void displayInventory(sf::RenderWindow& window, int rows, int cols);
};

