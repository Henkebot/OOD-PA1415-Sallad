#ifndef PAUSE_H
#define PAUSE_H
#include "State.h"
#include "GameStateManager.h"
#include "Application.h"

class Pause : public State
{
public:
	Pause(GameStateManager * gsm);
	virtual ~Pause();

	void update(float dt);
	void handleEvents();

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void initiateText();
private:
	sf::Texture tBg;
	sf::Sprite sBg;

	sf::Text pause;
	sf::Text goToGame;
	sf::Text goToMenu;
	sf::Font aFont;
};



#endif // !PAUSE_H
