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
#include "TSString.h"
#include "TSArray.h"
#include "TSClasses.h"

class TC_GAME_API TSMap {
public:
    Map *map;
    TSMap(Map *map);
    TSMap();
    TSMap* operator->() { return this;}
    bool IsNull() { return map == nullptr; };
    bool IsArena();
    bool IsBattleground();
    bool IsDungeon();
    bool IsEmpty();
    bool IsHeroic();
    bool IsRaid();
    TSString GetName();
    float GetHeight(float x, float y, uint32 phasemask);
    int32 GetDifficulty();
    uint32 GetInstanceId();
    uint32 GetPlayerCount();
    uint32 GetMapId();
    TSArray<TSPlayer> GetPlayers(uint32 team);
    uint32 GetAreaId(float x, float y, float z, float phasemask);
    TSWorldObject  GetWorldObject(uint64 guid);
    void SetWeather(uint32 zoneId, uint32 weatherType, float grade);
};
