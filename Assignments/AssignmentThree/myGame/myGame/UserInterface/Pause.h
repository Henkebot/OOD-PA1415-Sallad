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
private:
	sf::Text pause;
	sf::Font aFont;
};



#endif // !PAUSE_H
