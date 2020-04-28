#include "Pistol.h"

Pistol::Pistol(int renderLayer) : Weapon(renderLayer)
{
	initalization();
}

Pistol::Pistol()
{
	initalization();
}

void Pistol::initalization()
{
	ammo = 100;

	if (!texture.loadFromFile("Pistol.png"))
		std::cout << "Failed to load Pistol Image" << std::endl;
	sprite.setTexture(texture);
	offsetPos = sf::Vector2f(35, 35);
	fireSpeed = 400;
}



