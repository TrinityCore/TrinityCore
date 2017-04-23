#pragma once
#include "../Value.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class NearestGameObjects : public ObjectGuidListCalculatedValue
	{
	public:
        NearestGameObjects(PlayerbotAI* ai, float range = sPlayerbotAIConfig.sightDistance) :
            ObjectGuidListCalculatedValue(ai), range(range) {}

    protected:
        virtual list<ObjectGuid> Calculate();

    private:
        float range;
	};
}
