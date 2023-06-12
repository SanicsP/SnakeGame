#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Cell.h"


class SnakeHead;
class Cell;
class Score;

class Fruit : public Cell {

public:
	Fruit();
	void Update() override;
	void Replace();
	bool colidWithHead() const;
	void attachHead(SnakeHead* head);
	void attchScreen(sf::VideoMode* screen);
	void attachScore(Score* score);
private:
	sf::Sprite m_sprite;
	std::unique_ptr<SnakeHead> mp_head;
	sf::VideoMode* mp_screen_size;
	std::unique_ptr<Score> mp_score;
};