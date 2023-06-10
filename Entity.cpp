#include "Entity.h"

sf::Vector2i Entity::getPos()
{
	return m_pos;
}

void Entity::setPosition(sf::Vector2i pos)
{
	m_pos = pos;
}
