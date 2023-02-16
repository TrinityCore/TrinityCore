#include "botpch.h"
#include "../../playerbot.h"
#include "CheckValuesAction.h"

#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"
using namespace ai;

CheckValuesAction::CheckValuesAction(PlayerbotAI* ai) : Action(ai, "check values")
{
}

bool CheckValuesAction::Execute(Event event)
{
    list<ObjectGuid> possible_targets = *context->GetValue<list<ObjectGuid> >("possible targets");
    list<ObjectGuid> all_targets = *context->GetValue<list<ObjectGuid> >("all targets");
    list<ObjectGuid> npcs = *context->GetValue<list<ObjectGuid> >("nearest npcs");
    list<ObjectGuid> corpses = *context->GetValue<list<ObjectGuid> >("nearest corpses");
    list<ObjectGuid> gos = *context->GetValue<list<ObjectGuid> >("nearest game objects");
    list<ObjectGuid> nfp = *context->GetValue<list<ObjectGuid> >("nearest friendly players");
    return true;
}
