#include "RobotAI_Group.h"

RobotAI_Group::RobotAI_Group(Player* pmMe)
{
    me = pmMe;
    strategyMap.clear();
    Strategy_Group* sg = new Strategy_Group(pmMe);
    strategyMap[Strategy_Group_Index::Strategy_Group_Index_Default] = sg;
    activeStrategyIndex = Strategy_Group_Index::Strategy_Group_Index_Default;
}

void RobotAI_Group::Update(uint32 pmDiff)
{
    strategyMap[activeStrategyIndex]->Update(pmDiff);
}

Strategy_Group* RobotAI_Group::GetActiveStrategy()
{
    return strategyMap[activeStrategyIndex];
}
