#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "BaseEntities.h"

static void BeginCombat(Player& player, BaseEntities& entity);
void CheckCombat(Player& player, BaseEntities& entity);
static int CalcDamage(Armour& armour, Weapons& weapons);
static void Fight(Player& player, BaseEntities& entity);
static void FleeCombat(Player& player, int& flee_attempts);
static void Bargain(Player& player, int&  bargain_attempts);
static inline int SpitRand(int min, int max);

static constexpr int MAX_ATTEMPTS = 3;
bool START_COMBAT;

enum COMBAT_OPTIONS
{
	FIGHT,
	BARGAIN,
	FLEE
};

//Put all this into a source file

inline void CheckCombat(Player& player, BaseEntities& entity) {
	if (START_COMBAT) 
	BeginCombat(player, entity);
}

static void FleeCombat(Player& player, int& flee_attempts) //Chance based
{
	if (flee_attempts < MAX_ATTEMPTS)
	{
		if (SpitRand(0, 3) * 3 % 2)
		{
			std::cout << "You successfuly fled! Move to continue." << std::endl;
			START_COMBAT = false;
		}
		else
		{
			std::cout << "You failed to flee!" << std::endl;
			++flee_attempts;
		}
	}
	else
	{
		std::cout << "You are unable to flee.\n" << std::endl;
	}
}

static void Bargain(Player& player, int& bargain_attempts) //Chance based
{

}

static void BeginCombat(Player& player, BaseEntities& entity)
{
	int combat_options = 0;
	int bargain_attempts = 0;
	int flee_attempts = 0;

	system("cls");
	std::cout << "You've been caught by a " + entity.GetEntName() + "!\n" << std::endl;

	while (START_COMBAT)
	{
		std::cout << "Your Options:\n[0] Fight\n[1] Bargain\n[2] Flee\n" << std::endl;
		
		std::cin >> combat_options;

		switch (combat_options)
		{
		case FIGHT:
			Fight(player, entity);
			break;

		case BARGAIN:
			break;

		case FLEE:
			FleeCombat(player, flee_attempts);
			break;

		default:
			std::cout << "?" << std::endl;
			break;
		}
	}

	flee_attempts = 0;
	bargain_attempts = 0;
}

static int CalcDamage(Armour& armour, Weapons& weapons)
{
	return armour.GetDurability() - weapons.GetDamage();  //TO-DO Value of durability stays same, need to decrease for weapon and armour.
}

void Fight(Player& player, BaseEntities& entity)
{
	int prev_health = 0;

	while (player.GetPlayerHealth() > 0 && entity.GetEntHealth() > 0)
	{
		prev_health = player.GetPlayerHealth();

		player.SetPlayerHealth(CalcDamage(player.GetPlayerArmour(), entity.GetEntWeapon())); //Test Implementation, just needed values
		entity.SetEntHealth(CalcDamage(entity.GetEntArmour(), player.GetPlayerWeapon()));


		std::cout << "You took " << prev_health - player.GetPlayerHealth() << " Damage!" << std::endl;
		std::cout << "Current Health: " << player.GetPlayerHealth() << std::endl;
		std::cout << entity.GetEntName() << " Health: " << entity.GetEntHealth() << std::endl;

		std::cout << std::endl;
	}

	START_COMBAT = false;
	if (player.GetPlayerHealth() > 0)
	{
		std::cout << "You have beaten the " + entity.GetEntName() << std::endl; 
		entity.SetEntDead(true);
	}
	else
		std::cout << "You have died!" << std::endl;
}

static inline int SpitRand(int min, int max)
{
	std::random_device rd;  std::mt19937 gen(rd()); std::uniform_int_distribution<>distr(min, max); return distr(gen);
}


#endif //COMBAT_H