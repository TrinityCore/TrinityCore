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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "the_stockade.h"

enum Spells
{
    SPELL_FIREBALL           = 12466, // starts 1-2 secs from pull
    SPELL_OVERHEAT           = 86633, // probably cast every 10 secs, need to confirm.
    SPELL_RAIN_OF_FIRE       = 86636  // probably cast every 10 secs, need to confirm
};

enum Events
{
    EVENT_OVERHEAT = 1,
    EVENT_RAIN_OF_FIRE,
    EVENT_FIREBALL
};

enum Says
{
    SAY_PULL  = 0, // Yell: ALL MUST BURN!
    SAY_DEATH = 1  // Yell: FIRE... EXTINGUISHED!
};

// Lord Overheat - 46264
struct boss_lord_overheat : public BossAI
{
    boss_lord_overheat(Creature* creature) : BossAI(creature, DATA_LORD_OVERHEAT) { }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);

        Talk(SAY_PULL);

        events.ScheduleEvent(EVENT_FIREBALL, 2s);
        events.ScheduleEvent(EVENT_OVERHEAT, 9s, 11s);
        events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 10s, 13s);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        Talk(SAY_DEATH);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_FIREBALL:
                DoCastVictim(SPELL_FIREBALL);
                events.Repeat(2s);
                break;
            case EVENT_OVERHEAT:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    DoCast(target, SPELL_OVERHEAT);
                events.Repeat(9s, 10s);
                break;
            case EVENT_RAIN_OF_FIRE:
                DoCastAOE(SPELL_RAIN_OF_FIRE);
                events.Repeat(15s, 20s);
                break;
            default:
                break;
        }
    }
};

void AddSC_boss_lord_overheat()
{
    RegisterStormwindStockadesAI(boss_lord_overheat);
}
