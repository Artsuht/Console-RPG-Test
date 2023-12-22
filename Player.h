#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Map.h"

class Player
{
public:
	Player(Map& map) { SpawnPlayer(map); }
	void MovePlayer(Map& map);
	void SpawnPlayer(Map& map);
	void DisplayStats();
	void UpdatePosition(Map& map, int p_x, int p_y, int cur_x, int cur_y);
	bool EmptyTile(Map& map, int p_x, int p_y);
	//Getters
	int GetPlayerX() { return player_x; }
	int GetPlayerY() { return player_y; }
private:

	enum CONTROLS
	{
		KEY_W = 0x57,
		KEY_A = 0x41,
		KEY_S = 0x53,
		KEY_D = 0x44,
	};

	enum DIRECTIONS //To improve readability of collision handling
	{
		LEFT = -1, UP = -1,
		RIGHT = 1, DOWN = 1
	};

	int selection_state = MOVEMENT;
	enum SELECTION_STATE
	{
		MENU_SELECT,
		MOVEMENT
	};

	int player_x = 0, player_y = 0;
	std::vector<std::string>player_inventory;
	const std::string player_body = "@";
};

#endif //PLAYER_H
