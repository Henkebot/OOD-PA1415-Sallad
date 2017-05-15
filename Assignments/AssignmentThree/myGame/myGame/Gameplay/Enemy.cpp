#include "Enemy.h"
#include <random>
#include <cmath>
#include "../Utility/Values.h"
#include <iostream>

Enemy::Enemy(sf::Texture* texture, sf::Vector2f coords)  : Mob(texture,coords)
{
	agro = 3;
	state = states::idle;
}

Enemy::~Enemy()
{

}

void Enemy::create()
{

}

void Enemy::checkState(sf::Vector2f playerCoords)
{
	float distance = sqrt(pow((playerCoords.x - getCoords().x),2) + (pow((playerCoords.y - getCoords().y),2)));
	float tile = Val::SPRITE_SIZE;
	std::cout << "distance = " << distance << std::endl << "tile = " << tile << std::endl;
	if (distance <= tile)
	{
		state = states::attack;
		if (playerCoords.x < getCoords().x)
		{
			this->setDirection(directions::left);
			this->setCurrentSpriteFrame(0, 3);
		}
		else if (playerCoords.x > getCoords().x)
		{
			this->setDirection(directions::right);
			this->setCurrentSpriteFrame(0, 1);
		}
		else if (playerCoords.y < getCoords().y)
		{
			this->setDirection(directions::up);
			this->setCurrentSpriteFrame(0, 0);
		}
		else if (playerCoords.y > getCoords().y)
		{
			this->setDirection(directions::down);
			this->setCurrentSpriteFrame(0, 2);
		}
		else
		{
			state = states::idle;
		}
	}
	else if (distance <= tile * agro)
	{
		state = states::move;
		if (playerCoords.x < getCoords().x)
		{
			this->setDirection(directions::left);
			this->setCurrentSpriteFrame(0, 3);
		}
		else if (playerCoords.x > getCoords().x)
		{
			this->setDirection(directions::right);
			this->setCurrentSpriteFrame(0, 1);
		}
		else if (playerCoords.y < getCoords().y)
		{
			this->setDirection(directions::up);
			this->setCurrentSpriteFrame(0, 0);
		}
		else if (playerCoords.y > getCoords().y)
		{
			this->setDirection(directions::down);
			this->setCurrentSpriteFrame(0, 2);
		}
		else
		{
			state = states::idle;
		}
	}
	else
	{
		state = states::idle;
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
}

void Enemy::update(float dt)
{ 
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
	return state;
}

void Enemy::setState(states newState)
{
	state = newState;
}
