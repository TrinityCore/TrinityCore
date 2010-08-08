/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Black_Temple
SD%Complete: 95
SDComment: Spirit of Olum: Player Teleporter to Seer Kanai Teleport after defeating Naj'entus and Supremus. TODO: Find proper gossip.
SDCategory: Black Temple
EndScriptData */

/* ContentData
npc_spirit_of_olum
EndContentData */

#include "ScriptPCH.h"
#include "black_temple.h"

/*###
# npc_spirit_of_olum
####*/

#define SPELL_TELEPORT      41566                           // s41566 - Teleport to Ashtongue NPC's
#define GOSSIP_OLUM1        "Teleport me to the other Ashtongue Deathsworn"
class npc_spirit_of_olum : public CreatureScript
{
public:
    npc_spirit_of_olum() : CreatureScript("npc_spirit_of_olum") { }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
            pPlayer->CLOSE_GOSSIP_MENU();

        pPlayer->InterruptNonMeleeSpells(false);
        pPlayer->CastSpell(pPlayer, SPELL_TELEPORT, false);
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();

        if (pInstance && (pInstance->GetData(DATA_SUPREMUSEVENT) >= DONE) && (pInstance->GetData(DATA_HIGHWARLORDNAJENTUSEVENT) >= DONE))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OLUM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

};


void AddSC_black_temple()
{
    new npc_spirit_of_olum();
}
