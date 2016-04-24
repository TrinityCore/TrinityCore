
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "SpellScript.h"
#include "MoveSplineInit.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "iron_docks.h"

class at_iron_docks_gauntlet_2 : public AreaTriggerScript
{
public:
    at_iron_docks_gauntlet_2() : AreaTriggerScript("at_iron_docks_gauntlet_2") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*entered*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* koramar = instance->GetCreature(BOSS_KORAMAR))
                koramar->AI()->DoAction(ACTION_GAUNTLET_2);
        return true;
    }
};

void AddSC_iron_docks()
{
    new at_iron_docks_gauntlet_2();
}
