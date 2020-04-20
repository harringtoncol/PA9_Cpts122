#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class GameObject {
public:
	GameObject(int renderLayer);
	GameObject();

	virtual void Update(sf::RenderWindow& window);
	static std::vector<GameObject*> GameObjects;
	~GameObject();
	int renderLayer;
protected:

private:
	bool sortLayers(const GameObject& l, const GameObject& r);
};
