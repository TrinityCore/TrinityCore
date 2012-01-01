/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Corpse.h"
#include "Player.h"
#include "UpdateMask.h"
#include "ObjectAccessor.h"
#include "DatabaseEnv.h"
#include "Opcodes.h"
#include "GossipDef.h"
#include "World.h"

Corpse::Corpse(CorpseType type) : WorldObject(type != CORPSE_BONES)
, m_type(type)
{
    m_objectType |= TYPEMASK_CORPSE;
    m_objectTypeId = TYPEID_CORPSE;

    m_updateFlag = (UPDATEFLAG_HIGHGUID | UPDATEFLAG_HAS_POSITION | UPDATEFLAG_POSITION);

    m_valuesCount = CORPSE_END;

    m_time = time(NULL);

    lootForBody = false;
}

Corpse::~Corpse()
{
}

void Corpse::AddToWorld()
{
    ///- Register the corpse for guid lookup
    if (!IsInWorld())
        sObjectAccessor->AddObject(this);

    Object::AddToWorld();
}

void Corpse::RemoveFromWorld()
{
    ///- Remove the corpse from the accessor
    if (IsInWorld())
        sObjectAccessor->RemoveObject(this);

    Object::RemoveFromWorld();
}

bool Corpse::Create(uint32 guidlow, Map* map)
{
    SetMap(map);
    Object::_Create(guidlow, 0, HIGHGUID_CORPSE);
    return true;
}

bool Corpse::Create(uint32 guidlow, Player* owner)
{
    ASSERT(owner);

    Relocate(owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ(), owner->GetOrientation());

    if (!IsPositionValid())
    {
        sLog->outError("Corpse (guidlow %d, owner %s) not created. Suggested coordinates isn't valid (X: %f Y: %f)",
            guidlow, owner->GetName(), owner->GetPositionX(), owner->GetPositionY());
        return false;
    }

    //we need to assign owner's map for corpse
    //in other way we will get a crash in Corpse::SaveToDB()
    SetMap(owner->GetMap());

    WorldObject::_Create(guidlow, HIGHGUID_CORPSE, owner->GetPhaseMask());

    SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
    SetUInt64Value(CORPSE_FIELD_OWNER, owner->GetGUID());

    _gridCoord = Trinity::ComputeGridCoord(GetPositionX(), GetPositionY());

    return true;
}

void Corpse::SaveToDB()
{
    // prevent DB data inconsistence problems and duplicates
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    DeleteFromDB(trans);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CORPSE);
    stmt->setUInt32(0, GetGUIDLow());                                           // corpseGuid
    stmt->setUInt32(1, GUID_LOPART(GetOwnerGUID()));                            // guid
    stmt->setFloat (2, GetPositionX());                                         // posX
    stmt->setFloat (3, GetPositionY());                                         // posY
    stmt->setFloat (4, GetPositionZ());                                         // posZ
    stmt->setFloat (5, GetOrientation());                                       // orientation
    stmt->setUInt16(6, GetMapId());                                             // mapId
    stmt->setUInt32(7, GetUInt32Value(CORPSE_FIELD_DISPLAY_ID));                // displayId
    stmt->setString(8, _ConcatFields(CORPSE_FIELD_ITEM, EQUIPMENT_SLOT_END));   // itemCache
    stmt->setUInt32(9, GetUInt32Value(CORPSE_FIELD_BYTES_1));                   // bytes1
    stmt->setUInt32(10, GetUInt32Value(CORPSE_FIELD_BYTES_2));                  // bytes2
    stmt->setUInt32(11, GetUInt32Value(CORPSE_FIELD_GUILD));                    // guildId
    stmt->setUInt8 (12, GetUInt32Value(CORPSE_FIELD_FLAGS));                    // flags
    stmt->setUInt8 (13, GetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS));            // dynFlags
    stmt->setUInt32(14, uint32(m_time));                                        // time
    stmt->setUInt8 (15, GetType());                                             // corpseType
    stmt->setUInt32(16, GetInstanceId());                                       // instanceId
    stmt->setUInt16(17, GetPhaseMask());                                        // phaseMask
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void Corpse::DeleteBonesFromWorld()
{
    ASSERT(GetType() == CORPSE_BONES);
    Corpse* corpse = ObjectAccessor::GetCorpse(*this, GetGUID());

    if (!corpse)
    {
        sLog->outError("Bones %u not found in world.", GetGUIDLow());
        return;
    }

    AddObjectToRemoveList();
}

void Corpse::DeleteFromDB(SQLTransaction& trans)
{
    PreparedStatement* stmt = NULL;
    if (GetType() == CORPSE_BONES)
    {
        // Only specific bones
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CORPSE);
        stmt->setUInt32(0, GetGUIDLow());
    }
    else
    {
        // all corpses (not bones)
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PLAYER_CORPSES);
        stmt->setUInt32(0, GUID_LOPART(GetOwnerGUID()));
    }
    trans->Append(stmt);
}

bool Corpse::LoadCorpseFromDB(uint32 guid, Field* fields)
{
    uint32 ownerGuid = fields[17].GetUInt32();
    //        0     1     2     3            4      5          6          7       8       9        10     11        12    13          14          15         16          17
    // SELECT posX, posY, posZ, orientation, mapId, displayId, itemCache, bytes1, bytes2, guildId, flags, dynFlags, time, corpseType, instanceId, phaseMask, corpseGuid, guid FROM corpse WHERE corpseType <> 0
    float posX   = fields[0].GetFloat();
    float posY   = fields[1].GetFloat();
    float posZ   = fields[2].GetFloat();
    float o      = fields[3].GetFloat();
    uint32 mapId = fields[4].GetUInt16();

    Object::_Create(guid, 0, HIGHGUID_CORPSE);

    SetUInt32Value(CORPSE_FIELD_DISPLAY_ID, fields[5].GetUInt32());
    _LoadIntoDataField(fields[6].GetCString(), CORPSE_FIELD_ITEM, EQUIPMENT_SLOT_END);
    SetUInt32Value(CORPSE_FIELD_BYTES_1, fields[7].GetUInt32());
    SetUInt32Value(CORPSE_FIELD_BYTES_2, fields[8].GetUInt32());
    SetUInt32Value(CORPSE_FIELD_GUILD, fields[9].GetUInt32());
    SetUInt32Value(CORPSE_FIELD_FLAGS, fields[10].GetUInt8());
    SetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS, fields[11].GetUInt8());
    SetUInt64Value(CORPSE_FIELD_OWNER, MAKE_NEW_GUID(ownerGuid, 0, HIGHGUID_PLAYER));

    m_time = time_t(fields[12].GetUInt32());

    uint32 instanceId  = fields[14].GetUInt32();
    uint32 phaseMask   = fields[15].GetUInt16();

    // place
    SetLocationInstanceId(instanceId);
    SetLocationMapId(mapId);
    SetPhaseMask(phaseMask, false);
    Relocate(posX, posY, posZ, o);

    if (!IsPositionValid())
    {
        sLog->outError("Corpse (guid: %u, owner: %u) is not created, given coordinates are not valid (X: %f, Y: %f, Z: %f)",
            GetGUIDLow(), GUID_LOPART(GetOwnerGUID()), posX, posY, posZ);
        return false;
    }

    _gridCoord = Trinity::ComputeGridCoord(GetPositionX(), GetPositionY());
    return true;
}

bool Corpse::IsExpired(time_t t) const
{
    if (m_type == CORPSE_BONES)
        return m_time < t - 60 * MINUTE;
    else
        return m_time < t - 3 * DAY;
}
