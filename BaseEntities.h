#ifndef BASEENTITIES_H
#define BASEENTITIES_H

#include <iostream>
#include <vector>
#include <random>
#include "Player.h"

constexpr int MAXIMUM_ENTITES = 10; //Put into namespace or seperate constants header?
constexpr int DEFAULT_HEALTH = 100;

class BaseEntities
{
public:
	BaseEntities(std::string ent_body,Map& map, int ent_health, int quantity) : entity_body(ent_body), entity_health(ent_health) { GenerateEntity(map, quantity, ent_health, ent_body); }
	BaseEntities(std::string ent_body) : entity_body(ent_body){}
	void SpawnEntity(BaseEntities& entity, Map& map);
	void GenerateEntity(Map& map, int quantity, int health, std::string ent_body);
	
	void MoveEntity(Map& map, Player& player);
	void TriggerChase(BaseEntities& entity, Map& map, Player& player);
	void ChasePlayer(BaseEntities& entity, Map& map, Player& player);
	void RandEntityXY(int min, int max) { entity_x = SpitRand(min, max); entity_y = SpitRand(min, max); }

	int SpitRand(int min, int max); //Does what it says on the tin
	bool EmptyTile(BaseEntities& entity, int ent_y, int ent_x, Map& map);
	bool ChaseStatus() { return is_chasing_player; }
	
private:
	std::vector<BaseEntities>entity_duplicates;
	std::vector<std::string>inventory;
    std::string entity_body;

	int entity_x = 0, entity_y = 0;
	int entity_health = 0;

	bool is_chasing_player = false;
	bool ongoing_chase = false;
};

#endif //BASEENTITIES_H

