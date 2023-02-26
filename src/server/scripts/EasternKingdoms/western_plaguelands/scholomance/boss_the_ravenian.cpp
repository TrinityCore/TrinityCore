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
SDName: Boss_the_ravenian
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "scholomance.h"

#define SPELL_TRAMPLE           15550
#define SPELL_CLEAVE            20691
#define SPELL_SUNDERINCLEAVE    25174
#define SPELL_KNOCKAWAY         10101

struct boss_theravenianAI : public ScriptedAI
{
    boss_theravenianAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 Trample_Timer;
    uint32 Cleave_Timer;
    uint32 SunderingCleave_Timer;
    uint32 KnockAway_Timer;
    bool HasYelled;

    void Reset() override
    {
        Trample_Timer = 24000;
        Cleave_Timer = 15000;
        SunderingCleave_Timer = 40000;
        KnockAway_Timer = 32000;
        HasYelled = false;
    }

    void JustDied(Unit *killer) override
    {
        if (ScriptedInstance* pInstance = (ScriptedInstance*)m_creature->GetInstanceData())
            pInstance->SetData(TYPE_RAVENIAN, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Trample_Timer
        if (Trample_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TRAMPLE);
            Trample_Timer = 10000;
        }
        else Trample_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE);
            Cleave_Timer = 7000;
        }
        else Cleave_Timer -= diff;

        //SunderingCleave_Timer
        if (SunderingCleave_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SUNDERINCLEAVE);
            SunderingCleave_Timer = 20000;
        }
        else SunderingCleave_Timer -= diff;

        //KnockAway_Timer
        if (KnockAway_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKAWAY);
            KnockAway_Timer = 12000;
        }
        else KnockAway_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_theravenian(Creature* pCreature)
{
    return new boss_theravenianAI(pCreature);
}

void AddSC_boss_theravenian()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_the_ravenian";
    newscript->GetAI = &GetAI_boss_theravenian;
    newscript->RegisterSelf();
}
