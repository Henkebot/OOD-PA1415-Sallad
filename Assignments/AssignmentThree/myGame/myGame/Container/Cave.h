#ifndef CAVE_H
#define CAVE_H
#include <string>
#include <SFML\Graphics.hpp>
#include "Room.h"
#include <vector>
#include "../Utility/Twitter.h"

namespace Container
{

	class Cave : public sf::Drawable
	{
	private:
		

		Room* currentRoom;
		sf::Texture* tiles;
		int numberOfRooms;
		std::vector<Room*> roomPointers;
		Twitter twitterObj;

		std::string twitterUser;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		bool connectRoom(Room* rootRoom, int role, int lastRoom = 0); //role is what type of room: 0 Basic, 1 start, 2 end
	public:
		Cave();
		virtual~Cave();
		void generateCave();
		bool selectTwitterFeed(const std::string& user = "");
		void setSprite(sf::Sprite** spritesArray, float xIndex, float yIndex, int xSheet, int ySheet);

		
		void update(float dt);

		static const float SCALE;


	};



}
#endif // !CAVE_H

