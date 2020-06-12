#ifndef ROBOT_STRATEGY_LETHON_H
#define ROBOT_STRATEGY_LETHON_H

#include "RobotStrategy_Group.h"

enum GroupRole_Lethon :uint32
{
    GroupRole_Lethon_None = 0,
    GroupRole_Lethon_Tank1,
    GroupRole_Lethon_Tank2,
    GroupRole_Lethon_Healer1,
    GroupRole_Lethon_Healer2,
    GroupRole_Lethon_Healer3,
    GroupRole_Lethon_Healer4,
    GroupRole_Lethon_Healer5,
    GroupRole_Lethon_Healer6,
    GroupRole_Lethon_Healer7,
    GroupRole_Lethon_Healer8,
    GroupRole_Lethon_DPS_Range,
    GroupRole_Lethon_DPS_Melee,
};

enum ActionType_Lethon :uint32
{
    ActionType_Lethon_None = 0,
    ActionType_Lethon_MarkMove,
};

class RobotStrategy_Group_Lethon :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Lethon(Player* pmMe) :RobotStrategy_Group(pmMe)
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
