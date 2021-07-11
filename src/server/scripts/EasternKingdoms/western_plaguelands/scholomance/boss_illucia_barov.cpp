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
SDName: Boss_Illucia_Barov
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "scholomance.h"

#define SPELL_CURSEOFAGONY      18671
#define SPELL_SHADOWSHOCK       20603
#define SPELL_SILENCE           15487
#define SPELL_FEAR              6215

struct boss_illuciabarovAI : public ScriptedAI
{
    boss_illuciabarovAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 CurseOfAgony_Timer;
    uint32 ShadowShock_Timer;
    uint32 Silence_Timer;
    uint32 Fear_Timer;

    void Reset() override
    {
        CurseOfAgony_Timer = 18000;
        ShadowShock_Timer = 9000;
        Silence_Timer = 5000;
        Fear_Timer = 30000;
    }

    void JustDied(Unit *killer) override
    {
        if (ScriptedInstance* pInstance = (ScriptedInstance*)m_creature->GetInstanceData())
            pInstance->SetData(TYPE_ILLUCIABAROV, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //CurseOfAgony_Timer
        if (CurseOfAgony_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSEOFAGONY);
            CurseOfAgony_Timer = 30000;
        }
        else CurseOfAgony_Timer -= diff;

        //ShadowShock_Timer
        if (ShadowShock_Timer < diff)
        {
            Unit* target = nullptr;
            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target) DoCastSpellIfCan(target, SPELL_SHADOWSHOCK);

            ShadowShock_Timer = 12000;
        }
        else ShadowShock_Timer -= diff;

        //Silence_Timer
        if (Silence_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SILENCE);
            Silence_Timer = 14000;
        }
        else Silence_Timer -= diff;

        //Fear_Timer
        if (Fear_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FEAR);
            Fear_Timer = 30000;
        }
        else Fear_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_illuciabarov(Creature* pCreature)
{
    return new boss_illuciabarovAI(pCreature);
}

void AddSC_boss_illuciabarov()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_illucia_barov";
    newscript->GetAI = &GetAI_boss_illuciabarov;
    newscript->RegisterSelf();
}
