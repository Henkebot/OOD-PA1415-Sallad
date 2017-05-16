#ifndef PLAYER_H 
#define PLAYER_H
#include "Mob.h"
#include "../Container/Inventory.h"
#include "Item.h"

class Player : public Mob
{
private:
	long xp;
	Inventory* inventory;
public:
	Player(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(64*5, 64*5));
	~Player(); 
	void setXP(long xp);
	long getXP() const;
	void create();
	void update(float dt);
	sf::Vector2f interact();
	void pickUpItem(Item item);

};

#endif 

