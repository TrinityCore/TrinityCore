/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "violet_hold.h"

enum Spells
{
    SPELL_DRAINED                               = 59820,
    SPELL_FRENZY                                = 54312,
    SPELL_FRENZY_H                              = 59522,
    SPELL_PROTECTIVE_BUBBLE                     = 54306,
    SPELL_WATER_BLAST                           = 54237,
    SPELL_WATER_BLAST_H                         = 59520,
    SPELL_WATER_BOLT_VOLLEY                     = 54241,
    SPELL_WATER_BOLT_VOLLEY_H                   = 59521,
    SPELL_SPLASH                                = 59516,
    SPELL_WATER_GLOBULE                         = 54268
};

enum IchoronCreatures
{
    NPC_ICHOR_GLOBULE                           = 29321,
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_ENRAGE                                  = 4,
    SAY_SHATTER                                 = 5,
    SAY_BUBBLE                                  = 6
};

enum Actions
{
    ACTION_WATER_ELEMENT_HIT                    = 1,
    ACTION_WATER_ELEMENT_KILLED                 = 2,
};

/// @todo get those positions from spawn of creature 29326
#define MAX_SPAWN_LOC 5
static Position SpawnLoc[MAX_SPAWN_LOC]=
{
    {1840.64f, 795.407f, 44.079f, 1.676f},
    {1886.24f, 757.733f, 47.750f, 5.201f},
    {1877.91f, 845.915f, 43.417f, 3.560f},
    {1918.97f, 850.645f, 47.225f, 4.136f},
    {1935.50f, 796.224f, 52.492f, 4.224f},
};

enum Misc
{
    DATA_DEHYDRATION                            = 1
};

class boss_ichoron : public CreatureScript
{
public:
    boss_ichoron() : CreatureScript("boss_ichoron") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_ichoronAI>(creature);
    }

    struct boss_ichoronAI : public ScriptedAI
    {
        boss_ichoronAI(Creature* creature) : ScriptedAI(creature), m_waterElements(creature)
        {
            Initialize();
            instance  = creature->GetInstanceScript();
        }

        void Initialize()
        {
            bIsExploded = false;
            bIsFrenzy = false;
            dehydration = true;
            uiBubbleCheckerTimer = 1000;
            uiWaterBoltVolleyTimer = urand(10000, 15000);
        }

        bool bIsExploded;
        bool bIsFrenzy;
        bool dehydration;

        uint32 uiBubbleCheckerTimer;
        uint32 uiWaterBoltVolleyTimer;

        InstanceScript* instance;

        SummonList m_waterElements;

        void Reset() override
        {
            Initialize();

            me->SetVisible(true);
            DespawnWaterElements();

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            DoCast(me, SPELL_PROTECTIVE_BUBBLE);

            if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetData64(DATA_ICHORON_CELL)))
                if (pDoor->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }

        void AttackStart(Unit* who) override
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void DoAction(int32 param) override
        {
            if (!me->IsAlive())
                return;

            switch (param)
            {
                case ACTION_WATER_ELEMENT_HIT:
                    me->ModifyHealth(int32(me->CountPctFromMaxHealth(1)));

                    if (bIsExploded)
                        DoExplodeCompleted();

                    dehydration = false;
                    break;
                case ACTION_WATER_ELEMENT_KILLED:
                    uint32 damage = me->CountPctFromMaxHealth(3);
                    me->ModifyHealth(-int32(damage));
                    me->LowerPlayerDamageReq(damage);
                    break;
            }
        }

        void DespawnWaterElements()
        {
            m_waterElements.DespawnAll();
        }

        // call when explode shall stop.
        // either when "hit" by a bubble, or when there is no bubble left.
        void DoExplodeCompleted()
        {
            bIsExploded = false;

            if (!HealthBelowPct(25))
            {
                Talk(SAY_BUBBLE);
                DoCast(me, SPELL_PROTECTIVE_BUBBLE, true);
            }

            me->SetVisible(true);
            me->GetMotionMaster()->MoveChase(me->GetVictim());
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_DEHYDRATION)
                return dehydration ? 1 : 0;

            return 0;
        }

        void MoveInLineOfSight(Unit* /*who*/) override { }


        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (!bIsFrenzy && HealthBelowPct(25) && !bIsExploded)
            {
                Talk(SAY_ENRAGE);
                DoCast(me, SPELL_FRENZY, true);
                bIsFrenzy = true;
            }

            if (!bIsFrenzy)
            {
                if (uiBubbleCheckerTimer <= uiDiff)
                {
                    if (!bIsExploded)
                    {
                        if (!me->HasAura(SPELL_PROTECTIVE_BUBBLE, 0))
                        {
                            Talk(SAY_SHATTER);
                            DoCast(me, SPELL_WATER_BLAST);
                            DoCast(me, SPELL_DRAINED);
                            bIsExploded = true;
                            me->AttackStop();
                            me->SetVisible(false);
                            for (uint8 i = 0; i < 10; i++)
                            {
                                int tmp = urand(0, MAX_SPAWN_LOC-1);
                                me->SummonCreature(NPC_ICHOR_GLOBULE, SpawnLoc[tmp], TEMPSUMMON_CORPSE_DESPAWN);
                            }
                        }
                    }
                    else
                    {
                        bool bIsWaterElementsAlive = false;
                        if (!m_waterElements.empty())
                        {
                            for (std::list<uint64>::const_iterator itr = m_waterElements.begin(); itr != m_waterElements.end(); ++itr)
                                if (Creature* temp = ObjectAccessor::GetCreature(*me, *itr))
                                    if (temp->IsAlive())
                                    {
                                        bIsWaterElementsAlive = true;
                                        break;
                                    }
                        }

                        if (!bIsWaterElementsAlive)
                            DoExplodeCompleted();
                    }
                    uiBubbleCheckerTimer = 1000;
                }
                else uiBubbleCheckerTimer -= uiDiff;
            }

            if (!bIsExploded)
            {
                if (uiWaterBoltVolleyTimer <= uiDiff)
                {
                    DoCast(me, SPELL_WATER_BOLT_VOLLEY);
                    uiWaterBoltVolleyTimer = urand(10000, 15000);
                }
                else uiWaterBoltVolleyTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            if (bIsExploded)
            {
                bIsExploded = false;
                me->SetVisible(true);
            }

            DespawnWaterElements();

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
            {
                instance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
            {
                instance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 13);
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned)
            {
                summoned->SetSpeed(MOVE_RUN, 0.3f);
                summoned->GetMotionMaster()->MoveFollow(me, 0, 0);
                m_waterElements.Summon(summoned);
                instance->SetData64(DATA_ADD_TRASH_MOB, summoned->GetGUID());
            }
        }

        void SummonedCreatureDespawn(Creature* summoned) override
        {
            if (summoned)
            {
                m_waterElements.Despawn(summoned);
                instance->SetData64(DATA_DEL_TRASH_MOB, summoned->GetGUID());
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }
    };

};

