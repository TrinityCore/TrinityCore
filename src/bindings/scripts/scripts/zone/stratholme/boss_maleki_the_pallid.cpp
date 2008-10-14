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
SDName: boss_maleki_the_pallid
SD%Complete: 100
SDComment: 
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"

#define SPELL_FROSTNOVA    22645
#define SPELL_FROSTBOLT    17503
#define SPELL_DRAINLIFE    20743
#define SPELL_ICETOMB    16869

struct TRINITY_DLL_DECL boss_maleki_the_pallidAI : public ScriptedAI
{
    boss_maleki_the_pallidAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 FrostNova_Timer;
    uint32 Frostbolt_Timer;
    uint32 IceTomb_Timer;
    uint32 DrainLife_Timer;

    void Reset()
    {
        FrostNova_Timer = 11000;
        Frostbolt_Timer = 1000;
        IceTomb_Timer = 16000;
        DrainLife_Timer = 31000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //FrostNova
        if (FrostNova_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_FROSTNOVA);
            //23 seconds until we should cast this again
            FrostNova_Timer = 23000;
        }else FrostNova_Timer -= diff;

        //Frostbolt
        if (Frostbolt_Timer < diff)
        {
            //Cast
            if (rand()%100 < 90) //90% chance to cast
            {
                DoCast(m_creature->getVictim(),SPELL_FROSTBOLT);
            }
            //3.5 seconds until we should cast this again
            Frostbolt_Timer = 3500;
        }else Frostbolt_Timer -= diff;

        //IceTomb
        if (IceTomb_Timer < diff)
        {
            //Cast
            if (rand()%100 < 65) //65% chance to cast
            {
                DoCast(m_creature->getVictim(),SPELL_ICETOMB);
            }
            //28 seconds until we should cast this again
            IceTomb_Timer = 28000;
        }else IceTomb_Timer -= diff;

        //DrainLife
        if (DrainLife_Timer < diff)
        {
            //Cast
            if (rand()%100 < 55) //55% chance to cast
            {
                DoCast(m_creature->getVictim(),SPELL_DRAINLIFE);
            }
            //31 seconds until we should cast this again
            DrainLife_Timer = 31000;
        }else DrainLife_Timer -= diff;

        DoMeleeAttackIfReady();
    }
}; 
CreatureAI* GetAI_boss_maleki_the_pallid(Creature *_Creature)
{
    return new boss_maleki_the_pallidAI (_Creature);
}


void AddSC_boss_maleki_the_pallid()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_maleki_the_pallid";
    newscript->GetAI = GetAI_boss_maleki_the_pallid;
    m_scripts[nrscripts++] = newscript;
}
