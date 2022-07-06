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

enum ScoreType
{
    // ALL
    SCORE_KILLING_BLOWS         = 1,
    SCORE_DEATHS                = 2,
    SCORE_HONORABLE_KILLS       = 3,
    SCORE_BONUS_HONOR           = 4,
    SCORE_DAMAGE_DONE           = 5,
    SCORE_HEALING_DONE          = 6,

    // WS, EY and TP
    SCORE_FLAG_CAPTURES         = 7,
    SCORE_FLAG_RETURNS          = 8,

    // AB and IC
    SCORE_BASES_ASSAULTED       = 9,
    SCORE_BASES_DEFENDED        = 10,

    // AV
    SCORE_GRAVEYARDS_ASSAULTED  = 11,
    SCORE_GRAVEYARDS_DEFENDED   = 12,
    SCORE_TOWERS_ASSAULTED      = 13,
    SCORE_TOWERS_DEFENDED       = 14,
    SCORE_MINES_CAPTURED        = 15,

    // SOTA
    SCORE_DESTROYED_DEMOLISHER  = 16,
    SCORE_DESTROYED_WALL        = 17
};

struct BattlegroundScore
{
    friend class Arena;
    friend class Battleground;

    protected:
        BattlegroundScore(ObjectGuid playerGuid, uint32 team);
        virtual ~BattlegroundScore();

        virtual void UpdateScore(uint32 type, uint32 value);

        virtual void BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics& playerData) const;

        // For Logging purpose
        virtual std::string ToString() const { return ""; }

        uint32 GetKillingBlows() const    { return KillingBlows; }
        uint32 GetDeaths() const          { return Deaths; }
        uint32 GetHonorableKills() const  { return HonorableKills; }
        uint32 GetBonusHonor() const      { return BonusHonor; }
        uint32 GetDamageDone() const      { return DamageDone; }
        uint32 GetHealingDone() const     { return HealingDone; }

        virtual uint32 GetAttr1() const { return 0; }
        virtual uint32 GetAttr2() const { return 0; }
        virtual uint32 GetAttr3() const { return 0; }
        virtual uint32 GetAttr4() const { return 0; }
        virtual uint32 GetAttr5() const { return 0; }

        ObjectGuid PlayerGuid;
        uint8 TeamId; // BattlegroundTeamId

        // Default score, present in every type
        uint32 KillingBlows;
        uint32 Deaths;
        uint32 HonorableKills;
        uint32 BonusHonor;
        uint32 DamageDone;
        uint32 HealingDone;
};

#endif // TRINITY_BATTLEGROUND_SCORE_H
