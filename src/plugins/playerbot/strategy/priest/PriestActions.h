#pragma once

#include "../actions/GenericActions.h"

namespace ai
{
    class CastGreaterHealAction : public CastHealingSpellAction {
    public:
        CastGreaterHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "greater heal") {}
    };

    class CastGreaterHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastGreaterHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "greater heal") {}

        virtual string getName() { return "greater heal on party"; }
    };

    class CastLesserHealAction : public CastHealingSpellAction {
    public:
        CastLesserHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "lesser heal") {}
    };

    class CastLesserHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastLesserHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "lesser heal") {}

        virtual string getName() { return "lesser heal on party"; }
    };

    class CastFlashHealAction : public CastHealingSpellAction {
    public:
        CastFlashHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "flash heal") {}
    };

    class CastFlashHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastFlashHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "flash heal") {}

        virtual string getName() { return "flash heal on party"; }
    };

    class CastHealAction : public CastHealingSpellAction {
    public:
        CastHealAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "heal") {}
    };

    class CastHealOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastHealOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "heal") {}

        virtual string getName() { return "heal on party"; }
    };

    class CastRenewAction : public CastHealingSpellAction {
    public:
        CastRenewAction(PlayerbotAI* ai) : CastHealingSpellAction(ai, "renew") {}
    };

    class CastRenewOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastRenewOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "renew") {}

        virtual string getName() { return "renew on party"; }
    };

    class CastFadeAction : public CastBuffSpellAction {
    public:
        CastFadeAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "fade") {}
    };

    class CastShadowformAction : public CastBuffSpellAction {
    public:
        CastShadowformAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "shadowform") {}
    };

    class CastRemoveShadowformAction : public Action {
    public:
        CastRemoveShadowformAction(PlayerbotAI* ai) : Action(ai, "remove shadowform") {}
        virtual bool isUseful() { return ai->HasAura("shadowform", AI_VALUE(Unit*, "self target")); }
        virtual bool isPossible() { return true; }
        virtual bool Execute(Event event) {
            ai->RemoveAura("shadowform");
            return true;
        }
    };

	class CastVampiricEmbraceAction : public CastBuffSpellAction {
	public:
		CastVampiricEmbraceAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "vampiric embrace") {}
	};

	class CastPowerWordShieldAction : public CastBuffSpellAction {
	public:
		CastPowerWordShieldAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "power word: shield") {}
	};

    class CastPowerWordShieldOnPartyAction : public HealPartyMemberAction
    {
    public:
        CastPowerWordShieldOnPartyAction(PlayerbotAI* ai) : HealPartyMemberAction(ai, "power word: shield") {}

        virtual string getName() { return "power word: shield on party"; }
    };

	class CastPowerWordFortitudeAction : public CastBuffSpellAction {
	public:
		CastPowerWordFortitudeAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "power word: fortitude") {}
	};

	class CastDivineSpiritAction : public CastBuffSpellAction {
	public:
		CastDivineSpiritAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "divine spirit") {}
	};

	class CastInnerFireAction : public CastBuffSpellAction {
	public:
		CastInnerFireAction(PlayerbotAI* ai) : CastBuffSpellAction(ai, "inner fire") {}
	};

    BEGIN_SPELL_ACTION(CastHolyNovaAction, "holy nova")
    virtual bool isUseful() {
        return !ai->HasAura("shadowform", AI_VALUE(Unit*, "self target"));
    }
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastHolyFireAction, "holy fire")
        virtual bool isUseful() {
            return !ai->HasAura("shadowform", AI_VALUE(Unit*, "self target"));
        }
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastSmiteAction, "smite")
        virtual bool isUseful() {
			return !ai->HasAura("shadowform", AI_VALUE(Unit*, "self target"));
        }
    END_SPELL_ACTION()

	class CastPowerWordFortitudeOnPartyAction : public BuffOnPartyAction {
	public:
		CastPowerWordFortitudeOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "power word: fortitude") {}
	};

	class CastDivineSpiritOnPartyAction : public BuffOnPartyAction {
	public:
		CastDivineSpiritOnPartyAction(PlayerbotAI* ai) : BuffOnPartyAction(ai, "divine spirit") {}
	};

	class CastPowerWordPainAction : public CastDebuffSpellAction
	{
    public:
	    CastPowerWordPainAction(PlayerbotAI* ai) : CastDebuffSpellAction(ai, "shadow word: pain") {}
	};

	class CastPowerWordPainOnAttackerAction : public CastDebuffSpellOnAttackerAction
	{
    public:
	    CastPowerWordPainOnAttackerAction(PlayerbotAI* ai) : CastDebuffSpellOnAttackerAction(ai, "shadow word: pain") {}
	};

    BEGIN_DEBUFF_ACTION(CastDevouringPlagueAction, "devouring plague")
    END_SPELL_ACTION()

    BEGIN_DEBUFF_ACTION(CastVampiricTouchAction, "vampiric touch")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastMindBlastAction, "mind blast")
    END_SPELL_ACTION()

    BEGIN_RANGED_SPELL_ACTION(CastMindFlayAction, "mind flay")
    END_SPELL_ACTION()

	class CastCureDiseaseAction : public CastCureSpellAction {
	public:
		CastCureDiseaseAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "cure disease") {}
	};

    class CastCureDiseaseOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastCureDiseaseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "cure disease", DISPEL_DISEASE) {}
        virtual string getName() { return "cure disease on party"; }
    };

	class CastAbolishDiseaseAction : public CastCureSpellAction {
	public:
		CastAbolishDiseaseAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "abolish disease") {}
		virtual NextAction** getAlternatives();
	};

    class CastAbolishDiseaseOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastAbolishDiseaseOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "abolish disease", DISPEL_DISEASE) {}
        virtual string getName() { return "abolish disease on party"; }
        virtual NextAction** getAlternatives();
    };

	class CastDispelMagicAction : public CastCureSpellAction {
	public:
		CastDispelMagicAction(PlayerbotAI* ai) : CastCureSpellAction(ai, "dispel magic") {}
	};

    class CastDispelMagicOnTargetAction : public CastSpellAction {
    public:
        CastDispelMagicOnTargetAction(PlayerbotAI* ai) : CastSpellAction(ai, "dispel magic") {}
    };

    class CastDispelMagicOnPartyAction : public CurePartyMemberAction
    {
    public:
        CastDispelMagicOnPartyAction(PlayerbotAI* ai) : CurePartyMemberAction(ai, "dispel magic", DISPEL_MAGIC) {}
        virtual string getName() { return "dispel magic on party"; }
    };

	class CastResurrectionAction : public ResurrectPartyMemberAction
	{
	public:
		CastResurrectionAction(PlayerbotAI* ai) : ResurrectPartyMemberAction(ai, "resurrection") {}
	};

	class CastCircleOfHealingAction : public CastAoeHealSpellAction
	{
	public:
		CastCircleOfHealingAction(PlayerbotAI* ai) : CastAoeHealSpellAction(ai, "circle of healing") {}
	};

	class CastPsychicScreamAction : public CastSpellAction
	{
	public:
	    CastPsychicScreamAction(PlayerbotAI* ai) : CastSpellAction(ai, "psychic scream") {}
	};

	class CastDispersionAction : public CastSpellAction
	{
	public:
	    CastDispersionAction(PlayerbotAI* ai) : CastSpellAction(ai, "dispersion") {}
	    virtual string GetTargetName() { return "self target"; }
	};

}
