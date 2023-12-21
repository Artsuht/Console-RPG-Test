#ifndef BASEENTITIES_H
#define BASEENTITIES_H

#include <iostream>
#include <vector>
#include <random>
#include "Player.h"

class BaseEntities
{
public:
	BaseEntities(std::string ent_body, int ent_health) : entity_body(ent_body), entity_health(ent_health) {}

	void SpawnEntity(BaseEntities* entity, Map* map);
	void GenerateEntity(BaseEntities* entity[], Map* map, const int& quantity, const int& health, std::string tile);
	void MoveEntity(BaseEntities* entity[], Map* map, Player* player);
	void TriggerChase(BaseEntities* entity, Map* map, Player* player);
	void ChasePlayer(BaseEntities* entity, Map* map, Player* player);
	bool EmptyTile(BaseEntities* entity, int ent_y, int ent_x, Map* map);
	int SpitRand(int min, int max); //Does what it says on the tin
	void AttackPlayer(Player* player);
	//Getter
	int GetNumEntities() { return num_entities; }
	int GetEntityX() { return entity_x; }
	int GetEntityY() { return entity_y; }
	bool ChaseStatus() { return is_chasing_player; }
	std::string GetEntityBody() { return entity_body; }
	//Setter
	void SetNumEntities(int ent_num) { num_entities = ent_num; }
	void RandEntityXY(int min, int max) { entity_x = SpitRand(min, max); entity_y = SpitRand(min, max); }
	void SetEntityX(int ent_x) { entity_x = ent_x; }
	void SetEntityY(int ent_y) { entity_y = ent_y; }
	void SetChase(bool chasing_state) { is_chasing_player = chasing_state; }
	//Clean-Up
	void CleanUpEntities(BaseEntities* entity[], int size);
private:
	const int MAXIMUM_ENTITIES = 5;
	enum SPACES
	{
		RIGHT_OF_PLAYER = 2, LEFT_OF_PLAYER = -2,
		BENEATH_PLAYER = 2, ABOVE_PLAYER = -2
	};
	int entity_x = 0, entity_y = 0;
	int entity_health = 0;
	std::vector<std::string>inventory;
	std::string entity_body	;
	int num_entities = 0;
	bool is_chasing_player = false;
};

#endif //BASEENTITIES_H

