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
	this->moveRequest(); 
	this->setTileXIndex(this->getSprite().getPosition().x / (64 * 0.75));
	this->setTileYIndex(this->getSprite().getPosition().y / (64 * 0.75));

	sf::Vector2i currentTile = sf::Vector2i(this->getTileXIndex(), this->getTileYIndex());
	int direction = (rand() % 4) + 1;

	if (direction == 1)
	{
		this->m_direction = directions::up;
	}
	else if (direction == 2)
	{
		this->m_direction = directions::right;
	}
	else if (direction == 3)
	{
		this->m_direction = directions::down;
	}
	else
	{
		this->m_direction = directions::left;
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
