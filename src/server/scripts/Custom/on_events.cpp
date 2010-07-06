/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include <cstring>

//This function is called when the player logs in (every login)
void OnLogin(Player * /*pPlayer*/)
{

}

//This function is called when the player logs out
void OnLogout(Player * /*pPlayer*/)
{

}

//This function is called when the player kills another player
void OnPVPKill(Player * /*killer*/, Player * /*killed*/)
{

}

//This function is called when a players AreaID changes
void OnAreaChange(Player * /*pPlayer*/, AreaTableEntry const * /*pArea*/)
{

}

//This is called when a player kills a creature (non pvp)
void OnCreatureKill(Player * /*pPlayer*/, Creature * /*pCreature*/)
{

}

//This function is called when a player has a money exchange
int32 OnGetMoney(Player * /*pPlayer*/, int32 amount)
{
    return amount;
}

//This function is called whenever a player gets XP
uint32 OnGetXP(Player * /*pPlayer*/, uint32 amount)
{
    return amount;
}

//This function is called when a player clicks a GO Object
bool OnGoClick(Player * /*pPlayer*/, GameObject * /*pGameObject*/)
{
    return true;
}

//This function is called when a player clicks and item
bool OnItemClick(Player * /*pPlayer*/, Item * /*pItem*/)
{
    return true;
}

//This function is called when a player opens an item (like a clam)
bool OnItemOpen(Player * /*pPlayer*/, Item * /*pItem*/)
{
    return true;
}

//This function is called when a player sends a chat message
bool OnPlayerChat(Player * /*pPlayer*/, const char * /*text*/)
{
    return true;
}

//this function is called when the server starts
void OnServerStartup()
{

}
//this function is called when the server shuts down
void OnServerShutdown()
{

}

//this function is called when a player casts a spell
bool OnSpellCast(Unit * /*pUnitTarget*/, Item * /*pItemTarget*/, GameObject * /*pGoTarget*/, uint32 /*i*/, SpellEntry const * /*spell*/)
{
    return true;
}

 void AddSC_onevents()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "scripted_on_events";
    newscript->pOnLogin = &OnLogin;
    newscript->pOnLogout = &OnLogout;
    newscript->pOnPVPKill = &OnPVPKill;
    newscript->pOnAreaChange = &OnAreaChange;
    newscript->pOnCreatureKill = &OnCreatureKill;
    newscript->pOnGetMoney = &OnGetMoney;
    newscript->pOnGetXP = &OnGetXP;
    newscript->pOnGoClick = &OnGoClick;
    newscript->pOnItemClick = &OnItemClick;
    newscript->pOnItemOpen = &OnItemOpen;
    newscript->pOnPlayerChat = &OnPlayerChat;
    newscript->pOnServerShutdown = &OnServerShutdown;
    newscript->pOnServerStartup = &OnServerStartup;
    newscript->pOnSpellCast = &OnSpellCast;

    newscript->RegisterSelf();
}
