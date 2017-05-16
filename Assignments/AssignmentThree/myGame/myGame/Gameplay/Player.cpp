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
	return sf::Vector2f(0, 0); 
}

void Player::pickUpItem(Item item)
{

}

//void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//
//	target.draw(this->getSprite(), states); 
//}


