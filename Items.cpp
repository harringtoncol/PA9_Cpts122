#include "Items.h"

int Items::getRandItem()
{
	return (rand() % maxItems + 1);
}

void Items::printItem(sf::RenderWindow& window, int posX, int posY, int item)
{
	sf::Texture texture;
	sf::Sprite icon;

	switch (item) {
	case _Pistol:
		if (!texture.loadFromFile("Pistol.png")) return;
		break;
	case _PistolAmmo:
		if (!texture.loadFromFile("PistolAmmo.png")) return;
		break;
	case _Ak47:
		if (!texture.loadFromFile("Ak47.png")) return;
		break;
	case _Ak47Ammo:
		if (!texture.loadFromFile("Ak47Ammo.png")) return;
		break;
	case _Sniper:
		if (!texture.loadFromFile("Sniper.png")) return;
		break;
	case _SniperAmmo:
		if (!texture.loadFromFile("SniperAmmo.png")) return;
		break;

	}
	icon.setTexture(texture);
	icon.setPosition(posX + 3, posY + 3);
	icon.scale(sf::Vector2f(.03f, .03f));
	window.draw(icon);
}
