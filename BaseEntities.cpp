#include "BaseEntities.h"

void BaseEntities::SpawnEntity(BaseEntities* entity, Map* map)
{
	while (map->GetMapAreaXY(entity->GetEntityX(), entity->GetEntityY()) != map->GetEmptyTile())
	{
		entity->RandEntityXY(map->GetMapMinimum(), map->GetMapMaximum());
	}
	map->UpdateMap(entity->GetEntityX(), entity->GetEntityY(), entity->GetEntityBody());
}

void BaseEntities::GenerateEntity(BaseEntities* entity[], Map* map, const int& quantity, const int& health, std::string tile)
{
	for (int i = 0; i < quantity; i++)
	{
		entity[i] = new BaseEntities(tile, health);
		entity[i]->SetNumEntities(quantity);
		SpawnEntity(entity[i], map);
	}
}

void BaseEntities::MoveEntity(BaseEntities* entity[], Map* map, Player* player)
{
	for (int i = 0; i < MAXIMUM_ENTITIES; i++)
	{
		if (!entity[i]->ChaseStatus())
		{
			TriggerChase(entity[i], map, player);
			map->UpdateMap(entity[i]->GetEntityX(), entity[i]->GetEntityY(), map->GetEmptyTile()); //Remove entity tile from old position
			entity[i]->RandEntityXY(2, 28);

			if (map->GetMapAreaXY(entity[i]->GetEntityX(), entity[i]->GetEntityY()) == map->GetEmptyTile()) //If the coordinates correspond to an empty space, move.
				map->UpdateMap(entity[i]->GetEntityX(), entity[i]->GetEntityY(), entity[i]->GetEntityBody());
			else //Re-roll buddy
				entity[i]->RandEntityXY(2, 28);
		}
		else
		{
			ChasePlayer(entity[i], map, player);
		}
	}
}

void BaseEntities::TriggerChase(BaseEntities* entity, Map* map, Player* player)
{
		
}

void BaseEntities::ChasePlayer(BaseEntities* entity, Map* map, Player* player) //Working on it, entity overwrites tiles. Test implementation
{
	map->UpdateMap(entity->GetEntityX(), entity->GetEntityY(), map->GetEmptyTile());

	if (map->GetMapAreaXY(player->GetPlayerX() + 2, entity->GetEntityY() + 1) == map->GetEmptyTile())
	{
		entity->SetEntityX(player->GetPlayerX() + 2);
		entity->SetEntityY(player->GetPlayerY() + 1);
	}
	else
	{
		entity->SetChase(false);
	}

	map->UpdateMap(entity->GetEntityX(), entity->GetEntityY(), entity->GetEntityBody());
}

bool BaseEntities::EmptyTile(BaseEntities* entity, int ent_y, int ent_x, Map* map)
{
	return (map->GetMapAreaXY(entity->GetEntityX(), entity->GetEntityY()) == map->GetEmptyTile());
}

inline int BaseEntities::SpitRand(int min, int max)
{
	std::random_device rd;  std::mt19937 gen(rd()); std::uniform_int_distribution<>distr(min, max); return distr(gen);
}

void BaseEntities::CleanUpEntities(BaseEntities* entity[], int size) 
{
	for (int i = 0; i < size; i++)
	{
		delete entity[i];
	}
}
