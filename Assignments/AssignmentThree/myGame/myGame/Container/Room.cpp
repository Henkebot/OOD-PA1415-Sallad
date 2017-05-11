#include "Room.h"
namespace Container
{
	Room::Room()
	{
		shape.setFillColor(sf::Color::Green);
		shape.setSize(sf::Vector2f(32 * 30, 32 * 13));
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
	}

}
