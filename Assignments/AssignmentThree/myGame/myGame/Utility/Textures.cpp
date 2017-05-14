#include "Textures.h"
namespace Textures
{

	sf::Font* tweetFont;

	void Textures::init()
	{
		tweetFont = new sf::Font();
		if (!tweetFont->loadFromFile("font/D3Stonism.ttf"))
			std::cout << "TweetFont: font/D3Stonism failed!" << std::endl;
		else
			std::cout << "RÖV" << std::endl;
	}

	void Textures::destroy()
	{
		delete tweetFont;
	}

	sf::Font * getFont()
	{
		return tweetFont;
	}

}
