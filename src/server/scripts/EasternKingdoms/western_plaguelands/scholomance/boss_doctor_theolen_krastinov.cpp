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
SDName: Boss_Doctor_Theolen_Krastinov
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "scholomance.h"

enum
{
    EMOTE_GENERIC_FRENZY_KILL   = 7797,

    SPELL_REND                  = 16509,
    SPELL_BACKHAND              = 18103,
    SPELL_FRENZY                = 8269
};

struct boss_theolenkrastinovAI : public ScriptedAI
{
    boss_theolenkrastinovAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiRend_Timer;
    uint32 m_uiBackhand_Timer;
    uint32 m_uiFrenzy_Timer;

    void Reset() override
    {
        m_uiRend_Timer = 8000;
        m_uiBackhand_Timer = 9000;
        m_uiFrenzy_Timer = 1000;
    }

    void JustDied(Unit *killer) override
    {
        if (ScriptedInstance* pInstance = (ScriptedInstance*)m_creature->GetInstanceData())
            pInstance->SetData(TYPE_THEOLEN, DONE);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Rend_Timer
        if (m_uiRend_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_REND);
            m_uiRend_Timer = 10000;
        }
        else
            m_uiRend_Timer -= uiDiff;

        //m_uiBackhand_Timer
        if (m_uiBackhand_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BACKHAND);
            DoModifyThreatPercent(m_creature->GetVictim(), -100);
            m_uiBackhand_Timer = 10000;
        }
        else
            m_uiBackhand_Timer -= uiDiff;

        //Frenzy_Timer
        if (m_creature->GetHealthPercent() < 26.0f)
        {
            if (m_uiFrenzy_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
                {
                    DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
                    m_uiFrenzy_Timer = 120000;
                }
            }
            else
                m_uiFrenzy_Timer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_theolenkrastinov(Creature* pCreature)
{
    return new boss_theolenkrastinovAI(pCreature);
}

void AddSC_boss_theolenkrastinov()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_doctor_theolen_krastinov";
    newscript->GetAI = &GetAI_boss_theolenkrastinov;
    newscript->RegisterSelf();
}
