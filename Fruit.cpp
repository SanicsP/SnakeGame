#include "Fruit.h"
#include "Entity.h"
#include "SankeHead.h"
#include "SnakeBody.h"
#include <random>
#include <chrono>
#include <iostream>

Fruit::Fruit() : Cell() , mp_screen_size(nullptr)
{
	m_rectangle.setFillColor(sf::Color::White);
}

void Fruit::Update()
{
	if (colidWithHead())
	{
		std::cout << "colide" << std::endl;
		Replace();
		mp_head->getBody()->addCell();

		std::cout << "new position " << m_pos.x << " " << m_pos.y << std::endl;
	}
}

void Fruit::Replace()
{
	std::mt19937 rand_engine{ (unsigned int)std::chrono::system_clock::now().time_since_epoch().count() };
	std::uniform_int_distribution<unsigned int> xDist{ 0 , (mp_screen_size->width / Entity::POS_DIV) - 1};
	std::uniform_int_distribution<unsigned int> yDist{ 0 , (mp_screen_size->height /Entity::POS_DIV) - 1};

	setPosition(sf::Vector2i(xDist(rand_engine) , yDist(rand_engine)));
	map_grid();
}

bool Fruit::colidWithHead() const
{
	return m_pos == mp_head->getPos();
}

void Fruit::attachHead(SnakeHead* head)
{
	mp_head.reset(head);
}

void Fruit::attchScreen(sf::VideoMode* screen)
{
	mp_screen_size = screen;
}
