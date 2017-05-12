#include "Pause.h"

Pause::Pause(GameStateManager * gsm):
	State(gsm)
{
	std::cout << "Pause pushed!\n";
	if (!this->aFont.loadFromFile("font/D3Stonism.ttf"))
	{
		std::cout << "No font... .|.." << std::endl;
	}

	this->pause.setFont(aFont);
	this->pause.setString("PAUSE");
	this->pause.setCharacterSize(128);
	this->pause.setPosition(sf::Vector2f(Application::SCREEN_WIDTH / 2 - 128 * 1.5, Application::SCREEN_HEIGHT / 2));

}

Pause::~Pause()
{
}

void Pause::update(float dt)
{
	this->handleEvents();
}

void Pause::handleEvents()
{
	if (InputManager::keyPressed(sf::Keyboard::Escape))
	{
		this->gsm->popState();
	}
	else if (InputManager::keyPressed(sf::Keyboard::Return))
	{
		this->gsm->popState(2);
	}
}

void Pause::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->pause);
}
