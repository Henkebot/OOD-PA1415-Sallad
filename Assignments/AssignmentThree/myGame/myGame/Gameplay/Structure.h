#ifndef STRUCTURE_H 
#define STRUCTURE_H 
#include "NonMoveable.h"
#include "..\Utility\enums.h"
class Structure : public NonMoveable
{
private:
	effects effect;
public:
	Structure(effects effect, sf::Texture* texture = nullptr, sf::Vector2f coords = sf::Vector2f(0, 0));
	~Structure(); 
	void create(); 
	std::string getInteractionEffect(); 
	void update(float dt); 
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	effects getEffect() const;
	void setEffect(effects effect);
};

#endif 

