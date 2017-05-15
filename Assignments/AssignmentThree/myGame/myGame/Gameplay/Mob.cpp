#include "Mob.h"
#include "../Utility/Values.h"

Mob::Mob(sf::Texture* texture, sf::Vector2f coords, int health) : Entity(texture,coords,health)
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
}

Mob::~Mob()
{

}

sf::Vector2f Mob::attack()
{
	return sf::Vector2f(0, 0);
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
void Mob::getStats() const
{

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

bool Mob::getIsAllowedLeft()
{
	return this->isAllowedLeft; 
}

void Mob::setIsAllowedLeft(bool isAllowed)
{
	this->isAllowedLeft = isAllowed; 
}

bool Mob::getIsAllowedRight()
{
	return this->isAllowedRight; 
}

void Mob::setIsAllowedRight(bool isAllowed)
{
	this->isAllowedRight = isAllowed;
}

bool Mob::getIsAllowedUp()
{
	return this->isAllowedUp; 
}

void Mob::setIsAllowedUp(bool isAllowed)
{
	this->isAllowedUp = isAllowed; 
}

bool Mob::getIsAllowedDown()
{
	return this->isAllowedDown; 
}

void Mob::setIsAllowedDown(bool isAllowed)
{
	this->isAllowedDown = isAllowed; 
}

//Rätt uppfattat? 
bool Mob::isDead() const
{
	bool isDead = false; 
	if (this->getHealth() <= 0)
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
	target.draw(this->getSprite(), states); 
}
