#ifndef CAVE_H
#define CAVE_H
#include <string>
#include <SFML\Graphics.hpp>
#include "Room.h"
#include <vector>

namespace Container
{

	class Cave : public sf::Drawable
	{
	private:
		Room* currentRoom;
		sf::Texture* tiles;
		int numberOfRooms;
		std::vector<Room*> roomPointers;

		std::string twitterURL;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		bool connectRoom(Room* rootRoom, int role, int lastRoom = 0); //role is what type of room: 0 Basic, 1 start, 2 end
	public:
		Cave();
		virtual~Cave();
		void generateCave();
		bool selectTwitterFeed(const std::string& URL);
		void setSprite(sf::Sprite** spritesArray, float xIndex, float yIndex, int xSheet, int ySheet);

		
		void update(float dt);


	};



}
#endif // !CAVE_H

