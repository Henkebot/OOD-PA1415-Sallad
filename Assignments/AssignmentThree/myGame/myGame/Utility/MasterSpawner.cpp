#include "MasterSpawner.h"

MasterSpawner::MasterSpawner(Identifier * inRoom, int size)
{
	this->inRoom = inRoom;
	this->size = size;
}

MasterSpawner::~MasterSpawner()
{
}

int MasterSpawner::floorType() const
{
	int type = -1;
	for (int i = 0; i < this->size && type == -1; i++)
	{
		if (this->inRoom[i].getId() == "room")
		{
			type = 0;
		}
		else if (this->inRoom[i].getId() == "path")
		{
			type = 1;
		}
		else if (this->inRoom[i].getId() == "water")
		{
			type = 2;
		}
	}
	return type;
}

int MasterSpawner::spawnEnemies(Enemy **& enemies) const
{
	int sizeOfEnemiesArr = this->getAmountOfEnemiesInRoom();
	
	int nrOfEmy = 0;
	enemies = new Enemy*[sizeOfEnemiesArr];
	sf::Texture* zombieTexture = new sf::Texture();
	sf::Texture* goblinTexure = new sf::Texture();
	zombieTexture->loadFromFile(".\\textures\\zombieSheet.png");
	goblinTexure->loadFromFile(".\\textures\\goblinSheet.png");

	for (int i = 0; i < this->size; i++)
	{
		if (this->inRoom[i].getId() == "goblin")
		{
			for (int k = 0; k < inRoom[i].getAmount(); k++)
			{
				int y = rand() % (static_cast<int>(Val::ROOM_HEIGHT) - 2) + 1;
				int x = rand() % (static_cast<int>(Val::ROOM_WIDTH) - 2) + 1;
				enemies[nrOfEmy++] = new Enemy(goblinTexure, sf::Vector2f(x * (Val::SPRITE_SIZE * Val::SCALE), y * (Val::SPRITE_SIZE * 0.75f)));
			}
		}
		else if (this->inRoom[i].getId() == "spider")
		{
			for (int k = 0; k < inRoom[i].getAmount(); k++)
			{
				//enemies[nrOfEmy++] = new Enemy("goblin");
			}
		}
		else if (this->inRoom[i].getId() == "skeleton")
		{
			for (int k = 0; k < inRoom[i].getAmount(); k++)
			{
				//enemies[nrOfEmy++] = new Enemy("goblin");
			}
		}
		else if (this->inRoom[i].getId() == "zombie")
		{
			for (int k = 0; k < inRoom[i].getAmount(); k++)
			{
				int y = rand() % (static_cast<int>(Val::ROOM_HEIGHT) - 2) + 1;
				int x = rand() % (static_cast<int>(Val::ROOM_WIDTH) - 2) + 1;
				enemies[nrOfEmy++] = new Enemy(zombieTexture, sf::Vector2f(5 * (64 * 0.75f), 7 * (64 * 0.75f)));
			}
		}
	}

	return nrOfEmy;
}

int MasterSpawner::spawnItems(Item **& items) const
{
	// Do magic like in spawnEnemies;
	return 0;
}

int MasterSpawner::spawnStructures(Structure **& structures) const
{
	// Do magic like in spawnEnemies;
	return 0;
}

int MasterSpawner::getAmountOfEnemiesInRoom() const
{
	int amount = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->inRoom[i].getId() == "goblin"		||
			this->inRoom[i].getId() == "spider"		||
			this->inRoom[i].getId() == "skeleton"	||
			this->inRoom[i].getId() == "zombie")
		{
			amount += this->inRoom[i].getAmount();
		}
	}
	return amount;
}

int MasterSpawner::getAmountOfItemsInRoom() const
{
	// Do magic like in getAmountOfEnemiesInRoom();
	return 0;
}

int MasterSpawner::getAmountOfStructuresInRoom() const
{
	// Do magic like in getAmountOfEnemiesInRoom();
	return 0;
}
