#include "TerrainObject.h"

void TerrainObject::SpawnTerrainObject(TerrainObject& t_object, Map& map) 
{
	while (map.GetMapAreaXY(t_object.t_object_x, t_object.t_object_x) != map.GetEmptyTile())
	{
		RandTObjXY(map.GetMapMinimum(), map.GetMapMaximum());
	}
	map.UpdateMap(t_object.t_object_x, t_object.t_object_y, t_object.t_object_tile);
}

void TerrainObject::GenerateTerrain(int quantity, Map& map, std::string tile)
{
	TerrainObject new_tobject(tile);
	std::vector<TerrainObject> t_objects;

	for (int i = 0; i < quantity; i++)
	{
		t_objects.push_back(new_tobject);
		SpawnTerrainObject(t_objects[i], map);
	}
}


inline int TerrainObject::SpitRand(int min, int max) { std::random_device rd; std::mt19937 gen(rd()); std::uniform_int_distribution<>distr(min, max); return distr(gen); }
