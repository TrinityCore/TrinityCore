#ifndef ROBOT_STRATEGY_TAERAR_H
#define ROBOT_STRATEGY_TAERAR_H

#include "RobotStrategy_Group.h"

enum GroupRole_Taerar :uint32
{
    GroupRole_Taerar_Tank1 = 0,
    GroupRole_Taerar_Tank2 = 1,
    GroupRole_Taerar_Tank3 = 2,
    GroupRole_Taerar_Tank4 = 3,
    GroupRole_Taerar_Tank5 = 4,
    GroupRole_Taerar_Healer1 = 5,
    GroupRole_Taerar_Healer2 = 6,
    GroupRole_Taerar_Healer3 = 7,
    GroupRole_Taerar_Healer4 = 8,
    GroupRole_Taerar_Healer5 = 9,
    GroupRole_Taerar_Healer6 = 10,
    GroupRole_Taerar_Healer7 = 11,
    GroupRole_Taerar_Healer8 = 12,
    GroupRole_Taerar_DPS_Range = 13,
    GroupRole_Taerar_DPS_Melee = 14,
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
