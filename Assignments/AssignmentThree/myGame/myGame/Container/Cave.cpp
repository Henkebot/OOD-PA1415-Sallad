#include "Cave.h"
#include "../UserInterface/Application.h"
#include "../Utility/Values.h"
#include <iostream>
namespace Container
{
	const float doorLeftX		= 0;
	const float doorLeftY		= 5;

	const float doorUpX			= 10;
	const float doorUpY			= 0;

	const float doorRightX		= 19;
	const float doorRightY		= 5;

	const float doorDownX		= 10;
	const float doorDownY		= 10;



	void Cave::applyRoomTextures()
	{
		sf::Sprite** spriteArray = new sf::Sprite*[20];

		for (int i = 0; i < Val::ROOM_WIDTH; i++)
		{
			spriteArray[i] = new sf::Sprite[11];

		}
		for (int i = 0; i < Val::ROOM_WIDTH; i++)
		{
			for (int j = 0; j < Val::ROOM_HEIGHT; j++)
			{
				spriteArray[i][j].scale(Val::SCALE, Val::SCALE);
			}
		}
		for (unsigned i = 0; i < roomPointers.size(); i++)
		{
			tilesNumber = rand() % 3;

			setSprite(spriteArray, 0, 0, 0, 0); // V�NSTER UPP H�RN
			for (float i = 1; i < Val::ROOM_WIDTH - 1; i++) // TOPPEN
			{
				setSprite(spriteArray, i, 0.0f, 1, 0);
			}
			setSprite(spriteArray, Val::ROOM_WIDTH - 1, 0, 2, 0); // H�GER UPP H�RN
			for (float i = 1; i < Val::ROOM_HEIGHT - 1; i++) // V�NSTER
			{
				setSprite(spriteArray, 0, i, 0, 1);
			}
			for (float i = 1; i < Val::ROOM_HEIGHT - 1; i++) // H�GER
			{
				setSprite(spriteArray, Val::ROOM_WIDTH - 1, i, 2, 1);
			}
			
			for (float i = 0; i < Val::ROOM_WIDTH; i++) // BOTTEN
			{
				setSprite(spriteArray, i, Val::ROOM_HEIGHT - 1, 0, 2);
			}

			//Ladders
			if (roomPointers.at(i)->getRole() == 1)
			{
				setSprite(spriteArray, Val::ROOM_HEIGHT - 1, 5, 3, 1);
				setSprite(spriteArray, Val::ROOM_HEIGHT - 1, 6, 3, 2);
			}
			else
			{
				setSprite(spriteArray, Val::ROOM_HEIGHT - 1, 5, 1, 1);
				setSprite(spriteArray, Val::ROOM_HEIGHT - 1, 6, 1, 1);
			}

			if (roomPointers.at(i)->getRole() == 2)
				setSprite(spriteArray, 5, 5, 3, 3);
			else
				setSprite(spriteArray, 5, 5, 1, 1);


			//DOORS
			if (roomPointers.at(i)->getLeftD() != nullptr)
				setSprite(spriteArray, 0, 5, 1, 2);
			else
				setSprite(spriteArray, 0, 5, 0, 1);

			if (roomPointers.at(i)->getUpD() != nullptr)
				setSprite(spriteArray, Val::ROOM_HEIGHT - 1, 0, 2, 2);
			else
				setSprite(spriteArray, Val::ROOM_HEIGHT - 1, 0, 1, 0);

			if (roomPointers.at(i)->getRightD() != nullptr)
				setSprite(spriteArray, Val::ROOM_WIDTH - 1, 5, 3, 0);
			else
				setSprite(spriteArray, Val::ROOM_WIDTH - 1, 5, 2, 1);

			if (roomPointers.at(i)->getDownD() != nullptr)
			{
				setSprite(spriteArray, 9, 10, 0, 3);
				setSprite(spriteArray, 10, 10, 1, 3);
				setSprite(spriteArray, 11, 10, 2, 3);
			}
			else
			{
				setSprite(spriteArray, 9, 10, 0, 2);
				setSprite(spriteArray, 10, 10, 0, 2);
				setSprite(spriteArray, 11, 10, 0, 2);
			}
			roomPointers.at(i)->customizeRoom(tilesNumber);
			roomPointers.at(i)->setSpriteArray(spriteArray);

			roomPointers[i]->giveEhLog(gameLog);

		}
		for (int i = 0; i < 20; i++)
		{
			delete[] spriteArray[i];
		}
		delete[] spriteArray;
	}

