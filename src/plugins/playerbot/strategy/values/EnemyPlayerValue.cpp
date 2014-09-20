#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "EnemyPlayerValue.h"
#include "TargetValue.h"

using namespace ai;
using namespace std;

class FindEnemyPlayerStrategy : public FindTargetStrategy
{
public:
    FindEnemyPlayerStrategy(PlayerbotAI* ai) : FindTargetStrategy(ai)
    {
    }

public:
    virtual void CheckAttacker(Unit* attacker, ThreatManager* threatManager)
    {
        if (!result)
        {
            Player* enemy = dynamic_cast<Player*>(attacker);
            if (enemy && ai->IsOpposing(enemy) && enemy->IsOutdoorPvPActive())
                result = attacker;
        }
    }

};


Unit* EnemyPlayerValue::Calculate()
{
    FindEnemyPlayerStrategy strategy(ai);
    return FindTarget(&strategy);
}
