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
    EVENT_SHADOWBOLT            = 1,
    EVENT_CLEAVE                = 2,
    EVENT_MORTALSTRIKE          = 3,
    EVENT_RAISEDEAD             = 4
};

struct boss_baron_rivendare : public BossAI
{
    boss_baron_rivendare(Creature* creature) : BossAI(creature, TYPE_BARON), _raiseDead(false) { }

    void Reset() override
    {
        if (instance->GetData(TYPE_RAMSTEIN) == DONE)
            instance->SetData(TYPE_BARON, NOT_STARTED);

        _raiseDead = false;

        events.Reset();
        scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* who) override
    {
        events.ScheduleEvent(EVENT_SHADOWBOLT, 5s);
        events.ScheduleEvent(EVENT_CLEAVE, 8s);
        events.ScheduleEvent(EVENT_MORTALSTRIKE, 12s);
        events.ScheduleEvent(EVENT_RAISEDEAD, 15s);

        BossAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
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
                case EVENT_SHADOWBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SHADOWBOLT);

                    events.Repeat(10s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(7s, 17s);
                    break;
                case EVENT_MORTALSTRIKE:
                    DoCastVictim(SPELL_MORTALSTRIKE);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_RAISEDEAD:
                    // After 12 seconds, if the servant still lives,
                    // it will sacrifice itself to heal the caster
                    if (!_raiseDead)
                    {
                        DoCast(SPELL_RAISEDEAD);
                        _raiseDead = true;
                        events.Repeat(1s);
                    }
                    else
                    {
                        _raiseDead = false;
                        events.Repeat(12s);
                    }
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _raiseDead;
};

void AddSC_boss_baron_rivendare()
{
    RegisterStratholmeCreatureAI(boss_baron_rivendare);
}
