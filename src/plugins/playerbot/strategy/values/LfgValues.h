#pragma once

#include "../Value.h"

namespace ai
{
class LfgProposalValue : public ManualSetValue<uint32>
{
public:
    LfgProposalValue(PlayerbotAI* ai) : ManualSetValue<uint32>(ai, 0, "lfg proposal") {}
};
}
