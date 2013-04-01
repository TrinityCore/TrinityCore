#ifndef AURAMETHODS_H
#define AURAMETHODS_H

class LuaAura
{
public:
    // GetUnitType()
    static int GetUnitType(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushString(L, "Aura");
        return 1;
    }

    // GetCaster()
    static int GetCaster(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushUnit(L, aura->GetCaster());
        return 1;
    }

    // GetCasterGUID()
    static int GetCasterGUID(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushULong(L, aura->GetCasterGUID());
        return 1;
    }

    // GetCasterLevel()
    static int GetCasterLevel(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushUnsigned(L, aura->GetCasterLevel());
        return 1;
    }

    // GetDuration()
    static int GetDuration(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushInteger(L, aura->GetDuration());
        return 1;
    }

    // GetCharges()
    static int GetCharges(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushUnsigned(L, aura->GetCharges());
        return 1;
    }

    // GetAuraId()
    static int GetAuraId(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushUnsigned(L, aura->GetId());
        return 1;
    }

    // GetMaxDuration()
    static int GetMaxDuration(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushInteger(L, aura->GetMaxDuration());
        return 1;
    }

    // GetStackAmount()
    static int GetStackAmount(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        sEluna->PushUnsigned(L, aura->GetStackAmount());
        return 1;
    }

    // SetDuration()
    static int SetDuration(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        int duration = luaL_checkinteger(L, 1);
        aura->SetDuration(duration, false);
        return 0;
    }

    // SetMaxDuration()
    static int SetMaxDuration(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        int duration = luaL_checkinteger(L, 1);
        aura->SetMaxDuration(duration);
        return 0;
    }

    // SetStackAmount()
    static int SetStackAmount(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        int amount = luaL_checkunsigned(L, 1);
        aura->SetStackAmount(amount);
        return 0;
    }

    // Remove()
    static int Remove(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        aura->Remove();
        return 0;
    }

    // GetOwner()
    static int GetOwner(lua_State* L, Aura* aura)
    {
        if (!aura)
            return 0;

        if (aura->GetType() != UNIT_AURA_TYPE)
            return 0;

        sEluna->PushUnit(L, aura->GetUnitOwner());
        return 1;
    }
};
#endif
