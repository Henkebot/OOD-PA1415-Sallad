#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>
#include "Cave.h"
#include <SFML\Graphics.hpp>
namespace Container
{
	class Map 
	{
	private:
		sf::Texture* hudTexture;
		sf::Sprite* hudSprite;
		Cave caves;
	public:
		Map();
		virtual ~Map();
		
		void update(float dt);
		void render(sf::RenderTarget& target) const;
		void generateCave(const std::string& url);
		void createMap();



	};

}


#endif // !MAP_H

