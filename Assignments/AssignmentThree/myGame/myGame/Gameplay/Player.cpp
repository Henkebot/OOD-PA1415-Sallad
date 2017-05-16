#include "Player.h"
#include <iostream>
#include "../Utility/Values.h"
Player::Player(sf::Texture* texture, sf::Vector2f coords) : Mob(texture,coords)
{
	this->getStats()->setAccuracy(7);
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
	sf::Vector2f request = getCoords();

	float tile = Val::SCALE * Val::SPRITE_SIZE;

	if (this->getDirection() == up)
	{
		request.y -= tile;
	}
	else if (this->getDirection() == left)
	{
		request.x -= tile;
	}
	else if (this->getDirection() == down)
	{
		request.y += tile;
	}
	else if (this->getDirection() == right)
	{
		request.x += tile;
	}
	return request;
}

void Player::pickUpItem(Item item)
{

}

//void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//
//	target.draw(this->getSprite(), states); 
//}


