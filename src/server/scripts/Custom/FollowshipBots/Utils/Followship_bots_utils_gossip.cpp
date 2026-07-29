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

#include "Followship_bots_utils_gossip.h"

#include "Creature.h"
#include "Player.h"
#include "GossipDef.h"
#include "ObjectMgr.h"
#include "Followship_bots_gossip_handler.h"

namespace FSBGossipUtils
{
    // Converts an int64 price in copper to a string like "10 silver"
    std::string MoneyToString(int64 price)
    {
        int32 gold = price / 10000;
        int32 silver = (price % 10000) / 100;
        int32 copper = price % 100;
        std::string result;
        if (gold > 0)   result += std::to_string(gold) + " gold ";
        if (silver > 0) result += std::to_string(silver) + " silver ";
        if (copper > 0) result += std::to_string(copper) + " copper";
        return result.empty() ? "0 copper" : result;
    }

    // Builds the hire option text dynamically
    std::string BuildHireText(int64 price, uint32 hours)
    {
        return std::to_string(hours) + " hour service: " + MoneyToString(price);
    }

    uint32 ResolveGossipTextId(Player* player, Creature* bot)
    {
        uint32 textId = player->GetGossipTextId(bot);

        if (textId == 0 || textId == DEFAULT_GOSSIP_MESSAGE || !sObjectMgr->GetNpcText(textId))
            textId = player->GetGossipTextId(FSB_GOSSIP_DEFAULT_MENU, bot);

        return textId;
    }
}
