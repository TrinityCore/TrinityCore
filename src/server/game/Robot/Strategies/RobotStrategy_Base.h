#ifndef ROBOT_STRATEGY_BASE_H
#define ROBOT_STRATEGY_BASE_H

#ifndef ANGLE_RANGE
# define ANGLE_RANGE M_PI / 16
#endif

#include "Player.h"

class RobotStrategy_Base
{
public:
    RobotStrategy_Base(Player* pmMe);
    virtual void Update(uint32 pmDiff);

public:
    Player* me;
    Unit* engageTarget;

    int restDelay;
    int32 engageDelay;
};
#endif
