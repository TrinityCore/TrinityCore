#include "ScriptPCH.h"
#include "Group.h"

#ifndef GROUPMETHODS_H
#define GROUPMETHODS_H

class LuaGroup
{
public:

    static int GetMembers(lua_State* L, Group* group)
    {
        if(!group)
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
        if(!group)
            return 0;

        Eluna::get()->PushGUID(L, group->GetLeaderGUID());
        return 1;
    }

    static int GetLeader(lua_State* L, Group* group)
    {
        if(!group)
            return 0;

        Eluna::get()->PushUnit(L, sObjectAccessor->FindPlayer(group->GetLeaderGUID()));
        return 1;
    }

    static int GetUnitType(lua_State* L, Group* group)
    {
        if(!group)
            return 0;

        Eluna::get()->PushString(L, "Group");
        return 1;
    }

    static int GetGUID(lua_State* L, Group* group)
    {
        if(!group)
            return 0;

        Eluna::get()->PushGUID(L, group->GetGUID());
        return 1;
    }

    static int ChangeLeader(lua_State* L, Group* group)
    {
        if(!group)
        {
            Eluna::get()->PushBoolean(L, false);
            return 1;
        }

        Player* leader = Eluna::get()->CHECK_PLAYER(L, 1);
        if(leader)
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
        if(!group)
        {
            Eluna::get()->PushBoolean(L, false);
            return 1;
        }

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        if(!player)
            if(const char* name = luaL_checkstring(L, 1))
                player = sObjectAccessor->FindPlayerByName(name);

        if(player)
            Eluna::get()->PushBoolean(L, (player->GetGUID() == group->GetLeaderGUID()));
        else
            Eluna::get()->PushBoolean(L, false);
        return 1;
    }

	// SendPacket(packet, sendToPlayersInBattleground[, ignoreguid])
	static int SendPacket(lua_State* L, Group* group)
	{
        if(!group)
            return 0;

		WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
		bool ignorePlayersInBg = lua_toboolean(L, 2);
		uint32 ignore = luaL_optunsigned(L, 3, 0);

		if (data)
			group->BroadcastPacket(data, ignorePlayersInBg, -1, (ignore ? MAKE_NEW_GUID(ignore, 0, HIGHGUID_PLAYER) : 0));
		return 0;
	}

};
#endif
