#include "Game.h"

Game::Game(GameStateManager * gsm) :
	State(gsm)
{
	std::cout << "Game State pushed!\n";
	this->shape.setSize(sf::Vector2f(200, 200));
	this->shape.setFillColor(sf::Color(255, 100, 55));
	this->wasAPressed = false;
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
	this->handleEvents();

}

void Game::handleEvents()
{
	bool isReturnPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	if (isReturnPressed && !this->wasAPressed)
	{
		std::cout << "A pressed" << std::endl;
		this->gsm->popState();
	}
	this->wasAPressed = isReturnPressed;
}

Game & Game::operator=(const Game & other)
{
	if (this != &other)
	{
		State::operator=(other);
		//more stuff
	}

	return *this;

}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->shape, states);
}