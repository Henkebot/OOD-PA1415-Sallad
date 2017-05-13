#include "Cave.h"
#include "../UserInterface/Application.h"
#include <iostream>
namespace Container
{
	const float Cave::SCALE		= 0.75f;

	const float doorLeftX		= 0;
	const float doorLeftY		= 5;

	const float doorUpX			= 10;
	const float doorUpY			= 0;

	const float doorRightX		= 19;
	const float doorRightY		= 5;

	const float doorDownX		= 10;
	const float doorDownY		= 10;


	void Cave::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
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

	Cave::Cave()
	{
		tiles = new sf::Texture();
		if (!tiles->loadFromFile(".\\textures\\sheet.png"))
			std::cout << "Failed to load spritesheet!" << std::endl;
		numberOfRooms = 0;
	}

	Cave::~Cave()
	{
		currentRoom->getCurrentEntityHandler().destroyPlayer();
		int oldSize = roomPointers.size();
		for (int i = 0; i < oldSize; i++)
		{
			delete roomPointers.at(i);
		}

		delete tiles;
	}

	void Cave::generateCave()
	{
		currentRoom = new Room(twitterObj.getRandomTweet(), 1);
		currentRoom->setCoord(sf::Vector2i(0, 0));

		roomPointers.push_back(currentRoom);
		for (int i = 0; i < twitterObj.getNumberOfTweets() - 2; i++)
		{
			connectRoom(currentRoom,0);
		}
		bool lastRoomCreated = false;
		while (!lastRoomCreated) lastRoomCreated = connectRoom(currentRoom, 2);



		//Sprite Stuff

		sf::Sprite** spriteArray = new sf::Sprite*[20];
		
		for (int i = 0; i < 20; i++)
		{
			spriteArray[i] = new sf::Sprite[11];
	
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				spriteArray[i][j].scale(SCALE, SCALE);
			}
		}
	
		setSprite(spriteArray, 0, 0, 0, 0); // VÄNSTER UPP HÖRN
		for (float i = 1; i < 19; i++) // TOPPEN
		{
			setSprite(spriteArray, i, 0.0f, 1, 0);
		}
		setSprite(spriteArray, 19, 0, 2, 0); // HÖGER UPP HÖRN
		for (float i = 1; i < 10; i++) // VÄNSTER
		{
			setSprite(spriteArray, 0, i, 0, 1);
		}
		for (float i = 1; i < 10; i++) // HÖGER
		{
			setSprite(spriteArray, 19, i, 2, 1);
		}
		for (float x = 1; x < 19; x++) // MITTEN
		{
			for (float y = 1; y < 10; y++)
			{
				setSprite(spriteArray, x, y, 1, 1);
			}
		}
		for (float i = 0; i < 20; i++) // BOTTEN
		{
			setSprite(spriteArray, i, 10, 0, 2);
		}



		for (unsigned i = 0; i < roomPointers.size(); i++)
		{

			//Ladders
			if (roomPointers.at(i)->getRole() == 1)
			{
				setSprite(spriteArray, 10, 5, 3, 1);
				setSprite(spriteArray, 10, 6, 3, 2);
			}
			else
			{
				setSprite(spriteArray, 10, 5, 1, 1);
				setSprite(spriteArray, 10, 6, 1, 1);
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
				setSprite(spriteArray, 10, 0, 2, 2);
			else
				setSprite(spriteArray, 10, 0, 1, 0);

			if (roomPointers.at(i)->getRightD() != nullptr)
				setSprite(spriteArray, 19, 5, 3, 0);
			else
				setSprite(spriteArray, 19, 5, 2, 1);

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
			roomPointers.at(i)->setSpriteArray(spriteArray);

		}



		for (int i = 0; i < 20; i++)
		{
			delete[] spriteArray[i];
		}
		delete[] spriteArray;
		//DISKUTERA DENNA
		Texture* texture = new Texture();
		texture->loadFromFile(".\\textures\\player.png");
		Player* player = new Player(texture);
		currentRoom->getCurrentEntityHandler().setPlayer(player);

	}

