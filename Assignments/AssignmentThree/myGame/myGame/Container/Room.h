#ifndef ROOM_H
#define ROOM_H
#include <SFML\Graphics.hpp>
#include "EntityHandler.h"
#include <string>
#include "../Utility/TweetAnalyzer.h"
#include "../Utility/Identifier.h"

namespace Container
{
	class Room : public sf::Drawable
	{
	private:

		Room* left;
		Room* right;
		Room* up;
		Room* down;

		sf::Vector2i coord;

		void deleteSpriteArray();
		int roomNumber;
		int roomRole;
		EntityHandler eh;
		std::string tweet;
		sf::Text currentTweet;
		//DEBUG
		/*sf::RectangleShape doorLeft;
		sf::RectangleShape doorRight;
		sf::RectangleShape doorUp;
		sf::RectangleShape doorDown;*/
	
	public:
		Room(const std::string& tweet, int role = 0);
		virtual~Room();

		static const int SPRITE_SIZE;
		void setEh(EntityHandler eh);

		EntityHandler& getCurrentEntityHandler();

		sf::Sprite** spritesArray;

		
		sf::Vector2i getCoord() const;
		void setCoord(const sf::Vector2i & coord);

		void setLeftD(Room* room);
		void setRightD(Room* room);
		void setUpD(Room* room);
		void setDownD(Room* room);

		Room* getLeftD() const;
		Room* getRightD() const;
		Room* getUpD() const;
		Room* getDownD() const;

		int getRole() const;

		void setSpriteArray(sf::Sprite** array);
		void update(float dt);

	private:
		
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	

	};

}

#endif

