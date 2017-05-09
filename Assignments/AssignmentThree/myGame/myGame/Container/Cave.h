#ifndef CAVE_H
#define CAVE_H
#include <string>
#include <SFML\Graphics.hpp>
#include "Room.h"
namespace Container
{

	class Cave : public sf::Drawable
	{
	private:
		Room** rooms;
		int nrOfRooms = 1;
		std::string twitterURL;

		sf::RectangleShape bg;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		Cave();

		void generateCave();
		bool selectTwitterFeed(const std::string& URL);

		void update(float dt);


	};



}
#endif // !CAVE_H

