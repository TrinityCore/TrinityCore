#ifndef WORLDPACKETMETHODS_H
#define WORLDPACKETMETHODS_H

class LuaPacket
{
public:
    // GetUnitType()
    static int GetUnitType(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        lua_pushstring(L, "Packet");
        return 1;
    }

    // GetOpcode()
    static int GetOpcode(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        sEluna->PushUnsigned(L, packet->GetOpcode());
        return 1;
    }

    // GetSize()
    static int GetSize(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        sEluna->PushUnsigned(L, packet->size());
        return 1;
    }

    // SetOpcode(opcode)
    static int SetOpcode(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint16 opcode = luaL_checkunsigned(L, 1);
        if (opcode >= NUM_MSG_TYPES)
            luaL_error(L, "Invalid opcode type (%d)", opcode);
        else
            packet->SetOpcode(opcode);
        return 0;
    }

    // ReadByte()
    static int ReadByte(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        int8 byte;
        (*packet) >> byte;
        sEluna->PushInteger(L, byte);
        return 1;
    }

    // ReadUByte()
    static int ReadUByte(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint8 byte;
        (*packet) >> byte;
        sEluna->PushUnsigned(L, byte);
        return 1;
    }

    // ReadShort()
    static int ReadShort(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        int16 _short;
        (*packet) >> _short;
        sEluna->PushInteger(L, _short);
        return 1;
    }

    // ReadUShort()
    static int ReadUShort(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint16 _ushort;
        (*packet) >> _ushort;
        sEluna->PushUnsigned(L, _ushort);
        return 1;
    }

    // ReadLong()
    static int ReadLong(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        int32 _long;
        (*packet) >> _long;
        sEluna->PushInteger(L, _long);
        return 1;
    }

    // ReadULong()
    static int ReadULong(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint32 _ulong;
        (*packet) >> _ulong;
        sEluna->PushUnsigned(L, _ulong);
        return 1;
    }

    // ReadFloat()
    static int ReadFloat(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        float _val;
        (*packet) >> _val;
        sEluna->PushFloat(L, _val);
        return 1;
    }

    // ReadDouble()
    static int ReadDouble(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        double _val;
        (*packet) >> _val;
        sEluna->PushDouble(L, _val);
        return 1;
    }

    // ReadGUID()
    static int ReadGUID(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint64 guid;
        (*packet) >> guid;
        sEluna->PushULong(L, guid);
        return 1;
    }

    // ReadString()
    static int ReadString(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        std::string _val;
        (*packet) >> _val;
        sEluna->PushString(L, _val.c_str());
        return 1;
    }

    // WriteGUID(guid)
    static int WriteGUID(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint64 guid = sEluna->CHECK_ULONG(L, 1);

        (*packet) << guid;
        return 0;
    }

    // WriteString(string)
    static int WriteString(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        std::string _val = std::string(luaL_checkstring(L, 1));
        (*packet) << _val;
        return 0;
    }

    // WriteBye(byte)
    static int WriteByte(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        int8 byte = luaL_checkinteger(L, 1);
        (*packet) << byte;
        return 0;
    }

    // WriteUByte(byte)
    static int WriteUByte(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint8 byte = luaL_checkunsigned(L, 1);
        (*packet) << byte;
        return 0;
    }

    // WriteUShort(short)
    static int WriteUShort(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint16 _ushort = luaL_checkunsigned(L, 1);
        (*packet) << _ushort;
        return 0;
    }

    // WriteShort(short)
    static int WriteShort(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        int16 _short = luaL_checkinteger(L, 1);
        (*packet) << _short;
        return 0;
    }

    // WriteLong(long)
    static int WriteLong(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        int32 _long = luaL_checkinteger(L, 1);
        (*packet) << _long;
        return 0;
    }

    // WriteULong(long)
    static int WriteULong(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        uint32 _ulong = luaL_checkunsigned(L, 1);
        (*packet) << _ulong;
        return 0;
    }

    // WriteFloat(float)
    static int WriteFloat(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        float _val = luaL_checknumber(L, 1);
        (*packet) << _val;
        return 0;
    }

    // WriteDouble(double)
    static int WriteDouble(lua_State* L, WorldPacket* packet)
    {
        if (!packet)
            return 0;

        double _val = luaL_checknumber(L, 1);
        (*packet) << _val;
        return 0;
    }
};

#endif