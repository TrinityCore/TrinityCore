/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/* Script Data Start
SDName: Redridge Mountains
SD%Complete: 0
SDComment:
Script Data End */

#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"

enum DumpyKeeshan
{
    NPC_BIGEARL                    = 43248,

    SPELL_APPLY_QUEST_INVIS_ZONE_3 = 80815, // Used by npc's in Lakeshire Inn
    SPELL_APPLY_QUEST_INVIS_ZONE_4 = 80816  // Used by npc's in Lakeshire Inn
};

/*######
# npc_dumpy_and_keeshan "Used by entries 43249 and 43184"
######*/

class npc_dumpy_and_keeshan : public CreatureScript
{
public:
    npc_dumpy_and_keeshan() : CreatureScript("npc_dumpy_and_keeshan") { }

    struct npc_dumpy_and_keeshanAI : public ScriptedAI
    {
        npc_dumpy_and_keeshanAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(1), [this](TaskContext targetSearch)
            {
                std::list<Creature*> bigEarlList;
                me->GetCreatureListWithEntryInGrid(bigEarlList, NPC_BIGEARL, 5.0f);

                for (Creature* bigEarl : bigEarlList)
                    if ((bigEarl->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_3) && me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_3))
                        || (bigEarl->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_4) && me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_4)))
                        AttackStart(bigEarl);

                if (!me->IsInCombat())
                    targetSearch.Repeat();
            });
        }

        void DamageTaken(Unit* who, uint32& damage) override
        {
            if (who->GetTypeId() == TYPEID_UNIT && me->HealthBelowPctDamaged(82, damage))
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
            DoMeleeAttackIfReady();
        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dumpy_and_keeshanAI(creature);
    }
};

/*######
# npc_big_earl "Used by entry 43248"
######*/

class npc_big_earl : public CreatureScript
{
public:
    npc_big_earl() : CreatureScript("npc_big_earl") { }

    struct npc_big_earlAI : public ScriptedAI
    {
        npc_big_earlAI(Creature* creature) : ScriptedAI(creature) { }

        void DamageTaken(Unit* who, uint32& damage) override
        {
            if (who->GetTypeId() == TYPEID_UNIT && me->HealthBelowPctDamaged(82, damage))
                damage = 0;
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_big_earlAI(creature);
    }
};

/*######
# npc_bridge_worker_alex "Used by entry 653" "Script not fully complete.  Needs scripting added for move rock will be updated in future."
######*/

enum BridgeWorkerAlex
{
    EVENT_STORE_GUIDS      = 1,
    EVENT_OSLOW_SAY        = 2,
    EVENT_ALEX_SAY         = 3,
    EVENT_WORKERS_SAY      = 4,
    EVENT_ALEX_SAY_PUSH    = 5,
    EVENT_MATTHEW_SAY      = 6,

    NPC_OSLOW              = 341,
    NPC_TRENT              = 648,
    NPC_DIMITRI            = 649,
    NPC_JESS               = 650,
    NPC_DANIEL             = 651,
    NPC_MATTHEW            = 652,

    SAY_OSLOW              = 0,
    SAY_ALEX_PUT           = 0,
    SAY_ALEX_HEAVE         = 1,
    SAY_ALEX_DAMN          = 2,
    SAY_ALEX_HANGON        = 3,
    SAY_ALEX_PUSH          = 4,
    SAY_WORKERS_HO         = 0,
    SAY_MATTHEW_IM_PUSHING = 1
};

class npc_bridge_worker_alex : public CreatureScript
{
public:
    npc_bridge_worker_alex() : CreatureScript("npc_bridge_worker_alex") { }

