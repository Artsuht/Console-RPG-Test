#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>

constexpr int METAL_SWORD_DAMAGE = 20; //Put into namespace or seperate constants header?
constexpr int SILVER_SWORD_DAMAGE = 10;
constexpr int BRONZE_SWORD_DAMAGE = 5;

constexpr int MAX_WEAPONS = 1;

enum WEAPON_EFFECT
{
	PIERCING,
	SLASHING,
};

enum WEAPON_TYPE
{
	RANGED_WEAPON,
	MELEE_WEAPON
};

enum WEAPON_MATERIAL 
{
	METAL_WEAPON,
	SILVER_WEAPON,
	BRONZE_WEAPON,
};

class Weapons
{
public:
	Weapons(std::string wpn_name, int lvl_req, int dmg, int str_req, int agil_req, int wpn_type) : level_req(lvl_req), name(wpn_name), str_requirement(str_req), agil_requirement(agil_req), type(wpn_type){ }
	Weapons();
	//Getters
	std::string GetName() { return name; }
	int GetDamage() { return damage; }
	int GetType() { return type; }
	int GetStrReq() { return str_requirement; }
	int GetAgilReq() { return agil_requirement; }
	int GetLevelReq() { return level_req; }
private:

	int type = 0;
	int level_req = 0;
	int damage = 0;
	int str_requirement = 0;

	int agil_requirement = 0;
	std::string name;
};

#endif //WEAPONS_H
