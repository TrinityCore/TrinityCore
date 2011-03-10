/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "icecrown_citadel.h"

// KNOWN BUGS:
// ~ No Slime Spray animation directly at target spot

enum eTexts
{
    SAY_PRECIOUS_DIES           = 0,
    SAY_AGGRO                   = 1,
    EMOTE_SLIME_SPRAY           = 2,
    SAY_SLIME_SPRAY             = 3,
    EMOTE_UNSTABLE_EXPLOSION    = 4,
    SAY_UNSTABLE_EXPLOSION      = 5,
    SAY_KILL                    = 6,
    SAY_BERSERK                 = 7,
    SAY_DEATH                   = 8,

    SAY_PUTRI_SLIME            = -1631091,
    SAY_PUTRI_SLIME_2          = -1631092,
    SOUND_PUTRI_SLIME          = 17126,
    SOUND_PUTRI_SLIME_2        = 17123
};
#define NPC_UNSTABLE_EXPLOSION_STALKER              38107
#define NPC_PLAGUED_ZOMBIE                          38104
#define EMOTE_DECIMATE "Precious cries out with a loud, baying howl!"
enum eSpells
{
    // Rotface
    SPELL_SLIME_SPRAY                       = 69508,    // every 20 seconds
    SPELL_SLIME_SPRAY_1                     = 70881,
    //SPELL_MUTATED_INFECTION                 = 69674,    // hastens every 1:30

    SPELL_OOZE_FLOOD                        = 69783,
    SPELL_OOZE_FLOOD_1                      = 69785,
    SPELL_UNSTABLE_OOZE_EXPLOSION           = 69839,
    SPELL_UNSTABLE_OOZE_EXPLOSION_TRIGGER   = 69832,
    // Oozes
    SPELL_LITTLE_OOZE_COMBINE               = 69537,    // combine 2 Small Oozes
    SPELL_LARGE_OOZE_COMBINE                = 69552,    // combine 2 Large Oozes
    SPELL_LARGE_OOZE_BUFF_COMBINE           = 69611,    // combine Large and Small Ooze
    SPELL_OOZE_MERGE                        = 69889,    // 2 Small Oozes summon a Large Ooze
    SPELL_WEAK_RADIATING_OOZE               = 69750,    // passive damage aura - small
    SPELL_UNSTABLE_OOZE                     = 69558,    // damage boost and counter for explosion
    SPELL_GREEN_ABOMINATION_HITTIN__YA_PROC = 70001,    // prevents getting hit by infection
    SPELL_STICKY_OOZE                       = 69774,

    // Precious
    SPELL_MORTAL_WOUND                      = 71127,
    SPELL_DECIMATE                          = 71123,
    SPELL_AWAKEN_PLAGUED_ZOMBIES            = 71159,
    SPELL_INFECTED_WOUND                    = 71158
};
#define SPELL_OOZE_FLOOD_EFFECT  RAID_MODE<int32>(69789, 71215, 71587, 71588)
static const uint32 oozeFloodSpells[4] = {69782, 69796, 69798, 69801};
#define SPELL_MUTATED_INFECTION RAID_MODE<int32>(69674,71224,73022,73023)
#define SPELL_RADIATING_OOZE RAID_MODE<int32>(69760, 73026, 71212, 73027)   // passive damage aura - large

enum eEvents
{
    //Rotface
    EVENT_SLIME_SPRAY       = 1,
    EVENT_HASTEN_INFECTIONS = 2,
    EVENT_MUTATED_INFECTION = 3,

    //Precious
    EVENT_DECIMATE          = 4,
    EVENT_MORTAL_WOUND      = 5,
    EVENT_AWAKEN_PLAGUED_ZOMBIES = 6,

    //Ooze
    EVENT_STICKY_OOZE       = 7,
    EVENT_UNSTABLE_DESPAWN  = 8,

    //Slime pipes flood
    EVENT_FLOOD_EFFECT      = 9,
    EVENT_FLOOD_START       = 10
};
const Position SpawnLocOozeStream[]=
{
    {4468.825f, 3094.986f, 372.385f, 0.0f},
    {4487.825f, 3114.452f, 372.385f, 0.0f},
    {4489.825f, 3159.452f, 372.385f, 0.0f},
    {4467.825f, 3178.986f, 372.385f, 0.0f},
    {4424.421f, 3178.986f, 372.385f, 0.0f},
    {4404.821f, 3158.452f, 372.385f, 0.0f},
    {4404.825f, 3116.452f, 372.385f, 0.0f},
    {4424.825f, 3095.986f, 372.385f, 0.0f}
};

