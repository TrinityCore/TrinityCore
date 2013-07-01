/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/*
Name:     Black_Temple
Complete: 100%
Comment:  Spirit of Olum: Player Teleporter to Seer Kanai Teleport after defeating Naj'entus and Supremus.
*/

/* Content
npc_spirit_of_olum
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "black_temple.h"
#include "Player.h"

/*###
# npc_spirit_of_olum
####*/

enum Spells
{
    SPELL_TELEPORT              = 39833
};

class npc_spirit_of_olum : public CreatureScript
{
public:
    npc_spirit_of_olum() : CreatureScript("npc_spirit_of_olum") { }

    void sGossipSelect(Player* player, uint32 /*sender*/, uint32 action)
    {
        if (action == 1)
        {
            player->CLOSE_GOSSIP_MENU();
            player->InterruptNonMeleeSpells(false);
            player->CastSpell(player, SPELL_TELEPORT, false);
        }
    }
};

void AddSC_black_temple()
{
    new npc_spirit_of_olum();
}
