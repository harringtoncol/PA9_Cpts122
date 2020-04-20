#include "Pistol.h"

Pistol::Pistol(int renderLayer) : Wepon(renderLayer)
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
}



