#ifndef BASEENTITIES_H
#define BASEENTITIES_H

#include <iostream>
#include <vector>
#include <random>
#include "Player.h"

constexpr int MAXIMUM_ENTITES = 10; //Put into namespace or seperate constants header?
constexpr int DEFAULT_HEALTH = 100; 

static Weapons b_sword("Bronze Sword", 1, BRONZE_SWORD_DAMAGE, 0, 0, MELEE_WEAPON); //Testing
static Armour c_plate("Bronze Chestplate", 1, 0, 0, BRONZE_ARMOUR, BRONZE_ARMOUR_DUR);

class BaseEntities
{
public:
	BaseEntities(std::string ent_name, std::string ent_body,Map& map, int ent_health, int quantity) : entity_body(ent_body), entity_health(ent_health), entity_name(ent_name)
	{ 
		GenerateEntity(map, ent_name, quantity, ent_health, ent_body); 
	}

	BaseEntities(std::string ent_name, std::string ent_body, int ent_health) : entity_name(ent_name), entity_health(ent_health), entity_body(ent_body) { }

	void SpawnEntity(BaseEntities& entity, Map& map);
	void GenerateEntity(Map& map, std::string ent_name, int quantity, int health, std::string ent_body);
	
	void MoveEntity(Map& map, Player& player);
	void TriggerChase(BaseEntities& entity, Map& map, Player& player);
	void ChasePlayer(BaseEntities& entity, Map& map, Player& player);
	void RandEntityXY(int min, int max) { entity_x = SpitRand(min, max); entity_y = SpitRand(min, max); }
	void UpdatePosition(BaseEntities& entity, Map& map, int p_x, int p_y);

	int SpitRand(int min, int max); //Does what it says on the tin

	bool IsCaughtPlayer(BaseEntities& entity, Player& player);
	bool EmptyTile(int e_x, int e_y, Map& map);
	
	Weapons& GetEntWeapon() { return entity_weapons[0]; }
	Armour& GetEntArmour() { return entity_armor[0]; }
	//Get
	int GetEntHealth() { return entity_health; }
	std::string GetEntName() { return entity_name; }
	//Set
	void SetEntHealth(int ent_health) { entity_health += ent_health; };
	void SetEntDead(bool ent_dead) { is_dead = ent_dead; }
	

private:
	std::vector<BaseEntities>entity_duplicates;
	std::vector<std::string>entity_inventory;
	std::vector<Weapons>entity_weapons{ b_sword };
	std::vector<Armour>entity_armor{ c_plate };

	std::string entity_name;
    std::string entity_body;

	int entity_x = 0, entity_y = 0;
	int entity_health = 0;

	bool is_dead = false;
	bool is_chasing_player = false;
	bool ongoing_chase = false;
};

#endif //BASEENTITIES_H

