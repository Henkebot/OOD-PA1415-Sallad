#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H


#include "../Gameplay/Player.h"
#include "../Gameplay/Enemy.h"
#include "../Gameplay/Floor.h"
#include "../Gameplay/Structure.h"
#include "../Utility/InputManager.h"
using namespace sf;
namespace Container
{
	class EntityHandler
	{
	public:
		EntityHandler();
		EntityHandler(Player* player);
		EntityHandler(Player* player, Vector2f playerCoords);
		~EntityHandler();
		void update(float dt);
		Player* getPlayer() const;
		void setPlayer(Player* player);
		void destroyPlayer();
	private:
		//player intraction
		bool playerMove();
		void playerInteract();
		void playerAttack();
		void playerTurnUp();
		void playerTurnLeft();
		void playerTurnDown();
		void playerTurnRight();


		void handleInput();
		void extraCon();
		//float calculateDmg(Stats attackerStats, Stats defenderStats);
		bool isFloor(Vector2f coords);
		void removeItem(int index);

		Player* player;
		sf::Texture* playerTexture;
		Enemy** enemys;
		Structure** structures;
		Item** items;
		Floor* floor[25][25];

		int nrOfEnemys;
		int nrOfStructures;
		int nrOfItems;

		bool playersTurn;
	};
}

#endif // !ENTITYHANDLER_H

