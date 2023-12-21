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

#include "BattlegroundScore.h"
#include "BattlegroundMgr.h"
#include "Errors.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SharedDefines.h"

#include <sstream>

BattlegroundScore::BattlegroundScore(ObjectGuid playerGuid, uint32 team, std::unordered_set<uint32> const* pvpStatIds) : PlayerGuid(playerGuid), TeamId(team == ALLIANCE ? PVP_TEAM_ALLIANCE : PVP_TEAM_HORDE),
    KillingBlows(0), Deaths(0), HonorableKills(0), BonusHonor(0), DamageDone(0), HealingDone(0),
    PreMatchRating(0), PreMatchMMR(0), PostMatchRating(0), PostMatchMMR(0), _validPvpStatIds(pvpStatIds)
{
    if (_validPvpStatIds)
        for (uint32 pvpStatId : *_validPvpStatIds)
            PvpStats[pvpStatId] = 0;
}

BattlegroundScore::~BattlegroundScore() = default;

void BattlegroundScore::UpdateScore(uint32 type, uint32 value)
{
    switch (type)
    {
        case SCORE_KILLING_BLOWS:   // Killing blows
            KillingBlows += value;
            break;
        case SCORE_DEATHS:          // Deaths
            Deaths += value;
            break;
        case SCORE_HONORABLE_KILLS: // Honorable kills
            HonorableKills += value;
            break;
        case SCORE_BONUS_HONOR:     // Honor bonus
            BonusHonor += value;
            break;
        case SCORE_DAMAGE_DONE:     // Damage Done
            DamageDone += value;
            break;
        case SCORE_HEALING_DONE:    // Healing Done
            HealingDone += value;
            break;
        default:
            ABORT_MSG("Not implemented Battleground score type %u!", type);
            break;
    }
}

void BattlegroundScore::UpdatePvpStat(uint32 pvpStatID, uint32 value)
{
    if (!_validPvpStatIds)
        return;

    if (!_validPvpStatIds->contains(pvpStatID))
    {
        TC_LOG_WARN("bg.scores", "Tried updating PvpStat {} but this stat is not allowed on this map", pvpStatID);
        return;
    }

    PvpStats[pvpStatID] += value;
    if (Player* player = ObjectAccessor::FindConnectedPlayer(PlayerGuid))
        player->UpdateCriteria(CriteriaType::TrackedWorldStateUIModified, pvpStatID);
}

uint32 BattlegroundScore::GetAttr(uint8 index) const
{
    auto const& itr = std::next(PvpStats.begin(), index);
    if (itr == PvpStats.end())
        return 0;

    return itr->second;
}

void BattlegroundScore::BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics& playerData) const
{
    playerData.PlayerGUID = PlayerGuid;
    playerData.Kills = KillingBlows;
    playerData.Faction = TeamId;
    if (HonorableKills || Deaths || BonusHonor)
    {
        playerData.Honor.emplace();
        playerData.Honor->HonorKills = HonorableKills;
        playerData.Honor->Deaths = Deaths;
        playerData.Honor->ContributionPoints = BonusHonor;
    }

    playerData.DamageDone = DamageDone;
    playerData.HealingDone = HealingDone;

    if (PreMatchRating)
        playerData.PreMatchRating = PreMatchRating;

    if (PostMatchRating != PreMatchRating)
        playerData.RatingChange = int32(PostMatchRating) - PreMatchRating;

    if (PreMatchMMR)
        playerData.PreMatchMMR = PreMatchMMR;

    if (PostMatchMMR != PreMatchMMR)
        playerData.MmrChange = int32(PostMatchMMR) - PreMatchMMR;

    for (const auto& [pvpStatID, value] : PvpStats)
        playerData.Stats.emplace_back(pvpStatID, value);
}

std::string BattlegroundScore::ToString() const
{
    std::ostringstream stream;
    stream << "Damage done: " << DamageDone << ", Healing done: " << HealingDone << ", Killing blows: " << KillingBlows
        << ", PreMatchRating: " << PreMatchRating << ", PreMatchMMR: " << PreMatchMMR
        << ", PostMatchRating: " << PostMatchRating << ", PostMatchMMR: " << PostMatchMMR;
    return stream.str();
}
