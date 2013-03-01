#include "WorldPacket.h"

#ifndef WORLDPACKETMETHODS_H
#define WORLDPACKETMETHODS_H

class LuaPacket
{
public:
	// GetUnitType()
	static int GetUnitType(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
		{
			lua_pushnil(L);
			return 1;
		}
		lua_pushstring(L, "Packet");
		return 1;
	}

	// CreatePacket(opcode, size)
	static int CreatePacket(lua_State* L, WorldPacket* packet)
	{
		uint16 opcode = luaL_checkunsigned(L, 1);
		int size = luaL_checkunsigned(L, 2);
		if (opcode >= NUM_MSG_TYPES)
			luaL_error(L, "Eluna Nova:: Opcode %d is greater than the max Opcode type (%d)!", opcode, NUM_MSG_TYPES);
		else
		{
			WorldPacket* _packet = new WorldPacket(opcode, size);
			Eluna::get()->PushPacket(L, _packet);
		}
		return 1;
	}

	// GetOpcode()
	static int GetOpcode(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
			Eluna::get()->PushInteger(L, packet->GetOpcode());
		return 1;
	}

	// GetSize()
	static int GetSize(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
			Eluna::get()->PushInteger(L, packet->size());
		return 1;
	}

	// SetOpcode(opcode)
	static int SetOpcode(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
		{
			lua_pushnil(L);
			return 0;
		}

		uint16 opcode = luaL_checkunsigned(L, 1);
		if (opcode >= NUM_MSG_TYPES)
			luaL_error(L, "Eluna Nova::Opcode %d is greater than the max Opcode type (%d)!", opcode, NUM_MSG_TYPES);
		else
			packet->SetOpcode(opcode);
		return 0;
	}

	// ReadByte()
	static int ReadByte(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			int8 byte;
			(*packet) >> byte;
			Eluna::get()->PushInteger(L, byte);
		}
		return 1;
	}

	// ReadUByte()
	static int ReadUByte(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			uint8 byte;
			(*packet) >> byte;
			Eluna::get()->PushInteger(L, byte);
		}
		return 1;
	}

	// ReadShort()
	static int ReadShort(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			int16 _short;
			(*packet) >> _short;
			Eluna::get()->PushInteger(L, _short);
		}
		return 1;
	}

	// ReadUShort()
	static int ReadUShort(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			uint16 _ushort;
			(*packet) >> _ushort;
			Eluna::get()->PushInteger(L, _ushort);
		}
		return 1;
	}

	// ReadLong()
	static int ReadLong(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			int32 _long;
			(*packet) >> _long;
			Eluna::get()->PushInteger(L, _long);
		}
		return 1;
	}

	// ReadULong()
	static int ReadULong(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			uint32 _ulong;
			(*packet) >> _ulong;
			Eluna::get()->PushInteger(L, _ulong);
		}
		return 1;
	}

	// ReadFloat()
	static int ReadFloat(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			float _val;
			(*packet) >> _val;
			Eluna::get()->PushFloat(L, _val);
		}
		return 1;
	}

	// ReadDouble()
	static int ReadDouble(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			double _val;
			(*packet) >> _val;
			Eluna::get()->PushDouble(L, _val);
		}
		return 1;
	}

	// ReadGUID()
	static int ReadGUID(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			uint64 guid;
			(*packet) >> guid;
			Eluna::get()->PushGUID(L, guid);
		}
		return 1;
	}

	// ReadString()
	static int ReadString(lua_State* L, WorldPacket* packet)
	{
		if (!packet)
			lua_pushnil(L);
		else
		{
			string _val;
			(*packet) >> _val;
			Eluna::get()->PushString(L, _val.c_str());
		}
		return 1;
	}

	// WriteGUID(guid)
	static int WriteGUID(lua_State* L, WorldPacket* packet)
	{
		uint64 guid = luaL_checkunsigned(L, 1);
		(*packet) << guid;
		return 0;
	}

	// WriteString(string)
	static int WriteString(lua_State* L, WorldPacket* packet)
	{
		string _val = string(luaL_checkstring(L, 1));
		(*packet) << _val;
		return 0;
	}

	// WriteBye(byte)
	static int WriteByte(lua_State* L, WorldPacket* packet)
	{
		int8 byte = (int8)luaL_checkunsigned(L, 1);
		(*packet) << byte;
		return 0;
	}

	// WriteUByte(byte)
	static int WriteUByte(lua_State* L, WorldPacket* packet)
	{
		uint8 byte = (uint8)luaL_checkunsigned(L, 1);
		(*packet) << byte;
		return 0;
	}

	// WriteUShort(short)
	static int WriteUShort(lua_State* L, WorldPacket* packet)
	{
		uint16 _ushort = (uint16)luaL_checkunsigned(L, 1);
		(*packet) << _ushort;
		return 0;
	}

	// WriteShort(short)
	static int WriteShort(lua_State* L, WorldPacket* packet)
	{
		int16 _short = (int16)luaL_checkunsigned(L, 1);
		(*packet) << _short;
		return 0;
	}

	// WriteLong(long)
	static int WriteLong(lua_State* L, WorldPacket* packet)
	{
		int32 _long = (int32)luaL_checkunsigned(L, 1);
		(*packet) << _long;
		return 0;
	}

	// WriteULong(long)
	static int WriteULong(lua_State* L, WorldPacket* packet)
	{
		uint32 _ulong = (uint32)luaL_checkunsigned(L, 1);
		(*packet) << _ulong;
		return 0;
	}

	// WriteFloat(float)
	static int WriteFloat(lua_State* L, WorldPacket* packet)
	{
		float _val = (float)luaL_checknumber(L, 1);
		(*packet) << _val;
		return 0;
	}

	// WriteDouble(double)
	static int WriteDouble(lua_State* L, WorldPacket* packet)
	{
		double _val = (double)luaL_checknumber(L, 1);
		(*packet) << _val;
		return 0;
	}
};

#endif