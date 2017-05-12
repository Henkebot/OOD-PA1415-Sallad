#include "Cave.h"
#include "../UserInterface/Application.h"
#include <iostream>
namespace Container
{
	void Cave::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(*currentRoom);
	}

	void Cave::connectRoom(Room * rootRoom, int role, int lastRoom)
	{
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

				for (int i = 0; i < roomPointers.size() && !overlapingRoom; i++)
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
					Room* newRoom = new Room(numberOfRooms++, role);
					newRoom->setCoord(newRoomCoord);
					rootRoom->setUpD(newRoom);
					newRoom->setDownD(rootRoom);
					roomPointers.push_back(newRoom);
				}
			}
			else
				connectRoom(rootRoom->getUpD(),role, door);
			break;
		case 1:
			if (rootRoom->getRightD() == nullptr)
			{
				sf::Vector2i rootRoomCoord = rootRoom->getCoord();
				sf::Vector2i newRoomCoord(sf::Vector2i(rootRoomCoord.x + 1, rootRoomCoord.y));

				bool overlapingRoom = false;
				int overlapingRoomIndex = -1;

				for (int i = 0; i < roomPointers.size() && !overlapingRoom; i++)
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
					Room* newRoom = new Room(numberOfRooms++, role);
					newRoom->setCoord(newRoomCoord);
					rootRoom->setRightD(newRoom);
					newRoom->setLeftD(rootRoom);
					roomPointers.push_back(newRoom);
				}
			}
			else
				connectRoom(rootRoom->getRightD(),role, door);
			
			break;
		case 2:
			if (rootRoom->getDownD() == nullptr)
			{
				sf::Vector2i rootRoomCoord = rootRoom->getCoord();
				sf::Vector2i newRoomCoord(sf::Vector2i(rootRoomCoord.x, rootRoomCoord.y + 1));
				bool overlapingRoom = false;
				int overlapingRoomIndex = -1;

				for (int i = 0; i < roomPointers.size() && !overlapingRoom; i++)
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
					Room* newRoom = new Room(numberOfRooms++, role);
					newRoom->setCoord(newRoomCoord);
					rootRoom->setDownD(newRoom);
					newRoom->setUpD(rootRoom);
					roomPointers.push_back(newRoom);
				}
			}
			else
				connectRoom(rootRoom->getDownD(),role, door);
			break;
		case 3:
			if (rootRoom->getLeftD() == nullptr)
			{
				sf::Vector2i rootRoomCoord = rootRoom->getCoord();
				sf::Vector2i newRoomCoord(sf::Vector2i(rootRoomCoord.x - 1, rootRoomCoord.y));

				bool overlapingRoom = false;
				int overlapingRoomIndex = -1;

				for (int i = 0; i < roomPointers.size() && !overlapingRoom; i++)
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
					Room* newRoom = new Room(numberOfRooms++, role);
					newRoom->setCoord(newRoomCoord);
					rootRoom->setLeftD(newRoom);
					newRoom->setRightD(rootRoom);
					roomPointers.push_back(newRoom);
				}
			}
			else
				connectRoom(rootRoom->getLeftD(),role, door);
			break;
		}

	}

	Cave::Cave()
	{
		tiles = new sf::Texture();
		if (tiles->loadFromFile(".\\textures\\sheet.png"))
			std::cout << "Failed to load file!" << std::endl;
		numberOfRooms = 0;
	}

	Cave::~Cave()
	{
		
		int oldSize = roomPointers.size();
		for (int i = 0; i < oldSize; i++)
		{
			delete roomPointers.at(i);
		}

		delete tiles;
	}

	void Cave::generateCave()
	{
		currentRoom = new Room(numberOfRooms++, 1);
		currentRoom->setCoord(sf::Vector2i(0, 0));
		roomPointers.push_back(currentRoom);
		for (int i = 0; i < 400; i++)
		{
			connectRoom(currentRoom,0);
		}
		connectRoom(currentRoom, 2);



		//Sprite Stuff

		sf::Sprite** spriteArray = new sf::Sprite*[20];
		for (int i = 0; i < 20; i++)
		{
			spriteArray[i] = new sf::Sprite[11];
		}
		setSprite(spriteArray, 0, 0, 0, 0); // VÄNSTER UPP HÖRN
		for (int i = 1; i < 19; i++) // TOPPEN
		{
			setSprite(spriteArray, i, 0, 1, 0);
		}
		setSprite(spriteArray, 19, 0, 2, 0); // HÖGER UPP HÖRN
		for (int i = 1; i < 10; i++) // VÄNSTER
		{
			setSprite(spriteArray, 0, i, 0, 1);
		}
		for (int i = 1; i < 10; i++) // HÖGER
		{
			setSprite(spriteArray, 19, i, 2, 1);
		}
		for (int x = 1; x < 19; x++) // MITTEN
		{
			for (int y = 1; y < 10; y++)
			{
				setSprite(spriteArray, x, y, 1, 1);
			}
		}
		for (int i = 0; i < 20; i++) // BOTTEN
		{
			setSprite(spriteArray, i, 10, 0, 2);
		}



		for (int i = 0; i < roomPointers.size(); i++)
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
		EntityHandler* currentEntityHandler = new EntityHandler();
		currentRoom->setEh(currentEntityHandler);

	}

	bool Cave::selectTwitterFeed(const std::string & URL)
	{
		return false;
	}
	void Cave::setSprite(sf::Sprite** spritesArray, int xIndex, int yIndex, int xSheet, int ySheet)
	{
		spritesArray[xIndex][yIndex].setTexture(*tiles);
		spritesArray[xIndex][yIndex].setTextureRect(sf::IntRect(xSheet*64, ySheet* 64, 64, 64));
		spritesArray[xIndex][yIndex].setPosition(sf::Vector2f(64 * xIndex, 64 * yIndex));

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
		
		
		Player* playerPos = currentRoom->getCurrentEntityHandler()->getPlayer();
		//DOOR LEFT (0,5)
		if ((playerPos->getCoords().x / 64) == 0 && (playerPos->getCoords().y / 64) == 5 && 
			currentRoom->getLeftD() != nullptr)
		{
			EntityHandler* currentH = currentRoom->getCurrentEntityHandler();
			currentRoom = currentRoom->getLeftD();
			currentRoom->setEh(currentH);
			currentRoom->getCurrentEntityHandler()->getPlayer()->setCoords(sf::Vector2f(18*64, 5*64));
			
		} //DOOR UP: (10,0)
		else if ((playerPos->getCoords().x / 64) == 10 && (playerPos->getCoords().y / 64) == 0 &&
			currentRoom->getUpD() != nullptr)
		{
			EntityHandler* currentH = currentRoom->getCurrentEntityHandler();
			currentRoom = currentRoom->getUpD();
			currentRoom->setEh(currentH);
			currentRoom->getCurrentEntityHandler()->getPlayer()->setCoords(sf::Vector2f(10 * 64, 9 * 64));
		}//DOOR RIGHT: (19,5)
		else if ((playerPos->getCoords().x / 64) == 19 && (playerPos->getCoords().y / 64) == 5 &&
			currentRoom->getRightD() != nullptr)
		{
			EntityHandler* currentH = currentRoom->getCurrentEntityHandler();
			currentRoom = currentRoom->getRightD();
			currentRoom->setEh(currentH);
			currentRoom->getCurrentEntityHandler()->getPlayer()->setCoords(sf::Vector2f(1 * 64, 5 * 64));
		}//DOOR DOWN: (10,10)
		else if ((playerPos->getCoords().x / 64) == 10 && (playerPos->getCoords().y / 64) == 10 &&
			currentRoom->getDownD() != nullptr)
		{
			EntityHandler* currentH = currentRoom->getCurrentEntityHandler();
			currentRoom = currentRoom->getDownD();
			currentRoom->setEh(currentH);
			currentRoom->getCurrentEntityHandler()->getPlayer()->setCoords(sf::Vector2f(10 * 64, 1 * 64));
		}
		
	}
}

