#pragma once
#include "Inventory.h"
class HotBar : public Inventory
{
public:
	HotBar(int arrSize = 0) : Inventory(arrSize) {
		return;
	}
	HotBar(int arrSize, int renderLayer) : Inventory(arrSize, renderLayer) {
		return;
	}
	void Update(sf::RenderWindow& window) override;
	void displayInventory(sf::RenderWindow& window, int rows, int cols);
};

