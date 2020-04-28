#pragma once
#include <iostream>
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Utilitys.h"
class Bullet : GameObject {
public:
	Bullet(std::string spriteName, const sf::Vector2f startPos,float rotation, float speed);
	void Update(sf::RenderWindow& window) override;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
	float rotation;
	float currentTime;
	const float destroyTime = 5;
};