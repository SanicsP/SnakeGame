#include "border.h"
#include "Entity.h"

Border::Border(SnakeHead* head, sf::VideoMode* videoMode) : mp_head(head) , mp_screen_size(videoMode)
{
}

void Border::Wrrap()
{
	if (isOutOfBound())
	{
		mp_head->kill();
	}
}

bool Border::isOutOfBound() const
{
	return (
		mp_head->getPos().x >= (mp_screen_size->width / Entity::POS_DIV) || 
		mp_head->getPos().x < 0 || 
		mp_head->getPos().y >= (mp_screen_size->height / Entity::POS_DIV) ||
		mp_head->getPos().y < 0
		);
}
