#define _Pistol 1
#define _PistolAmmo 2
#define _Ak47 3
#define _Ak47Ammo 4 
#define _Sniper 5
#define _SniperAmmo 6

#pragma once
#include "GameObject.h"

class Items : public GameObject
{ 
public:
	int maxItems = 2;
	int getRandItem();
	void printItem(sf::RenderWindow& window, int posX, int posY, int item);
};

