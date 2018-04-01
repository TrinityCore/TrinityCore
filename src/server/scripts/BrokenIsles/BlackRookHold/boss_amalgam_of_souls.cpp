/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "black_rook_hold.h"

enum
{
    SPELL_REAP_SOUL         = 194956,
    SPELL_SOUL_ECHOES       = 194966,
    SPELL_SWIRLING_SCYTHE   = 195254,

    // Heroic
    SPELL_CALL_SOULS        = 196078,
    SPELL_SOULGORGE         = 196930,
    SPELL_SOUL_BURST        = 196587,
};

struct boss_amalgam_of_souls : public BossAI
{
    boss_amalgam_of_souls(Creature* creature) : BossAI(creature, DATA_AMALGAM_OF_SOULS) { }

    void EnterCombat(Unit* /*attacker*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(SPELL_REAP_SOUL, 16s);
        events.ScheduleEvent(SPELL_SOUL_ECHOES, 10s, 20s);
        events.ScheduleEvent(SPELL_SWIRLING_SCYTHE, 12s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_REAP_SOUL:
            {
                DoCast(SPELL_REAP_SOUL);
                events.Repeat(16s);
                break;
            }
            case SPELL_SOUL_ECHOES:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    DoCast(target, SPELL_SOUL_ECHOES);

                events.Repeat(10s, 20s);
                break;
            }
            case SPELL_SWIRLING_SCYTHE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    DoCast(target, SPELL_SWIRLING_SCYTHE);

                events.Repeat(12s);
                break;
            }
            default:
                break;
        }
    }
};

void AddSC_boss_amalgam_of_souls()
{
    RegisterCreatureAI(boss_amalgam_of_souls);
}
