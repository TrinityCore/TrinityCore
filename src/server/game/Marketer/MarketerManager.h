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
    bool UpdateMarketer();
	bool UpdateSeller(uint32 pmDiff);
	bool UpdateBuyer(uint32 pmDiff);
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

<<<<<<< HEAD
    std::set<uint32> auctionHouseIDSet;
=======
    uint32 realPrevTime;
>>>>>>> 4caa787c51f36c1b16049a962875cdfb879ad9db
};

#define sMarketerManager MarketerManager::instance()

#endif
