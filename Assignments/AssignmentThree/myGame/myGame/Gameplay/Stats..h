#ifndef STATS_H
#define STATS_H
class Stats
{
private:
	float defence;
	float weaponModifier; //minimum 1
	float strength;
	float agility;
	float health;
public:
	Stats();
	Stats(float weaponModifier, float defence, float health, float strength, float agility);
	~Stats();

	float getDefence() const;
	float getAttack() const;
	void setDefence(float defence);
	void setweaponModifier(float weaponModifier);
	float getweaponModifier();
	void setAgility(float agility);
	float getAgility();
	void setHealth(float health);
	float getHealth() const;
	float getStrength() const;
	void setStrength(float strength);
	void takeDMG(float dmg);
};
#endif

