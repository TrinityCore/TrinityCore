/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Kurinnaxx
SD%Complete: 100
SDComment: VERIFY SCRIPT AND SQL
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "precompiled.h"

#define SPELL_MORTALWOUND 25646
#define SPELL_SANDTRAP 25656
#define SPELL_ENRAGE 28798

struct TRINITY_DLL_DECL boss_kurinnaxxAI : public ScriptedAI
{
    boss_kurinnaxxAI(Creature *c) : ScriptedAI(c) {}

    Unit *pTarget;
    uint32 MORTALWOUND_Timer;
    uint32 SANDTRAP_Timer;
    uint32 i;

    void Reset()
    {
        i=0;
        pTarget = NULL;
        MORTALWOUND_Timer = 30000;
        SANDTRAP_Timer = 30000;
    }

    void Aggro(Unit *who)
    {
        pTarget = who;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are <30% cast enrage
        if (i==0 && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 30 && !m_creature->IsNonMeleeSpellCasted(false))
        {
            i=1;
            DoCast(m_creature->getVictim(),SPELL_ENRAGE);
        }

        //MORTALWOUND_Timer
        if (MORTALWOUND_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MORTALWOUND);
            MORTALWOUND_Timer = 30000;
        }else MORTALWOUND_Timer -= diff;

        //SANDTRAP_Timer
        if (SANDTRAP_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SANDTRAP);
            SANDTRAP_Timer = 30000;
        }else SANDTRAP_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_kurinnaxx(Creature *_Creature)
{
    return new boss_kurinnaxxAI (_Creature);
}

void AddSC_boss_kurinnaxx()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_kurinnaxx";
    newscript->GetAI = &GetAI_boss_kurinnaxx;
    newscript->RegisterSelf();
}

