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

#ifndef TRINITYCORE_CORPSE_H
#define TRINITYCORE_CORPSE_H

#include "Object.h"
#include "GridObject.h"
#include "DatabaseEnvFwd.h"
#include "GridDefines.h"
#include "Loot.h"

enum CorpseType
{
    CORPSE_BONES             = 0,
    CORPSE_RESURRECTABLE_PVE = 1,
    CORPSE_RESURRECTABLE_PVP = 2
};
#define MAX_CORPSE_TYPE        3

// Value equal client resurrection dialog show radius.
#define CORPSE_RECLAIM_RADIUS 39

enum CorpseFlags
{
    CORPSE_FLAG_NONE        = 0x00,
    CORPSE_FLAG_BONES       = 0x01,
    CORPSE_FLAG_UNK1        = 0x02,
    CORPSE_FLAG_UNK2        = 0x04,
    CORPSE_FLAG_HIDE_HELM   = 0x08,
    CORPSE_FLAG_HIDE_CLOAK  = 0x10,
    CORPSE_FLAG_LOOTABLE    = 0x20
};

DEFINE_ENUM_FLAG(CorpseFlags);

class TC_GAME_API Corpse : public WorldObject, public GridObject<Corpse>
{
    public:
        explicit Corpse(CorpseType type = CORPSE_BONES);
        ~Corpse();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool Create(ObjectGuid::LowType guidlow);
        bool Create(ObjectGuid::LowType guidlow, Player* owner);

        void SaveToDB();
        bool LoadCorpseFromDB(ObjectGuid::LowType guid, Field* fields);

        void DeleteFromDB(CharacterDatabaseTransaction trans);
        static void DeleteFromDB(ObjectGuid const& ownerGuid, CharacterDatabaseTransaction trans);

        CorpseFlags GetCorpseFlags() const { return CorpseFlags(GetUInt32Value(CORPSE_FIELD_FLAGS)); }
        bool HasCorpseFlag(CorpseFlags flags) const { return (GetUInt32Value(CORPSE_FIELD_FLAGS) & flags) != 0; }
        void SetCorpseFlag(CorpseFlags flags) { SetFlag(CORPSE_FIELD_FLAGS, flags); }
        void RemoveCorpseFlag(CorpseFlags flags) { RemoveFlag(CORPSE_FIELD_FLAGS, flags); }
        void ReplaceAllCorpseFlags(CorpseFlags flags) { SetUInt32Value(CORPSE_FIELD_FLAGS, flags); }

        CorpseDynFlags GetCorpseDynamicFlags() const { return CorpseDynFlags(GetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS)); }
        bool HasCorpseDynamicFlag(CorpseDynFlags flags) const { return (GetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS) & flags) != 0; }
        void SetCorpseDynamicFlag(CorpseDynFlags flag) { SetFlag(CORPSE_FIELD_DYNAMIC_FLAGS, flag); }
        void RemoveCorpseDynamicFlag(CorpseDynFlags flag) { RemoveFlag(CORPSE_FIELD_DYNAMIC_FLAGS, flag); }
        void ReplaceAllCorpseDynamicFlags(CorpseDynFlags flag) { SetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS, flag); }

        ObjectGuid GetOwnerGUID() const override { return GetGuidValue(CORPSE_FIELD_OWNER); }
        void SetOwnerGUID(ObjectGuid owner) { SetGuidValue(CORPSE_FIELD_OWNER, owner); }
        ObjectGuid GetPartyGUID() const { return GetGuidValue(CORPSE_FIELD_PARTY); }
        void SetPartyGUID(ObjectGuid partyGuid) { SetGuidValue(CORPSE_FIELD_PARTY, partyGuid); }
        uint32 GetGuildId() const { return GetUInt32Value(CORPSE_FIELD_GUILD); }
        void SetGuildId(uint32 guildId) { SetUInt32Value(CORPSE_FIELD_GUILD, guildId); }
        uint32 GetDisplayId() const { return GetUInt32Value(CORPSE_FIELD_DISPLAY_ID); }
        void SetDisplayId(uint32 displayId) { SetUInt32Value(CORPSE_FIELD_DISPLAY_ID, displayId); }
        uint8 GetRace() const { return GetByteValue(CORPSE_FIELD_BYTES_1, 1); }
        void SetRace(uint8 race) { SetByteValue(CORPSE_FIELD_BYTES_1, 1, race); }
        uint8 GetSex() const { return GetByteValue(CORPSE_FIELD_BYTES_1, 2); }
        void SetSex(uint8 sex) { SetByteValue(CORPSE_FIELD_BYTES_1, 2, sex); }
        uint32 GetFaction() const override;
        uint32 GetItem(uint32 slot) const { return GetUInt32Value(CORPSE_FIELD_ITEM + slot); }
        void SetItem(uint32 slot, uint32 item) { SetUInt32Value(CORPSE_FIELD_ITEM + slot, item); }

        uint8 GetSkinId() const { return GetByteValue(CORPSE_FIELD_BYTES_1, 3); }
        void SetSkinId(uint8 skin) { SetByteValue(CORPSE_FIELD_BYTES_1, 3, skin); }
        uint8 GetFaceId() const { return GetByteValue(CORPSE_FIELD_BYTES_2, 0); }
        void SetFaceId(uint8 face) { SetByteValue(CORPSE_FIELD_BYTES_2, 0, face); }
        uint8 GetHairStyleId() const { return GetByteValue(CORPSE_FIELD_BYTES_2, 1); }
        void SetHairStyleId(uint8 hairStyle) { SetByteValue(CORPSE_FIELD_BYTES_2, 1, hairStyle); }
        uint8 GetHairColorId() const { return GetByteValue(CORPSE_FIELD_BYTES_2, 2); }
        void SetHairColorId(uint8 hairColor) { SetByteValue(CORPSE_FIELD_BYTES_2, 2, hairColor); }
        uint8 GetFacialStyle() const { return GetByteValue(CORPSE_FIELD_BYTES_2, 3); }
        void SetFacialStyle(uint8 facialStyle) { SetByteValue(CORPSE_FIELD_BYTES_2, 3, facialStyle); }

        time_t const& GetGhostTime() const { return m_time; }
        void ResetGhostTime();
        CorpseType GetType() const { return m_type; }

        CellCoord const& GetCellCoord() const { return _cellCoord; }
        void SetCellCoord(CellCoord const& cellCoord) { _cellCoord = cellCoord; }

        Loot loot;                                          // remove insignia ONLY at BG
        Player* lootRecipient;

        bool IsExpired(time_t t) const;

    private:
        CorpseType m_type;
        time_t m_time;
        CellCoord _cellCoord;
};
#endif
