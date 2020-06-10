#ifndef ROBOT_STRATEGY_EMERISS_H
#define ROBOT_STRATEGY_EMERISS_H

#include "RobotStrategy_Group.h"

enum GroupRole_Emeriss :uint32
{
    GroupRole_Emeriss_Tank1 = 0,
    GroupRole_Emeriss_Tank2,
    GroupRole_Emeriss_Healer1,
    GroupRole_Emeriss_Healer2,
    GroupRole_Emeriss_Healer3,
    GroupRole_Emeriss_Healer4,
    GroupRole_Emeriss_Healer5,
    GroupRole_Emeriss_Healer6,
    GroupRole_Emeriss_Healer7,
    GroupRole_Emeriss_Healer8,
    GroupRole_Emeriss_Healer9,
    GroupRole_Emeriss_Healer10,
    GroupRole_Emeriss_Healer11,
    GroupRole_Emeriss_Healer12,
    GroupRole_Emeriss_DPS_Range,
    GroupRole_Emeriss_DPS_Melee,
};

enum ActionType_Emeriss :uint32
{
    ActionType_Emeriss_None = 0,
    ActionType_Emeriss_MarkMove,
};

class RobotStrategy_Group_Emeriss :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Emeriss(Player* pmMe) :RobotStrategy_Group(pmMe)
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
