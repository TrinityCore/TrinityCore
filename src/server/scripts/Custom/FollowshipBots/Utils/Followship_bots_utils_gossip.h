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

#include <string>
#include "Define.h"

class Player;
class Creature;

namespace FSBGossipUtils
{
    // Converts an int64 price in copper to a string like 10 silver
    std::string MoneyToString(int64 price);

    // Builds the hire option text dynamically
    std::string BuildHireText(int64 price, uint32 hours);

    // Resolves gossip text ID: creature's own gossip text first, fallback to FSB_GOSSIP_DEFAULT_MENU (12504)
    uint32 ResolveGossipTextId(Player* player, Creature* bot);
}
