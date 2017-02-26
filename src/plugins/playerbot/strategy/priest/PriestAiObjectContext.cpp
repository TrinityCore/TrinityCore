#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PriestActions.h"
#include "PriestAiObjectContext.h"
#include "PriestNonCombatStrategy.h"
#include "ShadowPriestStrategy.h"
#include "../generic/PullStrategy.h"
#include "PriestTriggers.h"
#include "../NamedObjectContext.h"
#include "HolyPriestStrategy.h"

using namespace ai;


namespace ai
{
    namespace priest
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["nc"] = &priest::StrategyFactoryInternal::nc;
                creators["pull"] = &priest::StrategyFactoryInternal::pull;
                creators["aoe"] = &priest::StrategyFactoryInternal::shadow_aoe;
                creators["shadow aoe"] = &priest::StrategyFactoryInternal::shadow_aoe;
                creators["dps debuff"] = &priest::StrategyFactoryInternal::shadow_debuff;
                creators["shadow debuff"] = &priest::StrategyFactoryInternal::shadow_debuff;
            }

        private:
            static Strategy* nc(PlayerbotAI* ai) { return new PriestNonCombatStrategy(ai); }
            static Strategy* shadow_aoe(PlayerbotAI* ai) { return new ShadowPriestAoeStrategy(ai); }
            static Strategy* pull(PlayerbotAI* ai) { return new PullStrategy(ai, "shoot"); }
            static Strategy* shadow_debuff(PlayerbotAI* ai) { return new ShadowPriestDebuffStrategy(ai); }
        };

        class CombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            CombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["heal"] = &priest::CombatStrategyFactoryInternal::heal;
                creators["shadow"] = &priest::CombatStrategyFactoryInternal::dps;
                creators["dps"] = &priest::CombatStrategyFactoryInternal::dps;
                creators["holy"] = &priest::CombatStrategyFactoryInternal::holy;
            }

        private:
            static Strategy* heal(PlayerbotAI* ai) { return new HealPriestStrategy(ai); }
            static Strategy* dps(PlayerbotAI* ai) { return new ShadowPriestStrategy(ai); }
            static Strategy* holy(PlayerbotAI* ai) { return new HolyPriestStrategy(ai); }
        };
    };
};

namespace ai
{
    namespace priest
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()
            {
                creators["devouring plague"] = &TriggerFactoryInternal::devouring_plague;
                creators["shadow word: pain"] = &TriggerFactoryInternal::shadow_word_pain;
                creators["shadow word: pain on attacker"] = &TriggerFactoryInternal::shadow_word_pain_on_attacker;
                creators["dispel magic"] = &TriggerFactoryInternal::dispel_magic;
                creators["dispel magic on party"] = &TriggerFactoryInternal::dispel_magic_party_member;
                creators["cure disease"] = &TriggerFactoryInternal::cure_disease;
                creators["party member cure disease"] = &TriggerFactoryInternal::party_member_cure_disease;
                creators["power word: fortitude"] = &TriggerFactoryInternal::power_word_fortitude;
                creators["power word: fortitude on party"] = &TriggerFactoryInternal::power_word_fortitude_on_party;
                creators["divine spirit"] = &TriggerFactoryInternal::divine_spirit;
                creators["divine spirit on party"] = &TriggerFactoryInternal::divine_spirit_on_party;
                creators["inner fire"] = &TriggerFactoryInternal::inner_fire;
                creators["vampiric touch"] = &TriggerFactoryInternal::vampiric_touch;
                creators["shadowform"] = &TriggerFactoryInternal::shadowform;
                creators["vampiric embrace"] = &TriggerFactoryInternal::vampiric_embrace;

            }

        private:
            static Trigger* vampiric_embrace(PlayerbotAI* ai) { return new VampiricEmbraceTrigger(ai); }
            static Trigger* shadowform(PlayerbotAI* ai) { return new ShadowformTrigger(ai); }
            static Trigger* vampiric_touch(PlayerbotAI* ai) { return new VampiricTouchTrigger(ai); }
            static Trigger* devouring_plague(PlayerbotAI* ai) { return new DevouringPlagueTrigger(ai); }
            static Trigger* shadow_word_pain(PlayerbotAI* ai) { return new PowerWordPainTrigger(ai); }
            static Trigger* shadow_word_pain_on_attacker(PlayerbotAI* ai) { return new PowerWordPainOnAttackerTrigger(ai); }
            static Trigger* dispel_magic(PlayerbotAI* ai) { return new DispelMagicTrigger(ai); }
            static Trigger* dispel_magic_party_member(PlayerbotAI* ai) { return new DispelMagicPartyMemberTrigger(ai); }
            static Trigger* cure_disease(PlayerbotAI* ai) { return new CureDiseaseTrigger(ai); }
            static Trigger* party_member_cure_disease(PlayerbotAI* ai) { return new PartyMemberCureDiseaseTrigger(ai); }
            static Trigger* power_word_fortitude(PlayerbotAI* ai) { return new PowerWordFortitudeTrigger(ai); }
            static Trigger* power_word_fortitude_on_party(PlayerbotAI* ai) { return new PowerWordFortitudeOnPartyTrigger(ai); }
            static Trigger* divine_spirit(PlayerbotAI* ai) { return new DivineSpiritTrigger(ai); }
            static Trigger* divine_spirit_on_party(PlayerbotAI* ai) { return new DivineSpiritOnPartyTrigger(ai); }
            static Trigger* inner_fire(PlayerbotAI* ai) { return new InnerFireTrigger(ai); }
        };
    };
};



