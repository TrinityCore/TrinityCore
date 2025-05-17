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

#include "scholomance.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum RasSpells
{
    SPELL_FROSTBOLT         = 21369,
    SPELL_ICE_ARMOR         = 18100, // This is actually a buff he gives himself
    SPELL_FREEZE            = 18763,
    SPELL_FEAR              = 26070,
    SPELL_CHILL_NOVA        = 18099,
    SPELL_FROSTBOLT_VOLLEY  = 8398
};

enum RasEvents
{
    EVENT_FROSTBOLT = 1,
    EVENT_ICE_ARMOR,
    EVENT_FREEZE,
    EVENT_FEAR,
    EVENT_CHILL_NOVA,
    EVENT_FROSTVOLLEY
};

// 10508 - Ras Frostwhisper
struct boss_boss_ras_frostwhisper : public BossAI
{
    boss_boss_ras_frostwhisper(Creature* creature) : BossAI(creature, DATA_RAS_FROSTWHISPER) { }

    void Reset() override
    {
        BossAI::Reset();
        DoCastSelf(SPELL_ICE_ARMOR);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_ICE_ARMOR, 2s);
        events.ScheduleEvent(EVENT_FROSTBOLT, 8s);
        events.ScheduleEvent(EVENT_CHILL_NOVA, 12s);
        events.ScheduleEvent(EVENT_FREEZE, 18s);
        events.ScheduleEvent(EVENT_FEAR, 45s);
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
                case EVENT_ICE_ARMOR:
                    DoCastSelf(SPELL_ICE_ARMOR);
                    events.Repeat(3min);
                    break;
                case EVENT_FROSTBOLT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                        DoCast(target, SPELL_FROSTBOLT);
                    events.Repeat(8s);
                    break;
                case EVENT_FREEZE:
                    DoCastVictim(SPELL_FREEZE);
                    events.Repeat(24s);
                    break;
                case EVENT_FEAR:
                    DoCastSelf(SPELL_FEAR);
                    events.Repeat(30s);
                    break;
                case EVENT_CHILL_NOVA:
                    DoCastSelf(SPELL_CHILL_NOVA);
                    events.Repeat(14s);
                    break;
                case EVENT_FROSTVOLLEY:
                    DoCastVictim(SPELL_FROSTBOLT_VOLLEY);
                    events.Repeat(15s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

void AddSC_boss_rasfrost()
{
    RegisterScholomanceCreatureAI(boss_boss_ras_frostwhisper);
}
