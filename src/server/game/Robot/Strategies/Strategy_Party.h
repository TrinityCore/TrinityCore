#ifndef ROBOT_STRATEGIES_PARTY_H
#define ROBOT_STRATEGIES_PARTY_H

#ifndef DPS_DELAY
# define DPS_DELAY 4000
#endif

class RobotAI;

enum Group_Instruction :uint8
{
    Group_Instruction_None = 0,
    Group_Instruction_Wander = 1,
    Group_Instruction_Battle = 2,
    Group_Instruction_Rest = 3
};

class Strategy_Party
{
public:
    Strategy_Party(uint32 pmID);
    void Set();
    void Update();
    bool Rest(bool pmForce = false);
    bool Buff();    
    bool Battle();
    bool DPS();
    bool DPS(Unit* pmTarget);
    bool Tank();
    bool Tank(Unit* pmTarget);
    bool Attack(Unit* pmTarget);
    bool Healer();
    bool Follow();
    bool Follow(float pmFollowDistance);
    bool Stay();

    bool GroupInCombat();

public:
    uint32 realPrevTime;
    uint8 memberNumber;

    uint32 partyID;
    uint8 instruction;
    int32 assembleDelay;
    int32 dpsDelay;
    int32 groupCombatTime;

    std::unordered_set<uint32> memberSessionIDSet;

    float followDistance;
};
#endif
