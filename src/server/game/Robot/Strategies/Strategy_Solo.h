#ifndef ROBOT_STRATEGIES_SOLO_H
#define ROBOT_STRATEGIES_SOLO_H

#include "Script_Base.h"

enum RobotSoloState :uint32
{
    RobotSoloState_None = 0,
    RobotSoloState_Wander,
};

enum Solo_Instruction :uint8
{
	Solo_Instruction_None = 0,
	Solo_Instruction_Wander = 1,
	Solo_Instruction_Battle = 2,
	Solo_Instruction_Rest = 3,
	Solo_Instruction_Wait = 4,
	Solo_Instruction_Stroll = 5,
	Solo_Instruction_Confuse = 6
};

class Strategy_Solo
{
public:
    Strategy_Solo(uint32 pmAccount, uint32 pmCharacter);
	void Update();
    void Reset();
    bool Buff();
	bool Rest();
	bool Battle();
	bool Attack(Unit* pmTarget);
	bool Heal();
	bool Wait();
	bool Stroll();
	bool Confuse();

public:
    uint32 realPrevTime;
    uint32 account;
    uint32 character;

    uint32 soloState;
	int32 deathDuration;
	int32 soloDuration;	
	int32 waitDelay;
	int32 strollDelay;
	int32 confuseDelay;
	int32 interestsDelay;

    Script_Base* s_base;
};
#endif
