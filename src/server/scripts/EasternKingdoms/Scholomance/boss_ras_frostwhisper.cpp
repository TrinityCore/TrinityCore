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
#include "scholomance.h"
#include "ScriptedCreature.h"

enum RasSpells
{
    SPELL_ICE_ARMOR         = 18100,
    SPELL_FREEZE            = 18763,
    SPELL_FEAR              = 12096,
    SPELL_CHILL_NOVA        = 18099,
    SPELL_KNOCK_AWAY        = 11130,
    SPELL_FROSTBOLT_VOLLEY  = 8398
};

enum RasEvents
{
    EVENT_ICE_ARMOR         = 1,
    EVENT_FREEZE,
    EVENT_FEAR,
    EVENT_CHILL_NOVA,
    EVENT_KNOCK_AWAY,
    EVENT_FROSTBOLT_VOLLEY
};

// 10508 - Ras Frostwhisper
struct boss_boss_ras_frostwhisper : public ScriptedAI
{
    boss_boss_ras_frostwhisper(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();

        DoCastSelf(SPELL_ICE_ARMOR);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_ICE_ARMOR, 30s);
        _events.ScheduleEvent(EVENT_FREEZE, 20s, 30s);
        _events.ScheduleEvent(EVENT_FEAR, 10s, 20s);
        _events.ScheduleEvent(EVENT_CHILL_NOVA, 10s, 15s);
        _events.ScheduleEvent(EVENT_KNOCK_AWAY, 20s, 30s);
        _events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 10s, 20s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ICE_ARMOR:
                    if (!me->HasAura(SPELL_ICE_ARMOR))
                        DoCastSelf(SPELL_ICE_ARMOR);
                    _events.Repeat(30s);
                    break;
                case EVENT_FREEZE:
                    DoCastVictim(SPELL_FREEZE);
                    _events.Repeat(30s, 40s);
                    break;
                case EVENT_FEAR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FEAR);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_CHILL_NOVA:
                    DoCastSelf(SPELL_CHILL_NOVA);
                    _events.Repeat(15s, 25s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastSelf(SPELL_KNOCK_AWAY);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_FROSTBOLT_VOLLEY:
                    DoCastSelf(SPELL_FROSTBOLT_VOLLEY);
                    _events.Repeat(10s, 20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

void AddSC_boss_rasfrost()
{
    RegisterScholomanceCreatureAI(boss_boss_ras_frostwhisper);
}
