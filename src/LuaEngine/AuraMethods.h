/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef AURAMETHODS_H
#define AURAMETHODS_H

namespace LuaAura
{
    int GetCaster(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetCaster());
        return 1;
    }

    int GetCasterGUID(lua_State* L, Aura* aura)
    {
#ifdef MANGOS
        sEluna->Push(L, aura->GetCasterGuid());
#else
        sEluna->Push(L, aura->GetCasterGUID());
#endif
        return 1;
    }

    int GetCasterLevel(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetCaster()->getLevel());
        return 1;
    }

    int GetDuration(lua_State* L, Aura* aura)
    {
#ifdef MANGOS
        sEluna->Push(L, aura->GetAuraDuration());
#else
        sEluna->Push(L, aura->GetDuration());
#endif
        return 1;
    }

    int GetCharges(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetStackAmount());
        return 1;
    }

    int GetAuraId(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetId());
        return 1;
    }

    int GetMaxDuration(lua_State* L, Aura* aura)
    {
#ifdef MANGOS
        sEluna->Push(L, aura->GetAuraMaxDuration());
#else
        sEluna->Push(L, aura->GetMaxDuration());
#endif
        return 1;
    }

    int GetStackAmount(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetStackAmount());
        return 1;
    }

    int GetOwner(lua_State* L, Aura* aura)
    {
#ifdef MANGOS
        sEluna->Push(L, aura->GetTarget());
#else
        sEluna->Push(L, aura->GetOwner());
#endif
        return 1;
    }

    int SetDuration(lua_State* L, Aura* aura)
    {
        int duration = sEluna->CHECKVAL<int>(L, 2);
#ifdef MANGOS
        aura->GetHolder()->SetAuraDuration(duration);
#else
        aura->SetDuration(duration);
#endif
        return 0;
    }

    int SetMaxDuration(lua_State* L, Aura* aura)
    {
        int duration = sEluna->CHECKVAL<int>(L, 2);
#ifdef MANGOS
        aura->GetHolder()->SetAuraMaxDuration(duration);
#else
        aura->SetMaxDuration(duration);
#endif
        return 0;
    }

    int SetStackAmount(lua_State* L, Aura* aura)
    {
        int amount = sEluna->CHECKVAL<int>(L, 2);
        int duration = sEluna->CHECKVAL<int>(L, 2);
#ifdef MANGOS
        aura->GetHolder()->SetStackAmount(amount);
#else
        aura->SetStackAmount(amount);
#endif
        return 0;
    }

    int Remove(lua_State* L, Aura* aura)
    {
        int duration = sEluna->CHECKVAL<int>(L, 2);
#ifdef MANGOS
        aura->GetHolder()->RemoveAura(aura->GetEffIndex());
#else
        aura->Remove();
#endif
        return 0;
    }
};
#endif
