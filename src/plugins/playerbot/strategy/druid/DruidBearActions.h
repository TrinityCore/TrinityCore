#pragma once

namespace ai {
	class CastFeralChargeBearAction : public CastReachTargetSpellAction
	{
	public:
		CastFeralChargeBearAction(PlayerbotAI* ai) : CastReachTargetSpellAction(ai, "feral charge - bear", 1.5f) {}
	};

	class CastGrowlAction : public CastSpellAction
	{
	public:
		CastGrowlAction(PlayerbotAI* ai) : CastSpellAction(ai, "growl") {}
	};

	class CastMaulAction : public CastMeleeSpellAction
	{
	public:
		CastMaulAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "maul") {}
		virtual bool isUseful() { return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "rage", "self target") >= 45; }
	};

	class CastBashAction : public CastMeleeSpellAction
	{
	public:
		CastBashAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "bash") {}
	};

	class CastSwipeAction : public CastMeleeSpellAction
	{
	public:
		CastSwipeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "swipe") {}
	};

	class CastDemoralizingRoarAction : public CastDebuffSpellAction
	{
	public:
		CastDemoralizingRoarAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "demoralizing roar") {}
	};

	class CastMangleBearAction : public CastMeleeSpellAction
	{
	public:
		CastMangleBearAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "mangle (bear)") {}
	};

	class CastSwipeBearAction : public CastMeleeSpellAction
	{
	public:
		CastSwipeBearAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "swipe (bear)") {}
	};

    class CastLacerateAction : public CastMeleeSpellAction
    {
    public:
        CastLacerateAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "lacerate") {}
    };

    class CastBashOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastBashOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "bash") {}
    };
}
