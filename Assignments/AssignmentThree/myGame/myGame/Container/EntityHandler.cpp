#include "EntityHandler.h"
using namespace Container;
#include "Cave.h"
EntityHandler::EntityHandler()
{
	player = nullptr;
	extraCon();
	for (int i = 0; i < Cave::ROOM_WIDTH; i++)
	{
		lineX[i][0].position = sf::Vector2f(i * (Cave::SPRITE_SIZE * Cave::SCALE), 0);
			lineX[i][0].color = sf::Color::Red;
			lineX[i][1].position = sf::Vector2f(i * (Cave::SPRITE_SIZE * Cave::SCALE), (Cave::SPRITE_SIZE * Cave::SCALE) *11);
			lineX[i][1].color = sf::Color::Red;
	}
	for (int i = 0; i < Cave::ROOM_HEIGHT; i++)
	{
		lineY[i][0].position = sf::Vector2f(0, i * (Cave::SPRITE_SIZE * Cave::SCALE));
		lineY[i][0].color = sf::Color::Red;
		lineY[i][1].position = sf::Vector2f(20*(Cave::SPRITE_SIZE * Cave::SCALE),i* (Cave::SPRITE_SIZE * Cave::SCALE) );
		lineY[i][1].color = sf::Color::Red;
	}
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
	nrOfEnemys = 0;
	nrOfItems = 0;
	nrOfStructures = 0;
}

EntityHandler::~EntityHandler()
{
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
	player->update(dt);
	if (playersTurn == true)
	{
		handleInput();
	}
	else
	{
		Vector2f playerCoords = player->getCoords();
		for (int i = 0; i < nrOfEnemys; i++)
		{
			enemys[i]->update(dt/*, playerCoords*/);
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

void Container::EntityHandler::render(sf::RenderTarget & target) const
{
	target.draw(*player);
	for (int i = 0; i < Cave::ROOM_WIDTH; i++)
		target.draw(lineX[i], 2, sf::Lines);	
	for (int i = 0; i < Cave::ROOM_HEIGHT; i++)
		target.draw(lineY[i], 2, sf::Lines);

	
}

Player * Container::EntityHandler::getPlayer() const
{
	return player;
}

void Container::EntityHandler::setPlayer(Player* player)
{
	this->player = player;
}

void Container::EntityHandler::destroyPlayer()
{
	delete player;
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
	else if (InputManager::keyPressed(sf::Keyboard::W) || InputManager::keyPressed(sf::Keyboard::Up))
	{
		playerTurnUp();
	}
	else if (InputManager::keyPressed(sf::Keyboard::A) || InputManager::keyPressed(sf::Keyboard::Left))
	{
		playerTurnLeft();
	}
	else if (InputManager::keyPressed(sf::Keyboard::S) || InputManager::keyPressed(sf::Keyboard::Down))
	{
		playerTurnDown();
	}
	else if (InputManager::keyPressed(sf::Keyboard::D) || InputManager::keyPressed(sf::Keyboard::Right))
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

bool EntityHandler::playerMove()
{
	Vector2f requestedCoords = player->moveRequest();
	bool col = isFloor(requestedCoords);	
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
	for (int i = 0; i < nrOfItems; i++)
	{
		Vector2f otherCoords = items[i]->getCoords();
		//col = ColLisionHandler::isCol(requestedCoords, otherCoords);
		player->pickUpItem(*items[i]);
		removeItem(i);
	}
	return col;
}

void EntityHandler::playerTurnUp()
{
	if (player->getDirection() == up)
	{
		if (playerMove() == true)
		{
			//player->move(0, -1);
		}
		player->move(0, -1);//ta bort efter att playerMove �r f�rdig
		
	}
	else
	{
		player->setDirection(up);
		player->setCurrentSpriteFrame(0, 0);
	}
}

void EntityHandler::playerTurnLeft()
{
	if (player->getDirection() == left)
	{
		if (playerMove() == true)
		{
			//player->move(-1, 0);
		}
		player->move(-1,0);//ta bort efter att playerMove �r f�rdig
	}
	else
	{
		player->setDirection(left);
		player->setCurrentSpriteFrame(0, 3);
	}
}

void EntityHandler::playerTurnDown()
{
	if (player->getDirection() == down)
	{
		if (playerMove() == true)
		{
			//player->move(0, 1);
		}
		player->move(0, 1);//ta bort efter att playerMove �r f�rdig
	}
	else
	{
		player->setCurrentSpriteFrame(0, 2);
		player->setDirection(down);
	}
}

void EntityHandler::playerTurnRight()
{
	if (player->getDirection() == right)
	{
		if (playerMove() == true)
		{
			//player->move(1, 0);
		}
		player->move(1,0);//ta bort efter att playerMove �r f�rdig
	}
	else
	{
		player->setCurrentSpriteFrame(0, 1);
		player->setDirection(right);
	}
}

bool EntityHandler::isFloor(Vector2f coords)
{
	bool isFloor = false;
	/*int x = coords.x;
	int y = coords.y;
	if (floor[x][y] != nullptr)
	{
		isFloor = true;
	}*/
	return isFloor;
}

void Container::EntityHandler::removeItem(int index)
{
}
