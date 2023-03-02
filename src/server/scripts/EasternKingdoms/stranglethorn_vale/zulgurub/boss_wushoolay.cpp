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
SDName: Boss_Wushoolay
SD%Complete: 100
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

#define SPELL_LIGHTNINGCLOUD         25033
#define SPELL_LIGHTNINGWAVE          24819

struct boss_wushoolayAI : public ScriptedAI
{
    boss_wushoolayAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 LightningCloud_Timer;
    uint32 LightningWave_Timer;

    void Reset() override
    {
        LightningCloud_Timer = urand(5000, 10000);
        LightningWave_Timer = urand(8000, 16000);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //LightningCloud_Timer
        if (LightningCloud_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_LIGHTNINGCLOUD);
            LightningCloud_Timer = urand(15000, 20000);
        }
        else LightningCloud_Timer -= diff;

        //LightningWave_Timer
        if (LightningWave_Timer < diff)
        {
            Unit* target = nullptr;
            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target) DoCastSpellIfCan(target, SPELL_LIGHTNINGWAVE);

            LightningWave_Timer = urand(12000, 16000);
        }
        else LightningWave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_wushoolay(Creature* pCreature)
{
    return new boss_wushoolayAI(pCreature);
}

void AddSC_boss_wushoolay()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_wushoolay";
    newscript->GetAI = &GetAI_boss_wushoolay;
    newscript->RegisterSelf();
}
