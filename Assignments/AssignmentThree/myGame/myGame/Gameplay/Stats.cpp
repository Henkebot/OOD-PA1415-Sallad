#include "Stats..h"
#include <iostream>
Stats::Stats()
{
	this->defence = 0.2f;
	this->weaponModifier = 1;
	this->strength = 10;
	this->agility = 5;
	this->health = 10.0f;
}

Stats::Stats(float weaponModifier, float defence, float health, float strength, float agility, float accuracy)
{
	this->defence = defence;
	this->weaponModifier = weaponModifier;
	this->health = health;
	this->agility = agility;
	this->strength = strength;
	this->accuracy = accuracy;
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
	float attack = strength * weaponModifier;
	return attack;
}

float Stats::getAttackFloat() const
{
	float attack = strength * weaponModifier;
	return attack;
}

void Stats::setDefence(float defence)
{
	this->defence = defence;
}

void Stats::setweaponModifier(float weaponModifier)
{
	this->weaponModifier = weaponModifier;
}

float Stats::getweaponModifier()
{
	return weaponModifier;
}

void Stats::setAgility(float agility)
{
	this->agility = agility;
}

float Stats::getAgility() const
{
	return agility;
}

void Stats::setHealth(float health)
{
	this->health = health;
}

float Stats::getHealth() const
{
	return this->health;
}

float Stats::getStrength() const
{
	return strength;
}

void Stats::setStrength(float strength)
{
	this->strength = strength;
}

float Stats::getAccuracy()
{
	return accuracy;
}

void Stats::setAccuracy(float accuracy)
{
	this->accuracy = accuracy;
}

void Stats::takeDMG(float dmg)
{
	this->health -= dmg;
}
