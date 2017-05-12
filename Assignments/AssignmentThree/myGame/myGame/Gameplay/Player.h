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
	directions direction;
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

	
	void setDirection(directions newDirection);
	directions getDirection() const;
	sf::Vector2f moveRequest();
	void copy(Player player);
};

#endif 

