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
	//enemies = new Enemy*[sizeOfEnemiesArr];

	for (int i = 0; i < this->size; i++)
	{
		if (this->inRoom[i].getId() == "goblin")
		{
			for (int k = 0; k < inRoom[i].getAmount(); k++)
			{
				//enemies[nrOfEmy++] = new Enemy("goblin");
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
				//enemies[nrOfEmy++] = new Enemy("goblin");
			}
		}
	}

	return sizeOfEnemiesArr;
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
