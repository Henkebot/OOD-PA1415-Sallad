#include "Pause.h"

Pause::Pause(GameStateManager * gsm):
	State(gsm)
{
	std::cout << "Pause pushed!\n";
	if (!this->tBg.loadFromFile("textures/pause_wallpaper.jpg"))
	{
		std::cout << "Could not load bg\n";
	}
	this->sBg.setTexture(this->tBg);
	this->initiateText();
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
	else if (InputManager::keyPressed(sf::Keyboard::Home))
	{
		this->gsm->popState(2);
	}
}

void Pause::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sBg);
	target.draw(this->pause);
	target.draw(this->goToGame);
	target.draw(this->goToMenu);
}

void Pause::initiateText()
{
	if (!this->aFont.loadFromFile("font/D3Stonism.ttf"))
	{
		std::cout << "No font... .|.." << std::endl;
	}

	this->pause.setFont(aFont);
	this->goToGame.setFont(aFont);
	this->goToMenu.setFont(aFont);

	this->pause.setString("PAUSE");
	this->goToGame.setString("Press ESC to continue");
	this->goToMenu.setString("Press HOME to exit");

	this->pause.setCharacterSize(128);
	this->goToGame.setCharacterSize(32);
	this->goToMenu.setCharacterSize(16);

	this->pause.setPosition(sf::Vector2f(static_cast<float>(Application::SCREEN_WIDTH) / 2 - 128 * 2, static_cast<float>(Application::SCREEN_HEIGHT) / 2 - 128));
	this->goToGame.setPosition(sf::Vector2f(static_cast<float>(Application::SCREEN_WIDTH) / 2 - (15 * 32) / 2, static_cast<float>(Application::SCREEN_HEIGHT) / 2 + 120));
	this->goToMenu.setPosition(sf::Vector2f(static_cast<float>(Application::SCREEN_WIDTH) / 2 - (15 * 16) / 2, static_cast<float>(Application::SCREEN_HEIGHT) / 2 + 250));
}
