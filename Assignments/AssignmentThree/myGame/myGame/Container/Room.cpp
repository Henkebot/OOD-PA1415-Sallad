#include "Room.h"

Container::Room::Room()
{
	shape.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(32*30, 32*13));
}

void Container::Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape);
}
