/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef WORLDOBJECTMETHODS_H
#define WORLDOBJECTMETHODS_H

namespace LuaWorldObject
{
    /* GETTERS */
    int GetName(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetName());
        return 1;
    }

    int GetMap(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetMap());
        return 1;
    }

#ifndef TBC
    int GetPhaseMask(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetPhaseMask());
        return 1;
    }
#endif

    int GetInstanceId(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetInstanceId());
        return 1;
    }

    int GetAreaId(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetAreaId());
        return 1;
    }

    int GetZoneId(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetZoneId());
        return 1;
    }

    int GetMapId(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetMapId());
        return 1;
    }

    int GetX(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetPositionX());
        return 1;
    }

    int GetY(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetPositionY());
        return 1;
    }

    int GetZ(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetPositionZ());
        return 1;
    }

    int GetO(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetOrientation());
        return 1;
    }

    int GetLocation(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetPositionX());
        sEluna->Push(L, obj->GetPositionY());
        sEluna->Push(L, obj->GetPositionZ());
        sEluna->Push(L, obj->GetOrientation());
        return 4;
    }

    int GetNearestPlayer(lua_State* L, WorldObject* obj)
    {
        float range = sEluna->CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);

        Unit* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEMASK_PLAYER);
#ifdef MANGOS
        MaNGOS::UnitLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(target, checker);
        Cell::VisitWorldObjects(obj, searcher, range);
#else
        Trinity::UnitLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);
        obj->VisitNearbyObject(range, searcher);
#endif

        sEluna->Push(L, target);
        return 1;
    }

    int GetNearestGameObject(lua_State* L, WorldObject* obj)
    {
        float range = sEluna->CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);
        uint32 entry = sEluna->CHECKVAL<uint32>(L, 3, 0);

        GameObject* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEMASK_GAMEOBJECT, entry);
#ifdef MANGOS
        MaNGOS::GameObjectLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(target, checker);
        Cell::VisitGridObjects(obj, searcher, range);
#else
        Trinity::GameObjectLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);
        obj->VisitNearbyObject(range, searcher);
#endif

        sEluna->Push(L, target);
        return 1;
    }

    int GetNearestCreature(lua_State* L, WorldObject* obj)
    {
        float range = sEluna->CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);
        uint32 entry = sEluna->CHECKVAL<uint32>(L, 3, 0);

        Creature* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEMASK_UNIT, entry);
#ifdef MANGOS
        MaNGOS::CreatureLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(target, checker);
        Cell::VisitGridObjects(obj, searcher, range);
#else
        Trinity::CreatureLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);
        obj->VisitNearbyObject(range, searcher);
#endif

        sEluna->Push(L, target);
        return 1;
    }

    int GetPlayersInRange(lua_State* L, WorldObject* obj)
    {
        float range = sEluna->CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);

        std::list<Player*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEMASK_PLAYER);
#ifdef MANGOS
        MaNGOS::PlayerListSearcher<Eluna::WorldObjectInRangeCheck> searcher(list, checker);
        Cell::VisitWorldObjects(obj, searcher, range);
#else
        Trinity::PlayerListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
        obj->VisitNearbyObject(range, searcher);
#endif

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<Player*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna->Push(L, ++i);
            sEluna->Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    int GetCreaturesInRange(lua_State* L, WorldObject* obj)
    {
        float range = sEluna->CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);
        uint32 entry = sEluna->CHECKVAL<uint32>(L, 3, 0);

        std::list<Creature*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEMASK_UNIT, entry);
#ifdef MANGOS
        MaNGOS::CreatureListSearcher<Eluna::WorldObjectInRangeCheck> searcher(list, checker);
        Cell::VisitGridObjects(obj, searcher, range);
#else
        Trinity::CreatureListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
        obj->VisitNearbyObject(range, searcher);
#endif

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<Creature*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna->Push(L, ++i);
            sEluna->Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    int GetGameObjectsInRange(lua_State* L, WorldObject* obj)
    {
        float range = sEluna->CHECKVAL<float>(L, 2, SIZE_OF_GRIDS);
        uint32 entry = sEluna->CHECKVAL<uint32>(L, 3, 0);

        std::list<GameObject*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEMASK_GAMEOBJECT, entry);
#ifdef MANGOS
        MaNGOS::GameObjectListSearcher<Eluna::WorldObjectInRangeCheck> searcher(list, checker);
        Cell::VisitGridObjects(obj, searcher, range);
#else
        Trinity::GameObjectListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
        obj->VisitNearbyObject(range, searcher);
