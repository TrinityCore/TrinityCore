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
    SAY_AGGRO                                   = -1608018,
    SAY_SLAY_1                                  = -1608019,
    SAY_SLAY_2                                  = -1608020,
    SAY_SLAY_3                                  = -1608021,
    SAY_DEATH                                   = -1608022,
    SAY_SPAWN                                   = -1608023,
    SAY_ENRAGE                                  = -1608024,
    SAY_SHATTER                                 = -1608025,
    SAY_BUBBLE                                  = -1608026
};

enum Achievements
{
    ACHIEVEMENT_DEHYDRATION                     = 2041,
};

enum Actions
{
    ACTION_WATER_ELEMENT_HIT                    = 1,
    ACTION_WATER_ELEMENT_KILLED                 = 2,
};

// TODO get those positions from spawn of creature 29326
#define MAX_SPAWN_LOC 5
static Position SpawnLoc[MAX_SPAWN_LOC]=
{
    {1840.64f, 795.407f, 44.079f, 1.676f},
    {1886.24f, 757.733f, 47.750f, 5.201f},
    {1877.91f, 845.915f, 43.417f, 3.560f},
    {1918.97f, 850.645f, 47.225f, 4.136f},
    {1935.50f, 796.224f, 52.492f, 4.224f},
};

class boss_ichoron : public CreatureScript
{
public:
    boss_ichoron() : CreatureScript("boss_ichoron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ichoronAI (pCreature);
    }

    struct boss_ichoronAI : public ScriptedAI
    {
        boss_ichoronAI(Creature* pCreature) : ScriptedAI(pCreature), m_waterElements(pCreature)
        {
            pInstance  = pCreature->GetInstanceScript();
        }

        bool bIsExploded;
        bool bIsFrenzy;
        bool bAchievement;

        uint32 uiBubbleCheckerTimer;
        uint32 uiWaterBoltVolleyTimer;

        InstanceScript* pInstance;

        SummonList m_waterElements;

        void Reset()
        {
            bIsExploded = false;
            bIsFrenzy = false;
            bAchievement = true;
            uiBubbleCheckerTimer = 1000;
            uiWaterBoltVolleyTimer = urand(10000, 15000);

            me->SetVisible(true);
            DespawnWaterElements();

            if (pInstance)
            {
                if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                    pInstance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
                else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                    pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_AGGRO, me);

            DoCast(me, SPELL_PROTECTIVE_BUBBLE);

            if (pInstance)
            {
                if (GameObject *pDoor = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_ICHORON_CELL)))
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }
                if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                    pInstance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
                else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                    pInstance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
            }
        }

        void AttackStart(Unit* pWho)
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(pWho, true))
            {
                me->AddThreat(pWho, 0.0f);
                me->SetInCombatWith(pWho);
                pWho->SetInCombatWith(me);
                DoStartMovement(pWho);
            }
        }

        void DoAction(const int32 param)
        {
            if (!me->isAlive())
                return;

            switch(param)
            {
                case ACTION_WATER_ELEMENT_HIT:
                    me->ModifyHealth(int32(me->CountPctFromMaxHealth(1)));

                    if (bIsExploded)
                        DoExplodeCompleted();

                    bAchievement = false;
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
                DoScriptText(SAY_BUBBLE, me);
                DoCast(me, SPELL_PROTECTIVE_BUBBLE, true);
            }

            me->SetVisible(true);
            me->GetMotionMaster()->MoveChase(me->getVictim());
        }

        void MoveInLineOfSight(Unit* /*pWho*/) {}

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (!bIsFrenzy && HealthBelowPct(25) && !bIsExploded)
            {
                DoScriptText(SAY_ENRAGE, me);
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
                            DoScriptText(SAY_SHATTER, me);
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
                                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                                    if (pTemp->isAlive())
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

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (bIsExploded)
            {
                bIsExploded = false;
                me->SetVisible(true);
            }

            DespawnWaterElements();

            if (pInstance)
            {
                if (IsHeroic() && bAchievement)
                    pInstance->DoCompleteAchievement(ACHIEVEMENT_DEHYDRATION);

                if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                {
                    pInstance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                    pInstance->SetData(DATA_WAVE_COUNT, 7);
                }
                else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                {
                    pInstance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                    pInstance->SetData(DATA_WAVE_COUNT, 13);
                }
            }
        }

        void JustSummoned(Creature* pSummoned)
        {
            if (pSummoned)
            {
                pSummoned->SetSpeed(MOVE_RUN, 0.3f);
                pSummoned->GetMotionMaster()->MoveFollow(me, 0, 0);
                m_waterElements.push_back(pSummoned->GetGUID());
                pInstance->SetData64(DATA_ADD_TRASH_MOB,pSummoned->GetGUID());
            }
        }

        void SummonedCreatureDespawn(Creature *pSummoned)
        {
            if (pSummoned)
            {
                m_waterElements.remove(pSummoned->GetGUID());
                pInstance->SetData64(DATA_DEL_TRASH_MOB,pSummoned->GetGUID());
            }
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;
            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
        }
    };

};

class mob_ichor_globule : public CreatureScript
{
public:
    mob_ichor_globule() : CreatureScript("mob_ichor_globule") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_ichor_globuleAI (pCreature);
    }

    struct mob_ichor_globuleAI : public ScriptedAI
    {
        mob_ichor_globuleAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 uiRangeCheck_Timer;

        void Reset()
        {
            uiRangeCheck_Timer = 1000;
            DoCast(me,SPELL_WATER_GLOBULE);
        }

        void AttackStart(Unit* /*pWho*/)
        {
            return;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiRangeCheck_Timer < uiDiff)
            {
                if (pInstance)
                {
                    if (Creature* pIchoron = Unit::GetCreature(*me, pInstance->GetData64(DATA_ICHORON)))
                    {
                        if (me->IsWithinDist(pIchoron, 2.0f , false))
                        {
                            if (pIchoron->AI())
                                pIchoron->AI()->DoAction(ACTION_WATER_ELEMENT_HIT);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
                uiRangeCheck_Timer = 1000;
            }
            else uiRangeCheck_Timer -= uiDiff;
        }

        void JustDied(Unit* /*pKiller*/)
        {
            DoCast(me, SPELL_SPLASH);
            if (Creature* pIchoron = Unit::GetCreature(*me, pInstance->GetData64(DATA_ICHORON)))
                if (pIchoron->AI())
                    pIchoron->AI()->DoAction(ACTION_WATER_ELEMENT_KILLED);
        }
    };

};

void AddSC_boss_ichoron()
{
    new boss_ichoron();
    new mob_ichor_globule();
}
