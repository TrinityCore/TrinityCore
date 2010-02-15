/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* Script Data Start
SDName: Boss ichoron
SDAuthor: ckegg
SD%Complete: 80%
SDComment: TODO: better spawn location for adds
SDCategory:
Script Data End */

#include "ScriptedPch.h"
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
    {1840.64, 795.407, 44.079, 1.676},
    {1886.24, 757.733, 47.750, 5.201},
    {1877.91, 845.915, 43.417, 3.560},
    {1918.97, 850.645, 47.225, 4.136},
    {1935.50, 796.224, 52.492, 4.224},
};

struct boss_ichoronAI : public ScriptedAI
{
    boss_ichoronAI(Creature* pCreature) : ScriptedAI(pCreature), m_waterElements(pCreature)
    {
        pInstance  = pCreature->GetInstanceData();
    }

    bool bIsExploded;
    bool bIsFrenzy;
    bool bAchievement;

    uint32 uiBubbleCheckerTimer;
    uint32 uiWaterBoltVolleyTimer;

    ScriptedInstance* pInstance;

    SummonList m_waterElements;

    void Reset()
    {
        bIsExploded = false;
        bIsFrenzy = false;
        bAchievement = true;
        uiBubbleCheckerTimer = 1000;
        uiWaterBoltVolleyTimer = urand(10000, 15000);

        m_creature->SetVisibility(VISIBILITY_ON);
        DespawnWaterElements();

        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        DoCast(m_creature, SPELL_PROTECTIVE_BUBBLE);

        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }
    }

    void AttackStart(Unit* pWho)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(pWho, true))
        {
            m_creature->AddThreat(pWho, 0.0f);
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);
            DoStartMovement(pWho);
        }
    }

    void DoAction(const int32 param)
    {
        if (!m_creature->isAlive())
            return;

        switch(param)
        {
            case ACTION_WATER_ELEMENT_HIT:
                m_creature->SetHealth(m_creature->GetHealth() + m_creature->GetMaxHealth() * 0.01);

                if (bIsExploded)
                    DoExplodeCompleted();

                bAchievement = false;
                break;
            case ACTION_WATER_ELEMENT_KILLED:
                uint32 damage = (m_creature->GetMaxHealth()*3)/100;
                m_creature->SetHealth(m_creature->GetHealth() - damage);
                m_creature->LowerPlayerDamageReq(damage);
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
            DoScriptText(SAY_BUBBLE, m_creature);
            DoCast(m_creature, SPELL_PROTECTIVE_BUBBLE, true);
        }

        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
    }

    void MoveInLineOfSight(Unit* pWho) {}

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!bIsFrenzy && HealthBelowPct(25) && !bIsExploded)
        {
            DoScriptText(SAY_ENRAGE, m_creature);
            DoCast(m_creature, DUNGEON_MODE(SPELL_FRENZY, SPELL_FRENZY_H), true);
            bIsFrenzy = true;
        }

        if (!bIsFrenzy)
        {
            if (uiBubbleCheckerTimer <= uiDiff)
            {
                if (!bIsExploded)
                {
                    if (!m_creature->HasAura(SPELL_PROTECTIVE_BUBBLE, 0))
                    {
                        DoScriptText(SAY_SHATTER, m_creature);
                        DoCast(m_creature, DUNGEON_MODE(SPELL_WATER_BLAST, SPELL_WATER_BLAST_H));
                        DoCast(m_creature, SPELL_DRAINED);
                        bIsExploded = true;
                        m_creature->AttackStop();
                        m_creature->SetVisibility(VISIBILITY_OFF);
                        for(uint8 i = 0; i < 10; i++)
                        {
                            int tmp = urand(0, MAX_SPAWN_LOC-1);
                            m_creature->SummonCreature(NPC_ICHOR_GLOBULE, SpawnLoc[tmp], TEMPSUMMON_CORPSE_DESPAWN);
                        }
                    }
                }
                else
                {
                    bool bIsWaterElementsAlive = false;
                    if (!m_waterElements.empty())
                    {
                        for (std::list<uint64>::iterator itr = m_waterElements.begin(); itr != m_waterElements.end(); ++itr)
                            if (Creature* pTemp = Unit::GetCreature(*m_creature, *itr))
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
                DoCast(m_creature, DUNGEON_MODE(SPELL_WATER_BOLT_VOLLEY, SPELL_WATER_BOLT_VOLLEY_H));
                uiWaterBoltVolleyTimer = urand(10000, 15000);
            }
            else uiWaterBoltVolleyTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (bIsExploded)
        {
            bIsExploded = false;
            m_creature->SetVisibility(VISIBILITY_ON);
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
        pSummoned->SetSpeed(MOVE_RUN, 0.3f);
        pSummoned->GetMotionMaster()->MoveFollow(m_creature, 0, 0);
        m_waterElements.push_back(pSummoned->GetGUID());
    }


    void SummonedCreatureDespawn(Creature *pSummoned) 
    {
        m_waterElements.remove(pSummoned->GetGUID());
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_ichoron(Creature* pCreature)
{
    return new boss_ichoronAI (pCreature);
}

struct mob_ichor_globuleAI : public ScriptedAI
{
    mob_ichor_globuleAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
    	pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 uiRangeCheck_Timer;

    void Reset()
    {
        uiRangeCheck_Timer = 1000;
    }

    void AttackStart(Unit* pWho)
    {
        return;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (uiRangeCheck_Timer < uiDiff)
        {
            if (pInstance)
            {
                if (Creature* pIchoron = ((Creature*)Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_ICHORON))))
                {
                    if (m_creature->IsWithinDist(pIchoron, 2.0f , false))
                    {
                        if (pIchoron->AI())
                            pIchoron->AI()->DoAction(ACTION_WATER_ELEMENT_HIT);
                        m_creature->ForcedDespawn();
                    }
                }
            }
            uiRangeCheck_Timer = 1000;
        }
        else uiRangeCheck_Timer -= uiDiff;
    }

    void JustDied(Unit* pKiller)
    {
        DoCast(m_creature, SPELL_SPLASH);
        if (Creature* pIchoron = ((Creature*)Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_ICHORON))))
            if (pIchoron->AI())
                pIchoron->AI()->DoAction(ACTION_WATER_ELEMENT_KILLED);
    }
};

CreatureAI* GetAI_mob_ichor_globule(Creature* pCreature)
{
    return new mob_ichor_globuleAI (pCreature);
}

void AddSC_boss_ichoron()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_ichoron";
    newscript->GetAI = &GetAI_boss_ichoron;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ichor_globule";
    newscript->GetAI = &GetAI_mob_ichor_globule;
    newscript->RegisterSelf();
}
