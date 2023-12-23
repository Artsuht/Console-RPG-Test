#include "Player.h"

void Player::MovePlayer(Map& map) 
{
	if (GetAsyncKeyState(KEY_W) && EmptyTile(map, player_x, player_y + UP)) //UP
	{
		--player_y;
		//Args for UpdatePosition takes the previous position (Leftmost Coords) and current position(Rightmost Coords).
		//The opposite of the direction travelled renders the previous position hence the use of enum offsets. Same logic applies to rest. 
		UpdatePosition(map, player_x, player_y + DOWN, player_x, player_y); 
	}
        else if (GetAsyncKeyState(KEY_S) && EmptyTile(map, player_x, player_y + DOWN)) //DOWN
	{
		++player_y;
		UpdatePosition(map, player_x, player_y + UP, player_x, player_y);
	}
	else if (GetAsyncKeyState(KEY_A) && EmptyTile(map, player_x + LEFT, player_y)) //LEFT
	{
		--player_x;
		UpdatePosition(map, player_x + RIGHT, player_y, player_x, player_y);
	}
	else if (GetAsyncKeyState(KEY_D) && EmptyTile(map, player_x + RIGHT, player_y)) //RIGHT
	{
		++player_x;
		UpdatePosition(map, player_x + LEFT, player_y, player_x, player_y);
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

void Player::DisplayStats()
{
}

void Player::UpdatePosition(Map& map, int p_x, int p_y, int cur_x, int cur_y) //Remove player from previous map tile in previous x y, update corresponding X Y tile with player.
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
