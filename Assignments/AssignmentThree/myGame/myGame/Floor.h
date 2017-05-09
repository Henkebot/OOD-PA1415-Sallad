#ifndef FLOOR_H
#define FLOOR_H
#include "NonMoveable.h"
class Floor : public NonMoveable
{
private:

public:
	Floor(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0, 0), int health = 0);
	~Floor(); 
	void create(); 
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif
