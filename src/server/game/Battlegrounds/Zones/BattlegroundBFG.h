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

#ifndef __BATTLEGROUNDBFG_H
#define __BATTLEGROUNDBFG_H

#include "Battleground.h"
#include "BattlegroundScore.h"

enum BG_BFG_Objectives
{
    BFG_OBJECTIVE_BASES_ASSAULTED   = 370,
    BFG_OBJECTIVE_BASES_DEFENDED    = 371
};

class BattlegroundBFGScore final : public BattlegroundScore
{
    protected:
        BattlegroundBFGScore(ObjectGuid playerGuid, uint32 team) : BattlegroundScore(playerGuid, team), BasesAssaulted(0), BasesDefended(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_BASES_ASSAULTED:
                    BasesAssaulted += value;
                    break;
                case SCORE_BASES_DEFENDED:
                    BasesDefended += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildPvPLogPlayerDataPacket(WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics& playerData) const override
        {
            BattlegroundScore::BuildPvPLogPlayerDataPacket(playerData);

            playerData.Stats.emplace_back(BFG_OBJECTIVE_BASES_ASSAULTED, BasesAssaulted);
            playerData.Stats.emplace_back(BFG_OBJECTIVE_BASES_DEFENDED, BasesDefended);
        }

        uint32 GetAttr1() const final override { return BasesAssaulted; }
        uint32 GetAttr2() const final override { return BasesDefended; }

        uint32 BasesAssaulted;
        uint32 BasesDefended;
};

class BattlegroundBFG : public Battleground
{
    public:
        BattlegroundBFG(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundBFG();
};

#endif
