#pragma once
#include "../Value.h"
#include "TargetValue.h"
#include "../../LootObjectStack.h"

namespace ai
{
    class HasTotemValue : public BoolCalculatedValue, public Qualified
	{
	public:
        HasTotemValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

    public:
        bool Calculate()
        {
            list<ObjectGuid> units = *context->GetValue<list<ObjectGuid> >("nearest npcs");
            for (list<ObjectGuid>::iterator i = units.begin(); i != units.end(); i++)
            {
                Unit* unit = ai->GetUnit(*i);
                if (!unit)
                    continue;

                Creature* creature = dynamic_cast<Creature*>(unit);
                if (!creature || !creature->IsTotem())
                    continue;

                if (strstri(creature->GetName().c_str(), qualifier.c_str()) && bot->GetDistance(creature) <= sPlayerbotAIConfig.spellDistance)
                    return true;
            }

            return false;
        }
    };
}
