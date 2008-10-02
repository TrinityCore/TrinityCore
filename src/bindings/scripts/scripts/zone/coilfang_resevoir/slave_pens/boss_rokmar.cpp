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
SDName: Boss_Rokmar
SD%Complete: 100
SDComment:
SDCategory: Coilfang Resevoir, Slave Pens
EndScriptData */

#include "../../../creature/simple_ai.h"

#define SPELL_WATTER_SPIT     40086
#define SPELL_GRIEVOUS_WOUND  31956
#define SPELL_ENSARING_MOSS   31948

CreatureAI* GetAI_boss_rokmar_the_crackler(Creature *_Creature)
{
    SimpleAI* ai = new SimpleAI (_Creature);

    //Watter Spit
    ai->Spell[0].Enabled = true;
    ai->Spell[0].Spell_Id = SPELL_WATTER_SPIT;
    ai->Spell[0].Cooldown = 15000;
    ai->Spell[0].First_Cast = 15000;
    ai->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

    //Grievous Wound
    ai->Spell[1].Enabled = true;
    ai->Spell[1].Spell_Id = SPELL_GRIEVOUS_WOUND;
    ai->Spell[1].Cooldown = 25000;
    ai->Spell[1].First_Cast = 15000;
    ai->Spell[1].Cast_Target_Type = CAST_HOSTILE_TARGET;

    //Ensaring Moss
    ai->Spell[2].Enabled = true;
    ai->Spell[2].Spell_Id = SPELL_ENSARING_MOSS;
    ai->Spell[2].Cooldown = 15000 + (rand()%10000);
    ai->Spell[2].First_Cast = 25000;
    ai->Spell[2].Cast_Target_Type = CAST_HOSTILE_TARGET;

    return ai;
}

void AddSC_boss_rokmar_the_crackler()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_rokmar_the_crackler";
    newscript->GetAI = GetAI_boss_rokmar_the_crackler;
    m_scripts[nrscripts++] = newscript;
}
