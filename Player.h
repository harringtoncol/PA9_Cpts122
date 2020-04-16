#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "GameObject.h"
class Player : public GameObject {
private:
	const float SPEED = 50, ROTATIONAL_SPEED = 4;
	sf::Sprite playerSprite;
	sf::Vector2f lastPosition;
	sf::Texture texture[4];
	sf::Clock clock;
	float animTime;
	const float Rad2Deg = 180.0 / 3.14;
	int textureIndex;

protected:
	void walkingAnimation(float);
	void rotateTo(float);
	double deltaTime();

public:
	Player();
	void Move(sf::Vector2f direction, double distance);
	void Update(sf::RenderWindow& Window) override;
	void takeDamage(float damage);


};