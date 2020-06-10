#ifndef ROBOT_STRATEGY_TEST_H
#define ROBOT_STRATEGY_TEST_H

#include "RobotStrategy_Group.h"

enum GroupRole_Test :uint32
{
    GroupRole_Test_Tank1 = 0,
    GroupRole_Test_Tank2 = 1,
    GroupRole_Test_Tank3 = 2,
    GroupRole_Test_Tank4 = 3,
    GroupRole_Test_Tank5 = 4,
    GroupRole_Test_Healer1 = 5,
    GroupRole_Test_Healer2 = 6,
    GroupRole_Test_Healer3 = 7,
    GroupRole_Test_Healer4 = 8,
    GroupRole_Test_Healer5 = 9,
    GroupRole_Test_Healer6 = 10,
    GroupRole_Test_Healer7 = 11,
    GroupRole_Test_Healer8 = 12,
    GroupRole_Test_DPS_Range = 13,
    GroupRole_Test_DPS_Melee = 14,
};

enum ActionType_Test :uint32
{
    ActionType_Test_None = 0,
    ActionType_Test_MarkMove,
};

class RobotStrategy_Group_Test :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Test(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    void InitialStrategy();
    std::string GetGroupRoleName() override;
    void SetGroupRole(std::string pmRoleName) override;
    bool Follow() override;
    bool Stay(std::string pmTargetGroupRole) override;
    bool Hold(std::string pmTargetGroupRole) override;
    bool Engage(Unit* pmTarget) override;
    bool DPS() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;
    bool Heal() override;
    void Update(uint32 pmDiff) override;

    float engageAngle;
    float engageDistance;    
};
#endif
