#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "GameObject.h"
#include "Backpack.h"
#include "HotBar.h"
#include "Pistol.h"
#include "Weapon.h"
#include "Utilitys.h"
#include "AK47.h"
#include "Sniper.h"
#include "map.h"


class Player : public GameObject {
private:
	const float SPEED = 50, ROTATIONAL_SPEED = 4;
        float health = 1000;
	sf::Sprite playerSprite;
	sf::Vector2f lastPosition;
	sf::Texture texture[4];
	sf::Clock clock;
	float animTime;
	int textureIndex;
	void initialization();
protected:
	void walkingAnimation(float);
	void rotateTo(float);
	Weapon* currentWepon;

	AK47* ak;
	Sniper* sniper;
	Pistol* pistol;
public:
	HotBar playerInventory;
	Backpack playerBackpack;
	Map* myMap;
	Player(int renderLayer);
	Player();
        bool alive();
	void Move(sf::Vector2f direction, double distance);
	void Update(sf::RenderWindow& Window) override;
	void takeDamage(float damage);
	void attack();
	void ChangeWeapon(int hotBarIndex);

};