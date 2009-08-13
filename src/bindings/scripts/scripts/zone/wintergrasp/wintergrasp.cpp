/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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
#include "Wintergrasp.h"

bool GossipHello_npc_demolisher_engineerer(Player* pPlayer, Creature *_creature)
{
    if (_creature->isQuestGiver())
        pPlayer->PrepareQuestMenu(_creature->GetGUID());

    if (pPlayer->HasAura(SPELL_CORPORAL))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Build catapult.", GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
    else if (pPlayer->HasAura(SPELL_LIEUTENANT))
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Build catapult.", GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Build demolisher.", GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Build siege engine.", GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+2);
    }

    pPlayer->SEND_GOSSIP_MENU(_creature->GetNpcTextId(), _creature->GetGUID());
    return true;
}

bool GossipSelect_npc_demolisher_engineerer(Player* pPlayer, Creature* me, uint32 uiSender, uint32 uiAction)
{
    pPlayer->CLOSE_GOSSIP_MENU();
    switch(uiAction - GOSSIP_ACTION_INFO_DEF)
    {
        case 0: pPlayer->CastSpell(pPlayer, 56663, false, NULL, NULL, me->GetGUID()); break;
        case 1: pPlayer->CastSpell(pPlayer, 56575, false, NULL, NULL, me->GetGUID()); break;
        case 2: pPlayer->CastSpell(pPlayer, pPlayer->GetTeamId() ? 61408 : 56661, false, NULL, NULL, me->GetGUID()); break;
    }

    return true;
}

void AddSC_wintergrasp()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_demolisher_engineerer";
    newscript->pGossipHello = &GossipHello_npc_demolisher_engineerer;
    newscript->pGossipSelect = &GossipSelect_npc_demolisher_engineerer;
    newscript->RegisterSelf();
}