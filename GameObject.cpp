#include "GameObject.h"

GameObject::GameObject(int renderLayer = 0)
{
	this->renderLayer = renderLayer;
	GameObjects.push_back(this);
	std::sort(GameObjects.begin(), GameObjects.end(), [](const GameObject* lhs, const GameObject* rhs) {
		return lhs->renderLayer < rhs->renderLayer;
		});
}

GameObject::GameObject()
{
	this->renderLayer = 0;
	GameObjects.push_back(this);
	std::sort(GameObjects.begin(), GameObjects.end(), [](const GameObject* lhs, const GameObject* rhs) {
		return lhs->renderLayer < rhs->renderLayer;
		});
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
		{
			it = GameObjects.erase(it);
		}
		else
		{
			it++;
		}
	}

}
bool GameObject::sortLayers(const GameObject& l,const GameObject& r)
{
	return l.renderLayer < r.renderLayer;
}
std::vector<GameObject*> GameObject::GameObjects;
