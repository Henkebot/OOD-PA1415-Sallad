#include "Cave.h"
#include "../Application.h"
#include <iostream>
namespace Container
{
	void Cave::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(bg);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				target.draw(rooms[i][j]);
			}

		}
	}

	Cave::Cave()
	{
		bg.setFillColor(sf::Color::Red);
		bg.setSize(sf::Vector2f(Application::SCREEN_WIDTH, Application::SCREEN_HEIGHT));
	}

	Cave::~Cave()
	{
		
		for (int i = 0; i < 2; i++)
		{
			delete[] rooms[i];
			rooms[i] = nullptr;

		}
		delete[] rooms;
		rooms = nullptr;

		
	}

	void Cave::generateCave()
	{
		rooms = new Room*[2];
		for (int i = 0; i < 2; i++)
		{
			rooms[i] = new Room[2];
			
		}

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				auto roomSize = rooms[i][j].shape.getSize();
				rooms[i][j].shape.setPosition(sf::Vector2f(150 + (i*(roomSize.x + 150)), 150 + (j*(roomSize.y + 120))));
			}
		}
	}

	bool Cave::selectTwitterFeed(const std::string & URL)
	{
		return false;
	}
	void Cave::update(float dt)
	{
	}
}

