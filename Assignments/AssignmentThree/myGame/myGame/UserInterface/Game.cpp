#include "Game.h"

Game::Game(GameStateManager * gsm, std::string user) :
	State(gsm)
{
	std::cout << "Game State pushed!\n";
	this->map.createMap(user);


}

Game::Game(const Game & other) :
	State(other)
{

}

Game::~Game()
{
	
}

void Game::update(float dt)
{
	this->map.update(dt);

	this->handleEvents();

}

void Game::handleEvents()
{
	if (InputManager::keyPressed(sf::Keyboard::Escape))
	{
		sf::Image gameScreen;
		
		this->gsm->pushState(new Pause(this->gsm));
		std::cout << "Pause pushed\n";
	}

}

Game & Game::operator=(const Game & other)
{
	if (this != &other)
	{
		State::operator=(other);

	}

	return *this;

}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	this->map.render(target);

}