	bool Cave::selectTwitterFeed(const std::string & URL)
	{
		bool result = twitterObj.authenticate();
		if (result)
		{
			twitterObj.readFeed();
		}
		return result;
	}
	void Cave::setSprite(sf::Sprite** spritesArray, float xIndex, float yIndex, int xSheet, int ySheet)
	{
		int xDex = static_cast<int>(xIndex);
		int yDex = static_cast<int>(yIndex);
		spritesArray[xDex][yDex].setTexture(*tiles);
		spritesArray[xDex][yDex].setTextureRect(sf::IntRect(xSheet*64, ySheet* 64, 64, 64));
		spritesArray[xDex][yDex].setPosition(sf::Vector2f(64 * xIndex * SCALE, 64 * yIndex * SCALE));

	}
	void Cave::update(float dt)
	{
		/*if (InputManager::keyPressed(sf::Keyboard::A))
			currentRoom = currentRoom->getLeftD();
		if (InputManager::keyPressed(sf::Keyboard::D))
			currentRoom = currentRoom->getRightD();
		if (InputManager::keyPressed(sf::Keyboard::S))
			currentRoom = currentRoom->getDownD();
		if (InputManager::keyPressed(sf::Keyboard::W))
			currentRoom = currentRoom->getUpD();*/
		currentRoom->update(dt);

		
		// Förändringar inkomming
		
		
		Player* playerPos = currentRoom->getCurrentEntityHandler().getPlayer();
		//DOOR LEFT (0,5)
		if ((playerPos->getCoords().x / (64 * SCALE)) == doorLeftX && (playerPos->getCoords().y / (64 * SCALE)) == doorLeftY &&
			currentRoom->getLeftD() != nullptr)
		{
			Player* currentPlayer = currentRoom->getCurrentEntityHandler().getPlayer();
			currentRoom = currentRoom->getLeftD();
			currentRoom->getCurrentEntityHandler().setPlayer(currentPlayer);
			currentRoom->getCurrentEntityHandler().getPlayer()->setCoords(sf::Vector2f(18*64*SCALE, 5*64*SCALE));
			
		} //DOOR UP: (10,0)
		else if ((playerPos->getCoords().x / (64 * SCALE)) == doorUpX && (playerPos->getCoords().y / (64 * SCALE)) == doorUpY &&
			currentRoom->getUpD() != nullptr)
		{
			Player* currentPlayer = currentRoom->getCurrentEntityHandler().getPlayer();
			currentRoom = currentRoom->getUpD();
			currentRoom->getCurrentEntityHandler().setPlayer(currentPlayer);
			currentRoom->getCurrentEntityHandler().getPlayer()->setCoords(sf::Vector2f(10 * 64*SCALE, 9 * 64*SCALE));
		}//DOOR RIGHT: (19,5)
		else if ((playerPos->getCoords().x / (64 * SCALE)) == doorRightX && (playerPos->getCoords().y / (64 * SCALE)) == doorRightY &&
			currentRoom->getRightD() != nullptr)
		{
			Player* currentPlayer = currentRoom->getCurrentEntityHandler().getPlayer();
			currentRoom = currentRoom->getRightD();
			currentRoom->getCurrentEntityHandler().setPlayer(currentPlayer);
			currentRoom->getCurrentEntityHandler().getPlayer()->setCoords(sf::Vector2f(1 * 64*SCALE, 5 * 64*SCALE));
		}//DOOR DOWN: (10,10)
		else if ((playerPos->getCoords().x / (64 * SCALE)) == doorDownX && (playerPos->getCoords().y / (64 * SCALE)) == doorDownX &&
			currentRoom->getDownD() != nullptr)
		{
			Player* currentPlayer = currentRoom->getCurrentEntityHandler().getPlayer();
			currentRoom = currentRoom->getDownD();
			currentRoom->getCurrentEntityHandler().setPlayer(currentPlayer);
			currentRoom->getCurrentEntityHandler().getPlayer()->setCoords(sf::Vector2f(10 * 64*SCALE, 1 * 64*SCALE));
		}
		
	}
}

