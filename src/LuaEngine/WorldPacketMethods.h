/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
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
        uint32 opcode = sEluna->CHECKVAL<uint32>(L, 2);
        if (opcode >= NUM_MSG_TYPES)
            return luaL_argerror(L, 2, "valid opcode expected");
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
        uint64 guid = sEluna->CHECKVAL<uint64>(L, 2);
        (*packet) << guid;
        return 0;
    }

    // WriteString(string)
    int WriteString(lua_State* L, WorldPacket* packet)
    {
        std::string _val = sEluna->CHECKVAL<std::string>(L, 2);
        (*packet) << _val;
        return 0;
    }

    // WriteBye(byte)
    int WriteByte(lua_State* L, WorldPacket* packet)
    {
        int8 byte = sEluna->CHECKVAL<int8>(L, 2);
        (*packet) << byte;
        return 0;
    }

    // WriteUByte(byte)
    int WriteUByte(lua_State* L, WorldPacket* packet)
    {
        uint8 byte = sEluna->CHECKVAL<uint8>(L, 2);
        (*packet) << byte;
        return 0;
    }

    // WriteUShort(short)
    int WriteUShort(lua_State* L, WorldPacket* packet)
    {
        uint16 _ushort = sEluna->CHECKVAL<uint16>(L, 2);
        (*packet) << _ushort;
        return 0;
    }

    // WriteShort(short)
    int WriteShort(lua_State* L, WorldPacket* packet)
    {
        int16 _short = sEluna->CHECKVAL<int16>(L, 2);
        (*packet) << _short;
        return 0;
    }

    // WriteLong(long)
    int WriteLong(lua_State* L, WorldPacket* packet)
    {
        int32 _long = sEluna->CHECKVAL<int32>(L, 2);
        (*packet) << _long;
        return 0;
    }

    // WriteULong(long)
    int WriteULong(lua_State* L, WorldPacket* packet)
    {
        uint32 _ulong = sEluna->CHECKVAL<uint32>(L, 2);
        (*packet) << _ulong;
        return 0;
    }

    // WriteFloat(float)
    int WriteFloat(lua_State* L, WorldPacket* packet)
    {
        float _val = sEluna->CHECKVAL<float>(L, 2);
        (*packet) << _val;
        return 0;
    }

    // WriteDouble(double)
    int WriteDouble(lua_State* L, WorldPacket* packet)
    {
        double _val = sEluna->CHECKVAL<double>(L, 2);
        (*packet) << _val;
        return 0;
    }
};

#endif
