#ifndef ROBOT_STRATEGY_SOLO_H
#define ROBOT_STRATEGY_SOLO_H

#include "RobotStrategy_Base.h"

enum RobotSoloState :uint32
{
    RobotSoloState_None = 0,
    RobotSoloState_Wander,
    RobotSoloState_Battle,
    RobotSoloState_Rest,
    RobotSoloState_Wait,
    RobotSoloState_Stroll,
    RobotSoloState_Confuse,
};

class RobotStrategy_Solo :public RobotStrategy_Base
{
public:
    RobotStrategy_Solo(Player* pmMe) :RobotStrategy_Base(pmMe)
    {
        InitialStrategy();
    }
    void InitialStrategy();
    void Reset();
    void HandleChatCommand(Player* pmSender, std::string pmCMD);

    void Update(uint32 pmDiff) override;

    virtual bool Buff();
    virtual bool Rest();
    virtual bool PVP();
    virtual bool Battle();
    virtual bool Heal();
    virtual bool Wait();
    virtual bool Stroll();
    virtual bool Confuse();


public:
    uint32 soloState;
    int32 deathDelay;
    int32 soloDelay;
    int32 waitDelay;
    int32 strollDelay;
    int32 confuseDelay;
    int32 interestsDelay;
};
#endif
