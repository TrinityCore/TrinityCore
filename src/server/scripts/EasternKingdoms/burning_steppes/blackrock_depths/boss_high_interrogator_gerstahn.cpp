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
SDName: Boss_High_Interrogator_Gerstahn
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"

enum
{
    SPELL_SHADOWWORDPAIN        = 14032,
    SPELL_MANABURN              = 14033,
    SPELL_PSYCHICSCREAM         = 13704,
    SPELL_SHADOWSHIELD          = 12040
};

struct boss_high_interrogator_gerstahnAI : public ScriptedAI
{
    boss_high_interrogator_gerstahnAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiShadowWordPain_Timer;
    uint32 m_uiManaBurn_Timer;
    uint32 m_uiPsychicScream_Timer;
    uint32 m_uiShadowShield_Timer;

    void Reset() override
    {
        m_uiShadowWordPain_Timer = 4000;
        m_uiManaBurn_Timer = 14000;
        m_uiPsychicScream_Timer = 32000;
        m_uiShadowShield_Timer = 8000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //ShadowWordPain_Timer
        if (m_uiShadowWordPain_Timer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                DoCastSpellIfCan(pTarget, SPELL_SHADOWWORDPAIN);

            m_uiShadowWordPain_Timer = 7000;
        }
        else
            m_uiShadowWordPain_Timer -= uiDiff;

        //ManaBurn_Timer
        if (m_uiManaBurn_Timer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                DoCastSpellIfCan(pTarget, SPELL_MANABURN);

            m_uiManaBurn_Timer = 10000;
        }
        else
            m_uiManaBurn_Timer -= uiDiff;

        //PsychicScream_Timer
        if (m_uiPsychicScream_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PSYCHICSCREAM);
            m_uiPsychicScream_Timer = 30000;
        }
        else
            m_uiPsychicScream_Timer -= uiDiff;

        //ShadowShield_Timer
        if (m_uiShadowShield_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_SHADOWSHIELD);
            m_uiShadowShield_Timer = 25000;
        }
        else
            m_uiShadowShield_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_high_interrogator_gerstahn(Creature* pCreature)
{
    return new boss_high_interrogator_gerstahnAI(pCreature);
}

void AddSC_boss_high_interrogator_gerstahn()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_high_interrogator_gerstahn";
    newscript->GetAI = &GetAI_boss_high_interrogator_gerstahn;
    newscript->RegisterSelf();
}
