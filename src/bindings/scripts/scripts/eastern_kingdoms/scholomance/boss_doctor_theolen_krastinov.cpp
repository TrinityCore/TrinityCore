/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Boss_Doctor_Theolen_Krastinov
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"
#include "scholomance.h"

enum eEnums
{
    EMOTE_GENERIC_FRENZY_KILL   = -1000001,

    SPELL_REND                  = 16509,
    SPELL_BACKHAND              = 18103,
    SPELL_FRENZY                = 8269
};

struct TRINITY_DLL_DECL boss_theolenkrastinovAI : public ScriptedAI
{
    boss_theolenkrastinovAI(Creature *c) : ScriptedAI(c) {}

    uint32 m_uiRend_Timer;
    uint32 m_uiBackhand_Timer;
    uint32 m_uiFrenzy_Timer;

    void Reset()
    {
        m_uiRend_Timer = 8000;
        m_uiBackhand_Timer = 9000;
        m_uiFrenzy_Timer = 1000;
    }

    void JustDied(Unit* pKiller)
    {
        ScriptedInstance* pInstance = m_creature->GetInstanceData();
        if (pInstance)
        {
            pInstance->SetData(DATA_DOCTORTHEOLENKRASTINOV_DEATH, 0);

            if (pInstance->GetData(TYPE_GANDLING) == IN_PROGRESS)
                m_creature->SummonCreature(1853, 180.73, -9.43856, 75.507, 1.61399, TEMPSUMMON_DEAD_DESPAWN, 0);
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        //Rend_Timer
        if (m_uiRend_Timer <= uiDiff)
        {
            DoCast(m_creature->getVictim(), SPELL_REND);
            m_uiRend_Timer = 10000;
        }
        else
            m_uiRend_Timer -= uiDiff;

        //Backhand_Timer
        if (m_uiBackhand_Timer <= uiDiff)
        {
            DoCast(m_creature->getVictim(), SPELL_BACKHAND);
            m_uiBackhand_Timer = 10000;
        }
        else
            m_uiBackhand_Timer -= uiDiff;

        //Frenzy_Timer
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 26)
        {
            if (m_uiFrenzy_Timer <= uiDiff)
            {
                DoCast(m_creature, SPELL_FRENZY);
                DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);

                m_uiFrenzy_Timer = 120000;
            }
            else
                m_uiFrenzy_Timer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_theolenkrastinov(Creature* pCreature)
{
    return new boss_theolenkrastinovAI (pCreature);
}

void AddSC_boss_theolenkrastinov()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_doctor_theolen_krastinov";
    newscript->GetAI = &GetAI_boss_theolenkrastinov;
    newscript->RegisterSelf();
}

