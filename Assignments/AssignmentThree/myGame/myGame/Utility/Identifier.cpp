#include "Identifier.h"

Identifier::Identifier(const std::string & id, int amount)
{
	this->id = id;
	this->amount = amount;
}

void Identifier::setNewId(const std::string & id)
{
	this->id = id;
}

void Identifier::setNewAmount(int amount)
{
	this->amount = amount;
}

std::string Identifier::getId() const
{
	return this->id;
}

int Identifier::getAmount() const
{
	return this->amount;
}
