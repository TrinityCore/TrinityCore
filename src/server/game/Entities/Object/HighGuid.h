/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HighGuid_h__
#define HighGuid_h__

#include "Common.h"
#include <memory>

enum TypeID
{
    TYPEID_OBJECT = 0,
    TYPEID_ITEM = 1,
    TYPEID_CONTAINER = 2,
    TYPEID_UNIT = 3,
    TYPEID_PLAYER = 4,
    TYPEID_GAMEOBJECT = 5,
    TYPEID_DYNAMICOBJECT = 6,
    TYPEID_CORPSE = 7
};

#define NUM_CLIENT_OBJECT_TYPES             8

enum HighGuid
{
    HIGHGUID_ITEM = 0x4000,                      // blizz 4000
    HIGHGUID_CONTAINER = 0x4000,                 // blizz 4000
    HIGHGUID_PLAYER = 0x0000,                    // blizz 0000
    HIGHGUID_GAMEOBJECT = 0xF110,                // blizz F110
    HIGHGUID_TRANSPORT = 0xF120,                 // blizz F120 (for GAMEOBJECT_TYPE_TRANSPORT)
    HIGHGUID_UNIT = 0xF130,                      // blizz F130
    HIGHGUID_PET = 0xF140,                       // blizz F140
    HIGHGUID_VEHICLE = 0xF150,                   // blizz F550
    HIGHGUID_DYNAMICOBJECT = 0xF100,             // blizz F100
    HIGHGUID_CORPSE = 0xF101,                    // blizz F100
    HIGHGUID_MO_TRANSPORT = 0x1FC0,              // blizz 1FC0 (for GAMEOBJECT_TYPE_MO_TRANSPORT)
    HIGHGUID_INSTANCE = 0x1F40,                  // blizz 1F40
    HIGHGUID_GROUP = 0x1F50
};


class HighGuidBase
{
public:
    virtual HighGuid Guid() const = 0;
    virtual TypeID TypeId() const = 0;
    virtual bool HasEntry() const = 0;
    virtual std::string TypeName() const = 0;

    uint32 MaxCounter() const { return HasEntry() ? uint32(0x00FFFFFF) : uint32(0xFFFFFFFF); }
};

class ItemHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_ITEM; }
    TypeID TypeId() const override { return TYPEID_ITEM; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "Item"; }
};

class UnitHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_UNIT; }
    TypeID TypeId() const override { return TYPEID_UNIT; }
    bool HasEntry() const override { return true; }
    std::string TypeName() const override  { return "Unit"; }
};

class PetHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_PET; }
    TypeID TypeId() const override { return TYPEID_UNIT; }
    bool HasEntry() const override { return true; }
    std::string TypeName() const override  { return "Pet"; }
};

class PlayerHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_PLAYER; }
    TypeID TypeId() const override { return TYPEID_PLAYER; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "Player"; }
};

class GameObjectHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_GAMEOBJECT; }
    TypeID TypeId() const override { return TYPEID_GAMEOBJECT; }
    bool HasEntry() const override { return true; }
    std::string TypeName() const override  { return "GameObject"; }
};

class DynamicObjectHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_DYNAMICOBJECT; }
    TypeID TypeId() const override { return TYPEID_DYNAMICOBJECT; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "DynamicObject"; }
};

class CorpseHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_CORPSE; }
    TypeID TypeId() const override { return TYPEID_CORPSE; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "Corpse"; }
};

class MoTransportHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_MO_TRANSPORT; }
    TypeID TypeId() const override { return TYPEID_GAMEOBJECT; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "MO transport"; }
};

class VehicleHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_VEHICLE; }
    TypeID TypeId() const override { return TYPEID_UNIT; }
    bool HasEntry() const override { return true; }
    std::string TypeName() const override  { return "Vehicle"; }
};

class InstanceHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_INSTANCE; } // unknown
    TypeID TypeId() const override { return TYPEID_OBJECT; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "InstanceID"; }
};

class GroupHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_GROUP; } // unknown
    TypeID TypeId() const override { return TYPEID_OBJECT; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "Group"; }
};

class ContainerHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_CONTAINER; }
    TypeID TypeId() const override { return TYPEID_CONTAINER; }
    bool HasEntry() const override { return false; }
    std::string TypeName() const override  { return "Container"; }
};


class DefaultHighGuid : public HighGuidBase
{
public:
    HighGuid Guid() const override { return HIGHGUID_PLAYER; }
    TypeID TypeId() const override { return TYPEID_OBJECT; }
    bool HasEntry() const override { return true; }
    std::string TypeName() const override  { return "<Unknown>"; }
};

class HighGuidFactory
{
public:
    static HighGuidBase* Create(uint64 guid)
    {
        auto high = HighGuid((guid >> 48) & 0x0000FFFF);
        return Create(high);
    }

    static HighGuidBase* Create(HighGuid type)
    {
        switch (type){
         case HIGHGUID_ITEM:          return new ItemHighGuid();
         //case HIGHGUID_CONTAINER:     return new ContainerHighGuid();
         case HIGHGUID_UNIT:         return new UnitHighGuid();
         case HIGHGUID_PET:          return new PetHighGuid();
         case HIGHGUID_PLAYER:       return new PlayerHighGuid();
         case HIGHGUID_GAMEOBJECT:   return new GameObjectHighGuid();
         case HIGHGUID_DYNAMICOBJECT: return new DynamicObjectHighGuid();
         case HIGHGUID_CORPSE:       return new CorpseHighGuid();
         case HIGHGUID_MO_TRANSPORT: return new MoTransportHighGuid();
         case HIGHGUID_VEHICLE:      return new VehicleHighGuid();
         // unknown
         case HIGHGUID_INSTANCE:     return new InstanceHighGuid();
         case HIGHGUID_GROUP:        return new GroupHighGuid();
         default:                    return new DefaultHighGuid();
        }
    }
};

#endif