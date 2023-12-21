#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string.h>
#include <Windows.h>
#include <random>

class Map
{
public:
	void InitMap();
	void UpdateMap(int entity_x, int entity_y, std::string entity_char);
	void DrawMap();
	//Getters
	int GetMapMaximum() { return MAP_MAXIMUM; }
	int GetMapMinimum() { return MAP_MINIMUM; }
	int GetMapWidth() { return map_width; }
	int GetMapHeight() { return map_height; }
	std::string GetMapAreaXY(int m_x, int m_y) { return map[m_x][m_y]; }
	std::string GetEmptyTile() { return empty_tile; }
	//CleanUp
	void CleanUpMap(Map* map) { delete map; }
private:
	//Honestly, just makes it easier to comprehend map initialisation code.
	enum Borders
	{
		MAP_MINIMUM = 0, MAP_MAXIMUM = 29,
		//Used for clarity in iterators
		TOP_BORDER = 0, LEFT_BORDER = 0,
		BOTTOM_BORDER = 29, RIGHT_BORDER = 29
	};
	//Map Tiles
	const std::string border_tile = "#";
	const std::string empty_tile = ".";
	//Map
	static const int map_width = 30;
	static const int map_height = 30;
	std::string map[map_width][map_height];
};

#endif //MAP_H

