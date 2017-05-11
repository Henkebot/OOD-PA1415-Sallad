#include "Cave.h"
#include "../UserInterface/Application.h"
#include <iostream>
namespace Container
{
	void Cave::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(bg);
		target.draw(*currentRoom);
		
	}

	void Cave::connectRoom(Room * rootRoom, int lastRoom)
	{
		int door = rand() % 4;
		// 0 = up
		// 1 = right
		// 2 = down
		// 3 = left
		if (door == lastRoom) connectRoom(rootRoom, door);
		switch (door)
		{
		case 0:
			if (rootRoom->getUpD() == nullptr)
			{
				Room* newRoom = new Room(numberOfRooms++);
				rootRoom->setUpD(newRoom);
				newRoom->setDownD(rootRoom);

				roomPointers.push_back(newRoom);
			}
			else
				connectRoom(rootRoom->getUpD(),door);
			break;
		case 1:
			if (rootRoom->getRightD() == nullptr)
			{
				Room* newRoom = new Room(numberOfRooms++);
				rootRoom->setRightD(newRoom);
				newRoom->setLeftD(rootRoom);

				roomPointers.push_back(newRoom);
			}
			else
				connectRoom(rootRoom->getRightD(),door);
			
			break;
		case 2:
			if (rootRoom->getDownD() == nullptr)
			{
				Room* newRoom = new Room(numberOfRooms++);
				rootRoom->setDownD(newRoom);
				newRoom->setUpD(rootRoom);

				roomPointers.push_back(newRoom);
			}
			else
				connectRoom(rootRoom->getDownD(),door);
			break;
		case 3:
			if (rootRoom->getLeftD() == nullptr)
			{
				Room* newRoom = new Room(numberOfRooms++);
				rootRoom->setLeftD(newRoom);
				newRoom->setRightD(rootRoom);

				roomPointers.push_back(newRoom);
			}
			else
				connectRoom(rootRoom->getLeftD(),door);
			break;
		}

	}

	Cave::Cave()
	{
		bg.setFillColor(sf::Color::Red);
		bg.setSize(sf::Vector2f(Application::SCREEN_WIDTH, Application::SCREEN_HEIGHT));
		numberOfRooms = 0;
	}

	Cave::~Cave()
	{
		
		int oldSize = roomPointers.size();
		for (int i = 0; i < oldSize; i++)
		{
			delete roomPointers.at(i);
		}
	}

	void Cave::generateCave()
	{
		currentRoom = new Room(numberOfRooms++);
		roomPointers.push_back(currentRoom);
		for (int i = 0; i < 5; i++)
		{
			connectRoom(currentRoom);
		}

	}

	bool Cave::selectTwitterFeed(const std::string & URL)
	{
		return false;
	}
	void Cave::update(float dt)
	{
		if (InputManager::keyPressed(sf::Keyboard::A))
			currentRoom = currentRoom->getLeftD();
		if (InputManager::keyPressed(sf::Keyboard::D))
			currentRoom = currentRoom->getRightD();
		if (InputManager::keyPressed(sf::Keyboard::S))
			currentRoom = currentRoom->getDownD();
		if (InputManager::keyPressed(sf::Keyboard::W))
			currentRoom = currentRoom->getUpD();
		
	}
}

