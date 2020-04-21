#include "Weapon.h"

void Weapon::Initialization()
{
	damage = 10;
	offsetPos = sf::Vector2f(35, 35);
	ammo = 0;
	canFire = true;
}

void Weapon::Update(sf::RenderWindow& window)
{
	window.draw(sprite);
	fireTimer();
}

void Weapon::attack()
{
	if (canFire)
	{
		Bullet* bullet = new Bullet("Bullet.png", sprite.getPosition(), sprite.getRotation(), 0.3);
		canFire = false;
	}
}

void Weapon::SetPosition(const sf::Vector2f& position)
{
	double angle = sprite.getRotation();
	sf::Vector2f localOffset = sf::Vector2f(cos((angle - 60) * Utility::Deg2Rad) * offsetPos.x, sin((angle - 60) * Utility::Deg2Rad) * offsetPos.y);
	sprite.setPosition(position + localOffset);
}

void Weapon::SetRotation(const float angle)
{
	sprite.setRotation(angle);
}

void Weapon::fireTimer()
{
	if (clk.getElapsedTime().asMilliseconds() > 200)
	{
		canFire = true;
		clk.restart();
	}
}