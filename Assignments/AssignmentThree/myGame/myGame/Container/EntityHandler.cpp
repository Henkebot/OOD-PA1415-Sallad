#include "EntityHandler.h"
using namespace Container;
#include "../Utility/Values.h"
EntityHandler::EntityHandler()
{
	player = nullptr;
	extraCon();
	initLines();
	
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
	inputTimer.restart().asSeconds();
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

	for (int i = 1; i < Val::ROOM_HEIGHT - 1; i++)
	{
		for (int j = 1; j < Val::ROOM_WIDTH - 1; j++)
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
		handleInput(dt);
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
	for (int y = 1; y < Val::ROOM_HEIGHT - 1; y++)
	{
		for (int x = 1; x < Val::ROOM_WIDTH - 1; x++)
		{
			target.draw(*floor[y][x]);
		}
	}
	if (structureProperty == 1)
	{
		target.draw(*structures[1]);

	}
	target.draw(*player);
	for (int i = 0; i < Val::ROOM_WIDTH; i++)
		target.draw(lineX[i], 2, sf::Lines);	
	for (int i = 0; i < Val::ROOM_HEIGHT; i++)
		target.draw(lineY[i], 2, sf::Lines);

	for (int i = 0; i < nrOfEnemies; i++)
	{
		target.draw(*enemys[i]);
	}

	if (structureProperty == 1)
		target.draw(*structures[0]);
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

void Container::EntityHandler::setDoors(bool * doors)
{
	for (int i = 0; i < 4; i++)
	{
		doorStatus[i] = doors[i];
	}
}

void Container::EntityHandler::setStructureProperty(int role, int spriteSheet)
{
	structureProperty = role;
	floorSheet = spriteSheet;
}

void Container::EntityHandler::createEntities(Identifier * inRoom, int size)
{
	MasterSpawner spawner(inRoom, size);
	nrOfEnemies = spawner.spawnEnemies(enemys);

	sf::Texture* tiles = new sf::Texture();
	if(floorSheet == 0)
		tiles->loadFromFile("./textures/sheet.png", sf::IntRect(Val::SPRITE_SIZE * 1, Val::SPRITE_SIZE * 1, Val::SPRITE_SIZE, Val::SPRITE_SIZE));
	else if(floorSheet == 1)
		tiles->loadFromFile("./textures/sheet2.png", sf::IntRect(Val::SPRITE_SIZE * 1, Val::SPRITE_SIZE * 1, Val::SPRITE_SIZE, Val::SPRITE_SIZE));
	else 
		tiles->loadFromFile("./textures/sheet3.png", sf::IntRect(Val::SPRITE_SIZE * 1, Val::SPRITE_SIZE * 1, Val::SPRITE_SIZE, Val::SPRITE_SIZE));

	for (int y = 1; y < Val::ROOM_HEIGHT - 1; y++)
	{
		for (int x = 1; x < Val::ROOM_WIDTH - 1; x++)
		{
			floor[y][x] = new Floor(tiles, sf::Vector2f(x * Val::FINAL_SIZE, y * Val::FINAL_SIZE));
		}
	}

	if (structureProperty == 1)
	{
		std::cout << "köres!!!!!!!!";
		Texture* textureLadderLower = new sf::Texture();
		Texture* textureLadderUpper = new sf::Texture();
		textureLadderLower->loadFromFile("./textures/sheet.png", sf::IntRect(3 * Val::SPRITE_SIZE, 2 * Val::SPRITE_SIZE,
			Val::SPRITE_SIZE, Val::SPRITE_SIZE));
		textureLadderUpper->loadFromFile("./textures/sheet.png", sf::IntRect(3 * Val::SPRITE_SIZE, 1 * Val::SPRITE_SIZE,
			Val::SPRITE_SIZE, Val::SPRITE_SIZE));

		this->structures = new Structure*[2];
		structures[0] = new Structure(textureLadderUpper, sf::Vector2f(5*Val::FINAL_SIZE, 5*Val::FINAL_SIZE));
		structures[1] = new Structure(textureLadderLower, sf::Vector2f(5 * Val::FINAL_SIZE, 6 * Val::FINAL_SIZE));
		
	}
	// Lägga till start och slut skiten när victor är klar


}


void EntityHandler::handleInput(float dt)
{
	if (InputManager::keyPressed(sf::Keyboard::Q))
	{
		playerAttack();
	}
	else if (InputManager::keyPressed(sf::Keyboard::E))
	{
		playerInteract();
	}
	else if (inputTimer.getElapsedTime().asSeconds() > 500 * dt)
	{
		
		if (InputManager::keyPress(sf::Keyboard::W) || InputManager::keyPress(sf::Keyboard::Up))
		{
			playerTurnUp();
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemys[i]->update(0);
			}
			this->inputTimer.restart();
		}
		else if (InputManager::keyPress(sf::Keyboard::A) || InputManager::keyPress(sf::Keyboard::Left))
		{
			playerTurnLeft();
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemys[i]->update(0);
			}
			this->inputTimer.restart();
		}
		else if (InputManager::keyPress(sf::Keyboard::S) || InputManager::keyPress(sf::Keyboard::Down))
		{
			playerTurnDown();
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemys[i]->update(0);
			}
			this->inputTimer.restart();
		}
		else if (InputManager::keyPress(sf::Keyboard::D) || InputManager::keyPress(sf::Keyboard::Right))
		{
			playerTurnRight();
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemys[i]->update(0);
			}
			this->inputTimer.restart();
		}
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

	//Väggar
	int width = (Val::ROOM_WIDTH - 1) * (Val::FINAL_SIZE);
	int height = (Val::ROOM_HEIGHT - 1) * (Val::FINAL_SIZE);
	if (requestedCoords.x == width ||
		requestedCoords.x == 0 ||
		requestedCoords.y == height ||
		requestedCoords.y == 0)
		col = true;
	
	float scale = 0.75f;
	float spriteSize = 64;
	float reqIndexX = requestedCoords.x / (scale * spriteSize);
	float reqIndexY = requestedCoords.y / (scale * spriteSize);

	// DÖRRAR 
	// VÄNSTER
	if (reqIndexX == 0 && reqIndexY == 5 && doorStatus[3])
		col = false;
	else if (reqIndexX == 10 && reqIndexY == 0 && doorStatus[0]) // UP
		col = false;
	else if (reqIndexX == 19 && reqIndexY == 5 && doorStatus[1]) // HÖGER
		col = false;
	else if (reqIndexX == 10 && reqIndexY == 10 && doorStatus[2])
		col = false;
	return !col;
}

