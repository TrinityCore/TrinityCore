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
 * Timers requires update
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum MalownTexts
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1
};

enum MalownSpells
{
    SPELL_INCORPOREAL_DEFENSE   = 16331,
    SPELL_BACKHAND              = 6253,
    SPELL_CURSE_OF_WEAKNESS     = 12741,
    SPELL_CURSE_OF_TONGUES      = 13338,
    SPELL_FEAR                  = 12542
};

enum MalownEvents
{
    EVENT_BACKHAND              = 1,
    EVENT_CURSE_OF_WEAKNESS,
    EVENT_CURSE_OF_TONGUES,
    EVENT_FEAR
};

// 11143 - Postmaster Malown
struct boss_postmaster_malown : public BossAI
{
    boss_postmaster_malown(Creature* creature) : BossAI(creature, BOSS_POSTMASTER_MALOWN) { }

    void Reset() override
    {
        _Reset();
        DoCastSelf(SPELL_INCORPOREAL_DEFENSE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_BACKHAND, 10s, 20s);
        events.ScheduleEvent(EVENT_CURSE_OF_WEAKNESS, 20s, 30s);
        events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, 15s, 30s);
        events.ScheduleEvent(EVENT_FEAR, 25s, 35s);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
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
                case EVENT_BACKHAND:
                    DoCastVictim(SPELL_BACKHAND);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_CURSE_OF_WEAKNESS:
                    DoCastSelf(SPELL_CURSE_OF_WEAKNESS);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_CURSE_OF_TONGUES:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CURSE_OF_TONGUES);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_FEAR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FEAR);
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

void AddSC_boss_postmaster_malown()
{
    RegisterStratholmeCreatureAI(boss_postmaster_malown);
}
