#pragma once
#include "Player.h"
#include "HotBar.h"
#include "Backpack.h"
#include "map.h"

class PlayerManager : GameObject {
public:
	Player* currentPlayer;
	
	PlayerManager(Map* mapPtr);
	~PlayerManager();
};