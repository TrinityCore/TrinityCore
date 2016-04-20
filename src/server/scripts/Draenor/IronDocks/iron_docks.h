
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
    DATA_ZOGGOSH            = 3,
    DATA_KORAMAR            = 4,
	DATA_SKULLOC            = 5,
};

enum Actions
{
    ACTION_GAUNTLET_1 = 1,
    ACTION_GAUNTLET_2,
};

enum CreatureIds
{
    // Bosses
    BOSS_SKULLOC                    = 83612,
    BOSS_KORAMAR                    = 83613,
    BOSS_ZOGGOSH                    = 83616,

    // Generic npc's
    NPC_BACKDRAFT                   = 84464,
    NPC_BLACKHANDS_MIGHT_TURRET     = 84215,

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
