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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Yells
{
    // Jin'do the Godbreaker
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    EMOTE_SHADOWS_OF_HAKKAR     = 2, // ID - 97172 Shadows of Hakkar
    SAY_JINDO_SPIRIT_PHASE      = 3,
    //SAY_PLAYER_KILL             = 4, // missing data

    // Spirit of Hakkar
    SAY_SPIRIT_SPIRIT_PHASE     = 0,
    SAY_SPIRIT_DEFEATED         = 1,

    // Jin'do the Godbreaker - Trigger
    SAY_JINDO_DEFEATED          = 0,

    // Shadow of Hakkar
    SAY_SHADOW_DEFEATED         = 0,
};

enum Spells
{
    // Jin'do the Godbreaker
    SPELL_DRAIN_SPIRIT_ESSENCE = 97321,
};

enum Events
{
    EVENT_TALK_INTRO = 1,
    EVENT_DRAIN_SPIRIT_ESSENCE
};

enum Phases
{
    PHASE_PRE_FIGHT = 1,
    PHASE_COMBAT    = 2
};



struct boss_jindo_the_godbreaker : public BossAI
{
    boss_jindo_the_godbreaker(Creature* creature) : BossAI(creature, DATA_JINDO_THE_GODBREAKER) { }

    void Reset() override
    {
        _Reset();
        events.SetPhase(PHASE_PRE_FIGHT);
        events.ScheduleEvent(EVENT_DRAIN_SPIRIT_ESSENCE, 1s, 0, PHASE_PRE_FIGHT);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        events.SetPhase(PHASE_COMBAT);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_TRIGGER_JINDO_INTRO:
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAurasDueToSpell(SPELL_COSMETIC_ALPHA_STATE_25_PCT);
                    events.ScheduleEvent(EVENT_TALK_INTRO, 11s, 0, PHASE_PRE_FIGHT);
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_PRE_FIGHT))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK_INTRO:
                    Talk(SAY_INTRO);
                    break;
                case EVENT_DRAIN_SPIRIT_ESSENCE:
                    DoCastSelf(SPELL_DRAIN_SPIRIT_ESSENCE);
                    events.Repeat(20s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_jindo_the_godbreaker()
{
    RegisterZulGurubCreatureAI(boss_jindo_the_godbreaker);
}