#endif

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<GameObject*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna->Push(L, ++i);
            sEluna->Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    int GetNearObject(lua_State* L, WorldObject* obj)
    {
        bool nearest = sEluna->CHECKVAL<bool>(L, 2, true);
        float range = sEluna->CHECKVAL<float>(L, 3, SIZE_OF_GRIDS);
        uint16 type = sEluna->CHECKVAL<uint16>(L, 4, 0); // TypeMask
        uint32 entry = sEluna->CHECKVAL<uint32>(L, 5, 0);
        uint32 hostile = sEluna->CHECKVAL<uint32>(L, 6, 0); // 0 none, 1 hostile, 2 friendly

        float x, y, z;
        obj->GetPosition(x, y, z);
        Eluna::WorldObjectInRangeCheck checker(nearest, obj, range, type, entry, hostile);
        if (nearest)
        {
            WorldObject* target = NULL;
#ifdef MANGOS
            MaNGOS::WorldObjectLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(target, checker);
            Cell::VisitAllObjects(obj, searcher, range);
#else
            Trinity::WorldObjectLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);
            obj->VisitNearbyObject(range, searcher);
#endif

            sEluna->Push(L, target);
            return 1;
        }
        else
        {
            std::list<WorldObject*> list;
#ifdef MANGOS
            MaNGOS::WorldObjectListSearcher<Eluna::WorldObjectInRangeCheck> searcher(list, checker);
            Cell::VisitAllObjects(obj, searcher, range);
#else
            Trinity::WorldObjectListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
            obj->VisitNearbyObject(range, searcher);
#endif

            lua_newtable(L);
            int tbl = lua_gettop(L);
            uint32 i = 0;

            for (std::list<WorldObject*>::const_iterator it = list.begin(); it != list.end(); ++it)
            {
                sEluna->Push(L, ++i);
                sEluna->Push(L, *it);
                lua_settable(L, tbl);
            }

            lua_settop(L, tbl);
            return 1;
        }

        return 0;
    }

    int GetWorldObject(lua_State* L, WorldObject* obj)
    {
        uint64 guid = sEluna->CHECKVAL<uint64>(L, 2);

#ifdef MANGOS
        switch (GUID_HIPART(guid))
        {
        case HIGHGUID_PLAYER:        sEluna->Push(L, obj->GetMap()->GetPlayer(GUID_TYPE(guid))); break;
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_MO_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:    sEluna->Push(L, obj->GetMap()->GetGameObject(GUID_TYPE(guid))); break;
#ifndef TBC
        case HIGHGUID_VEHICLE:
#endif
        case HIGHGUID_UNIT:
        case HIGHGUID_PET:           sEluna->Push(L, obj->GetMap()->GetAnyTypeCreature(GUID_TYPE(guid))); break;
        default:                     return 0;
        }
#else
        switch (GUID_HIPART(guid))
        {
        case HIGHGUID_PLAYER:        sEluna->Push(L, sObjectAccessor->GetPlayer(*obj, GUID_TYPE(guid))); break;
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_MO_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:    sEluna->Push(L, sObjectAccessor->GetGameObject(*obj, GUID_TYPE(guid))); break;
        case HIGHGUID_VEHICLE:
        case HIGHGUID_UNIT:          sEluna->Push(L, sObjectAccessor->GetCreature(*obj, GUID_TYPE(guid))); break;
        case HIGHGUID_PET:           sEluna->Push(L, sObjectAccessor->GetPet(*obj, GUID_TYPE(guid))); break;
        default:                     return 0;
        }
#endif
        return 1;
    }

    int GetDistance(lua_State* L, WorldObject* obj)
    {
        WorldObject* target = sEluna->CHECKOBJ<WorldObject>(L, 2, false);
        if (target && target->IsInWorld())
            sEluna->Push(L, obj->GetDistance(target));
        else
        {
            float X = sEluna->CHECKVAL<float>(L, 2);
            float Y = sEluna->CHECKVAL<float>(L, 3);
            float Z = sEluna->CHECKVAL<float>(L, 4);
            sEluna->Push(L, obj->GetDistance(X, Y, Z));
        }
        return 1;
    }

    int GetRelativePoint(lua_State* L, WorldObject* obj)
    {
        float dist = sEluna->CHECKVAL<float>(L, 2);
        float rad = sEluna->CHECKVAL<float>(L, 3);

        float x, y, z;
        obj->GetClosePoint(x, y, z, 0.0f, dist, rad);

        sEluna->Push(L, x);
        sEluna->Push(L, y);
        sEluna->Push(L, z);
        return 3;
    }

    int GetAngle(lua_State* L, WorldObject* obj)
    {
        WorldObject* target = sEluna->CHECKOBJ<WorldObject>(L, 2, false);

        if (target && target->IsInWorld())
            sEluna->Push(L, obj->GetAngle(target));
        else
        {
            float x = sEluna->CHECKVAL<float>(L, 2);
            float y = sEluna->CHECKVAL<float>(L, 3);
            sEluna->Push(L, obj->GetAngle(x, y));
        }
        return 1;
    }

    /* OTHER */
    int SendPacket(lua_State* L, WorldObject* obj)
    {
        WorldPacket* data = sEluna->CHECKOBJ<WorldPacket>(L, 2);
        obj->SendMessageToSet(data, true);
        return 0;
    }

    int SummonGameObject(lua_State* L, WorldObject* obj)
    {
        uint32 entry = sEluna->CHECKVAL<uint32>(L, 2);
        float x = sEluna->CHECKVAL<float>(L, 3);
        float y = sEluna->CHECKVAL<float>(L, 4);
        float z = sEluna->CHECKVAL<float>(L, 5);
        float o = sEluna->CHECKVAL<float>(L, 6);
        uint32 respawnDelay = sEluna->CHECKVAL<uint32>(L, 7, 30);
#ifdef MANGOS
        sEluna->Push(L, obj->SummonGameObject(entry, x, y, z, o, respawnDelay));
#else
        sEluna->Push(L, obj->SummonGameObject(entry, x, y, z, o, 0, 0, 0, 0, respawnDelay));
#endif
        return 1;
    }

    int SpawnCreature(lua_State* L, WorldObject* obj)
    {
        uint32 entry = sEluna->CHECKVAL<uint32>(L, 2);
        float x = sEluna->CHECKVAL<float>(L, 3);
        float y = sEluna->CHECKVAL<float>(L, 4);
        float z = sEluna->CHECKVAL<float>(L, 5);
        float o = sEluna->CHECKVAL<float>(L, 6);
        uint32 spawnType = sEluna->CHECKVAL<uint32>(L, 7, 8);
        uint32 despawnTimer = sEluna->CHECKVAL<uint32>(L, 8, 0);

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
            return luaL_argerror(L, 7, "valid SpawnType expected");
        }
        sEluna->Push(L, obj->SummonCreature(entry, x, y, z, o, type, despawnTimer));
        return 1;
    }
};
#endif
