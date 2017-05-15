#include "Map.h"
namespace Container
{

	Map::Map()
	{
		hudTexture = new sf::Texture();
		if (hudTexture->loadFromFile(".\\textures\\hud.png"))
			std::cout << "HUD loading" << std::endl;
		hudSprite = new sf::Sprite();
		hudSprite->setTexture(*hudTexture);

		//generateCave("PA1415_Sallad");
		
	}

	Map::~Map()
	{
		delete hudTexture;
		delete hudSprite;
	}

	void Map::update(float dt)
	{
		caves.update(dt);
	}

	void Map::render(sf::RenderTarget & target) const
	{
		//target.draw(*hudSprite);
		target.draw(caves);
	}

	void Map::generateCave(const std::string & user)
	{
		std::cout << "Authenticating twitter..." << std::endl;
		if (caves.selectTwitterFeed(user))
			std::cout << "Succesfully authenticated!" << std::endl;
		else
			std::cout << "Failed to authenticate, will use local feed!" << std::endl;
		caves.generateCave();
	}

	void Map::createMap(std::string rootUser)
	{
		generateCave(rootUser);
	}

}
