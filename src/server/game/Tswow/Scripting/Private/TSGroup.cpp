/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
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
#include <memory.h>
#include "Object.h"
#include "Group.h"
#include "TSPlayer.h"
#include "TSWorldPacket.h"
#include "TSIncludes.h"
#include "TSGroup.h"

TSGroup::TSGroup(Group *group)
{
    this->group = group;
}

TSGroup::TSGroup()
{
    this->group = nullptr;
}

/**
 * Returns 'true' if the [Player] is the [Group] leader
 *
 * @param uint64 guid : guid of a possible leader
 * @return bool isLeader
 */
bool TSGroup::IsLeader(uint64 guid) 
{
    return group->IsLeader(ObjectGuid(guid));
}
    
/**
 * Returns 'true' if the [Group] is full
 *
 * @return bool isFull
 */
bool TSGroup::IsFull() 
{
    return group->IsFull();
}
    
/**
 * Returns 'true' if the [Group] is a raid [Group]
 *
 * @return bool isRaid
 */
bool TSGroup::IsRaidGroup() 
{
    return group->isRaidGroup();
}
    
/**
 * Returns 'true' if the [Group] is a battleground [Group]
 *
 * @return bool isBG
 */
bool TSGroup::IsBGGroup() 
{
    return group->isBGGroup();
}
    
/**
 * Returns 'true' if the [Player] is a member of this [Group]
 *
 * @param uint64 guid : guid of a player
 * @return bool isMember
 */
bool TSGroup::IsMember(uint64 guid) 
{
    return group->IsMember(ObjectGuid(guid));
}
    
/**
 * Returns 'true' if the [Player] is an assistant of this [Group]
 *
 * @param uint64 guid : guid of a player
 * @return bool isAssistant
 */
bool TSGroup::IsAssistant(uint64 guid) 
{
    return group->IsAssistant(ObjectGuid(guid));
}
    
/**
 * Returns 'true' if the [Player]s are in the same subgroup in this [Group]
 *
 * @param [Player] player1 : first [Player] to check
 * @param [Player] player2 : second [Player] to check
 * @return bool sameSubGroup
 */
bool TSGroup::SameSubGroup(TSPlayer _player1,TSPlayer _player2)
{
    auto player1 = _player1.player;
    auto player2 = _player2.player;
    return group->SameSubGroup(player1, player2);
}
    
/**
 * Returns 'true' if the subgroup has free slots in this [Group]
 *
 * @param uint8 subGroup : subGroup ID to check
 * @return bool hasFreeSlot
 */
bool TSGroup::HasFreeSlotSubGroup(uint8 subGroup) 
{
    
    if (subGroup >= MAX_RAID_SUBGROUPS)
    {
    }
    return group->HasFreeSlotSubGroup(subGroup);
}
    
/**
 * Adds a new member to the [Group]
 *
 * @param [Player] player : [Player] to add to the group
 * @return bool added : true if member was added
 */
bool TSGroup::AddMember(TSPlayer _player)
{
    auto player = _player.player;
    
    if (player->GetGroup() || !group->IsCreated() || group->IsFull())
    {
        return false;
    }
    
    if (player->GetGroupInvite())
        player->UninviteFromGroup();
    
#if defined TRINITY || AZEROTHCORE
    bool success = group->AddMember(player);
    if (success)
        group->BroadcastGroupUpdate();
#else
    bool success = group->AddMember(player->GetObjectGuid(), player->GetName());
#endif
    return success;
}
    
bool TSGroup::IsLFGGroup()
{
    return group->isLFGGroup();
}

bool TSGroup::IsBFGroup()
{
    return group->isBFGroup();
}
    
/**
 * Returns a table with the [Player]s in this [Group]
 *
 * @return table groupPlayers : table of [Player]s
 */
TSArray<TSPlayer> TSGroup::GetMembers() 
{
    TSArray<TSPlayer> tbl;
    uint32 i = 0;
    
    for (GroupReference* itr = group->GetFirstMember(); itr; itr = itr->next())
    {
#if defined TRINITY || AZEROTHCORE
        Player* member = itr->GetSource();
#else
        Player* member = itr->getSource();
#endif
    
        if (member && member->GetSession()) tbl.push(TSPlayer(member));
    }

    return tbl;
}
    
/**
 * Returns [Group] leader GUID
 *
 * @return uint64 leaderGUID
 */
uint64 TSGroup::GetLeaderGUID() 
{
#if defined TRINITY || AZEROTHCORE
    return group->GetLeaderGUID();
#else
    return group->GetLeaderGuid();
#endif
}
    
/**
 * Returns the [Group]'s GUID
 *
 * @return uint64 groupGUID
 */
