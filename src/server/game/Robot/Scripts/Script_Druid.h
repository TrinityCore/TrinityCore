#ifndef ROBOT_STRATEGIES_SCRIPT_DRUID_H
#define ROBOT_STRATEGIES_SCRIPT_DRUID_H

#ifndef DRUID_AURA_ECLIPSE_LUNAR
# define DRUID_AURA_ECLIPSE_LUNAR 48518
#endif

#ifndef DRUID_AURA_ECLIPSE_SOLAR
# define DRUID_AURA_ECLIPSE_SOLAR 48517
#endif

#ifndef DRUID_PREPARE_DISTANCE
# define DRUID_PREPARE_DISTANCE 10
#endif

#ifndef DRUID_RANGE_DISTANCE
# define DRUID_RANGE_DISTANCE 25
#endif

#include "Script_Base.h"

class Script_Druid :public Script_Base
{
public:    
	Script_Druid(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

    bool DPS_Balance(Unit* pmTarget, bool pmChase, bool pmAOE);
	bool DPS_Feral(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Plain(Unit* pmTarget, bool pmChase, bool pmAOE);
	bool Attack_Balance(Unit* pmTarget);
	bool Attack_Feral(Unit* pmTarget);
	bool Attack_Feral_Cat(Unit* pmTarget);
	bool Attack_Feral_Bear(Unit* pmTarget);
	bool Attack_Restoration(Unit* pmTarget);
};
#endif
