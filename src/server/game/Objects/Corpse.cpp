/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Corpse.h"
#include "Player.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "ObjectGuid.h"
#include "Database/DatabaseEnv.h"
#include "World.h"
#include "ObjectMgr.h"

Corpse::Corpse(CorpseType type) : WorldObject(), loot(nullptr), lootRecipient(nullptr), m_faction(nullptr)
{
    m_objectType |= TYPEMASK_CORPSE;
    m_objectTypeId = TYPEID_CORPSE;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    m_updateFlag = (UPDATEFLAG_ALL | UPDATEFLAG_HAS_POSITION);
#else
    m_updateFlag = 0;
#endif
    m_valuesCount = CORPSE_END;

    m_type = type;

    m_time = time(nullptr);

    lootForBody = false;
}

Corpse::~Corpse()
{
    if (m_currMap && (GetType() == CORPSE_BONES))
        GetMap()->RemoveBones(this);
}

void Corpse::AddToWorld()
{
    ///- Register the corpse for guid lookup
    if (!IsInWorld())
        sObjectAccessor.AddObject(this);

    Object::AddToWorld();
}

void Corpse::RemoveFromWorld()
{
    ///- Remove the corpse from the accessor
    if (IsInWorld())
        sObjectAccessor.RemoveObject(this);

    Object::RemoveFromWorld();
}

bool Corpse::Create(uint32 guidlow)
{
    Object::_Create(guidlow, 0, HIGHGUID_CORPSE);
    return true;
}

bool Corpse::Create(uint32 guidlow, Player* owner)
{
    if (!owner)
        return false;

    WorldObject::_Create(guidlow, HIGHGUID_CORPSE);
    Relocate(owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ(), owner->GetOrientation());

    //we need to assign owner's map for corpse
    //in other way we will get a crash in Corpse::SaveToDB()
    SetMap(owner->GetMap());

    if (!IsPositionValid())
    {
        sLog.outError("Corpse (guidlow %d, owner %s) not created. Suggested coordinates isn't valid (X: %f Y: %f)",
                      guidlow, owner->GetName(), owner->GetPositionX(), owner->GetPositionY());
        return false;
    }

    SetObjectScale(DEFAULT_OBJECT_SCALE);
    SetFloatValue(CORPSE_FIELD_POS_X, GetPositionX());
    SetFloatValue(CORPSE_FIELD_POS_Y, GetPositionY());
    SetFloatValue(CORPSE_FIELD_POS_Z, GetPositionZ());
    SetFloatValue(CORPSE_FIELD_FACING, GetOrientation());
    SetGuidValue(CORPSE_FIELD_OWNER, owner->GetObjectGuid());

    m_grid = MaNGOS::ComputeGridPair(GetPositionX(), GetPositionY());

    return true;
}

void Corpse::SaveToDB()
{
    // bones should not be saved to DB (would be deleted on startup anyway)
    MANGOS_ASSERT(GetType() != CORPSE_BONES);

    std::ostringstream ss;
    ss  << "REPLACE INTO `corpse` (`guid`, `player_guid`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `time`, `corpse_type`, `instance`) VALUES ("
        << GetGUIDLow() << ", "
        << GetOwnerGuid().GetCounter() << ", "
        << GetPositionX() << ", "
        << GetPositionY() << ", "
        << GetPositionZ() << ", "
        << GetOrientation() << ", "
        << GetMapId() << ", "
        << uint64(m_time) << ", "
        << uint32(GetType()) << ", "
        << int(GetInstanceId()) << ")";
    CharacterDatabase.Execute(ss.str().c_str());
}

void Corpse::DeleteBonesFromWorld()
{
    MANGOS_ASSERT(GetType() == CORPSE_BONES);
    Corpse* corpse = GetMap()->GetCorpse(GetObjectGuid());

    if (!corpse)
    {
        sLog.outError("Bones %u not found in world.", GetGUIDLow());
        return;
    }

    AddObjectToRemoveList();
}

void Corpse::DeleteFromDB()
{
    // bones should not be saved to DB (would be deleted on startup anyway)
    MANGOS_ASSERT(GetType() != CORPSE_BONES);

    // all corpses (not bones)
    static SqlStatementID id;

    SqlStatement stmt = CharacterDatabase.CreateStatement(id, "DELETE FROM `corpse` WHERE `player_guid` = ? AND `corpse_type` <> '0'");
    stmt.PExecute(GetOwnerGuid().GetCounter());
}

