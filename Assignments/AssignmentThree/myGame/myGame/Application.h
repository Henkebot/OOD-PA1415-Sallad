#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"
#include "Menu.h"
#include <iostream>

class Application : public sf::Drawable
{
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
public:
	Application();
	virtual ~Application();
private:
	void run();
	void update(float dt);

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::RenderWindow window;
	GameStateManager* gsm;
};
#endif