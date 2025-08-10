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
SDName: boss_maleki_the_pallid
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_FROSTBOLT     = 17503,
    SPELL_DRAINLIFE     = 20743,
    SPELL_DRAIN_MANA    = 17243,
    SPELL_ICETOMB       = 16869
};

enum MalekiEvents
{
    EVENT_FROSTBOLT     = 1,
    EVENT_DRAINLIFE     = 2,
    EVENT_DRAIN_MANA    = 3,
    EVENT_ICETOMB       = 4
};

class boss_maleki_the_pallid : public CreatureScript
{
public:
    boss_maleki_the_pallid() : CreatureScript("boss_maleki_the_pallid") { }

    struct boss_maleki_the_pallidAI : public BossAI
    {
        boss_maleki_the_pallidAI(Creature* creature) : BossAI(creature, BOSS_MALEKI_THE_PALLID)
        {
        }

        void JustEngagedWith(Unit* who) override
        {
            _JustEngagedWith(who);
            events.ScheduleEvent(EVENT_FROSTBOLT, 1s);
            events.ScheduleEvent(EVENT_ICETOMB, 16s);
            events.ScheduleEvent(EVENT_DRAINLIFE, 31s);
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FROSTBOLT:
                        if (rand32() % 90)
                            DoCastVictim(SPELL_FROSTBOLT);
                        events.ScheduleEvent(EVENT_FROSTBOLT, 3500ms);
                        break;
                    case EVENT_ICETOMB:
                        if (rand32() % 65)
                            DoCastVictim(SPELL_ICETOMB);
                        events.ScheduleEvent(EVENT_ICETOMB, 28s);
                        break;
                    case EVENT_DRAINLIFE:
                        if (rand32() % 55)
                            DoCastVictim(SPELL_DRAINLIFE);
                        events.ScheduleEvent(EVENT_DRAINLIFE, 31s);
                        break;
                    default:
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStratholmeAI<boss_maleki_the_pallidAI>(creature);
    }
};

void AddSC_boss_maleki_the_pallid()
{
    new boss_maleki_the_pallid();
}
