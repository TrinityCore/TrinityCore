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
#include "blackrock_spire.h"
#include "ScriptedCreature.h"

#include "GridNotifiers.h"

enum Spells
{
    SPELL_SNAPKICK                  = 15618,
    SPELL_CLEAVE                    = 15284,
    SPELL_UPPERCUT                  = 10966,
    SPELL_MORTALSTRIKE              = 16856,
    SPELL_PUMMEL                    = 15615,
    SPELL_THROWAXE                  = 16075
};

enum Events
{
    EVENT_SNAP_KICK                 = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_UPPERCUT                  = 3,
    EVENT_MORTAL_STRIKE             = 4,
    EVENT_PUMMEL                    = 5,
    EVENT_THROW_AXE                 = 6
};

class boss_warmaster_voone : public CreatureScript
{
public:
    boss_warmaster_voone() : CreatureScript("boss_warmaster_voone") { }

    struct boss_warmastervooneAI : public BossAI
    {
        boss_warmastervooneAI(Creature* creature) : BossAI(creature, DATA_WARMASTER_VOONE) { }

        void Reset() override
        {
            _Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            events.ScheduleEvent(EVENT_SNAP_KICK, 8s);
            events.ScheduleEvent(EVENT_CLEAVE,   14 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_UPPERCUT, 20s);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 12s);
            events.ScheduleEvent(EVENT_PUMMEL,   32 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_THROW_AXE, 1s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
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
                    case EVENT_SNAP_KICK:
                        DoCastVictim(SPELL_SNAPKICK);
                        events.ScheduleEvent(EVENT_SNAP_KICK, 6s);
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 12s);
                        break;
                    case EVENT_UPPERCUT:
                        DoCastVictim(SPELL_UPPERCUT);
                        events.ScheduleEvent(EVENT_UPPERCUT, 14s);
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTALSTRIKE);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 10s);
                        break;
                    case EVENT_PUMMEL:
                        DoCastVictim(SPELL_PUMMEL);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 16s);
                        break;
                    case EVENT_THROW_AXE:
                        DoCastVictim(SPELL_THROWAXE);
                        events.ScheduleEvent(EVENT_THROW_AXE, 8s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockSpireAI<boss_warmastervooneAI>(creature);
    }
};

void AddSC_boss_warmastervoone()
{
    new boss_warmaster_voone();
}

class boss_mor_grayhoof : public CreatureScript
{
public:
    boss_mor_grayhoof() : CreatureScript("boss_mor_grayhoof") { }

    struct boss_mor_grayhoofAI : public CreatureAI
    {
        boss_mor_grayhoofAI(Creature* creature) : CreatureAI(creature) { }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(1, 2000, 4000);
            events.ScheduleEvent(2, 10000,15000);
            events.ScheduleEvent(3, 5000,8000);
            events.ScheduleEvent(4, 8000, 10000);
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
                case 1:
                {
                    std::list<Player*> players;
                    Trinity::AnyPlayerInObjectRangeCheck checker(me, 25.0f);
                    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
                    Cell::VisitWorldObjects(me, searcher, 25.0f);                    
                    for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (Player* eachPlayer=*itr)
                        {
                            if (eachPlayer->IsAlive())
                            {
                                if (!eachPlayer->HasAura(27737))
                                {
                                    DoCast(eachPlayer, 27737);
                                    break;
                                }
                            }
                        }
                    }
                    events.Repeat(4000, 6000);
                    break;
                }
                case 2:
                {
                    DoCastVictim(27530);
                    events.Repeat(20000, 30000);
                    break;
                }
                case 3:
                {
                    if (me->GetHealthPct() < 80.0f)
                    {
                        DoCastSelf(27532);
                        events.Repeat(12000, 15000);
                    }
                    else
                    {
                        events.Repeat(2000, 4000);
                    }                    
                    break;
                }
                case 4:
                {
                    if (me->GetHealthPct() < 50.0f)
                    {
                        DoCastSelf(27527);
                        events.Repeat(15000, 20000);
                    }
                    else
                    {
                        events.Repeat(2000, 4000);
                    }                    
                    break;
                }
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockSpireAI<boss_mor_grayhoofAI>(creature);
    }
};

void AddSC_boss_mor_grayhoof()
{
    new boss_mor_grayhoof();
}
