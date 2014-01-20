/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef GROUPMETHODS_H
#define GROUPMETHODS_H

namespace LuaGroup
{
    int GetMembers(lua_State* L, Group* group)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (GroupReference* itr = group->GetFirstMember(); itr; itr = itr->next())
        {
            Player* member = itr->GetSource();

            if (!member || !member->GetSession())
                continue;

            ++i;
            sEluna->Push(L, i);
            sEluna->Push(L, member);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

    int GetLeaderGUID(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->GetLeaderGUID());
        return 1;
    }

    int GetLeader(lua_State* L, Group* group)
    {
        sEluna->Push(L, sObjectAccessor->FindPlayer(group->GetLeaderGUID()));
        return 1;
    }

    int GetGUID(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->GetGUID());
        return 1;
    }

    int ChangeLeader(lua_State* L, Group* group)
    {
        Player* leader = sEluna->CHECK_PLAYER(L, 1);
        if (!leader)
            return 0;

        group->ChangeLeader(leader->GetGUID());
        sEluna->Push(L, true);
        return 1;
    }

    int IsLeader(lua_State* L, Group* group)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            if (const char* name = luaL_checkstring(L, 1))
                player = sObjectAccessor->FindPlayerByName(name);
        if (!player)
            return 0;

        sEluna->Push(L, group->IsLeader(player->GetGUID()));
        return 1;
    }

    // SendPacket(packet, sendToPlayersInBattleground[, ignoreguid])
    int SendPacket(lua_State* L, Group* group)
    {
        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        bool ignorePlayersInBg = luaL_checkbool(L, 2);
        uint64 ignore = sEluna->CHECK_ULONG(L, 3);

        if (data)
            group->BroadcastPacket(data, ignorePlayersInBg, -1, ignore);
        return 0;
    }

    int AddInvite(lua_State* L, Group* group)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        sEluna->Push(L, group->AddInvite(player));
        return 1;
    }

    int RemoveMember(lua_State* L, Group* group)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        int method = luaL_optint(L, 2, 0);
        if (!player)
            return 0;

        sEluna->Push(L, group->RemoveMember(player->GetGUID(), (RemoveMethod)method));
        return 1;
    }

    int Disband(lua_State* L, Group* group)
    {
        group->Disband();
        return 0;
    }

    int IsFull(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->IsFull());
        return 1;
    }

    int isLFGGroup(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->isLFGGroup());
        return 1;
    }

    int isRaidGroup(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->isRaidGroup());
        return 1;
    }

    int isBGGroup(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->isBGGroup());
        return 1;
    }

    int isBFGroup(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->isBFGroup());
        return 1;
    }

    int IsMember(lua_State* L, Group* group)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;
        sEluna->Push(L, group->IsMember(player->GetGUID()));
        return 1;
    }

    int IsAssistant(lua_State* L, Group* group)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        sEluna->Push(L, group->IsAssistant(player->GetGUID()));
        return 1;
    }

    int SameSubGroup(lua_State* L, Group* group)
    {
        Player* player1 = sEluna->CHECK_PLAYER(L, 1);
        Player* player2 = sEluna->CHECK_PLAYER(L, 2);
        if (!player1 || !player2)
            return 0;
        sEluna->Push(L, group->SameSubGroup(player1, player2));
        return 1;
    }

    int HasFreeSlotSubGroup(lua_State* L, Group* group)
    {
        uint8 subGroup = luaL_checkunsigned(L, 1);
        sEluna->Push(L, group->HasFreeSlotSubGroup(subGroup));
        return 1;
    }

    int GetMemberGUID(lua_State* L, Group* group)
    {
        const char* name = luaL_checkstring(L, 1);
        sEluna->Push(L, group->GetMemberGUID(name));
        return 1;
    }

    int GetMembersCount(lua_State* L, Group* group)
    {
        sEluna->Push(L, group->GetMembersCount());
        return 1;
    }

    int ConvertToLFG(lua_State* L, Group* group)
    {
        group->ConvertToLFG();
        return 0;
    }

    int ConvertToRaid(lua_State* L, Group* group)
    {
        group->ConvertToRaid();
        return 0;
    }

    int ChangeMembersGroup(lua_State* L, Group* group)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        uint8 groupID = luaL_checkunsigned(L, 2);

        if (player)
            group->ChangeMembersGroup(player->GetGUID(), groupID);
        return 0;
    }

    int GetMemberGroup(lua_State* L, Group* group)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        sEluna->Push(L, group->GetMemberGroup(player->GetGUID()));
        return 1;
    }
};
#endif
