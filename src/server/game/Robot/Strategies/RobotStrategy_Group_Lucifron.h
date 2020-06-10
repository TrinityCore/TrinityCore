#ifndef ROBOT_STRATEGY_LUCIFRON_H
#define ROBOT_STRATEGY_LUCIFRON_H

#include "RobotStrategy_Group.h"

enum GroupRole_Lucifron :uint32
{
    GroupRole_Lucifron_Tank1 = 0,
    GroupRole_Lucifron_Tank2 = 1,
    GroupRole_Lucifron_Tank3 = 2,
    GroupRole_Lucifron_Tank4 = 3,
    GroupRole_Lucifron_Tank5 = 4,
    GroupRole_Lucifron_Healer1 = 5,
    GroupRole_Lucifron_Healer2 = 6,
    GroupRole_Lucifron_Healer3 = 7,
    GroupRole_Lucifron_Healer4 = 8,
    GroupRole_Lucifron_Healer5 = 9,
    GroupRole_Lucifron_Healer6 = 10,
    GroupRole_Lucifron_Healer7 = 11,
    GroupRole_Lucifron_Healer8 = 12,
    GroupRole_Lucifron_DPS_Range = 13,
    GroupRole_Lucifron_DPS_Melee = 14,
};

enum ActionType_Lucifron :uint32
{
    ActionType_Lucifron_None = 0,
    ActionType_Lucifron_MarkMove,
};

class RobotStrategy_Group_Lucifron :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Lucifron(Player* pmMe) :RobotStrategy_Group(pmMe)
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
