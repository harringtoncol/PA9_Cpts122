#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "GameObject.h"

class BasicZombie : public GameObject {
private:
	double speed = 4;
	double damage = 20;
	double health = 100;
	sf::Sprite zombieObj;
	sf::Vector2f lastPostition;
	sf::Texture texture;
public:
	BasicZombie();
	~BasicZombie();
	void move();
	void Update(sf::RenderWindow& Window) override;
	void takeDamage(double);
	int dealDamage();





};