#ifndef ENUMS_H 
#define ENUMS_H
enum directions
{
	up,
	left,
	down,
	right
};

enum states
{
	attack,
	move,
	idle,
	interact
};

enum effects
{
	ladderUp,
	ladderDown,
	heal,
	art
};

enum roomRoles //används inte 
{
	start,
	basic,
	end
};
	
#endif