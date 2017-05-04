#include "Player.hpp"

Player::Player()
{
	tPlayer.loadFromFile("../textures/Player.png");
	sPlayer.setTexture(tPlayer);

	/* For sprite sheet
	
	sPlayer.setTextureRect(sf::intRect(0,0,32,32));
	*/
}

void Player::update(float dt)
{
	sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction = sf::Vector2f(1.0f, 0.0f);
		//keyFrameDuration += dt;
		//currentKeyFrame.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction = sf::Vector2f(-1.0f, 0.0f);
		//keyFrameDuration += dt;
		//currentKeyFrame.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction = sf::Vector2f(0.0f, -1.0f);
		//keyFrameDuration += dt;
		//currentKeyFrame.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction = sf::Vector2f(0.0f, 1.0f);
		//keyFrameDuration += dt;
		//currentKeyFrame.y = 0;
	}

	bool isSpacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	if (isSpacePressed && !wasSpacePressed)
	{
		isJumping = true;
		jumpSpeed = 3.0f;
		startY = sPlayer.getPosition().y;
	}
	if (isJumping)
	{
		jumpSpeed -= gravity * dt;
		direction.y = jumpSpeed;
		if (sPlayer.getPosition().y > startY)
		{
			isJumping = false;
		}
	}

	wasSpacePressed = isSpacePressed;

	/* else
	{
		currentKeyFrame.x = 1;
	}

	*/

	sPlayer.move(direction * speed * dt);

	/*		Sprite sheet
	

	if (keyFrameDuration > animationSpeed
	{
		currentKeyFrame.x += 1;
		if(currentKeyFrame.x >= 4)
		{
			currentKeyFrame.x = 0;
		}

		sPlayer.setTextureRect(sf::IntRect(currentKeyFrame.x * keyFrameSize.x, currentKeyFrame.y * keyFrameSize.y, keyFrameSize.x, keyFrameSize.y))
		keyFrameDuration = 0.0f;

	}



	*/


}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sPlayer, states);
}

