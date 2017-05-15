#include "Stats..h"
#include <iostream>
Stats::Stats()
{
	this->defence = 0.2f;
	this->attack = 10.0f;
	this->health = 10.0f;
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

void Stats::setAttack(float attack)
{
	this->attack = attack;
}

void Stats::setHealth(float health)
{
	this->health = health;
}

float Stats::getHealth() const
{
	return this->health;
}

void Stats::takeDMG(int dmg)
{
	this->health -= dmg;
}
