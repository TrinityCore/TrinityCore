#include "RobotStrategy_Base.h"

RobotStrategy_Base::RobotStrategy_Base(Player* pmMe)
{
    me = pmMe;
    engageTarget = NULL;
    restDelay = 0;
    engageDelay = 0;
}

void RobotStrategy_Base::Update(uint32 pmDiff)
{
    return;
}
