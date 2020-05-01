#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "gameObject.h"
#include "player.h"

class Ghosts : public GameObject {
private:
	sf::Sprite ghostObj;
	sf::Vector2f p1Pos;
	sf::Vector2f p2Pos;
	sf::Vector2f ghostPos;
	sf::Clock clk;
	sf::Time time;
	float speed = 1;
	public:
		void setSpeed();
		Ghosts();
		int update(sf::Vector2f, sf::Vector2f);
		void move();
		int hitPlayer();
};
