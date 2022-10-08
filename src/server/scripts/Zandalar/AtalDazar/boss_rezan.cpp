/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "Conversation.h"
#include "atal_dazar.h"

enum Spells {
    SPELL_TAIL                        = 255372, //Cast if player is behind
    SPELL_SERRATHED_TEETH             = 255434,
    SPELL_DEVOUR                      = 255421,
    SPELL_TERRIFYING_VISAGE           = 255371,
    SPELL_PURSUIT                     = 257407,
    SPELL_RIDE_VEHICLE                = 46598,
    SPELL_PILE_OF_BONES_AREATRIGGER   = 256608, //AT 11959
    SPELL_PILE_OF_BONES_SPAWN_NORMAL  = 256634,
    SPELL_PILE_OF_BONES_SPAWN_HEROIC  = 256720,
    SPELL_PILE_OF_BONES_SLOW          = 257483,
};

Position AreatriggerPositions[]{
    { -814.344f, 2241.63f, 641.538f },
    { -868.391f, 2245.54f, 642.03f  },
    { -887.726f, 2242.22f, 642.04f  },
    { -846.66f,  2247.46f, 641.774f },
    { -902.443f, 2238.86f, 642.331f },
    { -829.602f, 2247.23f, 641.842f },
    { -793.8f,   2239.09f, 641.832f },
    { -859.222f, 2256.25f, 643.136f },
    { -871.375f, 2258.77f, 643.438f },
    { -804.901f, 2254.52f, 641.964f },
    { -884.057f, 2257.15f, 642.643f },
    { -818.212f, 2259.57f, 642.465f },
    { -830.214f, 2265.17f, 642.486f },
    { -897.104f, 2259.22f, 641.901f },
    { -874.649f, 2273.9f,  642.642f },
    { -809.342f, 2272.22f, 641.905f },
    { -821.203f, 2279.28f, 642.488f },
    { -893.123f, 2276.57f, 642.583f },
    { -848.333f, 2288.46f, 642.486f },
    { -797.328f, 2282.58f, 641.182f },
    { -900.995f, 2285.5f,  641.773f },
    { -804.385f, 2293.2f,  641.488f },
    { -895.255f, 2298.0f,  642.486f },
    { -880.141f, 2301.81f, 642.501f },
    { -826.514f, 2306.46f, 642.699f },
    { -871.58f,  2311.03f, 642.487f },
    { -803.264f, 2310.29f, 641.707f },
    { -817.41f,  2313.88f, 641.638f },
    { -889.821f, 2315.4f,  642.486f },
    { -834.929f, 2321.18f, 643.028f },
    { -861.599f, 2322.33f, 642.5f   },
    { -872.771f, 2324.00f, 642.77f  },
    { -825.752f, 2329.17f, 642.247f },
    { -810.163f, 2327.19f, 641.401f },
    { -884.835f, 2331.72f, 642.487f },
    { -843.49f,  2335.39f, 642.765f },
    { -895.611f, 2334.97f, 642.425f },
    { -874.451f, 2340.77f, 643.405f },
    { -817.785f, 2342.43f, 641.914f },
    { -861.078f, 2344.69f, 642.685f },
    { -838.155f, 2345.16f, 642.733f },
    { -869.793f, 2352.61f,  642.515f},
};

enum Actions {
    ACTION_AREATRIGGER_ACTIVATED = 1,
};

enum Talks {
    TALK_BONE_PILE = 0,
    TALK_DEVOUR,
    TALK_PURSUIT,
};
enum Npcs {
    NPC_REANIMATED_RAPTOR = 129517,


};
enum Events {
    EVENT_TAIL = 1,
    EVENT_SERRATHED_TEETH,
    EVENT_DEVOUR,
    EVENT_TERRIFYING_VISAGE,
    EVENT_PURSUIT,
    EVENT_PURSUIT_TARGET,
    EVENT_PURSUIT_STOP,
    EVENT_DISMOUNT,
};

enum
{
  CONVERSATION_REZAN_DEATH = 6322,
};

