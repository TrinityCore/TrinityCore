/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Errors.h"
#include "SharedDefines.h"

BattlegroundScore::BattlegroundScore(ObjectGuid playerGuid, uint32 team) : PlayerGuid(playerGuid), TeamId(team == ALLIANCE ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE),
    KillingBlows(0), Deaths(0), HonorableKills(0), BonusHonor(0), DamageDone(0), HealingDone(0)
{
}

BattlegroundScore::~BattlegroundScore()
{
}

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
            ASSERT(false, "Not implemented Battleground score type %u!", type);
            break;
    }
}

void BattlegroundScore::BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPLogData::PlayerData& playerData) const
{
    playerData.PlayerGUID = PlayerGuid;
    playerData.Kills = KillingBlows;
    playerData.Faction = TeamId;
    if (HonorableKills || Deaths || BonusHonor)
    {
        playerData.Honor = boost::in_place();
        playerData.Honor->HonorKills = HonorableKills;
        playerData.Honor->Deaths = Deaths;
        playerData.Honor->ContributionPoints = BonusHonor;
    }

    playerData.DamageDone = DamageDone;
    playerData.HealingDone = HealingDone;
}
