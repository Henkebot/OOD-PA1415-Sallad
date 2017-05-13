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

}
