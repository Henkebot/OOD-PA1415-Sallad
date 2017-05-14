#include "GameStateManager.h"
GameStateManager::GameStateManager()
{
	
}

GameStateManager::GameStateManager(const GameStateManager & other)
{
	this->states = other.states;
}

GameStateManager::~GameStateManager()
{
	while (!this->states.isEmpty())
	{
		this->popState();
	}
}

bool GameStateManager::emptyStack() const
{
	return this->states.isEmpty();
}

void GameStateManager::changeState(State * state)
{
	delete this->states.pop();
	this->states.push(state);
}

void GameStateManager::pushState(State * state)
{
	this->states.push(state);
}

void GameStateManager::popState(int amount)
{
	for (int i = 0; i < amount && !this->states.isEmpty(); i++)
		delete this->states.pop();
}

void GameStateManager::update(float dt)
{
	if (!this->states.isEmpty())
		this->states.peek()->update(dt);
}

GameStateManager & GameStateManager::operator=(const GameStateManager & other)
{
	if (this != &other)
	{
		this->states = other.states;
	}
	return *this;
}

void GameStateManager::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (!this->states.isEmpty())
		target.draw(*this->states.peek(), states);
}
