#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "CurrentCcTargetValue.h"

using namespace ai;

class FindCurrentCcTargetStrategy : public FindTargetStrategy
{
public:
    FindCurrentCcTargetStrategy(PlayerbotAI* ai, string spell) : FindTargetStrategy(ai)
    {
        this->spell = spell;
    }

public:
    virtual void CheckAttacker(Unit* attacker, ThreatManager* threatManager)
    {
        if (ai->HasAura(spell, attacker))
            result = attacker;
    }

private:
    string spell;
};


Unit* CurrentCcTargetValue::Calculate()
{
    FindCurrentCcTargetStrategy strategy(ai, qualifier);
    return FindTarget(&strategy);
}