const Position SpawnLocPuddle[]=
{
    {4468.825f, 3094.986f, 360.385f, 0.0f},
    {4487.825f, 3114.452f, 360.385f, 0.0f},
    {4489.825f, 3159.452f, 360.385f, 0.0f},
    {4467.825f, 3178.986f, 360.385f, 0.0f},
    {4424.421f, 3178.986f, 360.385f, 0.0f},
    {4404.821f, 3158.452f, 360.385f, 0.0f},
    {4404.825f, 3116.452f, 360.385f, 0.0f},
    {4424.825f, 3095.986f, 360.385f, 0.0f}
};
class boss_rotface : public CreatureScript
{
    public:
        boss_rotface() : CreatureScript("boss_rotface") { }

        struct boss_rotfaceAI : public BossAI
        {
            //For debug reasons only - remove it after you find out good parameters
            uint8 bSprayVariant;
            uint32 sprayCooldown;
            boss_rotfaceAI(Creature* creature) : BossAI(creature, DATA_ROTFACE_EVENT)
            {
                bSprayVariant = true;
                sprayCooldown = 20000;
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_SLIME_SPRAY, 20000);
                events.ScheduleEvent(EVENT_HASTEN_INFECTIONS, 90000);
                events.ScheduleEvent(EVENT_MUTATED_INFECTION, 14000);
                events.ScheduleEvent(EVENT_FLOOD_START, 5000);
                infectionStage = 0;
                infectionCooldown = 14000;
                DespawnOozes();
                bFlood = false;
                uiStage = 0;
                uiFloodStage = 1;
                infectionStage = 0;
                uiOoozeStream1 = 0;
                uiOoozeStream2 = 0;
                uiPuddleStalker1 = 0;
                uiPuddleStalker2 = 0;
                infectionCooldown = 14000;
                //initialize random flood sequence
                for (uint8 i = 0; i < 4; ++i)
                    floodOrder[i] = i;
                for (uint8 i = 0; i < 4; ++i)
                {
                    uint8 j = urand(0, 3);
                    uint8 temp = floodOrder[0];
                    floodOrder[0] = floodOrder[j];
                    floodOrder[j] = temp;
                }
                //Prevent dummies to attack players or keep them in combat
                if (Creature* dummy = me->FindNearestCreature(NPC_OOZE_SPRAY_STALKER, 100.0f, true))
                    dummy->SetReactState(REACT_PASSIVE);
                if (Creature* dummy = me->FindNearestCreature(NPC_PUDDLE_STALKER, 100.0f, true))
                    dummy->SetReactState(REACT_PASSIVE);
                if (Creature* dummy = me->FindNearestCreature(NPC_GREEN_GAS_STALKER, 100.0f, true))
                    dummy->SetReactState(REACT_PASSIVE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
                if (Creature* professor = Unit::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_ROTFACE_COMBAT);

                DoZoneInCombat(me);
                //instance->SetData(DATA_ROTFACE_EVENT, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);
                instance->SetBossState(GUID_ROTFACE, DONE);
                instance->SetData(DATA_ROTFACE_EVENT, DONE);
                if (Creature* professor = Unit::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_ROTFACE_DEATH);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MUTATED_INFECTION);
                DespawnOozes();
            }
            void DespawnOozes()
            {
                summons.DespawnAll();
                //Sometimes it's not enough - despawn all oozes forcefully
                while (Creature *littleOoze = me->FindNearestCreature(NPC_LITTLE_OOZE, 200.0f, true))
                    littleOoze->DespawnOrUnsummon(); 
                while (Creature *bigOoze = me->FindNearestCreature(NPC_BIG_OOZE, 200.0f, true))
                    bigOoze->DespawnOrUnsummon(); 
            }
            void JustReachedHome()
            {
                instance->SetBossState(GUID_ROTFACE, FAIL);
                instance->SetData(DATA_OOZE_DANCE_ACHIEVEMENT, uint32(true));   // reset
                instance->SetData(DATA_ROTFACE_EVENT, FAIL);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MUTATED_INFECTION);

