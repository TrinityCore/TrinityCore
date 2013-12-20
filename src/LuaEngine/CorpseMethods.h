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

#ifndef CORPSEMETHODS_H
#define CORPSEMETHODS_H

namespace LuaCorpse
{
    // GetOwnerGUID()
    int GetOwnerGUID(lua_State* L, Corpse* corpse)
    {
        sEluna->Push(L, corpse->GetOwnerGUID());
        return 1;
    }

    // GetGhostTime()
    int GetGhostTime(lua_State* L, Corpse* corpse)
    {
        sEluna->Push(L, corpse->GetGhostTime());
        return 1;
    }

    // GetType()
    int GetType(lua_State* L, Corpse* corpse)
    {
        sEluna->Push(L, corpse->GetType());
        return 1;
    }

    // ResetGhostTime()
    int ResetGhostTime(lua_State* L, Corpse* corpse)
    {
        corpse->ResetGhostTime();
        return 0;
    }

    // SaveToDB()
    int SaveToDB(lua_State* L, Corpse* corpse)
    {
        corpse->SaveToDB();
        return 0;
    }

    // DeleteBonesFromWorld()
    int DeleteBonesFromWorld(lua_State* L, Corpse* corpse)
    {
        corpse->DeleteBonesFromWorld();
        return 0;
    }
};
#endif