/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

        void BuildObjectivesBlock(std::vector<int32>& stats) override
        {
            stats.push_back(BasesAssaulted);
            stats.push_back(BasesDefended);
        }

        uint32 GetAttr1() const final override { return BasesAssaulted; }
        uint32 GetAttr2() const final override { return BasesDefended; }

        uint32 BasesAssaulted;
        uint32 BasesDefended;
};

class BattlegroundBFG : public Battleground
{
    public:
        BattlegroundBFG();
        ~BattlegroundBFG();
};

#endif