                DespawnOozes();
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
                if (Creature* professor = Unit::GetCreature(*me, instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    professor->AI()->EnterEvadeMode();
            }

            void SpellHitTarget(Unit* /*target*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_SLIME_SPRAY)
                    Talk(SAY_SLIME_SPRAY);
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
                // don't enter combat
            }

            Unit* GetAuraEffectTriggerTarget(uint32 spellId, uint8 /*effIndex*/)
            {
                if (spellId == SPELL_SLIME_SPRAY)
                {
                    for (std::list<uint64>::iterator itr = summons.begin(); itr != summons.end();)
                    {
                        Creature *summon = Unit::GetCreature(*me, *itr);
                        if (!summon)
                            summons.erase(itr++);
                        else if (summon->GetEntry() == NPC_OOZE_SPRAY_STALKER)
                            return summon;
                        else
                            ++itr;
                    }
                }

                return NULL;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!CheckInRoom())
                    EnterEvadeMode();
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FLOOD_EFFECT:
                        {
                            if(bFlood)
                            {
                                switch(uiFloodStage)
                                {
                                    case 1:
                                    {
                                        Creature *pOoozeStream1 = me->GetCreature(*me, uiOoozeStream1);
                                        Creature *pOoozeStream2 = me->GetCreature(*me, uiOoozeStream2);
                                        if (pOoozeStream1 && pOoozeStream2)
                                        {
                                            pOoozeStream1->CastSpell(pOoozeStream1, SPELL_OOZE_FLOOD, true);
                                            pOoozeStream2->CastSpell(pOoozeStream2, SPELL_OOZE_FLOOD, true); 
                                        }
                                        ++uiFloodStage;
                                        events.ScheduleEvent(EVENT_FLOOD_EFFECT, 4000);
                                    }
                                    break;
                                    case 2:
                                    {
                                        Creature *pPuddleStalker1 = me->GetCreature(*me, uiPuddleStalker1);
                                        Creature *pPuddleStalker2 = me->GetCreature(*me, uiPuddleStalker2);
                                        if (pPuddleStalker1 && pPuddleStalker2)
                                        {
                                            pPuddleStalker1->CastSpell(pPuddleStalker1, SPELL_OOZE_FLOOD_1, true);
                                            pPuddleStalker2->CastSpell(pPuddleStalker2, SPELL_OOZE_FLOOD_1, true);
                                            pPuddleStalker1->CastSpell(pPuddleStalker1, SPELL_OOZE_FLOOD_EFFECT, true);
                                            pPuddleStalker2->CastSpell(pPuddleStalker2, SPELL_OOZE_FLOOD_EFFECT, true);
                                            events.ScheduleEvent(EVENT_FLOOD_EFFECT, 1000);
                                        }
                                        ++uiFloodStage;
                                    }
                                    case 3:
                                    {
                                        Creature *pPuddleStalker1 = me->GetCreature(*me, uiPuddleStalker1);
                                        Creature *pPuddleStalker2 = me->GetCreature(*me, uiPuddleStalker2);
                                        if (pPuddleStalker1 && pPuddleStalker2)
                                        {
                                            pPuddleStalker1->CastSpell(pPuddleStalker1, SPELL_OOZE_FLOOD_EFFECT, true);
                                            pPuddleStalker2->CastSpell(pPuddleStalker2, SPELL_OOZE_FLOOD_EFFECT, true);
                                            events.ScheduleEvent(EVENT_FLOOD_EFFECT, 1000);
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case EVENT_FLOOD_START:
                        {
                            if(uiStage > 3)
                                uiStage = 0;

                            uint64 uiPutricide = (instance ? instance->GetData64(GUID_PROFESSOR_PUTRICIDE) : 0);
                            if (uiStage & 1)
                            {
                                if (Creature *pPutricide = me->GetCreature(*me, uiPutricide))
                                    DoScriptText(SAY_PUTRI_SLIME, pPutricide);
                            }
                            else
                            {
                                if (Creature *pPutricide = me->GetCreature(*me, uiPutricide))
                                    DoScriptText(SAY_PUTRI_SLIME_2, pPutricide);
                            }
                            
                            uiOoozeStream1 = me->SummonCreature(NPC_GREEN_GAS_STALKER, SpawnLocOozeStream[floodOrder[uiStage]*2], TEMPSUMMON_TIMED_DESPAWN, 4000)->GetGUID();
                            uiOoozeStream2 = me->SummonCreature(NPC_GREEN_GAS_STALKER, SpawnLocOozeStream[floodOrder[uiStage]*2 + 1], TEMPSUMMON_TIMED_DESPAWN, 4000)->GetGUID();
                            
                            uiPuddleStalker1 = me->SummonCreature(NPC_PUDDLE_STALKER, SpawnLocPuddle[floodOrder[uiStage]*2], TEMPSUMMON_TIMED_DESPAWN, 24000)->GetGUID();
                            uiPuddleStalker2 = me->SummonCreature(NPC_PUDDLE_STALKER, SpawnLocPuddle[floodOrder[uiStage]*2 + 1], TEMPSUMMON_TIMED_DESPAWN, 24000)->GetGUID();
                            ++uiStage;
                            uiFloodStage = 1;
                            bFlood = true;
                            events.ScheduleEvent(EVENT_FLOOD_START, 25000);
                            events.ScheduleEvent(EVENT_FLOOD_EFFECT, 1000);

                            break;
                        }
                        case EVENT_SLIME_SPRAY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Position pos;
                                target->GetPosition(&pos);
                                Creature *pSprayStalker = DoSummon(NPC_OOZE_SPRAY_STALKER, pos, 8000, TEMPSUMMON_TIMED_DESPAWN);
                                Talk(EMOTE_SLIME_SPRAY);
                                me->SetFacingToObject(pSprayStalker);
                                me->CastSpell(pSprayStalker, SPELL_SLIME_SPRAY_1, true);
                                me->CastSpell(pSprayStalker, SPELL_SLIME_SPRAY, true); 
                            }
                            events.ScheduleEvent(EVENT_SLIME_SPRAY, 20000);
                            break;
                        case EVENT_HASTEN_INFECTIONS:
                            if (infectionStage < 4)
                            {
                                infectionCooldown -= 2000;
                                events.ScheduleEvent(EVENT_HASTEN_INFECTIONS, 90000);
                                ++infectionStage;
                            }
                            break;
                        case EVENT_MUTATED_INFECTION:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_MUTATED_INFECTION);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_MUTATED_INFECTION);
                            if (target)
                                me->AddAura(SPELL_MUTATED_INFECTION, target); 
                            events.ScheduleEvent(EVENT_MUTATED_INFECTION, infectionCooldown);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 infectionCooldown;
            uint8 infectionStage;
            uint8 uiStage;
            uint8 uiFloodStage;
            bool bFlood;
            uint64 uiPuddleStalker1;
            uint64 uiPuddleStalker2;
            uint64 uiOoozeStream1;
            uint64 uiOoozeStream2;
            uint8 floodOrder[4];
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_rotfaceAI(creature);
        }
};

class npc_little_ooze : public CreatureScript
{
    public:
        npc_little_ooze() : CreatureScript("npc_ooze_little") { }

        struct npc_little_oozeAI : public ScriptedAI
        {
            npc_little_oozeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void IsSummonedBy(Unit* summoner)
            {
                DoCast(me, SPELL_LITTLE_OOZE_COMBINE, true);
                DoCast(me, SPELL_WEAK_RADIATING_OOZE, true);
                events.ScheduleEvent(EVENT_STICKY_OOZE, 5000);
                me->AddThreat(summoner, 500000.0f);
                // register in Rotface's summons - not summoned with Rotface as owner
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* rotface = Unit::GetCreature(*me, instance->GetData64(GUID_ROTFACE)))
                        rotface->AI()->JustSummoned(me);
                //Slow Little Oozes a bit
                me->SetSpeed(MOVE_WALK, me->GetSpeedRate(MOVE_RUN) * 0.9f);
                me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN) * 0.9f);
            }
            //Little ooze will always switch to target that dealed damage last time
            void DamageTaken(Unit *who, uint32 &)
            {
                me->getThreatManager().clearReferences();
                me->AddThreat(who, 1.0f);
            }
            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon();
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* rotface = Unit::GetCreature(*me, instance->GetData64(GUID_ROTFACE)))
                        rotface->AI()->SummonedCreatureDespawn(me);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_STICKY_OOZE)
                {
                    DoCastVictim(SPELL_STICKY_OOZE);
                    events.ScheduleEvent(EVENT_STICKY_OOZE, 15000);
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_little_oozeAI(creature);
        }
};

