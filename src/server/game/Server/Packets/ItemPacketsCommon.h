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

#ifndef ItemPacketsCommon_h__
#define ItemPacketsCommon_h__

#include "ItemDefines.h"
#include "PacketUtilities.h"
#include "Optional.h"
#include <vector>

class ByteBuffer;
class Item;
struct LootItem;
struct VoidStorageItem;
enum class ItemContext : uint8;

namespace UF
{
    struct SocketedGem;
}

namespace WorldPackets
{
    namespace Item
    {
        struct ItemBonuses
        {
            ItemContext Context = ItemContext(0);
            std::vector<int32> BonusListIDs;

            bool operator==(ItemBonuses const& r) const;
        };

        struct ItemMod
        {
            ItemMod() = default;
            ItemMod(int32 value, ItemModifier type) : Value(value), Type(type) { }

            int32 Value = 0;
            ItemModifier Type = MAX_ITEM_MODIFIERS;

            bool operator==(ItemMod const& r) const;
        };

        struct ItemModList
        {
            Array<ItemMod, MAX_ITEM_MODIFIERS> Values;

            bool operator==(ItemModList const& r) const;
        };

        struct ItemInstance
        {
            void Initialize(::Item const* item);
            void Initialize(UF::SocketedGem const* gem);
            void Initialize(::LootItem const& lootItem);
            void Initialize(::VoidStorageItem const* voidItem);

            uint32 ItemID = 0;
            Optional<ItemBonuses> ItemBonus;
            ItemModList Modifications;

            bool operator==(ItemInstance const& r) const;
        };

        struct ItemBonusKey
        {
            int32 ItemID = 0;
            std::vector<int32> BonusListIDs;

            bool operator==(ItemBonusKey const& right) const;
        };

        struct ItemEnchantData
        {
            ItemEnchantData(int32 id, uint32 expiration, int32 charges, uint8 slot) : ID(id), Expiration(expiration), Charges(charges), Slot(slot) { }
            int32 ID = 0;
            uint32 Expiration = 0;
            int32 Charges = 0;
            uint8 Slot = 0;
        };

        struct ItemGemData
        {
            uint8 Slot;
            ItemInstance Item;
        };

        struct InvUpdate
        {
            struct InvItem
            {
                uint8 ContainerSlot = 0;
                uint8 Slot = 0;
            };

            std::vector<InvItem> Items;
        };

        struct UiEventToast
        {
            int32 UiEventToastID = 0;
            int32 Asset = 0;
        };

        ByteBuffer& operator<<(ByteBuffer& data, ItemEnchantData const& itemEnchantData);

        ByteBuffer& operator<<(ByteBuffer& data, ItemGemData const& itemGemInstanceData);
        ByteBuffer& operator>>(ByteBuffer& data, ItemGemData& itemGemInstanceData);

        ByteBuffer& operator<<(ByteBuffer& data, ItemInstance const& itemInstance);
        ByteBuffer& operator>>(ByteBuffer& data, ItemInstance& itemInstance);

        ByteBuffer& operator<<(ByteBuffer& data, ItemBonusKey const& itemBonusKey);

        ByteBuffer& operator>>(ByteBuffer& data, InvUpdate& invUpdate);

        ByteBuffer& operator<<(ByteBuffer& data, UiEventToast const& uiEventToast);
    }
}

#endif // ItemPacketsCommon_h__
