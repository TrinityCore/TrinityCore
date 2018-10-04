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

enum Texts
{
    EMOTE_RAISE_DEAD            = 0,    // %s raises an undead servant back to life!
    EMOTE_DEATH_PACT            = 1     // %s attempts to cast Death Pact on his servants!     
};

enum BaronRun
{
    YELL_BARON_RUN_START        = 0,    // Intruders! More pawns of the Argent Dawn, no doubt. I already count one of their number among my prisoners. Withdraw from my domain before she is executed!
    YELL_BARON_RUN_BOSS_KILL    = 1,    // The Ash'ari Crystals have been destroyed! The Slaughterhouse is vulnerable!
    YELL_BARON_RUN_FAIL         = 2,    // Unknown
    YELL_EVENT_RAMSTEIN         = 3,    // So you see fit to toy with the Lich King's creations? Ramstein, be sure to give the intruders a proper greeting.
    YELL_EVENT_BARON            = 4,    // Time to take matters into my own hands. Come. Enter my domain and challenge the might of the Scourge!
};

enum Spells
{
    SPELL_SHADOWBOLT            = 17393,
    SPELL_CLEAVE                = 15284,
    SPELL_MORTALSTRIKE          = 15708,
    SPELL_DEATH_PACT            = 17471,
    SPELL_RAISE_DEAD            = 17473,
    SPELL_UNHOLY_AURA           = 17467
};

// Raise Dead (1-6) - Summon Skeletons (positions defined in database)
uint32 const RaiseDeadSpells[6] =
{
    17475, 17476, 17477,
    17478, 17479, 17480
};

enum BaronRivendareEvents
{
    EVENT_SHADOWBOLT            = 1,
    EVENT_CLEAVE                = 2,
    EVENT_MORTALSTRIKE          = 3,
    EVENT_RAISE_DEAD            = 4
};

struct boss_baron_rivendare : public BossAI
{
    boss_baron_rivendare(Creature* creature) : BossAI(creature, TYPE_BARON), RaiseDead(false) { }

    void Reset() override
    {
        DoCastSelf(SPELL_UNHOLY_AURA);

        if (instance->GetData(TYPE_RAMSTEIN) == DONE)
            instance->SetData(TYPE_BARON, NOT_STARTED);

        BossAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        if (instance->GetData(TYPE_BARON) == NOT_STARTED)
            instance->SetData(TYPE_BARON, IN_PROGRESS);

        events.ScheduleEvent(EVENT_SHADOWBOLT, 5s);
        events.ScheduleEvent(EVENT_CLEAVE, 8s);
        events.ScheduleEvent(EVENT_MORTALSTRIKE, 12s);
        events.ScheduleEvent(EVENT_RAISE_DEAD, 15s);

        BossAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        instance->SetData(TYPE_BARON, DONE);

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
                case EVENT_RAISE_DEAD:
                    if (!RaiseDead)
                    {
                        DoCast(SPELL_RAISE_DEAD);

                        for (uint32 const& summonSkeletons : RaiseDeadSpells)
                            DoCastSelf(summonSkeletons, true);

                        RaiseDead = true;
                        Talk(EMOTE_RAISE_DEAD);
                    }
                    else
                    {
                        RaiseDead = false;
                        Talk(EMOTE_DEATH_PACT);
                    }
                    events.Repeat(12s);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool RaiseDead;
};

void AddSC_boss_baron_rivendare()
{
    RegisterStratholmeCreatureAI(boss_baron_rivendare);
}
