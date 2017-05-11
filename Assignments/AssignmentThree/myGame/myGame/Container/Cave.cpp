#include "Cave.h"
#include "../UserInterface/Application.h"
#include <iostream>
namespace Container
{
	void Cave::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(bg);
	
	}

	Cave::Cave()
	{
		bg.setFillColor(sf::Color::Red);
		bg.setSize(sf::Vector2f(Application::SCREEN_WIDTH, Application::SCREEN_HEIGHT));
	}

	Cave::~Cave()
	{
		

		
	}

	void Cave::generateCave()
	{
		
	}

	bool Cave::selectTwitterFeed(const std::string & URL)
	{
		return false;
	}
	void Cave::update(float dt)
	{
	}
}

