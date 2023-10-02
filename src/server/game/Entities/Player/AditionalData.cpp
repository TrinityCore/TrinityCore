#include "AditionalData.h"
#include "AuctionHouseMgr.h"
#include "Log.h"
#include "Player.h"
#include "Transport.h"
#include "Unit.h"

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

void AditionalData::enterOnTransport(Transport* transport)
{
    if (pPlayer->ToUnit()->m_Controlled.empty())
        return;

    for (auto it : pPlayer->ToUnit()->m_Controlled)
    {
        if (it->IsTotem())
            continue;
        // if controlled unit (pet and etc...) is not in combat
        if (!it->GetVictim())
        {
            if (it->GetTransport() && !transport->isPassenger(it)) // remove pet from another transport, if exist
                it->GetTransport()->RemovePassenger(it);

            if (!transport->isPassenger(it))
                transport->AddPassenger(it);
        }
    }
}

void AditionalData::exitFromTransport(Transport* transport)
{
    if (pPlayer->ToUnit()->m_Controlled.empty())
        return;

    for (auto it : pPlayer->ToUnit()->m_Controlled)
    {
        if (it->IsTotem())
            continue;
        // if controlled unit (pet and etc...) is not in combat
        if (!it->GetVictim())
        {
            if (it->GetTransport() && transport->isPassenger(it))
                transport->RemovePassenger(it);
        }
    }
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
