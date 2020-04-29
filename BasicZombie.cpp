#include "BasicZombie.h"


BasicZombie::BasicZombie(Player* p) : GameObject() {
	pp = p;
	name = "mob";
	textureN.loadFromFile("ZombieTopN.png", sf::IntRect(0, 0, 200, 200));
	textureNE.loadFromFile("ZombieTopNE.png", sf::IntRect(0, 0, 200, 200));
	textureSE.loadFromFile("ZombieTopSE.png", sf::IntRect(0, 0, 200, 200));
	textureSW.loadFromFile("ZombieTopSW.png", sf::IntRect(0, 0, 200, 200));
	textureNW.loadFromFile("ZombieTopNW.png", sf::IntRect(0, 0, 200, 200));
	textureE.loadFromFile("ZombieTopE.png", sf::IntRect(0, 0, 200, 200));
	textureW.loadFromFile("ZombieTopW.png", sf::IntRect(0, 0, 200, 200));
	textureS.loadFromFile("ZombieTopS.png", sf::IntRect(0, 0, 200, 200));
	textureAttack.loadFromFile("ZombieAttack.png", sf::IntRect(0, 0, 200, 200));
	texture = &textureN;
	zombieObj.setTexture(*texture);
	int x = rand() % 600 + 1;
	int y = rand() % 600 + 1;
	//zombieObj.setOrigin(100, 100);
	zombieObj.setPosition(x, y);
	position = zombieObj.getPosition();
	index = 0;
}



void BasicZombie::Update(sf::RenderWindow& window) {
	index++;
	if (index == 5) {
		move();
		index = 0;
		tryAttack();
	}
	window.draw(zombieObj);
}

