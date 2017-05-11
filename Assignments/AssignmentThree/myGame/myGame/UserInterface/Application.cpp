#include "Application.h"
const int Application::SCREEN_WIDTH = 1280;
const int Application::SCREEN_HEIGHT = 720;

Application::Application()
{
	std::cout << "Application created\n";
	this->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TwitterNethack");
	this->gsm = new GameStateManager();

	this->run();
}

Application::~Application()
{
	delete this->gsm;
}

void Application::run()
{
	this->gsm->pushState(new Menu(this->gsm));
	
	while (this->window.isOpen())
	{
		sf::Event event;
		sf::Clock gameTime;
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				InputManager::keyPressed(sf::Keyboard::Escape)) // if Escape was pressed, the game will terminate!
			{
				this->window.close();
			}
		}

		this->window.clear();
		//Updates the window if it is focused :D
		if(window.hasFocus())
			this->update(gameTime.restart().asSeconds());

		this->window.draw(*this);
		this->window.display();
	}
}

void Application::update(float dt)
{
	this->gsm->update(dt);
}

void Application::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*this->gsm, states);
}
