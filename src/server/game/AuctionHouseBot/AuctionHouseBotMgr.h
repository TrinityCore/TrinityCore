#ifndef _AUCTION_HOUSE_BOT_MGR_H
#define _AUCTION_HOUSE_BOT_MGR_H

#include "Policies/Singleton.h"
#include "SharedDefines.h"

#include <vector>
#include <memory>

class Player;

struct AuctionHouseBotEntry
{
    uint32 item;
    uint32 stack;
    uint32 bid;
    uint32 buyout;
};

struct AuctionHouseBotConfig
{
    uint32 itemcount;
    uint32 ahid;
    uint32 ahfid;

    uint64 botguid;
    uint32 botaccount;

    bool enable;
};

class AuctionHouseBotMgr
{
    public :
        AuctionHouseBotMgr() = default;
        ~AuctionHouseBotMgr();

        void Load();

        // force - put items in AH even if bot is disabled
        void Update(bool force = false);
        void AddItem(AuctionHouseBotEntry e, AuctionHouseObject *auctionHouse);

    protected:
        std::vector<AuctionHouseBotEntry> m_items;
        std::unique_ptr<AuctionHouseBotConfig> m_config;
        AuctionHouseEntry const* m_auctionHouseEntry = nullptr;

        bool m_loaded = false;
};

#define sAuctionHouseBotMgr MaNGOS::Singleton< AuctionHouseBotMgr >::Instance()
#endif
