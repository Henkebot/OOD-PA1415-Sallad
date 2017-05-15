#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H


#include "../Gameplay/Player.h"
#include "../Gameplay/Enemy.h"
#include "../Gameplay/Floor.h"
#include "../Gameplay/Structure.h"
#include "../Utility/InputManager.h"
#include "../Utility/Identifier.h"
#include "../Utility/MasterSpawner.h"

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
		void render(sf::RenderTarget& target) const;

		Player* getPlayer() const;

		void setPlayer(Player* player);
		void destroyPlayer();
		
		void setDoors(bool* doors);
		void setStructureProperty(int role, int spriteSheet);
		void createEntities(Identifier* inRoom, int size);
	private:
		//player intraction
		bool playerMove();
		void playerInteract();
		void playerAttack();
		void playerTurnUp();
		void playerTurnLeft();
		void playerTurnDown();
		void playerTurnRight();

		void EnemyMove();

		void handleInput(float dt);
		void extraCon();
		int calculateDmg(Stats attackerStats, Stats defenderStats);
		bool isFloor(Vector2f coords);
		bool isCol(Vector2f firstCoord, Vector2f SecondCoord);
		void removeItem(int index);

		
		Player* player;
		sf::Clock inputTimer;
		sf::Texture* playerTexture;
		Enemy** enemys;		
		Structure** structures;
		Item** items;
		Floor* floor[11][20];

		int nrOfEnemies;
		int structureProperty;
		int nrOfStructures;
		int nrOfItems;
		int floorSheet;

		bool playersTurn;

		//DEBUG
		sf::Vertex lineX[20][2];
		sf::Vertex lineY[11][2];

		void initLines();

		bool doorStatus[4];
	};
}

#endif // !ENTITYHANDLER_H

