#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	currentPlayer = new Player(3);
}
PlayerManager::~PlayerManager()
{
	delete currentPlayer;
}
