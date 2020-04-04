/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "CharacterCache.h"
#include "Common.h"
#include "Corpse.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "UpdateData.h"
#include "World.h"
#include <sstream>

Corpse::Corpse(CorpseType type) : WorldObject(type != CORPSE_BONES), m_type(type)
{
    m_objectType |= TYPEMASK_CORPSE;
    m_objectTypeId = TYPEID_CORPSE;

    m_updateFlag.Stationary = true;

    m_time = time(NULL);

    lootRecipient = nullptr;
}

Corpse::~Corpse() { }

void Corpse::AddToWorld()
{
    ///- Register the corpse for guid lookup
    if (!IsInWorld())
        GetMap()->GetObjectsStore().Insert<Corpse>(GetGUID(), this);

    Object::AddToWorld();
}

void Corpse::RemoveFromWorld()
{
    ///- Remove the corpse from the accessor
    if (IsInWorld())
        GetMap()->GetObjectsStore().Remove<Corpse>(GetGUID());

    WorldObject::RemoveFromWorld();
}

bool Corpse::Create(ObjectGuid::LowType guidlow, Map* map)
{
    Object::_Create(ObjectGuid::Create<HighGuid::Corpse>(map->GetId(), 0, guidlow));
    return true;
}

bool Corpse::Create(ObjectGuid::LowType guidlow, Player* owner)
{
    ASSERT(owner);

    Relocate(owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ(), owner->GetOrientation());

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.player", "Corpse (guidlow " UI64FMTD ", owner %s) not created. Suggested coordinates isn't valid (X: %f Y: %f)",
            guidlow, owner->GetName().c_str(), owner->GetPositionX(), owner->GetPositionY());
        return false;
    }

    Object::_Create(ObjectGuid::Create<HighGuid::Corpse>(owner->GetMapId(), 0, guidlow));

    SetObjectScale(1.0f);
    SetOwnerGUID(owner->GetGUID());

    _cellCoord = Trinity::ComputeCellCoord(GetPositionX(), GetPositionY());

    PhasingHandler::InheritPhaseShift(this, owner);

    return true;
}

void Corpse::SaveToDB()
{
    // prevent DB data inconsistence problems and duplicates
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    DeleteFromDB(trans);

    std::ostringstream items;
    for (uint16 index = 0; index < EQUIPMENT_SLOT_END; ++index)
        items << m_corpseData->Items[index] << ' ';

    uint32 bytes1 = (uint32(*m_corpseData->RaceID) << 8) | (uint32(*m_corpseData->Sex) << 16) | (uint32(*m_corpseData->SkinID) << 24);
    uint32 bytes2 = (uint32(*m_corpseData->FaceID)) | (uint32(*m_corpseData->HairStyleID) << 8) | (uint32(*m_corpseData->HairColorID) << 16) | (uint32(*m_corpseData->FacialHairStyleID) << 24);

    uint16 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CORPSE);
    stmt->setUInt64(index++, GetOwnerGUID().GetCounter());                            // guid
    stmt->setFloat (index++, GetPositionX());                                         // posX
    stmt->setFloat (index++, GetPositionY());                                         // posY
    stmt->setFloat (index++, GetPositionZ());                                         // posZ
    stmt->setFloat (index++, GetOrientation());                                       // orientation
    stmt->setUInt16(index++, GetMapId());                                             // mapId
    stmt->setUInt32(index++, m_corpseData->DisplayID);                                // displayId
    stmt->setString(index++, items.str());                                            // itemCache
    stmt->setUInt32(index++, bytes1);                                                 // bytes1
    stmt->setUInt32(index++, bytes2);                                                 // bytes2
    stmt->setUInt8 (index++, m_corpseData->Flags);                                    // flags
    stmt->setUInt8 (index++, m_corpseData->DynamicFlags);                             // dynFlags
    stmt->setUInt32(index++, uint32(m_time));                                         // time
    stmt->setUInt8 (index++, GetType());                                              // corpseType
    stmt->setUInt32(index++, GetInstanceId());                                        // instanceId
    trans->Append(stmt);

    for (PhaseShift::PhaseRef const& phase : GetPhaseShift().GetPhases())
    {
        index = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CORPSE_PHASES);
        stmt->setUInt64(index++, GetOwnerGUID().GetCounter());                        // OwnerGuid
        stmt->setUInt32(index++, phase.Id);                                           // PhaseId
        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);
}

