/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "DB2Utility.h"
#include "ObjectMgr.h"

inline bool ItemExists(uint32 id)
{
    return sObjectMgr->GetItemTemplate(id) != NULL;
}

bool DB2Utilities::HasItemEntry(DB2Storage<ItemEntry> const& /*store*/, uint32 id)
{
    return ItemExists(id);
}

bool DB2Utilities::HasItemSparseEntry(DB2Storage<ItemSparseEntry> const& /*store*/, uint32 id)
{
    return ItemExists(id);
}

void DB2Utilities::WriteItemDbReply(DB2Storage<ItemEntry> const& /*store*/, uint32 id, uint32 /*locale*/, ByteBuffer& buffer)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(id);
    ASSERT(proto);

    buffer << uint32(proto->ItemId);
    buffer << uint32(proto->Class);
    buffer << uint32(proto->SubClass);
    buffer << int32(proto->SoundOverrideSubclass);
    buffer << uint32(proto->Material);
    buffer << uint32(proto->DisplayInfoID);
    buffer << uint32(proto->InventoryType);
    buffer << uint32(proto->Sheath);
}

void DB2Utilities::WriteItemSparseDbReply(DB2Storage<ItemSparseEntry> const& /*store*/, uint32 id, uint32 locale, ByteBuffer& buffer)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(id);
    ASSERT(proto);

    ItemLocale const* localeData = locale ? sObjectMgr->GetItemLocale(id) : NULL;

    buffer << uint32(proto->ItemId);
    buffer << uint32(proto->Quality);
    buffer << uint32(proto->Flags);
    buffer << uint32(proto->Flags2);
    buffer << float(proto->Unk430_1);
    buffer << float(proto->Unk430_2);
    buffer << uint32(proto->BuyCount);
    buffer << int32(proto->BuyPrice);
    buffer << uint32(proto->SellPrice);
    buffer << uint32(proto->InventoryType);
    buffer << int32(proto->AllowableClass);
    buffer << int32(proto->AllowableRace);
    buffer << uint32(proto->ItemLevel);
    buffer << uint32(proto->RequiredLevel);
    buffer << uint32(proto->RequiredSkill);
    buffer << uint32(proto->RequiredSkillRank);
    buffer << uint32(proto->RequiredSpell);
    buffer << uint32(proto->RequiredHonorRank);
    buffer << uint32(proto->RequiredCityRank);
    buffer << uint32(proto->RequiredReputationFaction);
    buffer << uint32(proto->RequiredReputationRank);
    buffer << int32(proto->MaxCount);
    buffer << int32(proto->Stackable);
    buffer << uint32(proto->ContainerSlots);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        buffer << uint32(proto->ItemStat[x].ItemStatType);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        buffer << int32(proto->ItemStat[x].ItemStatValue);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        buffer << int32(proto->ItemStat[x].ItemStatUnk1);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        buffer << int32(proto->ItemStat[x].ItemStatUnk2);

    buffer << uint32(proto->ScalingStatDistribution);
    buffer << uint32(proto->DamageType);
    buffer << uint32(proto->Delay);
    buffer << float(proto->RangedModRange);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        buffer << int32(proto->Spells[x].SpellId);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        buffer << uint32(proto->Spells[x].SpellTrigger);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        buffer << int32(proto->Spells[x].SpellCharges);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        buffer << int32(proto->Spells[x].SpellCooldown);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        buffer << uint32(proto->Spells[x].SpellCategory);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        buffer << int32(proto->Spells[x].SpellCategoryCooldown);

    buffer << uint32(proto->Bonding);

    // item name
    std::string name = proto->Name1;
    if (localeData)
        ObjectMgr::GetLocaleString(localeData->Name, locale, name);

    buffer << uint16(name.length());
    if (name.length())
        buffer << name;

    for (uint32 i = 0; i < 3; ++i) // other 3 names
        buffer << uint16(0);

    std::string desc = proto->Description;
    if (localeData)
        ObjectMgr::GetLocaleString(localeData->Description, locale, desc);

    buffer << uint16(desc.length());
    if (desc.length())
        buffer << desc;

    buffer << uint32(proto->PageText);
    buffer << uint32(proto->LanguageID);
    buffer << uint32(proto->PageMaterial);
    buffer << uint32(proto->StartQuest);
    buffer << uint32(proto->LockID);
    buffer << int32(proto->Material);
    buffer << uint32(proto->Sheath);
    buffer << int32(proto->RandomProperty);
    buffer << int32(proto->RandomSuffix);
    buffer << uint32(proto->ItemSet);

    buffer << uint32(proto->Area);
    buffer << uint32(proto->Map);
    buffer << uint32(proto->BagFamily);
    buffer << uint32(proto->TotemCategory);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SOCKETS; ++x)
        buffer << uint32(proto->Socket[x].Color);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SOCKETS; ++x)
        buffer << uint32(proto->Socket[x].Content);

    buffer << uint32(proto->socketBonus);
    buffer << uint32(proto->GemProperties);
    buffer << float(proto->ArmorDamageModifier);
    buffer << int32(proto->Duration);
    buffer << uint32(proto->ItemLimitCategory);
    buffer << uint32(proto->HolidayId);
    buffer << float(proto->StatScalingFactor);    // StatScalingFactor
    buffer << uint32(proto->CurrencySubstitutionId);
    buffer << uint32(proto->CurrencySubstitutionCount);
}
