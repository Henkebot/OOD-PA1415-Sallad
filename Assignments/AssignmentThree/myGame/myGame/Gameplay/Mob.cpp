#include "Mob.h"
#include "../Utility/Values.h"
#include <iostream>

Mob::Mob(sf::Texture* texture, sf::Vector2f coords) : Entity(texture,coords)
{
	int startDirection = (rand() % 4) + 1; 
	if (startDirection == 1)
	{
		this->m_direction = directions::up; 
		this->setCurrentSpriteFrame(0, 0);
	}
	else if (startDirection == 2)
	{
		this->m_direction = directions::right;
		this->setCurrentSpriteFrame(0, 1);
	}
	else if (startDirection == 3)
	{
		this->m_direction = directions::down;
		this->setCurrentSpriteFrame(0, 2);
	}
	else
	{
		this->m_direction = directions::left; 
		this->setCurrentSpriteFrame(0, 3);
	}
	stats = new Stats(10,0.2f,10);

	entireHealthBar.setSize(sf::Vector2f(48, 8));
	entireHealthBar.setFillColor(sf::Color::Red);

	healthLeftBar.setSize(sf::Vector2f(48, 8));
	healthLeftBar.setFillColor(sf::Color::Green);

}

Mob::~Mob()
{

}

sf::Vector2f Mob::attack()
{
	sf::Vector2f request = getCoords();
	// MÅSTE FIXA DETTA

	float tile = Val::SCALE * Val::SPRITE_SIZE;

	if (m_direction == up)
	{
		request.y -= tile;
	}
	else if (m_direction == left)
	{
		request.x -= tile;
	}
	else if (m_direction == down)
	{
		request.y += tile;
	}
	else if (m_direction == right)
	{
		request.x += tile;
	}
	return request;
}

sf::Vector2f Mob::moveRequest()
{
	sf::Vector2f request = getCoords();
	// MÅSTE FIXA DETTA

	float tile = Val::FINAL_SIZE;

	if (m_direction == up)
	{
		request.y -= tile;
	}
	else if (m_direction == left)
	{
		request.x -= tile;
	}
	else if (m_direction == down)
	{
		request.y += tile;
	}
	else if (m_direction == right)
	{
		request.x += tile;
	}
	return request;
}

void Mob::move(int xDir, int yDir)
{	
	float size = Val::SPRITE_SIZE;
	float scale = Val::SCALE;
	int playerNewX = getSprite().getPosition().x + ((size * scale) * xDir);
	int playerNewY = getSprite().getPosition().y + ((size * scale) * yDir);
	setPos(sf::Vector2f(playerNewX, playerNewY));
}
//ONLY TEMPORARY RETURNTYPE VOID UNTILL STATS ARE IMPLEMENTED
Stats* Mob::getStats() const
{
	return stats;
}

void Mob::setDirection(directions direction)
{
	this->m_direction = direction;
}

directions Mob::getDirection()
{
	return this->m_direction; 
}

int Mob::getDirX() const
{
	int dirX = 0; 
	if (m_direction == directions::left)
	{
		dirX = -1; 
	}
	else if (m_direction == directions::right)
	{
		dirX = 1; 
	}
	return dirX; 
}

int Mob::getDirY() const
{
	int dirY = 0; 
	if (m_direction == directions::down)
	{
		dirY = 1;
	}
	else if (m_direction == directions::up)
	{
		dirY = -1; 
	}
	return dirY; 
}

//Är detta rätt uppfattat?
void Mob::setPos(sf::Vector2f coords)
{
	this->setCoords(coords); 
}

sf::Vector2f Mob::interact()
{
	return sf::Vector2f(0, 0);
}
void Mob::updateHealthbar()
{
	int coordX = getSprite().getPosition().x;
	int coordY = getSprite().getPosition().y;
	float barModifier = getStats()->getHealth() / 10;

	healthLeftBar.setSize(sf::Vector2f(48 * barModifier,8));
	healthLeftBar.setPosition(sf::Vector2f(coordX, coordY - 20));
	entireHealthBar.setPosition(sf::Vector2f(coordX, coordY - 20));

}
//Rätt uppfattat? 
bool Mob::isDead() const
{
	bool isDead = false; 
	if (stats->getHealth() <= 0)
	{
		isDead = true;
	}
	return isDead; 
}

void Mob::update(float dt)
{
	sf::Vector2f newPos = this->moveRequest();
	this->move(newPos.x, newPos.y); 
}

void Mob::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(entireHealthBar);
	target.draw(healthLeftBar);
	target.draw(this->getSprite(), states); 
}
