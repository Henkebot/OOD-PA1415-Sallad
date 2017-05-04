#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Game : public sf::Drawable
{
public:
	Game();
	void update(float dt);
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Texture tBackground;
	sf::Sprite sBackground;
	Player mPlayer;
};


#endif