///122963
struct boss_ataldazar_rezan : public BossAI
{
    boss_ataldazar_rezan(Creature* creature) : BossAI(creature, DATA_REZAN) {

        for (Position point : AreatriggerPositions)
            me->CastSpell(point, SPELL_PILE_OF_BONES_AREATRIGGER);
    }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
    }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* /*spell*/) override
    {
    }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
        for (Position point : AreatriggerPositions)
            me->CastSpell(point, SPELL_PILE_OF_BONES_AREATRIGGER);
    }

    void EnterCombat(Unit* who) override
    {
        // Events
        events.ScheduleEvent(EVENT_TAIL, urand(15000, 20000)); //timed event like onyxia
        events.ScheduleEvent(EVENT_TERRIFYING_VISAGE, 12400);
        events.ScheduleEvent(EVENT_SERRATHED_TEETH, 6000);
        events.ScheduleEvent(EVENT_PURSUIT, 21800);

        BossAI::EnterCombat(who);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_AREATRIGGER_ACTIVATED:
            {
                Talk(TALK_BONE_PILE);
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        if (me->HasUnitState(UNIT_STATE_CASTING))
            if (me->GetChannelSpellId() != SPELL_PURSUIT && me->GetChannelSpellId() != SPELL_DEVOUR)
                return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_TAIL:
            {

                me->CastSpell(me, SPELL_TAIL, true);
                events.ScheduleEvent(EVENT_TAIL, urand(15000, 20000));
                break;
            }
            case EVENT_TERRIFYING_VISAGE:
            {
                me->CastSpell(me, SPELL_TERRIFYING_VISAGE);
                events.ScheduleEvent(EVENT_TERRIFYING_VISAGE, 40900);
                break;
            }
            case EVENT_SERRATHED_TEETH:
            {
                DoCastVictim(SPELL_SERRATHED_TEETH);
                events.ScheduleEvent(EVENT_SERRATHED_TEETH, 38000);
                break;
            }
            case EVENT_PURSUIT:
            {
                events.DelayEvents(18000);
                Talk(TALK_PURSUIT);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                {
                    me->CastSpell(target, SPELL_PURSUIT);
                    storedtarget = target;
                }
                events.ScheduleEvent(EVENT_PURSUIT, urand(38000, 44000));
                events.ScheduleEvent(EVENT_PURSUIT_TARGET, 1);
                events.ScheduleEvent(EVENT_PURSUIT_STOP, 18000);
                break;
            }
            case EVENT_PURSUIT_TARGET:
            {
                if(storedtarget)
                {
                    if (me->GetDistance(storedtarget->GetPosition()) > 7)
                    {
                        me->ClearUnitState(UNIT_STATE_CASTING);
                        me->GetMotionMaster()->MoveFollow(storedtarget, 0, 0.0f);
                    }
                    else
                    {
                        storedtarget->CastSpell(me, SPELL_RIDE_VEHICLE);
                        Talk(TALK_DEVOUR);
                        me->CastSpell(storedtarget, SPELL_DEVOUR);

                        events.ScheduleEvent(EVENT_PURSUIT_STOP, 0);
                        events.ScheduleEvent(EVENT_DISMOUNT, 8000);
                    }
                }
                events.ScheduleEvent(EVENT_PURSUIT_TARGET, 500);
                break;
            }
            case EVENT_PURSUIT_STOP:
            {
                events.CancelEvent(EVENT_PURSUIT_TARGET);
                break;
            }
            case EVENT_DISMOUNT:
            {
                if (me->HasAura(SPELL_RIDE_VEHICLE))
                    me->RemoveAura(SPELL_RIDE_VEHICLE);
            }
            default:
                break;
            }

        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer) override
    {
        _JustDied();
        instance->SetBossState(DATA_REZAN, DONE);
        std::list<Player*> playerList;
        me->GetPlayerListInGrid(playerList, 100.0f);
        for (auto player : playerList)
        {
			Conversation::CreateConversation(CONVERSATION_REZAN_DEATH, player, player->GetPosition(), { player->GetGUID() });
            if (player->HasAura(SPELL_UNSTABLE_HEX))
            {
                int cont = instance->GetData(DATA_ACHIEVEMENT_COUNT);
                instance->SetData(DATA_ACHIEVEMENT_COUNT, cont++);
                break;
            }
        }
    }

private:
    Unit* storedtarget;
};

struct areatrigger_ancient_bones : AreaTriggerAI
{
    areatrigger_ancient_bones(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (unit)
        {
            if (Creature* rezan = unit->FindNearestCreature(NPC_REZAN, 100, true))
                if(rezan->IsInCombat() == true)
                {
                    if (!rezan->GetMap()->IsHeroic() && !rezan->GetMap()->IsMythic())
                        if (unit == rezan)
                            return;
                    if (unit != rezan && unit->IsPlayer())
                        unit->AddAura(SPELL_PILE_OF_BONES_SLOW);
                    rezan->GetAI()->DoAction(ACTION_AREATRIGGER_ACTIVATED);
                    if (rezan->GetMap()->IsMythic())
                        rezan->CastSpell(at->GetPosition(), SPELL_PILE_OF_BONES_SPAWN_HEROIC, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
                    else
                        rezan->CastSpell(at->GetPosition(), SPELL_PILE_OF_BONES_SPAWN_NORMAL, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
                    at->Remove();
                }
        }
    }
};

void AddSC_boss_rezan()
{
    RegisterCreatureAI(boss_ataldazar_rezan);
    RegisterAreaTriggerAI(areatrigger_ancient_bones);
}