class npc_big_ooze : public CreatureScript
{
    public:
        npc_big_ooze() : CreatureScript("npc_ooze_big") { }

        struct npc_big_oozeAI : public ScriptedAI
        {
            npc_big_oozeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                DoCast(me, SPELL_LARGE_OOZE_COMBINE, true);
                DoCast(me, SPELL_LARGE_OOZE_BUFF_COMBINE, true);
                DoCast(me, SPELL_RADIATING_OOZE, true);
                DoCast(me, SPELL_UNSTABLE_OOZE, true);
                DoCast(me, SPELL_GREEN_ABOMINATION_HITTIN__YA_PROC, true);
                events.ScheduleEvent(EVENT_STICKY_OOZE, 5000);
                // register in Rotface's summons - not summoned with Rotface as owner
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* rotface = Unit::GetCreature(*me, instance->GetData64(GUID_ROTFACE)))
                        rotface->AI()->JustSummoned(me);
                //Big Oozes deal high melee damage, move at HALF speed and have a normal aggro table -- thus they can be kited.
                //Source: wowwiki.com
                me->SetSpeed(MOVE_WALK, me->GetSpeedRate(MOVE_RUN) * 0.5f);
                me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN) * 0.5f); 
            }

            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon();
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* rotface = Unit::GetCreature(*me, instance->GetData64(GUID_ROTFACE)))
                        rotface->AI()->SummonedCreatureDespawn(me);
            }

            void DoAction(const int32 action)
            {
                if (action == EVENT_STICKY_OOZE)
                    events.CancelEvent(EVENT_STICKY_OOZE);
                else if (action == EVENT_UNSTABLE_DESPAWN)
                {
                    me->RemoveAllAuras();
                    me->SetVisible(false);
                    events.Reset();
                    events.ScheduleEvent(EVENT_UNSTABLE_DESPAWN, 60000);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STICKY_OOZE:
                            DoCastVictim(SPELL_STICKY_OOZE);
                            events.ScheduleEvent(EVENT_STICKY_OOZE, 15000);
                            break;
                        case EVENT_UNSTABLE_DESPAWN:
                            me->Kill(me);
                            break;
                        default:
                            break;
                    }
                }

                if (me->IsVisible())
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_big_oozeAI(creature);
        }
};