namespace ai
{
    namespace priest
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
                creators["shadow word: pain"] = &AiObjectContextInternal::shadow_word_pain;
                creators["shadow word: pain on attacker"] = &AiObjectContextInternal::shadow_word_pain_on_attacker;
                creators["devouring plague"] = &AiObjectContextInternal::devouring_plague;
                creators["mind flay"] = &AiObjectContextInternal::mind_flay;
                creators["holy fire"] = &AiObjectContextInternal::holy_fire;
                creators["smite"] = &AiObjectContextInternal::smite;
                creators["mind blast"] = &AiObjectContextInternal::mind_blast;
                creators["shadowform"] = &AiObjectContextInternal::shadowform;
                creators["remove shadowform"] = &AiObjectContextInternal::remove_shadowform;
                creators["holy nova"] = &AiObjectContextInternal::holy_nova;
                creators["power word: fortitude"] = &AiObjectContextInternal::power_word_fortitude;
                creators["power word: fortitude on party"] = &AiObjectContextInternal::power_word_fortitude_on_party;
                creators["divine spirit"] = &AiObjectContextInternal::divine_spirit;
                creators["divine spirit on party"] = &AiObjectContextInternal::divine_spirit_on_party;
                creators["power word: shield"] = &AiObjectContextInternal::power_word_shield;
                creators["power word: shield on party"] = &AiObjectContextInternal::power_word_shield_on_party;
                creators["renew"] = &AiObjectContextInternal::renew;
                creators["renew on party"] = &AiObjectContextInternal::renew_on_party;
                creators["greater heal"] = &AiObjectContextInternal::greater_heal;
                creators["greater heal on party"] = &AiObjectContextInternal::greater_heal_on_party;
                creators["heal"] = &AiObjectContextInternal::heal;
                creators["heal on party"] = &AiObjectContextInternal::heal_on_party;
                creators["lesser heal"] = &AiObjectContextInternal::lesser_heal;
                creators["lesser heal on party"] = &AiObjectContextInternal::lesser_heal_on_party;
                creators["flash heal"] = &AiObjectContextInternal::flash_heal;
                creators["flash heal on party"] = &AiObjectContextInternal::flash_heal_on_party;
                creators["dispel magic"] = &AiObjectContextInternal::dispel_magic;
                creators["dispel magic on party"] = &AiObjectContextInternal::dispel_magic_on_party;
                creators["dispel magic on target"] = &AiObjectContextInternal::dispel_magic_on_target;
                creators["cure disease"] = &AiObjectContextInternal::cure_disease;
                creators["cure disease on party"] = &AiObjectContextInternal::cure_disease_on_party;
                creators["abolish disease"] = &AiObjectContextInternal::abolish_disease;
                creators["abolish disease on party"] = &AiObjectContextInternal::abolish_disease_on_party;
                creators["fade"] = &AiObjectContextInternal::fade;
                creators["inner fire"] = &AiObjectContextInternal::inner_fire;
                creators["resurrection"] = &AiObjectContextInternal::resurrection;
                creators["circle of healing"] = &AiObjectContextInternal::circle_of_healing;
                creators["psychic scream"] = &AiObjectContextInternal::psychic_scream;
                creators["vampiric touch"] = &AiObjectContextInternal::vampiric_touch;
                creators["vampiric embrace"] = &AiObjectContextInternal::vampiric_embrace;
                creators["dispersion"] = &AiObjectContextInternal::dispersion;
            }

        private:
            static Action* dispersion(PlayerbotAI* ai) { return new CastDispersionAction(ai); }
            static Action* vampiric_embrace(PlayerbotAI* ai) { return new CastVampiricEmbraceAction(ai); }
            static Action* vampiric_touch(PlayerbotAI* ai) { return new CastVampiricTouchAction(ai); }
            static Action* psychic_scream(PlayerbotAI* ai) { return new CastPsychicScreamAction(ai); }
            static Action* circle_of_healing(PlayerbotAI* ai) { return new CastCircleOfHealingAction(ai); }
            static Action* resurrection(PlayerbotAI* ai) { return new CastResurrectionAction(ai); }
            static Action* shadow_word_pain(PlayerbotAI* ai) { return new CastPowerWordPainAction(ai); }
            static Action* shadow_word_pain_on_attacker(PlayerbotAI* ai) { return new CastPowerWordPainOnAttackerAction(ai); }
            static Action* devouring_plague(PlayerbotAI* ai) { return new CastDevouringPlagueAction(ai); }
            static Action* mind_flay(PlayerbotAI* ai) { return new CastMindFlayAction(ai); }
            static Action* holy_fire(PlayerbotAI* ai) { return new CastHolyFireAction(ai); }
            static Action* smite(PlayerbotAI* ai) { return new CastSmiteAction(ai); }
            static Action* mind_blast(PlayerbotAI* ai) { return new CastMindBlastAction(ai); }
            static Action* shadowform(PlayerbotAI* ai) { return new CastShadowformAction(ai); }
            static Action* remove_shadowform(PlayerbotAI* ai) { return new CastRemoveShadowformAction(ai); }
            static Action* holy_nova(PlayerbotAI* ai) { return new CastHolyNovaAction(ai); }
            static Action* power_word_fortitude(PlayerbotAI* ai) { return new CastPowerWordFortitudeAction(ai); }
            static Action* power_word_fortitude_on_party(PlayerbotAI* ai) { return new CastPowerWordFortitudeOnPartyAction(ai); }
            static Action* divine_spirit(PlayerbotAI* ai) { return new CastDivineSpiritAction(ai); }
            static Action* divine_spirit_on_party(PlayerbotAI* ai) { return new CastDivineSpiritOnPartyAction(ai); }
            static Action* power_word_shield(PlayerbotAI* ai) { return new CastPowerWordShieldAction(ai); }
            static Action* power_word_shield_on_party(PlayerbotAI* ai) { return new CastPowerWordShieldOnPartyAction(ai); }
            static Action* renew(PlayerbotAI* ai) { return new CastRenewAction(ai); }
            static Action* renew_on_party(PlayerbotAI* ai) { return new CastRenewOnPartyAction(ai); }
            static Action* greater_heal(PlayerbotAI* ai) { return new CastGreaterHealAction(ai); }
            static Action* greater_heal_on_party(PlayerbotAI* ai) { return new CastGreaterHealOnPartyAction(ai); }
            static Action* heal(PlayerbotAI* ai) { return new CastHealAction(ai); }
            static Action* heal_on_party(PlayerbotAI* ai) { return new CastHealOnPartyAction(ai); }
            static Action* lesser_heal(PlayerbotAI* ai) { return new CastLesserHealAction(ai); }
            static Action* lesser_heal_on_party(PlayerbotAI* ai) { return new CastLesserHealOnPartyAction(ai); }
            static Action* flash_heal(PlayerbotAI* ai) { return new CastFlashHealAction(ai); }
            static Action* flash_heal_on_party(PlayerbotAI* ai) { return new CastFlashHealOnPartyAction(ai); }
            static Action* dispel_magic(PlayerbotAI* ai) { return new CastDispelMagicAction(ai); }
            static Action* dispel_magic_on_party(PlayerbotAI* ai) { return new CastDispelMagicOnPartyAction(ai); }
            static Action* dispel_magic_on_target(PlayerbotAI* ai) { return new CastDispelMagicOnTargetAction(ai); }
            static Action* cure_disease(PlayerbotAI* ai) { return new CastCureDiseaseAction(ai); }
            static Action* cure_disease_on_party(PlayerbotAI* ai) { return new CastCureDiseaseOnPartyAction(ai); }
            static Action* abolish_disease(PlayerbotAI* ai) { return new CastAbolishDiseaseAction(ai); }
            static Action* abolish_disease_on_party(PlayerbotAI* ai) { return new CastAbolishDiseaseOnPartyAction(ai); }
            static Action* fade(PlayerbotAI* ai) { return new CastFadeAction(ai); }
            static Action* inner_fire(PlayerbotAI* ai) { return new CastInnerFireAction(ai); }
        };
    };
};

PriestAiObjectContext::PriestAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::priest::StrategyFactoryInternal());
    strategyContexts.Add(new ai::priest::CombatStrategyFactoryInternal());
    actionContexts.Add(new ai::priest::AiObjectContextInternal());
    triggerContexts.Add(new ai::priest::TriggerFactoryInternal());
}
