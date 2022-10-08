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
SDName: Boss_Ramstein_the_Gorger
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"
#include "stratholme.h"

enum
{
    SPELL_TRAMPLE = 5568,
    SPELL_KNOCKOUT = 17307,
};

struct boss_ramstein_the_gorgerAI : public ScriptedAI
{
    boss_ramstein_the_gorgerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Engaged = false;
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 Trample_Timer;
    uint32 Knockout_Timer;
    bool Engaged;

    void Reset() override
    {
        Trample_Timer = 3000;
        Knockout_Timer = 12000;
        if (Engaged)
            m_pInstance->SetData(TYPE_RAMSTEIN, FAIL);
        Engaged = false;
    }

    void Aggro(Unit *who) override
    {
        Engaged = true;
        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAMSTEIN, IN_PROGRESS);
    }

    void JustDied(Unit* Killer) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAMSTEIN, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Trample
        if (Trample_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_TRAMPLE);
            Trample_Timer = 7000;
        }
        else Trample_Timer -= diff;

        //Knockout
        if (Knockout_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKOUT) == CAST_OK)
            {
                m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);
                Knockout_Timer = 10000;
            }
        }
        else Knockout_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_ramstein_the_gorger(Creature* pCreature)
{
    return new boss_ramstein_the_gorgerAI(pCreature);
}

void AddSC_boss_ramstein_the_gorger()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_ramstein_the_gorger";
    newscript->GetAI = &GetAI_boss_ramstein_the_gorger;
    newscript->RegisterSelf();
}
