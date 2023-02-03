#include "botpch.h"
#include "../../playerbot.h"
#include "SnareTargetValue.h"
#include "../../PlayerbotAIConfig.h"
#include "MotionGenerators/TargetedMovementGenerator.h"

using namespace ai;

Unit* SnareTargetValue::Calculate()
{
    string spell = qualifier;

    list<ObjectGuid> attackers = ai->GetAiObjectContext()->GetValue<list<ObjectGuid> >("attackers")->Get();
    Unit* target = ai->GetAiObjectContext()->GetValue<Unit*>("current target")->Get();
    for (list<ObjectGuid>::iterator i = attackers.begin(); i != attackers.end(); ++i)
    {
        Unit* unit = ai->GetUnit(*i);
        if (!unit || unit == target)
            continue;

        if (bot->GetDistance(unit) > sPlayerbotAIConfig.spellDistance)
            continue;

        Unit* chaseTarget;
        switch (unit->GetMotionMaster()->GetCurrentMovementGeneratorType())
        {
        case FLEEING_MOTION_TYPE:
            return unit;
        case CHASE_MOTION_TYPE:
            if (unit->GetTypeId() == TYPEID_PLAYER)
            {
                chaseTarget = static_cast<ChaseMovementGenerator<Player> const*>(unit->GetMotionMaster()->GetCurrent())->
#ifdef MANGOS
                        GetTarget();
#endif
#ifdef CMANGOS
                        GetCurrentTarget();
#endif
            }
            else
            {
                chaseTarget = static_cast<ChaseMovementGenerator<Creature> const*>(unit->GetMotionMaster()->GetCurrent())->
#ifdef MANGOS
                        GetTarget();
#endif
#ifdef CMANGOS
                        GetCurrentTarget();
#endif
            }

            if (!chaseTarget) continue;
            Player* chaseTargetPlayer = sObjectMgr.GetPlayer(chaseTarget->GetObjectGuid());
            if (chaseTargetPlayer && !ai->IsTank(chaseTargetPlayer)) {
                return unit;
            }
        }
    }

    return NULL;
}
