#include "Enemy.h"

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
