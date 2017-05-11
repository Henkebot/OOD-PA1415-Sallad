#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"
#include "../Utility/InputManager.h"

class GameStateManager;
class State : public sf::Drawable
{
public:
	State(GameStateManager* gsm);
	State(const State & other);
	virtual ~State() {}; // The gsm shall not be deleted. It will get deleted in the application class

	virtual void update(float dt) = 0;
	virtual void handleEvents() = 0;
	virtual State& operator=(const State& other);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

protected:
	GameStateManager* gsm;

};


#endif // !STATE_H
