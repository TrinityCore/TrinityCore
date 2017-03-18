/* Copyright 
Author : Callmephil
Version : 3.3.5 / 4.3.4
Dynamic Resurrection is a simple script that add a "Resurrection Waypoint" near the latest boss killed in dungeon or raid. for faster Resurrection.
*/

#ifndef DYNAMIC_RESURRECTION
#define DYNAMIC_RESURRECTION

#include "Player.h"
#include "DBCStores.h"

class Player;

enum WAYPOINT_CREATURE
{
	C_Resurrection_ENTRY = 1, // change this as you wishes
	C_DISTANCE_CHECK_RANGE = 1000, // change this (in yards)
	C_SPAWN_TIMER_TWO_HOURS = 1200000, // change this (in miliseconds)
};

class TC_GAME_API Dynamic_Resurrection
{
public:
	static Dynamic_Resurrection* instance()
	{
		static Dynamic_Resurrection instance;
		return &instance;
	}
	
	bool IsInDungeonOrRaid(Player* player);
	bool CheckForSpawnPoint(Player* player);
	void DynamicResurrection(Player* player)
	{
		// Find Nearest Creature And Teleport.
		if (Creature* creature = player->FindNearestCreature(C_Resurrection_ENTRY, C_DISTANCE_CHECK_RANGE))
			player->TeleportTo(player->GetMapId(), creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), 1);
		// Revive Player with 25 %
		player->ResurrectPlayer(0.25);
		player->SpawnCorpseBones();
	}
};
#define sDynRes Dynamic_Resurrection::instance()

#endif