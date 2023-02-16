#include "botpch.h"
#include "../../playerbot.h"
#include "LeastHpTargetValue.h"
#include "TargetValue.h"

using namespace ai;
using namespace std;

class FindLeastHpTargetStrategy : public FindTargetStrategy
{
public:
    FindLeastHpTargetStrategy(PlayerbotAI* ai) : FindTargetStrategy(ai)
    {
        minHealth = 0;
    }

public:
    virtual void CheckAttacker(Unit* attacker, ThreatManager* threatManager)
    {
        Group* group = ai->GetBot()->GetGroup();
        if (group)
        {
            uint64 guid = group->GetTargetIcon(4);
            if (guid && attacker->GetObjectGuid() == ObjectGuid(guid))
                return;
        }

        if (!result || result->GetHealth() > attacker->GetHealth())
            result = attacker;
    }

protected:
    float minHealth;
};


Unit* LeastHpTargetValue::Calculate()
{
    FindLeastHpTargetStrategy strategy(ai);
    return FindTarget(&strategy);
}
