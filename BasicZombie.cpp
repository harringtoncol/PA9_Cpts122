#include "BasicZombie.h"
#include "Player.h"

BasicZombie::BasicZombie() : GameObject(){
	texture.loadFromFile("ZombieTop.png", sf::IntRect(0, 0, 200, 200));
	name = "mob";
	zombieObj.setTexture(texture);
	int x = rand() % 600 + 1;
	int y = rand() % 600 + 1;
	//zombieObj.setOrigin(100, 100);
	zombieObj.setPosition(x, y);
	position = zombieObj.getPosition();
}



void BasicZombie::Update(sf::RenderWindow& window) {

	move();
	window.draw(zombieObj);
}

void BasicZombie::move() {
	bool cont = true;
	sf::Vector2f zombiePos = zombieObj.getPosition();
	printf("Zombie %lf  %lf\n\n\n", zombiePos.x, zombiePos.y);
	sf::Vector2f playerPos = GameObjects[GameObject::GameObjects.size()-3]->position;
	printf("Player %lf %lf\n\n\n\n", playerPos.x, playerPos.y);

	bool moved = false;
	//If NE
	if (playerPos.x > zombiePos.x && playerPos.y > zombiePos.y) {
		
		for (int i = 0; i < GameObjects.size(); i++) {
			
			std::cout << "Object" <<  GameObjects[i]->position.x<< "    " << GameObjects[i]->position.y << std::endl;
			if (GameObjects[i]->name == "mob")
			if (  (   ( (((zombiePos.x + speed / 2) < GameObjects[i]->position.x) && (zombiePos.x + speed / 2) > ((int)GameObjects[i]->position.x - 100)) && ((zombiePos.y + speed / 2) < GameObjects[i]->position.y) && (zombiePos.y + speed / 2) > ((int)GameObjects[i]->position.y - 100)) ) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {
				cont = false;
			}
		}
			if (cont) {
				zombieObj.setPosition(zombiePos.x + (speed / 2), zombiePos.y + (speed / 2));
				moved = true;
			}
		}
	//If SE
	else if (playerPos.x < zombiePos.x && playerPos.y > zombiePos.y) {
		
		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
			if (  (   ( (((zombiePos.x + speed / 2) < GameObjects[i]->position.x) && (zombiePos.x + speed / 2) > ((int)GameObjects[i]->position.x - 100)) && ((zombiePos.y + speed / 2) > GameObjects[i]->position.y) && (zombiePos.y + speed / 2) < ((int)GameObjects[i]->position.y - 100)) ) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {
			
				cont = false;
			}
		}
			if (cont) {
				zombieObj.setPosition(zombiePos.x - (speed / 2), zombiePos.y + (speed / 2));
				moved = true;
			}
		}
	//If SW
	else if (playerPos.x < zombiePos.x && playerPos.y < zombiePos.y) {
		for (int i = 0; i < GameObjects.size(); i++) {
			printf("%lf, %lf\n", GameObjects[i]->position.x, GameObjects[i]->position.y);
			if (GameObjects[i]->name == "mob")
			if ((((((zombiePos.x - speed / 2) > GameObjects[i]->position.x) && (zombiePos.x + speed / 2) < ((int)GameObjects[i]->position.x + 100)) && ((zombiePos.y - speed / 2) > GameObjects[i]->position.y) && (zombiePos.y + speed / 2) < ((int)GameObjects[i]->position.y + 100))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {
			
				cont = false;
			}
		}
			if (cont) {
				zombieObj.setPosition(zombiePos.x - (speed / 2), zombiePos.y - (speed / 2));
				moved = true;
			}
		}
	//If NW
	else if (playerPos.x > zombiePos.x && playerPos.y < zombiePos.y) {
	
	for (int i = 0; i < GameObjects.size(); i++) {
		if (GameObjects[i]->name == "mob")
		if ((((((zombiePos.x + speed / 2) < GameObjects[i]->position.x) && (zombiePos.x + speed / 2) > ((int)GameObjects[i]->position.x +100)) && ((zombiePos.y - speed / 2) < GameObjects[i]->position.y) && (zombiePos.y + speed / 2) > ((int)GameObjects[i]->position.y + 100))) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y))) {
			cont = false;
		}
	}
			if (cont) {
				zombieObj.setPosition(zombiePos.x + (speed / 2), zombiePos.y - (speed / 2));
			}
		}
	cont = true;
	//If E
    if (playerPos.x+100 > zombiePos.x && !moved){
		
		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
			if ((((zombiePos.x + speed) < GameObjects[i]->position.x) && (zombiePos.x + speed) > ((int)GameObjects[i]->position.x + 100)) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
				cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x + speed, zombiePos.y);
			
		}
	}
	//If W
	 if (playerPos.x-100 < zombiePos.x && !moved) {
		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
			if ((((zombiePos.x - speed / 2) > GameObjects[i]->position.x) && (zombiePos.x + speed / 2) < ((int)GameObjects[i]->position.x + 100)) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
				cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x - speed, zombiePos.y);
			
		}
	}
	//If N
	if (playerPos.y-100 < zombiePos.y && !moved) {

		for (int i = 0; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
			if (((((zombiePos.y - speed) < GameObjects[i]->position.y) && (zombiePos.y - speed) > ((int)GameObjects[i]->position.y + 100)) ) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
				cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x, zombiePos.y - speed);
			
		}
	}
	//If S
	if (playerPos.y+100 > zombiePos.y && !moved) {

		for (int i = 2; i < GameObjects.size(); i++) {
			if (GameObjects[i]->name == "mob")
			if (((((zombiePos.y + speed) > GameObjects[i]->position.y) && (zombiePos.y + speed) < ((int)GameObjects[i]->position.y - 100)) ) && (!(zombiePos.x == GameObjects[i]->position.x && zombiePos.y == GameObjects[i]->position.y)))
				cont = false;
		}
		if (cont) {
			zombieObj.setPosition(zombiePos.x, zombiePos.y+ speed);
			
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
		for (; i < GameObjects.size()-1; j++) {
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