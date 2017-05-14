#include "Enemy.h"
#include <random>

Enemy::Enemy(sf::Texture* texture, sf::Vector2f coords, int health)  : Mob(texture,coords,health)
{
}

Enemy::~Enemy()
{

}

void Enemy::create()
{

}

void Enemy::update(float dt)
{ 
	int direction = (rand() % 4) + 1;

	if (direction == 1)
	{
		this->setDirection(directions::up);
		this->setCurrentSpriteFrame(0, 0);
	}
	else if (direction == 2)
	{
		this->setDirection(directions::right);
		this->setCurrentSpriteFrame(0, 1);
	}
	else if (direction == 3)
	{
		this->setDirection(directions::down);
		this->setCurrentSpriteFrame(0, 2);
	}
	else
	{
		this->setDirection(directions::left);
		this->setCurrentSpriteFrame(0, 3);
	}
}

sf::Vector2f Enemy::interact()
{
	return sf::Vector2f();
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->getSprite(), states); 
}

states Enemy::getState() const
{
	return states();
}

void Enemy::setState(states newState)
{
	state = newState;
}
