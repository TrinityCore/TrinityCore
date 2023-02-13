#include "botpch.h"
#include "../../playerbot.h"
#include "CollisionValue.h"
#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"

#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

using namespace ai;

bool CollisionValue::Calculate()
{
    Unit* target = AI_VALUE(Unit*, qualifier);
    if (!target)
        return false;

    list<Unit*> targets;
    float range = sPlayerbotAIConfig.contactDistance;
    MaNGOS::AnyUnitInObjectRangeCheck u_check(bot, range);
    MaNGOS::UnitListSearcher<MaNGOS::AnyUnitInObjectRangeCheck> searcher(targets, u_check);
    Cell::VisitAllObjects(bot, searcher, range);

    for (list<Unit*>::iterator i = targets.begin(); i != targets.end(); ++i)
    {
        if (bot != *i && sServerFacade.GetDistance2d(bot, *i) < range) return true;
    }

    return false;
}
