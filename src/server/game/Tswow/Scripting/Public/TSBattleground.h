/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSMain.h"
#include "TSClasses.h"
#include "TSString.h"

class TC_GAME_API TSBattleground {
public:
    Battleground* bg;
    TSBattleground(Battleground* bg);
    TSBattleground();
    bool IsNull() { return bg == nullptr; };
    TSBattleground* operator->() { return this;}
    uint32 GetBracketId();
    TSString GetName();
    uint32 GetAlivePlayersCountByTeam(uint32 team);
    TSMap GetMap();
    uint32 GetBonusHonorFromKillCount(uint32 kills);
    uint32 GetEndTime();
    uint32 GetFreeSlotsForTeam(uint32 team);
    uint32 GetInstanceId();
    uint32 GetMapId();
    uint32 GetTypeId();
    uint32 GetMaxLevel();
    uint32 GetMinLevel();
    uint32 GetMaxPlayers();
    uint32 GetMinPlayers();
    uint32 GetMaxPlayersPerTeam();
    uint32 GetMinPlayersPerTeam();
    uint32 GetWinner();
    uint32 GetStatus();
};
