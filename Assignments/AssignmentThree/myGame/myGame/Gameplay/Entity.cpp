#include "Entity.h"
#include "../Utility/Values.h"
Entity::Entity(sf::Texture* texture, sf::Vector2f coords)
{
	this->texture = *texture; 
	this->coords = coords; 
	this->sprite.setTexture(this->texture); 
	setCurrentSpriteFrame(0, 0);
	this->sprite.setScale(Val::SCALE, Val::SCALE);
	this->sprite.setPosition(coords);
}

Entity::~Entity()
{

}

void Entity::setCoords(sf::Vector2f coords)
{
	this->coords = coords; 
	sprite.setPosition(coords);
}

sf::Vector2f Entity::getCoords() const
{
	return this->coords;
}

void Entity::setTexture(const sf::Texture& texture)
{
	this->texture = texture; 
}

void Entity::setCurrentSpriteFrame(int x, int y)
{
	sprite.setTextureRect(sf::IntRect(Val::SPRITE_SIZE * x, Val::SPRITE_SIZE * y, Val::SPRITE_SIZE, Val::SPRITE_SIZE));
}

sf::Texture Entity::getTexture() const
{
	return this->texture; 
}

void Entity::setSprite(const sf::Sprite& sprite)
{
	this->sprite = sprite;
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