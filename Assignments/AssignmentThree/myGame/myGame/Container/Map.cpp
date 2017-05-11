#include "Map.h"
namespace Container
{

	Map::Map()
	{
		shape.setFillColor(sf::Color::Blue);
		shape.setSize(sf::Vector2f(800, 600));
		caves.generateCave();
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
