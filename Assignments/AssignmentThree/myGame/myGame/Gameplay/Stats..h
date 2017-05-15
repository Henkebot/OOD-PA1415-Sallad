#ifndef STATS_H
#define STATS_H
class Stats
{
private:
	float defence;
	float attack;
	float health;
public:
	Stats();
	Stats(int attack, float defence, int health);
	~Stats();

	float getDefence() const;
	int getAttack() const;
	void setDefence(float defence);
	void setAttack(float attack);
	void setHealth(float health);
	float getHealth() const;
	void takeDMG(int dmg);
};
#endif

