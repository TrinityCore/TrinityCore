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
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "stratholme.h"

enum Texts
{
    EMOTE_RAISE_DEAD    = 0,    // %s raises an undead servant back to life!
    EMOTE_DEATH_PACT    = 1     // %s attempts to cast Death Pact on his servants!
};

enum Spells
{
    SPELL_SHADOWBOLT    = 17393,
    SPELL_CLEAVE        = 15284,
    SPELL_MORTALSTRIKE  = 15708,
    SPELL_DEATH_PACT_1  = 17698, // Heal Rivendare and damage skeleton
    SPELL_DEATH_PACT_2  = 17471, // Visual effect
    SPELL_DEATH_PACT_3  = 17472, // Instant kill self only
    SPELL_RAISE_DEAD    = 17473, // Inits. 17698 and 17471
    SPELL_RAISE_DEAD_1  = 17475,
    SPELL_RAISE_DEAD_2  = 17476,
    SPELL_RAISE_DEAD_3  = 17477,
    SPELL_RAISE_DEAD_4  = 17478,
    SPELL_RAISE_DEAD_5  = 17479,
    SPELL_RAISE_DEAD_6  = 17480,
    SPELL_UNHOLY_AURA   = 17467
};

enum BaronRivendareEvents
{
    EVENT_SHADOWBOLT    = 1,
    EVENT_CLEAVE        = 2,
    EVENT_MORTALSTRIKE  = 3,
    EVENT_RAISE_DEAD    = 4
};

uint32 const RaiseDeadSpells[6] =
{
    SPELL_RAISE_DEAD_1, SPELL_RAISE_DEAD_2, SPELL_RAISE_DEAD_3,
    SPELL_RAISE_DEAD_4, SPELL_RAISE_DEAD_5, SPELL_RAISE_DEAD_6
};

struct boss_baron_rivendare : public BossAI
{
public:
    boss_baron_rivendare(Creature* creature) : BossAI(creature, TYPE_BARON), RaiseDead(false) { }

    void Reset() override
    {
        // needed until re-write of instance scripts is done
        if (instance->GetData(TYPE_RAMSTEIN) == DONE)
            instance->SetData(TYPE_BARON, NOT_STARTED);

        BossAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        // needed until re-write of instance scripts is done
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
        // needed until re-write of instance scripts is done
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
                        DoCastSelf(SPELL_RAISE_DEAD);
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
                default:
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

// Death Pact 3 (17472) needs to be casted by the skeletons
struct npc_summoned_skeleton : public ScriptedAI
{
    npc_summoned_skeleton(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DEATH_PACT_2)
            DoCastSelf(SPELL_DEATH_PACT_3, true);
    }
};

void AddSC_boss_baron_rivendare()
{
    RegisterStratholmeCreatureAI(boss_baron_rivendare);
    RegisterStratholmeCreatureAI(npc_summoned_skeleton);
}
