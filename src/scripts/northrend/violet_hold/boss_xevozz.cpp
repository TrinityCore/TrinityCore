/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* Script Data Start
SDName: Boss xevozz
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include "ScriptedPch.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_ARCANE_BARRAGE_VOLLEY               = 54202,
    SPELL_ARCANE_BARRAGE_VOLLEY_H             = 59483,
    SPELL_ARCANE_BUFFET                       = 54226,
    SPELL_ARCANE_BUFFET_H                     = 59485,
    SPELL_SUMMON_ETHEREAL_SPHERE_1            = 54102,
    SPELL_SUMMON_ETHEREAL_SPHERE_2            = 54137,
    SPELL_SUMMON_ETHEREAL_SPHERE_3            = 54138,
};

enum NPCs
{
    NPC_ETHEREAL_SPHERE                       = 29271,
    //NPC_ETHEREAL_SPHERE2                    = 32582, // heroic only?
};

enum CreatureSpells
{
    SPELL_ARCANE_POWER                             = 54160,
    H_SPELL_ARCANE_POWER                           = 59474,
    SPELL_SUMMON_PLAYERS                           = 54164,
    SPELL_POWER_BALL_VISUAL                        = 54141,
};

//not in db
enum Yells
{
    SAY_AGGRO                                   = -1608027,
    SAY_SLAY_1                                  = -1608028,
    SAY_SLAY_2                                  = -1608029,
    SAY_SLAY_3                                  = -1608030,
    SAY_DEATH                                   = -1608031,
    SAY_SPAWN                                   = -1608032,
    SAY_CHARGED                                 = -1608033,
    SAY_REPEAT_SUMMON_1                         = -1608034,
    SAY_REPEAT_SUMMON_2                         = -1608035,
    SAY_SUMMON_ENERGY                           = -1608036
};

struct TRINITY_DLL_DECL boss_xevozzAI : public ScriptedAI
{
    boss_xevozzAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance  = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 uiSummonEtherealSphere_Timer;
    uint32 uiArcaneBarrageVolley_Timer;
    uint32 uiArcaneBuffet_Timer;

    void Reset()
    {
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }

        uiSummonEtherealSphere_Timer = urand(10000, 12000);
        uiArcaneBarrageVolley_Timer = urand(20000, 22000);
        uiArcaneBuffet_Timer = uiSummonEtherealSphere_Timer + urand(5000, 6000);
        DespawnSphere();
    }

    void DespawnSphere()
    {
        std::list<Creature*> assistList;
        GetCreatureListWithEntryInGrid(assistList,m_creature, NPC_ETHEREAL_SPHERE ,150.0f);

        if (assistList.empty())
            return;

        for(std::list<Creature*>::iterator iter = assistList.begin(); iter != assistList.end(); ++iter)
        {
            if (Creature* pSphere = *iter)
                pSphere->Kill(pSphere, false);
        }
    }

    void JustSummoned(Creature* pSummoned)
    {
        pSummoned->SetSpeed(MOVE_RUN, 0.5f);
        if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
        {
            pSummoned->AddThreat(pTarget, 0.00f);
            pSummoned->AI()->AttackStart(pTarget);
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

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }
    }

    void MoveInLineOfSight(Unit* pWho) {}

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiArcaneBarrageVolley_Timer < uiDiff)
        {
            DoCast(m_creature, DUNGEON_MODE(SPELL_ARCANE_BARRAGE_VOLLEY, SPELL_ARCANE_BARRAGE_VOLLEY_H));
            uiArcaneBarrageVolley_Timer = urand(20000, 22000);
        }
        else uiArcaneBarrageVolley_Timer -= uiDiff;

        if (uiArcaneBuffet_Timer)
            if (uiArcaneBuffet_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_ARCANE_BUFFET, SPELL_ARCANE_BUFFET_H));
                uiArcaneBuffet_Timer = 0;
            }
            else uiArcaneBuffet_Timer -= uiDiff;

        if (uiSummonEtherealSphere_Timer < uiDiff)
        {
            DoScriptText(SAY_SPAWN, m_creature);
            DoCast(m_creature, SPELL_SUMMON_ETHEREAL_SPHERE_1);
            if (IsHeroic()) // extra one for heroic
                m_creature->SummonCreature(NPC_ETHEREAL_SPHERE, m_creature->GetPositionX()-5+rand()%10, m_creature->GetPositionY()-5+rand()%10, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 40000);

            uiSummonEtherealSphere_Timer = urand(45000, 47000);
            uiArcaneBuffet_Timer = urand(5000, 6000);
        }
        else uiSummonEtherealSphere_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        DoScriptText(SAY_DEATH, m_creature);

        DespawnSphere();

        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
            {
                pInstance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                pInstance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
            {
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
                pInstance->SetData(DATA_WAVE_COUNT, 13);
            }
        }
    }
    void KilledUnit(Unit* pVictim)
    {
        if (pVictim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_xevozz(Creature* pCreature)
{
    return new boss_xevozzAI (pCreature);
}

struct TRINITY_DLL_DECL mob_ethereal_sphereAI : public ScriptedAI
{
    mob_ethereal_sphereAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
    	pInstance   = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 uiSummonPlayers_Timer;
    uint32 uiRangeCheck_Timer;

    void Reset()
    {
        uiSummonPlayers_Timer = urand(33000, 35000);
        uiRangeCheck_Timer = 1000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!m_creature->HasAura(SPELL_POWER_BALL_VISUAL))
            DoCast(m_creature, SPELL_POWER_BALL_VISUAL);

        if (uiRangeCheck_Timer < uiDiff)
        {
            if (pInstance)
            {
                if (Creature* pXevozz = ((Creature*)Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_XEVOZZ))))
                {
                    float fDistance = m_creature->GetDistance2d(pXevozz);
                    if (fDistance <= 3)
                        DoCast(pXevozz, DUNGEON_MODE(SPELL_ARCANE_POWER, H_SPELL_ARCANE_POWER));
                    else
                        DoCast(m_creature, 35845); //Is it blizzlike?
                }
            }
            uiRangeCheck_Timer = 1000;
        }
        else uiRangeCheck_Timer -= uiDiff;

        if (uiSummonPlayers_Timer < uiDiff)
        {
            DoCast(m_creature, SPELL_SUMMON_PLAYERS); // not working right

            Map* pMap = m_creature->GetMap();
            if (pMap && pMap->IsDungeon())
            {
                Map::PlayerList const &PlayerList = pMap->GetPlayers();

                if (!PlayerList.isEmpty())
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        if (i->getSource()->isAlive())
                            DoTeleportPlayer(i->getSource(), m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), i->getSource()->GetOrientation());
            }

            uiSummonPlayers_Timer = urand(33000, 35000);
        }
        else uiSummonPlayers_Timer -= uiDiff;
    }
};

CreatureAI* GetAI_mob_ethereal_sphere(Creature* pCreature)
{
    return new mob_ethereal_sphereAI (pCreature);
}

void AddSC_boss_xevozz()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_xevozz";
    newscript->GetAI = &GetAI_boss_xevozz;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ethereal_sphere";
    newscript->GetAI = &GetAI_mob_ethereal_sphere;
    newscript->RegisterSelf();
}
