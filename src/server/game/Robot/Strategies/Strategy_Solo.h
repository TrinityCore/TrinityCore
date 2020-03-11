#ifndef ROBOT_STRATEGIES_SOLO_H
#define ROBOT_STRATEGIES_SOLO_H

#include "Script_Base.h"

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

struct Strategy_Solo
{
public:
    Strategy_Solo()
    {

    }

    Strategy_Solo(uint32 pmAccount, uint32 pmCharacter);
	void Update();    
    bool Buff();
	bool Rest();
	bool Battle();
	bool Heal();
	bool Wait();
	bool Stroll();
	bool Confuse();

    void HandleChatCommand(Player* pmSender, std::string pmCMD);

public:
    uint32 realPrevTime;
    uint32 account;
    uint32 character;

    uint32 soloState;
	int32 deathDelay;
    int32 soloDelay;
    int32 restDelay;
	int32 waitDelay;
	int32 strollDelay;
	int32 confuseDelay;
	int32 interestsDelay;

    Script_Base* sb;
};
#endif
