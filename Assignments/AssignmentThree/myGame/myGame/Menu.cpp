#include "Menu.h"

Menu::Menu(GameStateManager * gsm) :
	State(gsm)
{
	std::cout << "Menu state pushed!\n";
	this->texture.loadFromFile("textures/menu_wallpaper.jpg");
	this->wallpaper.setTexture(this->texture);
	this->wallpaper.setPosition(0.0f, 0.0f);

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

	//Stuff goind down	


}

void Menu::handleEvents()
{
	if (InputManager::keyPressed(sf::Keyboard::Return))
	{
		this->gsm->pushState(new Game(this->gsm));
	}
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
	target.draw(this->wallpaper, states);
	//target.draw(this->shape, states);
}