class npc_precious_icc : public CreatureScript
{
    public:
        npc_precious_icc() : CreatureScript("npc_precious_icc") { }

        struct npc_precious_iccAI : public ScriptedAI
        {
            npc_precious_iccAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_INFECTED_WOUND, true); 
            }

            void Reset()
            {
                uiZombieSummonCooldown = 20000;
                events.Reset();
                events.ScheduleEvent(EVENT_DECIMATE, 35000);
                events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(3000, 7000));
                events.ScheduleEvent(EVENT_AWAKEN_PLAGUED_ZOMBIES, uiZombieSummonCooldown);
                summons.DespawnAll();
            }
            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == NPC_PLAGUED_ZOMBIE)
                {
                    summon->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true));
                    summon->CastSpell(summon,SPELL_INFECTED_WOUND,true);
                }
                summons.Summon(summon);
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
                    switch (eventId)
                    {
                        case EVENT_DECIMATE:
                            me->MonsterTextEmote(EMOTE_DECIMATE, 0, true);
                            DoCastVictim(SPELL_DECIMATE);
                            events.ScheduleEvent(EVENT_DECIMATE, 30000);
                            break;
                        case EVENT_MORTAL_WOUND:
                            DoCastVictim(SPELL_MORTAL_WOUND);
                            events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(10000, 12500));
                            break;
                        case EVENT_AWAKEN_PLAGUED_ZOMBIES:
                            uiZombieSummonCooldown -= 2000;
                            if (uiZombieSummonCooldown < 8000)
                                uiZombieSummonCooldown = 8000;
                            for (uint8 i = 0; i < RAID_MODE(5, 10, 5, 10); ++i)
                                DoCast(me, SPELL_AWAKEN_PLAGUED_ZOMBIES, true); 
                            events.ScheduleEvent(EVENT_AWAKEN_PLAGUED_ZOMBIES, uiZombieSummonCooldown);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                uint64 rotfaceGUID = instance ? instance->GetData64(GUID_ROTFACE) : 0;
                if (Creature* rotface = Unit::GetCreature(*me, rotfaceGUID))
                    if (rotface->isAlive())
                        rotface->AI()->Talk(SAY_PRECIOUS_DIES);
            }
            void JustReachedHome()
            {
                summons.DespawnAll();
            }
        private:
            EventMap events;
            InstanceScript* instance;
            uint32 uiZombieSummonCooldown;
            SummonList summons;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_precious_iccAI(creature);
        }
};

