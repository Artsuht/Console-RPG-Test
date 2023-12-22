#include "Game.h"

void Game::GameLoop()
{
	
	Map map;

	BaseEntities goblin("G", map, 100, 15);
	TerrainObject trees("*", map, 29);
	TerrainObject rocks("^", map, 29);
	TerrainObject bushes("&", map, 29);

	Player player(map);

	map.DrawMap();

	while (GameRunning)
	{
		Sleep(200);
		player.MovePlayer(map);
		goblin.MoveEntity(map, player);
		if (GetAsyncKeyState(EXIT_KEY))
			GameRunning = false;
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

