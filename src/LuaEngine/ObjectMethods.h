/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef OBJECTMETHODS_H
#define OBJECTMETHODS_H

namespace LuaObject
{
    int RemoveFlag(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 flag = luaL_checkunsigned(L, 2);

        obj->RemoveFlag(index, flag);
        return 0;
    }
    int SetFlag(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 flag = luaL_checkunsigned(L, 2);

        obj->SetFlag(index, flag);
        return 0;
    }
    int HasFlag(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 flag = luaL_checkunsigned(L, 2);

        sEluna->Push(L, obj->HasFlag(index, flag));
        return 1;
    }
    int GetInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->Push(L, obj->GetInt32Value(index));
        return 1;
    }
    int GetUInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->Push(L, obj->GetUInt32Value(index));
        return 1;
    }
    int GetFloatValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->Push(L, obj->GetFloatValue(index));
        return 1;
    }
    int GetByteValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna->Push(L, obj->GetByteValue(index, offset));
        return 1;
    }
    int GetUInt16Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna->Push(L, obj->GetUInt16Value(index, offset));
        return 1;
    }
    int SetInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        int32 value = luaL_checkinteger(L, 2);
        obj->SetInt32Value(index, value);
        return 0;
    }
    int SetUInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        obj->SetUInt32Value(index, value);
        return 0;
    }
    int UpdateUInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        obj->UpdateUInt32Value(index, value);
        return 0;
    }
    int SetFloatValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        float value = luaL_checknumber(L, 2);

        obj->SetFloatValue(index, value);
        return 0;
    }
    int SetByteValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint8 value = luaL_checkunsigned(L, 3);
        obj->SetByteValue(index, offset, value);
        return 0;
    }
    int SetUInt16Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint16 value = luaL_checkunsigned(L, 3);
        obj->SetUInt16Value(index, offset, value);
        return 0;
    }
    int SetInt16Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        int16 value = luaL_checkinteger(L, 3);
        obj->SetInt16Value(index, offset, value);
        return 0;
    }
    static int ToCorpse(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->ToCorpse());
        return 1;
    }
    static int ToGameObject(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->ToGameObject());
        return 1;
    }
    static int ToUnit(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->ToUnit());
        return 1;
    }
    static int ToCreature(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->ToCreature());
        return 1;
    }
    static int ToPlayer(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->ToPlayer());
        return 1;
    }
    int SetScale(lua_State* L, Object* obj)
    {
        float size = luaL_checknumber(L, 1);

        obj->SetObjectScale(size);
        return 0;
    }
    static int GetScale(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->GetObjectScale());
        return 1;
    }
    static int GetEntry(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->GetEntry());
        return 1;
    }
    static int GetGUID(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->GetGUID());
        return 1;
    }
    static int GetGUIDLow(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->GetGUIDLow());
        return 1;
    }
    static int IsInWorld(lua_State* L, Object* obj)
    {
        sEluna->Push(L, obj->IsInWorld());
        return 1;
    }
};
#endif
