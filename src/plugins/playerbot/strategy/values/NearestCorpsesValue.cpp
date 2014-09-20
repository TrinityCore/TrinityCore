#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NearestCorpsesValue.h"

#include "../../../Grids/Notifiers/GridNotifiers.h"
#include "../../../Grids/Notifiers/GridNotifiersImpl.h"
#include "../../../Grids/Cells/CellImpl.h"

using namespace ai;
using namespace Trinity;

class AnyDeadUnitInObjectRangeCheck
{
public:
    AnyDeadUnitInObjectRangeCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) {}
    WorldObject const& GetFocusObject() const { return *i_obj; }
    bool operator()(Unit* u)
    {
        return !u->IsAlive() && i_obj->IsWithinDistInMap(u, i_range);
    }
private:
    WorldObject const* i_obj;
    float i_range;
};

void NearestCorpsesValue::FindUnits(list<Unit*> &targets)
{
    AnyDeadUnitInObjectRangeCheck u_check(bot, range);
    UnitListSearcher<AnyDeadUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    bot->VisitNearbyObject(bot->GetMap()->GetVisibilityRange(), searcher);
}

bool NearestCorpsesValue::AcceptUnit(Unit* unit)
{
    return true;
}
