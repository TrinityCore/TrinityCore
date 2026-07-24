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
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "hyjal.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum WinterchillTexts
{
    SAY_INTRO                   = 0,
    SAY_DECAY                   = 1,
    SAY_NOVA                    = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4
};

enum WinterchillSpells
{
    SPELL_ICEBOLT               = 31249,
    SPELL_FROST_NOVA            = 31250,
    SPELL_FROST_ARMOR           = 31256,
    SPELL_DEATH_AND_DECAY       = 31258,
    SPELL_BERSERK               = 26662
};

enum WinterchillEvents
{
    EVENT_ICEBOLT               = 1,
    EVENT_FROST_NOVA,
    EVENT_FROST_ARMOR,
    EVENT_DEATH_AND_DECAY,
    EVENT_BERSERK
};

// 17767 - Rage Winterchill
struct boss_rage_winterchill : public BossAI
{
    boss_rage_winterchill(Creature* creature) : BossAI(creature, DATA_RAGEWINTERCHILL) { }

    void JustAppeared() override
    {
        Talk(SAY_INTRO);
        me->GetMotionMaster()->MovePath(RAND(PATH_ALLY_INITIAL_1, PATH_ALLY_INITIAL_2, PATH_ALLY_INITIAL_3), false);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_ICEBOLT, 4s, 10s);
        events.ScheduleEvent(EVENT_FROST_NOVA, 20s, 25s);
        events.ScheduleEvent(EVENT_FROST_ARMOR, 40s, 60s);
        events.ScheduleEvent(EVENT_DEATH_AND_DECAY, 30s, 40s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_FROST_NOVA:
                if (roll_chance_i(30))
                    Talk(SAY_NOVA);
                break;
            case SPELL_DEATH_AND_DECAY:
                if (roll_chance_i(30))
                    Talk(SAY_DECAY);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*waypointId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_ALLY_INITIAL_1:
            case PATH_ALLY_INITIAL_2:
            case PATH_ALLY_INITIAL_3:
                me->GetMotionMaster()->MovePath(RAND(PATH_ALLY_BASE_1, PATH_ALLY_BASE_2, PATH_ALLY_BASE_3), true);
                break;
            default:
                break;
        }
    }

    // Do not reset SetActive, we want boss to be active all the time
    void JustReachedHome() override { }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                case EVENT_ICEBOLT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                        DoCast(target, SPELL_ICEBOLT);
                    events.Repeat(6s, 8s);
                    break;
                case EVENT_FROST_NOVA:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.0f))
                        DoCast(target, SPELL_FROST_NOVA);
                    events.Repeat(30s, 45s);
                    break;
                case EVENT_FROST_ARMOR:
                    DoCastSelf(SPELL_FROST_ARMOR);
                    events.Repeat(40s, 60s);
                    break;
                case EVENT_DEATH_AND_DECAY:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f))
                        DoCast(target, SPELL_DEATH_AND_DECAY);
                    events.Repeat(35s, 50s);
                    break;
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
};

void AddSC_boss_rage_winterchill()
{
    RegisterHyjalCreatureAI(boss_rage_winterchill);
}
