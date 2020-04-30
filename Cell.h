#pragma once
#include <iostream>
#include <SFML/System/Vector2.hpp>
class Cell
{
public:

	sf::Vector2i position;

	int walls[4] = { 1,1,1,1 };
	bool visited = false;

	void print();

};