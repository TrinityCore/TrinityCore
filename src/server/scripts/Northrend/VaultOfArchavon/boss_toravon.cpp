// Copyright (C) 2010-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

// TODO: Schneesturm (SPELL_WHITEOUT) Areaeffekt fixen - keiner vorhanden imo!

#include "ScriptPCH.h"
#include "vault_of_archavon.h"

#include "OutdoorPvPMgr.h"
#include "OutdoorPvPTW.h"

#define SPELL_FREEZING_GROUND   RAID_MODE(72090,72104)
#define SPELL_FROZEN_ORB        RAID_MODE(72091,72095)  // Triggert 72092 - Spawnt die Stalker
#define SPELL_WHITEOUT          RAID_MODE(72034,72096)  // Every 38 sec. cast.
#define SPELL_FROST_BLAST       RAID_MODE(72123,72124)  // don't know cd... using 20 secs.

enum ToravonSpells
{
    // Spells Toravon
    SPELL_FROZEN_MALLET     = 71993,
    // Spells Frost Warder
    SPELL_FROZEN_MALLET_2   = 72122,
    // Spell Frozen Orb
    SPELL_FROZEN_ORB_DMG    = 72081,    // periodic dmg aura
    SPELL_FROZEN_ORB_AURA   = 72067,    // make visible
    // Spell Frozen Orb Stalker
    SPELL_FROZEN_ORB_SUMMON = 72094     // Groundeffect + Summon of Orb
};

enum ToravonEvents
{
    // Events boss
    EVENT_FREEZING_GROUND = 1,
    EVENT_FROZEN_ORB,
    EVENT_WHITEOUT,
    EVENT_TW_CHECK,
    // Events mob
    EVENT_FROST_BLAST
};

enum ToravonCreatures
{
    // Mob Frozen Orb
    MOB_FROZEN_ORB          = 38456,    // 1 in 10 mode and 3 in 25 mode
    MOB_FROZEN_ORB_STALKER  = 38461     // 1 of them is spawned for each player (through SPELL_FROZEN_ORB which triggers 72092)!
};

// Mob Frozen Orb Stalker
class mob_frozen_orb_stalker : public CreatureScript
{
public:
    mob_frozen_orb_stalker() : CreatureScript("mob_frozen_orb_stalker") { }

    struct mob_frozen_orb_stalkerAI : public Scripted_NoMovementAI
    {
        mob_frozen_orb_stalkerAI(Creature* c) : Scripted_NoMovementAI(c)
        {
            summon_done = false;
            can_start = false;
        }

        bool summon_done,
            can_start;

        void UpdateAI(const uint32 diff)
        {
            if (can_start && !summon_done)
            {
                DoCast(me, SPELL_FROZEN_ORB_SUMMON);
                summon_done = true;
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_frozen_orb_stalkerAI (pCreature);
    }
};

// Boss Toravon
class boss_toravon : public CreatureScript
{
public:
    boss_toravon() : CreatureScript("boss_toravon") { }

    struct boss_toravonAI : public ScriptedAI
    {
        boss_toravonAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            num_orbs = RAID_MODE(1,3);
        }

        InstanceScript *pInstance;
        EventMap events;
        EventMap eventsTW;
        uint32 spawntimer;
        uint8 num_orbs;

        void Reset()
        {
            // Only for orbs because the stalker despawns automatic
            std::list<Creature*> OrbList;
            GetCreatureListWithEntryInGrid(OrbList, me, MOB_FROZEN_ORB, 150.0f);
            for (std::list<Creature*>::iterator iter = OrbList.begin(); iter != OrbList.end(); ++iter)
                if ((*iter) && iter != OrbList.end())
                    CAST_CRE((*iter))->ForcedDespawn();

            events.Reset();
            eventsTW.Reset();
            eventsTW.ScheduleEvent(EVENT_TW_CHECK, 100);

            spawntimer = 0;

            if (pInstance)
                pInstance->SetData(DATA_TORAVON_EVENT, NOT_STARTED);
        }

        void JustDied(Unit* Killer)
        {
            if (pInstance)
                pInstance->SetData(DATA_TORAVON_EVENT, DONE);
        }

        void EnterCombat(Unit *who)
        {
            DoZoneInCombat();

            DoCast(me, SPELL_FROZEN_MALLET);

            events.ScheduleEvent(EVENT_FROZEN_ORB, 38000);
            events.ScheduleEvent(EVENT_WHITEOUT, 18000);
            events.ScheduleEvent(EVENT_FREEZING_GROUND, 28000);

            if (pInstance)
                pInstance->SetData(DATA_TORAVON_EVENT, IN_PROGRESS);
        }

