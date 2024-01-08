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

/* ScriptData
SDName: boss_mennu_the_betrayer
SD%Complete: 95%
SDComment:
SDCategory: Coilfang Reservoir, The Slave Pens
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_slave_pens.h"

enum Say
{
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_DEATH                       = 2
};

enum Spells
{
    SPELL_TAINTED_STONESKIN_TOTEM   = 31985, // every 30 sec if health below 100%
    SPELL_TAINTED_EARTHGRAB_TOTEM   = 31981, // ?
    SPELL_CORRUPTED_NOVA_TOTEM      = 31991, // ?
    SPELL_MENNUS_HEALING_WARD       = 34980, // every 14 - 25 sec
    SPELL_LIGHTNING_BOLT            = 35010  // every 14 - 19 sec
};

enum Events
{
    EVENT_TAINTED_STONESKIN_TOTEM   = 1,
    EVENT_TAINTED_EARTHGRAB_TOTEM   = 2,
    EVENT_CORRUPTED_NOVA_TOTEM      = 3,
    EVENT_MENNUS_HEALING_WARD       = 4,
    EVENT_LIGHTNING_BOLT            = 5
};

struct boss_mennu_the_betrayer : public BossAI
{
    boss_mennu_the_betrayer(Creature* creature) : BossAI(creature, DATA_MENNU_THE_BETRAYER) { }

    void Reset() override
    {
        _Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_TAINTED_STONESKIN_TOTEM, 30s);
        events.ScheduleEvent(EVENT_TAINTED_EARTHGRAB_TOTEM, 20s);
        events.ScheduleEvent(EVENT_CORRUPTED_NOVA_TOTEM, 1min);
        events.ScheduleEvent(EVENT_MENNUS_HEALING_WARD, 14s, 25s);
        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 14s, 19s);
        Talk(SAY_AGGRO);
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
                case EVENT_TAINTED_STONESKIN_TOTEM:
                    if (HealthBelowPct(100))
                        DoCast(me, SPELL_TAINTED_STONESKIN_TOTEM);
                    events.ScheduleEvent(EVENT_TAINTED_STONESKIN_TOTEM, 30s);
                    break;
                case EVENT_TAINTED_EARTHGRAB_TOTEM:
                    DoCast(me, SPELL_TAINTED_EARTHGRAB_TOTEM);
                    break;
                case EVENT_CORRUPTED_NOVA_TOTEM:
                    DoCast(me, SPELL_CORRUPTED_NOVA_TOTEM);
                    break;
                case EVENT_MENNUS_HEALING_WARD:
                    DoCast(me, SPELL_MENNUS_HEALING_WARD);
                    events.ScheduleEvent(EVENT_MENNUS_HEALING_WARD, 14s, 25s);
                    break;
                case EVENT_LIGHTNING_BOLT:
                    DoCastVictim(SPELL_LIGHTNING_BOLT, true);
                    events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 14s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

void AddSC_boss_mennu_the_betrayer()
{
    RegisterSlavePensCreatureAI(boss_mennu_the_betrayer);
}
