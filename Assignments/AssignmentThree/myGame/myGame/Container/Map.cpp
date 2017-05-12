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
		
		caves.selectTwitterFeed(url);
		caves.generateCave();
	}

	void Map::createMap()
	{

	}

}
