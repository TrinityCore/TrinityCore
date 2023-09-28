#ifndef AditionalData_h__
#define AditionalData_h__

#include "Define.h"

class Player;

class TC_GAME_API AditionalData
{
public:
    AditionalData(Player* player);
    ~AditionalData();

    void update(uint32 p_time);

    // Auction info
    void calculateAuctionLotsCounter();
    uint32 getAuctionLotsCount() const { return m_auctionlots; }
    void addLotsCount() { ++m_auctionlots; }
    void removeLotsCount() { m_auctionlots - 1 > 0 ? --m_auctionlots : m_auctionlots = 0; }

    // Walking data from move packets
    void setWalkingFlag(bool walkstatus) { m_walking = walkstatus; }
    bool hasWalkingFlag() const { return m_walking; }

private:
    Player* pPlayer = nullptr;
    uint32 m_auctionlots;       // Auction lots count for all auctions
    bool m_walking;             // Player walking
};

#endif // AditionalData_h__
