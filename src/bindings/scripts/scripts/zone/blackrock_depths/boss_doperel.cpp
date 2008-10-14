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
SDName: Boss_Doperel
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_SINISTERSTRIKE        15581
#define SPELL_BACKSTAB              15582
#define SPELL_GOUGE                 13579

struct MANGOS_DLL_DECL boss_doperelAI : public ScriptedAI
{
    boss_doperelAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 SinisterStrike_Timer;
    uint32 BackStab_Timer;
    uint32 Gouge_Timer;

    void Reset()
    {
        SinisterStrike_Timer = 8000;
        BackStab_Timer = 12000;
        Gouge_Timer = 6000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //SinisterStrike_Timer
        if (SinisterStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SINISTERSTRIKE);
            SinisterStrike_Timer = 7000;
        }else SinisterStrike_Timer -= diff;

        //BackStab_Timer
        if (BackStab_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_BACKSTAB);
            BackStab_Timer = 6000;
        }else BackStab_Timer -= diff;

        //Gouge_Timer
        if (Gouge_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_GOUGE);
            Gouge_Timer = 8000;
        }else Gouge_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_doperel(Creature *_Creature)
{
    return new boss_doperelAI (_Creature);
}

void AddSC_boss_doperel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_doperel";
    newscript->GetAI = GetAI_boss_doperel;
    m_scripts[nrscripts++] = newscript;
}
