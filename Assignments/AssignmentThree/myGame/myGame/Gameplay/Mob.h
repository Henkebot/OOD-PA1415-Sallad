#ifndef MOB_H 
#define MOB_H
#include "Entity.h"
#include "../Utility//enums.h"
class Mob : public Entity
{
private:
	bool isAllowedLeft; 
	bool isAllowedRight; 
	bool isAllowedUp; 
	bool isAllowedDown; 
	directions m_direction;
public:
	Mob(sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0,0) , int health = 0);
	~Mob(); 
	sf::Vector2f attack(); 
	sf::Vector2f moveRequest(); 
	void move(int xDir, int yDir);
	//ONLY HAS RETURN TYPE VOID TEMPORARLY, UNTILL THE STATS CLASS IS IMPLEMENTED
	void getStats() const; 
	void setPos(sf::Vector2f coords); 
	virtual sf::Vector2f interact() = 0; 
	bool getIsAllowedLeft(); 
	void setIsAllowedLeft(bool isAllowed); 
	bool getIsAllowedRight(); 
	void setIsAllowedRight(bool isAllowed); 
	bool getIsAllowedUp(); 
	void setIsAllowedUp(bool isAllowed); 
	bool getIsAllowedDown(); 
	void setIsAllowedDown(bool isAllowed);
	directions getDirection(); 
	void setDirection(directions direction); 
	bool isDead() const; 
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif 

