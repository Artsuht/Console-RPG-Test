#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "BaseEntities.h"

void BeginCombat(Player& player, BaseEntities& entity);
void CheckCombat(Player& player, BaseEntities& entity);
int CalcDamage(Armour& armour, Weapons& weapons);

bool START_COMBAT;

inline void CheckCombat(Player& player, BaseEntities& entity) {
	if (START_COMBAT) 
	BeginCombat(player, entity);
}

void BeginCombat(Player& player, BaseEntities& entity)
{
	std::cout << "You've been caught by a : " << entity.GetEntName() << " with " << entity.GetEntHealth() << " health!" << std::endl;
	while (START_COMBAT)
	{
	}
}

int CalcDamage(Armour& armour, Weapons& weapons)
{

	return 0;
}


#endif //COMBAT_H
