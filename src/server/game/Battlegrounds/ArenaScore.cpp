/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ArenaScore.h"
#include <sstream>

ArenaScore::ArenaScore(ObjectGuid playerGuid, uint32 team) : BattlegroundScore(playerGuid, team)
{
}

void ArenaScore::BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics& playerData) const
{
    BattlegroundScore::BuildPvPLogPlayerDataPacket(playerData);

    if (PreMatchRating)
        playerData.PreMatchRating = PreMatchRating;

    if (PostMatchRating != PreMatchRating)
        playerData.RatingChange = int32(PostMatchRating) - PreMatchRating;

    if (PreMatchMMR)
        playerData.PreMatchMMR = PreMatchMMR;

    if (PostMatchMMR != PreMatchMMR)
        playerData.MmrChange = int32(PostMatchMMR) - PreMatchMMR;
}

// For Logging purpose
std::string ArenaScore::ToString() const
{
    std::ostringstream stream;
    stream << "Damage done: " << DamageDone << ", Healing done: " << HealingDone << ", Killing blows: " << KillingBlows
        << ", PreMatchRating: " << PreMatchRating << ", PreMatchMMR: " << PreMatchMMR
        << ", PostMatchRating: " << PostMatchRating << ", PostMatchMMR: " << PostMatchMMR;
    return stream.str();
}

ArenaTeamScore::ArenaTeamScore()
{
}

ArenaTeamScore::~ArenaTeamScore()
{
}

void ArenaTeamScore::Assign(uint32 preMatchRating, uint32 postMatchRating, uint32 preMatchMMR, uint32 postMatchMMR)
{
    PreMatchRating = preMatchRating;
    PostMatchRating = postMatchRating;
    PreMatchMMR = preMatchMMR;
    PostMatchMMR = postMatchMMR;
}
