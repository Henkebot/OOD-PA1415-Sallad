#include "Mob.h"
#include <iostream>
Mob::Mob(sf::Texture* texture, sf::Vector2f coords, int health) : Entity(texture,coords,health)
{

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
	return sf::Vector2f(0, 0);
}

void Mob::move(int xDir, int yDir)
{

	
	setPos(sf::Vector2f(getSprite().getPosition().x + (64 * xDir), getSprite().getPosition().y + (64 * yDir)));

}
//ONLY TEMPORARY RETURNTYPE VOID UNTILL STATS ARE IMPLEMENTED
void Mob::getStats() const
{

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

void Mob::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->getSprite(), states); 
}
