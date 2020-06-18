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
# define DRUID_RANGE_DISTANCE 30
#endif

#ifndef DRUID_CHARGE_DISTANCE
# define DRUID_CHARGE_DISTANCE 9
#endif

#include "Script_Base.h"

class Script_Druid :public Script_Base
{
public:
    Script_Druid(Player* pmMe);
    void Update(uint32 pmDiff);
    bool SubTank(Unit* pmTarget, bool pmChase);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting = true);
    bool Tank(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    bool Taunt(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure = true);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure = true);

    bool DPS_Balance(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Feral(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool Tank_Feral(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    bool Attack_Balance(Unit* pmTarget);
    bool Attack_Feral(Unit* pmTarget);
    bool Attack_Feral_Cat(Unit* pmTarget);
    bool Attack_Feral_Bear(Unit* pmTarget);
    bool Attack_Common(Unit* pmTarget);
    bool Heal_Restoration(Unit* pmTarget, bool pmCure);

    int demoralizingRoarDelay;
};
#endif
