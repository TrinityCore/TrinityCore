#ifndef ROBOT_STRATEGIES_GROUP_NORMAL_H
#define ROBOT_STRATEGIES_GROUP_NORMAL_H

class RobotAI;

enum Group_Instruction :uint8
{
    Group_Instruction_None = 0,
    Group_Instruction_Wander = 1,
    Group_Instruction_Battle = 2,
    Group_Instruction_Rest = 3
};

class Strategy_Group_Normal
{
public:
    Strategy_Group_Normal(RobotAI* pmSourceAI);
    void Update(uint32 pmDiff);
    bool Rest(bool pmForce = false);
    bool Buff();
    bool Buff(Player* pmTarget);
    bool Battle();
    bool DPS();
    bool DPS(Unit* pmTarget);
    bool Tank();
    bool Tank(Unit* pmTarget);
    bool Attack(Unit* pmTarget);
    bool Healer();
    bool Healer(Unit* pmTarget);
    bool Follow();
    bool Follow(float pmFollowDistance);
    bool Stay();

    bool GroupInCombat();

public:
    RobotAI* sourceAI;
    uint8 memberNumber;

    uint8 instruction;
    int32 assembleDelay;

    float followDistance;
};
#endif
