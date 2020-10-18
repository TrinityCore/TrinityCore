/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef GROUPMETHODS_H
#define GROUPMETHODS_H

/***
 * Inherits all methods from: none
 */
namespace LuaGroup
{
    /**
     * Returns 'true' if the [Player] is the [Group] leader
     *
     * @param uint64 guid : guid of a possible leader
     * @return bool isLeader
     */
    int IsLeader(lua_State* L, Group* group)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        Eluna::Push(L, group->IsLeader(ObjectGuid(guid)));
        return 1;
    }

    /**
     * Returns 'true' if the [Group] is full
     *
     * @return bool isFull
     */
    int IsFull(lua_State* L, Group* group)
    {
        Eluna::Push(L, group->IsFull());
        return 1;
    }

    /**
     * Returns 'true' if the [Group] is a raid [Group]
     *
     * @return bool isRaid
     */
    int IsRaidGroup(lua_State* L, Group* group)
    {
        Eluna::Push(L, group->isRaidGroup());
        return 1;
    }

    /**
     * Returns 'true' if the [Group] is a battleground [Group]
     *
     * @return bool isBG
     */
    int IsBGGroup(lua_State* L, Group* group)
    {
        Eluna::Push(L, group->isBGGroup());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is a member of this [Group]
     *
     * @param uint64 guid : guid of a player
     * @return bool isMember
     */
    int IsMember(lua_State* L, Group* group)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        Eluna::Push(L, group->IsMember(ObjectGuid(guid)));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is an assistant of this [Group]
     *
     * @param uint64 guid : guid of a player
     * @return bool isAssistant
     */
    int IsAssistant(lua_State* L, Group* group)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        Eluna::Push(L, group->IsAssistant(ObjectGuid(guid)));
        return 1;
    }

    /**
     * Returns 'true' if the [Player]s are in the same subgroup in this [Group]
     *
     * @param [Player] player1 : first [Player] to check
     * @param [Player] player2 : second [Player] to check
     * @return bool sameSubGroup
     */
    int SameSubGroup(lua_State* L, Group* group)
    {
        Player* player1 = Eluna::CHECKOBJ<Player>(L, 2);
        Player* player2 = Eluna::CHECKOBJ<Player>(L, 3);
        Eluna::Push(L, group->SameSubGroup(player1, player2));
        return 1;
    }

    /**
     * Returns 'true' if the subgroup has free slots in this [Group]
     *
     * @param uint8 subGroup : subGroup ID to check
     * @return bool hasFreeSlot
     */
    int HasFreeSlotSubGroup(lua_State* L, Group* group)
    {
        uint8 subGroup = Eluna::CHECKVAL<uint8>(L, 2);

        if (subGroup >= MAX_RAID_SUBGROUPS)
        {
            luaL_argerror(L, 2, "valid subGroup ID expected");
            return 0;
        }

        Eluna::Push(L, group->HasFreeSlotSubGroup(subGroup));
        return 1;
    }

    /**
     * Adds a new member to the [Group]
     *
     * @param [Player] player : [Player] to add to the group
     * @return bool added : true if member was added
     */
    int AddMember(lua_State* L, Group* group)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);

        if (player->GetGroup() || !group->IsCreated() || group->IsFull())
        {
            Eluna::Push(L, false);
            return 1;
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

        Eluna::Push(L, success);
        return 1;
    }

    /*int IsLFGGroup(lua_State* L, Group* group) // TODO: Implementation
    {
        Eluna::Push(L, group->isLFGGroup());
        return 1;
    }*/

    /*int IsBFGroup(lua_State* L, Group* group) // TODO: Implementation
    {
        Eluna::Push(L, group->isBFGroup());
        return 1;
    }*/

    /**
     * Returns a table with the [Player]s in this [Group]
     *
     * @return table groupPlayers : table of [Player]s
     */
    int GetMembers(lua_State* L, Group* group)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (GroupReference* itr = group->GetFirstMember(); itr; itr = itr->next())
        {
#if defined TRINITY || AZEROTHCORE
            Player* member = itr->GetSource();
#else
            Player* member = itr->getSource();
#endif

            if (!member || !member->GetSession())
                continue;

            Eluna::Push(L, member);
            lua_rawseti(L, tbl, ++i);
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

    /**
     * Returns [Group] leader GUID
     *
     * @return uint64 leaderGUID
     */
    int GetLeaderGUID(lua_State* L, Group* group)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, group->GetLeaderGUID());
#else
        Eluna::Push(L, group->GetLeaderGuid());
