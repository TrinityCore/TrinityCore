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

#include "TSIncludes.h"
#include "TSObject.h"


TSObject::TSObject(Object *obj)
{
    this->obj = obj;
}

TSObject::TSObject()
{
}

/**
 * Returns `true` if the specified flag is set, otherwise `false`.
 *
 * @param uint16 index : the index of the flags data in the [Object]
 * @param uint32 flag : the flag to check for in the flags data
 * @return bool hasFlag
 */
bool TSObject::HasFlag(uint16 index,uint32 flag) 
{
    return obj->HasFlag(index, flag);
}
    
/**
 * Returns `true` if the [Object] has been added to its [Map], otherwise `false`.
 *
 * @return bool inWorld
 */
bool TSObject::IsInWorld() 
{
    return obj->IsInWorld();
}
    
/**
 * Returns the data at the specified index, casted to a signed 32-bit integer.
 *
 * @param uint16 index
 * @return int32 value
 */
int32 TSObject::GetInt32Value(uint16 index) 
{
    return obj->GetInt32Value(index);
}
    
/**
 * Returns the data at the specified index, casted to a unsigned 32-bit integer.
 *
 * @param uint16 index
 * @return uint32 value
 */
uint32 TSObject::GetUInt32Value(uint16 index) 
{
    return obj->GetUInt32Value(index);
}
    
/**
 * Returns the data at the specified index, casted to a single-precision floating point value.
 *
 * @param uint16 index
 * @return float value
 */
float TSObject::GetFloatValue(uint16 index) 
{
    return obj->GetFloatValue(index);
}
    
/**
 * Returns the data at the specified index and offset, casted to an unsigned 8-bit integer.
 *
 * E.g. if you want the second byte at index 10, you would pass in 1 as the offset.
 *
 * @param uint16 index
 * @param uint8 offset : should be 0, 1, 2, or 3
 * @return uint8 value
 */
uint8 TSObject::GetByteValue(uint16 index,uint8 offset) 
{
    return obj->GetByteValue(index, offset);
}
    
/**
 * Returns the data at the specified index and offset, casted to a signed 16-bit integer.
 *
 * E.g. if you want the second half-word at index 10, you would pass in 1 as the offset.
 *
 * @param uint16 index
 * @param uint8 offset : should be 0 or 1
 * @return uint16 value
 */
uint16 TSObject::GetUInt16Value(uint16 index,uint8 offset) 
{
    return obj->GetUInt16Value(index, offset);
}
    
/**
 * Returns the scale/size of the [Object].
 *
 * This affects the size of a [WorldObject] in-game, but [Item]s don't have a "scale".
 *
 * @return float scale
 */
float TSObject::GetScale() 
{
#ifndef AZEROTHCORE
    return obj->GetObjectScale();
#else
    return obj->GetFloatValue(OBJECT_FIELD_SCALE_X);
#endif
}
    
/**
 * Returns the entry of the [Object].
 *
 * [Player]s do not have an "entry".
 *
 * @return uint32 entry
 */
uint32 TSObject::GetEntry() 
{
    return obj->GetEntry();
}
    
/**
 * Returns the GUID of the [Object].
 * 
 * GUID is an unique identifier for the object.
 * 
 * However on MaNGOS and cMangos creatures and gameobjects inside different maps can share
 * the same GUID but not on the same map.
 * 
 * On TrinityCore this value is unique across all maps
 *
 * @return uint64 guid
 */
uint64 TSObject::GetGUID() 
{
    return obj->TS_GET_GUID();
}
    
/**
 * Returns the low-part of the [Object]'s GUID.
 * 
 * On TrinityCore all low GUIDs are different for all objects of the same type.
 * For example creatures in instances are assigned new GUIDs when the Map is created.
 * 
 * On MaNGOS and cMaNGOS low GUIDs are unique only on the same map.
 * For example creatures in instances use the same low GUID assigned for that spawn in the database.
 * This is why to identify a creature you have to know the instanceId and low GUID. See [Map:GetIntstanceId]
 *
 * @return uint32 guidLow
 */
uint32 TSObject::GetGUIDLow() 
{
#ifdef TRINITY
    return obj->GetGUID().GetCounter();
#else
    return obj->GetGUIDLow();
#endif
}
    
