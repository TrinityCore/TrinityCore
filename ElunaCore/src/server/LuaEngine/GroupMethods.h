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
		int i = 0;
        
        for (GroupReference* itr = group->GetFirstMember(); itr; itr = itr->next())
        {
            Player* member = itr->getSource();

            if (!member || !member->GetSession())
                continue;

            i++;
            lua_pushnumber(L, i);
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
        
        Eluna::get()->PushUnsigned(L, GUID_LOPART(group->GetLeaderGUID()));
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

        Eluna::get()->PushUnsigned(L, GUID_LOPART(group->GetGUID()));
        return 1;
    }

    static int ChangeLeader(lua_State* L, Group* group)
    {
        if(!group)
            return 0;

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
            return 0;
        
        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        if(player)
            Eluna::get()->PushBoolean(L, (player->GetGUID() == group->GetLeaderGUID()));
        else
            Eluna::get()->PushBoolean(L, false);
        return 1;
    }

};
#endif
