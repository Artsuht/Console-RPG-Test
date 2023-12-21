#ifndef TERRAINOBJECT_H
#define TERRAINOBJECT_H

#include "Game.h"
#include <random>

class TerrainObject
{
public:
	TerrainObject(std::string tobj_tile) : t_object_tile(tobj_tile){ }
	TerrainObject(){}
	void SpawnTerrainObject(TerrainObject* t_object, Map* map); 
	void CleanUpTObjs(TerrainObject* t_object[], int size);
	void GenerateTerrain(TerrainObject* t_object[], Map* map, int quantity, std::string tile);
	int SpitRand(int min, int max); //Does what it says on the tin
	//Getters
	int GetTObjHealth() { return t_object_health; }
	std::string GetTObjBody() { return t_object_tile; }
	int GetTObjX() { return t_object_x; }
	int GetTObjY() { return t_object_y; }
	//Setters
	void SetTObjTile(std::string tobj_tile) { t_object_tile = tobj_tile; }
	void SetTObjHealth(int new_tobj_health) { t_object_health = new_tobj_health; }
	void SetTObjX(int new_tobj_x) { t_object_x = new_tobj_x; } //Not exactly necessary but in the event that I want to place an entity in a specific location...
	void SetTObjY(int new_tobj_y) { t_object_y = new_tobj_y; }
	void RandTObjXY(int min, int max) { t_object_x = SpitRand(min, max); t_object_y = SpitRand(min, max); }
private:
	int t_object_health = 0;
	int t_object_x = 0, t_object_y = 0;
	std::string t_object_tile;
};

#endif //TERRAINOBJECT_H
