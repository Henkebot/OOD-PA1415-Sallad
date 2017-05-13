#include "Map.h"
namespace Container
{

	Map::Map()
	{
		generateCave("");
	}

	Map::~Map()
	{
		
	}

	void Map::update(float dt)
	{
		caves.update(dt);
	}

	void Map::render(sf::RenderTarget & target) const
	{
		target.draw(caves);
	}

	void Map::generateCave(const std::string & url)
	{
		std::cout << "Authenticating twitter..." << std::endl;
		if (caves.selectTwitterFeed(url))
			std::cout << "Succesfully authenticated!" << std::endl;
		else
			std::cout << "Failed to authenticate, will use local feed!" << std::endl;
		caves.generateCave();
	}

	void Map::createMap()
	{

	}

}
