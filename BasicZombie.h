#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "GameObject.h"
#include "Player.h"

class BasicZombie : public GameObject {
private:
	Player* pp;
	double speed = 10;
	double damage = 10;
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
	sf::Texture textureAttack;
	int direction[8]; //N, NE, E, SE , S, NW,W, SW
	int index;
public:
	BasicZombie(Player* p);
	~BasicZombie();
	void move();
	void Update(sf::RenderWindow& Window) override;
	void takeDamage(double);
	int dealDamage();
	void tryAttack();




};