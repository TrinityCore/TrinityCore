#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PossibleTargetsValue.h"

#include "../../../Grids/Notifiers/GridNotifiers.h"
#include "../../../Grids/Notifiers/GridNotifiersImpl.h"
#include "../../../Grids/Cells/CellImpl.h"

using namespace ai;
using namespace Trinity;

void PossibleTargetsValue::FindUnits(list<Unit*> &targets)
{
    AnyUnfriendlyUnitInObjectRangeCheck u_check(bot, bot, range);
    UnitListSearcher<AnyUnfriendlyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    bot->VisitNearbyObject(bot->GetMap()->GetVisibilityRange(), searcher);
}

bool PossibleTargetsValue::AcceptUnit(Unit* unit)
{
    return !unit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) &&
            (unit->IsHostileTo(bot) || (unit->getLevel() > 1 && !unit->IsFriendlyTo(bot)));
}
