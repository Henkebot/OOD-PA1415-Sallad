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
		static const int SPRITE_SIZE;

		sf::Sprite** spritesArray;

		Room(int number, int role = 0);
		virtual~Room();
		

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

	private:

		Room* left;
		Room* right;
		Room* up;
		Room* down;

		void deleteSpriteArray();
		int roomNumber;
		int roomRole;
		//DEBUG
		/*sf::RectangleShape doorLeft;
		sf::RectangleShape doorRight;
		sf::RectangleShape doorUp;
		sf::RectangleShape doorDown;*/

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};

}

#endif

