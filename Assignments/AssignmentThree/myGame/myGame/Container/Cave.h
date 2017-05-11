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

		sf::RectangleShape bg;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void connectRoom(Room* rootRoom, int role, int lastRoom = 0);
	public:
		Cave();
		virtual~Cave();
		void generateCave();
		bool selectTwitterFeed(const std::string& URL);
		void setSprite(sf::Sprite** spritesArray, int xIndex, int yIndex, int xSheet, int ySheet);

		
		void update(float dt);


	};



}
#endif // !CAVE_H

