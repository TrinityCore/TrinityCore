/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef WORLDPACKETMETHODS_H
#define WORLDPACKETMETHODS_H

/***
 * A packet used to pass messages between the server and a client.
 *
 * Each packet has an opcode that determines the type of message being sent,
 *   e.g. if a CMSG_LOGOUT_REQUEST packet is sent to the server,
 *   the client has sent a message that its [Player] wants to logout.
 *
 * The packet can contain further data, the format of which depends on the opcode.
 *
 * Inherits all methods from: none
 */
namespace LuaPacket
{
    /**
     * Returns the opcode of the [WorldPacket].
     *
     * @return uint16 opcode
     */
    int GetOpcode(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        Eluna::Push(L, packet->GetOpcode());
        return 1;
    }

    /**
     * Returns the size of the [WorldPacket].
     *
     * @return uint32 size
     */
    int GetSize(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        Eluna::Push(L, packet->size());
        return 1;
    }

    /**
     * Sets the opcode of the [WorldPacket] to the specified opcode.
     *
     * @param [Opcodes] opcode : see Opcodes.h for all known opcodes
     */
    int SetOpcode(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint32 opcode = Eluna::CHECKVAL<uint32>(L, 2);
        if (opcode >= NUM_MSG_TYPES)
            return luaL_argerror(L, 2, "valid opcode expected");
        packet->SetOpcode((OpcodesList)opcode);
        return 0;
    }

    /**
     * Reads and returns a signed 8-bit integer value from the [WorldPacket].
     *
     * @return int8 value
     */
    int ReadByte(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        int8 _byte;
        (*packet) >> _byte;
        Eluna::Push(L, _byte);
        return 1;
    }

    /**
     * Reads and returns an unsigned 8-bit integer value from the [WorldPacket].
     *
     * @return uint8 value
     */
    int ReadUByte(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint8 _ubyte;
        (*packet) >> _ubyte;
        Eluna::Push(L, _ubyte);
        return 1;
    }

    /**
     * Reads and returns a signed 16-bit integer value from the [WorldPacket].
     *
     * @return int16 value
     */
    int ReadShort(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        int16 _short;
        (*packet) >> _short;
        Eluna::Push(L, _short);
        return 1;
    }

    /**
     * Reads and returns an unsigned 16-bit integer value from the [WorldPacket].
     *
     * @return uint16 value
     */
    int ReadUShort(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint16 _ushort;
        (*packet) >> _ushort;
        Eluna::Push(L, _ushort);
        return 1;
    }

    /**
     * Reads and returns a signed 32-bit integer value from the [WorldPacket].
     *
     * @return int32 value
     */
    int ReadLong(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        int32 _long;
        (*packet) >> _long;
        Eluna::Push(L, _long);
        return 1;
    }

    /**
     * Reads and returns an unsigned 32-bit integer value from the [WorldPacket].
     *
     * @return uint32 value
     */
    int ReadULong(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint32 _ulong;
        (*packet) >> _ulong;
        Eluna::Push(L, _ulong);
        return 1;
    }

    /**
     * Reads and returns a single-precision floating-point value from the [WorldPacket].
     *
     * @return float value
     */
    int ReadFloat(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        float _val;
        (*packet) >> _val;
        Eluna::Push(L, _val);
        return 1;
    }

    /**
     * Reads and returns a double-precision floating-point value from the [WorldPacket].
     *
     * @return double value
     */
    int ReadDouble(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        double _val;
        (*packet) >> _val;
        Eluna::Push(L, _val);
        return 1;
    }

    /**
     * Reads and returns an unsigned 64-bit integer value from the [WorldPacket].
     *
     * @return uint64 value : value returned as string
     */
    int ReadGUID(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint64 guid;
        (*packet) >> guid;
        Eluna::Push(L, guid);
        return 1;
    }

    /**
     * Reads and returns a string value from the [WorldPacket].
     *
     * @return string value
     */
    int ReadString(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        std::string _val;
        (*packet) >> _val;
        Eluna::Push(L, _val);
        return 1;
    }

    /**
     * Writes an unsigned 64-bit integer value to the [WorldPacket].
     *
     * @param uint64 value : the value to be written to the [WorldPacket]
     */
    int WriteGUID(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);
        (*packet) << guid;
        return 0;
    }

    /**
     * Writes a string to the [WorldPacket].
     *
     * @param string value : the string to be written to the [WorldPacket]
     */
    int WriteString(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        std::string _val = Eluna::CHECKVAL<std::string>(L, 2);
        (*packet) << _val;
        return 0;
    }

    /**
     * Writes a signed 8-bit integer value to the [WorldPacket].
     *
     * @param int8 value : the int8 value to be written to the [WorldPacket]
     */
    int WriteByte(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        int8 byte = Eluna::CHECKVAL<int8>(L, 2);
        (*packet) << byte;
        return 0;
    }

    /**
     * Writes an unsigned 8-bit integer value to the [WorldPacket].
     *
     * @param uint8 value : the uint8 value to be written to the [WorldPacket]
     */
    int WriteUByte(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint8 byte = Eluna::CHECKVAL<uint8>(L, 2);
        (*packet) << byte;
        return 0;
    }

    /**
     * Writes a signed 16-bit integer value to the [WorldPacket].
     *
     * @param int16 value : the int16 value to be written to the [WorldPacket]
     */
    int WriteShort(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        int16 _short = Eluna::CHECKVAL<int16>(L, 2);
        (*packet) << _short;
        return 0;
    }

    /**
     * Writes an unsigned 16-bit integer value to the [WorldPacket].
     *
     * @param uint16 value : the uint16 value to be written to the [WorldPacket]
     */
    int WriteUShort(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint16 _ushort = Eluna::CHECKVAL<uint16>(L, 2);
        (*packet) << _ushort;
        return 0;
    }

    /**
     * Writes a signed 32-bit integer value to the [WorldPacket].
     *
     * @param int32 value : the int32 value to be written to the [WorldPacket]
     */
    int WriteLong(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        int32 _long = Eluna::CHECKVAL<int32>(L, 2);
        (*packet) << _long;
        return 0;
    }

    /**
     * Writes an unsigned 32-bit integer value to the [WorldPacket].
     *
     * @param uint32 value : the uint32 value to be written to the [WorldPacket]
     */
    int WriteULong(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        uint32 _ulong = Eluna::CHECKVAL<uint32>(L, 2);
        (*packet) << _ulong;
        return 0;
    }

    /**
     * Writes a 32-bit floating-point value to the [WorldPacket].
     *
     * @param float value : the float value to be written to the [WorldPacket]
     */
    int WriteFloat(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        float _val = Eluna::CHECKVAL<float>(L, 2);
        (*packet) << _val;
        return 0;
    }

    /**
     * Writes a 64-bit floating-point value to the [WorldPacket].
     *
     * @param double value : the double value to be written to the [WorldPacket]
     */
    int WriteDouble(Eluna* /*E*/, lua_State* L, WorldPacket* packet)
    {
        double _val = Eluna::CHECKVAL<double>(L, 2);
        (*packet) << _val;
        return 0;
    }
};

#endif
