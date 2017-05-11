#ifndef DBG_NEW
#define _CRTDBG_MAP_ALLOC
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#ifndef ROOM_H
#define ROOM_H
#include <SFML\Graphics.hpp>


namespace Container
{
	class Room : public sf::Drawable
	{
	public:
		Room();
		virtual~Room();
		sf::RectangleShape shape;
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};

}

#endif

