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
#include "GridNotifiers.h"

// EJ scripts
enum Spawn_ID
{
    Spawn_ID_Vectus = 48805,
    Spawn_ID_Marduk_Blackpool = 48806
};

enum Creature_Entry
{
    Creature_Entry_Scholomance_Student = 10475,
};

enum Emotes
{
    EMOTE_FRENZY                 = 0
};

enum Spells
{
    SPELL_FLAMESTRIKE            = 18399,
    SPELL_BLAST_WAVE             = 16046,
    SPELL_FIRE_SHIELD            = 19626,
    SPELL_FRENZY                 = 8269  // 28371
};

enum Events
{
    EVENT_FIRE_SHIELD = 1,
    EVENT_BLAST_WAVE,
    EVENT_FRENZY
};

class boss_vectus : public CreatureScript
{
public:
    boss_vectus() : CreatureScript("boss_vectus") { }

    struct boss_vectusAI : public ScriptedAI
    {
        boss_vectusAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            events.Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            if (Map* checkMap = me->GetMap())
            {
                if (Creature* checkC = checkMap->GetCreatureBySpawnId(Spawn_ID::Spawn_ID_Marduk_Blackpool))
                {
                    checkC->AI()->AttackStart(who);
                }
            }
            std::list<Creature*> templist;
            Trinity::AllCreaturesOfEntryInRange check(me, Creature_Entry::Creature_Entry_Scholomance_Student, VISIBILITY_DISTANCE_NORMAL);
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, templist, check);
            Cell::VisitGridObjects(me, searcher, VISIBILITY_DISTANCE_NORMAL);
            for (std::list<Creature*>::const_iterator cIT = templist.begin(); cIT != templist.end(); ++cIT)
            {
                if (Creature* eachC = *cIT)
                {
                    eachC->AI()->SetData(0, 0);
                    eachC->AI()->AttackStart(who);
                }
            }
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            events.ScheduleEvent(EVENT_FIRE_SHIELD, 2s);
            events.ScheduleEvent(EVENT_BLAST_WAVE, 14s);
            events.ScheduleEvent(EVENT_FRENZY, 20000, 30000);
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
                    case EVENT_FIRE_SHIELD:
                        DoCast(me, SPELL_FIRE_SHIELD);
                        events.ScheduleEvent(EVENT_FIRE_SHIELD, 90s);
                        break;
                    case EVENT_BLAST_WAVE:
                        DoCast(me, SPELL_BLAST_WAVE);
                        events.ScheduleEvent(EVENT_BLAST_WAVE, 12s);
                        break;
                    case EVENT_FRENZY:
                    {
                        if (me->GetHealthPct() < 25.0f)
                        {
                            DoCast(me, SPELL_FRENZY);
                            Talk(EMOTE_FRENZY);
                            events.Repeat(25000, 30000);
                        }
                        else
                        {
                            events.Repeat(3000, 5000);
                        }
                        break;
                    }
                    default:
                        break;
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
        return GetScholomanceAI<boss_vectusAI>(creature);
    }
};

void AddSC_boss_vectus()
{
    new boss_vectus();
}

enum Marduk_Blackpool_Lines
{
    Marduk_Blackpool_Lines_0 = 0
};

enum Marduk_Blackpool_Spells
{
    Marduk_Blackpool_Spells_0 = 17695,
    Marduk_Blackpool_Spells_1 = 17228,
    Marduk_Blackpool_Spells_2 = 15284,
    Marduk_Blackpool_Spells_3 = 12040
};

enum Marduk_Blackpool_Events
{
    Marduk_Blackpool_Events_0 = 1,
    Marduk_Blackpool_Events_1,
    Marduk_Blackpool_Events_2
};

class boss_marduk_blackpool : public CreatureScript
{
public:
    boss_marduk_blackpool() : CreatureScript("boss_marduk_blackpool") { }

    struct boss_marduk_blackpoolAI : public ScriptedAI
    {
        boss_marduk_blackpoolAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            events.Reset();  
        }

        void JustEngagedWith(Unit* who) override
        {
            if (Map* checkMap = me->GetMap())
            {
                if (Creature* checkC = checkMap->GetCreatureBySpawnId(Spawn_ID::Spawn_ID_Vectus))
                {
                    checkC->AI()->AttackStart(who);
                }
            }
            DoCast(me, Marduk_Blackpool_Spells_0);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            Talk(0);
            events.ScheduleEvent(Marduk_Blackpool_Events_0, 8000, 13000);
            events.ScheduleEvent(Marduk_Blackpool_Events_1, 5000, 8000);
            events.ScheduleEvent(Marduk_Blackpool_Events_2, 13000, 15000);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
          
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                return;
            }
            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
            {
                return;
            }
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case Marduk_Blackpool_Events_0:
                {
                    DoCastVictim(Marduk_Blackpool_Spells_1);
                    events.Repeat(12000, 15000);                    
                    break;
                }
                case Marduk_Blackpool_Events_1:
                {
                    DoCastVictim(Marduk_Blackpool_Spells_2);
                    events.Repeat(8000, 12000);                    
                    break;
                }
                case Marduk_Blackpool_Events_2:
                {
                    DoCast(me, Marduk_Blackpool_Spells_3);
                    events.Repeat(30000, 35000);
                    break;
                }
                default:
                {
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
        return GetScholomanceAI<boss_marduk_blackpoolAI>(creature);
    }
};

void AddSC_boss_marduk_blackpool()
{
    new boss_marduk_blackpool();
}

class npc_scholomance_student : public CreatureScript
{
public:
    npc_scholomance_student() : CreatureScript("npc_scholomance_student") { }

    struct npc_scholomance_studentAI : public ScriptedAI
    {
        npc_scholomance_studentAI(Creature* creature) : ScriptedAI(creature)
        {
            callAssists = 1;
        }

        void Reset() override
        {
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            events.Reset();
            callAssists = 1;
        }

        void JustEngagedWith(Unit* who) override
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            if (callAssists == 1)
            {
                std::list<Creature*> templist;
                Trinity::AllCreaturesOfEntryInRange check(me, Creature_Entry::Creature_Entry_Scholomance_Student, INTERACTION_DISTANCE);
                Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, templist, check);
                Cell::VisitGridObjects(me, searcher, INTERACTION_DISTANCE);
                for (std::list<Creature*>::const_iterator cIT = templist.begin(); cIT != templist.end(); ++cIT)
                {
                    if (Creature* eachC = *cIT)
                    {
                        eachC->AI()->SetData(0, 0);
                        eachC->AI()->AttackStart(who);
                    }
                }
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == 0)
            {
                callAssists = data;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(25, damage))
            {
                DoCast(me, SPELL_FRENZY);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                return;
            }
            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
            {
                return;
            }
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {                
                default:
                {
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
        uint32 callAssists;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScholomanceAI<npc_scholomance_studentAI>(creature);
    }
};

void AddSC_npc_scholomance_student()
{
    new npc_scholomance_student();
}
