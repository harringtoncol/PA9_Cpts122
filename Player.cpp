#include "Player.h"


Player::Player(int renderLayer) : GameObject(renderLayer)
{
	initialization();
}

Player::Player()
{
	initialization();
}

void Player::Move(sf::Vector2f direction, double distance)
{
	playerSprite.move(direction.x * distance, direction.y * distance);
}

void Player::Update(sf::RenderWindow& window)
{
	//weapon select
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		ChangeWeapon(1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		ChangeWeapon(2);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		ChangeWeapon(3);


	sf::Vector2f PlayerPos = playerSprite.getPosition();
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	//Input detection
	if (!myMap->checkCollisionLeft(PlayerPos))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			Move(sf::Vector2f(-1, 0), Utility::deltaTime() * SPEED);
	if (!myMap->checkCollisionRight(PlayerPos))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			Move(sf::Vector2f(1, 0), Utility::deltaTime() * SPEED);
	if (!myMap->checkCollisionUp(PlayerPos))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			Move(sf::Vector2f(0, -1), Utility::deltaTime() * SPEED);
	if (!myMap->checkCollisionDown(PlayerPos))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			Move(sf::Vector2f(0, 1), Utility::deltaTime() * SPEED);


	float angle = atan2f(mousePos.y - PlayerPos.y, mousePos.x - PlayerPos.x) * Utility::Rad2Deg + 90;
	rotateTo(angle);
	walkingAnimation(sqrt(pow((PlayerPos.x - lastPosition.x), 2) + pow((PlayerPos.y - lastPosition.y), 2)));

	if (currentWepon != nullptr)
	{
		//attack
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			attack();

		currentWepon->SetPosition(playerSprite.getPosition());
		currentWepon->SetRotation(playerSprite.getRotation());
	}

	window.draw(playerSprite);
	clock.restart();
	lastPosition = PlayerPos;
}



void Player::initialization()
{
	myMap = nullptr;
	textureIndex = 0;
	animTime = 0;

	pistol = new Pistol(1);
	ak = new AK47(1);
	sniper = new Sniper(1);

	playerInventory.add(0, 1);
	playerInventory.add(1, 3);
	playerInventory.add(2, 5);

	currentWepon = nullptr;

	if (!texture[0].loadFromFile("PlayerMainSprite.png", sf::IntRect(0, 0, 62, 33)))
		std::cout << "\n\nfile to load PlayerMainSprite.png check if it exists :)\n\n" << system("dir");
	if (!texture[1].loadFromFile("PlayerMainSprite.png", sf::IntRect(61, 0, 62, 33)))
		std::cout << "\n\nfile to load PlayerMainSprite.png check if it exists :)\n\n" << system("dir");
	if (!texture[2].loadFromFile("PlayerMainSprite.png", sf::IntRect(0, 32, 62, 33)))
		std::cout << "\n\nfile to load PlayerMainSprite.png check if it exists :)\n\n" << system("dir");
	if (!texture[3].loadFromFile("PlayerMainSprite.png", sf::IntRect(61, 32, 62, 33)))
		std::cout << "\n\nfile to load PlayerMainSprite.png check if it exists :)\n\n" << system("dir");
	playerSprite.setTexture(texture[0]);
	playerSprite.setOrigin(playerSprite.getTextureRect().width / 2, playerSprite.getTextureRect().height / 2);
	playerSprite.setPosition(700, 700);

}

void Player::walkingAnimation(float speed)
{
	animTime += Utility::deltaTime();
	if (speed > 0 && animTime > 0.1f)
	{
		animTime = 0;
		playerSprite.setTexture(texture[textureIndex++]);
		if (textureIndex > 3) textureIndex = 0;
	}
}

void Player::rotateTo(float angle)
{
	float currentAngle = playerSprite.getRotation();
	if (angle < 0) angle += 360;
	float delta = angle - currentAngle;
	if (delta < -180) delta = (360 - currentAngle + angle);
	if (delta > 180) delta = (-currentAngle - (360 - angle));

	playerSprite.setRotation(playerSprite.getRotation() + delta * Utility::deltaTime() * ROTATIONAL_SPEED);
}



void Player::takeDamage(float damage)
{


}

void Player::attack()
{
	currentWepon->attack();
}

void Player::ChangeWeapon(int hotBarIndex)
{
	if (currentWepon != nullptr)
	{
		currentWepon->enabled = false;
	}
	int value = playerInventory.peek(hotBarIndex - 1);

	if (value == _Pistol)
	{
		currentWepon = pistol;
		currentWepon->enabled = true;
	}
	else if (value == _Ak47) {
		currentWepon = ak;
		currentWepon->enabled = true;
	}
	else if (value == _Sniper) {
		currentWepon = sniper;
		currentWepon->enabled = true;
	}

}
