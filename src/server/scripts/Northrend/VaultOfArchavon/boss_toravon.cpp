/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "vault_of_archavon.h"

// Spells Toravon
#define SPELL_FREEZING_GROUND   RAID_MODE(72090,72104)  // don't know cd... using 20 secs.
#define SPELL_FROZEN_ORB        RAID_MODE(72091,72095)
#define SPELL_WHITEOUT          RAID_MODE(72034,72096)  // Every 38 sec. cast. (after SPELL_FROZEN_ORB)
#define SPELL_FROZEN_MALLET     71993

// Spells Frost Warder
#define SPELL_FROST_BLAST   RAID_MODE(72123,72124)      // don't know cd... using 20 secs.
#define SPELL_FROZEN_MALLET_2 72122

// Spell Frozen Orb
#define SPELL_FROZEN_ORB_DMG    72081   // priodic dmg aura
#define SPELL_FROZEN_ORB_AURA   72067   // make visible

// Spell Frozen Orb Stalker
#define SPELL_FROZEN_ORB_SUMMON 72093   // summon orb

// Events boss
#define EVENT_FREEZING_GROUND   1
#define EVENT_FROZEN_ORB        2
#define EVENT_WHITEOUT          3

// Events mob
#define EVENT_FROST_BLAST   4

// Mob Frozen Orb
#define MOB_FROZEN_ORB 38456    // 1 in 10 mode and 3 in 25 mode

class boss_toravon : public CreatureScript
{
public:
    boss_toravon() : CreatureScript("boss_toravon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_toravonAI (pCreature);
    }

    struct boss_toravonAI : public ScriptedAI
    {
        boss_toravonAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;
        EventMap events;

        void Reset()
        {
            events.Reset();

            if (pInstance)
                pInstance->SetData(DATA_TORAVON_EVENT, NOT_STARTED);
        }

        void KilledUnit(Unit* /*Victim*/) {}

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_TORAVON_EVENT, DONE);
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoZoneInCombat();

            DoCast(me, SPELL_FROZEN_MALLET);

            events.ScheduleEvent(EVENT_FROZEN_ORB, 11000);
            events.ScheduleEvent(EVENT_WHITEOUT, 13000);
            events.ScheduleEvent(EVENT_FREEZING_GROUND, 15000);

            if (pInstance)
                pInstance->SetData(DATA_TORAVON_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_FROZEN_ORB:
                        DoCast(me, SPELL_FROZEN_ORB);
                        events.ScheduleEvent(EVENT_FROZEN_ORB, 38000);
                        return;
                    case EVENT_WHITEOUT:
                        DoCast(me, SPELL_WHITEOUT);
                        events.ScheduleEvent(EVENT_WHITEOUT, 38000);
                        return;
                    case EVENT_FREEZING_GROUND:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_FREEZING_GROUND);
                        events.ScheduleEvent(EVENT_FREEZING_GROUND, 20000);
                        return;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

/*######
##  Mob Frost Warder
######*/
class mob_frost_warder : public CreatureScript
{
public:
    mob_frost_warder() : CreatureScript("mob_frost_warder") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_frost_warderAI (pCreature);
    }

    struct mob_frost_warderAI : public ScriptedAI
    {
        mob_frost_warderAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoZoneInCombat();

            DoCast(me, SPELL_FROZEN_MALLET_2);

            events.ScheduleEvent(EVENT_FROST_BLAST, 5000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_FROST_BLAST:
                        DoCast(me->getVictim(), SPELL_FROST_BLAST);
                        events.ScheduleEvent(EVENT_FROST_BLAST, 20000);
                        return;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};


/*######
##  Mob Frozen Orb
######*/
class mob_frozen_orb : public CreatureScript
{
public:
    mob_frozen_orb() : CreatureScript("mob_frozen_orb") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_frozen_orbAI (pCreature);
    }

    struct mob_frozen_orbAI : public ScriptedAI
    {
        mob_frozen_orbAI(Creature *c) : ScriptedAI(c) {}

        bool done;
        uint32 killtimer;

        void Reset()
        {
            done = false;
            killtimer = 60000; // if after this time there is no victim -> destroy!
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!done)
            {
                DoCast(me, SPELL_FROZEN_ORB_AURA, true);
                DoCast(me, SPELL_FROZEN_ORB_DMG, true);
                done = true;
            }

            if (killtimer <= diff)
            {
                if (!UpdateVictim())
                    me->ForcedDespawn();
                killtimer = 10000;
            }
            else
                killtimer -= diff;
        }
    };

};

/*######
##  Mob Frozen Orb Stalker
######*/
class mob_frozen_orb_stalker : public CreatureScript
{
public:
    mob_frozen_orb_stalker() : CreatureScript("mob_frozen_orb_stalker") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_frozen_orb_stalkerAI (pCreature);
    }

    struct mob_frozen_orb_stalkerAI : public Scripted_NoMovementAI
    {
        mob_frozen_orb_stalkerAI(Creature* c) : Scripted_NoMovementAI(c)
        {
            c->SetVisible(false);
            c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_DISABLE_MOVE);
            c->SetReactState(REACT_PASSIVE);

            pInstance = c->GetInstanceScript();
            spawned = false;
        }

        InstanceScript *pInstance;
        bool spawned;

        void UpdateAI(const uint32 /*diff*/)
        {
            if (spawned)
                return;

            spawned = true;
            if (!pInstance)
                return;

            Unit* pToravon = me->GetCreature(*me, pInstance->GetData64(DATA_TORAVON));
            if (!pToravon)
                return;

            uint8 num_orbs = RAID_MODE(1, 3);
            for (uint8 i=0; i<num_orbs; ++i)
            {
                Position pos;
                me->GetNearPoint(pToravon, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0.0f, 10.0f, 0.0f);
                me->SetPosition(pos, true);
                DoCast(me, SPELL_FROZEN_ORB_SUMMON);
            }
        }
    };

};





void AddSC_boss_toravon()
{
    new boss_toravon();
    new mob_frost_warder();
    new mob_frozen_orb();
    new mob_frozen_orb_stalker();
}
