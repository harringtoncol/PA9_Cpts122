#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class GameObject {
public:
	GameObject(int renderLayer);
	GameObject();
	sf::Vector2f position;
	virtual void Update(sf::RenderWindow& window);
	static std::vector<GameObject*> GameObjects;
	std::string name;
	~GameObject();
	int renderLayer;
protected:
	
private:
	bool sortLayers(const GameObject& l, const GameObject& r);
};