class spell_rotface_ooze_flood : public SpellScriptLoader
{
    public:
        spell_rotface_ooze_flood() : SpellScriptLoader("spell_rotface_ooze_flood") { }

        class spell_rotface_ooze_flood_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rotface_ooze_flood_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;
                std::list<Creature*> list;
                GetHitUnit()->GetCreatureListWithEntryInGrid(list, GetHitUnit()->GetEntry(), 12.5f);
                list.sort(Trinity::ObjectDistanceOrderPred(GetHitUnit()));
                GetHitUnit()->CastSpell(list.back(), uint32(GetEffectValue()), false, NULL, NULL, GetOriginalCaster() ? GetOriginalCaster()->GetGUID() : 0);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_rotface_ooze_flood_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rotface_ooze_flood_SpellScript();
        }
};

class spell_rotface_little_ooze_combine : public SpellScriptLoader
{
    public:
        spell_rotface_little_ooze_combine() : SpellScriptLoader("spell_rotface_little_ooze_combine") { }

        class spell_rotface_little_ooze_combine_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rotface_little_ooze_combine_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!(GetHitUnit() && GetHitUnit()->isAlive()))
                    return;
                if (GetHitUnit()->GetGUID() == GetCaster()->GetGUID())
                    return;

                GetCaster()->RemoveAurasDueToSpell(SPELL_LITTLE_OOZE_COMBINE);
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_LITTLE_OOZE_COMBINE);
                GetHitUnit()->CastSpell(GetCaster(), SPELL_OOZE_MERGE, true);
                Creature *rotface = 0;
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    rotface = Unit::GetCreature(*GetCaster(), instance->GetData64(GUID_ROTFACE));
                        
                if (TempSummon* summ = GetHitUnit()->ToTempSummon())
                {
                    if (rotface)
                        rotface->AI()->SummonedCreatureDespawn(summ);
                    if (GetHitUnit() && summ == GetHitUnit()->ToTempSummon())
                        summ->UnSummon();
                }
                else if (GetHitCreature())
                {
                    if (rotface)
                        rotface->AI()->SummonedCreatureDespawn(GetHitCreature());
                    if (GetHitCreature())
                        GetHitCreature()->DespawnOrUnsummon();
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_rotface_little_ooze_combine_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rotface_little_ooze_combine_SpellScript();
        }
};

class spell_rotface_large_ooze_combine : public SpellScriptLoader
{
    public:
        spell_rotface_large_ooze_combine() : SpellScriptLoader("spell_rotface_large_ooze_combine") { }

        class spell_rotface_large_ooze_combine_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rotface_large_ooze_combine_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!(GetHitCreature() && GetHitCreature()->isAlive()))
                    return;
                if (GetHitUnit()->GetGUID() == GetCaster()->GetGUID())
                    return;

                if (Aura* unstable = GetCaster()->GetAura(SPELL_UNSTABLE_OOZE))
                {
                    //Two Big Oozes merge into a Big Ooze with size one larger than the smaller of the two initial ones. Source: wowwiki.com/Rotface
                    uint8 targetAuraStack = 1;
                    if (Aura* targetAura = GetHitUnit()->GetAura(SPELL_UNSTABLE_OOZE))
                        targetAuraStack = targetAura->GetStackAmount();
                    uint8 myStack = unstable->GetStackAmount();
                    if (targetAuraStack > myStack)
                        unstable->SetStackAmount(myStack + 1);
                    else
                        unstable->SetStackAmount(targetAuraStack + 1);
                    // no idea why, but this does not trigger explosion on retail (only small+large do)
                }

                // just for safety
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_LARGE_OOZE_BUFF_COMBINE);
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_LARGE_OOZE_COMBINE);

                Creature *rotface = 0;
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    rotface = Unit::GetCreature(*GetCaster(), instance->GetData64(GUID_ROTFACE));
                        
                if (TempSummon* summ = GetHitUnit()->ToTempSummon())
                {
                    if (rotface)
                        rotface->AI()->SummonedCreatureDespawn(summ);
                    if (GetHitUnit() && summ == GetHitUnit()->ToTempSummon())
                        summ->UnSummon();
                }
                else if (GetHitCreature())
                {
                    if (rotface)
                        rotface->AI()->SummonedCreatureDespawn(GetHitCreature());
                    if (GetHitCreature())
                        GetHitCreature()->DespawnOrUnsummon();
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_rotface_large_ooze_combine_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rotface_large_ooze_combine_SpellScript();
        }
};

