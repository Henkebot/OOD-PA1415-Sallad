#include "Stats..h"
#include <iostream>
Stats::Stats()
{
	this->defence = 0.2f;
	this->attack = 10;
	this->health = 10;
}

Stats::Stats(int attack, float defence, int health)
{
	this->defence = defence;
	this->attack = attack;
	this->health = health;
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

void Stats::setHealth(int health)
{
	this->health = health;
}

int Stats::getHealth() const
{
	return this->health;
}

void Stats::takeDMG(int dmg)
{
	this->health -= dmg;
}
