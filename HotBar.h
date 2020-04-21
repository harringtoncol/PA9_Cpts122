#pragma once
#include "Inventory.h"
class HotBar : public Inventory
{
public:
	HotBar(int arrSize = 0);
	HotBar(int arrSize, int renderLayer) : Inventory(arrSize, renderLayer) {
		return;
	}
	void Update(sf::RenderWindow& window) override;
	void displayInventory(sf::RenderWindow& window, int rows, int cols);
};