class spell_rotface_large_ooze_buff_combine : public SpellScriptLoader
{
    public:
        spell_rotface_large_ooze_buff_combine() : SpellScriptLoader("spell_rotface_large_ooze_buff_combine") { }

        class spell_rotface_large_ooze_buff_combine_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rotface_large_ooze_buff_combine_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!(GetHitUnit() && GetHitUnit()->isAlive()))
                    return;
                if (GetHitUnit()->GetGUID() == GetCaster()->GetGUID())
                    return;
                if (Aura* unstable = GetCaster()->GetAura(SPELL_UNSTABLE_OOZE))
                {
                    uint8 newStack = uint8(unstable->GetStackAmount()+1);
                    unstable->SetStackAmount(newStack);

                    // explode!
                    if (newStack >= 5)
                    {
                        GetCaster()->RemoveAurasDueToSpell(SPELL_LARGE_OOZE_BUFF_COMBINE);
                        GetCaster()->RemoveAurasDueToSpell(SPELL_LARGE_OOZE_COMBINE);
                        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                            if (Creature* rotface = Unit::GetCreature(*GetCaster(), instance->GetData64(GUID_ROTFACE)))
                                if (rotface->isAlive())
                                {
                                    rotface->AI()->Talk(EMOTE_UNSTABLE_EXPLOSION);
                                    rotface->AI()->Talk(SAY_UNSTABLE_EXPLOSION);
                                }

                        GetCaster()->CastSpell(GetCaster(), SPELL_UNSTABLE_OOZE_EXPLOSION, true);
                        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                            instance->SetData(DATA_OOZE_DANCE_ACHIEVEMENT, uint32(false));
                        return;
                    }
                }

                Creature *rotface = 0;
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    rotface = Unit::GetCreature(*GetCaster(), instance->GetData64(GUID_ROTFACE));

                if (TempSummon* summ = GetHitUnit()->ToTempSummon())
                {
                    if (rotface)
                        rotface->AI()->SummonedCreatureDespawn(summ);
                    if (GetHitUnit() && summ == GetHitUnit()->ToTempSummon())
                        summ->UnSummon();
                }
                else if (GetHitCreature())
                {
                    if (rotface)
                        rotface->AI()->SummonedCreatureDespawn(GetHitCreature());
                    if (GetHitCreature())
                        GetHitCreature()->DespawnOrUnsummon();
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_rotface_large_ooze_buff_combine_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rotface_large_ooze_buff_combine_SpellScript();
        }
};

class spell_rotface_unstable_ooze_explosion_init : public SpellScriptLoader
{
    public:
        spell_rotface_unstable_ooze_explosion_init() : SpellScriptLoader("spell_rotface_unstable_ooze_explosion_init") { }

        class spell_rotface_unstable_ooze_explosion_init_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rotface_unstable_ooze_explosion_init_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_UNSTABLE_OOZE_EXPLOSION_TRIGGER))
                    return false;
                return true;
            }

            void HandleCast(SpellEffIndex effIndex)
            {
                PreventHitEffect(effIndex);
                if (!GetHitUnit())
                    return;

                float x, y, z;
                GetHitUnit()->GetPosition(x, y, z);
                Creature* dummy = GetCaster()->SummonCreature(NPC_UNSTABLE_EXPLOSION_STALKER, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 60000);
                GetCaster()->CastSpell(dummy, SPELL_UNSTABLE_OOZE_EXPLOSION_TRIGGER, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_rotface_unstable_ooze_explosion_init_SpellScript::HandleCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rotface_unstable_ooze_explosion_init_SpellScript();
        }
};

