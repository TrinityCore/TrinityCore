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
SDName: boss_ramstein_the_gorger
SD%Complete: 100
SDComment: 
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"

#define SPELL_TRAMPLE    15550
#define SPELL_KNOCKOUT    17307

struct TRINITY_DLL_DECL boss_ramstein_the_gorgerAI : public ScriptedAI
{
    boss_ramstein_the_gorgerAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Trample_Timer;
    uint32 Knockout_Timer;

    void Reset()
    {
        Trample_Timer = 3000;
        Knockout_Timer = 12000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //Trample
        if (Trample_Timer < diff)
        {
            //Cast
            if (rand()%100 < 75) //75% chance to cast
            {
                DoCast(m_creature->getVictim(),SPELL_TRAMPLE);
            }
            //7 seconds until we should cast this again
            Trample_Timer = 7000;
        }else Trample_Timer -= diff;

        //Knockout
        if (Knockout_Timer < diff)
        {
            //Cast
            if (rand()%100 < 70) //70% chance to cast
            {
                DoCast(m_creature->getVictim(),SPELL_KNOCKOUT);
            }
            //10 seconds until we should cast this again
            Knockout_Timer = 10000;
        }else Knockout_Timer -= diff;

        DoMeleeAttackIfReady();
    }
}; 
CreatureAI* GetAI_boss_ramstein_the_gorger(Creature *_Creature)
{
    return new boss_ramstein_the_gorgerAI (_Creature);
}


void AddSC_boss_ramstein_the_gorger()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_ramstein_the_gorger";
    newscript->GetAI = GetAI_boss_ramstein_the_gorger;
    m_scripts[nrscripts++] = newscript;
}
