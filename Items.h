#define RIFLE 1
#define AMMO 2

#pragma once
#include "GameObject.h"

class Items : public GameObject
{ 
public:
	int maxItems = 2;
	int getRandItem();
	void printItem(sf::RenderWindow& window, int posX, int posY, int item);
};

