#include "PlayerManager.h"


PlayerManager::PlayerManager(Map * mapPtr)
{
	currentPlayer = new Player(3);
	currentPlayer->myMap = mapPtr;
}
PlayerManager::~PlayerManager()
{
	delete currentPlayer;
}
