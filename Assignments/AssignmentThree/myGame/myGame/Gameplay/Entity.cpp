#include "Entity.h"

Entity::Entity(sf::Texture* texture, sf::Vector2f coords, int health)
{
	this->texture = *texture; 
	this->coords = coords; 
	this->health = health; 
	this->sprite.setTexture(this->texture); 
}

Entity::~Entity()
{

}

void Entity::setCoords(sf::Vector2f coords)
{
	this->coords = coords; 
}

sf::Vector2f Entity::getCoords() const
{
	return this->coords;
}

void Entity::setTexture(sf::Texture texture)
{
	this->texture = texture; 
}

sf::Texture Entity::getTexture() const
{
	return this->texture; 
}

void Entity::setHealth(int health)
{
	this->health = health; 
}

int Entity::getHealth() const
{
	return this->health; 
}

void Entity::setSprite(sf::Texture texture)
{
	this->sprite.setTexture(texture);
}

sf::Sprite Entity::getSprite() const
{
	return this->sprite; 
}

void Entity::update(float dt)
{

}

void Entity::create()
{

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->getSprite(), states); 
}