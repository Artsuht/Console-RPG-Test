#include "BaseEntities.h"
#include "Combat.h"

void BaseEntities::SpawnEntity(BaseEntities& entity, Map& map)
{
	while (!EmptyTile(entity, entity.entity_x, entity.entity_y, map))
	{
		entity.RandEntityXY(map.GetMapMinimum(), map.GetMapMaximum());
	}
	map.UpdateMap(entity.entity_x, entity.entity_y, entity.entity_body);
}

void BaseEntities::GenerateEntity(Map& map, std::string ent_name, int quantity, int health, std::string ent_body)
{	
	BaseEntities new_entities(ent_name,ent_body, health);

	for (int i = 0; i < quantity; i++)
	{
		entity_duplicates.push_back(new_entities);
		SpawnEntity(entity_duplicates[i], map);
	}
}

void BaseEntities::MoveEntity(Map& map, Player& player)
{
	for (int i = 0; i < entity_duplicates.size(); i++)
	{
		if (!entity_duplicates[i].ChaseStatus())
		{
			if(!ongoing_chase) //One entity to chase the player at a time.
			TriggerChase(entity_duplicates[i], map, player);

			map.UpdateMap(entity_duplicates[i].entity_x, entity_duplicates[i].entity_y, map.GetEmptyTile());
			entity_duplicates[i].RandEntityXY(2, 29);

			while (!EmptyTile(entity_duplicates[i], entity_duplicates[i].entity_x, entity_duplicates[i].entity_y, map))
			{
				entity_duplicates[i].RandEntityXY(2, 29);
			}
			map.UpdateMap(entity_duplicates[i].entity_x, entity_duplicates[i].entity_y, entity_duplicates[i].entity_body);
		}
		else
		{
			ongoing_chase = true;
			ChasePlayer(entity_duplicates[i], map, player);
		}
	}
}

void BaseEntities::TriggerChase(BaseEntities& entity, Map& map, Player& player)
{
	//Is the entity within two tiles of the player. Vertically, Horizontally 
	if (entity.entity_x <= player.GetPlayerX() - 3 || entity.entity_y <= player.GetPlayerY() - 3 || entity.entity_x <= player.GetPlayerX() + 3, entity.entity_y <= player.GetPlayerY() + 3)
		entity.is_chasing_player = true;
	else
		entity.is_chasing_player = false;
}
////////////////TO DO
void BaseEntities::ChasePlayer(BaseEntities& entity, Map& map, Player& player) //Pretty much you cannot escape gg //How will this handle multiple entities
{
	int old_x = entity.entity_x;
	int old_y = entity.entity_y;

	extern bool START_COMBAT;
	START_COMBAT = IsCaughtPlayer(entity, player);
	CheckCombat(player, entity);

	if (EmptyTile(entity, entity.entity_x + player.GetPlayerX() + 1, entity.entity_y + player.GetPlayerY() + 1, map))
	{
		map.UpdateMap(entity.entity_x, entity.entity_y, map.GetEmptyTile());
		entity.entity_x = player.GetPlayerX() + 1;
		entity.entity_y = player.GetPlayerY() + 1;
		map.UpdateMap(entity.entity_x, entity.entity_y, entity.entity_body);
	}
	else
	{
		ongoing_chase = false;
		entity.is_chasing_player = false;

		entity.entity_x = old_x;
		entity.entity_y = old_y;
		
		map.UpdateMap(entity.entity_x, entity.entity_y, entity.entity_body); //Assumes previous position is unoccupied
	}
}

bool BaseEntities::IsCaughtPlayer(BaseEntities& entity, Player& player)
{
	return (entity.entity_x == player.GetPlayerX() - 1 || entity.entity_x == player.GetPlayerX() + 1 || entity.entity_y == player.GetPlayerY() - 1 || entity.entity_y == player.GetPlayerY() + 1);
}

bool BaseEntities::EmptyTile(BaseEntities& entity, int ent_y, int ent_x, Map& map)
{
	return (map.GetMapAreaXY(entity.entity_x, entity.entity_y) == map.GetEmptyTile());
}


inline int BaseEntities::SpitRand(int min, int max)
{
	std::random_device rd;  std::mt19937 gen(rd()); std::uniform_int_distribution<>distr(min, max); return distr(gen);
}

