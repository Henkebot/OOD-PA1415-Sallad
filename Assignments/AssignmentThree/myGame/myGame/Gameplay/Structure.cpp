#include "Structure.h"

Structure::Structure(effects effect, sf::Texture* texture, sf::Vector2f coords) : NonMoveable(texture, coords)
{
	this->effect = effect;
}

Structure::~Structure()
{

}

void Structure::create()
{

}

std::string Structure::getInteractionEffect()
{
	return "InteractionEffect"; 
}

void Structure::update(float dt)
{

}

void Structure::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->getSprite(), states); 
}

effects Structure::getEffect() const
{
	return this->effect;
}

void Structure::setEffect(effects effect)
{
	this->effect = effect;
}
