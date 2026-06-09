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

enum TemporusTexts
{
    SAY_ENTER                   = 0,
    SAY_BANISH                  = 1,
    SAY_AGGRO                   = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4
};

enum TemporusSpells
{
    // Combat
    SPELL_HASTEN                = 31458,
    SPELL_MORTAL_WOUND          = 31464,
    SPELL_WING_BUFFET           = 31475,
    SPELL_BANISH_HELPER         = 31550,
    SPELL_SPELL_REFLECTION      = 38592,

    // Misc
    SPELL_CHANNEL_TRIGGER       = 31388,
    SPELL_CLOSE_TIME_RIFT       = 31322
};

enum TemporusEvents
{
    EVENT_HASTEN                = 1,
    EVENT_MORTAL_WOUND,
    EVENT_WING_BUFFET,
    EVENT_BANISH_HELPER,
    EVENT_SPELL_REFLECTION
};

// 17880 - Temporus
// 21698 - Infinite Timereaver
struct boss_temporus : public BossAI
{
    boss_temporus(Creature* creature) : BossAI(creature, DATA_TEMPORUS) { }

    void JustAppeared() override
    {
        Talk(SAY_ENTER);
        DoCastSelf(SPELL_CHANNEL_TRIGGER);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_HASTEN, 15s, 20s);
        events.ScheduleEvent(EVENT_MORTAL_WOUND, 6s, 8s);
        events.ScheduleEvent(EVENT_WING_BUFFET, 15s, 20s);
        events.ScheduleEvent(EVENT_BANISH_HELPER, 1s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SPELL_REFLECTION, 10s, 20s);
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
                case EVENT_HASTEN:
                    DoCastSelf(SPELL_HASTEN);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_MORTAL_WOUND:
                    DoCastVictim(SPELL_MORTAL_WOUND);
                    events.Repeat(6s, 8s);
                    break;
                case EVENT_WING_BUFFET:
                    DoCastSelf(SPELL_WING_BUFFET);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_BANISH_HELPER:
                    if (me->FindNearestCreature(NPC_TIME_KEEPER, 30.0f, true))
                        DoCastSelf(SPELL_BANISH_HELPER);
                    events.Repeat(1s);
                    break;
                case EVENT_SPELL_REFLECTION:
                    DoCastSelf(SPELL_SPELL_REFLECTION);
                    events.Repeat(25s, 35s);
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

void AddSC_boss_temporus()
{
    RegisterBlackMorassCreatureAI(boss_temporus);
}
