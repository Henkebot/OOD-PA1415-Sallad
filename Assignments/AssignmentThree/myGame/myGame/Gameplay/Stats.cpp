#include "Stats..h"

Stats::Stats()
{
	this->defence = 0;
	this->attack = 0;
}

Stats::~Stats()
{

}

float Stats::getDefence() const
{
	return this->defence;
}

int Stats::getAttack() const
{
	return this->attack;
}

void Stats::setDefence(float defence)
{
	this->defence = defence;
}

void Stats::setAttack(int attack)
{
	this->attack = attack;
}