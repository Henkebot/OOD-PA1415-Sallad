#ifndef ENEMY_H
#define ENEMY_H
#include "Mob.h"
#include <random>
class Enemy : public Mob
{
private:
	states state;
	directions m_direction; 
public:
	Enemy(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0,0), int health = 0);
	~Enemy();
	void create(); 
	//update needs to be checked
	void update(float dt); 
	sf::Vector2f interact();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; 

	states getState() const;
	void setState(states newState);
};
#endif
