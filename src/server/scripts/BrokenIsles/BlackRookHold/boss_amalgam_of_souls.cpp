/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "black_rook_hold.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum
{
    SPELL_REAP_SOUL                 = 194956,

    SPELL_SOUL_ECHOES               = 194966,
    SPELL_SOUL_ECHOES_CLONE_CASTER  = 194981,
    SPELL_SOUL_ECHOES_DAMAGE        = 194960,
    
    SPELL_SWIRLING_SCYTHE           = 195254,
    SPELL_SWIRLING_SCYTHE_DAMAGE    = 196517,

    // Heroic
    SPELL_CALL_SOULS                = 196078,
    SPELL_CALL_SOULS_VISUAL         = 196925,
    SPELL_SOULGORGE                 = 196930,

    SPELL_SOUL_BURST                = 196587,

    ACTION_SOUL_KILLED              = 1,
};

// 98542
struct boss_amalgam_of_souls : public BossAI
{
    boss_amalgam_of_souls(Creature* creature) : BossAI(creature, DATA_AMALGAM_OF_SOULS) { }

    void Reset() override
    {
        BossAI::Reset();

        restlessSoulsCount = 0;
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_REAP_SOUL, 16s);
        events.ScheduleEvent(SPELL_SOUL_ECHOES, 10s, 20s);
        events.ScheduleEvent(SPELL_SWIRLING_SCYTHE, 12s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (IsHeroic())
        {
            if (me->HealthWillBeBelowPctDamaged(50, damage))
            {
                me->CastSpell(nullptr, SPELL_CALL_SOULS, false);
                events.ScheduleEvent(SPELL_CALL_SOULS, 3s);
                events.ScheduleEvent(SPELL_SOUL_BURST, 33s);
            }
        }
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_SOUL_KILLED)
            return;

        if (--restlessSoulsCount == 0)
        {
            me->RemoveAurasDueToSpell(SPELL_CALL_SOULS_VISUAL);
            events.CancelEvent(SPELL_SOUL_BURST);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_REAP_SOUL:
            {
                DoCast(SPELL_REAP_SOUL);
                events.Repeat(16s);
                break;
            }
            case SPELL_SOUL_ECHOES:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    DoCast(target, SPELL_SOUL_ECHOES);

                events.Repeat(10s, 20s);
                break;
            }
            case SPELL_SWIRLING_SCYTHE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    DoCast(target, SPELL_SWIRLING_SCYTHE);

                events.Repeat(12s);
                break;
            }
            case SPELL_CALL_SOULS:
            {
                DoCastAOE(SPELL_CALL_SOULS_VISUAL);

                // Summon 7 Restless Souls with 1 to 2 seconds separation
                restlessSoulsCount = 7;
                me->GetScheduler().Schedule(1s, 2s, [this](TaskContext context)
                {
                    Position pos;
                    GetRandPosFromCenterInDist(me, 10.f, pos);
                    me->SummonCreature(NPC_RESTLESS_SOUL, pos);

                    if (context.GetRepeatCounter() <= 6)
                        context.Repeat(1s, 2s);
                });
                break;
            }
            default:
                break;
        }
    }

private:
    uint8 restlessSoulsCount;
};

// 99090
struct npc_aos_soul_echo : public ScriptedAI
{
    npc_aos_soul_echo(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        me->setFaction(16);
        summoner->CastSpell(me, SPELL_SOUL_ECHOES_CLONE_CASTER, true);

        me->GetScheduler().Schedule(5s, [](TaskContext context)
        {
            GetContextUnit()->CastSpell(nullptr, SPELL_SOUL_ECHOES_DAMAGE, false);
            GetContextCreature()->DespawnOrUnsummon();
        });
    }
};

// 99664
struct npc_aos_restless_soul : public ScriptedAI
{
    npc_aos_restless_soul(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetReactState(REACT_PASSIVE);
        me->GetMotionMaster()->MovePoint(1, *summoner, false);
    }

    void EnterCombat(Unit* /*who*/) override { }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            me->DespawnOrUnsummon();
            me->CastSpell(nullptr, SPELL_SOULGORGE, true);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (TempSummon* meTempSummon = me->ToTempSummon())
            if (Unit* summoner = meTempSummon->GetSummoner())
                if (summoner->IsCreature() && summoner->IsAIEnabled)
                    summoner->ToCreature()->AI()->DoAction(ACTION_SOUL_KILLED);
    }
};

//AT : 9899
//Spell : 195254
struct at_aos_swirling_scythe : AreaTriggerAI
{
    at_aos_swirling_scythe(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
            unit->CastSpell(unit, SPELL_SWIRLING_SCYTHE_DAMAGE, true);
    }
};

void AddSC_boss_amalgam_of_souls()
{
    RegisterCreatureAI(boss_amalgam_of_souls);
    RegisterCreatureAI(npc_aos_soul_echo);
    RegisterCreatureAI(npc_aos_restless_soul);

    RegisterAreaTriggerAI(at_aos_swirling_scythe);
}
