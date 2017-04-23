#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TellTargetAction.h"


using namespace ai;

bool TellTargetAction::Execute(Event event)
{
    Unit* target = context->GetValue<Unit*>("current target")->Get();
    if (target)
    {
        ostringstream out;
		out << "Attacking " << target->GetName();
        ai->TellMaster(out);

        context->GetValue<Unit*>("old target")->Set(target);
    }
    return true;
}

bool TellAttackersAction::Execute(Event event)
{
    ai->TellMaster("--- Attackers ---");

    list<ObjectGuid> attackers = context->GetValue<list<ObjectGuid> >("attackers")->Get();
    for (list<ObjectGuid>::iterator i = attackers.begin(); i != attackers.end(); i++)
    {
        Unit* unit = ai->GetUnit(*i);
        if (!unit || !unit->IsAlive())
            continue;

        ai->TellMaster(unit->GetName());
    }

    ai->TellMaster("--- Threat ---");
    HostileReference *ref = bot->getHostileRefManager().getFirst();
    if (!ref)
        return true;

    while( ref )
    {
        ThreatManager *threatManager = ref->GetSource();
        Unit *unit = threatManager->GetOwner();
        float threat = ref->getThreat();

        ostringstream out; out << unit->GetName() << " (" << threat << ")";
        ai->TellMaster(out);

        ref = ref->next();
    }
    return true;
}
