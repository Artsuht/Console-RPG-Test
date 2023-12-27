#include "BaseEntities.h"
#include "Combat.h"

void BaseEntities::SpawnEntity(BaseEntities& entity, Map& map)
{
	while (!EmptyTile(entity.entity_x, entity.entity_y, map))
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

void BaseEntities::MoveEntity(Map& map, Player& player) //Maybe I have way too many things going on in one function
{
	for (int i = 0; i < entity_duplicates.size(); i++)
	{
		if (!entity_duplicates[i].is_chasing_player)
		{
			if(!ongoing_chase) //One entity to chase the player at a time.
			TriggerChase(entity_duplicates[i], map, player);

			map.UpdateMap(entity_duplicates[i].entity_x, entity_duplicates[i].entity_y, map.GetEmptyTile());
			entity_duplicates[i].RandEntityXY(map.GetMapMinimum(), map.GetMapMinimum());

			while (!EmptyTile(entity_duplicates[i].entity_x, entity_duplicates[i].entity_y, map))
			{
				entity_duplicates[i].RandEntityXY(map.GetMapMinimum(), map.GetMapMaximum());
			}
			map.UpdateMap(entity_duplicates[i].entity_x, entity_duplicates[i].entity_y, entity_duplicates[i].entity_body);
		}
		else
		{
			ongoing_chase = true;
			ChasePlayer(entity_duplicates[i], map, player);
		}

		if (entity_duplicates[i].is_dead)
		{
			map.UpdateMap(entity_duplicates[i].entity_x, entity_duplicates[i].entity_y, map.GetEmptyTile());
			entity_duplicates.erase(entity_duplicates.begin() + i);
		}
	}
}

void BaseEntities::TriggerChase(BaseEntities& entity, Map& map, Player& player)
{
	//Is the entity within two tiles of the player. Vertically, Horizontally 
	if (entity.entity_x <= player.GetPlayerX() - 3 || entity.entity_y <= player.GetPlayerY() - 3 || entity.entity_x <= player.GetPlayerX() + 3 || entity.entity_y <= player.GetPlayerY() + 3)
		entity.is_chasing_player = true;
	else
		entity.is_chasing_player = false;
}

void BaseEntities::ChasePlayer(BaseEntities& entity, Map& map, Player& player)
{
	if (entity.entity_x < player.GetPlayerX() && EmptyTile(entity.entity_x + 1,entity.entity_y,map))
	{
		++entity.entity_x;
		UpdatePosition(entity, map, entity.entity_x - 1, entity.entity_y);
	}
	else if (entity.entity_x > player.GetPlayerX() && EmptyTile(entity.entity_x - 1, entity.entity_y, map))
	{
		--entity.entity_x;
		UpdatePosition(entity, map, entity.entity_x + 1, entity.entity_y);
	}
	else if (entity.entity_y < player.GetPlayerY() && EmptyTile(entity.entity_x, entity.entity_y + 1, map))
	{
		++entity.entity_y;
		UpdatePosition(entity, map, entity.entity_x, entity.entity_y - 1);
	}
	else if (entity.entity_y > player.GetPlayerY() && EmptyTile(entity.entity_x, entity.entity_y - 1, map))
	{
		--entity.entity_y;
		UpdatePosition(entity, map, entity.entity_x, entity.entity_y + 1);
	}
	else //Will stop entity from chasing player if it runs into an obstacle.
	{
		entity.is_chasing_player = false;
		ongoing_chase = false;
	}

	extern bool start_combat;
	start_combat = IsCaughtPlayer(entity, player);
	if (start_combat)
	{
		entity.is_chasing_player = false;
		ongoing_chase = false;
		BeginCombat(player, entity);
	}
}

void BaseEntities::UpdatePosition(BaseEntities& entity, Map& map, int p_x, int p_y)
{
	map.UpdateMap(p_x, p_y, map.GetEmptyTile());
	map.UpdateMap(entity.entity_x, entity.entity_y, entity.entity_body);
	system("cls");
	map.DrawMap();
}

bool BaseEntities::IsCaughtPlayer(BaseEntities& entity, Player& player)
{
	if (entity.entity_x == player.GetPlayerX() && entity.entity_y == player.GetPlayerY() + 1) //One below player
		return true;
	if(entity.entity_x == player.GetPlayerX() && entity.entity_y == player.GetPlayerY() - 1) //One above player
		return true;
	if (entity.entity_x == player.GetPlayerX() + 1 && entity.entity_y == player.GetPlayerY()) //Right of player
		return true;
    if (entity.entity_x == player.GetPlayerX() - 1 && entity.entity_y == player.GetPlayerY()) //Left of player
		return true;

	return false;
}

bool BaseEntities::EmptyTile(int e_x, int e_y, Map& map)
{
	return (map.GetMapAreaXY(e_x, e_y) == map.GetEmptyTile());
}

inline int BaseEntities::SpitRand(int min, int max)
{
	std::random_device rd;  std::mt19937 gen(rd()); std::uniform_int_distribution<>distr(min, max); return distr(gen);
}