/**
 * Returns the TypeId of the [Object].
 *
 *     enum TypeID
 *     {
 *         TYPEID_OBJECT        = 0,
 *         TYPEID_ITEM          = 1,
 *         TYPEID_CONTAINER     = 2,
 *         TYPEID_UNIT          = 3,
 *         TYPEID_PLAYER        = 4,
 *         TYPEID_GAMEOBJECT    = 5,
 *         TYPEID_DYNAMICOBJECT = 6,
 *         TYPEID_CORPSE        = 7
 *
 * @return uint8 typeID
 */
uint8 TSObject::GetTypeId() 
{
    return obj->GetTypeId();
}
    
/**
 * Returns the data at the specified index, casted to an unsigned 64-bit integer.
 *
 * @param uint16 index
 * @return uint64 value
 */
uint64 TSObject::GetUInt64Value(uint16 index) 
{
    return obj->GetUInt64Value(index);
}
    
/**
 * Sets the specified flag in the data value at the specified index.
 *
 * If the flag was already set, it remains set.
 *
 * To remove a flag, use [Object:RemoveFlag].
 *
 * @param uint16 index
 * @param uint32 value
 */
void TSObject::SetFlag(uint16 index,uint32 flag) 
{
    
    obj->SetFlag(index, flag);
}
    
/**
 * Sets the data at the specified index to the given value, converted to a signed 32-bit integer.
 *
 * @param uint16 index
 * @param int32 value
 */
void TSObject::SetInt32Value(uint16 index,int32 value) 
{
    obj->SetInt32Value(index, value);
}
    
/**
 * Sets the data at the specified index to the given value, converted to an unsigned 32-bit integer.
 *
 * @param uint16 index
 * @param uint32 value
 */
void TSObject::SetUInt32Value(uint16 index,uint32 value) 
{
    obj->SetUInt32Value(index, value);
}
    
/**
 * Sets the data at the specified index to the given value, converted to an unsigned 32-bit integer.
 *
 * @param uint16 index
 * @param uint32 value
 */
void TSObject::UpdateUInt32Value(uint16 index,uint32 value) 
{
    obj->UpdateUInt32Value(index, value);
}
    
/**
 * Sets the data at the specified index to the given value, converted to a single-precision floating point value.
 *
 * @param uint16 index
 * @param float value
 */
void TSObject::SetFloatValue(uint16 index,float value) 
{
    
    obj->SetFloatValue(index, value);
}
    
/**
 * Sets the data at the specified index and offset to the given value, converted to an unsigned 8-bit integer.
 *
 * @param uint16 index
 * @param uint8 offset : should be 0, 1, 2, or 3
 * @param uint8 value
 */
void TSObject::SetByteValue(uint16 index,uint8 offset,uint8 value) 
{
    obj->SetByteValue(index, offset, value);
}
    
/**
 * Sets the data at the specified index to the given value, converted to an unsigned 16-bit integer.
 *
 * @param uint16 index
 * @param uint8 offset : should be 0 or 1
 * @param uint16 value
 */
void TSObject::SetUInt16Value(uint16 index,uint8 offset,uint16 value) 
{
    obj->SetUInt16Value(index, offset, value);
}
    
/**
 * Sets the data at the specified index to the given value, converted to a signed 16-bit integer.
 *
 * @param uint16 index
 * @param uint8 offset : should be 0 or 1
 * @param int16 value
 */
void TSObject::SetInt16Value(uint16 index,uint8 offset,int16 value) 
{
    obj->SetInt16Value(index, offset, value);
}
    
/**
 * Sets the [Object]'s scale/size to the given value.
 *
 * @param float scale
 */
void TSObject::SetScale(float size) 
{
    
    obj->SetObjectScale(size);
}
    
/**
 * Sets the data at the specified index to the given value, converted to an unsigned 64-bit integer.
 *
 * @param uint16 index
 * @param uint64 value
 */
void TSObject::SetUInt64Value(uint16 index,uint64 value) 
{
    obj->SetUInt64Value(index, value);
}
    
/**
 * Removes a flag from the value at the specified index.
 *
 * @param uint16 index
 * @param uint32 flag
 */
void TSObject::RemoveFlag(uint16 index,uint32 flag) 
{
    
    obj->RemoveFlag(index, flag);
}
    