	void Cave::changeRoom(Room * newRoom, int startX, int startY)
	{
		Player* currentPlayer = currentRoom->getCurrentEntityHandler().getPlayer();
		currentRoom = newRoom;
		currentRoom->getCurrentEntityHandler().setPlayer(currentPlayer);
		currentRoom->getCurrentEntityHandler().getPlayer()->setCoords(sf::Vector2f(startX * Val::SPRITE_SIZE * Val::SCALE, startY * Val::SPRITE_SIZE * Val::SCALE));
		currentRoom->getCurrentEntityHandler().setDoors(currentRoom->getDoorStatus());
	}

	void Cave::checkDoors()
	{
		Player* playerPos = currentRoom->getCurrentEntityHandler().getPlayer();
		//DOOR LEFT (0,5)
		if ((playerPos->getCoords().x / (Val::SPRITE_SIZE * Val::SCALE)) == doorLeftX && (playerPos->getCoords().y / (Val::SPRITE_SIZE * Val::SCALE)) == doorLeftY &&
			currentRoom->getLeftD() != nullptr)
		{
			changeRoom(currentRoom->getLeftD(), 18, 5);
			updateMiniMap(1, 0);

		} //DOOR UP: (10,0)
		else if ((playerPos->getCoords().x / (Val::SPRITE_SIZE * Val::SCALE)) == doorUpX && (playerPos->getCoords().y / (Val::SPRITE_SIZE * Val::SCALE)) == doorUpY &&
			currentRoom->getUpD() != nullptr)
		{
			changeRoom(currentRoom->getUpD(), 10, 9);
			updateMiniMap(0, 1);
		}//DOOR RIGHT: (19,5)
		else if ((playerPos->getCoords().x / (Val::SPRITE_SIZE * Val::SCALE)) == doorRightX && (playerPos->getCoords().y / (Val::SPRITE_SIZE * Val::SCALE)) == doorRightY &&
			currentRoom->getRightD() != nullptr)
		{
			changeRoom(currentRoom->getRightD(), 1, 5);
			updateMiniMap(-1, 0);
		}//DOOR DOWN: (10,10)
		else if ((playerPos->getCoords().x / (Val::SPRITE_SIZE * Val::SCALE)) == doorDownX && (playerPos->getCoords().y / (Val::SPRITE_SIZE * Val::SCALE)) == doorDownX &&
			currentRoom->getDownD() != nullptr)
		{
			changeRoom(currentRoom->getDownD(), 10, 1);
			updateMiniMap(0, -1);
		}

	}

