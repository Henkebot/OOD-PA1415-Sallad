#include "Game.hpp"

Game::Game()
{
	if (!this->tBackground.loadFromFile("../textures/space.png"))
	{
		//Handle error!
	}
	this->sBackground.setTexture(this->tBackground);
	
}

void Game::update(float dt)
{
	mPlayer.update(dt);
}
void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(this->sBackground, states);
	target.draw(mPlayer);
}
