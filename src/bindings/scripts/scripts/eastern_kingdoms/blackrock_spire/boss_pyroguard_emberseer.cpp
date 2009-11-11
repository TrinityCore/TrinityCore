/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Pyroguard_Emberseer
SD%Complete: 100
SDComment: Event to activate Emberseer NYI
SDCategory: Blackrock Spire
EndScriptData */

#include "precompiled.h"

#define SPELL_FIRENOVA          23462
#define SPELL_FLAMEBUFFET       23341
#define SPELL_PYROBLAST         17274

struct TRINITY_DLL_DECL boss_pyroguard_emberseerAI : public ScriptedAI
{
    boss_pyroguard_emberseerAI(Creature *c) : ScriptedAI(c) {}

    uint32 FireNova_Timer;
    uint32 FlameBuffet_Timer;
    uint32 PyroBlast_Timer;

    void Reset()
    {
        FireNova_Timer = 6000;
        FlameBuffet_Timer = 3000;
        PyroBlast_Timer = 14000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //FireNova_Timer
        if (FireNova_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FIRENOVA);
            FireNova_Timer = 6000;
        } else FireNova_Timer -= diff;

        //FlameBuffet_Timer
        if (FlameBuffet_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FLAMEBUFFET);
            FlameBuffet_Timer = 14000;
        } else FlameBuffet_Timer -= diff;

        //PyroBlast_Timer
        if (PyroBlast_Timer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_PYROBLAST);
            PyroBlast_Timer = 15000;
        } else PyroBlast_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_pyroguard_emberseer(Creature* pCreature)
{
    return new boss_pyroguard_emberseerAI (pCreature);
}

void AddSC_boss_pyroguard_emberseer()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_pyroguard_emberseer";
    newscript->GetAI = &GetAI_boss_pyroguard_emberseer;
    newscript->RegisterSelf();
}

