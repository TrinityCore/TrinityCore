#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{
    BUFF_TRIGGER(BattleShoutTrigger, "battle shout", "battle shout")

    DEBUFF_TRIGGER(RendDebuffTrigger, "rend", "rend")
    DEBUFF_TRIGGER(DisarmDebuffTrigger, "disarm", "disarm")
    DEBUFF_TRIGGER(SunderArmorDebuffTrigger, "sunder armor", "sunder armor")

    class RendDebuffOnAttackerTrigger : public DebuffOnAttackerTrigger
    {
    public:
        RendDebuffOnAttackerTrigger(PlayerbotAI* ai) : DebuffOnAttackerTrigger(ai, "rend") {}
    };

	class RevengeAvailableTrigger : public SpellCanBeCastTrigger
	{
	public:
		RevengeAvailableTrigger(PlayerbotAI* ai) : SpellCanBeCastTrigger(ai, "revenge") {}
	};

    class RampageAvailableTrigger : public SpellCanBeCastTrigger
    {
    public:
        RampageAvailableTrigger(PlayerbotAI* ai) : SpellCanBeCastTrigger(ai, "rampage") {}
    };

    class BloodrageDebuffTrigger : public DebuffTrigger
    {
    public:
        BloodrageDebuffTrigger(PlayerbotAI* ai) : DebuffTrigger(ai, "bloodrage") {}
        virtual bool IsActive()
        {
            return DebuffTrigger::IsActive() &&
                AI_VALUE2(uint8, "health", "self target") >= 75 &&
                AI_VALUE2(uint8, "rage", "self target") < 20;
        }
    };

    class ShieldBashInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        ShieldBashInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "shield bash") {}
    };

    class VictoryRushTrigger : public HasAuraTrigger
    {
    public:
        VictoryRushTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "victory rush") {}
    };


    class ConcussionBlowTrigger : public SnareTargetTrigger
    {
    public:
        ConcussionBlowTrigger(PlayerbotAI* ai) : SnareTargetTrigger(ai, "concussion blow") {}
    };

    class HamstringTrigger : public SnareTargetTrigger
    {
    public:
        HamstringTrigger(PlayerbotAI* ai) : SnareTargetTrigger(ai, "hamstring") {}
    };

    class DeathWishTrigger : public BoostTrigger
    {
    public:
        DeathWishTrigger(PlayerbotAI* ai) : BoostTrigger(ai, "death wish") {}
    };

    class ShieldBashInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        ShieldBashInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "shield bash") {}
    };

    class PummelInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        PummelInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "pummel") {}
    };

    class PummelInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        PummelInterruptEnemyHealerSpellTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "pummel") {}
    };

    class WarriorCanInterceptTrigger : public Trigger {
    public:
        WarriorCanInterceptTrigger(PlayerbotAI* ai) : Trigger(ai, "intercept") {}
        virtual bool IsActive()
        {
#ifdef CMANGOS
            if (bot->isInCombat())
#endif
#ifdef MANGOS
            if (bot->IsInCombat())
#endif
            {
                Unit* target = AI_VALUE(Unit*, "current target");
                return target && AI_VALUE2(float, "distance", "current target") >= (sPlayerbotAIConfig.meleeDistance + 8) && target && AI_VALUE2(float, "distance", "current target") <= (sPlayerbotAIConfig.meleeDistance + 24);
            }
        }
    };

}
