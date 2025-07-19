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
#include "razorfen_downs.h"

enum TutenkashSpells
{
    SPELL_VIRULENT_POISON        = 12254,
    SPELL_THRASH                 = 8876,
    SPELL_WEB_SPRAY              = 12252,
    SPELL_CURSE_OF_TUTENKASH     = 12255
};

enum TutenkashEvents
{
    EVENT_WEB_SPRAY              = 1,
    EVENT_CURSE_OF_TUTENKASH
};

// 7355 - Tuten'kash
struct boss_tuten_kash : public BossAI
{
    boss_tuten_kash(Creature* creature) : BossAI(creature, DATA_TUTEN_KASH) { }

    void Reset() override
    {
        _Reset();
        DoCastSelf(SPELL_VIRULENT_POISON);
        DoCastSelf(SPELL_THRASH);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_WEB_SPRAY, 10s, 20s);
        events.ScheduleEvent(EVENT_CURSE_OF_TUTENKASH, 10s, 15s);
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
                case EVENT_WEB_SPRAY:
                    DoCastSelf(SPELL_WEB_SPRAY);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_CURSE_OF_TUTENKASH:
                    DoCastSelf(SPELL_CURSE_OF_TUTENKASH);
                    events.Repeat(15s, 25s);
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

void AddSC_boss_tuten_kash()
{
    RegisterRazorfenDownsCreatureAI(boss_tuten_kash);
}
