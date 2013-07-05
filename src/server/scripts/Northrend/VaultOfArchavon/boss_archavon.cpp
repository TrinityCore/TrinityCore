/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "vault_of_archavon.h"

enum Emotes
{
    EMOTE_BERSERK           = 0,
    EMOTE_LEAP              = 1 // Not in use
};

enum Spells
{

    // Spells Archavon
    SPELL_ROCK_SHARDS           = 58678,
    SPELL_CRUSHING_LEAP         = 58960,
    SPELL_STOMP                 = 58663,
    SPELL_IMPALE                = 58666,
    SPELL_BERSERK               = 47008,

    // Archavon Warders
    SPELL_ROCK_SHOWER           = 60919,
    SPELL_SHIELD_CRUSH          = 60897,
    SPELL_WHIRL                 = 60902
};

enum Creatures
{
    NPC_ARCHAVON_WARDER         = 32353
};

enum Events
{
    // Archavon
    EVENT_ROCK_SHARDS       = 1,    // 15s cd
    EVENT_CHOKING_CLOUD     = 2,    // 30s cd
    EVENT_STOMP             = 3,    // 45s cd
    EVENT_IMPALE            = 4,
    EVENT_BERSERK           = 5,    // 300s cd

    //mob
    EVENT_ROCK_SHOWER       = 6,    // set = 20s cd, unkown cd
    EVENT_SHIELD_CRUSH      = 7,    // set = 30s cd
    EVENT_WHIRL             = 8,    // set= 10s cd
};

class boss_archavon : public CreatureScript
{
    public:
        boss_archavon() : CreatureScript("boss_archavon") { }

        struct boss_archavonAI : public BossAI
        {
            boss_archavonAI(Creature* creature) : BossAI(creature, DATA_ARCHAVON)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_ROCK_SHARDS, 15000);
                events.ScheduleEvent(EVENT_CHOKING_CLOUD, 30000);
                events.ScheduleEvent(EVENT_STOMP, 45000);
                events.ScheduleEvent(EVENT_BERSERK, 300000);

                _EnterCombat();
            }

            // Below UpdateAI may need review/debug.
            void UpdateAI(uint32 diff)
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
                        case EVENT_ROCK_SHARDS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_ROCK_SHARDS);
                            events.ScheduleEvent(EVENT_ROCK_SHARDS, 15000);
                            break;
                        case EVENT_CHOKING_CLOUD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_CRUSHING_LEAP, true); //10y~80y, ignore range
                            events.ScheduleEvent(EVENT_CHOKING_CLOUD, 30000);
                            break;
                        case EVENT_STOMP:
                            DoCastVictim(SPELL_STOMP);
                            events.ScheduleEvent(EVENT_IMPALE, 3000);
                            events.ScheduleEvent(EVENT_STOMP, 45000);
                            break;
                        case EVENT_IMPALE:
                            DoCastVictim(SPELL_IMPALE);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(EMOTE_BERSERK);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_archavonAI(creature);
        }
};

/*######
##  Mob Archavon Warder
######*/
class npc_archavon_warder : public CreatureScript
{
    public:
        npc_archavon_warder() : CreatureScript("npc_archavon_warder") { }

        struct npc_archavon_warderAI : public ScriptedAI //npc 32353
        {
            npc_archavon_warderAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_ROCK_SHOWER, 2000);
                events.ScheduleEvent(EVENT_SHIELD_CRUSH, 20000);
                events.ScheduleEvent(EVENT_WHIRL, 7500);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat();
            }

            void UpdateAI(uint32 diff)
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
                        case EVENT_ROCK_SHOWER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_ROCK_SHOWER);
                            events.ScheduleEvent(EVENT_ROCK_SHARDS, 6000);
                            break;
                        case EVENT_SHIELD_CRUSH:
                            DoCastVictim(SPELL_SHIELD_CRUSH);
                            events.ScheduleEvent(EVENT_SHIELD_CRUSH, 20000);
                            break;
                        case EVENT_WHIRL:
                            DoCastVictim(SPELL_WHIRL);
                            events.ScheduleEvent(EVENT_WHIRL, 8000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_archavon_warderAI(creature);
        }
};

void AddSC_boss_archavon()
{
    new boss_archavon();
    new npc_archavon_warder();
}