#endif
        return 1;
    }

    /**
     * Returns the [Group]'s GUID
     *
     * @return uint64 groupGUID
     */
    int GetGUID(lua_State* L, Group* group)
    {
#ifdef CLASSIC
        Eluna::Push(L, group->GetId());
#else
        Eluna::Push(L, group->GET_GUID());
#endif
        return 1;
    }

    /**
     * Returns a [Group] member's GUID by their name
     *
     * @param string name : the [Player]'s name
     * @return uint64 memberGUID
     */
    int GetMemberGUID(lua_State* L, Group* group)
    {
        const char* name = Eluna::CHECKVAL<const char*>(L, 2);
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, group->GetMemberGUID(name));
#else
        Eluna::Push(L, group->GetMemberGuid(name));
#endif
        return 1;
    }

    /**
     * Returns the member count of this [Group]
     *
     * @return uint32 memberCount
     */
    int GetMembersCount(lua_State* L, Group* group)
    {
        Eluna::Push(L, group->GetMembersCount());
        return 1;
    }

    /**
     * Returns the [Player]'s subgroup ID of this [Group]
     *
     * @param uint64 guid : guid of the player
     * @return uint8 subGroupID : a valid subgroup ID or MAX_RAID_SUBGROUPS+1
     */
    int GetMemberGroup(lua_State* L, Group* group)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        Eluna::Push(L, group->GetMemberGroup(ObjectGuid(guid)));
        return 1;
    }

    /**
     * Sets the leader of this [Group]
     *
     * @param uint64 guid : guid of the new leader
     */
    int SetLeader(lua_State* L, Group* group)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        group->ChangeLeader(ObjectGuid(guid));
        group->SendUpdate();
        return 0;
    }

    /**
     * Sends a specified [WorldPacket] to this [Group]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to send
     * @param bool ignorePlayersInBg : ignores [Player]s in a battleground
     * @param uint64 ignore : ignore a [Player] by their GUID
     */
    int SendPacket(lua_State* L, Group* group)
    {
        WorldPacket* data = Eluna::CHECKOBJ<WorldPacket>(L, 2);
        bool ignorePlayersInBg = Eluna::CHECKVAL<bool>(L, 3);
        uint64 ignore = Eluna::CHECKVAL<uint64>(L, 4);

#ifdef CMANGOS
        group->BroadcastPacket(*data, ignorePlayersInBg, -1, ObjectGuid(ignore));
#else
        group->BroadcastPacket(data, ignorePlayersInBg, -1, ObjectGuid(ignore));
#endif
        return 0;
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
     * };
     * </pre>
     *
     * @param uint64 guid : guid of the player to remove
     * @param [RemoveMethod] method : method used to remove the player
     * @return bool removed
     */
    int RemoveMember(lua_State* L, Group* group)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        uint32 method = Eluna::CHECKVAL<uint32>(L, 3, 0);

#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, group->RemoveMember(ObjectGuid(guid), (RemoveMethod)method));
#else
        Eluna::Push(L, group->RemoveMember(ObjectGuid(guid), method));
#endif
        return 1;
    }

    /**
     * Disbands this [Group]
     *
     */
    int Disband(lua_State* /*L*/, Group* group)
    {
        group->Disband();
        return 0;
    }

    /**
     * Converts this [Group] to a raid [Group]
     *
     */
    int ConvertToRaid(lua_State* /*L*/, Group* group)
    {
        group->ConvertToRaid();
        return 0;
    }

    /**
     * Sets the member's subGroup
     *
     * @param uint64 guid : guid of the player to move
     * @param uint8 groupID : the subGroup's ID
     */
    int SetMembersGroup(lua_State* L, Group* group)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        uint8 subGroup = Eluna::CHECKVAL<uint8>(L, 3);

        if (subGroup >= MAX_RAID_SUBGROUPS)
        {
            luaL_argerror(L, 3, "valid subGroup ID expected");
            return 0;
        }

        if (!group->HasFreeSlotSubGroup(subGroup))
            return 0;

        group->ChangeMembersGroup(ObjectGuid(guid), subGroup);
        return 0;
    }

    /**
     * Sets the target icon of an object for the [Group]
     *
     * @param uint8 icon : the icon (Skull, Square, etc)
     * @param uint64 target : GUID of the icon target, 0 is to clear the icon
     * @param uint64 setter : GUID of the icon setter
     */
    int SetTargetIcon(lua_State* L, Group* group)
    {
        uint8 icon = Eluna::CHECKVAL<uint8>(L, 2);
        uint64 target = Eluna::CHECKVAL<uint64>(L, 3);
        uint64 setter = Eluna::CHECKVAL<uint64>(L, 4, 0);

        if (icon >= TARGETICONCOUNT)
            return luaL_argerror(L, 2, "valid target icon expected");

#if (defined(CLASSIC) || defined(TBC))
        group->SetTargetIcon(icon, ObjectGuid(target));
#else
        group->SetTargetIcon(icon, ObjectGuid(setter), ObjectGuid(target));
#endif
        return 0;
    }

    /*int ConvertToLFG(lua_State* L, Group* group) // TODO: Implementation
    {
        group->ConvertToLFG();
        return 0;
    }*/
};

#endif
