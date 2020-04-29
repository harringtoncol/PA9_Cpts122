#include "Sniper.h"

Sniper::Sniper(int renderLayer) : Weapon(renderLayer)
{

	initalization();
}

Sniper::Sniper()
{
	initalization();
}

void Sniper::initalization()
{
	ammo = 25;

	if (!texture.loadFromFile("Sniper.png"))
		std::cout << "Failed to load Pistol Image" << std::endl;
	sprite.setTexture(texture);
	offsetPos = sf::Vector2f(60, 60);
	angleOffset = 70;
	fireSpeed = 1500;
	damage = 100;
}
