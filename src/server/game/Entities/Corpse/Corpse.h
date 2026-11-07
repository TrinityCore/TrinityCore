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
#include "IteratorPair.h"

struct Loot;

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

DEFINE_ENUM_FLAG(CorpseFlags);

class TC_GAME_API Corpse final : public WorldObject, public GridObject<Corpse>
{
    public:
        explicit Corpse(CorpseType type = CORPSE_BONES);
        ~Corpse();

    protected:
        void BuildValuesCreate(UF::UpdateFieldFlag flags, ByteBuffer& data, Player const* target) const override;
        void BuildValuesUpdate(UF::UpdateFieldFlag flags, ByteBuffer& data, Player const* target) const override;
        void ClearValuesChangesMask() override;

    public:
        void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
            UF::CorpseData::Mask const& requestedCorpseMask, Player const* target, bool ignoreNestedChangesMask) const;

        struct ValuesUpdateForPlayerWithMaskSender // sender compatible with MessageDistDeliverer
        {
            explicit ValuesUpdateForPlayerWithMaskSender(Corpse const* owner) : Owner(owner), IgnoreNestedChangesMask(false) { }

            Corpse const* Owner;
            UF::ObjectData::Base ObjectMask;
            UF::CorpseData::Base CorpseMask;
            bool IgnoreNestedChangesMask;

            void operator()(Player const* player) const;
        };

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool Create(ObjectGuid::LowType guidlow, Map* map);
        bool Create(ObjectGuid::LowType guidlow, Player* owner);

        void Update(uint32 diff) override;

        void SaveToDB();
        bool LoadCorpseFromDB(ObjectGuid::LowType guid, Field* fields);

        void DeleteFromDB(CharacterDatabaseTransaction trans);
        static void DeleteFromDB(ObjectGuid const& ownerGuid, CharacterDatabaseTransaction trans);

        CorpseFlags GetCorpseFlags() const { return CorpseFlags(*m_corpseData->Flags); }
        bool HasCorpseFlag(CorpseFlags flags) const { return (*m_corpseData->Flags & flags) != 0; }
        void SetCorpseFlag(CorpseFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Flags), flags); }
        void RemoveCorpseFlag(CorpseFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Flags), flags); }
        void ReplaceAllCorpseFlags(CorpseFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Flags), flags); }

        CorpseDynFlags GetCorpseDynamicFlags() const { return CorpseDynFlags(*m_corpseData->DynamicFlags); }
        bool HasCorpseDynamicFlag(CorpseDynFlags flags) const { return (*m_corpseData->DynamicFlags & flags) != 0; }
        void SetCorpseDynamicFlag(CorpseDynFlags dynamicFlags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DynamicFlags), dynamicFlags); }
        void RemoveCorpseDynamicFlag(CorpseDynFlags dynamicFlags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DynamicFlags), dynamicFlags); }
        void ReplaceAllCorpseDynamicFlags(CorpseDynFlags dynamicFlags) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DynamicFlags), dynamicFlags); }

        ObjectGuid GetCreatorGUID() const override { return m_corpseData->Owner; }
        ObjectGuid GetOwnerGUID() const override { return m_corpseData->Owner; }
        void SetOwnerGUID(ObjectGuid owner) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Owner), owner); }
        ObjectGuid GetPartyGUID() const { return m_corpseData->PartyGUID; }
        void SetPartyGUID(ObjectGuid partyGuid) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::PartyGUID), partyGuid); }
        ObjectGuid GetGuildGUID() const { return m_corpseData->GuildGUID; }
        void SetGuildGUID(ObjectGuid guildGuid) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::GuildGUID), guildGuid); }
        uint32 GetDisplayId() const { return m_corpseData->DisplayID; }
        void SetDisplayId(uint32 displayId) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::DisplayID), displayId); }
        uint8 GetRace() const { return m_corpseData->RaceID; }
        void SetRace(uint8 race) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::RaceID), race); }
        uint8 GetClass() const { return m_corpseData->Class; }
        void SetClass(uint8 playerClass) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Class), playerClass); }
        uint8 GetSex() const { return m_corpseData->Sex; }
        void SetSex(uint8 sex) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Sex), sex); }
        uint32 GetFactionTemplate() const { return m_corpseData->FactionTemplate; }
        void SetFactionTemplate(int32 factionTemplate) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::FactionTemplate), factionTemplate); }
        uint32 GetFaction() const override { return m_corpseData->FactionTemplate; }
        void SetFaction(uint32 faction) override { SetFactionTemplate(faction); }
        uint32 GetItem(uint32 slot) const { return m_corpseData->Items[slot]; }
        void SetItem(uint32 slot, uint32 item) { SetUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Items, slot), item); }

        std::span<UF::ChrCustomizationChoice const> GetCustomizations() const { return { m_corpseData->Customizations.begin(), m_corpseData->Customizations.end() }; }
        void SetCustomizations(std::span<UF::ChrCustomizationChoice const> customizations)
        {
            ClearDynamicUpdateFieldValues(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Customizations));
            for (UF::ChrCustomizationChoice const& customization : customizations)
                AddDynamicUpdateFieldValue(m_values.ModifyValue(&Corpse::m_corpseData).ModifyValue(&UF::CorpseData::Customizations)) = customization;
        }

        time_t const& GetGhostTime() const { return m_time; }
        void ResetGhostTime();
        CorpseType GetType() const { return m_type; }

        std::unique_ptr<Loot> m_loot;
        Loot* GetLootForPlayer(Player const* /*player*/) const override { return m_loot.get(); }

        Player* lootRecipient;

        bool IsExpired(time_t t) const;

        UF::UpdateField<UF::CorpseData, int32(WowCS::EntityFragment::CGObject), TYPEID_CORPSE> m_corpseData;

    private:
        CorpseType m_type;
        time_t m_time;
};
#endif
