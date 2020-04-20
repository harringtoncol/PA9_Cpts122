#pragma once
#include "SFML/System/Clock.hpp"
#include "GameObject.h"

class Utility : GameObject
{
public:
	Utility() : GameObject(999)
	{

	}
	static const float Rad2Deg;
	static const float Deg2Rad;
	static double deltaTime();
	static Utility instance;
	void Update(sf::RenderWindow& window) override;

protected:
private:
	sf::Clock clk;
};
