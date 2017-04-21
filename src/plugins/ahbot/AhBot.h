#pragma once

#include "Category.h"
#include "ItemBag.h"
#include "../playerbot/PlayerbotAIBase.h"
#include "../AuctionHouse/AuctionHouseMgr.h"
#include "../WorldSession.h"
#include "../pchdef.h"

#define MAX_AUCTIONS 3
#define AHBOT_WON_EXPIRE 0
#define AHBOT_WON_PLAYER 1
#define AHBOT_WON_SELF 2
#define AHBOT_WON_BID 3
#define AHBOT_WON_DELAY 4
#define AHBOT_SELL_DELAY 5

namespace ahbot
{
    using namespace std;

    class AhBot
    {
    public:
        AhBot() : nextAICheckTime(0), updating(false) {}
        virtual ~AhBot();
        static AhBot& instance()
        {
            static AhBot instance;
            return instance;
        }

    public:
        static bool HandleAhBotCommand(ChatHandler* handler, char const* args);
        ObjectGuid GetAHBplayerGUID();
        void Init();
        void Update();
        void ForceUpdate();
        void HandleCommand(string command);
        void Won(AuctionEntry* entry) { AddToHistory(entry); }
        void Expired(AuctionEntry* entry) {}

        double GetCategoryMultiplier(string category)
        {
            return categoryMultipliers[category];
        }

        int32 GetSellPrice(const ItemTemplate* proto);
        int32 GetBuyPrice(const ItemTemplate* proto);
        double GetRarityPriceMultiplier(const ItemTemplate* proto);

    private:
        int Answer(int auction, Category* category, ItemBag* inAuctionItems);
        int AddAuctions(int auction, Category* category, ItemBag* inAuctionItems);
        int AddAuction(int auction, Category* category, const ItemTemplate* proto);
        void Expire(int auction);
        void PrintStats(int auction);
        void AddToHistory(AuctionEntry* entry, uint32 won = 0);
        void CleanupHistory();
        uint32 GetAvailableMoney(uint32 auctionHouse);
        void CheckCategoryMultipliers();
        void updateMarketPrice(uint32 itemId, double price, uint32 auctionHouse);
        bool IsBotAuction(uint32 bidder);
        uint32 GetRandomBidder(uint32 auctionHouse);
        void LoadRandomBots();
        uint32 GetAnswerCount(uint32 itemId, uint32 auctionHouse, uint32 withinTime);
        vector<AuctionEntry*> LoadAuctions(AuctionHouseObject* auctionHouse, Category*& category,
                int& auction);
        void FindMinPrice(AuctionHouseObject* auctionHouse, AuctionEntry*& entry, Item*& item, uint32* minBid,
                uint32* minBuyout);
        uint32 GetBuyTime(uint32 entry, uint32 itemId, uint32 auctionHouse, Category*& category, double priceLevel);
        uint32 GetTime(string category, uint32 id, uint32 auctionHouse, uint32 type);
        void SetTime(string category, uint32 id, uint32 auctionHouse, uint32 type, uint32 value);
        uint32 GetSellTime(uint32 itemId, uint32 auctionHouse, Category*& category);

    public:
        static uint32 auctionIds[MAX_AUCTIONS];
        static uint32 auctioneers[MAX_AUCTIONS];
        static map<uint32, uint32> factions;

    private:
        AvailableItemsBag availableItems;
        time_t nextAICheckTime;
        map<string, double> categoryMultipliers;
        map<string, uint32> categoryMaxAuctionCount;
        map<string, uint64> categoryMultiplierExpireTimes;
        map<uint32, vector<uint32> > bidders;
        set<uint32> allBidders;
        bool updating;
    };
};

#define auctionbot ahbot::AhBot::instance()
