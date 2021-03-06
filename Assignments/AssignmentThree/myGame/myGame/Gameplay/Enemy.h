#ifndef ENEMY_H
#define ENEMY_H
#include "Mob.h"
#include <random>
class Enemy : public Mob
{
private:
	states state;
	int agro;
	int stupidity;
public:
	Enemy(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0,0));
	~Enemy();
	void create(); 
	void checkState(sf::Vector2f playerCoords);
	void update(float dt); 
	sf::Vector2f interact();
	
	states getState() const;
	void setState(states newState);

};
#endif
