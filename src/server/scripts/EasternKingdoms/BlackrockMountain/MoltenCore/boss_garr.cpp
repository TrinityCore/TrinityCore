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

/* ScriptData
SDName: Boss_Garr
SD%Complete: 50
SDComment: Adds NYI
SDCategory: Molten Core
EndScriptData */

#include "ScriptMgr.h"
#include "molten_core.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    // Garr
    SPELL_ANTIMAGIC_PULSE    = 19492,
    SPELL_MAGMA_SHACKLES     = 19496,
    SPELL_ENRAGE             = 19516,
    SPELL_SEPARATION_ANXIETY = 23492,

    // Adds
    SPELL_ERUPTION          = 19497,
    SPELL_IMMOLATE          = 15732,
};

enum Events
{
    EVENT_ANTIMAGIC_PULSE    = 1,
    EVENT_MAGMA_SHACKLES     = 2,
};

struct boss_garr : public BossAI
{
    boss_garr(Creature* creature) : BossAI(creature, BOSS_GARR) { }

    void JustEngagedWith(Unit* victim) override
    {
        BossAI::JustEngagedWith(victim);
        events.ScheduleEvent(EVENT_ANTIMAGIC_PULSE, 25s);
        events.ScheduleEvent(EVENT_MAGMA_SHACKLES, 15s);
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
            case EVENT_ANTIMAGIC_PULSE:
                DoCast(me, SPELL_ANTIMAGIC_PULSE);
                events.ScheduleEvent(EVENT_ANTIMAGIC_PULSE, 10s, 15s);
                break;
            case EVENT_MAGMA_SHACKLES:
                DoCast(me, SPELL_MAGMA_SHACKLES);
                events.ScheduleEvent(EVENT_MAGMA_SHACKLES, 8s, 12s);
                break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_firesworn : public ScriptedAI
{
    npc_firesworn(Creature* creature) : ScriptedAI(creature) { }

    void ScheduleTasks()
    {
        // Timers for this are probably wrong
        _scheduler.Schedule(4s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_IMMOLATE);

            context.Repeat(5s, 10s);
        });

        // Separation Anxiety - Periodically check if Garr is nearby
        // ...and enrage if he is not.
        _scheduler.Schedule(3s, [this](TaskContext context)
        {
            if (!me->FindNearestCreature(NPC_GARR, 20.0f))
                DoCastSelf(SPELL_SEPARATION_ANXIETY);
            else if (me->HasAura(SPELL_SEPARATION_ANXIETY))
                me->RemoveAurasDueToSpell(SPELL_SEPARATION_ANXIETY);

            context.Repeat();
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ScheduleTasks();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        uint32 const health10pct = me->CountPctFromMaxHealth(10);
        uint32 health = me->GetHealth();
        if (int32(health) - int32(damage) < int32(health10pct))
        {
            damage = 0;
            DoCastVictim(SPELL_ERUPTION);
            me->DespawnOrUnsummon();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff,
            std::bind(&ScriptedAI::DoMeleeAttackIfReady, this));
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_boss_garr()
{
    RegisterMoltenCoreCreatureAI(boss_garr);
    RegisterMoltenCoreCreatureAI(npc_firesworn);
}
