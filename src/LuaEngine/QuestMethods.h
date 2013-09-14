#ifndef QUESTMETHODS_H
#define QUESTMETHODS_H

class LuaQuest
{
public:
    // :GetUnitType()
    static int GetUnitType(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        lua_pushstring(L, "Quest");
        return 1;
    }

    // :GetId()
    static int GetId(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushUnsigned(L, quest->GetQuestId());
        return 1;
    }

    // :GetLevel()
    static int GetLevel(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushInteger(L, quest->GetQuestLevel());
        return 1;
    }

    // :GetMaxLevel()
    static int GetMaxLevel(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushUnsigned(L, quest->GetMaxLevel());
        return 1;
    }

    // :GetMinLevel()
    static int GetMinLevel(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushUnsigned(L, quest->GetMinLevel());
        return 1;
    }

    // :GetNextQuestId()
    static int GetNextQuestId(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushInteger(L, quest->GetNextQuestId());
        return 1;
    }

    // :GetPrevQuestId()
    static int GetPrevQuestId(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushInteger(L, quest->GetPrevQuestId());
        return 1;
    }

    // :GetNextQuestInChain()
    static int GetNextQuestInChain(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushInteger(L, quest->GetNextQuestInChain());
        return 1;
    }

    // :GetFlags()
    static int GetFlags(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushUnsigned(L, quest->GetFlags());
        return 1;
    }

    // :GetType()
    static int GetType(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushUnsigned(L, quest->GetType());
        return 1;
    }

    // :HasFlag(flag)
    static int HasFlag(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        uint32 flag = luaL_checkunsigned(L, 1);
        sEluna->PushBoolean(L, quest->HasFlag(flag));
        return 1;
    }

    // :IsDaily()
    static int IsDaily(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushBoolean(L, quest->IsDaily());
        return 1;
    }

    // :IsRepeatable()
    static int IsRepeatable(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        sEluna->PushBoolean(L, quest->IsRepeatable());
        return 1;
    }

    // :SetFlag(flag)
    static int SetFlag(lua_State* L, Quest* quest)
    {
        if (!quest)
            return 0;

        uint32 flag = luaL_checkunsigned(L, 1);
        quest->SetFlag(flag);
        return 0;
    }
};
#endif