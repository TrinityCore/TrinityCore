#ifndef ROBOT_STRATEGY_AZUREGOS_H
#define ROBOT_STRATEGY_AZUREGOS_H

#include "RobotStrategy_Group.h"

enum GroupRole_Azuregos :uint32
{
    GroupRole_Azuregos_Tank = 0,
    GroupRole_Azuregos_Healer1,
    GroupRole_Azuregos_Healer2,
    GroupRole_Azuregos_DPS,
};

enum ActionType_Azuregos :uint32
{
    ActionType_Azuregos_None = 0,
    ActionType_Azuregos_MarkMove,
};

class RobotStrategy_Group_Azuregos :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Azuregos(Player* pmMe) :RobotStrategy_Group(pmMe)
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