void Corpse::DeleteFromDB(CharacterDatabaseTransaction& trans)
{
    DeleteFromDB(GetOwnerGUID(), trans);
}

void Corpse::DeleteFromDB(ObjectGuid const& ownerGuid, CharacterDatabaseTransaction& trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CORPSE);
    stmt->setUInt64(0, ownerGuid.GetCounter());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CORPSE_PHASES);
    stmt->setUInt64(0, ownerGuid.GetCounter());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

bool Corpse::LoadCorpseFromDB(ObjectGuid::LowType guid, Field* fields)
{
    //        0     1     2     3            4      5          6          7       8       9      10        11    12          13          14
    // SELECT posX, posY, posZ, orientation, mapId, displayId, itemCache, bytes1, bytes2, flags, dynFlags, time, corpseType, instanceId, guid FROM corpse WHERE mapId = ? AND instanceId = ?

    float posX   = fields[0].GetFloat();
    float posY   = fields[1].GetFloat();
    float posZ   = fields[2].GetFloat();
    float o      = fields[3].GetFloat();
    uint32 mapId = fields[4].GetUInt16();

    Object::_Create(ObjectGuid::Create<HighGuid::Corpse>(mapId, 0, guid));

    SetObjectScale(1.0f);
    SetDisplayId(fields[5].GetUInt32());
    Tokenizer items(fields[6].GetString(), ' ', EQUIPMENT_SLOT_END);
    if (items.size() == EQUIPMENT_SLOT_END)
        for (uint32 index = 0; index < EQUIPMENT_SLOT_END; ++index)
            SetItem(index, atoul(items[index]));

    uint32 bytes1 = fields[7].GetUInt32();
    uint32 bytes2 = fields[8].GetUInt32();
    SetRace((bytes1 >> 8) & 0xFF);
    SetSex((bytes1 >> 16) & 0xFF);
    SetSkin((bytes1 >> 24) & 0xFF);
    SetFace(bytes2 & 0xFF);
    SetHairStyle((bytes2 >> 8) & 0xFF);
    SetHairColor((bytes2 >> 16) & 0xFF);
    SetFacialHairStyle((bytes2 >> 24) & 0xFF);
    SetFlags(fields[9].GetUInt8());
    SetCorpseDynamicFlags(CorpseDynFlags(fields[10].GetUInt8()));
    SetOwnerGUID(ObjectGuid::Create<HighGuid::Player>(fields[14].GetUInt64()));
    SetFactionTemplate(sChrRacesStore.AssertEntry(m_corpseData->RaceID)->FactionID);

    m_time = time_t(fields[11].GetUInt32());

    uint32 instanceId  = fields[13].GetUInt32();

    // place
    SetLocationInstanceId(instanceId);
    SetLocationMapId(mapId);
    Relocate(posX, posY, posZ, o);

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.player", "Corpse (%s, owner: %s) is not created, given coordinates are not valid (X: %f, Y: %f, Z: %f)",
            GetGUID().ToString().c_str(), GetOwnerGUID().ToString().c_str(), posX, posY, posZ);
        return false;
    }

    _cellCoord = Trinity::ComputeCellCoord(GetPositionX(), GetPositionY());
    return true;
}

bool Corpse::IsExpired(time_t t) const
{
    // Deleted character
    if (!sCharacterCache->HasCharacterCacheEntry(GetOwnerGUID()))
        return true;

    if (m_type == CORPSE_BONES)
        return m_time < t - 60 * MINUTE;
    else
        return m_time < t - 3 * DAY;
}

void Corpse::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_corpseData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Corpse::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_CORPSE))
        m_corpseData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Corpse::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&Corpse::m_corpseData);
    Object::ClearUpdateMask(remove);
}
