#include <iostream>
#include <SFML/Graphics.hpp>
#include "SankeHead.h"
#include "SnakeBody.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(500, 500), "snake");
	sf::Event event;
	
	SnakeHead snake_head;
	SnakeBody body(&snake_head);
	snake_head.attach_body(&body);
	for (int i = 0; i < 50; i++)
		body.addCell();

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
		snake_head.map_diretion();
		if (clock.getElapsedTime().asSeconds() >= UpdateDelta.asSeconds())
		{
			snake_head.Update();
			clock.restart();
		}
		win.clear();
		win.draw(snake_head);
		win.draw(body);
		win.display();

	}
	return 0;
}