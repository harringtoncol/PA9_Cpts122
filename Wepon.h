#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "SFML/System/Clock.hpp"
#include "Utilitys.h"

class Wepon : public GameObject{

public:

	Wepon()
	{
		Initialization();
	}
	Wepon(int renderLayer) : GameObject(renderLayer)
	{
		Initialization();
	}

	void Initialization();

	virtual void attack();
	virtual void SetPosition(const sf::Vector2f &position);
	virtual void SetRotation(const float angle);	
	void Update(sf::RenderWindow& window);

protected:
	float damage;
	int ammo;
	sf::Vector2f offsetPos;
	sf::Texture texture;
	sf::Sprite sprite;
	bool canFire;

private:
	sf::Clock clk;
	void fireTimer();
	
};