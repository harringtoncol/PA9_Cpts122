#include "Bullet.h"


Bullet::Bullet(std::string spriteName, const sf::Vector2f startPos, float rotation, float speed)
{

	if (!texture.loadFromFile(spriteName))
		std::cout << "Failed to load " << spriteName;
	sprite.setTexture(texture);



	this->rotation = rotation;
	this->speed = speed;


	sprite.setPosition(startPos.x, startPos.y);
	sprite.setRotation(rotation);
}

void Bullet::Update(sf::RenderWindow& window)
{
	sprite.move(-speed * cos(rotation * 0.0174533 + 1.5708) * Rad2Deg, -speed * sin(rotation * 0.0174533 + 1.5708) * Rad2Deg);
	window.draw(sprite);

}
