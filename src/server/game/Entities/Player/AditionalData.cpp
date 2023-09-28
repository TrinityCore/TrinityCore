#include "AditionalData.h"
#include "AuctionHouseMgr.h"
#include "Log.h"
#include "Player.h"

AditionalData::AditionalData(Player* player)
{
    pPlayer = player;
    m_auctionlots = 0;
    m_walking = false;
}

AditionalData::~AditionalData()
{
    m_auctionlots = 0;
    m_walking = false;
}

void AditionalData::update(uint32 p_time)
{

}

void AditionalData::calculateAuctionLotsCounter()
{
    uint32 count = 0;
    if (AuctionHouseObject* AllianceauctionHouse = sAuctionMgr->GetAuctionsMapByHouseId(AUCTIONHOUSE_ALLIANCE))
        AllianceauctionHouse->BuildListAllLots(pPlayer, count);

    if (AuctionHouseObject* AllianceauctionHouse = sAuctionMgr->GetAuctionsMapByHouseId(AUCTIONHOUSE_HORDE))
        AllianceauctionHouse->BuildListAllLots(pPlayer, count);

    if (AuctionHouseObject* AllianceauctionHouse = sAuctionMgr->GetAuctionsMapByHouseId(AUCTIONHOUSE_NEUTRAL))
        AllianceauctionHouse->BuildListAllLots(pPlayer, count);

    TC_LOG_DEBUG("chatmessage", "Player: CalculateAuctionLotsCounter - Player ({}) has {} lots in all auctions", pPlayer->GetName(), count);
    m_auctionlots = count;
}
