#include "EnterFeed.h"

EnterFeed::EnterFeed(GameStateManager * gsm):
	State(gsm)
{
	std::cout << "Enter Feed state pushed!\n";
	this->initiateVars();
}

EnterFeed::~EnterFeed()
{
}

void EnterFeed::update(float dt)
{
	this->handleEvents();
	this->aFeed.setString(this->input);

}

void EnterFeed::handleEvents()
{
	
	
	if (InputManager::keyPressed(sf::Keyboard::Return))
	{		
		this->gsm->changeState(new Game(this->gsm, this->input.substring(1, this->input.getSize())));
	}
	else if (InputManager::keyPressed(sf::Keyboard::Escape))
	{
		this->gsm->popState();
	}
	else if (InputManager::keyPressed(sf::Keyboard::BackSpace))
	{
		if (this->input.getSize() > 1)
		{
			this->input.erase(input.getSize() - 1);
		}
	}
	if (this->input.getSize() < 17)
	{
		int c = InputManager::getIndexOfKeyPressed();
		if (c != -1)
		{
			this->input += static_cast<char>(c);
		}
	}
	
	
	
}

void EnterFeed::initiateVars()
{
	if (!this->texture.loadFromFile("textures/menu_wallpaper2.jpg"))
	{
		std::cout << "shit" << std::endl;
	}

	this->wallpaper.setTexture(this->texture);
	this->initiateText();
	this->initiateBox();
}

void EnterFeed::initiateText()
{
	if (!this->aFont.loadFromFile("font/D3Stonism.ttf"))
	{
		//FUCK
	}
	if (!this->inputFont.loadFromFile("font/times.ttf"))
	{
		//omg
	}
	this->enterFeed.setFont(this->aFont);
	this->aFeed.setFont(this->inputFont);
	this->aFeed.setFillColor(sf::Color::Black);
	this->goBack.setFont(this->aFont);
	this->input = '@';

	this->enterFeed.setString("Please enter a twitter user");
	this->aFeed.setString(this->input);
	this->goBack.setString("Press ESC to go back");

	this->enterFeed.setCharacterSize(64);
	this->aFeed.setCharacterSize(32);
	this->goBack.setCharacterSize(16);

	this->enterFeed.setPosition(sf::Vector2f(static_cast<float>(Application::SCREEN_WIDTH) / 2 - (15 * 60) / 2, static_cast<float>(Application::SCREEN_HEIGHT) / 2 - 150));
	this->aFeed.setPosition(sf::Vector2f(static_cast<float>(Application::SCREEN_WIDTH) / 2 - (15 * 20) / 2 - 30, static_cast<float>(Application::SCREEN_HEIGHT) / 2 + 50));
	this->goBack.setPosition(sf::Vector2f(static_cast<float>(Application::SCREEN_WIDTH) / 2 - (15 * 16) / 2, static_cast<float>(Application::SCREEN_HEIGHT) / 2 + 250));
}

void EnterFeed::initiateBox()
{
	this->inputBox.setSize(sf::Vector2f(17.0f * 25.0f, 40.0f));
	this->inputBox.setOutlineThickness(5.0f);
	this->inputBox.setOutlineColor(sf::Color::Black);
	this->inputBox.setPosition(sf::Vector2f(static_cast<float>(Application::SCREEN_WIDTH) / 2 - (15 * 20) / 2 - 30, static_cast<float>(Application::SCREEN_HEIGHT) / 2 + 55));
}

void EnterFeed::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->wallpaper);
	target.draw(this->inputBox);
	target.draw(this->aFeed);
	target.draw(this->enterFeed);
	target.draw(this->goBack);
}
