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
SDName: Boss_Gorosh_the_Dervish
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"

#define SPELL_WHIRLWIND             15589
#define SPELL_MORTALSTRIKE          15708
#define SPELL_BLOODLUST             21049


struct boss_gorosh_the_dervishAI : public ScriptedAI
{
    boss_gorosh_the_dervishAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 WhirlWind_Timer;
    uint32 MortalStrike_Timer;
    uint32 Bloodlust_Timer;

    void Reset() override
    {
        WhirlWind_Timer = 12000;
        MortalStrike_Timer = 22000;
        Bloodlust_Timer = 0;
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //WhirlWind_Timer
        if (WhirlWind_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_WHIRLWIND);
            WhirlWind_Timer = 15000;
        }
        else WhirlWind_Timer -= diff;

        //MortalStrike_Timer
        if (MortalStrike_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTALSTRIKE);
            MortalStrike_Timer = 15000;
        }
        else MortalStrike_Timer -= diff;

        //Bloodlust_Timer
        if (m_creature->GetHealthPercent() < 51.0f)
        {
            if (Bloodlust_Timer < diff)
            {
                DoCastSpellIfCan(m_creature, SPELL_BLOODLUST);
                Bloodlust_Timer = 45000;
            }
            else Bloodlust_Timer -= diff;
        }


        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_gorosh_the_dervish(Creature* pCreature)
{
    return new boss_gorosh_the_dervishAI(pCreature);
}

void AddSC_boss_gorosh_the_dervish()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_gorosh_the_dervish";
    newscript->GetAI = &GetAI_boss_gorosh_the_dervish;
    newscript->RegisterSelf();
}
