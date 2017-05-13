#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Enemy.h"
class Zombie : public Enemy
{
private:

public:
	Zombie(sf::Texture* texture, sf::Vector2f coords, int health);
	~Zombie();

	void update(float dt); 

};
#endif 
