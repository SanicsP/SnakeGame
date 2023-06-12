#include <iostream>
#include <SFML/Graphics.hpp>
#include "SankeHead.h"
#include "SnakeBody.h"
#include "Fruit.h"
#include "border.h"
#include <memory>
#include "Score.h"

int main()
{
	sf::VideoMode screen_size(500, 500);
	sf::RenderWindow win(screen_size, "snake");
	sf::Event event;
	
	std::unique_ptr<SnakeHead> p_snake_head = std::make_unique<SnakeHead>();
	std::unique_ptr<SnakeBody> p_body = std::make_unique<SnakeBody>(p_snake_head.get());
	p_snake_head->attach_body(p_body.get());
	
	
	Fruit fruit;
	fruit.attachHead(p_snake_head.get());
	fruit.attchScreen(&screen_size);
	fruit.Replace();
	
	Border background(p_snake_head.get(), &screen_size);

	for (int i = 0; i < 2; i++)
		p_body->addCell();
	sf::Font score_font;
	
	if (!score_font.loadFromFile("res/arial.ttf"))
	{
		std::cout << "pas de font" << std::endl;
	}
	
	Score score(&score_font);
	fruit.attachScore(&score);

	sf::Clock clock;
	sf::Time UpdateDelta(sf::milliseconds(100));
	win.setFramerateLimit(60);

	while (win.isOpen())
	{
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				win.close();
			}
		}
		
		p_snake_head->map_diretion();
		
		background.Wrrap();
		fruit.Update();
		
		if (p_snake_head->isDead())
		{
			p_snake_head->getBody()->reset();
			p_snake_head->restart();
		}

		if (clock.getElapsedTime().asSeconds() >= UpdateDelta.asSeconds())
		{
			p_snake_head->Update();
			clock.restart();
		}

		win.clear();
		win.draw(*p_snake_head);
		win.draw(*p_body);
		win.draw(fruit);
		win.draw(score);
		win.display();

	}
	return 0;
}