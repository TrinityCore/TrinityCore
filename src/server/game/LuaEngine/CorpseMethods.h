/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef CORPSEMETHODS_H
#define CORPSEMETHODS_H

/***
 * The remains of a [Player] that has died.
 *
 * Inherits all methods from: [Object], [WorldObject]
 */
namespace LuaCorpse
{
    /**
     * Returns the GUID of the [Player] that left the [Corpse] behind.
     *
     * @return uint64 ownerGUID
     */
    int GetOwnerGUID(lua_State* L, Corpse* corpse)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, corpse->GetOwnerGUID());
#else
        Eluna::Push(L, corpse->GetOwnerGuid());
#endif
        return 1;
    }

    /**
     * Returns the time when the [Player] became a ghost and spawned this [Corpse].
     *
     * @return uint32 ghostTime
     */
    int GetGhostTime(lua_State* L, Corpse* corpse)
    {
        Eluna::Push(L, corpse->GetGhostTime());
        return 1;
    }

    /**
     * Returns the [CorpseType] of a [Corpse].
     *
     *     enum CorpseType
     *     {
     *         CORPSE_BONES             = 0,
     *         CORPSE_RESURRECTABLE_PVE = 1,
     *         CORPSE_RESURRECTABLE_PVP = 2
     *     };
     *
     * @return [CorpseType] corpseType
     */
    int GetType(lua_State* L, Corpse* corpse)
    {
        Eluna::Push(L, corpse->GetType());
        return 1;
    }

    /**
     * Sets the "ghost time" to the current time.
     *
     * See [Corpse:GetGhostTime].
     */
    int ResetGhostTime(lua_State* /*L*/, Corpse* corpse)
    {
        corpse->ResetGhostTime();
        return 0;
    }

    /**
     * Saves the [Corpse] to the database.
     */
    int SaveToDB(lua_State* /*L*/, Corpse* corpse)
    {
        corpse->SaveToDB();
        return 0;
    }
};
#endif
