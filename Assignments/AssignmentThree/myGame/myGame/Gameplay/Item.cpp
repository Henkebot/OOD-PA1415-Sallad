#include "Item.h"

Item::Item(sf::Texture* texture, sf::Vector2f coords) : Entity(texture, coords)
{

}

Item::~Item()
{

}

void Item::create()
{

}

void Item::update(float dt)
{

}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(this->getSprite(), states); 
}