void EntityHandler::playerTurnUp()
{
	if (player->getDirection() == up)
	{
		if (playerMove())
		{
			player->move(0, -1);
		}
		EnemyMove();
		//player->move(0, -1);//ta bort efter att playerMove är färdig
		
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
		if (playerMove())
		{
			player->move(-1, 0);
		}
		EnemyMove();
		//player->move(-1,0);//ta bort efter att playerMove är färdig
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
		if (playerMove())
		{
			player->move(0, 1);
		}
		EnemyMove();
		//player->move(0, 1);//ta bort efter att playerMove är färdig
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
		if (playerMove())
		{
			player->move(1, 0);
		}
		EnemyMove(); 
		//player->move(1,0);//ta bort efter att playerMove är färdig
	}
	else
	{
		player->setCurrentSpriteFrame(0, 1);
		player->setDirection(right);
	}
}

void Container::EntityHandler::EnemyMove()
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		Vector2f requestedCoords = enemys[i]->moveRequest();
		bool col = isFloor(requestedCoords);

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

		int width = (20 - 1) * (64 * 0.75f);
		int height = (11 - 1) * (64 * 0.75f);
		if (requestedCoords.x == width ||
			requestedCoords.x == 0 ||
			requestedCoords.y == height ||
			requestedCoords.y == 0)
			col = true;
		if (!col)
		{
			this->enemys[i]->move(enemys[i]->getDirX(), enemys[i]->getDirY());
		}
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

void Container::EntityHandler::initLines()
{
	for (int i = 0; i < Val::ROOM_WIDTH; i++)
	{
		lineX[i][0].position = sf::Vector2f(i * (Val::SPRITE_SIZE * Val::SCALE), 0);
		lineX[i][0].color = sf::Color::Red;
		lineX[i][1].position = sf::Vector2f(i * (Val::SPRITE_SIZE * Val::SCALE), (Val::SPRITE_SIZE * Val::SCALE) * 11);
		lineX[i][1].color = sf::Color::Red;
	}
	for (int i = 0; i < Val::ROOM_WIDTH; i++)
	{
		lineY[i][0].position = sf::Vector2f(0, i * (Val::SPRITE_SIZE * Val::SCALE));
		lineY[i][0].color = sf::Color::Red;
		lineY[i][1].position = sf::Vector2f(20 * (Val::SPRITE_SIZE * Val::SCALE), i* (Val::SPRITE_SIZE * Val::SCALE));
		lineY[i][1].color = sf::Color::Red;
	}
}
