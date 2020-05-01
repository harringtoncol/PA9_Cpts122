#include "Ghosts.h"

Ghosts::Ghosts() : GameObject(sf::Vector2f(0,0)){

	ghostObj.setOrigin(10, 10);
	ghostPos = ghostObj.getPosition();
	clk.restart();
}

int Ghosts::update(sf::Vector2f p1, sf::Vector2f p2) {
	p1Pos = p1;
	p2Pos = p2;
	time = clk.getElapsedTime();
	float time = clk.getElapsedTime().asSeconds();
	speed = log(time) + 1;
	move();
return	hitPlayer();
}

void Ghosts::move() {

	float i = ghostPos.y - p1Pos.y;
	float y = ghostPos.x - p1Pos.x;
	float z = sqrt(i * i + y * y);
	float j = ghostPos.y - p2Pos.y;
	float  k = ghostPos.x - p2Pos.x;
	float b = sqrt(j * j + k * k);
	
	sf::Vector2f playerPos;
	if (z > b) 
		playerPos = p2Pos;
	else
		playerPos = p1Pos;


	bool moved = false;
	
	if (playerPos.x > ghostPos.x && playerPos.y > ghostPos.y) {

		
		
		ghostObj.setPosition(ghostPos.x + (speed / 2), ghostPos.y + (speed / 2));
			moved = true;
			
			
	}
	//If SE
	else if (playerPos.x < ghostPos.x && playerPos.y > ghostPos.y) {

		
	
		ghostObj.setPosition(ghostPos.x - (speed / 2), ghostPos.y + (speed / 2));
			moved = true;
		
		
	}
	//If SW
	else if (playerPos.x < ghostPos.x && playerPos.y < ghostPos.y) {
		
			

		
			ghostObj.setPosition(ghostPos.x - (speed / 2), ghostPos.y - (speed / 2));
				moved = true;
	
	}
	//If NW
	else if (playerPos.x > ghostPos.x && playerPos.y < ghostPos.y) {

		
	
		ghostObj.setPosition(ghostPos.x + (speed / 2), ghostPos.y - (speed / 2));
		
			moved = true;
	
	}

	//If E
	if (playerPos.x  > ghostPos.x && !moved) {

	
		ghostObj.setPosition(ghostPos.x + speed, ghostPos.y);
			moved = true;
			

	}
	//If W
	if (playerPos.x  < ghostPos.x && !moved) {

		ghostObj.setPosition(ghostPos.x - speed, ghostPos.y);
			moved = true;

	}
	//If N
	if (playerPos.y  < ghostPos.y && !moved) {


		ghostObj.setPosition(ghostPos.x, ghostPos.y - speed);
			moved = true;

	}
	//If S
	if (playerPos.y  > ghostPos.y && !moved) {

			ghostObj.setPosition(ghostPos.x, ghostPos.y + speed);
			moved = true;
	


	}
	ghostPos = ghostObj.getPosition();
	//std::cout << " Position is:  " << ghostPos.x << "  " << ghostPos.y << std::endl;
	pos = ghostObj.getPosition();



}


int Ghosts::hitPlayer() {
//first checking the first player
	//if (ghostObj.getPosition().x + 10 > p1Pos.x && ghostObj.getPosition().y + 10 > p1Pos.y)
		//return 1;
	if (ghostObj.getPosition().x == p1Pos.x && ghostObj.getPosition().y == p1Pos.y) {
		std::cout << ghostObj.getPosition().x << "   " << p1Pos.x << "    " << ghostObj.getPosition().y << p1Pos.y << std::endl;
		return 1;
	
	}
	//second checking the second player
	if (ghostObj.getPosition().x == p2Pos.x && ghostObj.getPosition().y == p2Pos.y)
		return 2;


	return 0;
}