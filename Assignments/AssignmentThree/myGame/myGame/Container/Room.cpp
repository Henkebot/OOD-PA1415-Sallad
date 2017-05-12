#include "Room.h"
#include <iostream>
namespace Container
{
	const int Room::SPRITE_SIZE = 64;

	void Room::setEh(EntityHandler eh)
	{
		this->eh = eh;
	}

	EntityHandler& Room::getCurrentEntityHandler() 
	{
		return eh;
	}

	Room::Room(int number, int role)
	{	
		roomRole = role;
		left = right = up = down = nullptr;

		/*doorDown.setFillColor(sf::Color::Blue);
		doorDown.setSize(sf::Vector2f(128, 16));
		doorDown.setPosition(64 * 9.5f, 64 * 10.5f);
		
		doorUp.setFillColor(sf::Color::Blue);
		doorUp.setSize(sf::Vector2f(128, 16));
		doorUp.setPosition(64 * 9.5f, 0);

		doorRight.setFillColor(sf::Color::Blue);
		doorRight.setSize(sf::Vector2f(16, 128));
		doorRight.setPosition(64 * 19.5f, 64*5);

		doorLeft.setFillColor(sf::Color::Blue);
		doorLeft.setSize(sf::Vector2f(16, 128));
		doorLeft.setPosition(0, 64 * 5);*/


		roomNumber = number;

	}

	Room::~Room()
	{
		deleteSpriteArray();
	}

	sf::Vector2i Room::getCoord() const
	{
		return coord;
	}

	void Room::setCoord(const sf::Vector2i & coord)
	{
		this->coord = coord;
	}

	void Room::setLeftD(Room * room)
	{
		left = room;

	}

	void Room::setRightD(Room * room)
	{
		right = room;
	}

	void Room::setUpD(Room * room)
	{
		up = room;
	}

	void Room::setDownD(Room * room)
	{
		down = room;

	}

	Room * Room::getLeftD() const
	{
		return left;
	}

	Room * Room::getRightD() const
	{
		return right;
	}

	Room * Room::getUpD() const
	{
		return up;
	}

	Room * Room::getDownD() const
	{
		return down;
	}

	int Room::getRole() const
	{
		return roomRole;
	}

	void Room::setSpriteArray(sf::Sprite ** array)
	{
		sf::Sprite** newArray = new sf::Sprite*[20];
		for (int i = 0; i < 20; i++)
		{
			newArray[i] = new sf::Sprite[11];
			for (int j = 0; j < 11; j++)
			{
				newArray[i][j] = array[i][j];
			}
		}
		spritesArray = newArray;
	}

	void Room::update(float dt)
	{
		eh.update(dt);
		
	}

	void Room::deleteSpriteArray()
	{
		for (int x = 0; x < 20; x++)
		{
			delete[] spritesArray[x];
		}
		delete[] spritesArray;
	}

	void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		
		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 11; y++)
			{
				target.draw(spritesArray[x][y]);

			}

		}
		target.draw(*eh.getPlayer());
		/*if(down != nullptr) target.draw(doorDown);
		if(up != nullptr) target.draw(doorUp);
		if (right != nullptr) target.draw(doorRight);
		if (left != nullptr) 	target.draw(doorLeft);*/
	}

}
