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
		int roomRole;
		EntityHandler eh;

		sf::Font* tweetFont;

		static std::string owner;
		sf::Text tweetOwner;

		std::string tweet;
		sf::Text currentTweet;
		sf::Sprite** spritesArray;
		
	public:
		Room(const std::string& tweet, int role = 0);
		virtual~Room();

		void setEh(EntityHandler eh);

		EntityHandler& getCurrentEntityHandler();


		
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

		void setOwner(const std::string& owner);

		void setSpriteArray(sf::Sprite** array);
		void update(float dt);

		bool* getDoorStatus() const;

	private:

		void deleteSpriteArray();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	

	};

};

#endif

