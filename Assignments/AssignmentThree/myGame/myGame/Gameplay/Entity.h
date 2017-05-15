#ifndef  ENTITY_H
#define ENTITY_H
#include "SFML\Graphics.hpp"

class Entity : public sf::Drawable
{
private:
	sf::Vector2f coords;
	sf::Texture texture; 
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int tileX;
	int tileY; 

public:
	Entity(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0,0)); 
	~Entity(); 
	void setCoords(sf::Vector2f coords); 
	sf::Vector2f getCoords() const; 
	void setTexture(const sf::Texture& texture); 
	void setCurrentSpriteFrame(int x, int y);
	sf::Texture getTexture() const; 
	void setSprite(const sf::Sprite& sprite); 
	sf::Sprite getSprite() const;
	void setTileXIndex(int tileX); 
	int getTileXIndex();
	void setTileYIndex(int tileY); 
	int getTileYIndex(); 
	virtual void update(float dt) = 0;
	virtual void create() = 0; 
};

#endif 

