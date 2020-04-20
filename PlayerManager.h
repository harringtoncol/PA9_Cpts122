#pragma once
#include "Player.h"

class PlayerManager : GameObject {
public:
	Player* currentPlayer;

	PlayerManager();
	~PlayerManager();
};