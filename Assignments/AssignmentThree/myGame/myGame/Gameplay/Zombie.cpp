#include "Zombie.h"

Zombie::Zombie(sf::Texture* texture, sf::Vector2f coords, int health) : Enemy(texture, coords, health)
{

}

Zombie::~Zombie()
{

}

void Zombie::update(float dt)
{
	sf::Vector2i zombieTilePos = sf::Vector2i(this->getTileXIndex(), this->getTileYIndex()); 
	int direction = (rand() % 4) + 1;
	
	/*if (direction == 1)
	{
		if (zombieTilePos += sf::Vector2f(64, 0) != Other entityPos)
		{
			this->setIsAllowedRight(true);
			this->move(1, 0);
		}
		else
		{
			this->setIsAllowedRight(false);
		}
	}
	
	if (direction == 2)
	{
		if (zombieTilePos += sf::Vector2f(-64, 0) != Other entityPos)
		{
			this->setIsAllowedRight(true);
			this->move(1, 0);
		}
		else
		{
			this->setIsAllowedRight(false);
		}
	}

	if (direction == 3)
	{
		if (zombieTilePos += sf::Vector2f(0, -64) != Other entityPos*)
		{
			this->setIsAllowedUp(true); 
			this->move(0, -1); 
		}
		else
		{
			this->setIsAllowedUp(false); 
		}
	}

	if (direction == 4)
	{
		if(zombieTilePos += sf::Vector2f(0,))
	}*/

}
