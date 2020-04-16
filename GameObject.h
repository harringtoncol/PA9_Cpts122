#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class GameObject {
public:
	GameObject();
	virtual void Update(sf::RenderWindow& window);
	static std::vector<GameObject*> GameObjects;
	~GameObject();
protected:

private:

};
