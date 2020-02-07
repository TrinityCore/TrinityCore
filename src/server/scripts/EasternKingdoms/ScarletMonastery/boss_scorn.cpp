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

#include "scarlet_monastery.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum ScornSpells
{
    SPELL_LICHSLAP = 28873,
    SPELL_FROSTBOLT_VOLLEY = 8398,
    SPELL_MINDFLAY = 17313,
    SPELL_FROSTNOVA = 15531
};

enum ScornEvents
{
    EVENT_LICH_SLAP = 1,
    EVENT_FROSTBOLT_VOLLEY,
    EVENT_MIND_FLAY,
    EVENT_FROST_NOVA
};

struct boss_scorn : public BossAI
{
    boss_scorn(Creature* creature) : BossAI(creature, DATA_SCORN) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_LICH_SLAP, 45s);
        events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 30s);
        events.ScheduleEvent(EVENT_MIND_FLAY, 30s);
        events.ScheduleEvent(EVENT_FROST_NOVA, 30s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_LICH_SLAP:
                DoCastVictim(SPELL_LICHSLAP);
                events.Repeat(45s);
                break;
            case EVENT_FROSTBOLT_VOLLEY:
                DoCastVictim(SPELL_FROSTBOLT_VOLLEY);
                events.Repeat(20s);
                break;
            case EVENT_MIND_FLAY:
                DoCastVictim(SPELL_MINDFLAY);
                events.Repeat(20s);
                break;
            case EVENT_FROST_NOVA:
                DoCastVictim(SPELL_FROSTNOVA);
                events.Repeat(15s);
                break;
            default:
                break;
        }
    }
};

void AddSC_boss_scorn()
{
    RegisterScarletMonasteryCreatureAI(boss_scorn);
}
