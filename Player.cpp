#include "Player.h"

void Player::MovePlayer(Map& map) 
{
	if (GetAsyncKeyState(KEY_W) && EmptyTile(map, player_x, player_y + - 1)) //UP
	{
		--player_y;
		UpdatePosition(map, player_x, player_y + 1); 
	}
    else if (GetAsyncKeyState(KEY_S) && EmptyTile(map, player_x, player_y + 1)) //DOWN
	{
		++player_y;
		UpdatePosition(map, player_x, player_y + -1);
	}
	else if (GetAsyncKeyState(KEY_A) && EmptyTile(map, player_x + -1, player_y)) //LEFT
	{
		--player_x;
		UpdatePosition(map, player_x + 1, player_y);
	}
	else if (GetAsyncKeyState(KEY_D) && EmptyTile(map, player_x + 1, player_y)) //RIGHT
	{
		++player_x;
		UpdatePosition(map, player_x + -1, player_y);
	}
}

void Player::SpawnPlayer(Map& map)
{
	while (!EmptyTile(map, player_x, player_y))
	{
		//Check row by row for an empty space
		++player_x;
		if (player_x > map.GetMapMaximum())
		{
			player_x = map.GetMapMinimum(); //Reset the x coord once end of a row is reached and move down
			++player_y;
		}
	}
	map.UpdateMap(player_x, player_y, player_body);
}

void Player::DisplayInv() //WIP
{
	for (auto& i : player_weapons)
	{
		std::cout << "Weapons - Name\n" << i.GetName() << std::endl;
	}

	for (auto& i : player_armour)
	{
		std::cout << "Armour - Name:\n" << i.GetName() << std::endl;
	}
}

void Player::UpdatePosition(Map& map, int p_x, int p_y) //Remove player from previous map tile in previous x y, update corresponding X Y tile with player.
{
	map.UpdateMap(p_x, p_y, map.GetEmptyTile());
	map.UpdateMap(player_x, player_y, player_body);

	system("cls");

	map.DrawMap();
}


bool Player::EmptyTile(Map& map, int p_x, int p_y)
{
	return (map.GetMapAreaXY(p_x, p_y) == map.GetEmptyTile());
}
