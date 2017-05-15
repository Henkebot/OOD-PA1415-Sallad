#ifndef NONMOVEABLE_H 
#define NONMOVEABLE_H
#include "Entity.h"


class NonMoveable : public Entity
{
private:

public:
	NonMoveable(sf::Texture* texture, sf::Vector2f coords); 
	~NonMoveable(); 

};
#endif
