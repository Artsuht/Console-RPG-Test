#ifndef ARMOUR_H
#define ARMOUR_H

#include "Weapons.h"

//Put into namespace or seperate constants header?
constexpr int METAL_ARMOUR_DUR = 35;
constexpr int SILVER_ARMOUR_DUR = 25;
constexpr int BRONZE_ARMOUR_DUR = 15;

constexpr int MAX_ARMOUR = 4; //Maximum amount of armour that can be equipped

enum ARMOUR_TYPE 
{
	HELMET,
	BREASTPLATE,
	LEGGINGS,
	GAUNTLETS
};

enum ARMOUR_MATERIAL
{
	METAL_ARMOUR,
	SILVER_ARMOUR,
	BRONZE_ARMOUR
};

class Armour
{
public:
	Armour(std::string armr_name, int lvl_req, int str_req, int agil_req, int armr_type) : name(armr_name), level_req(lvl_req), str_requirement(str_req), agil_requirement(agil_req), type(armr_type){}
	//Getters
	std::string GetName() { return name; }
	int GetType() { return type; }
	int GetStrReq() { return str_requirement; }
	int GetAgilReq() { return agil_requirement; }
	int GetLevelReq() { return level_req; }
private:
	std::string name;
	int level_req = 0;
	int str_requirement = 0;
	int agil_requirement = 0;
	int type = 0;

};

#endif //ARMOUR_H