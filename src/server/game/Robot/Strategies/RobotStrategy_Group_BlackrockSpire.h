#ifndef ROBOT_STRATEGY_BLACKROCK_SPIRE_H
#define ROBOT_STRATEGY_BLACKROCK_SPIRE_H

#include "RobotStrategy_Group.h"

enum GroupRole_Blackrock_Spire :uint32
{
    GroupRole_Blackrock_Spire_DPS = 0,
    GroupRole_Blackrock_Spire_Tank1 = 1,
    GroupRole_Blackrock_Spire_Tank2 = 2,
    GroupRole_Blackrock_Spire_Tank3 = 3,
    GroupRole_Blackrock_Spire_Healer1 = 4,
    GroupRole_Blackrock_Spire_Healer2 = 5,
};

enum ActionType_Blackrock_Spire :uint32
{
    ActionType_Blackrock_Spire_None = 0,
    ActionType_Blackrock_Spire_TankGythMove,
    ActionType_Blackrock_Spire_TankRendMove,
    ActionType_Blackrock_Spire_DPSGythMove,
    ActionType_Blackrock_Spire_TankDrakkisathMove1,
    ActionType_Blackrock_Spire_TankDrakkisathMove2,
    ActionType_Blackrock_Spire_TankDrakkisathAddsMove,
    ActionType_Blackrock_Spire_DPSDrakkisathMove,
};

class RobotStrategy_Group_BlackrockSpire :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_BlackrockSpire(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    void InitialStrategy();

    void Update(uint32 pmDiff) override;
    std::string GetGroupRoleName() override;
    void SetGroupRole(std::string pmRoleName) override;
    Player* GetMainTank() override;
    bool DPS() override;
    bool Engage(Unit* pmTarget);
    bool Heal() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;

    Position tankGythPos;
    Position tankRendPos;
    Position dpsGythPos;
    Position tankDrakkisathPos1;
    Position tankDrakkisathPos2;
    Position tankDrakkisathAddsPos;
    Position dpsDrakkisathPos;
};
#endif
