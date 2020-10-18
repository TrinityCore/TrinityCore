/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef GAMEOBJECTMETHODS_H
#define GAMEOBJECTMETHODS_H

/***
 * Inherits all methods from: [Object], [WorldObject]
 */
namespace LuaGameObject
{
    /**
     * Returns 'true' if the [GameObject] can give the specified [Quest]
     *
     * @param uint32 questId : quest entry Id to check
     * @return bool hasQuest
     */
    int HasQuest(lua_State* L, GameObject* go)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);

#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, go->hasQuest(questId));
#else
        Eluna::Push(L, go->HasQuest(questId));
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [GameObject] is spawned
     *
     * @return bool isSpawned
     */
    int IsSpawned(lua_State* L, GameObject* go)
    {
        Eluna::Push(L, go->isSpawned());
        return 1;
    }

    /**
     * Returns 'true' if the [GameObject] is a transport
     *
     * @return bool isTransport
     */
    int IsTransport(lua_State* L, GameObject* go)
    {
        Eluna::Push(L, go->IsTransport());
        return 1;
    }

    /**
     * Returns 'true' if the [GameObject] is active
     *
     * @return bool isActive
     */
    int IsActive(lua_State* L, GameObject* go)
    {
        Eluna::Push(L, go->isActiveObject());
        return 1;
    }

    /*int IsDestructible(lua_State* L, GameObject* go) // TODO: Implementation core side
    {
        Eluna::Push(L, go->IsDestructibleBuilding());
        return 1;
    }*/

    /**
     * Returns display ID of the [GameObject]
     *
     * @return uint32 displayId
     */
    int GetDisplayId(lua_State* L, GameObject* go)
    {
        Eluna::Push(L, go->GetDisplayId());
        return 1;
    }

    /**
     * Returns the state of a [GameObject]
     * Below are client side [GOState]s off of 3.3.5a
     *
     * <pre>
     * enum GOState
     * {
     *     GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
     *     GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
     *     GO_STATE_ACTIVE_ALTERNATIVE = 2                         // show in world as used in alt way and not reset (closed door open by cannon fire)
     * };
     * </pre>
     *
     * @return [GOState] goState
     */
    int GetGoState(lua_State* L, GameObject* go)
    {
        Eluna::Push(L, go->GetGoState());
        return 1;
    }

    /**
     * Returns the [LootState] of a [GameObject]
     * Below are [LootState]s off of 3.3.5a
     *
     * <pre>
     * enum LootState
     * {
     *     GO_NOT_READY = 0,
     *     GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
     *     GO_ACTIVATED,
     *     GO_JUST_DEACTIVATED
     * };
     * </pre>
     *
     * @return [LootState] lootState
     */
    int GetLootState(lua_State* L, GameObject* go)
    {
        Eluna::Push(L, go->getLootState());
        return 1;
    }

    /**
     * Returns the [Player] that can loot the [GameObject]
     *
     * Not the original looter and may be nil.
     *
     * @return [Player] player
     */
    int GetLootRecipient(lua_State* L, GameObject* go)
    {
        Eluna::Push(L, go->GetLootRecipient());
        return 1;
    }

    /**
     * Returns the [Group] that can loot the [GameObject]
     *
     * Not the original looter and may be nil.
     *
     * @return [Group] group
     */
    int GetLootRecipientGroup(lua_State* L, GameObject* go)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, go->GetLootRecipientGroup());
#else
        Eluna::Push(L, go->GetGroupLootRecipient());
