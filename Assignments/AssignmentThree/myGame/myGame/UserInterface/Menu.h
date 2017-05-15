#ifndef MENU_H
#define MENU_H
#include "State.h"
#include <iostream>
#include "EnterFeed.h"
#include "Application.h"

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
	void initiateVars();
private:
	void initiateText();

	float timeCollector;
private:
	sf::Texture texture;
	sf::Sprite wallpaper;

	float alpha;

	sf::Font aFont;
	sf::Text startGame;
	sf::Text endGame;
	sf::Text nethack;
};

#endif