    struct npc_bridge_worker_alexAI : public ScriptedAI
    {
        npc_bridge_worker_alexAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _oslowGUID.Clear();
            _trentGUID.Clear();
            _dimitriGUID.Clear();
            _jessGUID.Clear();
            _danielGUID.Clear();
            _matthewGUID.Clear();
            _events.ScheduleEvent(EVENT_STORE_GUIDS, Seconds(5));
            _events.ScheduleEvent(EVENT_OSLOW_SAY, Seconds(40), Seconds(50));
            _events.ScheduleEvent(EVENT_ALEX_SAY, Seconds(22), Seconds(30));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (!UpdateVictim())
            {
                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_STORE_GUIDS:
                        if (Creature* oslow = me->FindNearestCreature(NPC_OSLOW, 5.0f, true))
                            _oslowGUID = oslow->GetGUID();
                        if (Creature* trent = me->FindNearestCreature(NPC_TRENT, 5.0f, true))
                            _trentGUID = trent->GetGUID();
                        if (Creature* dimitri = me->FindNearestCreature(NPC_DIMITRI, 5.0f, true))
                            _dimitriGUID = dimitri->GetGUID();
                        if (Creature* jess = me->FindNearestCreature(NPC_JESS, 5.0f, true))
                            _jessGUID = jess->GetGUID();
                        if (Creature* daniel = me->FindNearestCreature(NPC_DANIEL, 5.0f, true))
                            _danielGUID = daniel->GetGUID();
                        if (Creature* matthew = me->FindNearestCreature(NPC_MATTHEW, 5.0f, true))
                            _matthewGUID = matthew->GetGUID();
                        break;
                    case EVENT_OSLOW_SAY:
                        if (Creature* oslow = ObjectAccessor::GetCreature(*me, _oslowGUID))
                            oslow->AI()->Talk(SAY_OSLOW);
                        _events.Repeat(Seconds(40), Seconds(50));
                        break;
                    case EVENT_ALEX_SAY:
                        switch (urand(0, 3))
                        {
                        case 0:
                            Talk(SAY_ALEX_PUT);
                            break;
                        case 1:
                            Talk(SAY_ALEX_HEAVE);
                            _events.ScheduleEvent(EVENT_WORKERS_SAY, Seconds(2));
                            break;
                        case 2:
                            Talk(SAY_ALEX_DAMN);
                            _events.ScheduleEvent(EVENT_ALEX_SAY_PUSH, Seconds(4));
                            break;
                        case 3:
                            Talk(SAY_ALEX_HANGON);
                            break;
                        }
                        _events.Repeat(Seconds(22), Seconds(30));
                        break;
                    case EVENT_WORKERS_SAY:
                        if (Creature* trent = ObjectAccessor::GetCreature(*me, _trentGUID))
                            trent->AI()->Talk(SAY_WORKERS_HO);
                        if (Creature* dimitri = ObjectAccessor::GetCreature(*me, _dimitriGUID))
                            dimitri->AI()->Talk(SAY_WORKERS_HO);
                        if (Creature* jess = ObjectAccessor::GetCreature(*me, _jessGUID))
                            jess->AI()->Talk(SAY_WORKERS_HO);
                        if (Creature* daniel = ObjectAccessor::GetCreature(*me, _danielGUID))
                            daniel->AI()->Talk(SAY_WORKERS_HO);
                        if (Creature* matthew = ObjectAccessor::GetCreature(*me, _matthewGUID))
                            matthew->AI()->Talk(SAY_WORKERS_HO);
                        break;
                    case EVENT_ALEX_SAY_PUSH:
                        Talk(SAY_ALEX_PUSH);
                        _events.ScheduleEvent(EVENT_MATTHEW_SAY, Seconds(4));
                        break;
                    case EVENT_MATTHEW_SAY:
                        if (Creature* matthew = ObjectAccessor::GetCreature(*me, _matthewGUID))
                            matthew->AI()->Talk(SAY_MATTHEW_IM_PUSHING);
                        break;
                    default:
                        break;
                    }
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        ObjectGuid _oslowGUID;
        ObjectGuid _trentGUID;
        ObjectGuid _dimitriGUID;
        ObjectGuid _jessGUID;
        ObjectGuid _danielGUID;
        ObjectGuid _matthewGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bridge_worker_alexAI(creature);
    }
};

/*######
# npc_redridge_citizen "Used by entries 43222 and 43247"
######*/

enum RedridgeCitizen
{
    EVENT_DETERMINE_EVENT           = 7,     // Determine where npc is located by aura
    EVENT_PLAYEMOTE                 = 8,     // Used by npc's in Lakeshire Inn
    EVENT_SAY_TEXT                  = 9,     // Used by npc's in Lakeshire Townhall
    EVENT_LEAVE_TOWNHALL            = 10,    // Used by npc's in Lakeshire Townhall

