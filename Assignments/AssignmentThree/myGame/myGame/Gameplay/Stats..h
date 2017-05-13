#ifndef STATS_H
#define STATS_H
class Stats
{
private:
	float defence;
	int attack;
public:
	Stats();
	~Stats();

	float getDefence() const;
	int getAttack() const;
	void setDefence(float defence);
	void setAttack(int attack);
};
#endif

