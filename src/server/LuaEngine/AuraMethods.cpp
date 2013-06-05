#include "LuaEngine.h"
#include "AuraMethods.h"

int LuaAura::GetUnitType(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushString(L, "Aura");
    return 1;
}

int LuaAura::GetCaster(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushUnit(L, aura->GetCaster());
    return 1;
}

int LuaAura::GetCasterGUID(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushULong(L, aura->GetCasterGUID());
    return 1;
}

int LuaAura::GetCasterLevel(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushUnsigned(L, aura->GetCasterLevel());
    return 1;
}

int LuaAura::GetDuration(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushInteger(L, aura->GetDuration());
    return 1;
}

int LuaAura::GetCharges(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushUnsigned(L, aura->GetCharges());
    return 1;
}

int LuaAura::GetAuraId(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushUnsigned(L, aura->GetId());
    return 1;
}

int LuaAura::GetMaxDuration(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushInteger(L, aura->GetMaxDuration());
    return 1;
}

int LuaAura::GetStackAmount(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    sEluna->PushUnsigned(L, aura->GetStackAmount());
    return 1;
}

int LuaAura::SetDuration(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    int duration = luaL_checkinteger(L, 1);
    aura->SetDuration(duration, false);
    return 0;
}

int LuaAura::SetMaxDuration(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    int duration = luaL_checkinteger(L, 1);
    aura->SetMaxDuration(duration);
    return 0;
}

int LuaAura::SetStackAmount(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    int amount = luaL_checkunsigned(L, 1);
    aura->SetStackAmount(amount);
    return 0;
}

int LuaAura::Remove(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    aura->Remove();
    return 0;
}

int LuaAura::GetOwner(lua_State* L, Aura* aura)
{
    if (!aura)
        return 0;

    if (aura->GetType() != UNIT_AURA_TYPE)
        return 0;

    sEluna->PushUnit(L, aura->GetUnitOwner());
    return 1;
}
