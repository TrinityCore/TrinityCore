/* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef CORPSEMETHODS_H
#define CORPSEMETHODS_H

class LuaCorpse
{
public:
    // GetOwnerGUID() [CORPSE_FIELD_OWNER]
    static int GetOwnerGUID(lua_State* L, Corpse* corpse)
    {
        if (!corpse)
            return 0;
        sEluna->PushULong(L, corpse->GetOwnerGUID());
        return 1;
    }

    // GetGhostTime()
    static int GetGhostTime(lua_State* L, Corpse* corpse)
    {
        if (!corpse)
            return 0;
        sEluna->PushUnsigned(L, corpse->GetGhostTime());
        return 1;
    }

    // GetType()
    static int GetType(lua_State* L, Corpse* corpse)
    {
        if (!corpse)
            return 0;
        sEluna->PushUnsigned(L, corpse->GetType());
        return 1;
    }

    // Create(map)
    static int Create(lua_State* L, Corpse* corpse)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player || !corpse)
            return 0;
        if (corpse->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_CORPSE), player))
            return 0;
        return 0;
    }

    // ResetGhostTime()
    static int ResetGhostTime(lua_State* L, Corpse* corpse)
    {
        if (!corpse)
            return 0;
        corpse->ResetGhostTime();
        return 0;
    }

    // SaveToDB()
    static int SaveToDB(lua_State* L, Corpse* corpse)
    {
        if (!corpse)
            return 0;
        corpse->SaveToDB();
        return 0;
    }

    // DeleteBonesFromWorld()
    static int DeleteBonesFromWorld(lua_State* L, Corpse* corpse)
    {
        if (!corpse)
            return 0;
        corpse->DeleteBonesFromWorld();
        return 0;
    }
};
#endif