#include "Score.h"

Score::Score(sf::Font* font) : mp_font(font)
{
	m_score_txt.setFont(*mp_font);
	m_score_txt.setString(sf::String("SCORE : "));
}

void Score::update()
{

}

void Score::addScore(int mount)
{
	m_score += mount;
	m_score_txt.setString(sf::String("SCORE : " + std::to_string(m_score)));

}

void Score::removeScore(int mount)
{
	m_score -= mount;
	m_score_txt.setString(sf::String("SCORE : " + std::to_string(m_score)));

}

void Score::resetScore()
{
	m_score = 0;
	m_score_txt.setString(sf::String("SCORE : " + std::to_string(m_score)));
}

void Score::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_score_txt);
}
