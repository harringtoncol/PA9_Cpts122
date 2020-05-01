#pragma once
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <list>

#define MAZE_SIZE 13
#define CELL_SIZE 60

class Maze {
private:
	std::stack<Cell*> path;
	int* map = nullptr;
	sf::Sprite sprite;
	sf::Texture texture;
	Cell* checkNeighbors(sf::Vector2i position);
	Cell maze[MAZE_SIZE * MAZE_SIZE];
	Cell* getCell(int x, int y);
	Cell* current;
	Cell* start;
	Cell* end;
	void removeWall(Cell* current, Cell* next);
	void singleStep();

public:
	Maze();
	~Maze();
	int** copyMazeToIntArray();
	void setMazeFromIntArray(int* arry);
	void generateMaze();

	void printMazeConsole();
	void printMazeSFML(sf::RenderWindow& window);
	void drawCell(Cell cell, sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
};