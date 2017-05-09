#include "Map.h"
namespace Container
{

	Map::Map()
	{
		shape.setFillColor(sf::Color::Blue);
		shape.setSize(sf::Vector2f(800, 600));
		generateCave("lol");
	}

	Map::~Map()
	{
		for (int i = 0; i < caves.size(); i++)
		{
			delete caves.at(i);
		}
	}

	void Map::update(float dt)
	{
		caves.back()->update(dt);
	}

	void Map::render(sf::RenderTarget & target) const
	{
		target.draw(*caves.back());
	}

	void Map::generateCave(const std::string & url)
	{
		caves.push_back(new Cave());
		caves.back()->selectTwitterFeed(url);
		caves.back()->generateCave();
	}

	void Map::createMap()
	{

	}

}
