#include "RobotAI_Solo.h"

RobotAI_Solo::RobotAI_Solo(Player* pmMe)
{
    me = pmMe;
    strategyMap.clear();
    Strategy_Solo* ss = new Strategy_Solo(pmMe);
    strategyMap[Strategy_Solo_Index::Strategy_Solo_Index_Default] = ss;
    activeStrategyIndex = Strategy_Solo_Index::Strategy_Solo_Index_Default;
}

void RobotAI_Solo::Update(uint32 pmDiff)
{
    strategyMap[activeStrategyIndex]->Update(pmDiff);
}

Strategy_Solo* RobotAI_Solo::GetActiveStrategy()
{
    return strategyMap[activeStrategyIndex];
}
