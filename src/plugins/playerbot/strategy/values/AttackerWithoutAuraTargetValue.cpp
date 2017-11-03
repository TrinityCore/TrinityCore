#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "AttackerWithoutAuraTargetValue.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;

Unit* AttackerWithoutAuraTargetValue::Calculate()
{
    list<ObjectGuid> attackers = ai->GetAiObjectContext()->GetValue<list<ObjectGuid> >("attackers")->Get();
    Unit* target = ai->GetAiObjectContext()->GetValue<Unit*>("current target")->Get();
    for (list<ObjectGuid>::iterator i = attackers.begin(); i != attackers.end(); ++i)
    {
        Unit* unit = ai->GetUnit(*i);
        if (!unit || unit == target)
            continue;

        if (bot->GetDistance(unit) > sPlayerbotAIConfig.spellDistance)
            continue;

        if (!ai->HasAura(qualifier, unit))
            return unit;
    }

    return NULL;
}
