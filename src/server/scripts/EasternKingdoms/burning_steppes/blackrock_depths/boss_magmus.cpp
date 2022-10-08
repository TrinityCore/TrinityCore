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

/* ScriptData
SDName: Boss_Magmus
SD%Complete: 80
SDComment: Missing pre-event to open doors
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"
#include "blackrock_depths.h"

enum
{
    SPELL_FIERYBURST        = 13900,
    SPELL_WARSTOMP          = 24375
};

struct boss_magmusAI : public ScriptedAI
{
    boss_magmusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Engaged = false;
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiFieryBurst_Timer;
    uint32 m_uiWarStomp_Timer;
    bool Engaged;

    void Reset() override
    {
        m_uiFieryBurst_Timer = 5000;
        m_uiWarStomp_Timer = 0;

        if (Engaged)
            m_pInstance->SetData(TYPE_IRON_HALL, FAIL);
        Engaged = false;
    }

    void Aggro(Unit* pWho) override
    {
        Engaged = true;
        if (m_pInstance)
            m_pInstance->SetData(TYPE_IRON_HALL, IN_PROGRESS);

    }

    void JustDied(Unit* pVictim) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_IRON_HALL, DONE);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //FieryBurst_Timer
        if (m_uiFieryBurst_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FIERYBURST);
            m_uiFieryBurst_Timer = 6000;
        }
        else
            m_uiFieryBurst_Timer -= uiDiff;

        //WarStomp_Timer
        if (m_creature->GetHealthPercent() < 51.0f)
        {
            if (m_uiWarStomp_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WARSTOMP);
                m_uiWarStomp_Timer = 8000;
            }
            else
                m_uiWarStomp_Timer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_magmus(Creature* pCreature)
{
    return new boss_magmusAI(pCreature);
}

void AddSC_boss_magmus()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_magmus";
    newscript->GetAI = &GetAI_boss_magmus;
    newscript->RegisterSelf();
}
