#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Cell : public Entity  , public sf::Drawable{

public :
	Cell();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update();
	void map_grid();
	void setColor(const sf::Color& color);
protected : 
	sf::RectangleShape m_rectangle;
};