        void StartSummonOrb()
        {
            uint8 cnt = 0;
            std::list<Creature*> StalkerList;
            GetCreatureListWithEntryInGrid(StalkerList, me, MOB_FROZEN_ORB_STALKER, 100.0f);
            for (std::list<Creature*>::iterator iter = StalkerList.begin(); iter != StalkerList.end(); ++iter)
            {
                if ((*iter) && iter != StalkerList.end())
                {
                    if (cnt < num_orbs)
                    {
                        CAST_AI(mob_frozen_orb_stalker::mob_frozen_orb_stalkerAI, (*iter)->AI())->can_start = true;
                        ++cnt;
                    }
                    else
                        break;
                }
            }
            spawntimer = 0;
        }

        void CheckTW()
        {
            if (Tausendwinter * pTW = const_cast<Tausendwinter*> ((Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER)))
                pTW->DarfAngegriffenWerden(me);

            eventsTW.RescheduleEvent(EVENT_TW_CHECK, 29000);
        }

        void UpdateAI(const uint32 diff)
        {
            eventsTW.Update(diff);

            if (eventsTW.ExecuteEvent() == EVENT_TW_CHECK)
                CheckTW();

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (spawntimer && spawntimer <= diff)
                StartSummonOrb();
            else
                if (spawntimer)
                    spawntimer -= diff;

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_FROZEN_ORB:
                        spawntimer = 2000;
                        DoCast(me, SPELL_FROZEN_ORB);
                        events.ScheduleEvent(EVENT_FROZEN_ORB, 32000);
                        return;
                    case EVENT_WHITEOUT:
                        DoCast(me, SPELL_WHITEOUT);
                        events.ScheduleEvent(EVENT_WHITEOUT, 38000);
                        return;
                    case EVENT_FREEZING_GROUND:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_FREEZING_GROUND);
                        events.ScheduleEvent(EVENT_FREEZING_GROUND, 28000);
                        return;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_toravonAI (pCreature);
    }
};

// Mob Frost Warder
class mob_frost_warder : public CreatureScript
{
public:
    mob_frost_warder() : CreatureScript("mob_frost_warder") { }

    struct mob_frost_warderAI : public ScriptedAI
    {
        mob_frost_warderAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;
        EventMap eventsTW;

        void Reset()
        {
            events.Reset();
            eventsTW.Reset();
            eventsTW.ScheduleEvent(EVENT_TW_CHECK, 100);
        }

        void EnterCombat(Unit *who)
        {
            DoZoneInCombat();

            DoCast(me, SPELL_FROZEN_MALLET_2);

            events.ScheduleEvent(EVENT_FROST_BLAST, 5000);
        }

        void CheckTW()
        {
            if (Tausendwinter * pTW = const_cast<Tausendwinter*> ((Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER)))
                pTW->DarfAngegriffenWerden(me);

            eventsTW.RescheduleEvent(EVENT_TW_CHECK, 29000);
        }

        void UpdateAI(const uint32 diff)
        {
            eventsTW.Update(diff);

            if (eventsTW.ExecuteEvent() == EVENT_TW_CHECK)
                CheckTW();

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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_frost_warderAI (pCreature);
    }
};

// Mob Frozen Orb
class mob_frozen_orb : public CreatureScript
{
public:
    mob_frozen_orb() : CreatureScript("mob_frozen_orb") { }

    struct mob_frozen_orbAI : public ScriptedAI
    {
        mob_frozen_orbAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            done = false;
        }

        InstanceScript *pInstance;

        bool done;

        void Reset() {}

        void EnterCombat(Unit *who)
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

            if (!UpdateVictim() && pInstance)
            {
                Unit* pToravon = me->GetMap()->GetCreature(pInstance->GetData64(DATA_TORAVON));
                if (pToravon)
                {
                    Unit* pTarget = pToravon->SelectNearbyTarget(50);
                    if (pTarget)
                        me->AI()->AttackStart(pTarget);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_frozen_orbAI (pCreature);
    }
};

void AddSC_boss_toravon()
{
    new boss_toravon();
    new mob_frost_warder();
    new mob_frozen_orb();
    new mob_frozen_orb_stalker();
}
