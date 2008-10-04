/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: boss_magistrate_barthilas
SD%Complete: 100
SDComment: 
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"

#define SPELL_DRAININGBLOW    16793
#define SPELL_CROWDPUMMEL    10887
#define SPELL_MIGHTYBLOW    14099
#define SPELL_DAZED    1604

struct MANGOS_DLL_DECL boss_magistrate_barthilasAI : public ScriptedAI
{
    boss_magistrate_barthilasAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 DrainingBlow_Timer;
    uint32 CrowdPummel_Timer;
    uint32 MightyBlow_Timer;
    uint32 Dazed_Timer;

    void Reset()
    {
        DrainingBlow_Timer = 4000;
        CrowdPummel_Timer = 13000;
        MightyBlow_Timer = 11000;
        Dazed_Timer = 7000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //DrainingBlow
        if (DrainingBlow_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_DRAININGBLOW);

            //4 seconds until we should cast this again
            DrainingBlow_Timer = 4000;
        }else DrainingBlow_Timer -= diff;

        //CrowdPummel
        if (CrowdPummel_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_CROWDPUMMEL);

            //13 seconds until we should cast this agian
            CrowdPummel_Timer = 13000;
        }else CrowdPummel_Timer -= diff;

        //MightyBlow
        if (MightyBlow_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_MIGHTYBLOW);

            //11 seconds until we should cast this again
            MightyBlow_Timer = 11000;
        }else MightyBlow_Timer -= diff;

        //Dazed
        if (Dazed_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_DAZED);

            //20 seconds until we should cast this again
            Dazed_Timer = 20000;
        }else Dazed_Timer -= diff;

        DoMeleeAttackIfReady();
    }
}; 
CreatureAI* GetAI_boss_magistrate_barthilas(Creature *_Creature)
{
    return new boss_magistrate_barthilasAI (_Creature);
}


void AddSC_boss_magistrate_barthilas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_magistrate_barthilas";
    newscript->GetAI = GetAI_boss_magistrate_barthilas;
    m_scripts[nrscripts++] = newscript;
}
