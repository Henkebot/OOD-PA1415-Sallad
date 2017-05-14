#include "Player.h"
#include <iostream>
#include "../Utility/Values.h"
Player::Player(sf::Texture* texture, sf::Vector2f coords, int health) : Mob(texture,coords,health)
{
}

Player::~Player()
{

}

void Player::setXP(long xp)
{
	this->xp = xp; 
}

long Player::getXP() const
{
	return this->xp;
}

void Player::create()
{

}

void Player::update(float dt)
{

}

sf::Vector2f Player::interact()
{
	return sf::Vector2f(0, 0); 
}

void Player::pickUpItem(Item item)
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(this->getSprite(), states); 
}

void Player::setDirection(directions newDirection)
{
	direction = newDirection;
}

directions Player::getDirection() const
{
	return direction;
}

sf::Vector2f Player::moveRequest()
{
	sf::Vector2f request = getCoords();
	// MÅSTE FIXA DETTA
	
	float tile = Val::SCALE * Val::SPRITE_SIZE;

	if (direction == up)
	{
		request.y-=tile;
	}
	else if(direction == left)
	{
		request.x-=tile;
	}
	else if (direction == down)
	{
		request.y+=tile;
	}
	else if (direction == right)
	{
		request.x+=tile;
	}
	return request;
}

void Player::copy(Player player)
{
	this->xp = player.xp;
	this->inventory = player.inventory;
	this->direction = player.direction;
	this->setHealth(player.getHealth());
	this->setCoords(player.getCoords());
	this->setSprite(player.getSprite());
}
