#include "Inventory.h"


Inventory::Inventory(int arrSize)
{
	arr = new int[arrSize];
	length = arrSize;
	clear(); //Zeros out the arrIsEmpty
}

Inventory::Inventory(int arrSize, int renderLayer): GameObject(renderLayer) { //Constructor
	arr = new int[arrSize];
	length = arrSize;
	clear(); //Zeros out the arrIsEmpty
}

void Inventory::printCells(sf::RenderWindow& window, int posX, int posY, int rows, int cols)
{
	Items icon;

	int count = 0;
	int lastPosX = posX;
	int lastPosY = posY;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printOneCell(window, lastPosX, lastPosY, count);
			if (arr[count] != 0) { //If there is an item at the location
				int value = arr[count];
				icon.printItem(window, (lastPosX + 6), (lastPosY + 6), value);
			}
			lastPosX += CELL_LENGTH_HEIGHT + 5;
			count++;
		}
		lastPosX = posX;
		lastPosY += CELL_LENGTH_HEIGHT + 5;
	}
}

void Inventory::printOneCell(sf::RenderWindow& window, int lastPosX, int lastPosY, int count)
{
	sf::RectangleShape cell(sf::Vector2f(CELL_LENGTH_HEIGHT, CELL_LENGTH_HEIGHT));
	cell.setFillColor(sf::Color::White);
	cell.setPosition(lastPosX + 5, lastPosY + 5);
	window.draw(cell);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) return;
	sf::Text text;
	string s = to_string(count);
	text.setFont(font);
	text.setString(s);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setPosition(sf::Vector2f(lastPosX + 5, lastPosY + 5));
	window.draw(text);
}

bool Inventory::add(int idx, int val) { //Adds an item, if the array isnt full
	if (idx == -1) { //Array is full
		return false;
	}
	arr[idx] = val;
	itemsInArr++;
	return true;
}

int Inventory::remove(int idx) { //Removes an item, if there is an item to remove
	int retValue = 0;

	if (idx >= 0 && idx < count()) {
		retValue = arr[idx];
		itemsInArr--;
	}
	return retValue; //Returns value that was removed
}

int Inventory::peek(int idx) {
	return (arr[idx]); //Returns true if the retValue is valid
}

bool Inventory::isEmpty() {
	return (itemsInArr == 0);
}

bool Inventory::isEmptyIdx(int idx) { //Return true if out of bound or empty!!
	return (idx < 0 || idx >= size());
}

bool Inventory::isFull() {
	return (itemsInArr == length);
}

int Inventory::count() {
	return itemsInArr;
}

int Inventory::size() {
	return length;
}

void Inventory::clear() {
	for (int i = 0; i < length; i++) {
		arr[i] = 0;
	}
	itemsInArr = 0;
}

void Inventory::trade(Inventory& inventory1, Inventory& inventory2, int num)
{
	int item = 0;
	int count = 0;
	if (!inventory2.isFull()) {
		inventory1.remove(num);
		while (!inventory2.isEmptyIdx(count)) {
			count++;
		}
		inventory2.add(count, item);
	}
}

int Inventory::checkInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) return 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) return 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) return 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) return 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) return 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) return 5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) return 6;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) return 7;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) return 8;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) return 9;
	else return -1;
}


