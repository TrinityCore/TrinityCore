/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include <memory.h>
#include "Object.h"
#include "WorldPacket.h"

#include "TSIncludes.h"
#include "TSWorldPacket.h"

TSWorldPacket::TSWorldPacket(WorldPacket *packet)
{
    this->packet = packet;
    this->owner = false;
}

TSWorldPacket::TSWorldPacket()
{
    this->packet = nullptr;
    this->owner = false;
}

TSWorldPacket::TSWorldPacket(uint16 opcode, uint32 res)
{
    this->packet = new WorldPacket(opcode,res);
    this->owner = true;
}

TSWorldPacket::~TSWorldPacket()
{
    if(this->owner)
    {
        // TODO: why does this segfault? I'm just leaving it like this
        // because that looks like what eluna is doing.
        //delete this->packet;
    }
}

/**
 * Returns the opcode of the [WorldPacket].
 *
 * @return uint16 opcode
 */
uint16 TSWorldPacket::GetOpcode() 
{
    return packet->GetOpcode();
}
    
/**
 * Returns the size of the [WorldPacket].
 *
 * @return uint32 size
 */
uint32 TSWorldPacket::GetSize() 
{
    return packet->size();
}
    
/**
 * Sets the opcode of the [WorldPacket] to the specified opcode.
 *
 * @param [Opcodes] opcode : see Opcodes.h for all known opcodes
 */
void TSWorldPacket::SetOpcode(uint32 opcode) 
{
    packet->SetOpcode(opcode);
}
    
/**
 * Reads and returns a signed 8-bit integer value from the [WorldPacket].
 *
 * @return int8 value
 */
int8 TSWorldPacket::ReadByte() 
{
    int8 _byte;
    (*packet) >> _byte;
    return _byte;
}
    
/**
 * Reads and returns an unsigned 8-bit integer value from the [WorldPacket].
 *
 * @return uint8 value
 */
uint8 TSWorldPacket::ReadUByte() 
{
    uint8 _ubyte;
    (*packet) >> _ubyte;
    return _ubyte;
}
    
/**
 * Reads and returns a signed 16-bit integer value from the [WorldPacket].
 *
 * @return int16 value
 */
int16 TSWorldPacket::ReadShort() 
{
    int16 _short;
    (*packet) >> _short;
    return _short;
}
    
/**
 * Reads and returns an unsigned 16-bit integer value from the [WorldPacket].
 *
 * @return uint16 value
 */
uint16 TSWorldPacket::ReadUShort() 
{
    uint16 _ushort;
    (*packet) >> _ushort;
    return _ushort;
}
    
/**
 * Reads and returns a signed 32-bit integer value from the [WorldPacket].
 *
 * @return int32 value
 */
int32 TSWorldPacket::ReadLong() 
{
    int32 _long;
    (*packet) >> _long;
    return _long;
}
    
/**
 * Reads and returns an unsigned 32-bit integer value from the [WorldPacket].
 *
 * @return uint32 value
 */
uint32 TSWorldPacket::ReadULong() 
{
    uint32 _ulong;
    (*packet) >> _ulong;
    return _ulong;
}
    
/**
 * Reads and returns a single-precision floating-point value from the [WorldPacket].
 *
 * @return float value
 */
float TSWorldPacket::ReadFloat() 
{
    float _val;
    (*packet) >> _val;
    return _val;
}
    
/**
 * Reads and returns a double-precision floating-point value from the [WorldPacket].
 *
 * @return double value
 */
double TSWorldPacket::ReadDouble() 
{
    double _val;
    (*packet) >> _val;
    return _val;
}
    
/**
 * Reads and returns an unsigned 64-bit integer value from the [WorldPacket].
 *
 * @return uint64 value : value returned as string
 */
uint64 TSWorldPacket::ReadGUID() 
{
    uint64 guid;
    (*packet) >> guid;
    return guid;
}
    
/**
 * Reads and returns a string value from the [WorldPacket].
 *
 * @return string value
 */
TSString TSWorldPacket::ReadString()
{
    std::string _val;
    (*packet) >> _val;
     return TSString(_val);
}
    
/**
 * Writes an unsigned 64-bit integer value to the [WorldPacket].
 *
 * @param uint64 value : the value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteGUID(uint64 guid) 
{
    (*packet) << guid;
}
    
/**
 * Writes a string to the [WorldPacket].
 *
 * @param string value : the string to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteString(TSString __val)
{
    auto _val = __val._value;
    (*packet) << _val;
}
    
/**
 * Writes a signed 8-bit integer value to the [WorldPacket].
 *
 * @param int8 value : the int8 value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteByte(int8 byte) 
{
    (*packet) << byte;
}
    
/**
 * Writes an unsigned 8-bit integer value to the [WorldPacket].
 *
 * @param uint8 value : the uint8 value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteUByte(uint8 byte) 
{
    (*packet) << byte;
}
    
/**
 * Writes a signed 16-bit integer value to the [WorldPacket].
 *
 * @param int16 value : the int16 value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteShort(int16 _short) 
{
    (*packet) << _short;
}
    
/**
 * Writes an unsigned 16-bit integer value to the [WorldPacket].
 *
 * @param uint16 value : the uint16 value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteUShort(uint16 _ushort) 
{
    (*packet) << _ushort;
}
    
/**
 * Writes a signed 32-bit integer value to the [WorldPacket].
 *
 * @param int32 value : the int32 value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteLong(int32 _long) 
{
    (*packet) << _long;
}
    
/**
 * Writes an unsigned 32-bit integer value to the [WorldPacket].
 *
 * @param uint32 value : the uint32 value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteULong(uint32 _ulong) 
{
    (*packet) << _ulong;
}
    
/**
 * Writes a 32-bit floating-point value to the [WorldPacket].
 *
 * @param float value : the float value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteFloat(float _val) 
{
    (*packet) << _val;
}
    
/**
 * Writes a 64-bit floating-point value to the [WorldPacket].
 *
 * @param double value : the double value to be written to the [WorldPacket]
 */
void TSWorldPacket::WriteDouble(double _val) 
{
    (*packet) << _val;
}
