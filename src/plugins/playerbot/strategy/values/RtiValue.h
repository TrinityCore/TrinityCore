#pragma once
#include "../Value.h"

namespace ai
{
    class RtiValue : public ManualSetValue<string>
	{
	public:
        RtiValue(PlayerbotAI* ai);
    };
}
