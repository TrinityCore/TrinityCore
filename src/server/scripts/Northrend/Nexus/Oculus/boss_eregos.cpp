/*
 * Copyright (C) 2010 TrinityScript 2
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
#include "oculus.h"

//Types of drake mounts: Ruby(Tank),  Amber(DPS),  Emerald(Healer)
//Two Repeating phases

enum Spells
{
    SPELL_ARCANE_BARRAGE                          = 50804,
    H_SPELL_ARCANE_BARRAGE                        = 59381,
    SPELL_ARCANE_VOLLEY                           = 51153,
    H_SPELL_ARCANE_VOLLEY                         = 59382,
    SPELL_ENRAGED_ASSAULT                         = 51170,
    SPELL_PLANAR_ANOMALIES                        = 57959,
    SPELL_PLANAR_SHIFT                            = 51162,
    SPELL_ARCANE_SHIELD                           = 53813,
    SPELL_PLANAR_BLAST                            = 57976,
};
/*Ruby Drake ,
(npc 27756) (item 37860)
(summoned by spell Ruby Essence = 37860 ---> Call Amber Drake == 49462 ---> Summon 27756)
*/
enum RubyDrake
{
    NPC_RUBY_DRAKE_VEHICLE                        = 27756,
    SPELL_RIDE_RUBY_DRAKE_QUE                     = 49463,          //Apply Aura: Periodic Trigger, Interval: 3 seconds ---> 49464
    SPELL_RUBY_DRAKE_SADDLE                       = 49464,          //Allows you to ride on the back of an Amber Drake. ---> Dummy
    SPELL_RUBY_SEARING_WRATH                      = 50232,          //(60 yds) - Instant - Breathes a stream of fire at an enemy dragon, dealing 6800 to 9200 Fire damage and then jumping to additional dragons within 30 yards. Each jump increases the damage by 50%. Affects up to 5 total targets
    SPELL_RUBY_EVASIVE_AURA                       = 50248,          //Instant - Allows the Ruby Drake to generate Evasive Charges when hit by hostile attacks and spells.
    SPELL_RUBY_EVASIVE_MANEUVERS                  = 50240,          //Instant - 5 sec. cooldown - Allows your drake to dodge all incoming attacks and spells. Requires Evasive Charges to use. Each attack or spell dodged while this ability is active burns one Evasive Charge. Lasts 30 sec. or until all charges are exhausted.
    //you do not have acces to until you kill Mage-Lord Urom
    SPELL_RUBY_MARTYR                             = 50253          //Instant - 10 sec. cooldown - Redirect all harmful spells cast at friendly drakes to yourself for 10 sec.
};
/*Amber Drake,
(npc 27755)  (item 37859)
(summoned by spell Amber Essence = 37859 ---> Call Amber Drake == 49461 ---> Summon 27755)
*/
enum AmberDrake
{
    NPC_AMBER_DRAKE_VEHICLE                       = 27755,
    SPELL_RIDE_AMBER_DRAKE_QUE                    = 49459,          //Apply Aura: Periodic Trigger, Interval: 3 seconds ---> 49460
    SPELL_AMBER_DRAKE_SADDLE                      = 49460,          //Allows you to ride on the back of an Amber Drake. ---> Dummy
    SPELL_AMBER_SHOCK_LANCE                       = 49840,         //(60 yds) - Instant - Deals 4822 to 5602 Arcane damage and detonates all Shock Charges on an enemy dragon. Damage is increased by 6525 for each detonated.
//  SPELL_AMBER_STOP_TIME                                    //Instant - 1 min cooldown - Halts the passage of time, freezing all enemy dragons in place for 10 sec. This attack applies 5 Shock Charges to each affected target.
    //you do not have access to until you kill the  Mage-Lord Urom.
    SPELL_AMBER_TEMPORAL_RIFT                     = 49592         //(60 yds) - Channeled - Channels a temporal rift on an enemy dragon for 10 sec. While trapped in the rift, all damage done to the target is increased by 100%. In addition, for every 15,000 damage done to a target affected by Temporal Rift, 1 Shock Charge is generated.
};
/*Emerald Drake,
(npc 27692)  (item 37815),
 (summoned by spell Emerald Essence = 37815 ---> Call Emerald Drake == 49345 ---> Summon 27692)
*/
enum EmeraldDrake
{
    NPC_EMERALD_DRAKE_VEHICLE                     = 27692,
    SPELL_RIDE_EMERALD_DRAKE_QUE                  = 49427,         //Apply Aura: Periodic Trigger, Interval: 3 seconds ---> 49346
    SPELL_EMERALD_DRAKE_SADDLE                    = 49346,         //Allows you to ride on the back of an Amber Drake. ---> Dummy
    SPELL_EMERALD_LEECHING_POISON                 = 50328,         //(60 yds) - Instant - Poisons the enemy dragon, leeching 1300 to the caster every 2 sec. for 12 sec. Stacks up to 3 times.
    SPELL_EMERALD_TOUCH_THE_NIGHTMARE             = 50341,         //(60 yds) - Instant - Consumes 30% of the caster's max health to inflict 25,000 nature damage to an enemy dragon and reduce the damage it deals by 25% for 30 sec.
    // you do not have access to until you kill the Mage-Lord Urom
    SPELL_EMERALD_DREAM_FUNNEL                    = 50344         //(60 yds) - Channeled - Transfers 5% of the caster's max health to a friendly drake every second for 10 seconds as long as the caster channels.
};

