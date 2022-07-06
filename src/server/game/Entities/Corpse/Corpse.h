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
#include "DatabaseEnvFwd.h"
#include "GridDefines.h"
#include "IteratorPair.h"
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
    CORPSE_FLAG_PVP         = 0x04,
    CORPSE_FLAG_HIDE_HELM   = 0x08,
    CORPSE_FLAG_HIDE_CLOAK  = 0x10,
    CORPSE_FLAG_SKINNABLE   = 0x20,
    CORPSE_FLAG_FFA_PVP     = 0x40
};

class TC_GAME_API Corpse : public WorldObject, public GridObject<Corpse>
{
    public:
        explicit Corpse(CorpseType type = CORPSE_BONES);
        ~Corpse();

    protected:
        void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
        void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
        void ClearUpdateMask(bool remove) override;

    public:
        void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
            UF::CorpseData::Mask const& requestedCorpseMask, Player const* target) const;

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool Create(ObjectGuid::LowType guidlow, Map* map);
        bool Create(ObjectGuid::LowType guidlow, Player* owner);

        void SaveToDB();
        bool LoadCorpseFromDB(ObjectGuid::LowType guid, Field* fields);

        void DeleteFromDB(CharacterDatabaseTransaction& trans);
        static void DeleteFromDB(ObjectGuid const& ownerGuid, CharacterDatabaseTransaction& trans);

        void AddCorpseDynamicFlag(CorpseDynFlags dynamicFlags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DynamicFlags), dynamicFlags); }
        void RemoveCorpseDynamicFlag(CorpseDynFlags dynamicFlags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DynamicFlags), dynamicFlags); }
        void SetCorpseDynamicFlags(CorpseDynFlags dynamicFlags) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DynamicFlags), dynamicFlags); }
        ObjectGuid GetOwnerGUID() const { return m_corpseData->Owner; }
        void SetOwnerGUID(ObjectGuid owner) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Owner), owner); }
        void SetPartyGUID(ObjectGuid partyGuid) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::PartyGUID), partyGuid); }
        void SetGuildGUID(ObjectGuid guildGuid) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::GuildGUID), guildGuid); }
        void SetDisplayId(uint32 displayId) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DisplayID), displayId); }
        void SetRace(uint8 race) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::RaceID), race); }
        void SetClass(uint8 playerClass) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Class), playerClass); }
        void SetSex(uint8 sex) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Sex), sex); }
        void SetFlags(uint32 flags) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Flags), flags); }
        void SetFactionTemplate(int32 factionTemplate) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::FactionTemplate), factionTemplate); }
        void SetItem(uint32 slot, uint32 item) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Items, slot), item); }

        template<typename Iter>
        void SetCustomizations(Trinity::IteratorPair<Iter> customizations)
        {
            ClearDynamicUpdateFieldValues(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Customizations));
            for (auto&& customization : customizations)
            {
                UF::ChrCustomizationChoice& newChoice = AddDynamicUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Customizations));
                newChoice.ChrCustomizationOptionID = customization.ChrCustomizationOptionID;
                newChoice.ChrCustomizationChoiceID = customization.ChrCustomizationChoiceID;
            }
        }

        time_t const& GetGhostTime() const { return m_time; }
        void ResetGhostTime();
        CorpseType GetType() const { return m_type; }

        CellCoord const& GetCellCoord() const { return _cellCoord; }
        void SetCellCoord(CellCoord const& cellCoord) { _cellCoord = cellCoord; }

        Loot loot;                                          // remove insignia ONLY at BG
        Player* lootRecipient;

        bool IsExpired(time_t t) const;

        UF::UpdateField<UF::CorpseData, 0, TYPEID_CORPSE> m_corpseData;

    private:
        CorpseType m_type;
        time_t m_time;
        CellCoord _cellCoord;
};
#endif
