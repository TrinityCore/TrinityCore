#ifndef GROUPMETHODS_H
#define GROUPMETHODS_H

class LuaGroup
{
public:

    static int GetMembers(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (GroupReference* itr = group->GetFirstMember(); itr; itr = itr->next())
        {
            Player* member = itr->GetSource();

            if (!member || !member->GetSession())
                continue;

            ++i;
            sEluna->PushUnsigned(L, i);
            sEluna->PushUnit(L, member);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

    static int GetLeaderGUID(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        sEluna->PushULong(L, group->GetLeaderGUID());
        return 1;
    }

    static int GetLeader(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        sEluna->PushUnit(L, sObjectAccessor->FindPlayer(group->GetLeaderGUID()));
        return 1;
    }

    static int GetUnitType(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        sEluna->PushString(L, "Group");
        return 1;
    }

    static int GetGUID(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        sEluna->PushULong(L, group->GetGUID());
        return 1;
    }

    static int ChangeLeader(lua_State* L, Group* group)
    {
        if (!group)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        Player* leader = sEluna->CHECK_PLAYER(L, 1);
        if (leader)
        {
            group->ChangeLeader(leader->GetGUID());
            sEluna->PushBoolean(L, true);
        }
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    static int IsLeader(lua_State* L, Group* group)
    {
        if (!group)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            if (const char* name = luaL_checkstring(L, 1))
                player = sObjectAccessor->FindPlayerByName(name);

        if (player)
            sEluna->PushBoolean(L, group->IsLeader(player->GetGUID()));
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    // SendPacket(packet, sendToPlayersInBattleground[, ignoreguid])
    static int SendPacket(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        bool ignorePlayersInBg = luaL_checkbool(L, 2);
        uint64 ignore = sEluna->CHECK_ULONG(L, 3);

        if (data)
            group->BroadcastPacket(data, ignorePlayersInBg, -1, ignore);
        return 0;
    }

    static int AddInvite(lua_State* L, Group* group)
    {
        if (!group)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (player)
            sEluna->PushBoolean(L, group->AddInvite(player));
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    static int RemoveMember(lua_State* L, Group* group)
    {
        if (!group)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }

        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (player)
            sEluna->PushBoolean(L, group->RemoveMember(player->GetGUID()));
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    static int Disband(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        group->Disband();
        return 0;
    }

    static int IsFull(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, group->IsFull());
        return 1;
    }

    static int isLFGGroup(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, group->isLFGGroup());
        return 1;
    }

    static int isRaidGroup(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, group->isRaidGroup());
        return 1;
    }

    static int isBGGroup(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, group->isBGGroup());
        return 1;
    }

    static int isBFGroup(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, group->isBFGroup());
        return 1;
    }

    static int IsMember(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
        {
            Player* player = sEluna->CHECK_PLAYER(L, 1);
            if (player)
                sEluna->PushBoolean(L, group->IsMember(player->GetGUID()));
            else
                sEluna->PushBoolean(L, false);
        }
        return 1;
    }

    static int IsAssistant(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
        {
            Player* player = sEluna->CHECK_PLAYER(L, 1);
            if (player)
                sEluna->PushBoolean(L, group->IsAssistant(player->GetGUID()));
            else
                sEluna->PushBoolean(L, false);
        }
        return 1;
    }

    static int SameSubGroup(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
        {
            Player* player1 = sEluna->CHECK_PLAYER(L, 1);
            Player* player2 = sEluna->CHECK_PLAYER(L, 2);
            if (player1 && player2)
                sEluna->PushBoolean(L, group->SameSubGroup(player1, player2));
            else
                sEluna->PushBoolean(L, false);
        }
        return 1;
    }

    static int HasFreeSlotSubGroup(lua_State* L, Group* group)
    {
        if (!group)
            sEluna->PushBoolean(L, false);
        else
        {
            uint8 subGroup = luaL_checkunsigned(L, 1);
            sEluna->PushBoolean(L, group->HasFreeSlotSubGroup(subGroup));
        }
        return 1;
    }

    static int GetMemberGUID(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        const char* name = luaL_checkstring(L, 1);
        sEluna->PushULong(L, group->GetMemberGUID(name));
        return 1;
    }

    static int GetMembersCount(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        sEluna->PushUnsigned(L, group->GetMembersCount());
        return 1;
    }

    static int ConvertToLFG(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        group->ConvertToLFG();
        return 0;
    }

    static int ConvertToRaid(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        group->ConvertToRaid();
        return 0;
    }

    static int ChangeMembersGroup(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Player* player = sEluna->CHECK_PLAYER(L, 1);
        uint8 groupID = luaL_checkunsigned(L, 2);

        if (player)
            group->ChangeMembersGroup(player->GetGUID(), groupID);
        return 0;
    }

    static int GetMemberGroup(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        sEluna->PushUnsigned(L, group->GetMemberGroup(player->GetGUID()));
        return 1;
    }

};
#endif
