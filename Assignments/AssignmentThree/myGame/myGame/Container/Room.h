#ifndef ROOM_H
#define ROOM_H
#include <SFML\Graphics.hpp>

class EntityHandler;
namespace Container
{
	class Room : public sf::Drawable
	{
	public:
		EntityHandler* eHandler;
		Room();
		sf::RectangleShape shape;
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};

}

#endif

