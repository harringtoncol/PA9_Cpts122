#pragma once
#include "Inventory.h"
class HotBar : public Inventory
{
public:
	HotBar(int arrSize) : Inventory(arrSize) {
		return;
	}
	void Update(sf::RenderWindow& window);
	void displayInventory(sf::RenderWindow& window, int rows, int cols);
};

