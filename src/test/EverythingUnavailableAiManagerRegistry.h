#pragma once

namespace ai
{
    class EverythingUnavailablePlayerbotAI : public MockPlayerbotAIBase
    {
    public:
        EverythingUnavailablePlayerbotAI() : MockPlayerbotAIBase()
		{
			managers[AiSpellManagerType] = new EverythingUnavailableAiSpellManager(ai, this, &buffer);
		}
        virtual bool CanCastSpell(string  name, Unit* target) { return false; }
    };

}