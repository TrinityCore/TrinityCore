#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{
    
    BUFF_TRIGGER(HornOfWinterTrigger, "horn of winter", "horn of winter")
	BUFF_TRIGGER(BoneShieldTrigger, "bone shield", "bone shield")
	BUFF_TRIGGER(ImprovedIcyTalonsTrigger, "improved icy talons", "improved icy talons")

    class DKPresenceTrigger : public BuffTrigger {
    public:
        DKPresenceTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blood presence") {}
        virtual bool IsActive();
    };

    class PlagueStrikeTrigger : public DebuffTrigger {
    public:
		PlagueStrikeTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "plague strike") {}
	};

	class PestilenceTrigger : public DebuffTrigger {
	public:
		PestilenceTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "pestilence") {}
	};

	class BloodStrikeTrigger : public DebuffTrigger {
	public:
		BloodStrikeTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "blood strike") {}
	};

    class IcyTouchTrigger : public DebuffTrigger {
    public:
		IcyTouchTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "icy touch") {}
    };

	class HowlingBlastTrigger : public DebuffTrigger {
	public:
		HowlingBlastTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "howling blast") {}
	};

    class MindFreezeInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
		MindFreezeInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "mind freeze") {}
    };

	class StrangulateInterruptSpellTrigger : public InterruptSpellTrigger
	{
	public:
		StrangulateInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "strangulate") {}
	};

    class KillingMachineTrigger : public BoostTrigger
    {
    public:
		KillingMachineTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "killing machine") {}
    };

    class MindFreezeOnEnemyHealerTrigger : public InterruptEnemyHealerTrigger
    {
    public:
		MindFreezeOnEnemyHealerTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "mind freeze") {}
    };

	class StrangulateOnEnemyHealerTrigger : public InterruptEnemyHealerTrigger
	{
	public:
		StrangulateOnEnemyHealerTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "strangulate") {}
	};
}
