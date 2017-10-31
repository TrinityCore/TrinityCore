#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NearestNonBotPlayersValue.h"

#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

using namespace ai;
using namespace Trinity;

void NearestNonBotPlayersValue::FindUnits(list<Unit*> &targets)
{
    Trinity::AnyUnitInObjectRangeCheck u_check(bot, range);
	Trinity::UnitListSearcher<AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
	bot->VisitNearbyObject(range, searcher);
}

bool NearestNonBotPlayersValue::AcceptUnit(Unit* unit)
{
    ObjectGuid guid = unit->GetGUID();
    return guid.IsPlayer() && !((Player*)unit)->GetPlayerbotAI();
}
