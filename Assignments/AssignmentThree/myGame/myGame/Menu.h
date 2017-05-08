#ifndef MENU_H
#define MENU_H
#include "State.h"
#include <iostream>
#include "Game.h"

class Menu : public State
{
public:
	Menu(GameStateManager* gsm = nullptr);
	Menu(const Menu& other);
	virtual ~Menu();

	void update(float dt);
	void handleEvents();

	Menu& operator=(const Menu& other);
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	sf::Texture texture;
	sf::Sprite wallpaper;
	sf::CircleShape shape;
};

#endif