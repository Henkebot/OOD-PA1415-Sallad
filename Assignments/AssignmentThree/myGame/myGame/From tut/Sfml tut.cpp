#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 700), "sfml works!", sf::Style::Titlebar | sf::Style::Close);
	sf::Clock gameTime;
	Game game;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		game.update(gameTime.restart().asSeconds());

		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}