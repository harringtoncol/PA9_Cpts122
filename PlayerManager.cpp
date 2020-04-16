#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	currentPlayer = new Player();
}
PlayerManager::~PlayerManager()
{
	delete currentPlayer;
}
