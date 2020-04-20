#include "Utilitys.h"

const float Utility::Rad2Deg = 57.2958f;
const float Utility::Deg2Rad = 0.0174533f;
Utility Utility::instance;


double Utility::deltaTime()
{
	return instance.clk.getElapsedTime().asMicroseconds() / (double)1000000;
}

void Utility::Update(sf::RenderWindow& window)
{
	clk.restart();
}