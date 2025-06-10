/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "drak_tharon_keep.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum DredTexts
{
    EMOTE_SLASH                 = 0
};

enum DredSpells
{
    // Dred
    SPELL_BELLOWING_ROAR        = 22686,
    SPELL_GRIEVOUS_BITE         = 48920,
    SPELL_FEARSOME_ROAR         = 48849,
    SPELL_RAPTOR_CALL           = 59416,
    SPELL_MULTI_SLASH           = 48856,
    SPELL_PIERCING_SLASH        = 48878,
    SPELL_MANGLING_SLASH        = 48873,

    // Raptors
    SPELL_GUT_RIP               = 49710,
    SPELL_REND                  = 13738
};

enum DredEvents
{
    EVENT_BELLOWING_ROAR        = 1,
    EVENT_GRIEVOUS_BITE,
    EVENT_FEARSOME_ROAR,
    EVENT_RAPTOR_CALL,
    EVENT_MULTI_SLASH,
    EVENT_PIERCING_SLASH,
    EVENT_MANGLING_SLASH
};

enum DredMisc
{
    ACTION_RAPTOR_KILLED        = 1,
    DATA_RAPTORS_KILLED         = 2
};

// 27483 - King Dred
struct boss_king_dred : public BossAI
{
    boss_king_dred(Creature* creature) : BossAI(creature, DATA_KING_DRED), _raptorsKilled(0) { }

    void Reset() override
    {
        _Reset();
        _raptorsKilled = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_BELLOWING_ROAR, 15s, 25s);
        events.ScheduleEvent(EVENT_GRIEVOUS_BITE, 15s, 20s);
        events.ScheduleEvent(EVENT_FEARSOME_ROAR, 10s, 20s);
        events.ScheduleEvent(EVENT_RAPTOR_CALL, 15s, 20s);
        events.ScheduleEvent(EVENT_MULTI_SLASH, 18s, 22s);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_MULTI_SLASH)
            Talk(EMOTE_SLASH);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_MULTI_SLASH)
        {
            events.ScheduleEvent(EVENT_PIERCING_SLASH, 1s);
            events.ScheduleEvent(EVENT_MANGLING_SLASH, 3s);
        }

        if (spellInfo->Id == SPELL_RAPTOR_CALL)
        {
            /// @todo: This is wrong. Engage nearby alive not yet engaged raptor instead
            float x, y, z;

            me->GetClosePoint(x, y, z, me->GetCombatReach() / 3, 10.0f);
            me->SummonCreature(RAND(NPC_DRAKKARI_GUTRIPPER, NPC_DRAKKARI_SCYTHECLAW), x, y, z, 0, TEMPSUMMON_DEAD_DESPAWN, 1s);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_RAPTOR_KILLED)
            ++_raptorsKilled;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_RAPTORS_KILLED)
            return _raptorsKilled;

        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BELLOWING_ROAR:
                    DoCastAOE(SPELL_BELLOWING_ROAR);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_GRIEVOUS_BITE:
                    DoCastVictim(SPELL_GRIEVOUS_BITE);
                    events.Repeat(20s);
                    break;
                case EVENT_FEARSOME_ROAR:
                    DoCastAOE(SPELL_FEARSOME_ROAR);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_RAPTOR_CALL:
                    DoCastSelf(SPELL_RAPTOR_CALL);
                    events.Repeat(30s);
                    break;
                case EVENT_MULTI_SLASH:
                    DoCastSelf(SPELL_MULTI_SLASH);
                    events.Repeat(18s, 22s);
                    break;
                case EVENT_PIERCING_SLASH:
                    DoCastVictim(SPELL_PIERCING_SLASH);
                    break;
                case EVENT_MANGLING_SLASH:
                    DoCastVictim(SPELL_MANGLING_SLASH);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _raptorsKilled;
};

// 26641 - Drakkari Gutripper
struct npc_drakkari_gutripper : public ScriptedAI
{
    npc_drakkari_gutripper(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(10s, 15s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_GUT_RIP);
            task.Repeat(10s, 15s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* dred = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_KING_DRED)))
            dred->AI()->DoAction(ACTION_RAPTOR_KILLED);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 26628 - Drakkari Scytheclaw
struct npc_drakkari_scytheclaw : public ScriptedAI
{
    npc_drakkari_scytheclaw(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(10s, 15s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_REND);
            task.Repeat(10s, 15s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* dred = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_KING_DRED)))
            dred->AI()->DoAction(ACTION_RAPTOR_KILLED);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

class achievement_king_dred : public AchievementCriteriaScript
{
    public:
        achievement_king_dred() : AchievementCriteriaScript("achievement_king_dred")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Dred = target->ToCreature())
                if (Dred->AI()->GetData(DATA_RAPTORS_KILLED) >= 6)
                    return true;

            return false;
        }
};

void AddSC_boss_king_dred()
{
    RegisterDrakTharonKeepCreatureAI(boss_king_dred);
    RegisterDrakTharonKeepCreatureAI(npc_drakkari_gutripper);
    RegisterDrakTharonKeepCreatureAI(npc_drakkari_scytheclaw);
    new achievement_king_dred();
}
