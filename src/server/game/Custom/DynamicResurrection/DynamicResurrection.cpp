/* Copyright 
Author : Callmephil
Version : 3.3.5 / 4.3.4
Dynamic Resurrection is a simple script that add a "Resurrection Waypoint" near the latest boss killed in dungeon or raid. for faster Resurrection.
*/

#include "DynamicResurrection.h"

bool Dynamic_Resurrection::IsInDungeonOrRaid(Player* player)
{
	if (sMapStore.LookupEntry(player->GetMapId())->Instanceable())
		return true; // boolean need to return to a value
	return false;
}

bool Dynamic_Resurrection::CheckForSpawnPoint(Player* player)
{
	// Find Nearest Creature And Teleport.
	if (Creature* creature = player->FindNearestCreature(C_Resurrection_ENTRY, C_DISTANCE_CHECK_RANGE))
		return true;
	return false;
}

