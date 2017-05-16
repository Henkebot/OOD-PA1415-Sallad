#include "Map.h"
namespace Container
{

	Map::Map()
	{
		hudTexture = new sf::Texture();
		if (hudTexture->loadFromFile(".\\textures\\hud.png", sf::IntRect(960, 0, 320, 293)))
			std::cout << "HUD loading" << std::endl;
		hudSprite = new sf::Sprite();
		hudSprite->setTexture(*hudTexture);
		hudSprite->setPosition(sf::Vector2f(957, 0));
		//0, 528
		tweetTexture = new sf::Texture();
		tweetTexture->loadFromFile(".\\textures\\hud.png", sf::IntRect(0, 528, 960, 192));
		tweetZone = new sf::Sprite();
		tweetZone->setTexture(*tweetTexture);
		tweetZone->setPosition(sf::Vector2f(0, 528));
		gameLog = new Log();
		gameLog->setPosition(1000, 365);
		
		//generateCave("PA1415_Sallad");
	}

	Map::~Map()
	{
		delete hudTexture;
		delete hudSprite;
		delete tweetTexture;
		delete tweetZone;
		delete gameLog;
	}

	void Map::update(float dt)
	{
		caves.update(dt);
	}

	void Map::render(sf::RenderTarget & target) const
	{
		target.draw(*tweetZone);
		target.draw(caves);
		
		target.draw(*hudSprite);
		target.draw(*gameLog);
	}

	void Map::generateCave(const std::string & user)
	{
		caves.setLog(gameLog);
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
