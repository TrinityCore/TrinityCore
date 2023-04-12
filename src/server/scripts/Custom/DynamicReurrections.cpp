/* Copyright 
Author : Callmephil
Version : 3.3.5 / 4.3.4
Dynamic Resurrection is a simple script that add a "Resurrection Waypoint" near the latest boss killed in dungeon or raid. for faster Resurrection.
*/

#include "DynamicResurrection.h"
#include "Config.h"

class Dynamic_Resurrections : public PlayerScript
{
public:
	Dynamic_Resurrections() : PlayerScript("Dynamic_Resurrections") {}

    void OnCreatureKill(Player* player, Creature* boss) override
    {
        if (sConfigMgr->GetBoolDefault("Dynamic_Resurrections.Enable", true))//读取配置文件
        {
            if (sDynRes->IsInDungeonOrRaid(player) && (boss->isWorldBoss() || boss->IsDungeonBoss()))
                //player->SummonCreature(C_Resurrection_ENTRY, boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, C_SPAWN_TIMER_TWO_HOURS);//org
                player->SummonCreature(C_Resurrection_ENTRY, boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, C_SPAWN_TIMER_TWO_HOURS, ObjectGuid::Empty);
                //player->SummonCreature(C_Resurrection_ENTRY, boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, Milliseconds(C_SPAWN_TIMER_TWO_HOURS));
                //另一种写法
        }
    }
};

void AddSC_Dynamic_Resurrections()
{
	new Dynamic_Resurrections();
}
