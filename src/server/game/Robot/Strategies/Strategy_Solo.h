#ifndef ROBOT_STRATEGIES_SOLO_H
#define ROBOT_STRATEGIES_SOLO_H

#include "Script_Base.h"
#include "Player.h"

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

class Strategy_Solo
{
public:
    Strategy_Solo(Player* pmMe);
    virtual void Update(uint32 pmDiff);
    void Reset();
    bool Buff();
	bool Rest();
    bool PVP();
	bool Battle();
	bool Heal();
	bool Wait();
	bool Stroll();
	bool Confuse();

    void HandleChatCommand(Player* pmSender, std::string pmCMD);

public:
    Player* me;
    uint32 soloState;
	int32 deathDelay;
    int32 soloDelay;
    int32 restDelay;
	int32 waitDelay;
	int32 strollDelay;
	int32 confuseDelay;
	int32 interestsDelay;
    int32 engageDelay;

    Script_Base* sb;
};
#endif
