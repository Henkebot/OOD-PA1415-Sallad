#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	Player();

	void update(float dt);
private:
	sf::Texture tPlayer;
	sf::Sprite sPlayer;
	float speed = 100.0f;



	//Jump var
	bool wasSpacePressed = false;
	bool isJumping = false;
	float gravity = 9.82f;
	float startY = 0.0f;
	float jumpSpeed = 0.0f;


	/*  -:: Animation var ::-
	sf::Vector2i keyFrameSize = sf::Vector2i(32,32);
	int spriteSheetWidth = 4;
	sf::Vector2i currentKeyFrame = sf::Vector2i(0,0);
	float animationSpeed = 0.2f;
	float keyFramDuration = 0.0f;


	*/
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif