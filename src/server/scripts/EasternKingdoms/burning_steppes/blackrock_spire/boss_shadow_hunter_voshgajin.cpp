/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Shadow_Hunter_Voshgajin
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "scriptPCH.h"

enum
{
    SPELL_CURSEOFBLOOD = 24673,
    SPELL_HEX          = 16708,
    SPELL_CLEAVE       = 20691
};

struct boss_shadowvoshAI : public ScriptedAI
{
    boss_shadowvoshAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiCurseOfBloodTimer;
    uint32 m_uiHexTimer;
    uint32 m_uiCleaveTimer;

    void Reset() override
    {
        m_uiCurseOfBloodTimer = 2000;
        m_uiHexTimer          = 8000;
        m_uiCleaveTimer       = 14000;

        //m_creature->CastSpell(m_creature,SPELL_ICEARMOR,true);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Curse Of Blood
        if (m_uiCurseOfBloodTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_CURSEOFBLOOD);
            m_uiCurseOfBloodTimer = 45000;
        }
        else
            m_uiCurseOfBloodTimer -= uiDiff;

        // Hex
        if (m_uiHexTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                DoCastSpellIfCan(pTarget, SPELL_HEX);
                m_uiHexTimer += 15000;
            }
        }
        else
            m_uiHexTimer -= uiDiff;

        // Cleave
        if (m_uiCleaveTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE);
            m_uiCleaveTimer = 7000;
        }
        else
            m_uiCleaveTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_shadowvosh(Creature* pCreature)
{
    return new boss_shadowvoshAI(pCreature);
}

void AddSC_boss_shadowvosh()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_shadow_hunter_voshgajin";
    newscript->GetAI = &GetAI_boss_shadowvosh;
    newscript->RegisterSelf();
}
