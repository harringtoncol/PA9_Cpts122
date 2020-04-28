#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "SFML/System/Clock.hpp"
#include "Utilitys.h"

class Weapon : public GameObject{

public:

	Weapon()
	{
		Initialization();
	}
	Weapon(int renderLayer) : GameObject(renderLayer)
	{
		Initialization();
	}

	void Initialization();

	virtual void attack();
	virtual void SetPosition(const sf::Vector2f &position);
	virtual void SetRotation(const float angle);	
	void Update(sf::RenderWindow& window);
	bool enabled = false;
protected:
	float damage;
	float angleOffset;
	int ammo;
	sf::Vector2f offsetPos;
	sf::Texture texture;
	sf::Sprite sprite;
	bool canFire;
	float fireSpeed;
private:
	sf::Clock clk;
	void fireTimer();
	
};