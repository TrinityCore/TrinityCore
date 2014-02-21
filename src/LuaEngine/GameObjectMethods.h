/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef GAMEOBJECTMETHODS_H
#define GAMEOBJECTMETHODS_H

namespace LuaGameObject
{
    int GetDisplayId(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        sEluna->Push(L, go->GetDisplayId());
        return 1;
    }

    int HasQuest(lua_State* L, GameObject* go)
    {
        uint32 questId = sEluna->CHECKVAL<uint32>(L, 2);

#ifdef MANGOS
        sEluna->Push(L, go->HasQuest(questId));
#else
        sEluna->Push(L, go->hasQuest(questId));
#endif
        return 1;
    }

    int IsSpawned(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            sEluna->Push(L, false);
        else
            sEluna->Push(L, go->isSpawned());
        return 1;
    }

    int IsTransport(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            sEluna->Push(L, false);
        else
            sEluna->Push(L, go->IsTransport());
        return 1;
    }

    /*int IsDestructible(lua_State* L, GameObject* go) // TODO: Implementation core side
    {
    if (!go || !go->IsInWorld())
    sEluna->Push(L, false);
    else
    sEluna->Push(L, go->IsDestructibleBuilding());
    return 1;
    }*/

    int IsActive(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            sEluna->Push(L, false);
        else
            sEluna->Push(L, go->isActiveObject());
        return 1;
    }

    int SaveToDB(lua_State* L, GameObject* go)
    {
        go->SaveToDB();
        return 0;
    }

    int RemoveFromWorld(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        bool del = sEluna->CHECKVAL<bool>(L, 2, false);
        if (del)
            go->DeleteFromDB();
        go->RemoveFromWorld();
        return 0;
    }

    int RegisterEvent(lua_State* L, GameObject* go)
    {
        luaL_checktype(L, 2, LUA_TFUNCTION);
        uint32 delay = sEluna->CHECKVAL<uint32>(L, 3);
        uint32 repeats = sEluna->CHECKVAL<uint32>(L, 4);

        lua_settop(L, 2);
        int functionRef = lua_ref(L, true);
        functionRef = sEluna->m_EventMgr.AddEvent(&go->m_Events, functionRef, delay, repeats, go);
        if (functionRef)
            sEluna->Push(L, functionRef);
        else
            sEluna->Push(L);
        return 1;
    }

    int RemoveEventById(lua_State* L, GameObject* go)
    {
        int eventId = sEluna->CHECKVAL<int>(L, 2);
        sEluna->m_EventMgr.RemoveEvent(&go->m_Events, eventId);
        return 0;
    }

    int RemoveEvents(lua_State* L, GameObject* go)
    {
        sEluna->m_EventMgr.RemoveEvents(&go->m_Events);
        return 0;
    }

    int UseDoorOrButton(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint32 delay = sEluna->CHECKVAL<uint32>(L, 2, 0);

        go->UseDoorOrButton(delay);
        return 0;
    }

    int SetGoState(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint32 state = sEluna->CHECKVAL<uint32>(L, 2, 0);

        if (state == 0)
            go->SetGoState(GO_STATE_ACTIVE);
        else if (state == 1)
            go->SetGoState(GO_STATE_READY);
        else if (state == 2)
            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

        return 0;
    }

    int GetGoState(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        sEluna->Push(L, go->GetGoState());
        return 1;
    }

    int SetLootState(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        uint32 state = sEluna->CHECKVAL<uint32>(L, 2, 0);

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

    int GetLootState(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        sEluna->Push(L, go->getLootState());
        return 1;
    }

    int Despawn(lua_State* L, GameObject* go)
    {
        uint32 delay = sEluna->CHECKVAL<uint32>(L, 2, 1);
        if (!delay)
            delay = 1;

        go->SetSpawnedByDefault(false);
        go->SetRespawnTime(delay);
        return 0;
    }

    int Respawn(lua_State* L, GameObject* go)
    {
        uint32 delay = sEluna->CHECKVAL<uint32>(L, 2, 1);
        if (!delay)
            delay = 1;

        go->SetSpawnedByDefault(true);
        go->SetRespawnTime(delay);
        return 0;
    }
};
#endif
