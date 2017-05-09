#ifndef  INVENTORY_H 
#define INVENTORY_H
#include "Item.h"
class Inventory
{
private:
	const static int INVENTORY_SIZE = 28;
	Item itemArray[INVENTORY_SIZE]; 
public:
	Inventory(); 
	~Inventory();
	Item* getItems(); 
};
#endif  

