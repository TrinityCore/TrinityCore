#ifndef ROBOT_STRATEGIES_SOLO_NORMAL_H
#define ROBOT_STRATEGIES_SOLO_NORMAL_H

#include "RobotAI.h"
#include "Player.h"

class RobotAI;

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

class Strategy_Solo_Normal
{
public:
	Strategy_Solo_Normal(RobotAI* pmSourceAI);
	void Update(uint32 pmDiff);

	bool Buff(Unit* pmTarget);	
	bool Rest();
	bool Battle();
	bool Attack(Unit* pmTarget);
	bool Heal();
	bool Wait();
	bool Stroll();
	bool Confuse();

public:
	RobotAI* sourceAI;

	uint8 instruction;
	int32 deathDuration;
	int32 soloDuration;	
	int32 waitDelay;
	int32 strollDelay;
	int32 confuseDelay;
	int32 interestsDelay;
};
#endif
