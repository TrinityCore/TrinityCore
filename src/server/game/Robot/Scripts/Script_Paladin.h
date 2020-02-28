#ifndef ROBOT_STRATEGIES_SCRIPT_PALADIN_H
#define ROBOT_STRATEGIES_SCRIPT_PALADIN_H

#ifndef AURA_THE_ART_OF_WAR_1
# define AURA_THE_ART_OF_WAR_1 53489
#endif

#ifndef AURA_THE_ART_OF_WAR_2
# define AURA_THE_ART_OF_WAR_2 59578
#endif

#include "Script_Base.h"
#include "RobotAI.h"

class Script_Paladin :public Script_Base
{
public:
	Script_Paladin(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget);
	virtual bool Tank(Unit* pmTarget);
	virtual bool Healer();
	virtual bool Attack(Unit* pmTarget);
	virtual bool Buff();
	virtual bool HealMe();

	bool DPS_Retribution(Unit* pmTarget);

    bool DPS_Common(Unit* pmTarget);

    bool Attack_Retribution(Unit* pmTarget);
    bool Attack_Common(Unit* pmTarget);
};
#endif
