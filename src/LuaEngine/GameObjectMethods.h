/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef GAMEOBJECTMETHODS_H
#define GAMEOBJECTMETHODS_H

namespace LuaGameObject
{
    int GetRelativePoint(lua_State* L, GameObject* go)
    {
        float dist = luaL_checknumber(L, 1);
        int deg = luaL_checkinteger(L, 2);

        float o = Position::NormalizeOrientation(go->GetOrientation() + (deg * M_PI / 180));
        sEluna->Push(L, go->GetPositionX() + (dist * cosf(o)));
        sEluna->Push(L, go->GetPositionY() + (dist * sinf(o)));
        sEluna->Push(L, o);
        return 3;
    }

    int SummonCreature(lua_State* L, GameObject* go)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 spawnType = luaL_optunsigned(L, 6, 0);
        uint32 despawnTimer = luaL_optunsigned(L, 7, 0);

        TempSummonType type;
        switch (spawnType)
        {
            case 1:
                type = TEMPSUMMON_TIMED_OR_DEAD_DESPAWN;
                break;
            case 2:
                type = TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN;
                break;
            case 3:
                type = TEMPSUMMON_TIMED_DESPAWN;
                break;
            case 4:
                type = TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT;
               break;
            case 5:
                type = TEMPSUMMON_CORPSE_DESPAWN;
                break;
            case 6:
                type = TEMPSUMMON_CORPSE_TIMED_DESPAWN;
                break;
            case 7:
                type = TEMPSUMMON_DEAD_DESPAWN;
                break;
            case 8:
                type = TEMPSUMMON_MANUAL_DESPAWN;
                break;
            default:
                return 0;
        }
        sEluna->Push(L, go->SummonCreature(entry, x, y, z, o, type, despawnTimer)->ToCreature());
        return 1;
    }

    int SummonGameObject(lua_State* L, GameObject* go)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 respawnDelay = luaL_optunsigned(L, 6, 30);
        sEluna->Push(L, go->SummonGameObject(entry, x, y, z, o, 0, 0, 0, 0, respawnDelay));
        return 1;
    }

    int GetDisplayId(lua_State* L, GameObject* go)
    {
        sEluna->Push(L, go->GetDisplayId());
        return 1;
    }

    int HasQuest(lua_State* L, GameObject* go)
    {
        uint32 questId = luaL_checkunsigned(L, 1);

        sEluna->Push(L, go->hasQuest(questId));
        return 1;
    }

    int IsSpawned(lua_State* L, GameObject* go)
    {
        sEluna->Push(L, go->isSpawned());
        return 1;
    }

    int IsTransport(lua_State* L, GameObject* go)
    {
        sEluna->Push(L, go->IsTransport());
        return 1;
    }

    int IsDestructible(lua_State* L, GameObject* go)
    {
        sEluna->Push(L, go->IsDestructibleBuilding());
        return 1;
    }

    int IsActive(lua_State* L, GameObject* go)
    {
        sEluna->Push(L, go->isActiveObject());
        return 1;
    }

    int Move(lua_State* L, GameObject* go)
    {
        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);
        float o = luaL_checknumber(L, 4);
        go->Relocate(x, y, z, o);
        return 0;
    }

    int SaveToDB(lua_State* L, GameObject* go)
    {
        go->SaveToDB();
        return 0;
    }

    int RemoveFromWorld(lua_State* L, GameObject* go)
    {
        bool del = luaL_optbool(L, 1, false);
        if (del)
            go->DeleteFromDB();
        go->RemoveFromWorld();
        return 0;
    }

    int RegisterEvent(lua_State* L, GameObject* go)
    {
        luaL_checktype(L, 1, LUA_TFUNCTION);
        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);

        lua_settop(L, 1);
        int functionRef = lua_ref(L, true);
        sEluna->Push(L, sEluna->m_EventMgr.AddEvent(go->GetGUID(), functionRef, delay, repeats, go));
        return 1;
    }

    int RemoveEventById(lua_State* L, GameObject* go)
    {
        int eventId = luaL_checkinteger(L, 1);
        sEluna->m_EventMgr.RemoveEvent(go->GetGUID(), eventId);
        return 0;
    }

    int RemoveEvents(lua_State* L, GameObject* go)
    {
        sEluna->m_EventMgr.RemoveEvents(go->GetGUID());
        return 0;
    }

    int UseDoorOrButton(lua_State* L, GameObject* go)
    {
        uint32 delay = luaL_optunsigned(L, 1, 0);

        go->UseDoorOrButton(delay);
        return 0;
    }

    int SetGoState(lua_State* L, GameObject* go)
    {
        uint32 state = luaL_optunsigned(L, 1, 0);

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
        uint32 state = luaL_optunsigned(L, 1, 0);

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
        sEluna->Push(L, go->getLootState());
        return 1;
    }

    int Despawn(lua_State* L, GameObject* go)
    {
        uint32 delay = luaL_optunsigned(L, 1, 1);
        if (!delay)
            delay = 1;

        go->SetSpawnedByDefault(false);
        go->SetRespawnTime(delay);
        return 0;
    }

    int Respawn(lua_State* L, GameObject* go)
    {
        uint32 delay = luaL_optunsigned(L, 1, 1);
        if (!delay)
            delay = 1;

        go->SetSpawnedByDefault(true);
        go->SetRespawnTime(delay);
        return 0;
    }
};
#endif
