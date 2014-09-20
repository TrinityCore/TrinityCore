#pragma once
#include "../Value.h"

namespace ai
{
    class PetTargetValue : public UnitCalculatedValue
	{
	public:
        PetTargetValue(PlayerbotAI* ai) : UnitCalculatedValue(ai) {}

        virtual Unit* Calculate() { return (Unit*)(ai->GetBot()->GetPet()); }
    };
}
