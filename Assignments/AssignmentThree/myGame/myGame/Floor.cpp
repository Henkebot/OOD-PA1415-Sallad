#include "Floor.h"

Floor::Floor(sf::Texture* texture, sf::Vector2f coords, int health) : NonMoveable(texture,coords,health)
{

}

Floor::~Floor()
{

}

void Floor::create()
{

}

void Floor::update(float dt)
{

}

void Floor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->getSprite(), states); 
}