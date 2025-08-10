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
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "karazhan.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum MaidenOfVirtueTexts
{
    SAY_AGGRO           = 0,
    SAY_SLAY            = 1,
    SAY_REPENTANCE      = 2,
    SAY_DEATH           = 3
};

enum MaidenOfVirtueSpells
{
    SPELL_HOLYGROUND    = 29523,
    SPELL_REPENTANCE    = 29511,
    SPELL_HOLYFIRE      = 29522,
    SPELL_HOLYWRATH     = 32445,
    SPELL_BERSERK       = 26662
};

enum MaidenOfVirtueEvents
{
    EVENT_REPENTANCE    = 1,
    EVENT_HOLYFIRE,
    EVENT_HOLYWRATH,
    EVENT_BERSERK
};

// 16457 - Maiden of Virtue
struct boss_maiden_of_virtue : public BossAI
{
    boss_maiden_of_virtue(Creature* creature) : BossAI(creature, DATA_MAIDEN_OF_VIRTUE) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_HOLYGROUND, true);
        events.ScheduleEvent(EVENT_REPENTANCE, 33s, 45s);
        events.ScheduleEvent(EVENT_HOLYFIRE, 8s);
        events.ScheduleEvent(EVENT_HOLYWRATH, 15s, 25s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_REPENTANCE)
            Talk(SAY_REPENTANCE);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        if (roll_chance_i(50))
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
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
                case EVENT_REPENTANCE:
                    DoCastVictim(SPELL_REPENTANCE);
                    events.Repeat(35s);
                    break;
                case EVENT_HOLYFIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50, true))
                        DoCast(target, SPELL_HOLYFIRE);
                    events.Repeat(8s, 19s);
                    break;
                case EVENT_HOLYWRATH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 80, true))
                        DoCast(target, SPELL_HOLYWRATH);
                    events.Repeat(15s, 25s);
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

void AddSC_boss_maiden_of_virtue()
{
    RegisterKarazhanCreatureAI(boss_maiden_of_virtue);
}
