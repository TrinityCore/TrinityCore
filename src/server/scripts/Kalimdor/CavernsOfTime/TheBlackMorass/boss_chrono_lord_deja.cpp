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
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "the_black_morass.h"

enum DejaTexts
{
    SAY_ENTER                   = 0,
    SAY_BANISH                  = 1,
    SAY_AGGRO                   = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4
};

enum DejaSpells
{
    // Combat
    SPELL_ARCANE_BLAST          = 31457,
    SPELL_TIME_LAPSE            = 31467,
    SPELL_ARCANE_DISCHARGE      = 31472,
    SPELL_BANISH_HELPER         = 31550,
    SPELL_ATTRACTION            = 38540,

    // Misc
    SPELL_CHANNEL_TRIGGER       = 31388,
    SPELL_CLOSE_TIME_RIFT       = 31322
};

enum DejaEvents
{
    EVENT_ARCANE_BLAST          = 1,
    EVENT_TIME_LAPSE,
    EVENT_ARCANE_DISCHARGE,
    EVENT_BANISH_HELPER,
    EVENT_ATTRACTION
};

// 17879 - Chrono Lord Deja
// 21697 - Infinite Chrono-Lord
struct boss_chrono_lord_deja : public BossAI
{
    boss_chrono_lord_deja(Creature* creature) : BossAI(creature, DATA_DEJA) { }

    void JustAppeared() override
    {
        Talk(SAY_ENTER);
        DoCastSelf(SPELL_CHANNEL_TRIGGER);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_ARCANE_BLAST, 15s, 25s);
        events.ScheduleEvent(EVENT_TIME_LAPSE, 10s, 15s);
        events.ScheduleEvent(EVENT_ARCANE_DISCHARGE, 15s, 25s);
        events.ScheduleEvent(EVENT_BANISH_HELPER, 1s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_ATTRACTION, 20s, 30s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BANISH_HELPER)
            Talk(SAY_BANISH);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        DoCastSelf(SPELL_CLOSE_TIME_RIFT, true);
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
                case EVENT_ARCANE_BLAST:
                    DoCastVictim(SPELL_ARCANE_BLAST);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_TIME_LAPSE:
                    DoCastSelf(SPELL_TIME_LAPSE);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_ARCANE_DISCHARGE:
                    DoCastSelf(SPELL_ARCANE_DISCHARGE);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_BANISH_HELPER:
                    if (me->FindNearestCreature(NPC_TIME_KEEPER, 30.0f, true))
                        DoCastSelf(SPELL_BANISH_HELPER);
                    events.Repeat(1s);
                    break;
                case EVENT_ATTRACTION:
                    DoCastSelf(SPELL_ATTRACTION);
                    events.Repeat(20s, 30s);
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

void AddSC_boss_chrono_lord_deja()
{
    RegisterBlackMorassCreatureAI(boss_chrono_lord_deja);
}
