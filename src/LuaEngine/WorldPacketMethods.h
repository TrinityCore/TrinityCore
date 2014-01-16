/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef WORLDPACKETMETHODS_H
#define WORLDPACKETMETHODS_H

namespace LuaPacket
{
    // GetOpcode()
    int GetOpcode(lua_State* L, WorldPacket* packet)
    {
        sEluna->Push(L, packet->GetOpcode());
        return 1;
    }

    // GetSize()
    int GetSize(lua_State* L, WorldPacket* packet)
    {
        sEluna->Push(L, packet->size());
        return 1;
    }

    // SetOpcode(opcode)
    int SetOpcode(lua_State* L, WorldPacket* packet)
    {
        uint16 opcode = luaL_checkunsigned(L, 1);
        if (opcode >= NUM_OPCODE_HANDLERS)
            luaL_error(L, "Invalid opcode type (%d)", opcode);
        else
            packet->SetOpcode((Opcodes)opcode);
        return 0;
    }

    // ReadByte()
    int ReadByte(lua_State* L, WorldPacket* packet)
    {
        int8 byte;
        (*packet) >> byte;
        sEluna->Push(L, byte);
        return 1;
    }

    // ReadUByte()
    int ReadUByte(lua_State* L, WorldPacket* packet)
    {
        uint8 byte;
        (*packet) >> byte;
        sEluna->Push(L, byte);
        return 1;
    }

    // ReadShort()
    int ReadShort(lua_State* L, WorldPacket* packet)
    {
        int16 _short;
        (*packet) >> _short;
        sEluna->Push(L, _short);
        return 1;
    }

    // ReadUShort()
    int ReadUShort(lua_State* L, WorldPacket* packet)
    {
        uint16 _ushort;
        (*packet) >> _ushort;
        sEluna->Push(L, _ushort);
        return 1;
    }

    // ReadLong()
    int ReadLong(lua_State* L, WorldPacket* packet)
    {
        int32 _long;
        (*packet) >> _long;
        sEluna->Push(L, _long);
        return 1;
    }

    // ReadULong()
    int ReadULong(lua_State* L, WorldPacket* packet)
    {
        uint32 _ulong;
        (*packet) >> _ulong;
        sEluna->Push(L, _ulong);
        return 1;
    }

    // ReadFloat()
    int ReadFloat(lua_State* L, WorldPacket* packet)
    {
        float _val;
        (*packet) >> _val;
        sEluna->Push(L, _val);
        return 1;
    }

    // ReadDouble()
    int ReadDouble(lua_State* L, WorldPacket* packet)
    {
        double _val;
        (*packet) >> _val;
        sEluna->Push(L, _val);
        return 1;
    }

    // ReadGUID()
    int ReadGUID(lua_State* L, WorldPacket* packet)
    {
        uint64 guid;
        (*packet) >> guid;
        sEluna->Push(L, guid);
        return 1;
    }

    // ReadString()
    int ReadString(lua_State* L, WorldPacket* packet)
    {
        std::string _val;
        (*packet) >> _val;
        sEluna->Push(L, _val);
        return 1;
    }

    // WriteGUID(guid)
    int WriteGUID(lua_State* L, WorldPacket* packet)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        (*packet) << guid;
        return 0;
    }

    // WriteString(string)
    int WriteString(lua_State* L, WorldPacket* packet)
    {
        std::string _val = std::string(luaL_checkstring(L, 1));
        (*packet) << _val;
        return 0;
    }

    // WriteBye(byte)
    int WriteByte(lua_State* L, WorldPacket* packet)
    {
        int8 byte = luaL_checkinteger(L, 1);
        (*packet) << byte;
        return 0;
    }

    // WriteUByte(byte)
    int WriteUByte(lua_State* L, WorldPacket* packet)
    {
        uint8 byte = luaL_checkunsigned(L, 1);
        (*packet) << byte;
        return 0;
    }

    // WriteUShort(short)
    int WriteUShort(lua_State* L, WorldPacket* packet)
    {
        uint16 _ushort = luaL_checkunsigned(L, 1);
        (*packet) << _ushort;
        return 0;
    }

    // WriteShort(short)
    int WriteShort(lua_State* L, WorldPacket* packet)
    {
        int16 _short = luaL_checkinteger(L, 1);
        (*packet) << _short;
        return 0;
    }

    // WriteLong(long)
    int WriteLong(lua_State* L, WorldPacket* packet)
    {
        int32 _long = luaL_checkinteger(L, 1);
        (*packet) << _long;
        return 0;
    }

    // WriteULong(long)
    int WriteULong(lua_State* L, WorldPacket* packet)
    {
        uint32 _ulong = luaL_checkunsigned(L, 1);
        (*packet) << _ulong;
        return 0;
    }

    // WriteFloat(float)
    int WriteFloat(lua_State* L, WorldPacket* packet)
    {
        float _val = luaL_checknumber(L, 1);
        (*packet) << _val;
        return 0;
    }

    // WriteDouble(double)
    int WriteDouble(lua_State* L, WorldPacket* packet)
    {
        double _val = luaL_checknumber(L, 1);
        (*packet) << _val;
        return 0;
    }
};

#endif