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
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include "precompiled.h"
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

//not in db
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

struct Locations
{
    float x, y, z;
    uint32 id;
};

static Locations PortalLoc[]=
{
    {1857.125, 763.295, 38.654},
    {1925.480, 849.981, 47.174},
    {1892.737, 744.589, 47.666},
    {1878.198, 850.005, 43.333},
    {1909.381, 806.796, 38.645},
    {1936.101, 802.950, 52.417},
};

struct TRINITY_DLL_DECL boss_ichoronAI : public ScriptedAI
{
    boss_ichoronAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance  = pCreature->GetInstanceData();
    }

    bool bIsExploded;
    bool bIsFrenzy;

    uint32 uiBuubleChecker_Timer;
    uint32 uiWaterBoltVolley_Timer;
    uint32 uiShowup_Counter;

    ScriptedInstance* pInstance;

    std::list<uint64> m_lWaterElementsGUIDList;

    void Reset()
    {
        bIsExploded = false;
        bIsFrenzy = false;
        uiBuubleChecker_Timer = 1000;
        uiWaterBoltVolley_Timer = urand(10000, 15000);
        uiShowup_Counter = 0;

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

    void WaterElementHit()
    {
        m_creature->SetHealth(m_creature->GetHealth() + m_creature->GetMaxHealth() * 0.01);
        if (bIsExploded)
        {
            DoCast(m_creature, SPELL_PROTECTIVE_BUBBLE);
            bIsExploded = false;
            m_creature->SetVisibility(VISIBILITY_ON);
            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
        }
    }

    void DespawnWaterElements()
    {
        if (m_lWaterElementsGUIDList.empty())
            return;

        for(std::list<uint64>::iterator itr = m_lWaterElementsGUIDList.begin(); itr != m_lWaterElementsGUIDList.end(); ++itr)
        {
            if (Creature* pTemp = (Creature*)Unit::GetUnit(*m_creature, *itr))
            {
                if (pTemp->isAlive())
                    pTemp->Kill(pTemp, false);
            }
        }
        m_lWaterElementsGUIDList.clear();
    }

    void MoveInLineOfSight(Unit* pWho) {}

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!bIsFrenzy)
        {
            if (uiBuubleChecker_Timer < uiDiff)
            {
                if (!bIsExploded)
                {
                    if (!m_creature->HasAura(SPELL_PROTECTIVE_BUBBLE, 0))
                    {
                        DoCast(m_creature, DUNGEON_MODE(SPELL_WATER_BLAST, SPELL_WATER_BLAST_H));
                        //DoCast(m_creature, SPELL_DRAINED);
                        bIsExploded = true;
                        uiShowup_Counter = 0;
                        m_creature->AttackStop();
                        m_creature->SetVisibility(VISIBILITY_OFF);
                        for(uint8 i = 0; i < 10; i++)
                        {
                            //int tmp = urand(0, 5);
                            //m_creature->SummonCreature(NPC_ICHOR_GLOBULE, PortalLoc[tmp].x, PortalLoc[tmp].y, PortalLoc[tmp].z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                            m_creature->SummonCreature(NPC_ICHOR_GLOBULE, m_creature->GetPositionX()-10+rand()%20, m_creature->GetPositionY()-10+rand()%20, m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        }
                    }
                    uiBuubleChecker_Timer = 3000;
                }
                else
                {
                    bool bIsWaterElementsAlive = false;
                    ++uiShowup_Counter;
                    if (!m_lWaterElementsGUIDList.empty())
                    {
                        for(std::list<uint64>::iterator itr = m_lWaterElementsGUIDList.begin(); itr != m_lWaterElementsGUIDList.end(); ++itr)
                            if (Creature* pTemp = (Creature*)Unit::GetUnit(*m_creature, *itr))
                                if (pTemp->isAlive())
                                    bIsWaterElementsAlive = true;
                    }
                    if (!bIsWaterElementsAlive || uiShowup_Counter > 20)
                    {
                        DoCast(m_creature, SPELL_PROTECTIVE_BUBBLE);
                        bIsExploded = false;
                        uiShowup_Counter = 0;
                        m_creature->SetVisibility(VISIBILITY_ON);
                        m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                    }
                    uiBuubleChecker_Timer = 1000;
                }
            }
            else uiBuubleChecker_Timer -= uiDiff;
        }

        if (!bIsExploded)
        {
            if (uiWaterBoltVolley_Timer < uiDiff)
            {
                DoCast(m_creature, DUNGEON_MODE(SPELL_WATER_BOLT_VOLLEY, SPELL_WATER_BOLT_VOLLEY_H));
                uiWaterBoltVolley_Timer = urand(10000, 15000);
            }
            else uiWaterBoltVolley_Timer -= uiDiff;

            if (!bIsFrenzy && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25)
            {
                DoCast(m_creature, DUNGEON_MODE(SPELL_FRENZY, SPELL_FRENZY_H));
                bIsFrenzy = true;
            }

        DoMeleeAttackIfReady();
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        DespawnWaterElements();

        if (pInstance)
        {
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
        pSummoned->SetSpeed(MOVE_RUN, 0.2f);
        pSummoned->GetMotionMaster()->MoveFollow(m_creature, 0, 0);
        m_lWaterElementsGUIDList.push_back(pSummoned->GetGUID());
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

struct TRINITY_DLL_DECL mob_ichor_globuleAI : public ScriptedAI
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
                    //maybe 12.0f is not offlike, maybe 2.00f ?
                    float fDistance = m_creature->GetDistance(pIchoron);
                    if (m_creature->IsWithinDist(pIchoron, fDistance <= 12.0f , false))
                    {
                        ((boss_ichoronAI*)pIchoron->AI())->WaterElementHit();
                        m_creature->Kill(m_creature, false);
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
