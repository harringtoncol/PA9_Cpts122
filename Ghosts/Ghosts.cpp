#include "Ghosts.h"
//This is the constructor initializes ghostObjs origin and position as well as the clock.
Ghosts::Ghosts() : GameObject(sf::Vector2f(0,0)){

	ghostObj.setOrigin(10, 10);
	ghostPos = ghostObj.getPosition();
	clk.restart();
}

//This is the update function, we take in two players positions and set them to a private variable in the class
//Then we increment the speed based on the amount of time in seconds thats passed (this way the ghost moves faster as the game continues)
//after speed is updated calls move which updates the ghost position, then calls hit player.
int Ghosts::update(sf::Vector2f p1, sf::Vector2f p2) {
	p1Pos = p1;
	p2Pos = p2;
	time = clk.getElapsedTime();
	float time = clk.getElapsedTime().asSeconds();
	speed = log(time) + 1;
	move();
return	hitPlayer();
}

//move uses pythagorean theorem to decide which player is closer to the ghost
//then checks whihc direction the ghost moves and hten moves the ghost
void Ghosts::move() {

	//This is pythagorean to  find the closest player
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


	bool moved = false; //so that if it moves diagonal direction does also move in a straight driection.
	//NE	
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
	ghostPos = ghostObj.getPosition();  //updates updates the classes private variable of ghost postition
	//std::cout << " Position is:  " << ghostPos.x << "  " << ghostPos.y << std::endl;
	pos = ghostObj.getPosition(); //updates teh game objects variable of the ghost possition



}


//This function tests if the ghost and the player overlap.
//if the first player and ghost match then returns a one if second player and ghost match returns a 2
//if neither of them will return a 0;
int Ghosts::hitPlayer() {
 
	
	//first checking the first player
	if (ghostObj.getPosition().x == p1Pos.x && ghostObj.getPosition().y == p1Pos.y) {
		std::cout << ghostObj.getPosition().x << "   " << p1Pos.x << "    " << ghostObj.getPosition().y << p1Pos.y << std::endl;
		return 1;
	
	}
	//second checking the second player
	if (ghostObj.getPosition().x == p2Pos.x && ghostObj.getPosition().y == p2Pos.y)
		return 2;


	return 0;
}