	void Cave::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		for (int i = 0; i < aMap.size(); i++)
		{
			target.draw(aMap.at(i));
		}
		target.draw(*currentRoom);
	}

	bool Cave::connectRoom(Room * rootRoom, int role, int lastRoom)
	{
		bool newRoomCreated = false;
		int door = rand() % 4;
		// 0 = up
		// 1 = right
		// 2 = down
		// 3 = left
		while (door == lastRoom) door = rand() % 4;
		switch (door)
		{
		case 0:
			if (rootRoom->getUpD() == nullptr)
			{
				sf::Vector2i rootRoomCoord = rootRoom->getCoord();
				sf::Vector2i newRoomCoord(sf::Vector2i(rootRoomCoord.x, rootRoomCoord.y - 1));

				bool overlapingRoom = false;
				int overlapingRoomIndex = -1;

				for (unsigned i = 0; i < roomPointers.size() && !overlapingRoom; i++)
				{
					if (roomPointers.at(i)->getCoord() == newRoomCoord)
					{
						overlapingRoom = true;
						overlapingRoomIndex = i;
					}
				}

				if (overlapingRoom)
				{
					rootRoom->setUpD(roomPointers.at(overlapingRoomIndex));
					roomPointers.at(overlapingRoomIndex)->setDownD(rootRoom);
				}
				else
				{
					Room* newRoom = new Room(twitterObj.getRandomTweet(), role);
					newRoom->setCoord(newRoomCoord);
					newRoom->setOwner(twitterObj.getUser());
					rootRoom->setUpD(newRoom);
					newRoom->setDownD(rootRoom);
					roomPointers.push_back(newRoom);
					newRoomCreated = true;
				}
			}
			else
				newRoomCreated = connectRoom(rootRoom->getUpD(),role, door);
			break;
		case 1:
			if (rootRoom->getRightD() == nullptr)
			{
				sf::Vector2i rootRoomCoord = rootRoom->getCoord();
				sf::Vector2i newRoomCoord(sf::Vector2i(rootRoomCoord.x + 1, rootRoomCoord.y));

				bool overlapingRoom = false;
				int overlapingRoomIndex = -1;

				for (unsigned i = 0; i < roomPointers.size() && !overlapingRoom; i++)
				{
					if (roomPointers.at(i)->getCoord() == newRoomCoord)
					{
						overlapingRoom = true;
						overlapingRoomIndex = i;
					}
				}

				if (overlapingRoom)
				{
					rootRoom->setRightD(roomPointers.at(overlapingRoomIndex));
					roomPointers.at(overlapingRoomIndex)->setLeftD(rootRoom);
				}
				else
				{
					Room* newRoom = new Room(twitterObj.getRandomTweet(), role);
					newRoom->setCoord(newRoomCoord);
					newRoom->setOwner(twitterObj.getUser());
					rootRoom->setRightD(newRoom);
					newRoom->setLeftD(rootRoom);
					roomPointers.push_back(newRoom);
					newRoomCreated = true;
				}
			}
			else
				newRoomCreated = connectRoom(rootRoom->getRightD(),role, door);
			
			break;
		case 2:
			if (rootRoom->getDownD() == nullptr)
			{
				sf::Vector2i rootRoomCoord = rootRoom->getCoord();
				sf::Vector2i newRoomCoord(sf::Vector2i(rootRoomCoord.x, rootRoomCoord.y + 1));
				bool overlapingRoom = false;
				int overlapingRoomIndex = -1;

				for (unsigned i = 0; i < roomPointers.size() && !overlapingRoom; i++)
				{
					if (roomPointers.at(i)->getCoord() == newRoomCoord)
					{
						overlapingRoom = true;
						overlapingRoomIndex = i;
					}
				}

				if (overlapingRoom)
				{
					rootRoom->setDownD(roomPointers.at(overlapingRoomIndex));
					roomPointers.at(overlapingRoomIndex)->setUpD(rootRoom);
				}
				else
				{
					Room* newRoom = new Room(twitterObj.getRandomTweet(), role);
					newRoom->setCoord(newRoomCoord);
					newRoom->setOwner(twitterObj.getUser());
					rootRoom->setDownD(newRoom);
					newRoom->setUpD(rootRoom);
					roomPointers.push_back(newRoom);
					newRoomCreated = true;
				}
			}
			else
				newRoomCreated = connectRoom(rootRoom->getDownD(),role, door);
			break;
		case 3:
			if (rootRoom->getLeftD() == nullptr)
			{
				sf::Vector2i rootRoomCoord = rootRoom->getCoord();
				sf::Vector2i newRoomCoord(sf::Vector2i(rootRoomCoord.x - 1, rootRoomCoord.y));

				bool overlapingRoom = false;
				int overlapingRoomIndex = -1;

				for (unsigned i = 0; i < roomPointers.size() && !overlapingRoom; i++)
				{
					if (roomPointers.at(i)->getCoord() == newRoomCoord)
					{
						overlapingRoom = true;
						overlapingRoomIndex = i;
					}
				}

				if (overlapingRoom)
				{
					rootRoom->setLeftD(roomPointers.at(overlapingRoomIndex));
					roomPointers.at(overlapingRoomIndex)->setRightD(rootRoom);
				}
				else
				{
					Room* newRoom = new Room(twitterObj.getRandomTweet(), role);
					newRoom->setCoord(newRoomCoord);
					newRoom->setOwner(twitterObj.getUser());
					rootRoom->setLeftD(newRoom);
					newRoom->setRightD(rootRoom);
					roomPointers.push_back(newRoom);
					newRoomCreated = true;
				}
			}
			else
				newRoomCreated = connectRoom(rootRoom->getLeftD(),role, door);
			break;
		}
		return newRoomCreated;
	}

	void Cave::importMap()
	{
		for (int i = 0; i < roomPointers.size(); i++)
		{
			aMap.push_back(roomPointers.at(i)->getMap());
		}


		aMap.at(0).setFillColor(sf::Color(128, 247, 101, 255));
		aMap.at(0).setOutlineColor(sf::Color(42, 81, 34, 255));
	}

	void Cave::updateMiniMap(int xDir, int yDir)
	{

		for (int i = 0; i < aMap.size(); i++)
		{
			aMap[i].setPosition(sf::Vector2f(aMap[i].getPosition().x + (aMap[i].getSize().x * xDir), aMap[i].getPosition().y + (aMap[i].getSize().y * yDir)));
		}


		for (int i = 0; i < roomPointers.size(); i++)
		{

			if (i != 0 && roomPointers[i]->isDiscovered())
			{
				aMap[i].setFillColor(sf::Color(188, 188, 181, 155));
				aMap[i].setOutlineColor(sf::Color(89, 88, 64, 255));
			}
			if (currentRoom == roomPointers[i])
			{
				if(i != 0)
					aMap.at(0).setOutlineColor(sf::Color(42, 81, 34, 255));
				aMap[i].setFillColor(sf::Color(188, 188, 181, 155));
				if (!currentRoom->isDiscovered())
				{
					currentRoom->setDiscovered();
					gameLog->addMessage("Discovered a new room!");
				}
				
				aMap.at(i).setOutlineColor(sf::Color(168, 166, 74, 255));
			}



		}

		aMap.at(0).setFillColor(sf::Color(128, 247, 101, 255));
	
	}

	Cave::Cave()
	{
		tilesNumber = 0;
		tiles1 = new sf::Texture();
		if (!tiles1->loadFromFile(".\\textures\\sheet.png"))
			std::cout << "Failed to load spritesheet!" << std::endl;
		tiles2 = new sf::Texture();
		if (!tiles2->loadFromFile(".\\textures\\sheet2.png"))
			std::cout << "Failed to load spritesheet!" << std::endl;
		tiles3 = new sf::Texture();
		if (!tiles3->loadFromFile(".\\textures\\sheet3.png"))
			std::cout << "Failed to load spritesheet!" << std::endl;
		

	}

	Cave::~Cave()
	{
		currentRoom->getCurrentEntityHandler().destroyPlayer();
		int oldSize = roomPointers.size();
		for (int i = 0; i < oldSize; i++)
		{
			delete roomPointers.at(i);
		}

		delete tiles1;
	}

	void Cave::generateCave()
	{
		

		currentRoom = new Room(twitterObj.getRandomTweet(), 1);
		currentRoom->setCoord(sf::Vector2i(0, 0));
		currentRoom->setOwner(twitterObj.getUser());
		roomPointers.push_back(currentRoom);
		for (int i = 0; i < twitterObj.getNumberOfTweets() - 2; i++)
		{
			connectRoom(currentRoom,0);
		}
		bool lastRoomCreated = false;
		while (!lastRoomCreated) lastRoomCreated = connectRoom(currentRoom, 2);


		importMap();

		applyRoomTextures();

		Texture* texture = new Texture();
		texture->loadFromFile(".\\textures\\playerCool.png");

		Player* player = new Player(texture, sf::Vector2f((Val::SPRITE_SIZE*Val::SCALE)*6, 5 * (Val::SPRITE_SIZE * Val::SCALE)));

		currentRoom->getCurrentEntityHandler().setPlayer(player);
		currentRoom->getCurrentEntityHandler().setDoors(currentRoom->getDoorStatus());
		currentRoom->setDiscovered();

	}

	bool Cave::selectTwitterFeed(const std::string & user)
	{
		bool result = twitterObj.authenticate();
		if (result)
		{
			int max = rand() % 200;
			while (max == 1 || max == 2)
			{
				max = rand() % 200;
			}
			twitterObj.readFeed(user, max);
		}
		return result;
	}
	void Cave::setSprite(sf::Sprite** spritesArray, float xIndex, float yIndex, int xSheet, int ySheet)
	{
		int xDex = static_cast<int>(xIndex);
		int yDex = static_cast<int>(yIndex);
	
		if(tilesNumber == 0)
			spritesArray[xDex][yDex].setTexture(*tiles1);
		else if(tilesNumber == 1)
			spritesArray[xDex][yDex].setTexture(*tiles2);
		else
			spritesArray[xDex][yDex].setTexture(*tiles3);
		spritesArray[xDex][yDex].setTextureRect(sf::IntRect(xSheet*Val::SPRITE_SIZE, ySheet* Val::SPRITE_SIZE, Val::SPRITE_SIZE, Val::SPRITE_SIZE));
		spritesArray[xDex][yDex].setPosition(sf::Vector2f(Val::SPRITE_SIZE * xIndex * Val::SCALE, Val::SPRITE_SIZE * yIndex * Val::SCALE));

	}
	void Cave::update(float dt)
	{
		currentRoom->update(dt);
		checkDoors();
	}
	void Cave::setLog(Log * gameLog)
	{
		this->gameLog = gameLog;
	}
}