void BasicZombie::move() {
	bool cont = true;
	sf::Vector2f zombiePos = zombieObj.getPosition();
	printf("Zombie %lf  %lf\n\n\n", zombiePos.x, zombiePos.y);
	sf::Vector2f playerPos = pp->position;
	printf("Player %lf %lf\n\n\n\n", playerPos.x, playerPos.y);

	bool moved = false;
	//If NE
	if (playerPos.x > zombiePos.x && playerPos.y > zombiePos.y) {

		for (int i = 0; i < GameObjects.size(); i++) {

			std::cout << "Object" << GameObjects[i]->position.x << "    " << GameObjects[i]->position.y << std::endl;
			if (GameObjects[i]->name == "mob")
				if ((((((zombiePos.x + speed / 2) < GameObjects[i]->position.x) && (zombiePos.x + speed / 2) > ((int)GameObjects[i]->position.x - 40)) && ((zombiePos.y + speed / 2) < GameObjects[i]->position.y) && (zombiePos.y + speed / 2) > ((int)GameObjects[i]->position.y - 40))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {
					cont = false;
				}
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x + (speed / 2), zombiePos.y + (speed / 2));
			moved = true;
			zombieObj.setTexture(textureSE);
			direction[0] = 0;
			direction[1] = 0;
			direction[2] = 0;
			direction[3] = 1;
			direction[4] = 0;
			direction[5] = 0;
			direction[6] = 0;
			direction[7] = 0;
			//zombieObj.setRotation(zombieObj.getRotation() + 180);
		}
	}
	//If SE
	else if (playerPos.x < zombiePos.x && playerPos.y > zombiePos.y) {

		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
				if ((((((zombiePos.x + speed / 2) < GameObjects[i]->position.x) && (zombiePos.x + speed / 2) > ((int)GameObjects[i]->position.x - 40)) && ((zombiePos.y + speed / 2) > GameObjects[i]->position.y) && (zombiePos.y + speed / 2) < ((int)GameObjects[i]->position.y - 40))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {

					cont = false;
				}
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x - (speed / 2), zombiePos.y + (speed / 2));
			moved = true;
			direction[0] = 0;
			direction[1] = 0;
			direction[2] = 0;
			direction[3] = 0;
			direction[4] = 0;
			direction[5] = 0;
			direction[6] = 0;
			direction[7] = 1;
			zombieObj.setTexture(textureSW);

		}
	}
	//If SW
	else if (playerPos.x < zombiePos.x && playerPos.y < zombiePos.y) {
		for (int i = 0; i < GameObjects.size(); i++) {
			printf("%lf, %lf\n", GameObjects[i]->position.x, GameObjects[i]->position.y);
			if (GameObjects[i]->name == "mob")
				if ((((((zombiePos.x - speed / 2) > GameObjects[i]->position.x) && (zombiePos.x + speed / 2) < ((int)GameObjects[i]->position.x + 40)) && ((zombiePos.y - speed / 2) > GameObjects[i]->position.y) && (zombiePos.y + speed / 2) < ((int)GameObjects[i]->position.y + 40))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {

					cont = false;
				}

			if (cont) {
				zombieObj.setPosition(zombiePos.x - (speed / 2), zombiePos.y - (speed / 2));
				moved = true;
				direction[0] = 0;
				direction[1] = 0;
				direction[2] = 0;
				direction[3] = 0;
				direction[4] = 0;
				direction[5] = 1;
				direction[6] = 0;
				direction[7] = 0;
				zombieObj.setTexture(textureNW);
			}
		}
	}
		//If NW
	else if (playerPos.x > zombiePos.x && playerPos.y < zombiePos.y) {

		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
				if ((((((zombiePos.x + speed / 2) < GameObjects[i]->position.x) && (zombiePos.x + speed / 2) > ((int)GameObjects[i]->position.x + 40)) && ((zombiePos.y - speed / 2) < GameObjects[i]->position.y) && (zombiePos.y + speed / 2) > ((int)GameObjects[i]->position.y + 40))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {
					cont = false;
				}
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x + (speed / 2), zombiePos.y - (speed / 2));
			direction[0] = 0;
			direction[1] = 1;
			direction[2] = 0;
			direction[3] = 0;
			direction[4] = 0;
			direction[5] = 0;
			direction[6] = 0;
			direction[7] = 0;
			zombieObj.setTexture(textureNE);
			moved = true;
		}
	}
	cont = true;
	//If E
	if (playerPos.x + 100 > zombiePos.x && !moved) {

		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
				if ((((zombiePos.x + speed) < GameObjects[i]->position.x) && (zombiePos.x + speed) > ((int)GameObjects[i]->position.x + 100)) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
					cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x + speed, zombiePos.y);
			moved = true;
			zombieObj.setTexture(textureE);
			direction[0] = 0;
			direction[1] = 0;
			direction[2] = 1;
			direction[3] = 0;
			direction[4] = 0;
			direction[5] = 0;
			direction[6] = 0;
			direction[7] = 0;
		}
	}
	//If W
	if (playerPos.x - 100 < zombiePos.x && !moved) {
		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
				if ((((zombiePos.x - speed / 2) > GameObjects[i]->position.x) && (zombiePos.x + speed / 2) < ((int)GameObjects[i]->position.x + 100)) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
					cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x - speed, zombiePos.y);
			moved = true;
			zombieObj.setTexture(textureW);
			direction[0] = 0;
			direction[1] = 0;
			direction[2] = 0;
			direction[3] = 0;
			direction[4] = 0;
			direction[5] = 0;
			direction[6] = 1;
			direction[7] = 0;
		}
	}
	//If N
	if (playerPos.y - 100 < zombiePos.y && !moved) {

		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
				if (((((zombiePos.y - speed) < GameObjects[i]->position.y) && (zombiePos.y - speed) > ((int)GameObjects[i]->position.y + 100))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
					cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x, zombiePos.y - speed);
			moved = true;
			zombieObj.setTexture(textureN);
			direction[0] = 1;
			direction[1] = 0;
			direction[2] = 0;
			direction[3] = 0;
			direction[4] = 0;
			direction[5] = 0;
			direction[6] = 0;
			direction[7] = 0;
		}
	}
	//If S
	if (playerPos.y + 100 > zombiePos.y && !moved) {

		for (int i = 2; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
				if (((((zombiePos.y + speed) > GameObjects[i]->position.y) && (zombiePos.y + speed) < ((int)GameObjects[i]->position.y - 100))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
					cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x, zombiePos.y + speed);
			moved = true;
			zombieObj.setTexture(textureS);
			direction[0] = 0;
			direction[1] = 0;
			direction[2] = 0;
			direction[3] = 0;
			direction[4] = 1;
			direction[5] = 0;
			direction[6] = 0;
			direction[7] = 0;
		}

	}
	position = zombieObj.getPosition();

	}



void BasicZombie::takeDamage(double i) {
	health = health - i;

	if (health <= 0) {
		int j = 0;
		for (int i = 0; i < GameObjects.size(); i++) {
			if ((GameObjects[i]->position.x == zombieObj.getPosition().x) && (GameObjects[i])->position.y) {
				j = i;
			}
		}
		for (; i < GameObjects.size() - 1; j++) {
			GameObjects[j] = GameObjects[j + 1];
		}
	}

}

BasicZombie::~BasicZombie() {
	std::cout << "Zombie has died";


}

int BasicZombie::dealDamage() {
	return damage;
}

void BasicZombie::tryAttack() {
	//Player p = GameObjects[GameObjects.size() - 3];
	sf::Vector2f playerPos = pp->position;
	sf::Vector2f zombiePos = zombieObj.getPosition();

	if (direction[0] == 1 && zombieObj.getPosition().y - 100 < playerPos.y) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
	else if (direction[2] == 1 && zombieObj.getPosition().x + 100 > playerPos.x) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
	else if (direction[4] == 1 && zombieObj.getPosition().y + 100 > playerPos.y) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
	else if (direction[6] == 1 && zombieObj.getPosition().x - 100 < playerPos.x) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
	else if (direction[1] == 1 && ((((zombiePos.x + speed / 2) < playerPos.x) && (zombiePos.x + speed / 2) > ((int)playerPos.x + 40)) && ((zombiePos.y - speed / 2) < playerPos.y) && (zombiePos.y + speed / 2) > ((int)playerPos.y + 40))) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
	else if (direction[3] == 1 && (((zombiePos.x + speed / 2) < playerPos.x) && (zombiePos.x + speed / 2) > ((int)playerPos.x - 40)) && ((zombiePos.y + speed / 2) < playerPos.y) && (zombiePos.y + speed / 2) > ((int)playerPos.y - 40)) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
	else if (direction[5] == 1 && ((((zombiePos.x - speed / 2) > playerPos.x) && (zombiePos.x + speed / 2) < ((int)playerPos.x + 40)) && ((zombiePos.y - speed / 2) > playerPos.y) && (zombiePos.y + speed / 2) < ((int)playerPos.y + 40))) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
	else if (direction[7] == 1 && (((((zombiePos.x + speed / 2) < playerPos.x) && (zombiePos.x + speed / 2) > ((int)playerPos.x - 40)) && ((zombiePos.y + speed / 2) > playerPos.y) && (zombiePos.y + speed / 2) < ((int)playerPos.y - 40)))) {
		pp->takeDamage(20);
		zombieObj.setTexture(textureAttack);
	}
}