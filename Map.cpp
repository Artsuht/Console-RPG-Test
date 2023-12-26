#include "Map.h"

void Map::InitMap() //Initialize Map
{
	for (int rows = 0; rows < map_width; rows++)
	{
		for (int columns = 0; columns < map_height; columns++)
		{
			map[columns][rows] = empty_tile;
			map[columns][TOP_BORDER] = border_tile; 
			map[LEFT_BORDER][rows] = border_tile;
			map[columns][BOTTOM_BORDER] = border_tile;
			map[RIGHT_BORDER][rows] = border_tile;	
		}
	}
}

void Map::UpdateMap(int entity_x, int entity_y, std::string entity_char)
{
	map[entity_x][entity_y] = entity_char;
}

void Map::DrawMap() //If only double buffer
{
	for (int rows = 0; rows < map_width; rows++)
	{
		for (int columns = 0; columns < map_height; columns++)
		{
			std::cout << map[columns][rows];
		}
		std::cout << std::endl;
	}
}
