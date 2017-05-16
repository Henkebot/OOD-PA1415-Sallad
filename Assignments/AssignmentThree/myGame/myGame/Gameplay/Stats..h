#ifndef STATS_H
#define STATS_H
class Stats
{
private:
	float defence;
	float weaponModifier; //minimum 1
	float strength;
	float agility;
	float accuracy;
	float health;
	float maxHealth;
public:
	Stats();
	Stats(float weaponModifier = 5, float defence = 5, float health = 5, float strength = 5, float agility = 5, float accuracy = 5);
	~Stats();

	float getDefence() const;
	int getAttack() const;
	float getAttackFloat() const;
	void setDefence(float defence);
	void setweaponModifier(float weaponModifier);
	float getweaponModifier();
	void setAgility(float agility);
	float getAgility() const ;
	void setHealth(float health);
	float getHealth() const;
	float getStrength() const;
	void setStrength(float strength);
	float getAccuracy();
	void setAccuracy(float accuracy);
	void takeDMG(float dmg);
};
#endif

