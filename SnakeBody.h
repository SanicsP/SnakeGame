#pragma once


#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class SnakeHead;
class Cell;

class SnakeBody : public sf::Drawable {
public :
	SnakeBody(SnakeHead* head);
	void update();
	void addCell();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setLastPos(sf::Vector2i last_pos);
	void reset();
private : 
	std::unique_ptr<SnakeHead> mp_head;
	std::vector<Cell> m_cells;
	sf::Vector2i m_head_last_pos;
	
private:
	void replace_all_cells();
	bool head_in_cell();
};