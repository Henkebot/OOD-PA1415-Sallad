#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#include <SFML/Graphics.hpp>
//#include <stack>
#include "Stack.h"
#include "State.h"

class State;
class GameStateManager : public sf::Drawable
{
public:
	GameStateManager();
	GameStateManager(const GameStateManager & other);
	virtual ~GameStateManager();
	bool emptyStack() const;
	void changeState(State* state);
	void pushState(State* state);
	void popState(int amount = 1);
	void update(float dt);
	GameStateManager& operator=(const GameStateManager & other);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
private:
	Stack<State*> states;
};

#endif
