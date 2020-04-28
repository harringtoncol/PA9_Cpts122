#include "Bullet.h"


Bullet::Bullet(std::string spriteName, const sf::Vector2f startPos, float rotation, float speed)
{
	if (!texture.loadFromFile(spriteName))
		std::cout << "Failed to load " << spriteName;
	sprite.setTexture(texture);

	this->rotation = rotation;
	this->speed = speed;
	currentTime = 0;


	sprite.setPosition(startPos.x, startPos.y);
	sprite.setRotation(rotation);
}

void Bullet::Update(sf::RenderWindow& window)
{
	sprite.move(-speed * cos(rotation * Utility::Deg2Rad + 1.5708) * Utility::Rad2Deg,
		-speed * sin(rotation * Utility::Deg2Rad + 1.5708) * Utility::Rad2Deg);
	window.draw(sprite);
	currentTime += Utility::deltaTime();

	if (currentTime > destroyTime)
	{
		delete this;
	}
}
