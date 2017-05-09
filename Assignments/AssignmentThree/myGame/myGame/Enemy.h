#ifndef ENEMY_H
#define ENEMY_H
#include "Mob.h"
class Enemy : public Mob
{
private:

public:
	Enemy(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0,0), int health = 0);
	~Enemy();
	void create(); 
	void update(float dt); 
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
};
#endif
