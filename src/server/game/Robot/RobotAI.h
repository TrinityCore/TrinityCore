#ifndef ROBOT_AI_H
#define ROBOT_AI_H

#ifndef AI_CHECK_DELAY
# define AI_CHECK_DELAY 100
#endif

#include "RobotStrategy.h"

enum RobotCharacterType :uint32
{
    RobotCharacterType_DPS = 0,
    RobotCharacterType_TANK = 1,
    RobotCharacterType_HEALER = 2,
};

enum Strategy_Index :uint32
{
    Strategy_Index_Solo = 0,
    Strategy_Index_Group,
    Strategy_Index_Group_Blackrock_Spire,
    Strategy_Index_Group_Alcaz_Island,
    Strategy_Index_Group_Shadow_Labyrinth,
    Strategy_Index_Group_Ysondre,
    Strategy_Index_Group_Taerar,
};

class RobotAI
{
public:
    RobotAI(Player* pmMe);
    void Update(uint32 pmDiff);
    RobotStrategy* GetActiveStrategy(uint32 pmStrategyType = RobotStrategyType::RobotStrategyType_All);

public:
    Player* me;
    std::unordered_map<uint32, RobotStrategy*> strategyMap;
    uint32 activeStrategyIndex;
    uint32 robotType;
    int checkDelay;    
};
#endif
