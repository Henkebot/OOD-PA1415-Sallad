#include "Application.h"
#include <ctime>
const int Application::SCREEN_WIDTH = 1280;
const int Application::SCREEN_HEIGHT = 720;

Application::Application()
{
	srand(static_cast<unsigned>(time(0)));
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
	
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Event event;
		sf::Clock gameTime;
		float currentTime = clock.restart().asSeconds();
		float fps = 1.0f / currentTime;
		this->window.setTitle("TwitterNethack\t\t" + std::to_string(fps));
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || this->gsm->emptyStack()) 
			{
				this->window.close();
			}
		}

		this->window.clear();
		//Updates the window if it is focused :D
		if (this->window.hasFocus() && !this->gsm->emptyStack())
		{
			this->update(gameTime.restart().asSeconds());
		}

		this->window.draw(*this);
		this->window.display();
	}
}

void Application::update(float dt)
{
	if (!this->gsm->emptyStack())
		this->gsm->update(dt);
}

void Application::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*this->gsm, states);
}
