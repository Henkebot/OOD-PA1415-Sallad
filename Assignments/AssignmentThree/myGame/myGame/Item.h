#ifndef  ITEM_H 
#define ITEM_H 
#include "Entity.h"
class Item : public Entity
{
private:

public:
	Item(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0,0), int health = 0); 
	~Item(); 
	void create();
	void update(float dt); 
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; 
};
#endif // ! ITEM_H 

