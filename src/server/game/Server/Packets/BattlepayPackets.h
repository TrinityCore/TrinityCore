/*
* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "ItemPackets.h"
#include "Packet.h"
#include "PacketUtilities.h"
#include "ObjectGuid.h"
#include "WorldSession.h"

class Player;
class BattlepayEntry;

namespace WorldPackets
{
    namespace Battlepay
    {
        struct BattlepayDisplayInfo
        {
            Optional<uint32> CreatureDisplayInfoID;
            Optional<uint32> FileDataID;
            std::string Name1;
            std::string Name2;
            std::string Name3;
            Optional<uint32> Flags;
        };

        struct BATTLEPETRESULT
        {
            // EmptyStruct
        };

        struct BattlepayProductItem
        {
            uint32 ID = 0;
            uint32 ItemID = 0;
            uint32 Quantity = 0;
            Optional<BattlepayDisplayInfo> DisplayInfo;
            bool HasPet = false;
            Optional<BATTLEPETRESULT> PetResult;
            bool HasMount = false;
            bool HasBattlePayDisplayInfo = false;
        };

        struct BattlePayProduct
        {
            uint32 ProductID = 0;
            uint64 NormalPriceFixedPoint = 0;
            uint64 CurrentPriceFixedPoint = 0;
            std::vector<BattlepayProductItem> Items;
            uint8 Type = 0;
            uint8 ChoiceType = 0;
            uint32 Flags = 0;
            Optional<BattlepayDisplayInfo> DisplayInfo;
        };

        struct BattlePayProductGroup
        {
            uint32 GroupID = 0;
            std::string Name;
            int32 IconFileDataID = 0;
            uint8 DisplayType = 0;
            int32 Ordering = 0;
        };

        struct BattlePayShopEntry
        {
            uint32 EntryID = 0;
            uint32 GroupID = 0;
            uint32 ProductID = 0;
            int32 Ordering = 0;
            uint32 Flags = 0;
            uint8 BannerType = 0;
            Optional<BattlepayDisplayInfo> DisplayInfo;
        };

        struct BattlePayDistributionObject
        {
            uint64 DistributionID = 0;
            uint32 Status = 0;
            uint32 ProductID = 0;
            ObjectGuid TargetPlayer;
            uint32 TargetVirtualRealm = 0;
            uint32 TargetNativeRealm = 0;
            uint64 PurchaseID = 0;
            Optional<BattlePayProduct> Product;
            bool Revoked = false;
        };

        class BattlepayStartPurchaseResponse final : public ServerPacket
        {
        public:
            BattlepayStartPurchaseResponse() : ServerPacket(SMSG_BATTLE_PAY_START_PURCHASE_RESPONSE, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 PurchaseID = 0;
            uint32 PurchaseResult = 0;
            uint32 ClientToken = 0;
        };

        class BattlepayStartDistributionAssignToTargetResponse final : public ServerPacket
        {
        public:
            BattlepayStartDistributionAssignToTargetResponse() : ServerPacket(SMSG_BATTLE_PAY_START_DISTRIBUTION_ASSIGN_TO_TARGET_RESPONSE, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 DistributionID = 0;
            uint32 ClientToken = 0;
            uint32 Result = 0;
        };

        class BattlepayStartDistributionMakeProductChoiceResponse final : public ServerPacket
        {
        public:
            //BattlepayStartDistributionMakeProductChoiceResponse() : ServerPacket(/*SMSG_BATTLE_PAY_START_DISTRIBUTION_MAKE_PRODUCT_CHOICE_RESPONSE*/) { }

            WorldPacket const* Write() override;

            uint32 ClientToken = 0;
            //ProductChoiceResult Result;
            uint64 DistributionID = 0;
        };

        struct BattlePayPurchase
        {
            uint64 PurchaseID = 0;
            uint32 Status = 0;
            uint32 ResultCode = 0;
            uint32 ProductID = 0;
            std::string WalletName;
        };

        class BattlepayPurchaseUpdate final : public ServerPacket
        {
        public:
            BattlepayPurchaseUpdate() : ServerPacket(SMSG_BATTLE_PAY_PURCHASE_UPDATE) { }

            WorldPacket const* Write() override;

            std::vector<BattlePayPurchase> Purchases;
        };

        class BattlePayConfirmPurchase final : public ServerPacket
        {
        public:
            BattlePayConfirmPurchase() : ServerPacket(SMSG_BATTLE_PAY_CONFIRM_PURCHASE, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            uint64 CurrentPriceFixedPoint = 0;
            uint64 PurchaseID = 0;
            uint32 ServerToken = 0;
        };

        class BattlePayAckFailed final : public ServerPacket
        {
        public:
            BattlePayAckFailed() : ServerPacket(SMSG_BATTLE_PAY_ACK_FAILED, 16 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 PurchaseID = 0;
            uint32 Status = 0;
            uint32 Result = 0;
            uint32 ServerToken = 0;
        };

        class BattlePayDistributionAssignToTarget final : ClientPacket
        {
        public:
            BattlePayDistributionAssignToTarget(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_DISTRIBUTION_ASSIGN_TO_TARGET, std::move(packet)) { }

            void Read();

            ObjectGuid TargetCharacter;
            uint64 DistributionID = 0;
            uint32 ProductChoice = 0;
            uint32 ClientToken = 0;
        };

        /*class BattlePayDistributionSelectChoice final : public ClientPacket
        {
        public:
            BattlePayDistributionSelectChoice(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_DISTRIBUTION_SELECT_CHOCIE, std::move(packet)) { }

            void Read();

            uint64 DistributionID = 0;
            ObjectGuid TargetCharacter;
            uint32 ProductChoice = 0;
            uint32 ClientToken = 0;
        };*/

        class BattlePayStartPurchase final : public ClientPacket
        {
        public:
            BattlePayStartPurchase(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_START_PURCHASE, std::move(packet)) { }

            void Read();

            ObjectGuid TargetCharacter;
            uint32 ProductID = 0;
            uint32 ClientToken = 0;
        };

        class BattlePayConfirmPurchaseResponse final : public ClientPacket
        {
        public:
            BattlePayConfirmPurchaseResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_CONFIRM_PURCHASE_RESPONSE, std::move(packet)) { }

            void Read();

            uint64 ClientCurrentPriceFixedPoint = 0;
            bool ConfirmPurchase = false;
            uint32 ServerToken = 0;
        };

        class BattlePayAckFailedResponse final : public ClientPacket
        {
        public:
            BattlePayAckFailedResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_ACK_FAILED_RESPONSE, std::move(packet)) { }

            void Read();

            uint32 ServerToken = 0;
        };

        class BattlePayGetProductListResponse final : public ServerPacket
        {
        public:
            BattlePayGetProductListResponse() : ServerPacket(SMSG_BATTLE_PAY_GET_PRODUCT_LIST_RESPONSE, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            std::vector<BattlePayProduct const*> Products;
            std::vector<BattlePayProductGroup const*> Groups;
            std::vector<BattlePayShopEntry const*> ShopEntries;
            uint32 Result = 0;
            uint32 CurrencyID = 0;
        };

        class BattlePayGetPurchaseListResponse final : public ServerPacket
        {
        public:
            BattlePayGetPurchaseListResponse() : ServerPacket(SMSG_BATTLE_PAY_GET_PURCHASE_LIST_RESPONSE, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            std::vector<BattlePayPurchase> Purchases;
            uint32 Result = 0;
        };

        class BattlePayGetDistributionListResponse final : public ServerPacket
        {
        public:
            BattlePayGetDistributionListResponse() : ServerPacket(SMSG_BATTLE_PAY_GET_DISTRIBUTION_LIST_RESPONSE, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
            std::vector<BattlePayDistributionObject> DistributionObjects;
        };

        class BattlePayDistributionUpdate final : public ServerPacket
        {
        public:
            BattlePayDistributionUpdate() : ServerPacket(SMSG_BATTLE_PAY_DISTRIBUTION_UPDATE, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            BattlePayDistributionObject DistributionObject;
        };

        class BattlePayDeliveryStarted final : public ServerPacket
        {
        public:
            BattlePayDeliveryStarted() : ServerPacket(SMSG_BATTLE_PAY_DELIVERY_STARTED, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            uint64 DistributionID = 0;
        };

        class BattlePayDeliveryEnded final : public ServerPacket
        {
        public:
            BattlePayDeliveryEnded() : ServerPacket(SMSG_BATTLE_PAY_DELIVERY_ENDED, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            uint64 DistributionID = 0;
            std::vector<WorldPackets::Item::ItemInstance> Items;
        };

        class BattlePayGetProductList final : public ClientPacket
        {
        public:
            BattlePayGetProductList(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PAY_GET_PRODUCT_LIST, std::move(packet)) { }

            void Read() override;
        };
    }
}

#endif // BattlePayPacket_h__