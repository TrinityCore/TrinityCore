#include "RobotAI.h"

RobotAI::RobotAI(Player* pmMe)
{
    me = pmMe;
    checkDelay = 0;
    robotType = 0;
    strategyMap.clear();

    RobotStrategy_Solo* rss = new RobotStrategy_Solo(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Solo] = rss;

    RobotStrategy_Group* rsg = new RobotStrategy_Group(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group] = rsg;

    RobotStrategy_Group_Blackrock_Spire* rsgbs = new RobotStrategy_Group_Blackrock_Spire(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Blackrock_Spire] = rsgbs;

    RobotStrategy_Group_Alcaz_Island* rsgai = new RobotStrategy_Group_Alcaz_Island(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Alcaz_Island] = rsgai;

    RobotStrategy_Group_Shadow_Labyrinth* rsgsl = new RobotStrategy_Group_Shadow_Labyrinth(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Shadow_Labyrinth] = rsgsl;

    activeStrategyIndex = Strategy_Index::Strategy_Index_Solo;
}

void RobotAI::Update(uint32 pmDiff)
{
    checkDelay += pmDiff;
    if (checkDelay > AI_CHECK_DELAY)
    {
        strategyMap[activeStrategyIndex]->Update(checkDelay);
        checkDelay = 0;
    }
}

RobotStrategy* RobotAI::GetActiveStrategy(uint32 pmStrategyType)
{
    if (pmStrategyType == RobotStrategyType::RobotStrategyType_All)
    {
        return strategyMap[activeStrategyIndex];
    }
    else if (strategyMap[activeStrategyIndex]->strategyType == pmStrategyType)
    {
        return strategyMap[activeStrategyIndex];
    }
    return NULL;
}
