#include "Cell.h"

Cell::Cell()
{
	m_rectangle = sf::RectangleShape(sf::Vector2f(Entity::POS_DIV, Entity::POS_DIV));
	m_rectangle.setFillColor(sf::Color::Red);
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle);
}

void Cell::Update()
{
}

void Cell::map_grid()
{
	m_rectangle.setPosition(sf::Vector2f(m_pos.x * Entity::POS_DIV, m_pos.y * Entity::POS_DIV));
}

void Cell::setColor(const sf::Color& color)
{
	m_rectangle.setFillColor(color);
}
