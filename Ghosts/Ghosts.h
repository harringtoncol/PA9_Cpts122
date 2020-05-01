#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "gameObject.h"
#include "player.h"

class Ghosts : public GameObject {
private:
	sf::Sprite ghostObj; //the sprite of the ghost object that we will mvoe around in the executable
	sf::Vector2f p1Pos; //The position that we currently have of player 1
	sf::Vector2f p2Pos;// The position that we currently have of player 2
	sf::Vector2f ghostPos;//The postiion of the ghost this si updated every time we move
	sf::Clock clk;//this is the clk object that we can use to find the seconds that we use to update the speed.
	sf::Time time;//TIme is another object that we use to get the seconds from the clk.
	float speed = 1;//This is the base speed. It slowly changes based on how much time has elapsed in the game.
	public:
		Ghosts(); //Constructor of Ghosts
		int update(sf::Vector2f, sf::Vector2f); // update function that calls move and hit player.
		void move(); //Decides which player is closer and moves them towards that player based on speed
		int hitPlayer(); // decides if the the ghost is on top of the player if so returns integer 1 if player1 2 if player2 zero if doesnt hit. 
};
