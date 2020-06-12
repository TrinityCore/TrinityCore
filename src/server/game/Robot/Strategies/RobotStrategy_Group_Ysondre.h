#ifndef ROBOT_STRATEGY_YSONDRE_H
#define ROBOT_STRATEGY_YSONDRE_H

#include "RobotStrategy_Group.h"

enum GroupRole_Ysondre :uint32
{
    GroupRole_Ysondre_None = 0,
    GroupRole_Ysondre_Tank1,
    GroupRole_Ysondre_Tank2,
    GroupRole_Ysondre_Healer1,
    GroupRole_Ysondre_Healer2,
    GroupRole_Ysondre_Healer3,
    GroupRole_Ysondre_Healer4,
    GroupRole_Ysondre_Healer5,
    GroupRole_Ysondre_Healer6,
    GroupRole_Ysondre_Healer7,
    GroupRole_Ysondre_Healer8,
    GroupRole_Ysondre_DPS_Range,
    GroupRole_Ysondre_DPS_Melee,
};

enum ActionType_Ysondre :uint32
{
    ActionType_Ysondre_None = 0,
    ActionType_Ysondre_MarkMove,
};

class RobotStrategy_Group_Ysondre :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Ysondre(Player* pmMe) :RobotStrategy_Group(pmMe)
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
