/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "stratholme.h"

enum Says
{
    SAY_BARON_RUN_START         = 0,
    SAY_BARON_RUN_BOSS_KILL     = 1,
    SAY_BARON_RUN_FAIL          = 2,
    SAY_EVENT_RAMSTEIN          = 3,
    SAY_EVENT_BARON             = 4
};

enum Spells
{
    SPELL_SHADOWBOLT            = 17393,
    SPELL_CLEAVE                = 15284,
    SPELL_MORTALSTRIKE          = 15708,
    SPELL_UNHOLY_AURA           = 17467,    // Unholy Aura is handled via DB
    SPELL_RAISEDEAD             = 17473,    // Triggers death pact (17471)
    SPELL_RAISE_DEAD1           = 17475,
    SPELL_RAISE_DEAD2           = 17476,
    SPELL_RAISE_DEAD3           = 17477,
    SPELL_RAISE_DEAD4           = 17478,
    SPELL_RAISE_DEAD5           = 17479,
    SPELL_RAISE_DEAD6           = 17480
};

enum BaronRivendareEvents
{
    EVENT_SPELL_SHADOWBOLT      = 1,
    EVENT_SPELL_CLEAVE          = 2,
    EVENT_SPELL_MORTALSTRIKE    = 3,
    EVENT_SUMMON_SKELETON       = 4
};

Position const PosSkeleton[6] =
{
    { 4017.403809f, -3339.703369f, 115.057655f, 5.487860f },
    { 4013.189209f, -3351.808350f, 115.052254f, 0.134280f },
    { 4017.738037f, -3363.478016f, 115.057274f, 0.723313f },
    { 4048.877197f, -3363.223633f, 115.054253f, 3.627735f },
    { 4051.777588f, -3350.893311f, 115.055351f, 3.066176f },
    { 4048.375977f, -3339.966309f, 115.055222f, 2.457497f }
};

struct boss_baron_rivendare : public BossAI
{
    boss_baron_rivendare(Creature* creature) : BossAI(creature, TYPE_BARON) { }

    bool RaiseDead;

    void Reset() override
    {
        if (instance->GetData(TYPE_RAMSTEIN) == DONE)
            instance->SetData(TYPE_BARON, NOT_STARTED);

        RaiseDead = false;
        events.Reset();
    }

    // can't use entercombat(), boss' dmg aura sets near
    // players in combat, before entering the room's door
    void AttackStart(Unit* /*who*/) override
    {
        if (instance->GetData(TYPE_BARON) == NOT_STARTED)
            instance->SetData(TYPE_BARON, IN_PROGRESS);

        events.ScheduleEvent(EVENT_SPELL_SHADOWBOLT, 5s);
        events.ScheduleEvent(EVENT_SPELL_CLEAVE, 8s);
        events.ScheduleEvent(EVENT_SPELL_MORTALSTRIKE, 12s);
        events.ScheduleEvent(EVENT_SUMMON_SKELETON, 15s);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
            summoned->AI()->AttackStart(target);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SetData(TYPE_BARON, DONE);
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
                case EVENT_SPELL_SHADOWBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SHADOWBOLT);
                    events.Repeat(10s);
                    break;
                case EVENT_SPELL_CLEAVE:
                    DoCastVictim(EVENT_SPELL_CLEAVE);
                    events.Repeat(7s, 17s);
                    break;
                case EVENT_SPELL_MORTALSTRIKE:
                    DoCastVictim(SPELL_MORTALSTRIKE);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_SUMMON_SKELETON:
                    if (!RaiseDead)
                    {
                        DoCast(SPELL_RAISEDEAD);
                        RaiseDead = true;
                        events.Repeat(1s);
                    }
                    else
                    {
                        for (uint8 i = 0; i < sizeof(PosSkeleton[0]); ++i)
                            me->SummonCreature(NPC_SEKELETON, PosSkeleton[i], TEMPSUMMON_TIMED_DESPAWN, 13000);

                        RaiseDead = false;
                        events.Repeat(15s);
                    }
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};


void AddSC_boss_baron_rivendare()
{
    RegisterStratholmeCreatureAI(boss_baron_rivendare);
}
