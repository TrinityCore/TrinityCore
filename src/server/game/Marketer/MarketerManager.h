#ifndef MARKETER_MANAGER_H
#define MARKETER_MANAGER_H

#ifndef MARKETER_MANAGER_UPDATE_GAP
#define MARKETER_MANAGER_UPDATE_GAP 500
#endif

#include <string>
#include "Log.h"
#include "MarketerConfig.h"
#include "AuctionHouse/AuctionHouseMgr.h"
#include "Item.h"

class MarketerManager
{
	MarketerManager();
	MarketerManager(MarketerManager const&) = delete;
	MarketerManager& operator=(MarketerManager const&) = delete;
	~MarketerManager() = default;

public:
    void ResetMarketer();
    bool UpdateMarketer(uint32 pmDiff);
	bool UpdateSeller();
	bool UpdateBuyer();
	static MarketerManager* instance();

private:    
    bool MarketEmpty();    

public:
	std::unordered_set<uint32> vendorUnlimitItemSet;

	int32 buyerCheckDelay;
    int32 sellerCheckDelay;    

private:    
    std::unordered_map<uint32, uint32> sellingItemIDMap;
    bool selling;
    uint32 sellingIndex;
	Player* pMarketer;
    std::set<uint32> auctionHouseIDSet;    
};

#define sMarketerManager MarketerManager::instance()

#endif
