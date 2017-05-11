#include "EntityHandler.h"
using namespace Container;

EntityHandler::EntityHandler()
{
	player = new Player(nullptr, Vector2f(0, 0));
	extraCon();
}
EntityHandler::EntityHandler(Vector2f playerCoords)
{
	player = new Player(nullptr, playerCoords);
	extraCon();
}
EntityHandler::EntityHandler(Player* player)
{
	this->player = player;
	extraCon();
}
EntityHandler::EntityHandler(Player* player, Vector2f playerCoords)
{
	this->player = player;
	player->setCoords(playerCoords);
	extraCon();
}

void EntityHandler::extraCon()
{
	playersTurn = true;
}

EntityHandler::~EntityHandler()
{
	delete player;
	for (int i = 0; i < nrOfEnemys; i++)
	{
		delete enemys[i];
	}
	delete enemys;

	for (int i = 0; i < nrOfStructures; i++)
	{
		delete structures[i];
	}
	delete structures;

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			delete floor[i][j];
		}
	}
}

void EntityHandler::update(float dt)
{
	if (playersTurn == true)
	{
		handleInput();
	}
	else
	{
		Vector2f playerCoords = player->getCoords();
		for (int i = 0; i < nrOfEnemys; i++)
		{
			enemys[i]->update(dt, playerCoords);
			/*if (enemys[i]->getState() == attack)
			{
				Stats enemyStat = enemys[i]->getStats();
				Stats playerStat = player->getStats();

				float dmg = calculateDmg(enemyStat, playerStat);

				player->setHealth(player->getHealth()-dmg);
			}
			else if (enemys[i]->getState() == move)
			{
				Vector2f requestedCoords = enemys[i]->moveRequest();
				bool floor = isFloor(requestedCoords);
				bool col = false;
				for (int j = 0; j < nrOfEnemys && col == false; j++)
				{
					Vector2f otherCoords = enemys[j]->getCoords();
					//col = ColLisionHandler::isCol(requestedCoords, otherCoords);
				}
				for (int j = 0; j < nrOfStructures && col == false; j++)
				{
					Vector2f otherCoords = structures[j]->getCoords();
					//col = ColLisionHandler::isCol(requestedCoords, otherCoords);
				}
				enemys[i]->setPos(requestedCoords);
			}*/
		}
	}
}

void EntityHandler::handleInput()
{
	if (InputManager::keyPressed(sf::Keyboard::Q))
	{
		playerAttack();
	}
	else if (InputManager::keyPressed(sf::Keyboard::E))
	{
		playerInteract();
	}
	else if (InputManager::keyPressed(sf::Keyboard::Space))
	{
		playerMove();
	}
	else if (InputManager::keyPressed(sf::Keyboard::W))
	{
		playerTurnUp();
	}
	else if (InputManager::keyPressed(sf::Keyboard::A))
	{
		playerTurnLeft();
	}
	else if (InputManager::keyPressed(sf::Keyboard::S))
	{
		playerTurnDown();
	}
	else if (InputManager::keyPressed(sf::Keyboard::D))
	{
		playerTurnRight();
	}
}

void EntityHandler::playerAttack()
{
	Vector2f attackCoord = player->attack();
	bool col = false;
	for (int i = 0; i < nrOfEnemys && col == false; i++)
	{
		Vector2f enemyCoord = enemys[i]->getCoords();

		//col = ColLisionHandler::isCol(attackCoord, enemyCoord);
		/*if (col == true)
		{
			Stats enemyStat = enemys[i]->getStats();
			Stats playerStat = player->getStats();

			float dmg = calculateDmg(playerStat, enemyStat);

			enemys[i]->setHealth(player->getHealth() - dmg);
		}*/
	}
	for (int i = 0; i < nrOfStructures && col == false; i++)
	{
		Vector2f structureCoord = structures[i]->getCoords();

		//col = ColLisionHandler::isCol(attackCoord, enemyCoord);
		/*if (col == true)
		{
			Stats structureStat = structures[i]->getStats();
			Stats playerStat = player->getStats();

			float dmg = calculateDmg(playerStat, enemyStat);

			Vector2f enemyCoord = structures[i]->getCoords();
			structures[i]->setHealth(player->getHealth() - dmg);
		}*/
	}
}

void EntityHandler::playerInteract()
{
	Vector2f interactCoord = player->interact();
	bool col = false;
	for (int i = 0; i < nrOfStructures && col == false; i++)
	{
		Vector2f structureCoord = structures[i]->getCoords();

		//col = ColLisionHandler::isCol(attackCoord, enemyCoord);
		if (col == true)
		{
		}
	}
}

void EntityHandler::playerMove()
{
	Vector2f requestedCoords = player->moveRequest();
	bool floor = isFloor(requestedCoords);
	bool col = false;
	for (int i = 0; i < nrOfEnemys && col == false; i++)
	{
		Vector2f otherCoords = enemys[i]->getCoords();
		//col = ColLisionHandler::isCol(requestedCoords, otherCoords);
	}
	for (int i = 0; i < nrOfStructures && col == false; i++)
	{
		Vector2f otherCoords = structures[i]->getCoords();
		//col = ColLisionHandler::isCol(requestedCoords, otherCoords);
	}
	for (int i = 0; i < nrOfStructures; i++)
	{
		Vector2f otherCoords = items[i]->getCoords();
		//col = ColLisionHandler::isCol(requestedCoords, otherCoords);
		player->pickUpItem(*items[i]);
		removeItem(i);
	}
	player->setPos(requestedCoords);
}

void EntityHandler::playerTurnUp()
{
	//player->setDirection(Up);
}

void EntityHandler::playerTurnLeft()
{
	//player->setDirection(Left);
}

void EntityHandler::playerTurnDown()
{
	//player->setDirection(Down);
}

void EntityHandler::playerTurnRight()
{
	//player->setDirection(Right);
}

bool EntityHandler::isFloor(Vector2f coords)
{
	bool isFloor = false;
	int x = coords.x;
	int y = coords.y;
	if (floor[x][y] != nullptr)
	{
		isFloor = true;
	}
	return isFloor;
}