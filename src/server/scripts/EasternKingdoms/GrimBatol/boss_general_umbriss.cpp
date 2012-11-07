/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

#define SAY_AGGRO "A million more await my orders. What chance you do have?"
#define SAY_DIED "Vermin, your dinner awaits!"

enum CreatureIds
{
    BOSS_UMBRISS    = 39625,
    MOB_TROGG_MALICE   = 39984,
    MOB_TROGG_DWE   = 45467,
};

enum Spells
{
    //Umbriss
    SPELL_FRENZY = 74853,
    SPELL_GROUND_SIEGE = 74634,
    SPELL_BLITZ = 74670,
    SPELL_BLEENDING_WOUND = 74846,
    SPELL_SUMMON_SKARDYN = 74859,
    //Trogg Malveillant and Dweller
    SPELL_MALICE = 74699,
    SPELL_MALICE_EFFECT = 90170,
    SPELL_MODGUD = 74837,
    SPELL_PUNCTURE = 76507,
};

enum Events
{
    //Umbriss
    EVENT_GROUND_SIEGE  = 0,
    EVENT_BLITZ   = 1,
    EVENT_BLEENDING_WOUND    = 2,
    EVENT_SUMMON_SKARDYN   = 3,
    //Trogg
    EVENT_PUNCTURE   = 4,
    EVENT_MALICE      = 5,
    EVENT_MOGUD    = 6,
};

enum SummonIds
{
    NPC_TROGG_MALICE = 39984,
    NPC_TROGG_DWE = 45467,
};

const Position aSpawnLocations[3] =
{
    {-721.551697f, -439.109711f, 268.767456f, 0.814808f},
    {-700.411255f, -454.676971f, 268.767395f, 1.388150f},
    {-697.920105f, -435.002228f, 269.147583f, 1.470617f},
};

class boss_umbriss : public CreatureScript
{
    public:
        boss_umbriss() : CreatureScript("boss_umbriss") {}

        struct boss_umbrissAI : public ScriptedAI
        {
            boss_umbrissAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            SummonList Summons;

            bool isEnraged;

            void EnterCombat(Unit * /*who*/)
            {
                EnterPhaseGround();
                me->MonsterYell(SAY_AGGRO, 0, 0);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->MonsterYell(SAY_DIED, 0, 0);
            }

            void JustSummoned(Creature *pSummoned)
            {
                pSummoned->SetInCombatWithZone();
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                pSummoned->AI()->AttackStart(pTarget);

                Summons.Summon(pSummoned);
            }

            void Reset()
            {
                events.Reset();
                Summons.DespawnAll();
                isEnraged = false;
            }

            void EnterPhaseGround()
            {
                events.ScheduleEvent(EVENT_GROUND_SIEGE, 6000);
                events.ScheduleEvent(EVENT_BLITZ, 13000);
                events.ScheduleEvent(EVENT_BLEENDING_WOUND, 20000);
                events.ScheduleEvent(EVENT_SUMMON_SKARDYN, 60000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (HealthBelowPct(30) && !isEnraged)
                {
                    DoCast(me, SPELL_FRENZY);
                    return;
                }
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_GROUND_SIEGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_GROUND_SIEGE);
                            events.ScheduleEvent(EVENT_GROUND_SIEGE, 6000);
                            return;
                        case EVENT_BLITZ:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,1,100,true))
                                DoCast(target, SPELL_BLITZ);
                            events.ScheduleEvent(EVENT_BLITZ, 13000);
                            return;
                        case EVENT_BLEENDING_WOUND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_BLEENDING_WOUND);
                            events.ScheduleEvent(EVENT_BLEENDING_WOUND, 20000);
                            return;
                        case EVENT_SUMMON_SKARDYN:
                            me->SummonCreature(NPC_TROGG_MALICE, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                            me->SummonCreature(NPC_TROGG_DWE, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                            events.ScheduleEvent(EVENT_SUMMON_SKARDYN, 60000);
                            return;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_umbrissAI(creature);
    }
};

class npc_malveillant: public CreatureScript
{
public:
 npc_malveillant() : CreatureScript("npc_malveillant") { }

 struct npc_malveillantAI : public ScriptedAI
    {
        npc_malveillantAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;

        void EnterCombat(Unit * /*who*/)
        {
            EnterPhaseGround();
        }

        void EnterPhaseGround()
        {
            events.ScheduleEvent(EVENT_PUNCTURE, 2000);
            events.ScheduleEvent(EVENT_MALICE, 6000);
            events.ScheduleEvent(EVENT_MOGUD, 12000);
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
                    case EVENT_PUNCTURE:
                        DoCastVictim(SPELL_PUNCTURE);
                        events.ScheduleEvent(EVENT_PUNCTURE, 2000);
                        return;
                    case EVENT_MALICE:
                        DoCastVictim(SPELL_MALICE);
                        events.ScheduleEvent(EVENT_MALICE, 6000);
                        return;
                    case EVENT_MOGUD:
                        DoCastVictim(SPELL_MODGUD);
                        events.ScheduleEvent(EVENT_MOGUD, 12000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_malveillantAI (pCreature);
    }

};

/****************
** Trogg Dweller
****************/
class npc_dweller: public CreatureScript
{
public:
 npc_dweller() : CreatureScript("npc_dweller") { }

 struct npc_dwellerAI : public ScriptedAI
    {
        npc_dwellerAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;

        void EnterCombat(Unit * /*who*/)
        {
            EnterPhaseGround();
        }

        void EnterPhaseGround()
        {
            events.ScheduleEvent(EVENT_PUNCTURE, 5000);
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
                    case EVENT_PUNCTURE:
                        DoCastVictim(SPELL_PUNCTURE);
                        events.ScheduleEvent(EVENT_PUNCTURE, 5000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_dwellerAI (pCreature);
    }

};

class ModgudMaladyTargetSelector
{
public:
    explicit ModgudMaladyTargetSelector(Unit* _caster) : caster(_caster) { }

    bool operator() (Unit* unit)
    {
        return !unit->IsWithinDist(caster, 8.0f);
    }

private:
    Unit* caster;
};

void AddSC_boss_general_umbriss()
{
    new boss_umbriss();
    new npc_dweller();
    new npc_malveillant();
}