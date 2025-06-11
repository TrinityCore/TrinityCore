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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_slave_pens.h"

enum MennuTexts
{
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_DEATH                       = 2
};

enum MennuSpells
{
    SPELL_TAINTED_STONESKIN_TOTEM   = 31985,
    SPELL_TAINTED_EARTHGRAB_TOTEM   = 31981,
    SPELL_CORRUPTED_NOVA_TOTEM      = 31991,
    SPELL_MENNUS_HEALING_WARD       = 34980,
    SPELL_LIGHTNING_BOLT            = 35010
};

enum MennuEvents
{
    EVENT_TAINTED_STONESKIN_TOTEM   = 1,
    EVENT_TAINTED_EARTHGRAB_TOTEM,
    EVENT_CORRUPTED_NOVA_TOTEM,
    EVENT_MENNUS_HEALING_WARD,
    EVENT_LIGHTNING_BOLT
};

// 17941 - Mennu the Betrayer
struct boss_mennu_the_betrayer : public BossAI
{
    boss_mennu_the_betrayer(Creature* creature) : BossAI(creature, DATA_MENNU_THE_BETRAYER) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_TAINTED_STONESKIN_TOTEM, 30s, 40s);
        events.ScheduleEvent(EVENT_TAINTED_EARTHGRAB_TOTEM, 20s, 30s);
        events.ScheduleEvent(EVENT_CORRUPTED_NOVA_TOTEM, 20s, 30s);
        events.ScheduleEvent(EVENT_MENNUS_HEALING_WARD, 15s, 25s);
        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 10s, 20s);
        Talk(SAY_AGGRO);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
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
                case EVENT_TAINTED_STONESKIN_TOTEM:
                    DoCastSelf(SPELL_TAINTED_STONESKIN_TOTEM);
                    events.Repeat(35s, 40s);
                    break;
                case EVENT_TAINTED_EARTHGRAB_TOTEM:
                    DoCastSelf(SPELL_TAINTED_EARTHGRAB_TOTEM);
                    events.Repeat(35s, 40s);
                    break;
                case EVENT_CORRUPTED_NOVA_TOTEM:
                    DoCastSelf(SPELL_CORRUPTED_NOVA_TOTEM);
                    events.Repeat(35s, 40s);
                    break;
                case EVENT_MENNUS_HEALING_WARD:
                    DoCastSelf(SPELL_MENNUS_HEALING_WARD);
                    events.Repeat(35s, 40s);
                    break;
                case EVENT_LIGHTNING_BOLT:
                    DoCastVictim(SPELL_LIGHTNING_BOLT);
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

void AddSC_boss_mennu_the_betrayer()
{
    RegisterSlavePensCreatureAI(boss_mennu_the_betrayer);
}
