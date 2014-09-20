#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TellLosAction.h"


using namespace ai;

bool TellLosAction::Execute(Event event)
{
    string param = event.getParam();

    if (param.empty() || param == "targets")
    {
        list<ObjectGuid> targets = *context->GetValue<list<ObjectGuid> >("possible targets");
        ListUnits("--- Targets ---", targets);
    }

    if (param.empty() || param == "npcs")
    {
        list<ObjectGuid> npcs = *context->GetValue<list<ObjectGuid> >("nearest npcs");
        ListUnits("--- NPCs ---", npcs);
    }

    if (param.empty() || param == "corpses")
    {
        list<ObjectGuid> corpses = *context->GetValue<list<ObjectGuid> >("nearest corpses");
        ListUnits("--- Corpses ---", corpses);
    }

    if (param.empty() || param == "gos" || param == "game objects")
    {
        list<ObjectGuid> gos = *context->GetValue<list<ObjectGuid> >("nearest game objects");
        ListGameObjects("--- Game objects ---", gos);
    }

    return true;
}

void TellLosAction::ListUnits(string title, list<ObjectGuid> units)
{
    ai->TellMaster(title);

    for (list<ObjectGuid>::iterator i = units.begin(); i != units.end(); i++)
    {
        Unit* unit = ai->GetUnit(*i);
        if (unit)
            ai->TellMaster(unit->GetName());
    }

}
void TellLosAction::ListGameObjects(string title, list<ObjectGuid> gos)
{
    ai->TellMaster(title);

    for (list<ObjectGuid>::iterator i = gos.begin(); i != gos.end(); i++)
    {
        GameObject* go = ai->GetGameObject(*i);
        if (go)
            ai->TellMaster(chat->formatGameobject(go));
    }
}
