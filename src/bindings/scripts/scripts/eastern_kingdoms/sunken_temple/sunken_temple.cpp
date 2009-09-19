/* Copyright (C) 2006 - 2009 kb_z
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
SDName: Sunken_Temple
SD%Complete: 100
SDComment: Area Trigger + Puzzle event support
SDCategory: Sunken Temple
EndScriptData */

/* ContentData
at_malfurion_Stormrage_trigger
EndContentData */

#include "precompiled.h"
#include "def_sunken_temple.h"

/*#####
# at_malfurion_Stormrage_trigger
#####*/

bool AreaTrigger_at_malfurion_stormrage(Player* pPlayer, AreaTriggerEntry *at)
{
    if (ScriptedInstance* pInstance = pPlayer->GetInstanceData())
    {
        if (!pPlayer->FindNearestCreature(15362,15))
        Unit* Malfurion = pPlayer->SummonCreature(15362, pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(), -1. 52, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 100000);
        return false;
    }
return false;
}
/*#####
# go_atalai_statue
#####*/

bool GOHello_go_atalai_statue(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = pPlayer->GetInstanceData();
    if (!pInstance)
        return false;
    pInstance->SetData(EVENT_STATE,pGo->GetEntry());
    return false;
}

void AddSC_sunken_temple()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "at_malfurion_stormrage";
    newscript->pAreaTrigger = &AreaTrigger_at_malfurion_stormrage;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_atalai_statue";
    newscript->pGOHello = &GOHello_go_atalai_statue;
    newscript->RegisterSelf();
}
