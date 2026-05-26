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

/* Timers requires update */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "steam_vault.h"

enum ThespiaTexts
{
    SAY_CLOUD                   = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3
};

enum ThespiaSpells
{
    SPELL_LIGHTNING_CLOUD       = 25033,
    SPELL_LUNG_BURST            = 31481,
    SPELL_ENVELOPING_WINDS      = 31718,

    SPELL_WATER_BOLT_VOLLEY     = 34449
};

enum ThespiaEvents
{
    EVENT_LIGHTNING_CLOUD       = 1,
    EVENT_LUNG_BURST,
    EVENT_ENVELOPING_WINDS
};

// 17797 - Hydromancer Thespia
struct boss_hydromancer_thespia : public BossAI
{
    boss_hydromancer_thespia(Creature* creature) : BossAI(creature, DATA_HYDROMANCER_THESPIA) { }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_LIGHTNING_CLOUD, 10s, 15s);
        events.ScheduleEvent(EVENT_LUNG_BURST, 7s, 12s);
        events.ScheduleEvent(EVENT_ENVELOPING_WINDS, 10s, 15s);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_LIGHTNING_CLOUD)
            if (roll_chance_i(50))
                Talk(SAY_CLOUD);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_LIGHTNING_CLOUD:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true))
                    DoCast(target, SPELL_LIGHTNING_CLOUD);
                events.Repeat(15s, 25s);
                break;
            case EVENT_LUNG_BURST:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                    DoCast(target, SPELL_LUNG_BURST);
                events.Repeat(7s, 12s);
                break;
            case EVENT_ENVELOPING_WINDS:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 35.0f, true))
                    DoCast(target, SPELL_ENVELOPING_WINDS);
                events.Repeat(10s, 15s);
                break;
            default:
                break;
        }
    }
};

// 17917 - Coilfang Water Elemental
struct npc_coilfang_waterelemental : public ScriptedAI
{
    npc_coilfang_waterelemental(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(4s, 12s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_WATER_BOLT_VOLLEY);
            task.Repeat(8s, 15s);
        });
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
};

void AddSC_boss_hydromancer_thespia()
{
    RegisterSteamVaultCreatureAI(boss_hydromancer_thespia);
    RegisterSteamVaultCreatureAI(npc_coilfang_waterelemental);
}
