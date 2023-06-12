#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Fruit.h"

class Score : public sf::Drawable{
public : 
	Score(sf::Font* font);
	void update();

	void addScore(int mount);
	void removeScore(int mount);
	void resetScore();
	
	void draw(sf::RenderTarget& target , sf::RenderStates states) const override;

private:
	int m_score;
	sf::Text m_score_txt;
	std::unique_ptr<sf::Font> mp_font;
};