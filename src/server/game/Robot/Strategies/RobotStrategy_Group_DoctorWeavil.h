#ifndef ROBOT_STRATEGY_DOCTOR_WEAVIL_H
#define ROBOT_STRATEGY_DOCTOR_WEAVIL_H

#include "RobotStrategy_Group.h"

class RobotStrategy_Group_DoctorWeavil :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_DoctorWeavil(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    bool DPS() override;
    bool Tank() override;
};
#endif
