
#ifndef IRON_DOCKS_H_
#define IRON_DOCKS_H_

#include "Map.h"
#include "CreatureAI.h"

#define DataHeader "ID"
#define IronDocksScriptName "instance_iron_docks"

uint32 const EncounterCount = 4;

enum DataTypes
{
	DATA_FLESHRENDER_NOKGAR = 0,
	DATA_GRIMRAIL_ENFORCER 	= 1,
	DATA_OHSIR              = 2,
	DATA_SKULLOC            = 3,
};

enum CreatureIds
{
    // Bosses
    BOSS_SKULLOC            = 83612,

    // Generic npc's
    NPC_BACKDRAFT           = 84464,
};


template<class AI>
CreatureAI* GetIronDocksAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(IronDocksScriptName))
                return new AI(creature);
    return NULL;
}

#endif // IRON_DOCKS_H_
