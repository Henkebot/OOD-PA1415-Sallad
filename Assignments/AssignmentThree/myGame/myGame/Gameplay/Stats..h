#ifndef STATS_H
#define STATS_H
class Stats
{
private:
	float defence;
	int attack;
	int health;
public:
	Stats();
	Stats(int attack, float defence, int health);
	~Stats();

	float getDefence() const;
	int getAttack() const;
	void setDefence(float defence);
	void setAttack(int attack);
	void setHealth(int health);
	int getHealth() const;
	void takeDMG(int dmg);
};
#endif