class npc_ichor_globule : public CreatureScript
{
public:
    npc_ichor_globule() : CreatureScript("npc_ichor_globule") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_ichor_globuleAI>(creature);
    }

    struct npc_ichor_globuleAI : public ScriptedAI
    {
        npc_ichor_globuleAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiRangeCheck_Timer = 1000;
        }

        InstanceScript* instance;

        uint32 uiRangeCheck_Timer;

        void Reset() override
        {
            Initialize();
            DoCast(me, SPELL_WATER_GLOBULE);
        }

        void AttackStart(Unit* /*who*/) override
        {
            return;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (uiRangeCheck_Timer < uiDiff)
            {
                if (Creature* pIchoron = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ICHORON)))
                {
                    if (me->IsWithinDist(pIchoron, 2.0f, false))
                    {
                        if (pIchoron->AI())
                            pIchoron->AI()->DoAction(ACTION_WATER_ELEMENT_HIT);
                        me->DespawnOrUnsummon();
                    }
                }
                uiRangeCheck_Timer = 1000;
            }
            else uiRangeCheck_Timer -= uiDiff;
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCast(me, SPELL_SPLASH);
            if (Creature* pIchoron = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ICHORON)))
                if (pIchoron->AI())
                    pIchoron->AI()->DoAction(ACTION_WATER_ELEMENT_KILLED);
        }
    };

};

class achievement_dehydration : public AchievementCriteriaScript
{
    public:
        achievement_dehydration() : AchievementCriteriaScript("achievement_dehydration")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Ichoron = target->ToCreature())
                if (Ichoron->AI()->GetData(DATA_DEHYDRATION))
                    return true;

            return false;
        }
};

void AddSC_boss_ichoron()
{
    new boss_ichoron();
    new npc_ichor_globule();
    new achievement_dehydration();
}
