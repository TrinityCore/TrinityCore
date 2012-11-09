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
 
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptPCH.h"
#include "halls_of_origination.h"

enum Spells
{
    //Ammunae
    SPELL_WITHER                           = 76043,
    SPELL_CONSUME_LIFE_DAMAGE_EFFECT       = 79767,
    SPELL_CONSUME_LIFE_ENERGIZE_EFFECT     = 75665,
    SPELL_CONSUME_LIFE_POWER_BURN_EFFECT   = 75666,
    SPELL_RAMPANT_GROWTH                   = 75790,   //Only with 100 energy

    //Seeding Pod
    SPELL_ENERGIZE                         = 75657,
    SPELL_ENERGIZING_GROWTH                = 89123,   //Only Hero

    //Bloodpetal
    SPELL_THORN_SLASH                      = 76044,

    //Spore
    SPELL_NOXIOUS_SPORE                    = 75702,    //Triggered by Spore Cloud
    SPELL_SPORE_CLOUD                      = 75701
};

enum NPCs
{
    NPC_SEEDING_POD         = 51329,
    //NPC_BLOODPETAL_BLOSSOM  = 40622,
    NPC_SPORE               = 40585
};

enum ScriptTexts
{
    SAY_AGGRO                = 0,
    SAY_GROWTH               = 1,
    SAY_KILL                 = 2,
    SAY_DEATH                = 3,
};

enum Gameobjects
{
};

enum Events
{
    EVENT_WITHER               = 1,
    EVENT_CONSUME_LIFE         = 2,
    EVENT_RAMPANT_GROWTH       = 3,
    EVENT_SUMMON_POD           = 4,
    EVENT_SUMMON_SPORE         = 5
};

enum Timers
{
    TIMER_WITHER               = 7500,
    TIMER_CONSUME_LIFE         = 20000,
    TIMER_RAMPANT_GROWTH       = 15000,
    TIMER_SUMMON_POD           = 5000,
    TIMER_SUMMON_SPORE         = 15000
};

class boss_ammunae : public CreatureScript
{
    public:
        boss_ammunae() : CreatureScript("boss_ammunae") { }

        struct boss_ammunaeAI : public BossAI
        {
            boss_ammunaeAI(Creature* creature) : BossAI(creature, DATA_AMMUNAE_EVENT)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_AMMUNAE_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                //DoScriptText(SAY_AGGRO, me);

                if (instance)
                    instance->SetData(DATA_AMMUNAE_EVENT, IN_PROGRESS);

                events.ScheduleEvent(EVENT_WITHER, TIMER_WITHER);
                events.ScheduleEvent(EVENT_CONSUME_LIFE, TIMER_CONSUME_LIFE);
                events.ScheduleEvent(EVENT_RAMPANT_GROWTH, TIMER_RAMPANT_GROWTH);
                events.ScheduleEvent(EVENT_SUMMON_POD, TIMER_SUMMON_POD);
                events.ScheduleEvent(EVENT_SUMMON_SPORE, TIMER_SUMMON_SPORE);

                DoZoneInCombat();
            }

            void RampartSummon(uint32 entry, float distance)
            {
                std::list<Creature*> pCreatureList;
                Trinity::AllCreaturesOfEntryInRange checker(me, entry, distance);
                Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, pCreatureList, checker);
                me->VisitNearbyObject(distance, searcher);
                if (pCreatureList.empty())
                    return;

                std::list<Creature*>::iterator itr = pCreatureList.begin();
                uint32 count = pCreatureList.size();
                for (std::list<Creature*>::iterator iter = pCreatureList.begin(); iter != pCreatureList.end(); ++iter)
                {
                    (*iter)->SummonCreature(NPC_BLOODPETAL_BLOSSOM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    (*iter)->DespawnOrUnsummon();
                }
            }

