#include "ScriptPCH.h"
#include "Group.h"

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
            Player* member = itr->getSource();

            if (!member || !member->GetSession())
                continue;

            ++i;
            Eluna::get()->PushUnsigned(L, i);
            Eluna::get()->PushUnit(L, member);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

    static int GetLeaderGUID(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Eluna::get()->PushGUID(L, group->GetLeaderGUID());
        return 1;
    }

    static int GetLeader(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Eluna::get()->PushUnit(L, sObjectAccessor->FindPlayer(group->GetLeaderGUID()));
        return 1;
    }

    static int GetUnitType(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Eluna::get()->PushString(L, "Group");
        return 1;
    }

    static int GetGUID(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Eluna::get()->PushGUID(L, group->GetGUID());
        return 1;
    }

    static int ChangeLeader(lua_State* L, Group* group)
    {
        if (!group)
        {
            Eluna::get()->PushBoolean(L, false);
            return 1;
        }

        Player* leader = Eluna::get()->CHECK_PLAYER(L, 1);
        if (leader)
        {
            group->ChangeLeader(leader->GetGUID());
            Eluna::get()->PushBoolean(L, true);
        }
        else
            Eluna::get()->PushBoolean(L, false);

        return 1;
    }

    static int IsLeader(lua_State* L, Group* group)
    {
        if (!group)
        {
            Eluna::get()->PushBoolean(L, false);
            return 1;
        }

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        if (!player)
            if (const char* name = luaL_checkstring(L, 1))
                player = sObjectAccessor->FindPlayerByName(name);

        if (player)
            Eluna::get()->PushBoolean(L, group->IsLeader(player->GetGUID()));
        else
            Eluna::get()->PushBoolean(L, false);
        return 1;
    }

    // SendPacket(packet, sendToPlayersInBattleground[, ignoreguid])
    static int SendPacket(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
        bool ignorePlayersInBg = luaL_checkbool(L, 2);
        uint32 ignore = luaL_optunsigned(L, 3, 0);

        if (data)
            group->BroadcastPacket(data, ignorePlayersInBg, -1, (ignore ? MAKE_NEW_GUID(ignore, 0, HIGHGUID_PLAYER) : 0));
        return 0;
    }

    static int AddInvite(lua_State* L, Group* group)
    {
        if (!group)
        {
            Eluna::get()->PushBoolean(L, false);
            return 1;
        }

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        if (player)
            Eluna::get()->PushBoolean(L, group->AddInvite(player));
        else
            Eluna::get()->PushBoolean(L, false);
        return 1;
    }

    static int RemoveMember(lua_State* L, Group* group)
    {
        if (!group)
        {
            Eluna::get()->PushBoolean(L, false);
            return 1;
        }

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        if (player)
            Eluna::get()->PushBoolean(L, group->RemoveMember(player->GetGUID()));
        else
            Eluna::get()->PushBoolean(L, false);
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
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, group->IsFull());
        return 1;
    }

    static int isLFGGroup(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, group->isLFGGroup());
        return 1;
    }

    static int isRaidGroup(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, group->isRaidGroup());
        return 1;
    }

    static int isBGGroup(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, group->isBGGroup());
        return 1;
    }

    static int isBFGroup(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, group->isBFGroup());
        return 1;
    }

    static int IsMember(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
        {
            Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
            if (player)
                Eluna::get()->PushBoolean(L, group->IsMember(player->GetGUID()));
            else
                Eluna::get()->PushBoolean(L, false);
        }
        return 1;
    }

    static int IsAssistant(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
        {
            Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
            if (player)
                Eluna::get()->PushBoolean(L, group->IsAssistant(player->GetGUID()));
            else
                Eluna::get()->PushBoolean(L, false);
        }
        return 1;
    }

    static int SameSubGroup(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
        {
            Player* player1 = Eluna::get()->CHECK_PLAYER(L, 1);
            Player* player2 = Eluna::get()->CHECK_PLAYER(L, 2);
            if (player1 && player2)
                Eluna::get()->PushBoolean(L, group->SameSubGroup(player1, player2));
            else
                Eluna::get()->PushBoolean(L, false);
        }
        return 1;
    }

    static int HasFreeSlotSubGroup(lua_State* L, Group* group)
    {
        if (!group)
            Eluna::get()->PushBoolean(L, false);
        else
        {
            uint8 subGroup = luaL_checkunsigned(L, 1);
            Eluna::get()->PushBoolean(L, group->HasFreeSlotSubGroup(subGroup));
        }
        return 1;
    }

    static int GetMemberGUID(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        const char* name = luaL_checkstring(L, 1);
        Eluna::get()->PushGUID(L, group->GetMemberGUID(name));
        return 1;
    }

    static int GetMembersCount(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Eluna::get()->PushUnsigned(L, group->GetMembersCount());
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

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        uint8 groupID = luaL_checkunsigned(L, 2);

        if (player)
            group->ChangeMembersGroup(player->GetGUID(), groupID);
        return 0;
    }

    static int GetMemberGroup(lua_State* L, Group* group)
    {
        if (!group)
            return 0;

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        Eluna::get()->PushUnsigned(L, group->GetMemberGroup(player->GetGUID()));
        return 1;
    }

};
#endif