enum adds
{
    PLANAR_ANOMALY                          = 30879
};

class boss_eregos : public CreatureScript
{
    public:
        boss_eregos(): CreatureScript("boss_eregos") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_eregosAI (pCreature);
    }

    struct boss_eregosAI : public ScriptedAI
    {
        boss_eregosAI(Creature *pCreature) : ScriptedAI(pCreature), lSummons(me)
        {
            pInstance = pCreature->GetInstanceScript();
        }

            InstanceScript* pInstance;
            uint32 uiArcaneBarrage_Timer;
            uint32 uiArcaneVolley_Timer;
            uint32 uiEnragedAssault_Timer;
            bool hp1,hp2,started;
            int phase;
            SummonList lSummons;

        void Reset()
        {
            if (pInstance)
                    {
                pInstance->SetData(DATA_EREGOS_EVENT, NOT_STARTED);
                    }
                    uiArcaneBarrage_Timer       = 3000;
                    uiArcaneVolley_Timer        = 10000;
                    uiEnragedAssault_Timer      = 30000;
                    hp1 = false;
                    hp2 = false;
                    phase = 1;
                    started = false;
                    lSummons.DespawnAll();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveRandom(80.0f);
                    me->SetReactState(REACT_PASSIVE);
        }

            void SummonPlanarAnomaly()
            {
                    std::list<HostileReference*>& m_threatlist = me->getThreatManager().getThreatList();
                    std::list<HostileReference*>::const_iterator i = m_threatlist.begin();
                    for (i = m_threatlist.begin(); i!= m_threatlist.end(); ++i)
                    {
                            Unit* pUnit = Unit::GetUnit((*me), (*i)->getUnitGuid());
                            if (pUnit )
                            {
                                    Creature* summon = DoSummon(PLANAR_ANOMALY, me, 3.0f, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                    if(summon)
                                    {
                                            summon->Attack(pUnit,true);
                                            //printf("PLANAR_ANOMALY attack uinit %s \n",pUnit->GetName());
                                            summon->SetVisible(true);
                                            summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                            summon->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                                    }
                            }
                    }
            }

        void EnterCombat(Unit* who)
        {
            if (pInstance)
                pInstance->SetData(DATA_EREGOS_EVENT, IN_PROGRESS);                
        }

        void UpdateAI(const uint32 uiDiff)
        {
                    if(!started && pInstance->GetData(DATA_UROM_EVENT) == DONE)
                    {
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->RemoveAllAuras();
                            me->SetReactState(REACT_AGGRESSIVE);
                            started=true;
                    }
            //Return since we have no target
            if (!UpdateVictim())
                return;

                    if(!hp1 && HealthBelowPct(60))
                    {
                            phase = 2;
                            hp1=true;
                    }

                    if(!hp2 && HealthBelowPct(20))
                    {
                            phase = 2;
                            hp2=true;
                    }

                    switch(phase)
                    {
                            case 1:
                                    if(!me->HasAura(SPELL_PLANAR_SHIFT))
                                    {
                                            lSummons.DespawnAll();
                                            if(uiArcaneBarrage_Timer <= uiDiff)
                                            {
                                                    uiArcaneBarrage_Timer = 3000;
                                                    DoCast(me->getVictim(),DUNGEON_MODE(SPELL_ARCANE_BARRAGE,H_SPELL_ARCANE_BARRAGE)); 
                                            } else uiArcaneBarrage_Timer -= uiDiff;

                                            if(uiArcaneVolley_Timer <= uiDiff)
                                            {
                                                    uiArcaneVolley_Timer = 8000;
                                                    DoCast(DUNGEON_MODE(SPELL_ARCANE_VOLLEY,H_SPELL_ARCANE_VOLLEY)); 
                                            } else uiArcaneVolley_Timer -= uiDiff;

                                            if(uiEnragedAssault_Timer <= uiDiff)
                                            {
                                                    uiEnragedAssault_Timer = 30000;
                                                    DoCast(SPELL_ENRAGED_ASSAULT); 
                                            } else uiEnragedAssault_Timer -= uiDiff;
                                            DoMeleeAttackIfReady();
                                    }
                                    break;
                            case 2:
                                    SummonPlanarAnomaly();
                                    DoCast(SPELL_PLANAR_SHIFT);
                                    phase = 1;
                                    break;

                    }
        }

            void JustSummoned(Creature* summoned)
            {
                lSummons.Summon(summoned);
            }

        void JustDied(Unit* killer)
        {
            if (pInstance)
                    {
                pInstance->SetData(DATA_EREGOS_EVENT, DONE);
                    }
                    lSummons.DespawnAll();
        }
    };
};

class npc_planar_anomaly : public CreatureScript
{
    public:
        npc_planar_anomaly(): CreatureScript("npc_planar_anomaly") {}

    struct npc_planar_anomalyAI : public ScriptedAI
    {
        npc_planar_anomalyAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiDeathTimer;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MoveRandom(40.0f);

            uiDeathTimer = 16000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiDeathTimer <= uiDiff)
            {
                DoCast(SPELL_PLANAR_BLAST);
                uiDeathTimer = 15*IN_MILLISECONDS;
            } else uiDeathTimer -= uiDiff;

            if (uiDeathTimer <= uiDiff)
                me->DisappearAndDie();
            else uiDeathTimer -= uiDiff;
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_planar_anomalyAI (pCreature);
    };
};

void AddSC_boss_eregos()
{
    new boss_eregos();
    new npc_planar_anomaly();
}