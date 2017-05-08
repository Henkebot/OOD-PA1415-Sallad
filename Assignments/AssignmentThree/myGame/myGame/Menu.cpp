#include "Menu.h"

Menu::Menu(GameStateManager * gsm) :
	State(gsm)
{
	std::cout << "Menu state pushed!\n";
	this->shape.setRadius(50);
	this->shape.setFillColor(sf::Color(100, 250, 50));
}

Menu::Menu(const Menu & other):
	State(other)
{

}

Menu::~Menu()
{

}

void Menu::update(float dt)
{
	this->handleEvents();
}

void Menu::handleEvents()
{
	
}

Menu & Menu::operator=(const Menu & other)
{
	if (this != &other)
	{
		State::operator=(other);
		//more stuff
	}
	
	return *this;

}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->shape, states);
}
