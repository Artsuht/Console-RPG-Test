#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Map.h"
#include "Armour.h"

class Player
{
public:
	Player(Map& map)
	{
		SpawnPlayer(map); 
	    Weapons b_sword("Bronze Sword", 1, METAL_SWORD_DAMAGE, 0, 0, MELEE_WEAPON); 
		Armour c_plate("Bronze Chestplate", 1, 0, 0, BRONZE_ARMOUR, BRONZE_ARMOUR_DUR);
		player_armour.push_back(c_plate);
		player_weapons.push_back(b_sword); //Starting Weapon
	}
	void MovePlayer(Map& map);
	void SpawnPlayer(Map& map);
	void DisplayInv();
	void UpdatePosition(Map& map, int p_x, int p_y);
	bool EmptyTile(Map& map, int p_x, int p_y);
	//Getters
	int GetPlayerX() { return player_x; }
	int GetPlayerY() { return player_y; }
	int GetPlayerHealth() { return player_health; }

	Weapons& GetPlayerWeapon() { return player_weapons[0]; }
	Armour& GetPlayerArmour() { return player_armour[0]; }
	//Set
	void SetPlayerHealth(int p_health) { player_health += p_health; }
private:

	enum CONTROLS
	{
		KEY_W = 0x57,
		KEY_A = 0x41,
		KEY_S = 0x53,
		KEY_D = 0x44,
	};

	//Player Stats
	int player_health = 100;
	int strength = 1;
	int agility = 1;

	int player_x = 0, player_y = 0;
	const std::string player_body = "@";
	//Inventory Items
	std::vector<Weapons>player_weapons;
	std::vector<Armour>player_armour;
};

#endif //PLAYER_H
