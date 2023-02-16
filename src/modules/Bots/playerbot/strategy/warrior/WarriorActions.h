#pragma once
#include "../actions/GenericActions.h"

namespace ai
{
    // battle
    class CastBattleMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastBattleMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("battle stance"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    // berserker
    class CastBerserkerMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastBerserkerMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge(NextAction::array(0, new NextAction("berserker stance"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    // defensive
    class CastDefensiveMeleeSpellAction : public CastMeleeSpellAction {
    public:
        CastDefensiveMeleeSpellAction(PlayerbotAI* ai, string spell) : CastMeleeSpellAction(ai, spell) {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastMeleeSpellAction::getPrerequisites());
        }
    };

    // all
    class CastHeroicStrikeAction : public CastMeleeSpellAction {
    public:
        CastHeroicStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "heroic strike") {}
    };

    // all
    class CastCleaveAction : public CastMeleeSpellAction {
    public:
        CastCleaveAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "cleave") {}
    };

 /*   // all
    class CastRampageAction : public CastMeleeSpellAction {
    public:
        CastRampageAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "rampage") {}
    };*/

    // battle
    class CastMockingBlowAction : public CastBattleMeleeSpellAction {
    public:
        CastMockingBlowAction(PlayerbotAI* ai) : CastBattleMeleeSpellAction(ai, "mocking blow") {}
    };

    // battle, berserker
    class CastMortalStrikeAction : public CastMeleeSpellAction {
    public:
        CastMortalStrikeAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "mortal strike") {}
    };

