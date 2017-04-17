#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NearestFriendlyPlayersValue.h"

#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

using namespace ai;
using namespace Trinity;

void NearestFriendlyPlayersValue::FindUnits(list<Unit*> &targets)
{
	Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(bot, bot, range);
	Trinity::UnitListSearcher<AnyFriendlyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
	bot->VisitNearbyObject(range, searcher);
}

bool NearestFriendlyPlayersValue::AcceptUnit(Unit* unit)
{
    return dynamic_cast<Player*>(unit);
}
