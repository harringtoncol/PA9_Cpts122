#define INVENTORY_BACKGROUND_LENGTH_HEIGHT 150
#define CELL_LENGTH_HEIGHT 42.5

#pragma once
#include <SFML\Graphics.hpp>
#include<vector>
#include "Items.h"

using namespace std;

class Inventory : public GameObject {
protected:
	int* arr;
	int length; //Length of array and should only be in intervals of 3 (Player inventory = 3, Chest = 9, Backpack = 9)
	int itemsInArr;
public:
	Inventory(int arrSize = 0);
	Inventory(int arrSize, int renderLayer); //Creates an array of size zero, unless specificied otherwise
	void printCells(sf::RenderWindow& window, int posX, int posY, int rows, int cols);
	void printOneCell(sf::RenderWindow& window, int lastPosX, int lastPosY, int count);
	bool add(int idx, int val);
	int remove(int idx, bool& success);
	int peek(int idx, bool& success);
	int remove(int idx); //overload without success flag return
	int peek(int idx); //overload without success flag return
	bool isEmpty();
	bool isEmptyIdx(int idx);
	bool isFull();
	int count();
	int size();
	void clear();
	void trade(Inventory& inventory1, Inventory& inventory2, int num);
	int checkInput();
};

