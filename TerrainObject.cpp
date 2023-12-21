#include "TerrainObject.h"

void TerrainObject::SpawnTerrainObject(TerrainObject* t_object, Map* map) 
{
	while (map->GetMapAreaXY(t_object->GetTObjX(), t_object->GetTObjY()) != map->GetEmptyTile())
	{
		t_object->RandTObjXY(map->GetMapMinimum(), map->GetMapMaximum());
	}
	map->UpdateMap(t_object->GetTObjX(), t_object->GetTObjY(), t_object-> GetTObjBody());
}

void TerrainObject::CleanUpTObjs(TerrainObject* t_object[], int size)
{
	for (int i = 0; i < size; i++)
	{
		delete t_object[i];
	}
}

void TerrainObject::GenerateTerrain(TerrainObject* t_object[], Map* map, int quantity, std::string tile)
{
	for (int i = 0; i < quantity; i++)
	{
			t_object[i] = new TerrainObject(tile);
			SpawnTerrainObject(t_object[i], map);
    }
}

inline int TerrainObject::SpitRand(int min, int max) { std::random_device rd; std::mt19937 gen(rd()); std::uniform_int_distribution<>distr(min, max); return distr(gen); }
