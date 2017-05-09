#ifndef PLAYER_H 
#define PLAYER_H
#include "Mob.h"
#include "Inventory.h"
#include "Item.h"
class Player : public Mob
{
private:
	long xp;
	Inventory inventory;
public:
	Player(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0, 0), int health = 0);
	~Player(); 
	void setXP(long xp);
	long getXP() const;
	void create();
	void update(float dt);
	sf::Vector2f interact();
	void pickUpItem(Item item);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
};

#endif 