class spell_rotface_unstable_ooze_explosion : public SpellScriptLoader
{
    public:
        spell_rotface_unstable_ooze_explosion() : SpellScriptLoader("spell_rotface_unstable_ooze_explosion") { }

        class spell_rotface_unstable_ooze_explosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rotface_unstable_ooze_explosion_SpellScript);

            void CheckTarget(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(EFFECT_0);
                if (!GetTargetUnit())
                    return;

                uint32 triggered_spell_id = GetSpellInfo()->EffectTriggerSpell[effIndex];

                float x, y, z;
                GetTargetUnit()->GetPosition(x, y, z);
                // let Rotface handle the cast - caster dies before this executes
                if (InstanceScript* script = GetTargetUnit()->GetInstanceScript())
                    if (Creature* rotface = script->instance->GetCreature(script->GetData64(GUID_ROTFACE)))
                        rotface->CastSpell(x, y, z, triggered_spell_id, true, NULL, NULL, GetCaster()->GetGUID(), GetTargetUnit());
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_rotface_unstable_ooze_explosion_SpellScript::CheckTarget, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rotface_unstable_ooze_explosion_SpellScript();
        }
};

class spell_rotface_unstable_ooze_explosion_suicide : public SpellScriptLoader
{
    public:
        spell_rotface_unstable_ooze_explosion_suicide() : SpellScriptLoader("spell_rotface_unstable_ooze_explosion_suicide") { }

        class spell_rotface_unstable_ooze_explosion_suicide_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rotface_unstable_ooze_explosion_suicide_AuraScript);

            void DespawnSelf(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                Unit* target = GetTarget();
                if (target->GetTypeId() != TYPEID_UNIT)
                    return;

                target->ToCreature()->AI()->DoAction(EVENT_UNSTABLE_DESPAWN);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rotface_unstable_ooze_explosion_suicide_AuraScript::DespawnSelf, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_rotface_unstable_ooze_explosion_suicide_AuraScript();
        }
};

class spell_rotface_plagued_zombie_infected_wound : public SpellScriptLoader
{
    public:
        spell_rotface_plagued_zombie_infected_wound() : SpellScriptLoader("spell_rotface_plagued_zombie_infected_wound") { }

        class spell_rotface_plagued_zombie_infected_wound_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rotface_plagued_zombie_infected_wound_SpellScript);

            bool Load()
            {
                prevented = false;
                return true;
            }

            void EnsureAuraStack()
            {
                if (!(GetHitUnit() && GetHitUnit()->isAlive()))
                    return;
                if (GetHitUnit()->GetGUID() == GetCaster()->GetGUID())
                    return;

                if (Unit *who = GetHitUnit())
                {
                    uint32 curSpellId = GetSpellInfo()->Id;
                    if (Aura* oldAura = who->GetAura(curSpellId))
                    {
                        prevented = true;
                        prevStackAmount = oldAura->GetStackAmount();
                    }
                }
            }

            void RemoveImmunity()
            {
                if (Unit* target = GetHitUnit())
                {
                    if (prevented)
                    {
                        if (Aura* oldAura = GetHitUnit()->GetAura(GetSpellInfo()->Id))
                        {
                            oldAura->SetStackAmount(prevStackAmount+1);
                            oldAura->RefreshDuration();
                        }
                    }
                }
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_rotface_plagued_zombie_infected_wound_SpellScript::EnsureAuraStack);
                AfterHit += SpellHitFn(spell_rotface_plagued_zombie_infected_wound_SpellScript::RemoveImmunity);
            }
        private:
            bool prevented;
            uint8 prevStackAmount;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rotface_plagued_zombie_infected_wound_SpellScript();
        }
};

void AddSC_boss_rotface()
{
    new boss_rotface();
    new npc_little_ooze();
    new npc_big_ooze();
    new npc_precious_icc();
    new spell_rotface_ooze_flood();
    new spell_rotface_little_ooze_combine();
    new spell_rotface_large_ooze_combine();
    new spell_rotface_large_ooze_buff_combine();
    new spell_rotface_unstable_ooze_explosion_init();
    new spell_rotface_unstable_ooze_explosion();
    new spell_rotface_unstable_ooze_explosion_suicide();
    new spell_rotface_plagued_zombie_infected_wound();
} 