/*
* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
*
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

#include "precompiled.h"
#include "blackfathom_deeps.h"

enum Spells
{
    SPELL_BLESSING_OF_BLACKFATHOM                          = 8733
};

bool GoHello_blackfathom_altar(Player *pPlayer, GameObject* pGo)
{
    if (!pPlayer->HasAura(SPELL_BLESSING_OF_BLACKFATHOM))
        pPlayer->AddAura(SPELL_BLESSING_OF_BLACKFATHOM,pPlayer);
    return true;
}

bool GoHello_blackfathom_fire(Player *pPlayer, GameObject* pGo)
{
    ScriptedInstance *pInstance = pGo->GetInstanceData();
    
    if (pInstance)
    {
        pGo->SetGoState(GO_STATE_ACTIVE);
        pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
        pInstance->SetData(DATA_FIRE, pInstance->GetData(DATA_FIRE) + 1);
        return true;
    }
    return false;
}


bool AddSC_blackfathom_deeps()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "go_blackfathom_altar";
    newscript->pGOHello = &GoHello_blackfathom_altar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_blackfathom_fire";
    newscript->pGOHello = &GoHello_blackfathom_fire;
    newscript->RegisterSelf();
}