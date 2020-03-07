#ifndef ROBOT_STRATEGIES_RAID_H
#define ROBOT_STRATEGIES_RAID_H

#ifndef DPS_DELAY
# define DPS_DELAY 4000
#endif

class Strategy_Raid
{
public:
    Strategy_Raid(uint32 pmID);
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

    uint32 raidID;
    std::unordered_set<uint32> memberSessionIDSet;
    uint8 instruction;
    int32 assembleDelay;
    int32 dpsDelay;
    int32 groupCombatTime;

    float followDistance;
};
#endif
