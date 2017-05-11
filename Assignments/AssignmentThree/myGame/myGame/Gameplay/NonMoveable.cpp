#include "NonMoveable.h"

NonMoveable::NonMoveable(sf::Texture* texture, sf::Vector2f coords, int health) : Entity(texture,coords,health)
{

}

NonMoveable::~NonMoveable()
{

}