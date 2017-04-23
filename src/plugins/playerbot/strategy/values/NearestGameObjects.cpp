#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "NearestGameObjects.h"

#include "../../../Grids/Notifiers/GridNotifiers.h"
#include "../../../Grids/Notifiers/GridNotifiersImpl.h"
#include "../../../Grids/Cells/CellImpl.h"

using namespace ai;
using namespace Trinity;

class AnyGameObjectInObjectRangeCheck
{
public:
    AnyGameObjectInObjectRangeCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) {}
    WorldObject const& GetFocusObject() const { return *i_obj; }
    bool operator()(GameObject* u)
    {
        if (u && i_obj->IsWithinDistInMap(u, i_range) && u->isSpawned() && u->GetGOInfo())
            return true;

        return false;
    }

private:
    WorldObject const* i_obj;
    float i_range;
};

list<ObjectGuid> NearestGameObjects::Calculate()
{
    list<GameObject*> targets;

    AnyGameObjectInObjectRangeCheck u_check(bot, range);
    GameObjectListSearcher<AnyGameObjectInObjectRangeCheck> searcher(bot, targets, u_check);
    bot->VisitNearbyObject(bot->GetMap()->GetVisibilityRange(), searcher);

    list<ObjectGuid> result;
    for(list<GameObject*>::iterator tIter = targets.begin(); tIter != targets.end(); ++tIter)
    {
		GameObject* go = *tIter;
        if(bot->IsWithinLOSInMap(go))
			result.push_back(go->GetGUID());
    }

    return result;
}
