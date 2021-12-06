#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PhasingHandler.h"
#include "TemporarySummon.h"
#include "Log.h"
#include "Chat.h"
#include "ZoneScript.h"
#include "ScriptedGossip.h"

//160737 npc_combat_dummy
struct npc_combat_dummy : public ScriptedAI
{
    npc_combat_dummy(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
            player->KilledMonsterCredit(174954);
    }
};

enum ExileReach
{
    QUEST_STAND_YOUR_GROUND = 59927,
};

struct quest_stand_your_ground : public ScriptedAI
{
    quest_stand_your_ground(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_STAND_YOUR_GROUND)
        {
            Talk(1);
            me->SetFaction(14);
            me->SetReactState(REACT_AGGRESSIVE);
        }
    }

    void DamageTaken(Unit* attacker, uint32& /*damage*/) override
    {
        if (Player* player = attacker->ToPlayer())
            if (me->GetHealth() < me->CountPctFromMaxHealth(20))
                if (player->GetQuestStatus(QUEST_STAND_YOUR_GROUND))
                {
                    player->KilledMonsterCredit(155607);
                }
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
                player->KilledMonsterCredit(155607);
    }
};

void AddSC_zone_exiles_reach()
{
    RegisterCreatureAI(npc_combat_dummy);
    RegisterCreatureAI(quest_stand_your_ground);
}
