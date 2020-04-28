#include "AK47.h"

AK47::AK47(int renderLayer) : Weapon(renderLayer)
{
	initalization();
}

AK47::AK47()
{
	initalization();
}

void AK47::initalization()
{
	ammo = 200;

	if (!texture.loadFromFile("Ak47.png"))
		std::cout << "Failed to load Pistol Image" << std::endl;
	sprite.setTexture(texture);
	offsetPos = sf::Vector2f(50, 50);
}
