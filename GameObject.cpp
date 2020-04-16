#include "GameObject.h"

GameObject::GameObject()
{
	GameObjects.push_back(this);
}

void GameObject::Update(sf::RenderWindow& window)
{

}

GameObject::~GameObject()
{
	//find self
	std::vector<GameObject*>::iterator it = GameObjects.begin();
	while (it != GameObjects.end())
	{
		if (*it == this)
			GameObjects.erase(it);
		it++;
	}

}
std::vector<GameObject*> GameObject::GameObjects;
