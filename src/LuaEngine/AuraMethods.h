/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 * Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
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
        sEluna->Push(L, aura->GetCasterGUID());
        return 1;
    }

    int GetCasterLevel(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetCaster()->getLevel());
        return 1;
    }

    int GetDuration(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetDuration());
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
        sEluna->Push(L, aura->GetMaxDuration());
        return 1;
    }

    int GetStackAmount(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetStackAmount());
        return 1;
    }

    int SetDuration(lua_State* L, Aura* aura)
    {
        int duration = luaL_checkinteger(L, 1);
        aura->SetDuration(duration);
        return 0;
    }

    int SetMaxDuration(lua_State* L, Aura* aura)
    {
        int duration = luaL_checkinteger(L, 1);
        aura->SetMaxDuration(duration);
        return 0;
    }

    int SetStackAmount(lua_State* L, Aura* aura)
    {
        int amount = luaL_checkunsigned(L, 1);
        aura->SetStackAmount(amount);
        return 0;
    }

    int Remove(lua_State* L, Aura* aura)
    {
        aura->Remove();
        return 0;
    }

    int GetOwner(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetOwner());
        return 1;
    }
};
#endif
