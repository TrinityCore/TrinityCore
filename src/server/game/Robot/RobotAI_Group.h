#ifndef ROBOT_AI_GROUP_H
#define ROBOT_AI_GROUP_H

#include "Strategy_Group.h"
#include "Player.h"

enum GroupRole :uint32
{
    GroupRole_DPS = 0,
    GroupRole_Tank = 1,
    GroupRole_Healer = 2,
};

enum Strategy_Group_Index :uint32
{
    Strategy_Group_Index_Default = 0,
    Strategy_Group_Index_Shadow_Labyrinth = 1,
};

class RobotAI_Group
{
public:
    RobotAI_Group(Player* pmMe);
    void Update(uint32 pmDiff);
    Strategy_Group* GetActiveStrategy();
    
public:
    Player* me;
    std::unordered_map<uint32, Strategy_Group*> strategyMap;
    uint32 activeStrategyIndex;
};
#endif
