#ifndef ROOM_H
#define ROOM_H
#include <SFML\Graphics.hpp>
#include "EntityHandler.h"

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
		//DEBUG
		/*sf::RectangleShape doorLeft;
		sf::RectangleShape doorRight;
		sf::RectangleShape doorUp;
		sf::RectangleShape doorDown;*/
	
	public:
		static const int SPRITE_SIZE;
		void setEh(EntityHandler eh);

		EntityHandler& getCurrentEntityHandler();

		sf::Sprite** spritesArray;

		Room(int number, int role = 0);
		virtual~Room();
		
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

