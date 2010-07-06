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

/*** SQL START ***
UPDATE `creature_template` SET `ScriptName`='boss_toravon' WHERE `entry`='38433';
UPDATE `creature_template` SET `ScriptName`='mob_frost_warder' WHERE `entry`='38482';
UPDATE `creature_template` SET `ScriptName`='mob_frozen_orb_stalker' WHERE `entry`='38461';
UPDATE `creature_template` SET `ScriptName`='mob_frozen_orb' WHERE `entry`='38456';
*** SQL END ***/

#include "ScriptPCH.h"
#include "vault_of_archavon.h"

// Spells Toravon
#define SPELL_FREEZING_GROUND   RAID_MODE(72090,72104)  // don't know cd... using 20 secs.
#define SPELL_FROZEN_ORB        RAID_MODE(72091,72095)
#define SPELL_WHITEOUT          RAID_MODE(72034,72096)  // Every 38 sec. cast. (after SPELL_FROZEN_ORB)
#define SPELL_FROZEN_MALLET     71993

// Spells Frost Warder
#define SPELL_FROST_BLAST   RAID_MODE(72123,72124)      // don't know cd... using 20 secs.
#define SPELL_FROZEN_MALLET 72122

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

struct boss_toravonAI : public ScriptedAI
{
    boss_toravonAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;
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

        if (me->hasUnitState(UNIT_STAT_CASTING))
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

/*######
##  Mob Frost Warder
######*/
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

        DoCast(me, SPELL_FROZEN_MALLET);

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


/*######
##  Mob Frozen Orb
######*/
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

/*######
##  Mob Frozen Orb Stalker
######*/
struct mob_frozen_orb_stalkerAI : public Scripted_NoMovementAI
{
    mob_frozen_orb_stalkerAI(Creature* c) : Scripted_NoMovementAI(c)
    {
        c->SetVisibility(VISIBILITY_OFF);
        c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_DISABLE_MOVE);
        c->SetReactState(REACT_PASSIVE);

        pInstance = c->GetInstanceData();
        spawned = false;
    }

    ScriptedInstance *pInstance;
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

CreatureAI* GetAI_boss_toravon(Creature* pCreature)
{
    return new boss_toravonAI (pCreature);
}

CreatureAI* GetAI_mob_frost_warder(Creature* pCreature)
{
    return new mob_frost_warderAI (pCreature);
}

CreatureAI* GetAI_mob_frozen_orb(Creature* pCreature)
{
    return new mob_frozen_orbAI (pCreature);
}

CreatureAI* GetAI_mob_frozen_orb_stalker(Creature* pCreature)
{
    return new mob_frozen_orb_stalkerAI (pCreature);
}

void AddSC_boss_toravon()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_toravon";
    newscript->GetAI = &GetAI_boss_toravon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_frost_warder";
    newscript->GetAI = &GetAI_mob_frost_warder;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_frozen_orb";
    newscript->GetAI = &GetAI_mob_frozen_orb;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_frozen_orb_stalker";
    newscript->GetAI = &GetAI_mob_frozen_orb_stalker;
    newscript->RegisterSelf();
}
