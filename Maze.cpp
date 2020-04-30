#include "Maze.h"
#include <SFML\System\Sleep.hpp>
Cell* Maze::checkNeighbors(sf::Vector2i position)
{
	std::list<Cell*>  neighbors;


	Cell* right = position.x < MAZE_SIZE - 1 ? getCell(position.x + 1, position.y) : nullptr;
	Cell* left = position.x > 0 ? getCell(position.x - 1, position.y) : nullptr;
	Cell* top = position.y > 0 ? getCell(position.x, position.y - 1) : nullptr;
	Cell* bottom = position.y < MAZE_SIZE - 1 ? getCell(position.x, position.y + 1) : nullptr;

	if (top != nullptr && !top->visited)
	{
		neighbors.push_back(top);
	}
	if (bottom != nullptr && !bottom->visited)
	{
		neighbors.push_back(bottom);
	}
	if (left != nullptr && !left->visited)
	{
		neighbors.push_back(left);
	}
	if (right != nullptr && !right->visited)
	{
		neighbors.push_back(right);
	}

	if (neighbors.size() > 0)
	{
		int num = rand() % neighbors.size();
		std::list<Cell*>::iterator it = neighbors.begin();
		//	std::cout << neighbors.size();
		std::advance(it, num);
		//std::cout << (*it)->position.x << "," << (*it)->position.y << std::endl;
		return *it;
	}
	else
	{
		return nullptr;
	}

}

Cell* Maze::getCell(int x, int y)
{
	return maze + (int)(y * (int)MAZE_SIZE) + x;
}

void Maze::removeWall(Cell* current, Cell* next)
{
	int deltaX = current->position.x - next->position.x;
	int deltaY = current->position.y - next->position.y;
	if (deltaX == -1)
	{
		current->walls[1] = false;
		next->walls[3] = false;
	}
	else if (deltaX == 1)
	{
		current->walls[3] = false;
		next->walls[1] = false;
	}
	if (deltaY == 1) {
		current->walls[0] = false;
		next->walls[2] = false;
	}
	else if (deltaY == -1)
	{
		current->walls[2] = false;
		next->walls[0] = false;
	}

}

void Maze::singleStep()
{
	current->visited = true;

	Cell* next = checkNeighbors(current->position);

	if (next != nullptr)
	{
		next->visited = true;

		path.push(current);

		removeWall(current, next);
		current = next;

	}
	else if (!path.empty())
	{
		current = path.top();
		path.pop();
	}
	else
	{
		return;
	}

	singleStep();
}

void Maze::generateMaze()
{
	for (int y = 0; y < MAZE_SIZE; y++)
	{
		for (int x = 0; x < MAZE_SIZE; x++)
		{
			getCell(x, y)->position.x = x;
			getCell(x, y)->position.y = y;
		}
	}
	current = &maze[rand() % MAZE_SIZE * MAZE_SIZE - 1];

	singleStep();

	printMazeConsole();
	std::cout << "Maze built.";
}



Maze::Maze()
{
	if (!texture.loadFromFile("Wall.png"))
		std::cout << "failed to load texture";
	sprite.setTexture(texture);

}

Maze::~Maze()
{
	if (map != nullptr) delete map;
}


int** Maze::copyMazeToIntArray()
{
	int** map = 0;
	map = new int* [MAZE_SIZE * 3];
	for (int y = 0; y < MAZE_SIZE * 3; y++)
	{
		map[y] = new int[MAZE_SIZE * 3];
		for (int x = 0; x < MAZE_SIZE * 3; x++)
		{
			map[y][x] = 1;
		}
	}



	for (int y = 0; y < MAZE_SIZE; y++)
	{
		for (int x = 0; x < MAZE_SIZE; x++)
		{
			Cell cell = *getCell(x, y);
			int cellVertical = y * 3;
			int cellHorizontal = x * 3;
			map[cellVertical + 1][cellHorizontal + 1] = 0;
			if (!cell.walls[0])
			{
				map[cellVertical][cellHorizontal + 1] = 0;
			}
			if (!cell.walls[1])
			{
				map[cellVertical + 1][cellHorizontal + 2] = 0;
			}
			if (!cell.walls[2])
			{
				map[cellVertical + 2][cellHorizontal + 1] = 0;
			}
			if (!cell.walls[3])
			{
				map[cellVertical + 1][cellHorizontal] = 0;
			}
		}
	}
	return map;
}

void Maze::setMazeFromIntArray(int* arry)
{
	//gen maze

	/*for (int i = 0; i < MAZE_SIZE * MAZE_SIZE; i++)
	{
		int index = i / 4;
		Cell* ptr = getCell(index % MAZE_SIZE, index / MAZE_SIZE);
		ptr->walls[i % 4] = arry[i];
	}*/

}


void Maze::printMazeAsArray(int** arry)
{
	std::cout << std::endl;
	for (int y = 0; y < MAZE_SIZE * 3; y++)
	{
		for (int x = 0; x < MAZE_SIZE * 3; x++)
		{
			std::cout << arry[y][x];
		}
		std::cout << std::endl;
	}

}

void Maze::printMazeConsole()
{
	for (int y = 0; y < MAZE_SIZE; y++)
	{
		for (int x = 0; x < MAZE_SIZE; x++)
		{
			Cell cell = *getCell(x, y);

			std::cout << cell.position.x << ", " << cell.position.y << "\t" << cell.walls[0] << ","
				<< cell.walls[1] << "," << cell.walls[2] << "," << cell.walls[3] << "," << std::endl;
		}
		std::cout << std::endl;
	}

}

void Maze::printMazeSFML(sf::RenderWindow& window)
{
	drawCell(*getCell(0, 0), window);

	for (int y = 0; y < MAZE_SIZE; y++)
	{
		for (int x = 0; x < MAZE_SIZE; x++)
		{
			drawCell(*getCell(x, y), window);
		}
	}
}

void Maze::drawCell(Cell cell, sf::RenderWindow& window)
{
	int wallSize = (CELL_SIZE / 3);
	int cellVertical = cell.position.y * CELL_SIZE;
	int cellHorizontal = cell.position.x * CELL_SIZE;
	//std::cout << cell.position.x * CELL_SIZE + wallSize << "," << cell.position.y * CELL_SIZE + wallSize << std::endl;

	sprite.setPosition(cellHorizontal + (wallSize << 1), cellVertical + (wallSize << 1));
	window.draw(sprite);

	sprite.setPosition(cellHorizontal, cellVertical);
	window.draw(sprite);

	sprite.setPosition(cellHorizontal, cellVertical + (wallSize << 1));
	window.draw(sprite);

	sprite.setPosition(cellHorizontal + (wallSize << 1), cellVertical);
	window.draw(sprite);

	if (cell.walls[0])
	{
		sprite.setPosition(cellHorizontal + wallSize, cellVertical);
		window.draw(sprite);
	}
	if (cell.walls[1])
	{
		sprite.setPosition(cellHorizontal + (wallSize << 1), cellVertical + wallSize);
		window.draw(sprite);
	}
	if (cell.walls[2])
	{
		sprite.setPosition(cellHorizontal + wallSize, cellVertical + (wallSize << 1));
		window.draw(sprite);
	}
	if (cell.walls[3])
	{
		sprite.setPosition(cellHorizontal, cellVertical + wallSize);
		window.draw(sprite);
	}
}

void Maze::Update(sf::RenderWindow& window)
{
	printMazeSFML(window);
}

