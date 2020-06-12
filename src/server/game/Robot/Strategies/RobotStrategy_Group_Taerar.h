#ifndef ROBOT_STRATEGY_TAERAR_H
#define ROBOT_STRATEGY_TAERAR_H

#include "RobotStrategy_Group.h"

enum GroupRole_Taerar :uint32
{
    GroupRole_Taerar_None = 0,
    GroupRole_Taerar_Tank1,
    GroupRole_Taerar_Tank2,
    GroupRole_Taerar_Tank3,
    GroupRole_Taerar_Tank4,
    GroupRole_Taerar_Tank5,
    GroupRole_Taerar_Healer1,
    GroupRole_Taerar_Healer2,
    GroupRole_Taerar_Healer3,
    GroupRole_Taerar_Healer4,
    GroupRole_Taerar_Healer5,
    GroupRole_Taerar_Healer6,
    GroupRole_Taerar_Healer7,
    GroupRole_Taerar_Healer8,
    GroupRole_Taerar_DPS_Range,
    GroupRole_Taerar_DPS_Melee,
};

enum ActionType_Taerar :uint32
{
    ActionType_Taerar_None = 0,
    ActionType_Taerar_MarkMove,
};

class RobotStrategy_Group_Taerar :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Taerar(Player* pmMe) :RobotStrategy_Group(pmMe)
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
    uint32 shadeCombatTime;
};
#endif
