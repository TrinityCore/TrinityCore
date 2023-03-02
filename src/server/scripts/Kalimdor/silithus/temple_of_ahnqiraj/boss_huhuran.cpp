/*
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2010-2011 ScriptDev0 <http://github.com/mangos-zero/scriptdev0>
 *
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

/* ScriptData
SDName: Boss_Huhuran
SD%Complete: 100
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"
#include "temple_of_ahnqiraj.h"

enum
{
    EMOTE_GENERIC_FRENZY_KILL   = 7797,
    EMOTE_GENERIC_BERSERK       = -1000004,

    SPELL_ACIDSPIT              = 26050,
    SPELL_FRENZY                = 26051,
    SPELL_NOXIOUSPOISON         = 26053,
    SPELL_BERSERK               = 26068,
    SPELL_WYVERNSTING           = 26180
};

struct boss_huhuranAI : public ScriptedAI
{
    boss_huhuranAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiFrenzyTimer;
    uint32 m_uiWyvernTimer;
    uint32 m_uiSpitTimer;
    uint32 m_uiNoxiousPoisonTimer;
    uint32 m_uiBerserkTimer;

    bool m_bBerserk;

    void MoveInLineOfSight(Unit* pWho) override
    {
        
        if (m_creature->CanAttack(pWho)
            && !m_creature->IsInCombat()
            && m_creature->IsWithinDistInMap(pWho, 80.0f) 
            && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH))
        {
            AttackStart(pWho); 
        }
        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_HUHURAN, IN_PROGRESS);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_HUHURAN, FAIL);
    }

    void JustDied(Unit*) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_HUHURAN, DONE);
    }

    void Reset() override
    {
        m_uiFrenzyTimer        = urand(25000, 35000);
        m_uiWyvernTimer        = urand(18000, 28000);
        m_uiSpitTimer          = 8000;
        m_uiNoxiousPoisonTimer = urand(10000, 20000);
        m_uiBerserkTimer       = 5 * MINUTE * IN_MILLISECONDS;

        m_bBerserk             = false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //m_uiFrenzyTimer
        if (m_uiFrenzyTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
            {
                DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
                m_uiFrenzyTimer = urand(25000, 35000);
            }
        }
        else
            m_uiFrenzyTimer -= uiDiff;

        // No longer cast wyvern string during enrage
        if (!m_bBerserk)
        {
            // Wyvern Timer
            if (m_uiWyvernTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WYVERNSTING) == CAST_OK)
                    m_uiWyvernTimer = urand(15000, 32000);
            }
            else
                m_uiWyvernTimer -= uiDiff;
        }

        //Spit Timer
        if (m_uiSpitTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ACIDSPIT) == CAST_OK)
                m_uiSpitTimer = urand(5000, 10000);
        }
        else
            m_uiSpitTimer -= uiDiff;

        // Noxious Poison
        if (m_uiNoxiousPoisonTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                if (DoCastSpellIfCan(pTarget, SPELL_NOXIOUSPOISON) == CAST_OK)
                    m_uiNoxiousPoisonTimer = urand(12000, 24000);
        }
        else
            m_uiNoxiousPoisonTimer -= uiDiff;

        if (m_bBerserk)
            DoCastSpellIfCan(m_creature, SPELL_BERSERK, CF_AURA_NOT_PRESENT);
        else if (m_creature->GetHealthPercent() < 31.0f || m_uiBerserkTimer < uiDiff)
        {
            DoScriptText(EMOTE_GENERIC_BERSERK, m_creature);
            m_bBerserk = true;
        }
        else
            m_uiBerserkTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_huhuran(Creature* pCreature)
{
    return new boss_huhuranAI(pCreature);
}

void AddSC_boss_huhuran()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_huhuran";
    newscript->GetAI = &GetAI_boss_huhuran;
    newscript->RegisterSelf();
}