    EMOTE_ONESHOTCHEER              = 4,
    EMOTE_ONESHOTROAR               = 15,
    EMOTE_ONESHOTSHOT               = 22,
    EMOTE_ONESHOTPOINT              = 25,
    EMOTE_ONESHOTBATTLEROAR         = 53,
    EMOTE_ONESHOTNO                 = 274,

    SAY_IN_TOWNHALL                 = 0,     // Used by npc's in Lakeshire Townhall
    SAY_LEAVE_TOWNHALL              = 1,     // Used by npc's in Lakeshire Townhall

    SPELL_APPLY_QUEST_INVIS_ZONE_19 = 82099  // Used by npc's in Lakeshire Townhall
};

const uint32 Emote[6] =
{
    EMOTE_ONESHOTCHEER,
    EMOTE_ONESHOTROAR,
    EMOTE_ONESHOTSHOT,
    EMOTE_ONESHOTPOINT,
    EMOTE_ONESHOTBATTLEROAR,
    EMOTE_ONESHOTNO
};

uint32 const pathSize = 8;
Position const TownhallPath[pathSize] =
{
    { -9221.39f, -2198.45f, 66.34846f },
    { -9221.39f, -2198.45f, 66.34846f },
    { -9226.39f, -2196.45f, 66.34846f },
    { -9231.64f, -2196.45f, 65.34846f },
    { -9231.39f, -2205.45f, 66.34846f },
    { -9231.64f, -2210.45f, 66.34846f },
    { -9244.14f, -2211.20f, 66.34846f },
    { -9255.31f, -2211.62f, 63.93340f }
};

class npc_redridge_citizen : public CreatureScript
{
public:
    npc_redridge_citizen() : CreatureScript("npc_redridge_citizen") { }

    struct npc_redridge_citizenAI : public ScriptedAI
    {
        npc_redridge_citizenAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _events.ScheduleEvent(EVENT_DETERMINE_EVENT, Seconds(2));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (!UpdateVictim())
            {
                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_DETERMINE_EVENT: // Determine where npc is located
                        if (me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_3) || me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_4))  // Lakeshire Inn
                            _events.ScheduleEvent(EVENT_PLAYEMOTE, Seconds(5), Seconds(15));
                        else if (me->HasAura(SPELL_APPLY_QUEST_INVIS_ZONE_19)) // Lakeshire Townhall
                            _events.ScheduleEvent(EVENT_SAY_TEXT, Seconds(5), Seconds(30));
                        break;
                    case EVENT_PLAYEMOTE:
                        me->HandleEmoteCommand(Emote[urand(0, 5)]);
                        _events.ScheduleEvent(EVENT_PLAYEMOTE, Seconds(10), Seconds(25));
                        break;
                    case EVENT_SAY_TEXT:
                        if (roll_chance_i(3))
                        {
                            Talk(SAY_LEAVE_TOWNHALL);
                            _events.ScheduleEvent(EVENT_LEAVE_TOWNHALL, Seconds(2));
                            break;
                        }
                        if (roll_chance_i(30))
                            Talk(SAY_IN_TOWNHALL);
                        _events.Repeat(Seconds(30), Seconds(60));
                        break;
                    case EVENT_LEAVE_TOWNHALL:
                        me->GetMotionMaster()->MoveSmoothPath(pathSize, TownhallPath, pathSize, true, false);
                        me->DespawnOrUnsummon(Seconds(30), Seconds(60));
                        break;
                    default:
                        break;
                    }
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_redridge_citizenAI(creature);
    }
};

void AddSC_redridge_mountains()
{
    new npc_big_earl();
    new npc_dumpy_and_keeshan();
    new npc_bridge_worker_alex();
    new npc_redridge_citizen();
}
