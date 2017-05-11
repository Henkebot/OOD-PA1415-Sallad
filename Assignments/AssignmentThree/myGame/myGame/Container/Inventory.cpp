#include "Inventory.h" 
Inventory::Inventory()
{
	//Arrayen redan initierad
}

Inventory::~Inventory()
{

}

 Item* Inventory::getItems() 
{
	return this->itemArray; 
}