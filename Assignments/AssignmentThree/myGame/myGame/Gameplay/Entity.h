#ifndef  ENTITY_H
#define ENTITY_H
#include "SFML\Graphics.hpp"
class Entity : public sf::Drawable
{
private:
	sf::Vector2f coords;
	sf::Texture texture; 
	int health; 
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Entity(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0,0), int health = 0); 
	~Entity(); 
	void setCoords(sf::Vector2f coords); 
	sf::Vector2f getCoords() const; 
	void setTexture(sf::Texture texture); 
	sf::Texture getTexture() const; 
	void setHealth(int health); 
	int getHealth() const;
	void setSprite(sf::Sprite sprite); 
	sf::Sprite getSprite() const; 
	virtual void update(float dt) = 0;
	virtual void create() = 0; 
};

#endif 

