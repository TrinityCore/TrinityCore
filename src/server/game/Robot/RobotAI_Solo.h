#ifndef ROBOT_AI_SOLO_H
#define ROBOT_AI_SOLO_H

#ifndef SOLO_CHECK_DELAY
# define SOLO_CHECK_DELAY 500
#endif

#include "Strategy_Solo.h"
#include "Player.h"

enum Strategy_Solo_Index :uint32
{
    Strategy_Solo_Index_Default = 0,
};

class RobotAI_Solo
{
public:
    RobotAI_Solo(Player* pmMe);
    void Update(uint32 pmDiff);
    Strategy_Solo* GetActiveStrategy();
    
public:
    Player* me;
    std::unordered_map<uint32, Strategy_Solo*> strategyMap;
    uint32 activeStrategyIndex;
    int checkDelay;
};
#endif
