#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "GameObject.h"

class BasicZombie : public GameObject {
private:
	double speed = 10;
	double damage = 20;
	double health = 100;
	sf::Sprite zombieObj;
	sf::Vector2f lastPostition;
	sf::Texture textureN;
	sf::Texture textureNE;
	sf::Texture textureSE; 
	sf::Texture textureSW;
	sf::Texture textureS;
	sf::Texture textureW;
	sf::Texture textureNW;
	sf::Texture textureE;
	sf::Texture* texture;
	int direction[8]; //N, NE, E, SE , S, NW,W, SW
	int index;
public:
	BasicZombie();
	~BasicZombie();
	void move();
	void Update(sf::RenderWindow& Window) override;
	void takeDamage(double);
	int dealDamage();
	




};