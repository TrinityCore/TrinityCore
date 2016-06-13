#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DpsTargetValue.h"

using namespace ai;

class FindTargetForDpsStrategy : public FindTargetStrategy
{
public:
    FindTargetForDpsStrategy(PlayerbotAI* ai) : FindTargetStrategy(ai)
    {
        minThreat = 0;
        maxTankCount = 0;
        minDpsCount = 0;
    }

public:
    virtual void CheckAttacker(Unit* creature, ThreatManager* threatManager)
    {
        float threat = threatManager->getThreat(ai->GetBot());
        int tankCount, dpsCount;
        GetPlayerCount(creature, &tankCount, &dpsCount);

        if (!result ||
            minThreat >= threat && (maxTankCount <= tankCount || minDpsCount >= dpsCount))
        {
            minThreat = threat;
            maxTankCount = tankCount;
            minDpsCount = dpsCount;
            result = creature;
        }
    }

protected:
    float minThreat;
    int maxTankCount;
    int minDpsCount;
};


Unit* DpsTargetValue::Calculate()
{
    FindTargetForDpsStrategy strategy(ai);
    return FindTarget(&strategy);
}
