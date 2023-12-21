#include "Game.h"

void Game::GameLoop()
{
	Player* player = new Player;
	Map* map = new Map;

	BaseEntities* goblins[5]{ nullptr };
	TerrainObject* rocks[29]{ nullptr }, * trees[29]{ nullptr }, * bushes[29]{ nullptr }; //
	map->InitMap();
	
	//Mobs
	goblins[0]->GenerateEntity(goblins, map, 5, 100, "G");
	//Terrain
	rocks[0]->GenerateTerrain(rocks, map, 29, "^");
	trees[0]->GenerateTerrain(trees, map, 29, "*");
	bushes[0]->GenerateTerrain(bushes, map, 29, "&");

	player->SpawnPlayer(map);

	map->DrawMap();

	while (GameRunning)
	{
		Sleep(50);
		goblins[0]->MoveEntity(goblins, map, player);
		player->MovePlayer(map);
		Sleep(100);
		if (GetAsyncKeyState(EXIT_KEY))
			GameRunning = false;
	}

	//De-Alloc Memory - I could create a function with params but meh
	//Mobs;
	goblins[0]->CleanUpEntities(goblins, 5); 
	//Terrain
	rocks[0]->CleanUpTObjs(rocks, 29);
	trees[0]->CleanUpTObjs(trees, 29);
	bushes[0]->CleanUpTObjs(bushes, 29);
	
	player->CleanUpPlayer(player);
	map->CleanUpMap(map);

}

void Game::DisplayMenu()
{
	std::cout << "Welcome to Summoner's Tales:\n[0] Start Game\n[1] Guide\n[2] Exit\n";
	int option = 0;
	std::cin >> option;

		switch (option)
		{
		case START_GAME:
			GameLoop();
			break;
		case GAME_GUIDE:
			break;
		case EXIT_GAME:
			exit(0);
			break;
		default:
			std::cout << "Invalid input!";
			break;
		}
}

