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

/*
 * Everything should be rechecked with sniffs
 * The way beams are handled out of combat requires additional research. It seems like it's timed
   and is enabled and disabled from time to time, not used all the time
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"

enum HydrossTexts
{
    SAY_AGGRO                       = 0,
    SAY_SWITCH_TO_CLEAN             = 1,
    SAY_CLEAN_SLAY                  = 2,
    SAY_CLEAN_DEATH                 = 3,
    SAY_SWITCH_TO_CORRUPT           = 4,
    SAY_CORRUPT_SLAY                = 5,
    SAY_CORRUPT_DEATH               = 6
};

enum HydrossSpells
{
    SPELL_WATER_TOMB                = 38235,
    SPELL_VILE_SLUDGE               = 38246,

    SPELL_BERSERK                   = 27680,       // This spell need verification
    SPELL_CORRUPTION                = 37961,

    SPELL_MARK_OF_HYDROSS_1         = 38215,
    SPELL_MARK_OF_HYDROSS_2         = 38216,
    SPELL_MARK_OF_HYDROSS_3         = 38217,
    SPELL_MARK_OF_HYDROSS_4         = 38218,
    SPELL_MARK_OF_HYDROSS_5         = 38231,
    SPELL_MARK_OF_HYDROSS_6         = 40584,

    SPELL_MARK_OF_CORRUPTION_1      = 38219,
    SPELL_MARK_OF_CORRUPTION_2      = 38220,
    SPELL_MARK_OF_CORRUPTION_3      = 38221,
    SPELL_MARK_OF_CORRUPTION_4      = 38222,
    SPELL_MARK_OF_CORRUPTION_5      = 38230,
    SPELL_MARK_OF_CORRUPTION_6      = 40583,

    SPELL_SUMMON_PURIFIED_SPAWN_1   = 38198,
    SPELL_SUMMON_PURIFIED_SPAWN_2   = 38199,
    SPELL_SUMMON_PURIFIED_SPAWN_3   = 38200,
    SPELL_SUMMON_PURIFIED_SPAWN_4   = 38201,

    SPELL_SUMMON_CORRUPTED_SPAWN_1  = 38188,
    SPELL_SUMMON_CORRUPTED_SPAWN_2  = 38189,
    SPELL_SUMMON_CORRUPTED_SPAWN_3  = 38190,
    SPELL_SUMMON_CORRUPTED_SPAWN_4  = 38191,

    SPELL_BLUE_BEAM                 = 38015,
    SPELL_SUMMON_WATER_ELEMENTAL    = 36459,       // NYI, OOC
    SPELL_PURIFY_ELEMENTAL          = 36461        // NYI, OOC
};

enum HydrossEvents
{
    EVENT_MARK_OF_HYDROSS           = 1,
    EVENT_WATER_TOMB,
    EVENT_SWITCH_TO_CORRUPTED,

    EVENT_MARK_OF_CORRUPTION,
    EVENT_VILE_SLUDGE,
    EVENT_SWITCH_TO_PURIFIED,

    EVENT_BERSERK,

    EVENT_BLUE_BEAMS
};

enum HydrossMisc
{
    SWITCH_RADIUS                   = 18,
    NPC_HYDROSS_BEAM_HELPER         = 21933
};

#define HYDROSS_X                   -239.439f
#define HYDROSS_Y                   -363.481f

// 21216 - Hydross the Unstable
struct boss_hydross_the_unstable : public BossAI
{
    boss_hydross_the_unstable(Creature* creature) : BossAI(creature, BOSS_HYDROSS_THE_UNSTABLE),
        _markOfHydrossCount(0), _markOfCorruptionCount(0), _corruptedForm(false) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_BLUE_BEAMS, 5s);
    }

    void Reset() override
    {
        HandleBeamHelpers(true);

        me->SetMeleeDamageSchool(SPELL_SCHOOL_FROST);
        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);

        me->RemoveAurasDueToSpell(SPELL_CORRUPTION);

        _Reset();
        _markOfHydrossCount = 0;
        _markOfCorruptionCount = 0;
        _corruptedForm = false;
    }

    void HandleBeamHelpers(bool reset)
    {
        std::list<Creature*> helpersList;
        me->GetCreatureListWithEntryInGrid(helpersList, NPC_HYDROSS_BEAM_HELPER);
        if (!helpersList.empty())
        {
            for (Creature* helper : helpersList)
                if (reset)
                    helper->InterruptNonMeleeSpells(false);
                else
                    helper->CastSpell(helper, SPELL_BLUE_BEAM);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);

        _JustEngagedWith(who);

        events.ScheduleEvent(EVENT_MARK_OF_HYDROSS, 15s);
        events.ScheduleEvent(EVENT_WATER_TOMB, 7s);
        events.ScheduleEvent(EVENT_SWITCH_TO_CORRUPTED, 2500ms);

        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void JustReachedHome() override
    {
        events.ScheduleEvent(EVENT_BLUE_BEAMS, 5s);
        _JustReachedHome();
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(_corruptedForm ? SAY_CORRUPT_SLAY : SAY_CLEAN_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(_corruptedForm ? SAY_CORRUPT_DEATH : SAY_CLEAN_DEATH);

        _JustDied();
    }

    void UpdateOutOfCombatEvents(uint32 diff)
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BLUE_BEAMS:
                    HandleBeamHelpers(false);
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateOutOfCombatEvents(diff);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Purified form
                case EVENT_MARK_OF_HYDROSS:
                    if (_markOfHydrossCount <= 5)
                    {
                        uint32 markSpell = 0;

                        switch (_markOfHydrossCount)
                        {
                            case 0: markSpell = SPELL_MARK_OF_HYDROSS_1; break;
                            case 1: markSpell = SPELL_MARK_OF_HYDROSS_2; break;
                            case 2: markSpell = SPELL_MARK_OF_HYDROSS_3; break;
                            case 3: markSpell = SPELL_MARK_OF_HYDROSS_4; break;
                            case 4: markSpell = SPELL_MARK_OF_HYDROSS_5; break;
                            case 5: markSpell = SPELL_MARK_OF_HYDROSS_6; break;
                        }

                        DoCastVictim(markSpell);

                        if (_markOfHydrossCount < 5)
                            ++_markOfHydrossCount;
                    }
                    events.Repeat(15s);
                    break;
                case EVENT_WATER_TOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                        DoCast(target, SPELL_WATER_TOMB);
                    events.Repeat(7s);
                    break;
                case EVENT_SWITCH_TO_CORRUPTED:
                    if (!me->IsWithinDist2d(HYDROSS_X, HYDROSS_Y, SWITCH_RADIUS))
                    {
                        DoCastSelf(SPELL_CORRUPTION);
                        _markOfCorruptionCount = 0;
                        _corruptedForm = true;

                        Talk(SAY_SWITCH_TO_CORRUPT);
                        ResetThreatList();
                        HandleBeamHelpers(true);

                        DoCastSelf(SPELL_SUMMON_CORRUPTED_SPAWN_1);
                        DoCastSelf(SPELL_SUMMON_CORRUPTED_SPAWN_2);
                        DoCastSelf(SPELL_SUMMON_CORRUPTED_SPAWN_3);
                        DoCastSelf(SPELL_SUMMON_CORRUPTED_SPAWN_4);

                        me->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);

                        events.CancelEvent(EVENT_MARK_OF_HYDROSS);
                        events.CancelEvent(EVENT_WATER_TOMB);
                        events.CancelEvent(EVENT_SWITCH_TO_CORRUPTED);

                        events.ScheduleEvent(EVENT_MARK_OF_CORRUPTION, 15s);
                        events.ScheduleEvent(EVENT_VILE_SLUDGE, 7s);
                        events.ScheduleEvent(EVENT_SWITCH_TO_PURIFIED, 2500ms);
                    }
                    else
                        events.Repeat(2500ms);
                    break;

                // Corrupted form
                case EVENT_MARK_OF_CORRUPTION:
                    if (_markOfCorruptionCount <= 5)
                    {
                        uint32 markSpell = 0;

                        switch (_markOfCorruptionCount)
                        {
                            case 0: markSpell = SPELL_MARK_OF_CORRUPTION_1; break;
                            case 1: markSpell = SPELL_MARK_OF_CORRUPTION_2; break;
                            case 2: markSpell = SPELL_MARK_OF_CORRUPTION_3; break;
                            case 3: markSpell = SPELL_MARK_OF_CORRUPTION_4; break;
                            case 4: markSpell = SPELL_MARK_OF_CORRUPTION_5; break;
                            case 5: markSpell = SPELL_MARK_OF_CORRUPTION_6; break;
                        }

                        DoCastVictim(markSpell);

                        if (_markOfCorruptionCount < 5)
                            ++_markOfCorruptionCount;
                    }
                    events.Repeat(15s);
                    break;
                case EVENT_VILE_SLUDGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                        DoCast(target, SPELL_VILE_SLUDGE);
                    events.Repeat(15s);
                    break;
                case EVENT_SWITCH_TO_PURIFIED:
                    if (me->IsWithinDist2d(HYDROSS_X, HYDROSS_Y, SWITCH_RADIUS))
                    {
                        me->RemoveAurasDueToSpell(SPELL_CORRUPTION);
                        _corruptedForm = false;
                        _markOfHydrossCount = 0;

                        Talk(SAY_SWITCH_TO_CLEAN);
                        ResetThreatList();
                        HandleBeamHelpers(false);

                        DoCastSelf(SPELL_SUMMON_PURIFIED_SPAWN_1);
                        DoCastSelf(SPELL_SUMMON_PURIFIED_SPAWN_2);
                        DoCastSelf(SPELL_SUMMON_PURIFIED_SPAWN_3);
                        DoCastSelf(SPELL_SUMMON_PURIFIED_SPAWN_4);

                        me->SetMeleeDamageSchool(SPELL_SCHOOL_FROST);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);

                        events.ScheduleEvent(EVENT_MARK_OF_HYDROSS, 15s);
                        events.ScheduleEvent(EVENT_WATER_TOMB, 7s);
                        events.ScheduleEvent(EVENT_SWITCH_TO_CORRUPTED, 2500ms);

                        events.CancelEvent(EVENT_MARK_OF_CORRUPTION);
                        events.CancelEvent(EVENT_VILE_SLUDGE);
                        events.CancelEvent(EVENT_SWITCH_TO_PURIFIED);
                    }
                    else
                        events.Repeat(2500ms);
                    break;

                // All forms
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
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
    uint32 _markOfHydrossCount;
    uint32 _markOfCorruptionCount;
    bool _corruptedForm;
};

void AddSC_boss_hydross_the_unstable()
{
    RegisterSerpentshrineCavernCreatureAI(boss_hydross_the_unstable);
}
