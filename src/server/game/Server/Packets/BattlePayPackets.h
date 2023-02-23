/*
* Copyright 2021 ShadowCore
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


#ifndef BattlePayPackets_h__
#define BattlePayPackets_h__

#include "Packet.h"
#include "ItemPackets.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace BattlePay
    {
        class GetProductList final : public ClientPacket
        {
        public:
            GetProductList(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_GET_PRODUCT_LIST, std::move(packet)) { }

            void Read() override { }
        };

        class GetPurchaseListQuery final : public ClientPacket
        {
        public:
            GetPurchaseListQuery(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_GET_PURCHASE_LIST, std::move(packet)) { }

            void Read() override { }
        };

        class UpdateVasPurchaseStates final : public ClientPacket
        {
        public:
            UpdateVasPurchaseStates(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_VAS_PURCHASE_STATES, std::move(packet)) { }

            void Read() override { }
        };

        struct ProductDisplayVisualData
        {
            uint32 DisplayId = 0;
            uint32 VisualId = 0;
            uint32 VisualId2 = 0;
            std::string ProductName;
        };

        struct ProductDisplayInfo
        {
            std::vector<ProductDisplayVisualData> Visuals;
            Optional<uint32> CreatureDisplayInfoID;
            Optional<uint32> FileDataID;
            Optional<uint32> Flags;
            Optional<uint32> Flags2;
            Optional<uint32> Flags3;
            Optional<uint32> Flags4;
            uint32 DisplayCardWidth;
            std::string Name1;
            std::string Name2;
            std::string Name3;
            std::string Name4;
            std::string Name5;
            std::string UnkString;
        };

        struct ProductItem
        {
            Optional<ProductDisplayInfo> DisplayInfo;
            Optional<uint8> PetResult;
            uint32 ID = 0;
            uint32 ItemID = 0;
            uint32 Quantity = 0;
            uint32 UnkInt1 = 0;
            uint32 UnkInt2 = 0;
            uint8 UnkByte = 0;
            bool HasPet = false;
        };

        struct BattlePayProduct
        {
            std::vector<ProductItem> Items;
            Optional<ProductDisplayInfo> DisplayInfo;
            Optional<uint8> UnkBits;
            uint32 ProductID = 0;
            uint32 Flags = 0;
            uint32 UnkInt1 = 0;
            uint32 SpellID = 0;
            uint32 CreatureID = 0;
            uint32 UnkInt4 = 0;
            uint32 UnkInt5 = 0;
            std::string UnkString;
            uint8 Type = 0;
            bool UnkBit = false;
        };

        struct BattlePayDistributionObject
        {
            Optional<BattlePayProduct> Product;
            ObjectGuid TargetPlayer;
            uint64 DistributionID = 0;
            uint64 PurchaseID = 0;
            uint32 Status = 0;
            uint32 ProductID = 0;
            uint32 TargetVirtualRealm = 0;
            uint32 TargetNativeRealm = 0;
            bool Revoked = false;
        };

        struct BattlePayPurchase
        {
            uint64 PurchaseID = 0;
            uint64 UnkLong = 0;
            uint64 UnkLong2 = 0;
            uint32 Status = 0;
            uint32 ResultCode = 0;
            uint32 ProductID = 0;
            uint32 UnkInt = 0;
            std::string WalletName;
        };

        class PurchaseListResponse final : public ServerPacket
        {
        public:
            PurchaseListResponse() : ServerPacket(SMSG_BATTLE_PAY_GET_PURCHASE_LIST_RESPONSE, 8) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
            std::vector<BattlePayPurchase> Purchase;
        };

        class SyncWowEntitlements final : public ServerPacket
        {
        public:
            SyncWowEntitlements() : ServerPacket(SMSG_SYNC_WOW_ENTITLEMENTS) { }

            WorldPacket const* Write() override;

            std::vector<uint32> purchaseCount;
            std::vector<uint32> productCount;
            std::vector<BattlePayProduct> Product;
        };

        class DistributionListResponse final : public ServerPacket
        {
        public:
            DistributionListResponse() : ServerPacket(SMSG_BATTLE_PAY_GET_DISTRIBUTION_LIST_RESPONSE, 8) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
            std::vector<BattlePayDistributionObject> DistributionObject;
        };

        class EnumVasPurchaseStatesResponse final : public ServerPacket
        {
        public:
            EnumVasPurchaseStatesResponse() : ServerPacket(SMSG_ENUM_VAS_PURCHASE_STATES_RESPONSE, 4) { }

            WorldPacket const* Write() override;

            uint8 Result = 0;
        };

        class DistributionUpdate final : public ServerPacket
        {
        public:
            DistributionUpdate() : ServerPacket(SMSG_BATTLE_PAY_DISTRIBUTION_UPDATE, 100) { }

            WorldPacket const* Write() override;

            BattlePayDistributionObject DistributionObject;
        };

        struct BattlePayProductGroup
        {
            uint32 GroupID = 0;
            uint32 IconFileDataID = 0;
            uint32 Ordering = 0;
            uint32 UnkInt = 0;
            std::string Name;
            std::string IsAvailableDescription;
            uint8 DisplayType = 0;
        };

        struct BattlePayShopEntry
        {
            Optional<ProductDisplayInfo> DisplayInfo;
            uint32 EntryID = 0;
            uint32 GroupID = 0;
            uint32 ProductID = 0;
            int32 Ordering = 0;
            uint32 VasServiceType = 0;
            uint8 StoreDeliveryType = 0;
        };

        struct ProductInfoStruct
        {
            std::vector<uint32> ProductIDs;
            std::vector<uint32> UnkInts;
            Optional<ProductDisplayInfo> DisplayInfo;
            uint64 NormalPriceFixedPoint = 0;
            uint64 CurrentPriceFixedPoint = 0;
            uint32 ProductID = 0;
            uint32 UnkInt2 = 0;
            uint32 ChoiceType = 0;
        };

        struct ProductListData
        {
            std::vector<ProductInfoStruct> ProductInfo;
            std::vector<BattlePayProduct> Product;
            std::vector<BattlePayProductGroup> ProductGroup;
            std::vector<BattlePayShopEntry> Shop;
            uint32 CurrencyID = 0;
        };

        class ProductListResponse final : public ServerPacket
        {
        public:
            ProductListResponse() : ServerPacket(SMSG_BATTLE_PAY_GET_PRODUCT_LIST_RESPONSE, 20) { }

            WorldPacket const* Write() override;

            ProductListData ProductList;
            uint32 Result = 0;
        };

        class StartPurchase final : public ClientPacket
        {
        public:
            StartPurchase(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_START_PURCHASE, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetCharacter;
            uint32 ClientToken = 0;
            uint32 ProductID = 0;
        };

        class StartPurchaseResponse final : public ServerPacket
        {
        public:
            StartPurchaseResponse() : ServerPacket(SMSG_BATTLE_PAY_START_PURCHASE_RESPONSE, 16) { }

            WorldPacket const* Write() override;

            uint64 PurchaseID = 0;
            uint32 ClientToken = 0;
            uint32 PurchaseResult = 0;
        };

        class BattlePayAckFailed final : public ServerPacket
        {
        public:
            BattlePayAckFailed() : ServerPacket(SMSG_BATTLE_PAY_ACK_FAILED, 16) { }

            WorldPacket const* Write() override;

            uint64 PurchaseID = 0;
            uint32 ClientToken = 0;
            uint32 PurchaseResult = 0;
        };

        class PurchaseUpdate final : public ServerPacket
        {
        public:
            PurchaseUpdate() : ServerPacket(SMSG_BATTLE_PAY_PURCHASE_UPDATE, 4) { }

            WorldPacket const* Write() override;

            std::vector<BattlePayPurchase> Purchase;
        };

        class ConfirmPurchase final : public ServerPacket
        {
        public:
            ConfirmPurchase() : ServerPacket(SMSG_BATTLE_PAY_CONFIRM_PURCHASE, 20) { }

            WorldPacket const* Write() override;

            uint64 PurchaseID = 0;
            uint32 ServerToken = 0;
        };

        class ConfirmPurchaseResponse final : public ClientPacket
        {
        public:
            ConfirmPurchaseResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_CONFIRM_PURCHASE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint64 ClientCurrentPriceFixedPoint = 0;
            uint32 ServerToken = 0;
            bool ConfirmPurchase = false;
        };

        class BattlePayAckFailedResponse final : public ClientPacket
        {
        public:
            BattlePayAckFailedResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_ACK_FAILED_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 ServerToken = 0;
        };

        class DeliveryEnded final : public ServerPacket
        {
        public:
            DeliveryEnded() : ServerPacket(SMSG_BATTLE_PAY_DELIVERY_ENDED, 12) { }

            WorldPacket const* Write() override;

            std::vector<Item::ItemInstance> item;
            uint64 DistributionID = 0;
        };

        class BattlePayDeliveryStarted final : public ServerPacket
        {
        public:
            BattlePayDeliveryStarted() : ServerPacket(SMSG_BATTLE_PAY_DELIVERY_STARTED, 8) { }

            WorldPacket const* Write() override;

            uint64 DistributionID = 0;
        };

        class UpgradeStarted final : public ServerPacket
        {
        public:
            UpgradeStarted() : ServerPacket(SMSG_CHARACTER_UPGRADE_STARTED, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid CharacterGUID;
        };

        class DistributionAssignToTarget final : public ClientPacket
        {
        public:
            DistributionAssignToTarget(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_DISTRIBUTION_ASSIGN_TO_TARGET, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetCharacter;
            uint64 DistributionID = 0;
            uint32 ProductID = 0;
            uint16 SpecializationID = 0;
            uint16 ChoiceID = 0;
        };

        struct VasPurchaseData
        {
            std::vector<uint32> ItemIDs;
            ObjectGuid PlayerGuid;
            uint64 UnkLong = 0;
            uint32 UnkInt = 0;
            uint32 UnkInt2 = 0;
        };

        /*class BattlePayVasPurchaseStarted final : public ServerPacket
        {
        public:
            BattlePayVasPurchaseStarted() : ServerPacket(SMSG_BATTLE_PAY_VAS_PURCHASE_STARTED, 4 + 4 + 16 + 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            VasPurchaseData VasPurchase;
            uint32 UnkInt = 0;
        };*/

        /*class CharacterClassTrialCreate final : public ServerPacket
        {
        public:
            CharacterClassTrialCreate() : ServerPacket(SMSG_CHARACTER_CLASS_TRIAL_CREATE, 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
        };*/

        /*class BattlePayQueryClassTrialResult final : public ClientPacket
        {
        public:
            BattlePayQueryClassTrialResult(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_QUERY_CLASS_TRIAL_BOOST_RESULT, std::move(packet)) { }

            void Read() override { }
        };*/

        /*class BattlePayCharacterUpgradeQueued final : public ServerPacket
        {
        public:
            BattlePayCharacterUpgradeQueued() : ServerPacket(SMSG_CHARACTER_UPGRADE_QUEUED, 4 + 16) { }

            WorldPacket const* Write() override;

            std::vector<uint32> EquipmentItems;
            ObjectGuid Character;
        };*/

        /*class BattlePayTrialBoostCharacter final : public ClientPacket
        {
        public:
            BattlePayTrialBoostCharacter(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_TRIAL_BOOST_CHARACTER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Character;
            uint32 SpecializationID = 0;
        };*/

        /*class BattlePayVasPurchaseList final : public ServerPacket
        {
        public:
            BattlePayVasPurchaseList() : ServerPacket(SMSG_BATTLE_PAY_VAS_PURCHASE_LIST, 4) { }

            WorldPacket const* Write() override;

            std::vector<VasPurchaseData> VasPurchase;
        };*

        /*class BattlePayPurchaseDetails final : public ServerPacket
        {
        public:
            BattlePayPurchaseDetails() : ServerPacket(SMSG_BATTLE_PAY_PURCHASE_DETAILS, 20) { }

            WorldPacket const* Write() override;

            uint64 UnkLong = 0;
            uint32 UnkInt = 0;
            uint32 VasPurchaseProgress = 0;
            std::string Key;
            std::string Key2;
        };*/

        /*class BattlePayPurchaseUnk final : public ServerPacket
        {
        public:
            BattlePayPurchaseUnk() : ServerPacket(SMSG_BATTLE_PAY_PURCHASE_UNK, 20) { }

            WorldPacket const* Write() override;

            uint32 UnkInt = 0;
            std::string Key;
            uint8 UnkByte = 0;
        };*/

        class BattlePayBattlePetDelivered final : public ServerPacket
        {
        public:
            BattlePayBattlePetDelivered() : ServerPacket(SMSG_BATTLE_PAY_BATTLE_PET_DELIVERED, 20) { }

            WorldPacket const* Write() override;

            ObjectGuid BattlePetGuid;
            uint32 DisplayID = 0;
        };

        /*class BattlePayPurchaseDetailsResponse final : public ClientPacket
        {
        public:
            BattlePayPurchaseDetailsResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_PURCHASE_DETAILS_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint8 UnkByte = 0;
        };*/

        /*class BattlePayPurchaseUnkResponse final : public ClientPacket
        {
        public:
            BattlePayPurchaseUnkResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_PURCHASE_UNK_RESPONSE, std::move(packet)) { }

            void Read() override;

            std::string Key;
            std::string Key2;
        };*/

        class DisplayPromotion final : public ServerPacket
        {
        public:
            DisplayPromotion(uint32 ID) : ServerPacket(SMSG_DISPLAY_PROMOTION, 4), PromotionID(ID) { }

            WorldPacket const* Write() override;

            uint32 PromotionID = 0;
        };

        /*class BattlepayUnk final : public ServerPacket
        {
        public:
            BattlepayUnk(uint32 unkInt) : ServerPacket(SMSG_BATTLE_PAY_UNK, 4), UnkInt(unkInt) { }

            WorldPacket const* Write() override;

            uint32 UnkInt = 0;
        };*/

        class BattlePayStartDistributionAssignToTargetResponse final : public ServerPacket
        {
        public:
            BattlePayStartDistributionAssignToTargetResponse() : ServerPacket(SMSG_BATTLE_PAY_START_DISTRIBUTION_ASSIGN_TO_TARGET_RESPONSE, 16) { }

            WorldPacket const* Write() override;

            uint64 DistributionID = 0;
            uint32 unkint1 = 0;
            uint32 unkint2 = 0;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::ProductDisplayInfo const& displayInfo);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayProduct const& product);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayDistributionObject const& object);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayPurchase const& purchase);

#endif // BattlePayPackets_h__
