#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "BaseEntities.h"
#include "TerrainObject.h"

class Game
{
public:
	void LoadTerrain();
	void LoadMobs();
	void GameLoop();
	void DisplayMenu();
private:
	enum MENU_OPTIONS
	{
		START_GAME,
		GAME_GUIDE,
		EXIT_GAME,
		EXIT_KEY = 0X4F
	};
	bool GameRunning = true;
};

#endif //GAME_H
