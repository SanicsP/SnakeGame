#include <iostream>
#include <SFML/Graphics.hpp>
#include "SankeHead.h"
#include "SnakeBody.h"
#include "Fruit.h"
#include "border.h"

int main()
{
	sf::VideoMode screen_size(500, 500);
	sf::RenderWindow win(screen_size, "snake");
	sf::Event event;
	
	SnakeHead snake_head;
	SnakeBody body(&snake_head);
	snake_head.attach_body(&body);
	
	
	Fruit fruit;
	fruit.attachHead(&snake_head);
	fruit.attchScreen(&screen_size);
	fruit.Replace();
	
	Border background(&snake_head, &screen_size);

	for (int i = 0; i < 2; i++)
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
		background.Wrrap();
		if (clock.getElapsedTime().asSeconds() >= UpdateDelta.asSeconds())
		{
			snake_head.Update();
			fruit.Update();
			clock.restart();
		}
		win.clear();
		win.draw(snake_head);
		win.draw(body);
		win.draw(fruit);
		win.display();

	}
	return 0;
}