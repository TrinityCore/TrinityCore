/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
/*
#include "precompiled.h"
#include "simple_ai.h"

CreatureAI* GetAI_leaders(Creature *_Creature)
{
    SimpleAI* ai = new SimpleAI (_Creature);

	ai->Spell[0].Enabled = true;               
        ai->Spell[0].Spell_Id = 23931;   // aoe 1000+ danno, 60% speed in meno, 100% speed di att in meno            
        ai->Spell[0].Cooldown = 7899;                 
        ai->Spell[0].First_Cast = 5000;            
        ai->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

    ai->Spell[1].Enabled = true;               
        ai->Spell[1].Spell_Id = 41975;   // heroik strike, 5k di danno            
        ai->Spell[1].Cooldown = 11075;                 
        ai->Spell[1].First_Cast = 13000;            
        ai->Spell[1].Cast_Target_Type = CAST_HOSTILE_TARGET;

    ai->Spell[2].Enabled = true;               
        ai->Spell[2].Spell_Id = 31739;   // si cura da 6938 a 8062     
        ai->Spell[2].Cooldown = 21071;                 
        ai->Spell[2].First_Cast = 8000;            
        ai->Spell[2].Cast_Target_Type = CAST_SELF;
        /home/giuseppe/WORKSPACE/works-emu-wow/repositories/mangos/mangos_master_hw2system/src/bindings/scriptdev2/scripts/azerothscripts/leaders.cpp:18:23: fatal error: simple_ai.h: File o directory non esistente

	ai->EnterEvadeMode();

    return ai;

}

void AddSC_leaders()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="leaders";
    newscript->GetAI = GetAI_leaders;
    newscript->RegisterSelf();
}

*/
