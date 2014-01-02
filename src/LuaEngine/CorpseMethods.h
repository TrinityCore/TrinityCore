/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
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