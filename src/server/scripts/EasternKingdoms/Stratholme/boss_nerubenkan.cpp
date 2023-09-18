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
#include "ScriptedCreature.h"
#include "stratholme.h"

enum NerubenkanSpells
{
    SPELL_CRYPT_SCARABS         = 31602,
    SPELL_ENCASING_WEBS         = 4962,
    SPELL_PIERCE_ARMOR          = 6016,
    SPELL_RAISE_SCARAB          = 17235
};

enum NerubenkanEvents
{
    EVENT_CRYPT_SCARABS         = 1,
    EVENT_ENCASING_WEBS,
    EVENT_PIERCE_ARMOR,
    EVENT_RAISE_SCARAB
};

// 10437 - Nerub'enkan
struct boss_nerubenkan : public BossAI
{
    boss_nerubenkan(Creature* creature) : BossAI(creature, BOSS_NERUB_ENKAN) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_CRYPT_SCARABS, 0s);
        events.ScheduleEvent(EVENT_ENCASING_WEBS, 5s, 10s);
        events.ScheduleEvent(EVENT_PIERCE_ARMOR, 5s, 20s);
        events.ScheduleEvent(EVENT_RAISE_SCARAB, 6s, 12s);
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
                case EVENT_CRYPT_SCARABS:
                    DoCastVictim(SPELL_CRYPT_SCARABS);
                    events.Repeat(2s, 10s);
                    break;
                case EVENT_ENCASING_WEBS:
                    DoCastVictim(SPELL_ENCASING_WEBS);
                    events.Repeat(6s, 10s);
                    break;
                case EVENT_PIERCE_ARMOR:
                    DoCastVictim(SPELL_PIERCE_ARMOR);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_RAISE_SCARAB:
                    DoCastSelf(SPELL_RAISE_SCARAB);
                    events.Repeat(25s, 30s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_nerubenkan()
{
    RegisterStratholmeCreatureAI(boss_nerubenkan);
}
