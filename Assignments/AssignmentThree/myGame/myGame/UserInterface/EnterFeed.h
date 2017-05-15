#ifndef ENTERFEED_H
#define ENTERFEED_H
#include "State.h"
#include <iostream>
#include "Game.h"

class EnterFeed : public State
{
public:
	EnterFeed(GameStateManager* gsm = nullptr);
	virtual ~EnterFeed();

	void update(float dt);
	void handleEvents();
private:
	void initiateVars();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	sf::Texture texture;
	sf::Sprite wallpaper;

	sf::Font aFont;
	sf::String input;


	sf::Text enterFeed;
	sf::Text aFeed;
	sf::Text goBack;

};

#endif