uint64 TSGroup::GetGUID() 
{
#ifdef CLASSIC
    return group->GetId();
#else
    return group->TS_GET_GUID();
#endif
}
    
/**
 * Returns a [Group] member's GUID by their name
 *
 * @param string name : the [Player]'s name
 * @return uint64 memberGUID
 */
uint64 TSGroup::GetMemberGUID(TSString name) 
{
#if defined TRINITY || AZEROTHCORE
    return group->GetMemberGUID(name._value);
#else
    return group->GetMemberGuid(name._value);
#endif
}
    
/**
 * Returns the member count of this [Group]
 *
 * @return uint32 memberCount
 */
uint32 TSGroup::GetMembersCount() 
{
    return group->GetMembersCount();
}
    
/**
 * Returns the [Player]'s subgroup ID of this [Group]
 *
 * @param uint64 guid : guid of the player
 * @return uint8 subGroupID : a valid subgroup ID or MAX_RAID_SUBGROUPS+1
 */
uint8 TSGroup::GetMemberGroup(uint64 guid) 
{
    return group->GetMemberGroup(ObjectGuid(guid));
}
    
/**
 * Sets the leader of this [Group]
 *
 * @param uint64 guid : guid of the new leader
 */
void TSGroup::SetLeader(uint64 guid) 
{
    group->ChangeLeader(ObjectGuid(guid));
    group->SendUpdate();
}

void TSGroup::SendPacket(std::shared_ptr<TSWorldPacket> _data,bool ignorePlayersInBg,uint64 ignore)
{
    SendPacket(*_data,ignorePlayersInBg,ignore);
}
    
/**
 * Sends a specified [WorldPacket] to this [Group]
 *
 * @param [WorldPacket] packet : the [WorldPacket] to send
 * @param bool ignorePlayersInBg : ignores [Player]s in a battleground
 * @param uint64 ignore : ignore a [Player] by their GUID
 */
void TSGroup::SendPacket(TSWorldPacket _data,bool ignorePlayersInBg,uint64 ignore)
{
    auto data = _data.packet;
    
#ifdef CMANGOS
    group->BroadcastPacket(*data, ignorePlayersInBg, -1, ObjectGuid(ignore));
#else
    group->BroadcastPacket(data, ignorePlayersInBg, -1, ObjectGuid(ignore));
#endif
}
    
/**
 * Removes a [Player] from this [Group] and returns 'true' if successful
 *
 * <pre>
 * enum RemoveMethod
 * {
 *     GROUP_REMOVEMETHOD_DEFAULT  = 0,
 *     GROUP_REMOVEMETHOD_KICK     = 1,
 *     GROUP_REMOVEMETHOD_LEAVE    = 2,
 *     GROUP_REMOVEMETHOD_KICK_LFG = 3
 * </pre>
 *
 * @param uint64 guid : guid of the player to remove
 * @param [RemoveMethod] method : method used to remove the player
 * @return bool removed
 */
bool TSGroup::RemoveMember(uint64 guid,uint32 method) 
{
    
#if defined TRINITY || AZEROTHCORE
    return group->RemoveMember(ObjectGuid(guid), (RemoveMethod)method);
#else
    return group->RemoveMember(ObjectGuid(guid), method);
#endif
}
    
/**
 * Disbands this [Group]
 *
 */
void TSGroup::Disband() 
{
    group->Disband();
}
    
/**
 * Converts this [Group] to a raid [Group]
 *
 */
void TSGroup::ConvertToRaid() 
{
    group->ConvertToRaid();
}
    
/**
 * Sets the member's subGroup
 *
 * @param uint64 guid : guid of the player to move
 * @param uint8 groupID : the subGroup's ID
 */
void TSGroup::SetMembersGroup(uint64 guid,uint8 subGroup) 
{
    
    if (subGroup >= MAX_RAID_SUBGROUPS)
    {
    }
    
    
    group->ChangeMembersGroup(ObjectGuid(guid), subGroup);
}
    
/**
 * Sets the target icon of an object for the [Group]
 *
 * @param uint8 icon : the icon (Skull, Square, etc)
 * @param uint64 target : GUID of the icon target, 0 is to clear the icon
 * @param uint64 setter : GUID of the icon setter
 */
void TSGroup::SetTargetIcon(uint8 icon,uint64 target,uint64 setter) 
{
    
    
#if (defined(CLASSIC) || defined(TBC))
    group->SetTargetIcon(icon, ObjectGuid(target));
#else
    group->SetTargetIcon(icon, ObjectGuid(setter), ObjectGuid(target));
#endif
}
    
/*int TSGroup::ConvertToLFG(lua_State* L, Group* group) // TODO: Implementation
{
    group->ConvertToLFG();
}*/