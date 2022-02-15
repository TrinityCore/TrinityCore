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

#ifndef __BATTLEGROUNDTP_H
#define __BATTLEGROUNDTP_H

#include "Battleground.h"
#include "BattlegroundScore.h"

enum BG_TP_Objectives
{
    BG_TP_FLAG_CAPTURES = 290,
    BG_TP_FLAG_RETURNS  = 291
};

class BattlegroundTPScore final : public BattlegroundScore
{
    protected:
        BattlegroundTPScore(ObjectGuid playerGuid, uint32 team) : BattlegroundScore(playerGuid, team), FlagCaptures(0), FlagReturns(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_FLAG_CAPTURES:
                    FlagCaptures += value;
                    break;
                case SCORE_FLAG_RETURNS:
                    FlagReturns += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics& playerData) const override
        {
            BattlegroundScore::BuildPvPLogPlayerDataPacket(playerData);

            playerData.Stats.emplace_back(BG_TP_FLAG_CAPTURES, FlagCaptures);
            playerData.Stats.emplace_back(BG_TP_FLAG_RETURNS, FlagReturns);
        }

        uint32 GetAttr1() const final override { return FlagCaptures; }
        uint32 GetAttr2() const final override { return FlagReturns; }

        uint32 FlagCaptures;
        uint32 FlagReturns;
};

class BattlegroundTP : public Battleground
{
    public:
        BattlegroundTP(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundTP();
};

#endif
