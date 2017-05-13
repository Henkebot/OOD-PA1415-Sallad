#include <SFML/Graphics.hpp>
#include <iostream>
FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
int main()
{
	sf::Texture lol;
	/*if (!lol.loadFromFile(".\\textures\\ground2.png"))
	{
		std::cout << "Failed to load menu texture!" << std::endl;
	}*/
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}