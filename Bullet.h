#pragma once
#include <iostream>
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class Bullet : GameObject {
public:
	Bullet(std::string spriteName, const sf::Vector2f startPos,float rotation, float speed);
	void Update(sf::RenderWindow& window) override;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
	float rotation;
	const float Rad2Deg = 180 / 3.14;

};