/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef QUESTMETHODS_H
#define QUESTMETHODS_H

namespace LuaQuest
{
    int GetId(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetQuestId());
        return 1;
    }

    int GetLevel(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetQuestLevel());
        return 1;
    }

    int GetMaxLevel(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetMaxLevel());
        return 1;
    }

    int GetMinLevel(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetMinLevel());
        return 1;
    }

    int GetNextQuestId(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetNextQuestId());
        return 1;
    }

    int GetPrevQuestId(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetPrevQuestId());
        return 1;
    }

    int GetNextQuestInChain(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetNextQuestInChain());
        return 1;
    }

    int GetFlags(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetFlags());
        return 1;
    }

    int GetType(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->GetType());
        return 1;
    }

    int HasFlag(lua_State* L, Quest* quest)
    {
        uint32 flag = luaL_checkunsigned(L, 1);
        sEluna->Push(L, quest->HasFlag(flag));
        return 1;
    }

    int IsDaily(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->IsDaily());
        return 1;
    }

    int IsRepeatable(lua_State* L, Quest* quest)
    {
        sEluna->Push(L, quest->IsRepeatable());
        return 1;
    }

    int SetFlag(lua_State* L, Quest* quest)
    {
        uint32 flag = luaL_checkunsigned(L, 1);
        quest->SetSpecialFlag((QuestSpecialFlags)flag);
        return 0;
    }
};
#endif