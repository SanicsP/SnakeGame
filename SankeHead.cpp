#include "SankeHead.h"
#include "SnakeBody.h"
#include <iostream>

SnakeHead::SnakeHead() : mp_body(nullptr), m_is_dead(false)
{
	setPosition(sf::Vector2i(1, 20));
}

void SnakeHead::Update()
{
	if (m_is_dead)
	{
		setColor(sf::Color::Green);
	}
	mp_body->setLastPos(m_pos);
	//std::cout << " before : \nposX : " << m_pos.x << " posY : " << m_pos.y << std::endl;

	mp_body->update();
	move(m_current_dir);
	
	grid_move();
	
	//std::cout << "after : \nposX : " << m_pos.x << " posY : " << m_pos.y << std::endl;

}

void SnakeHead::move(direction dir)
{
	switch (dir)
	{
		case direction::UP:
			m_pos.y -= 1;
			break;
		case direction::DOWN:
			m_pos.y += 1;
			break;
		case direction::RIGHT:
			m_pos.x += 1;
			break;
		case direction::LEFT:
			m_pos.x -= 1;
			break;
	}
}

void SnakeHead::grid_move()
{
	m_rectangle.setPosition(sf::Vector2f(m_pos.x * Entity::POS_DIV, m_pos.y * Entity::POS_DIV));
}

void SnakeHead::map_diretion()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_current_dir = direction::UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_current_dir = direction::DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_current_dir = direction::RIGHT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_current_dir = direction::LEFT;
}

void SnakeHead::attach_body(SnakeBody* body)
{
	mp_body.reset(body);
}

void SnakeHead::kill()
{
	m_is_dead = true;
}

bool SnakeHead::isDead() const
{
	return m_is_dead;
}
