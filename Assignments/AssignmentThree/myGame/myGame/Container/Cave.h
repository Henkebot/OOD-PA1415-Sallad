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
	public:
		static const int ROOM_WIDTH;
		static const int ROOM_HEIGHT;
	
	public:
		Cave();
		virtual~Cave();
		void generateCave();
		bool selectTwitterFeed(const std::string& user = "");
		void setSprite(sf::Sprite** spritesArray, float xIndex, float yIndex, int xSheet, int ySheet);
		
		void update(float dt);

	private:
		std::string twitterUser;
		Room* currentRoom;
		int tilesNumber;
		sf::Texture* tiles1;
		sf::Texture* tiles2;
		sf::Texture* tiles3;
		std::vector<Room*> roomPointers;
		Twitter twitterObj;

		std::vector<sf::RectangleShape> aMap;

		void applyRoomTextures();
		void changeRoom(Room* newRoom, int startX, int startY);
		void checkDoors();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		bool connectRoom(Room* rootRoom, int role, int lastRoom = 0); //role is what type of room: 0 Basic, 1 start, 2 end
		void importMap();


	};



}
#endif // !CAVE_H

