#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TankTargetValue.h"

using namespace ai;

class FindTargetForTankStrategy : public FindTargetStrategy
{
public:
    FindTargetForTankStrategy(PlayerbotAI* ai) : FindTargetStrategy(ai)
    {
        minThreat = 0;
        minTankCount = 0;
        maxDpsCount = 0;
    }

public:
    virtual void CheckAttacker(Unit* creature, ThreatManager* threatManager)
    {
        Player* bot = ai->GetBot();
        float threat = threatManager->getThreat(bot);
        int tankCount, dpsCount;
        GetPlayerCount(creature, &tankCount, &dpsCount);

        if (!result ||
            (minThreat >= threat &&
            (minTankCount >= tankCount || maxDpsCount <= dpsCount)))
        {
            minThreat = threat;
            minTankCount = tankCount;
            maxDpsCount = dpsCount;
            result = creature;
        }
    }

protected:
    float minThreat;
    int minTankCount;
    int maxDpsCount;
};


Unit* TankTargetValue::Calculate()
{
    FindTargetForTankStrategy strategy(ai);
    return FindTarget(&strategy);
}
