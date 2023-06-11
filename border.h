#pragma once

#include <memory>
#include "SankeHead.h"
#include <SFML/Graphics.hpp>

class Border {
public :
	Border(SnakeHead* head, sf::VideoMode* videoMode);
	void Wrrap();
	bool isOutOfBound() const;
private :
	SnakeHead* mp_head;
	sf::VideoMode* mp_screen_size;
};