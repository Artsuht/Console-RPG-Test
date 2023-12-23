#ifndef TERRAINATTRIBUTES_H
#define TERRAINATTRIBUTES_H

struct TerrainAttributes
{
	TerrainAttributes(int t_health, bool t_destructible);
	int terrain_health = 0;
	bool Destructible = false;
};

#endif TERRAINATTRIBUTES_H
