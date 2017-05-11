#include "Room.h"
#include <iostream>
namespace Container
{
	Room::Room(int number)
	{
		shape.setFillColor(sf::Color::Green);
		shape.setSize(sf::Vector2f(64 * 20, 64 * 11));

		left = right = up = down = nullptr;

		doorDown.setFillColor(sf::Color::Blue);
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
		doorLeft.setPosition(0, 64 * 5);


		roomNumber = number;

	}

	Room::~Room()
	{

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

	void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(shape);
		if(down != nullptr) target.draw(doorDown);
		if(up != nullptr) target.draw(doorUp);
		if (right != nullptr) target.draw(doorRight);
		if (left != nullptr) 	target.draw(doorLeft);
		std::cout << roomNumber << std::endl;
	}

}
