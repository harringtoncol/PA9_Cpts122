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
	case _Ak47:
		if (!texture.loadFromFile("Rifle.png")) return;
		break;
	case _Ak47Ammo:
		if (!texture.loadFromFile("Ammo.png")) return;
		break;
	}
	icon.setTexture(texture);
	icon.setPosition(posX + 3, posY + 3);
	icon.scale(sf::Vector2f(.03f, .03f));
	window.draw(icon);
}
