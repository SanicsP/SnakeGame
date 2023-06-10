#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	const static int POS_DIV = 20;
	virtual void Update() = 0;
	sf::Vector2i getPos();
	void setPosition(sf::Vector2i pos);
protected : 
	sf::Vector2i m_pos;
};