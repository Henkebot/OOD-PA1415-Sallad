#ifndef MASTERSPAWNER_H
#define MASTERSPAWNER_H
#include "Identifier.h"
#include "../Gameplay/IncludeEntites.h"
#include "Values.h"

class MasterSpawner
{
public:
	MasterSpawner(Identifier* inRoom, int size);
	~MasterSpawner();

	int floorType() const;
	int spawnEnemies(Enemy**& enemies) const;
	int spawnItems(Item**& items) const;
	int spawnStructures(Structure**& structures) const;
private:
	int getAmountOfEnemiesInRoom() const;
	int getAmountOfItemsInRoom() const;
	int getAmountOfStructuresInRoom() const;
	Identifier* inRoom;
	int size;
};

#endif