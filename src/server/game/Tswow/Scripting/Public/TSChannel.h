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

class TC_GAME_API TSChannel {
public:
    Channel* channel;
    TSChannel(Channel* channel);
    TSChannel();
    TSChannel* operator->() { return this;}
    TSString GetName(uint32 locale = 0);
    uint32 GetID();
    bool IsConstant();
    bool IsLFG();
    bool IsAnnounce();
    void SetAnnounce(bool announce);
    void SetDirty();
    void SetPassword(TSString password);
    bool CheckPassword(TSString password);
    uint32 GetNumPlayers();
    uint8 GetFlags();
    bool HasFlag(uint8 flag);
    void JoinChannel(TSPlayer player, TSString password = JSTR(""));
    void LeaveChannel(TSPlayer player, bool send = true);
    void SetInvisible(TSPlayer player, bool on);
    void SetOwner(uint64 guid, bool exclaim = true);
    void Say(uint64 guid, TSString what, uint32 lang);
};