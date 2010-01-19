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

/* ScriptData
SDName: Boss_Moam
SD%Complete: 90
SDComment: TODO: Adjust timer, correct Stone phase buff
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "ScriptedPch.h"
#include "ruins_of_ahnqiraj.h"

enum Emotes
{
    EMOTE_AGGRO             = -1509000,
    EMOTE_MANA_FULL         = -1509001
};

enum Spells
{
    SPELL_TRAMPLE           = 15550,
    SPELL_DRAINMANA         = 27256,    //Doesn't exist ?
    SPELL_ARCANEERUPTION    = 25672,
    SPELL_SUMMONMANA        = 25681,    //Summon Mana fiend. It only summons one so exec it three times
    SPELL_GRDRSLEEP         = 24360     //Greater Dreamless Sleep
};

enum Creatures
{
    CREATURE_MANA_FIEND     = 15527
};

enum CombatPhase
{
    NORMAL,
    STONE
};

struct TRINITY_DLL_DECL boss_moamAI : public ScriptedAI
{
    boss_moamAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    uint32 uiTrampleTimer;
    uint32 uiDrainManaTimer;
    uint32 uiPhaseTimer;
    CombatPhase Phase;
    
    ScriptedInstance *pInstance;

    void Reset()
    {
        uiTrampleTimer = urand(3000,7000);
        uiDrainManaTimer = urand(3000,7000);
        uiPhaseTimer = 90000;
        Phase = NORMAL;
        m_creature->SetPower(POWER_MANA,0);
        
        if (pInstance)
            pInstance->SetData(DATA_MOAM_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(EMOTE_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_MOAM_EVENT, IN_PROGRESS);
    }
    
    void JustDied(Unit *killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_MOAM_EVENT, DONE);
    }
    
    void DrainMana()
    {
        for (uint8 i=0;i<6;++i)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            {
                pTarget->ModifyPower(POWER_MANA, -500);
                m_creature->ModifyPower(POWER_MANA, 1000);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (Phase == NORMAL)
        {
            if (!UpdateVictim())
                return;
            
            //If we are 100%MANA cast Arcane Erruption
            if (m_creature->GetPower(POWER_MANA) == m_creature->GetMaxPower(POWER_MANA))
            {
                DoCast(m_creature->getVictim(), SPELL_ARCANEERUPTION);
                DoScriptText(EMOTE_MANA_FULL, m_creature);
                m_creature->SetPower(POWER_MANA,0);
            }
            
            //Trample Spell
            if (uiTrampleTimer <= diff)
            {
                DoCast(m_creature->getVictim(), SPELL_TRAMPLE);
                uiTrampleTimer = urand(3000,7000);
            } else uiTrampleTimer -= diff;
            
            //Drain Mana
            if (uiDrainManaTimer <= diff)
            {
                DrainMana();
                uiDrainManaTimer = urand(3000,7000);
            } else uiDrainManaTimer -= diff;
            
            DoMeleeAttackIfReady();
            
            //After 90secs change phase
            if (uiPhaseTimer <= diff)
            {
                Phase = STONE;
                DoCast(m_creature, SPELL_SUMMONMANA);
                DoCast(m_creature, SPELL_SUMMONMANA);
                DoCast(m_creature, SPELL_SUMMONMANA);
                DoCast(m_creature, SPELL_GRDRSLEEP);
            } else uiPhaseTimer -= diff;
        }
    }
};

CreatureAI* GetAI_boss_moam(Creature* pCreature)
{
    return new boss_moamAI (pCreature);
}

void AddSC_boss_moam()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_moam";
    newscript->GetAI = &GetAI_boss_moam;
    newscript->RegisterSelf();
}

