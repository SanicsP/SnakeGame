#pragma once
#include "Entity.h"
#include "Cell.h"
#include "direction.h"
#include <memory>

class SnakeBody;

class SnakeHead : public Cell {

public :
	SnakeHead();
	void Update() override;
	void map_diretion();
	void attach_body(SnakeBody* body);
	void kill();
	bool isDead() const;
private : 
	direction m_current_dir;
	std::unique_ptr<SnakeBody> mp_body;
	bool m_is_dead;
private:
	void move(direction dir);
	void grid_move();
	
};