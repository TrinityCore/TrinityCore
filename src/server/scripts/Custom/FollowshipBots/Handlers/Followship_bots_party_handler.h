/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <vector>

#include "Creature.h"
#include "Group.h"

#include "Followship_bots_defines.h"

constexpr size_t MAX_CLIENT_PARTY = 5;

class Creature;
class Player;

namespace FSBParty
{
    void PeriodicPartyNeededCheck(Creature* bot);
    void PeriodicBattlegroundRaidUpdate(Creature* bot);
    std::vector<Creature*> CollectActiveBots(Player* player);

    // Sends a fake SMSG_PARTY_UPDATE to the player that includes their bots
    // If the player is in a real group, bots are appended to the real group members
    // If not in a group, creates a standalone fake party with just the player + bots
    void SendFakePartyUpdate(Player* player, Creature* bot = nullptr);

    // Sends a fake SMSG_PARTY_UPDATE for a battleground raid roster.
    // No 5-member cap is applied; all bots are sent for the client's raid frame.
    void SendBattlegroundRaidUpdate(Player* player, std::vector<Creature*> const& bots);

    // Sends SMSG_PARTY_MEMBER_FULL_STATE for a single bot creature to the owner
    // This updates health, mana, position etc. on the party frame
    void SendBotMemberState(Player* player, Creature* bot);

    // Sends an empty party update to clear the fake group (on dismiss/logout)
    void SendClearFakeParty(Player* player);

    void OnMemberAdd(Group* group, ObjectGuid guid);
    void OnMemberRemove(Group* group, ObjectGuid guid);

    std::vector<uint32> GetBotAppliedAuras(Creature* bot);
}
