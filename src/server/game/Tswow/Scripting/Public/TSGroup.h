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
#include "TSArray.h"
#include "TSClasses.h"

class TC_GAME_API TSGroup {
public:
    Group* group;
    TSGroup(Group* group);
    TSGroup();
    TSGroup* operator->() { return this;}
    bool IsNull() { return group == nullptr; };
    bool IsLeader(uint64 guid);
    bool IsFull();
    bool IsRaidGroup();
    bool IsBGGroup();
    bool IsMember(uint64 guid);
    bool IsAssistant(uint64 guid);
    bool SameSubGroup(TSPlayer player1, TSPlayer player2);
    bool HasFreeSlotSubGroup(uint8 subGroup);
    bool AddMember(TSPlayer player);
    TSArray<TSPlayer> GetMembers();
    uint64 GetLeaderGUID();
    uint64 GetGUID();
    uint64 GetMemberGUID(TSString name);
    uint32 GetMembersCount();
    uint8 GetMemberGroup(uint64 guid);
    void SetLeader(uint64 guid);
    void SendPacket(TSWorldPacket data, bool ignorePlayersInBg, uint64 ignore);
    void SendPacket(std::shared_ptr<TSWorldPacket> data, bool ignorePlayersInBg, uint64 ignore);
    bool RemoveMember(uint64 guid, uint32 method);
    void Disband();
    void ConvertToRaid();
    void SetMembersGroup(uint64 guid, uint8 subGroup);
    void SetTargetIcon(uint8 icon, uint64 target, uint64 setter);
    bool IsLFGGroup();
    bool IsBFGroup();
};
