#include "Game.h"

void Game::GameLoop()
{
	
	Map map;

	TerrainObject trees("*", map, MAX_TERRAIN);
	TerrainObject rocks("^", map, MAX_TERRAIN);
	TerrainObject bushes("&", map, MAX_TERRAIN);

	Player player(map);
	map.DrawMap();

	BaseEntities goblin("Goblin", "G", map, DEFAULT_HEALTH, MAXIMUM_ENTITES);

	while (GameRunning)
	{
		Sleep(350);
		player.MovePlayer(map);
		goblin.MoveEntity(map, player);
	}
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