    class CastBloodthirstAction : public CastMeleeSpellAction {
    public:
        CastBloodthirstAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "bloodthirst") {}
    };

    // battle, berserker
    class CastExecuteAction : public CastMeleeSpellAction {
    public:
        CastExecuteAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "execute") {}
    };

    // berserker
    class CastWhirlwindAction : public CastBerserkerMeleeSpellAction {
    public:
        CastWhirlwindAction(PlayerbotAI* ai) : CastBerserkerMeleeSpellAction(ai, "whirlwind") {}
    };

    // berserker
    class CastPummelAction : public CastBerserkerMeleeSpellAction {
    public:
        CastPummelAction(PlayerbotAI* ai) : CastBerserkerMeleeSpellAction(ai, "pummel") {}
    };

    // battle
    class CastOverpowerAction : public CastBattleMeleeSpellAction {
    public:
        CastOverpowerAction(PlayerbotAI* ai) : CastBattleMeleeSpellAction(ai, "overpower") {}
    };

    // battle
    class CastRetaliationAction : public CastBattleMeleeSpellAction {
    public:
        CastRetaliationAction(PlayerbotAI* ai) : CastBattleMeleeSpellAction(ai, "retaliation") {}
    };

    // battle, berserker
    class CastHamstringAction : public CastSnareSpellAction {
    public:
        CastHamstringAction(PlayerbotAI* ai) : CastSnareSpellAction(ai, "hamstring") {}
    };

    // battle, berserker
    class CastSweepingStrikeAction : public CastSnareSpellAction {
    public:
        CastSweepingStrikeAction(PlayerbotAI* ai) : CastSnareSpellAction(ai, "sweeping strike") {}
    };

    // defensive
    class CastTauntAction : public CastSpellAction {
    public:
        CastTauntAction(PlayerbotAI* ai) : CastSpellAction(ai, "taunt") {}
        virtual NextAction** getPrerequisites() {
            return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastSpellAction::getPrerequisites());
        }
    };

    // defensive
    class CastShieldBlockAction : public CastBuffSpellAction {
    public:
        CastShieldBlockAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shield block") {}
		virtual NextAction** getPrerequisites() {
			return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastSpellAction::getPrerequisites());
		}
    };

    // defensive
    class CastSpellReflectionAction : public CastDefensiveMeleeSpellAction {
    public:
        CastSpellReflectionAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "spell reflection") {}
    };

    // defensive
    class CastShieldWallAction : public CastDefensiveMeleeSpellAction {
    public:
        CastShieldWallAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "shield wall") {}
    };

    class CastBloodrageAction : public CastBuffSpellAction {
    public:
        CastBloodrageAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "bloodrage") {}
    };

    // defensive
    class CastDevastateAction : public CastDefensiveMeleeSpellAction {
    public:
        CastDevastateAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "devastate") {}
    };

    // all
    class CastSlamAction : public CastMeleeSpellAction {
    public:
        CastSlamAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "slam") {}
    };

	// all
	class CastShieldSlamAction : public CastMeleeSpellAction {
	public:
		CastShieldSlamAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "shield slam") {}
	};

    // after dodge
    BEGIN_MELEE_SPELL_ACTION(CastRevengeAction, "revenge")
        virtual NextAction** getPrerequisites();
    END_SPELL_ACTION()

    // after crit
    BEGIN_MELEE_SPELL_ACTION(CastRampageAction, "rampage")
        virtual NextAction** getPrerequisites();
    END_SPELL_ACTION()

    //debuffs
    BEGIN_DEBUFF_ACTION(CastRendAction, "rend")
    END_SPELL_ACTION()

    class CastRendOnAttackerAction : public CastDebuffSpellOnAttackerAction
    {
    public:
        CastRendOnAttackerAction(PlayerbotAI* ai) : CastDebuffSpellOnAttackerAction(ai, "rend") {}
    };

    BEGIN_DEBUFF_ACTION(CastDisarmAction, "disarm")
        virtual NextAction** getPrerequisites();
    END_SPELL_ACTION()

    BEGIN_DEBUFF_ACTION(CastSunderArmorAction, "sunder armor") // 5 times
    END_SPELL_ACTION()

    class CastDemoralizingShoutAction : public CastDebuffSpellAction {
    public:
        CastDemoralizingShoutAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "demoralizing shout") {}
    };

    BEGIN_MELEE_SPELL_ACTION(CastChallengingShoutAction, "challenging shout")
    END_SPELL_ACTION()

    // stuns
    BEGIN_MELEE_SPELL_ACTION(CastShieldBashAction, "shield bash")
    END_SPELL_ACTION()

    BEGIN_MELEE_SPELL_ACTION(CastIntimidatingShoutAction, "intimidating shout")
    END_SPELL_ACTION()

    BEGIN_MELEE_SPELL_ACTION(CastThunderClapAction, "thunder clap")
    END_SPELL_ACTION()

    // buffs
	class CastBattleShoutAction : public CastBuffSpellAction {
	public:
		CastBattleShoutAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "battle shout") {}
	};

	class CastDefensiveStanceAction : public CastBuffSpellAction {
	public:
		CastDefensiveStanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "defensive stance") {}
	};

	class CastBattleStanceAction : public CastBuffSpellAction {
	public:
		CastBattleStanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "battle stance") {}
	};

    class CastBerserkerStanceAction : public CastBuffSpellAction {
    public:
        CastBerserkerStanceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "berserker stance") {}
    };

    BEGIN_RANGED_SPELL_ACTION(CastChargeAction, "charge")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastInterceptAction, "intercept")
    END_SPELL_ACTION()

	class CastDeathWishAction : public CastBuffSpellAction {
	public:
		CastDeathWishAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "death wish") {}
	};

	class CastBerserkerRageAction : public CastBerserkerMeleeSpellAction {
	public:
		CastBerserkerRageAction(PlayerbotAI* ai) : CastBerserkerMeleeSpellAction(ai, "berserker rage") {}
	};

	class CastLastStandAction : public CastBuffSpellAction {
	public:
		CastLastStandAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "last stand") {}
	};

    // berserker
    class CastRecklessnessAction : public CastBerserkerMeleeSpellAction {
    public:
        CastRecklessnessAction(PlayerbotAI* ai) : CastBerserkerMeleeSpellAction(ai, "recklessness") {}
    };

	// defensive
	//class CastShockwaveAction : public CastDefensiveMeleeSpellAction {
	//public:
	//	CastShockwaveAction(PlayerbotAI* ai) : CastDefensiveMeleeSpellAction(ai, "shockwave") {}
	//};

	// defensive
	class CastConcussionBlowAction : public CastSnareSpellAction {
	public:
		CastConcussionBlowAction(PlayerbotAI* ai) : CastSnareSpellAction(ai, "concussion blow") {}
	};

	BEGIN_MELEE_SPELL_ACTION(CastVictoryRushAction, "victory rush")
	END_SPELL_ACTION()

    class CastShieldBashOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
    {
    public:
        CastShieldBashOnEnemyHealerAction(PlayerbotAI* ai) : CastSpellOnEnemyHealerAction(ai, "shield bash") {}
    };
}
