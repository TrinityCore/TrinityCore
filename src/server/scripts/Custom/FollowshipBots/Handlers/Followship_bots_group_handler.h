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

#include <vector>
#include "ObjectGuid.h"

class Creature;
class Unit;
class WorldObject;
struct DispelAbility;

namespace FSBGroup
{
    // Builds a list containing:
    // - owner (player)
    // - the calling bot (me)
    // - other bots owned by the same player
    void BuildLogicalBotGroup(Creature* bot, std::vector<ObjectGuid>& outGroup);
    std::vector<Unit*> ResolveGroup(WorldObject* context, const std::vector<ObjectGuid>& guids, bool requireAlive = true);

    Unit* BotGetFirstMemberToAssist(Creature* bot);
    Unit* BotGetFirstGroupHealer(Creature* bot);
    Unit* BotGetFirstGroupTank(Creature* bot);
    Unit* BotGetFirstDeadMember(Creature* bot);
    Unit* BotGetDispelMember(Creature* bot, const DispelAbility& ability);
    std::vector<Unit*> BotGetMembersToHeal(Creature* bot, float lowHpThreshold);
    float CalculateEmergencyPriority(Unit* unit);
    void SortEmergencyTargets(std::vector<Unit*>& targets);

    bool BotGroupIsHealthy_Average(Creature* bot, uint32 groupHP);
}