bool Corpse::LoadFromDB(uint32 lowguid, Field* fields)
{
    ////                                                    0            1            2                  3                  4                  5                   6
    //QueryResult* result = CharacterDatabase.Query("SELECT corpse.guid, player_guid, corpse.position_x, corpse.position_y, corpse.position_z, corpse.orientation, corpse.map,"
    ////   7     8            9         10      11    12     13     14   15          16          17           18               19        20
    //    "time, corpse_type, instance, gender, race, class, skin, face, hair_style, hair_color, facial_hair, equipment_cache, guild_id, player_flags FROM corpse"
    uint32 playerLowGuid = fields[1].GetUInt32();
    float positionX     = fields[2].GetFloat();
    float positionY     = fields[3].GetFloat();
    float positionZ     = fields[4].GetFloat();
    float orientation   = fields[5].GetFloat();
    uint32 mapid        = fields[6].GetUInt32();

    Object::_Create(lowguid, 0, HIGHGUID_CORPSE);

    m_time = time_t(fields[7].GetUInt64());
    m_type = CorpseType(fields[8].GetUInt32());

    if (m_type >= MAX_CORPSE_TYPE)
    {
        sLog.outError("%s Owner %s have wrong corpse type (%i), not load.", GetGuidStr().c_str(), GetOwnerGuid().GetString().c_str(), m_type);
        return false;
    }

    uint32 instanceid   = fields[9].GetUInt32();
    uint8 gender        = fields[10].GetUInt8();
    uint8 race          = fields[11].GetUInt8();
    uint8 _class        = fields[12].GetUInt8();

    uint8 skin = fields[13].GetUInt8();
    uint8 face = fields[14].GetUInt8();
    uint8 hairstyle = fields[15].GetUInt8();
    uint8 haircolor = fields[16].GetUInt8();
    uint8 facialhair = fields[17].GetUInt8();

    uint32 guildId      = fields[19].GetUInt32();
    uint32 playerFlags  = fields[20].GetUInt32();

    ObjectGuid guid = ObjectGuid(HIGHGUID_CORPSE, lowguid);
    ObjectGuid playerGuid = ObjectGuid(HIGHGUID_PLAYER, playerLowGuid);

    // overwrite possible wrong/corrupted guid
    SetGuidValue(OBJECT_FIELD_GUID, guid);
    SetGuidValue(CORPSE_FIELD_OWNER, playerGuid);

    SetObjectScale(DEFAULT_OBJECT_SCALE);

    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(race, _class);
    if (!info)
    {
        sLog.outError("Player %u has incorrect race/class pair.", GetGUIDLow());
        return false;
    }
    SetUInt32Value(CORPSE_FIELD_DISPLAY_ID, gender == GENDER_FEMALE ? info->displayId_f : info->displayId_m);

    // Load equipment
    Tokens data = StrSplit(fields[18].GetCppString(), " ");
    for (uint8 slot = 0; slot < EQUIPMENT_SLOT_END; slot++)
    {
        uint32 visualbase = slot * 2;
        uint32 item_id = GetUInt32ValueFromArray(data, visualbase);
        ItemPrototype const* proto = ObjectMgr::GetItemPrototype(item_id);
        if (!proto)
        {
            SetUInt32Value(CORPSE_FIELD_ITEM + slot, 0);
            continue;
        }

        SetUInt32Value(CORPSE_FIELD_ITEM + slot, proto->DisplayInfoID | (proto->InventoryType << 24));
    }

    SetUInt32Value(CORPSE_FIELD_BYTES_1, ((0x00) | (race << 8) | (gender << 16) | (skin << 24)));
    SetUInt32Value(CORPSE_FIELD_BYTES_2, ((face) | (hairstyle << 8) | (haircolor << 16) | (facialhair << 24)));

    SetUInt32Value(CORPSE_FIELD_GUILD, guildId);

    uint32 flags = CORPSE_FLAG_UNK2;
    if (playerFlags & PLAYER_FLAGS_HIDE_HELM)
        flags |= CORPSE_FLAG_HIDE_HELM;
    if (playerFlags & PLAYER_FLAGS_HIDE_CLOAK)
        flags |= CORPSE_FLAG_HIDE_CLOAK;
    SetUInt32Value(CORPSE_FIELD_FLAGS, flags);

    // no need to mark corpse as lootable, because corpses are not saved in battle grounds

    if (mapid <= 1)
        instanceid = sMapMgr.GetContinentInstanceId(mapid, positionX, positionY);
    SetLocationInstanceId(instanceid);
    SetLocationMapId(mapid);
    Relocate(positionX, positionY, positionZ, orientation);

    if (!IsPositionValid())
    {
        sLog.outError("%s Owner %s not created. Suggested coordinates isn't valid (X: %f Y: %f)",
                      GetGuidStr().c_str(), GetOwnerGuid().GetString().c_str(), GetPositionX(), GetPositionY());
        return false;
    }

    m_grid = MaNGOS::ComputeGridPair(GetPositionX(), GetPositionY());

    return true;
}

bool Corpse::IsVisibleForInState(WorldObject const* pDetector, WorldObject const* viewPoint, bool inVisibleList) const
{
    return IsInWorld() && pDetector->IsInWorld() && IsWithinDist(viewPoint, std::max(pDetector->GetMap()->GetVisibilityDistance() + (inVisibleList ? World::GetVisibleObjectGreyDistance() : 0.0f), GetVisibilityModifier()), false);
}

ReputationRank Corpse::GetReactionTo(WorldObject const* target) const
{
    if (Player* owner = sObjectMgr.GetPlayer(GetOwnerGuid()))
        return owner->GetReactionTo(target);
    else if (target->IsPlayer() && target->ToPlayer()->GetGroup() && target->ToPlayer()->GetGroup()->IsMember(GetOwnerGuid()))
        return REP_FRIENDLY;
    else if (m_faction)
        return WorldObject::GetFactionReactionTo(m_faction, target);
    else
        return REP_NEUTRAL;
}

bool Corpse::IsHostileTo(WorldObject const* target) const
{
    return GetReactionTo(target) <= REP_HOSTILE;
}

bool Corpse::IsFriendlyTo(WorldObject const* target) const
{
    return GetReactionTo(target) >= REP_FRIENDLY;
}

bool Corpse::IsExpired(time_t t) const
{
    if (m_type == CORPSE_BONES)
        return m_time < t - sWorld.getConfig(CONFIG_UINT32_BONES_EXPIRE_MINUTES) * MINUTE;
    else
        return m_time < t - 3 * DAY;
}

uint32 Corpse::GetFactionTemplateId() const 
{
    return m_faction->ID;
}
