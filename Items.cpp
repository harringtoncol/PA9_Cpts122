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
	case RIFLE:
		if (!texture.loadFromFile("Rifle.png")) return;
		break;
	case AMMO:
		if (!texture.loadFromFile("Ammo.png")) return;
		break;
	}
	icon.setTexture(texture);
	icon.setPosition(posX + 3, posY + 3);
	icon.scale(sf::Vector2f(.03f, .03f));
	window.draw(icon);
}