#endif
        return 1;
    }

    /**
     * Returns the guid of the [GameObject] that is used as the ID in the database
     *
     * @return uint32 dbguid
     */
    int GetDBTableGUIDLow(lua_State* L, GameObject* go)
    {
#ifdef TRINITY
        Eluna::Push(L, go->GetSpawnId());
#elif AZEROTHCORE
        Eluna::Push(L, go->GetDBTableGUIDLow());
#else
        // on mangos based this is same as lowguid
        Eluna::Push(L, go->GetGUIDLow());
#endif
        return 1;
    }

    /**
     * Sets the state of a [GameObject]
     *
     * <pre>
     * enum GOState
     * {
     *     GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
     *     GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
     *     GO_STATE_ACTIVE_ALTERNATIVE = 2                         // show in world as used in alt way and not reset (closed door open by cannon fire)
     * };
     * </pre>
     *
     * @param [GOState] state : all available go states can be seen above
     */
    int SetGoState(lua_State* L, GameObject* go)
    {
        uint32 state = Eluna::CHECKVAL<uint32>(L, 2, 0);

        if (state == 0)
            go->SetGoState(GO_STATE_ACTIVE);
        else if (state == 1)
            go->SetGoState(GO_STATE_READY);
        else if (state == 2)
        {
#ifdef TRINITY
            go->SetGoState(GO_STATE_DESTROYED);
#else
            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
#endif
        }

        return 0;
    }

    /**
     * Sets the [LootState] of a [GameObject]
     * Below are [LootState]s off of 3.3.5a
     *
     * <pre>
     * enum LootState
     * {
     *     GO_NOT_READY = 0,
     *     GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
     *     GO_ACTIVATED,
     *     GO_JUST_DEACTIVATED
     * };
     * </pre>
     *
     * @param [LootState] state : all available loot states can be seen above
     */
    int SetLootState(lua_State* L, GameObject* go)
    {
        uint32 state = Eluna::CHECKVAL<uint32>(L, 2, 0);

        if (state == 0)
            go->SetLootState(GO_NOT_READY);
        else if (state == 1)
            go->SetLootState(GO_READY);
        else if (state == 2)
            go->SetLootState(GO_ACTIVATED);
        else if (state == 3)
            go->SetLootState(GO_JUST_DEACTIVATED);

        return 0;
    }

    /**
     * Saves [GameObject] to the database
     *
     */
    int SaveToDB(lua_State* /*L*/, GameObject* go)
    {
        go->SaveToDB();
        return 0;
    }

    /**
     * Removes [GameObject] from the world
     *
     * The object is no longer reachable after this and it is not respawned.
     *
     * @param bool deleteFromDB : if true, it will delete the [GameObject] from the database
     */
    int RemoveFromWorld(lua_State* L, GameObject* go)
    {
        bool deldb = Eluna::CHECKVAL<bool>(L, 2, false);

        // cs_gobject.cpp copy paste
#if defined TRINITY || AZEROTHCORE
        ObjectGuid ownerGuid = go->GetOwnerGUID();
#else
        ObjectGuid ownerGuid = go->GetOwnerGuid();
#endif
        if (ownerGuid)
        {
            Unit* owner = eObjectAccessor()GetUnit(*go, ownerGuid);
            if (!owner || !ownerGuid.IsPlayer())
                return 0;

            owner->RemoveGameObject(go, false);
        }

        if (deldb)
        {
#ifdef TRINITY
            GameObject::DeleteFromDB(go->GetSpawnId());
#else
            go->DeleteFromDB();
#endif
        }

        go->SetRespawnTime(0);
        go->Delete();

        Eluna::CHECKOBJ<ElunaObject>(L, 1)->Invalidate();
        return 0;
    }

    /**
     * Activates a door or a button/lever
     *
     * @param uint32 delay = 0 : cooldown time in seconds to restore the [GameObject] back to normal. 0 for infinite duration
     */
    int UseDoorOrButton(lua_State* L, GameObject* go)
    {
        uint32 delay = Eluna::CHECKVAL<uint32>(L, 2, 0);

        go->UseDoorOrButton(delay);
        return 0;
    }

    /**
     * Despawns a [GameObject]
     *
     * The gameobject may be automatically respawned by the core
     */
    int Despawn(lua_State* /*L*/, GameObject* go)
    {
        go->SetLootState(GO_JUST_DEACTIVATED);
        return 0;
    }

    /**
     * Respawns a [GameObject]
     */
    int Respawn(lua_State* /*L*/, GameObject* go)
    {
        go->Respawn();
        return 0;
    }

    /**
     * Sets the respawn or despawn time for the gameobject.
     *
     * Respawn time is also used as despawn time depending on gameobject settings
     *
     * @param int32 delay = 0 : cooldown time in seconds to respawn or despawn the object. 0 means never
     */
    int SetRespawnTime(lua_State* L, GameObject* go)
    {
        int32 respawn = Eluna::CHECKVAL<int32>(L, 2);

        go->SetRespawnTime(respawn);
        return 0;
    }
};
#endif
