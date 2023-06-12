#include "SnakeBody.h"
#include "Cell.h"
#include "SankeHead.h"
#include <iostream>

SnakeBody::SnakeBody(SnakeHead* head) : mp_head(head)
{

}

void SnakeBody::update()
{
	if (head_in_cell())
	{
		mp_head->kill();
	}

	m_head_last_pos = mp_head->getPos();
	replace_all_cells();

}

void SnakeBody::addCell()
{
	m_cells.push_back(Cell());
	m_cells.back().setColor(sf::Color::Blue);

}

void SnakeBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < m_cells.size(); i++)
		target.draw(m_cells[i]);
}

void SnakeBody::setLastPos(sf::Vector2i last_pos)
{
	m_head_last_pos = last_pos;
}

void SnakeBody::reset()
{
	m_cells.clear();
	m_cells.push_back(Cell());
}

void SnakeBody::replace_all_cells()
{
	sf::Vector2i ghostPos;
	sf::Vector2i tempPos;

	tempPos = m_cells[0].getPos();
	
	m_cells[0].setPosition(m_head_last_pos);
	
	ghostPos = tempPos;
	
	m_cells[0].map_grid();
	
	//std::cout << "body pos : " << m_cells[0].getPos().x << " " << m_cells[0].getPos().y << std::endl;

	for (int i = 1; i < m_cells.size(); i++)
	{

		tempPos = m_cells[i].getPos();
		
		m_cells[i].setPosition(ghostPos);
		
		m_cells[i].map_grid();
		
		ghostPos = tempPos;
		//std::cout << "cell n"<<i<<" pos " << m_cells[i].getPos().x << " " << m_cells[i].getPos().y << std::endl;
		//std::cout << "cell n" << i-1 << " pos " << m_cells[i-1].getPos().x << " " << m_cells[i-1].getPos().y << std::endl;

	}

}

bool SnakeBody::head_in_cell()
{
	for (int i = 0; i < m_cells.size(); i++)
		if (mp_head->getPos() == m_cells[i].getPos())
			return true;
	return false;
}
