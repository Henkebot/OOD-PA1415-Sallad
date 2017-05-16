#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>
#include "Cave.h"
#include <SFML\Graphics.hpp>
#include "../UserInterface/Log.h"
namespace Container
{
	class Map 
	{
	private:
		sf::Texture* hudTexture;
		sf::Texture* tweetTexture;
		sf::Sprite* hudSprite;
		sf::Sprite* tweetZone;
		Log* gameLog;

		Cave caves;
	public:
		Map();
		virtual ~Map();
		
		void update(float dt);
		void render(sf::RenderTarget& target) const;
		void generateCave(const std::string& user);
		void createMap(std::string rootUser = "");



	};

}


#endif // !MAP_H

