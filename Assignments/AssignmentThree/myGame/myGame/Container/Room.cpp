#include "Room.h"
#include <iostream>
#include "../UserInterface/Application.h"
namespace Container
{
	std::string Room::owner = "";

	void Room::setEh(EntityHandler eh)
	{
		this->eh = eh;
	}

	EntityHandler& Room::getCurrentEntityHandler() 
	{
		return eh;
	}

	Room::Room(const std::string& tweet,int role)
	{	
		left = right = up = down = nullptr;
		roomRole = role;
		this->tweet = tweet;

		tweetFont = new sf::Font();

		if (!tweetFont->loadFromFile("font/D3Stonism.ttf"))
			std::cout << "Lol" << std::endl;

		currentTweet.setFont(*tweetFont);

		//test
		std::string aTweet = tweet;
		bool wantNewLine = false;
		for (int i = 0; i < aTweet.size(); i++)
		{
			if ((i + 1) % 60 == 0)
			{
				wantNewLine = true;
			}
			if (wantNewLine && tweet[i] == ' ')
			{
				aTweet[i] = '\n';
				wantNewLine = false;
			}
		}

		currentTweet.setString(aTweet);
		currentTweet.setCharacterSize(16);
		currentTweet.setPosition(sf::Vector2f(175, Application::SCREEN_HEIGHT - 140));
		currentTweet.setFillColor(sf::Color::Black);

		discovered = false;

	}

	Room::~Room()
	{
		deleteSpriteArray();
	}

	sf::Vector2i Room::getCoord() const
	{
		return coord;
	}

	void Room::setCoord(const sf::Vector2i & coord)
	{
		this->coord = coord;
	}

	void Room::setLeftD(Room * room)
	{
		left = room;

	}

	void Room::setRightD(Room * room)
	{
		right = room;
	}

	void Room::setUpD(Room * room)
	{
		up = room;
	}

	void Room::setDownD(Room * room)
	{
		down = room;

	}

	Room * Room::getLeftD() const
	{
		return left;
	}

	Room * Room::getRightD() const
	{
		return right;
	}

	Room * Room::getUpD() const
	{
		return up;
	}

	Room * Room::getDownD() const
	{
		return down;
	}

	int Room::getRole() const
	{
		return roomRole;
	}

	void Room::setOwner(const std::string & owner)
	{
		this->owner = owner;
		tweetOwner.setFont(*tweetFont);
		tweetOwner.setString("@" + this->owner);
		tweetOwner.setCharacterSize(20);
		tweetOwner.setPosition(sf::Vector2f(175, Application::SCREEN_HEIGHT - 170));
		tweetOwner.setFillColor(sf::Color::Black);
	}

	void Room::customizeRoom(int spriteSheet)
	{
		Identifier* inRoom = nullptr;
		int size = TweetAnalyser::getInRoom(tweet, inRoom);

		eh.setStructureProperty(roomRole, spriteSheet);
		eh.createEntities(inRoom, size);
		//remove this delete and move it into EH destructor
		delete[] inRoom;
	}

	void Room::setSpriteArray(sf::Sprite ** array)
	{
		sf::Sprite** newArray = new sf::Sprite*[20];
		for (int i = 0; i < 20; i++)
		{
			newArray[i] = new sf::Sprite[11];
			for (int j = 0; j < 11; j++)
			{
				newArray[i][j] = array[i][j];
			}
		}
		spritesArray = newArray;
	}

	void Room::update(float dt)
	{
		eh.update(dt);
		
	}

	bool* Room::getDoorStatus() const
	{
		bool doors[4];
		doors[0] = (up != nullptr);
		doors[1] = (right != nullptr);
		doors[2] = (down != nullptr);
		doors[3] = (left != nullptr);
		return doors;
	}

	sf::RectangleShape Room::getMap() const
	{
		float x = 50.0f;
		float y = 28.0f;

		sf::RectangleShape map(sf::Vector2f(x, y));
		map.setPosition(sf::Vector2f(this->coord.x * x + Application::SCREEN_WIDTH * 0.853, this->coord.y * y + Application::SCREEN_HEIGHT * 0.22));
		map.setFillColor(sf::Color(0, 0, 0, 0));
		map.setOutlineThickness(-3.0f);
		map.setOutlineColor(sf::Color(0, 0, 0, 0));
		

		return map;
	}

	void Room::setDiscovered()
	{
		discovered = true;
	}

	bool Room::isDiscovered() const
	{
		return discovered;
	}

	void Room::giveEhLog(Log * gameLog)
	{
		this->eh.setLog(gameLog);
	}

	void Room::deleteSpriteArray()
	{
		for (int x = 0; x < 20; x++)
		{
			delete[] spritesArray[x];
		}
		delete[] spritesArray;
	}

	void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		
		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 11; y++)
			{
				target.draw(spritesArray[x][y]);

			}

		}

		eh.render(target);

		target.draw(currentTweet);
		target.draw(tweetOwner);

		/*if(down != nullptr) target.draw(doorDown);
		if(up != nullptr) target.draw(doorUp);
		if (right != nullptr) target.draw(doorRight);
		if (left != nullptr) 	target.draw(doorLeft);*/
	}

}
