#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NearestNpcsValue.h"

#include "../../../Grids/Notifiers/GridNotifiers.h"
#include "../../../Grids/Notifiers/GridNotifiersImpl.h"
#include "../../../Grids/Cells/CellImpl.h"


using namespace ai;
using namespace Trinity;

void NearestNpcsValue::FindUnits(list<Unit*> &targets)
{
    AnyFriendlyUnitInObjectRangeCheck u_check(bot, bot, range);
    UnitListSearcher<AnyFriendlyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    bot->VisitNearbyObject(bot->GetMap()->GetVisibilityRange(), searcher);
}

bool NearestNpcsValue::AcceptUnit(Unit* unit)
{
    return !dynamic_cast<Player*>(unit);
}