            void DoRampartGrowth()
            {
                //DoScriptText(SAY_GROWTH, me);
                me->SetPower(POWER_ENERGY, 0);
                DoCastAOE(SPELL_RAMPANT_GROWTH);
                RampartSummon(NPC_SEEDING_POD, 100);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WITHER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                                DoCast(target, SPELL_WITHER);
                                events.ScheduleEvent(EVENT_WITHER, 1000);
                            break;
                        case EVENT_CONSUME_LIFE:
                            DoCast(me->getVictim(), SPELL_CONSUME_LIFE_DAMAGE_EFFECT);
                            events.ScheduleEvent(EVENT_CONSUME_LIFE, urand(15000, 22000));
                            break;
                        case EVENT_RAMPANT_GROWTH:
                            if (me->GetPower(POWER_ENERGY) == me->GetMaxPower(POWER_ENERGY))
                                DoRampartGrowth();
                            events.ScheduleEvent(EVENT_RAMPANT_GROWTH, 10000);
                            break;
                        case EVENT_SUMMON_POD:
                            me->SummonCreature(NPC_SEEDING_POD, me->GetPositionX()+rand()%10, me->GetPositionY()+rand()%10, me->GetPositionZ());
                            events.ScheduleEvent(EVENT_SUMMON_POD, 20000);
                            break;
                        case EVENT_SUMMON_SPORE:
                            me->SummonCreature(NPC_SPORE, me->GetPositionX()+rand()%10, me->GetPositionY()+rand()%10, me->GetPositionZ());
                            events.ScheduleEvent(EVENT_SUMMON_SPORE, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                //DoScriptText(SAY_DEATH, me);

                if (instance)
                    instance->SetData(DATA_AMMUNAE_EVENT, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ammunaeAI(creature);
        }
};

class mob_bloodpetal_blossom : public CreatureScript
{
public:
    mob_bloodpetal_blossom() : CreatureScript("mob_bloodpetal_blossom") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_bloodpetal_blossomAI(creature);
    }

    struct mob_bloodpetal_blossomAI : public ScriptedAI
    {
        mob_bloodpetal_blossomAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* instance;
        uint32 SlashTimer;

        void Reset()
        {
            SlashTimer = 5000;
        }

         void UpdateAI(uint32 const diff)
         {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

            if (SlashTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_THORN_SLASH);
                SlashTimer = 7500;
            }
            else SlashTimer -= diff;
        }

        void JustDied(Unit* /*killer*/)
        {
            // used to despawn corpse immediately
            me->DespawnOrUnsummon();
        }
    };
};

class mob_seed_pod : public CreatureScript
{
public:
    mob_seed_pod() : CreatureScript("mob_seed_pod") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_seed_podAI(creature);
    }

    struct mob_seed_podAI : public Scripted_NoMovementAI
    {
        mob_seed_podAI(Creature* creature) : Scripted_NoMovementAI(creature), Summons(me)
        {
            instance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* instance;

        SummonList Summons;
        uint32 EnergizeTimer;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);

            EnergizeTimer = 1000;
            Summons.DespawnAll();
        }

        void Energize()
        {
            if (IsHeroic())
            {
                if (Unit* target = me->FindNearestCreature(BOSS_AMMUNAE, 100))
                {
                    DoCast(SPELL_ENERGIZE);
                    DoCast(target, SPELL_ENERGIZE);
                    DoCast(SPELL_ENERGIZING_GROWTH);
                    DoCast(target, SPELL_ENERGIZING_GROWTH);
                }
            }
            else
            {
                if (Unit* target = me->FindNearestCreature(BOSS_AMMUNAE, 100))
                {
                    DoCast(SPELL_ENERGIZE);
                    DoCast(target, SPELL_ENERGIZE);
                }
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if (EnergizeTimer <= diff)
            {
                Energize();
                EnergizeTimer = 3000;
            } else EnergizeTimer -= diff;
        }

        void JustDied(Unit* /*killer*/)
        {
            // used to despawn corpse immediately
            me->DespawnOrUnsummon();
        }
    };
};

class mob_spore : public CreatureScript
{
public:
    mob_spore() : CreatureScript("mob_spore") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_sporeAI(creature);
    }

    struct mob_sporeAI : public Scripted_NoMovementAI
    {
        mob_sporeAI(Creature* creature) : Scripted_NoMovementAI(creature), Summons(me)
        {
            instance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* instance;

        SummonList Summons;
        uint32 SporeTimer;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);

            SporeTimer = 1000;
            Summons.DespawnAll();
        }

        void UpdateAI(uint32 const diff)
        {
            if (SporeTimer <= diff)
            {
                DoCast(SPELL_SPORE_CLOUD);
                //SporeTimer = 3000;
            }
            else SporeTimer -= diff;
        }

        void JustDied(Unit* /*killer*/)
        {
            // used to despawn corpse immediately
            me->DespawnOrUnsummon();
        }
    };
};

void AddSC_boss_ammunae()
{
    new boss_ammunae;
    new mob_bloodpetal_blossom;
    new mob_seed_pod;
    new mob_spore;
}