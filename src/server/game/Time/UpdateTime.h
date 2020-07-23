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

#ifndef __UPDATETIME_H
#define __UPDATETIME_H

#include "Define.h"
#include <array>
#include <string>

#define AVG_DIFF_COUNT 500

class TC_GAME_API UpdateTime
{
    using DiffTableArray = std::array<uint32, AVG_DIFF_COUNT>;

    public:
        uint32 GetAverageUpdateTime() const;
        uint32 GetTimeWeightedAverageUpdateTime() const;
        uint32 GetMaxUpdateTime() const;
        uint32 GetMaxUpdateTimeOfCurrentTable() const;
        uint32 GetLastUpdateTime() const;

        void UpdateWithDiff(uint32 diff);

    protected:
        UpdateTime();

    private:
        DiffTableArray _updateTimeDataTable;
        uint32 _averageUpdateTime;
        uint32 _totalUpdateTime;
        uint32 _updateTimeTableIndex;
        uint32 _maxUpdateTime;
        uint32 _maxUpdateTimeOfLastTable;
        uint32 _maxUpdateTimeOfCurrentTable;
};

class TC_GAME_API WorldUpdateTime : public UpdateTime
{
    public:
        WorldUpdateTime() : UpdateTime() { }
};

TC_GAME_API extern WorldUpdateTime sWorldUpdateTime;

#endif
