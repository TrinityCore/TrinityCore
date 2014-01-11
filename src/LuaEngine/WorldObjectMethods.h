/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef WORLDOBJECTMETHODS_H
#define WORLDOBJECTMETHODS_H

namespace LuaWorldObject
{
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
    int GetPhaseMask(lua_State* L, WorldObject* obj)
    {
        sEluna->Push(L, obj->GetPhaseMask());
        return 1;
    }
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
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

        Player* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEMASK_PLAYER);
        Trinity::PlayerLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);

        sEluna->Push(L, target);
        return 1;
    }
    int GetNearestGameObject(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        GameObject* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEMASK_GAMEOBJECT, entry);
        Trinity::GameObjectLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);
        obj->VisitNearbyGridObject(range, searcher);

        sEluna->Push(L, target);
        return 1;
    }
    int GetNearestCreature(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        Creature* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEMASK_UNIT, entry);
        Trinity::CreatureLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);
        obj->VisitNearbyGridObject(range, searcher);

        sEluna->Push(L, target);
        return 1;
    }
    int GetPlayersInRange(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

        std::list<Player*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEMASK_PLAYER);
        Trinity::PlayerListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
        obj->VisitNearbyWorldObject(range, searcher);

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
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        std::list<Creature*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEMASK_UNIT);
        Trinity::CreatureListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
        obj->VisitNearbyGridObject(range, searcher);

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
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        float x, y, z;
        obj->GetPosition(x, y, z);
        std::list<GameObject*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEMASK_GAMEOBJECT);
        Trinity::GameObjectListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
        obj->VisitNearbyGridObject(range, searcher);

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
        bool nearest = luaL_optbool(L, 1, true);
        float range = luaL_optnumber(L, 2, SIZE_OF_GRIDS);
        uint16 type = luaL_optunsigned(L, 3, 0); // TypeMask
        uint32 entry = luaL_optunsigned(L, 4, 0);
        uint32 hostile = luaL_optunsigned(L, 5, 0); // 0 none, 1 hostile, 2 friendly

        float x, y, z;
        obj->GetPosition(x, y, z);
        Eluna::WorldObjectInRangeCheck checker(nearest, obj, range, type, entry, hostile);
        if (nearest)
        {
            WorldObject* target = NULL;
            Trinity::WorldObjectLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, target, checker);
            obj->VisitNearbyObject(range, searcher);

            sEluna->Push(L, target);
            return 1;
        }
        else
        {
            std::list<WorldObject*> list;
            Trinity::WorldObjectListSearcher<Eluna::WorldObjectInRangeCheck> searcher(obj, list, checker);
            obj->VisitNearbyObject(range, searcher);

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
        uint64 guid = sEluna->CHECK_ULONG(L, 1);

        switch (GUID_HIPART(guid))
        {
        case HIGHGUID_PLAYER:        sEluna->Push(L, sObjectAccessor->GetPlayer(*obj, guid)); break;
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_MO_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:    sEluna->Push(L, sObjectAccessor->GetGameObject(*obj, guid)); break;
        case HIGHGUID_VEHICLE:
        case HIGHGUID_UNIT:          sEluna->Push(L, sObjectAccessor->GetCreature(*obj, guid)); break;
        case HIGHGUID_PET:           sEluna->Push(L, sObjectAccessor->GetPet(*obj, guid)); break;
        default:                     return 0;
        }
        return 1;
    }
};
#endif
