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

#ifndef TRINITY_BATTLEGROUND_SCORE_H
#define TRINITY_BATTLEGROUND_SCORE_H

#include "BattlegroundPackets.h"
#include "ObjectGuid.h"
#include <string>

struct BattlegroundPlayerScoreTemplate;

enum ScoreType
{
    // ALL
    SCORE_KILLING_BLOWS         = 1,
    SCORE_DEATHS                = 2,
    SCORE_HONORABLE_KILLS       = 3,
    SCORE_BONUS_HONOR           = 4,
    SCORE_DAMAGE_DONE           = 5,
    SCORE_HEALING_DONE          = 6
};

struct BattlegroundScore
{
    BattlegroundScore(ObjectGuid playerGuid, uint32 team, std::unordered_set<uint32> const* pvpStatIds);
    virtual ~BattlegroundScore();

    void UpdateScore(uint32 type, uint32 value);
    void UpdatePvpStat(uint32 pvpStatID, uint32 value);

    // For Logging purpose
    virtual std::string ToString() const { return ""; }

    uint32 GetKillingBlows() const { return KillingBlows; }
    uint32 GetDeaths() const { return Deaths; }
    uint32 GetHonorableKills() const { return HonorableKills; }
    uint32 GetBonusHonor() const { return BonusHonor; }
    uint32 GetDamageDone() const { return DamageDone; }
    uint32 GetHealingDone() const { return HealingDone; }

    uint32 GetAttr1() const { return GetAttr(0); }
    uint32 GetAttr2() const { return GetAttr(1); }
    uint32 GetAttr3() const { return GetAttr(2); }
    uint32 GetAttr4() const { return GetAttr(3); }
    uint32 GetAttr5() const { return GetAttr(4); }

    virtual void BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics& playerData) const;

protected:

    ObjectGuid PlayerGuid;
    uint8 TeamId; // PvPTeamId

    // Default score, present in every type
    uint32 KillingBlows;
    uint32 Deaths;
    uint32 HonorableKills;
    uint32 BonusHonor;
    uint32 DamageDone;
    uint32 HealingDone;

    std::map<uint32, uint32> PvpStats;
private:
    uint32 GetAttr(uint8 index) const;

    std::unordered_set<uint32> const* _validPvpStatIds;
};

#endif // TRINITY_BATTLEGROUND_SCORE_H
