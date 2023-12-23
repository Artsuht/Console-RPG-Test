#ifndef TERRAINOBJECT_H
#define TERRAINOBJECT_H

#include "Game.h"
#include <random>

class TerrainObject
{
public:
	TerrainObject(std::string tobj_tile, Map& map, int quantity) : t_object_tile(tobj_tile) { GenerateTerrain(quantity, map, tobj_tile); }
	TerrainObject(std::string tobj_tile) : t_object_tile(tobj_tile) {} //Used to create duplicate objects.
	void SpawnTerrainObject(TerrainObject& t_object,Map& map);
	void GenerateTerrain(int quantity, Map& map, std::string tile);
	int SpitRand(int min, int max); //Does what it says on the tin
	//Setters
	void RandTObjXY(int min, int max) { t_object_x = SpitRand(min, max); t_object_y = SpitRand(min, max); }
private:
	int t_object_x = 0, t_object_y = 0;
	std::string t_object_tile;
};

#endif //TERRAINOBJECT_H
