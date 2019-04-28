#ifndef PROJECT_PACKETS_BATTLEPAY_H
#define PROJECT_PACKETS_BATTLEPAY_H

#include "project_battle_pay_placeholder.h"
#include "Packet.h"
#include "ItemPackets.h"

namespace PROJECT
{
    namespace Packets
    {
        namespace BattlePay
        {
            class GetProductList final : public WorldPackets::ClientPacket
            {
            	public:
            	    GetProductList(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_BATTLE_PAY_GET_PRODUCT_LIST, std::move(packet)) { }
            	
                    void Read() override { }
            };

            class GetPurchaseList final : public WorldPackets::ClientPacket
            {
        	    public:
        	        GetPurchaseList(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_BATTLE_PAY_GET_PURCHASE_LIST, std::move(packet)) { }
        	
                    void Read() override { }
            };

            class StartPurchase final : public WorldPackets::ClientPacket
            {
            	public:
                    StartPurchase(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_BATTLE_PAY_START_PURCHASE, std::move(packet)) { }
            	
                    void Read() override;

                    ObjectGuid TargetCharacter;
                    uint32 ProductID = 0;
                    uint32 ClientToken = 0;
                    std::string Unk1;
                    std::string Unk2;
            };

            class ConfirmPurchaseResponse final : public WorldPackets::ClientPacket
            {
            	public:
            	    ConfirmPurchaseResponse(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_BATTLE_PAY_CONFIRM_PURCHASE_RESPONSE, std::move(packet)) { }
            	
                    void Read() override;

                    uint64 ClientCurrentPriceFixedPoint = 0;
                    bool ConfirmPurchase = false;
                    uint32 ServerToken = 0;
            };

            class AckFailedResponse final : public WorldPackets::ClientPacket
            {
            	public:
            	    AckFailedResponse(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_BATTLE_PAY_ACK_FAILED_RESPONSE, std::move(packet)) { }
            	
                    void Read() override;

                    uint32 ServerToken = 0;
            };

            class GetProductListResponse final : public WorldPackets::ServerPacket
            {
                public:
                    GetProductListResponse() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_GET_PRODUCT_LIST_RESPONSE) { }
            
                    WorldPacket const* Write() override;

                    std::vector<PROJECT::BattlePay::Product> Products;
                    uint32 Result = 0;
                    std::vector<PROJECT::BattlePay::Group> Groups;
                    std::vector<PROJECT::BattlePay::ShopEntry> ShopEntries;
                    uint32 CurrencyID = 0;
            };

            class GetPurchaseListResponse final : public WorldPackets::ServerPacket
            {
                public:
                    GetPurchaseListResponse() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_GET_PURCHASE_LIST_RESPONSE) { }
            
                    WorldPacket const* Write() override;

                    uint32 Result = 0;
                    std::vector<PROJECT::BattlePay::Purchase> Purchases;
            };

            class GetDistributionListResponse final : public WorldPackets::ServerPacket
            {
                public:
                    GetDistributionListResponse() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_GET_DISTRIBUTION_LIST_RESPONSE) { }
            
                    WorldPacket const* Write() override;

                    uint32 Result = 0;
                    std::vector<uint32> DistributionObjects; // BattlePayDistributionObject vector
            };

            class StartPurchaseResponse final : public WorldPackets::ServerPacket
            {
                public:
                    StartPurchaseResponse() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_START_PURCHASE_RESPONSE) { }
            
                    WorldPacket const* Write() override;

                    uint64 PurchaseID = 0;
                    uint32 PurchaseResult = 0;
                    uint32 ClientToken = 0;
            };

            class ConfirmPurchase final : public WorldPackets::ServerPacket
            {
                public:
                    ConfirmPurchase() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_CONFIRM_PURCHASE) { }
            
                    WorldPacket const* Write() override;

                    uint64 CurrentPriceFixedPoint = 0;
                    uint64 PurchaseID = 0;
                    uint32 ServerToken = 0;
            };

            class PurchaseUpdate final : public WorldPackets::ServerPacket
            {
                public:
                    PurchaseUpdate() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_PURCHASE_UPDATE) { }
            
                    WorldPacket const* Write() override;

                    std::vector<PROJECT::BattlePay::Purchase> Purchases;
            };

            class DeliveryEnded final : public WorldPackets::ServerPacket
            {
                public:
                    DeliveryEnded() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_DELIVERY_ENDED) { }
            
                    WorldPacket const* Write() override;

                    uint64 DistributionID = 0;
                    std::vector<WorldPackets::Item::ItemInstance> Items;
            };

            class AckFailed final : public WorldPackets::ServerPacket
            {
                public:
                    AckFailed() : WorldPackets::ServerPacket(SMSG_BATTLE_PAY_ACK_FAILED) { }
            
                    WorldPacket const* Write() override;

                    uint64 PurchaseID = 0;
                    uint32 Status = 0;
                    uint32 Result = 0;
                    uint32 ServerToken = 0;
            };
        }
    }
}

#endif
