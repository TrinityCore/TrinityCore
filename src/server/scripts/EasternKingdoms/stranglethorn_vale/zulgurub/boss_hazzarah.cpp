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
SDName: Boss_Hazzarah
SD%Complete: 100
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

#define SPELL_MANABURN         26046
#define SPELL_SLEEP            24664

struct boss_hazzarahAI : public ScriptedAI
{
    boss_hazzarahAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 ManaBurn_Timer;
    uint32 Sleep_Timer;
    uint32 Illusions_Timer;

    void Reset() override
    {
        ManaBurn_Timer = urand(4000, 10000);
        Sleep_Timer = urand(10000, 18000);
        Illusions_Timer = urand(10000, 18000);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //ManaBurn_Timer
        if (ManaBurn_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MANABURN);
            ManaBurn_Timer = urand(8000, 16000);
        }
        else ManaBurn_Timer -= diff;

        //Sleep_Timer
        if (Sleep_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SLEEP);
            Sleep_Timer = urand(12000, 20000);

            m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);

            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                m_creature->Attack(pTarget, false);
                m_creature->AddThreat(pTarget);
            }
        }
        else Sleep_Timer -= diff;

        //Illusions_Timer
        if (Illusions_Timer < diff)
        {
            //We will summon 3 illusions that will spawn on a random gamer and attack this gamer
            //We will just use one model for the beginning
            for (int i = 0; i < 3; ++i)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    if (Creature* pIllusion = m_creature->SummonCreature(15163, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000))
                        pIllusion->AI()->AttackStart(pTarget);
                }
            }

            Illusions_Timer = urand(15000, 25000);
        }
        else Illusions_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_hazzarah(Creature* pCreature)
{
    return new boss_hazzarahAI(pCreature);
}

void AddSC_boss_hazzarah()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_hazzarah";
    newscript->GetAI = &GetAI_boss_hazzarah;
    newscript->RegisterSelf();
}
