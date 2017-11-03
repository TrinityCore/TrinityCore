#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "../Strategy.h"
#include "DKActions.h"
#include "DKAiObjectContext.h"
#include "FrostDKStrategy.h"
#include "BloodDKStrategy.h"
#include "GenericDKNonCombatStrategy.h"
#include "UnholyDKStrategy.h"
#include "../generic/PullStrategy.h"
#include "DKTriggers.h"
#include "../NamedObjectContext.h"

using namespace ai;


namespace ai
{
    namespace DK
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["nc"] = &DK::StrategyFactoryInternal::nc;
                creators["pull"] = &DK::StrategyFactoryInternal::pull;
				creators["frost aoe"] = &DK::StrategyFactoryInternal::frost_aoe;
				creators["unholy aoe"] = &DK::StrategyFactoryInternal::unholy_aoe;
            }

        private:
            static Strategy* nc(PlayerbotAI* ai) { return new GenericDKNonCombatStrategy(ai); }
            static Strategy* pull(PlayerbotAI* ai) { return new PullStrategy(ai, "icy touch"); }
			static Strategy* frost_aoe(PlayerbotAI* ai) { return new FrostDKAoeStrategy(ai); }
			static Strategy* unholy_aoe(PlayerbotAI* ai) { return new UnholyDKAoeStrategy(ai); }
        };

        class CombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
			CombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["tank"] = &DK::CombatStrategyFactoryInternal::blood;
				creators["blood"] = &DK::CombatStrategyFactoryInternal::blood;
                creators["frost"] = &DK::CombatStrategyFactoryInternal::frost_dps;
				creators["unholy"] = &DK::CombatStrategyFactoryInternal::unholy_dps;
            }

        private:
            static Strategy* frost_dps(PlayerbotAI* ai) { return new FrostDKStrategy(ai); }
            static Strategy* unholy_dps(PlayerbotAI* ai) { return new UnholyDKStrategy(ai); }
            static Strategy* tank(PlayerbotAI* ai) { return new BloodDKStrategy(ai); }
			static Strategy* blood(PlayerbotAI* ai) { return new BloodDKStrategy(ai); }
        };

        class DKBuffStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            DKBuffStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                
                creators["bdps"] = &DK::DKBuffStrategyFactoryInternal::bdps;
            }

        private:
            static Strategy* bdps(PlayerbotAI* ai) { return new DKBuffDpsStrategy(ai); }
        };
    };
};


namespace ai
{
    namespace DK
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()  
            {
                creators["bone shield"] = &TriggerFactoryInternal::bone_shield;
                creators["pestilence"] = &TriggerFactoryInternal::pestilence;
                creators["blood strike"] = &TriggerFactoryInternal::blood_strike;
				creators["plague strike"] = &TriggerFactoryInternal::plague_strike;
				creators["plague strike on attacker"] = &TriggerFactoryInternal::plague_strike_on_attacker;
                creators["icy touch"] = &TriggerFactoryInternal::icy_touch;
				creators["death coil"] = &TriggerFactoryInternal::death_coil;
				creators["icy touch on attacker"] = &TriggerFactoryInternal::icy_touch_on_attacker;
                creators["improved icy talons"] = &TriggerFactoryInternal::improved_icy_talons;
                creators["plague strike"] = &TriggerFactoryInternal::plague_strike;
                creators["horn of winter"] = &TriggerFactoryInternal::horn_of_winter;
                creators["mind freeze"] = &TriggerFactoryInternal::mind_freeze;
                creators["mind freeze on enemy healer"] = &TriggerFactoryInternal::mind_freeze_on_enemy_healer;
				creators["strangulate"] = &TriggerFactoryInternal::strangulate;
				creators["strangulate on enemy healer"] = &TriggerFactoryInternal::strangulate_on_enemy_healer;
				creators["blood tap"] = &TriggerFactoryInternal::blood_tap;
				creators["raise dead"] = &TriggerFactoryInternal::raise_dead;
				creators["chains of ice"] = &TriggerFactoryInternal::chains_of_ice;
            }

        private:
            static Trigger* bone_shield(PlayerbotAI* ai) { return new BoneShieldTrigger(ai); }
            static Trigger* pestilence(PlayerbotAI* ai) { return new PestilenceTrigger(ai); }
            static Trigger* blood_strike(PlayerbotAI* ai) { return new BloodStrikeTrigger(ai); }
			static Trigger* plague_strike(PlayerbotAI* ai) { return new PlagueStrikeDebuffTrigger(ai); }
			static Trigger* plague_strike_on_attacker(PlayerbotAI* ai) { return new PlagueStrikeDebuffOnAttackerTrigger(ai); }
            static Trigger* icy_touch(PlayerbotAI* ai) { return new IcyTouchDebuffTrigger(ai); }
			static Trigger* death_coil(PlayerbotAI* ai) { return new DeathCoilTrigger(ai); }
			static Trigger* icy_touch_on_attacker(PlayerbotAI* ai) { return new IcyTouchDebuffOnAttackerTrigger(ai); }
            static Trigger* improved_icy_talons(PlayerbotAI* ai) { return new ImprovedIcyTalonsTrigger(ai); }
            static Trigger* horn_of_winter(PlayerbotAI* ai) { return new HornOfWinterTrigger(ai); }
            static Trigger* mind_freeze(PlayerbotAI* ai) { return new MindFreezeInterruptSpellTrigger(ai); }
            static Trigger* mind_freeze_on_enemy_healer(PlayerbotAI* ai) { return new MindFreezeOnEnemyHealerTrigger(ai); }
			static Trigger* strangulate(PlayerbotAI* ai) { return new StrangulateInterruptSpellTrigger(ai); }
			static Trigger* strangulate_on_enemy_healer(PlayerbotAI* ai) { return new StrangulateOnEnemyHealerTrigger(ai); }
			static Trigger* blood_tap(PlayerbotAI* ai) { return new BloodTapTrigger(ai); }
			static Trigger* raise_dead(PlayerbotAI* ai) { return new RaiseDeadTrigger(ai); }
			static Trigger* chains_of_ice(PlayerbotAI* ai) { return new ChainsOfIceSnareTrigger(ai); }


		};
    };
};


namespace ai
{
    namespace DK
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
                
				// Unholy
				creators["bone shield"] = &AiObjectContextInternal::bone_shield;
				creators["plague strike"] = &AiObjectContextInternal::plague_strike;
				creators["plague strike on attacker"] = &AiObjectContextInternal::plague_strike_on_attacker;
				creators["death grip"] = &AiObjectContextInternal::death_grip;
				creators["death coil"] = &AiObjectContextInternal::death_coil;
				creators["death strike"] = &AiObjectContextInternal::death_strike;
				creators["unholy blight"] = &AiObjectContextInternal::unholy_blight;
				creators["scourge strike"] = &AiObjectContextInternal::scourge_strike;
				creators["death and decay"] = &AiObjectContextInternal::death_and_decay;
				creators["unholy pressence"] = &AiObjectContextInternal::unholy_pressence;
				creators["raise dead"] = &AiObjectContextInternal::raise_dead;
				creators["army of the dead"] = &AiObjectContextInternal::army_of_the_dead;
				creators["summon gargoyle"] = &AiObjectContextInternal::summon_gargoyle;
				creators["anti magic shell"] = &AiObjectContextInternal::anti_magic_shell;
				creators["anti magic zone"] = &AiObjectContextInternal::anti_magic_zone;
				creators["ghoul frenzy"] = &AiObjectContextInternal::ghoul_frenzy;
				creators["corpse explosion"] = &AiObjectContextInternal::corpse_explosion;
				// Frost
				creators["icy touch"] = &AiObjectContextInternal::icy_touch;
				creators["icy touch on attacker"] = &AiObjectContextInternal::icy_touch_on_attacker;
				creators["obliterate"] = &AiObjectContextInternal::obliterate;
				creators["howling blast"] = &AiObjectContextInternal::howling_blast;
				creators["frost strike"] = &AiObjectContextInternal::frost_strike;
				creators["chains of ice"] = &AiObjectContextInternal::chains_of_ice;
				creators["rune strike"] = &AiObjectContextInternal::rune_strike;
				//creators["icy clutch"] = &AiObjectContextInternal::icy_clutch;
				creators["horn of winter"] = &AiObjectContextInternal::horn_of_winter;
				creators["killing machine"] = &AiObjectContextInternal::killing_machine;
				creators["frost presence"] = &AiObjectContextInternal::frost_presence;
				creators["deathchill"] = &AiObjectContextInternal::deathchill;
				creators["icebound fortitude"] = &AiObjectContextInternal::icebound_fortitude;
				creators["mind freeze"] = &AiObjectContextInternal::mind_freeze;
				creators["empower rune weapon"] = &AiObjectContextInternal::empower_rune_weapon;
				creators["hungering cold"] = &AiObjectContextInternal::hungering_cold;
				creators["unbreakable armor"] = &AiObjectContextInternal::unbreakable_armor;
				creators["improved icy talons"] = &AiObjectContextInternal::improved_icy_talons;
				// blood
				creators["blood strike"] = &AiObjectContextInternal::blood_strike;
				creators["blood tap"] = &AiObjectContextInternal::blood_tap;
				creators["pestilence"] = &AiObjectContextInternal::pestilence;
				creators["strangulate"] = &AiObjectContextInternal::strangulate;
				creators["blood boil"] = &AiObjectContextInternal::blood_boil;
				creators["heart strike"] = &AiObjectContextInternal::heart_strike;
				creators["mark of_blood"] = &AiObjectContextInternal::mark_of_blood;
				creators["blood presence"] = &AiObjectContextInternal::blood_presence;
				creators["rune tap"] = &AiObjectContextInternal::rune_tap;
				creators["vampiric blood"] = &AiObjectContextInternal::vampiric_blood;
				creators["death pact"] = &AiObjectContextInternal::death_pact;
				creators["death rune_mastery"] = &AiObjectContextInternal::death_rune_mastery;
				//creators["hysteria"] = &AiObjectContextInternal::hysteria;
				creators["dancing weapon"] = &AiObjectContextInternal::dancing_weapon;
				creators["dark command"] = &AiObjectContextInternal::dark_command;
            }

        private:
            
			// Unholy
			static Action* bone_shield(PlayerbotAI* ai) { return new CastBoneShieldAction(ai); }
			static Action* plague_strike(PlayerbotAI* ai) { return new CastPlagueStrikeAction(ai); }
			static Action* plague_strike_on_attacker(PlayerbotAI* ai) { return new CastPlagueStrikeOnAttackerAction(ai); }
			static Action* death_grip(PlayerbotAI* ai) { return new CastDeathGripAction(ai); }
			static Action* death_coil(PlayerbotAI* ai) { return new CastDeathCoilAction(ai); }
			static Action* death_strike(PlayerbotAI* ai) { return new CastDeathStrikeAction(ai); }
			static Action* unholy_blight(PlayerbotAI* ai) { return new CastUnholyBlightAction(ai); }
			static Action* scourge_strike(PlayerbotAI* ai) { return new CastScourgeStrikeAction(ai); }
			static Action* death_and_decay(PlayerbotAI* ai) { return new CastDeathAndDecayAction(ai); }
			static Action* unholy_pressence(PlayerbotAI* ai) { return new CastUnholyPresenceAction(ai); }
			static Action* raise_dead(PlayerbotAI* ai) { return new CastRaiseDeadAction(ai); }
			static Action* army_of_the_dead(PlayerbotAI* ai) { return new CastArmyOfTheDeadAction(ai); }
			static Action* summon_gargoyle(PlayerbotAI* ai) { return new CastSummonGargoyleAction(ai); }
			static Action* anti_magic_shell(PlayerbotAI* ai) { return new CastAntiMagicShellAction(ai); }
			static Action* anti_magic_zone(PlayerbotAI* ai) { return new CastAntiMagicZoneAction(ai); }
			static Action* ghoul_frenzy(PlayerbotAI* ai) { return new CastGhoulFrenzyAction(ai); }
			static Action* corpse_explosion(PlayerbotAI* ai) { return new CastCorpseExplosionAction(ai); }
			// Frost
			static Action* icy_touch(PlayerbotAI* ai) { return new CastIcyTouchAction(ai); }
			static Action* icy_touch_on_attacker(PlayerbotAI* ai) { return new CastIcyTouchOnAttackerAction(ai); }
			static Action* obliterate(PlayerbotAI* ai) { return new CastObliterateAction(ai); }
			static Action* howling_blast(PlayerbotAI* ai) { return new CastHowlingBlastAction(ai); }
			static Action* frost_strike(PlayerbotAI* ai) { return new CastFrostStrikeAction(ai); }
			static Action* chains_of_ice(PlayerbotAI* ai) { return new CastChainsOfIceAction(ai); }
			static Action* rune_strike(PlayerbotAI* ai) { return new CastRuneStrikeAction(ai); }
			//static Action* icy_clutch(PlayerbotAI* ai) { return new CastIcyClutchAction(ai); }
			static Action* horn_of_winter(PlayerbotAI* ai) { return new CastHornOfWinterAction(ai); }
			static Action* killing_machine(PlayerbotAI* ai) { return new CastKillingMachineAction(ai); }
			static Action* frost_presence(PlayerbotAI* ai) { return new CastFrostPresenceAction(ai); }
			static Action* deathchill(PlayerbotAI* ai) { return new CastDeathchillAction(ai); }
			static Action* icebound_fortitude(PlayerbotAI* ai) { return new CastIceboundFortitudeAction(ai); }
			static Action* mind_freeze(PlayerbotAI* ai) { return new CastMindFreezeAction(ai); }
			static Action* empower_rune_weapon(PlayerbotAI* ai) { return new CastEmpowerRuneWeaponAction(ai); }
			static Action* hungering_cold(PlayerbotAI* ai) { return new CastHungeringColdAction(ai); }
			static Action* unbreakable_armor(PlayerbotAI* ai) { return new CastUnbreakableArmorAction(ai); }
			static Action* improved_icy_talons(PlayerbotAI* ai) { return new CastImprovedIcyTalonsAction(ai); }
			// blood
			static Action* blood_strike(PlayerbotAI* ai) { return new CastBloodStrikeAction(ai); }
			static Action* blood_tap(PlayerbotAI* ai) { return new CastBloodTapAction(ai); }
			static Action* pestilence(PlayerbotAI* ai) { return new CastPestilenceAction(ai); }
			static Action* strangulate(PlayerbotAI* ai) { return new CastStrangulateAction(ai); }
			static Action* blood_boil(PlayerbotAI* ai) { return new CastBloodBoilAction(ai); }
			static Action* heart_strike(PlayerbotAI* ai) { return new CastHeartStrikeAction(ai); }
			static Action* mark_of_blood(PlayerbotAI* ai) { return new CastMarkOfBloodAction(ai); }
			static Action* blood_presence(PlayerbotAI* ai) { return new CastBloodPresenceAction(ai); }
			static Action* rune_tap(PlayerbotAI* ai) { return new CastRuneTapAction(ai); }
			static Action* vampiric_blood(PlayerbotAI* ai) { return new CastVampiricBloodAction(ai); }
			static Action* death_pact(PlayerbotAI* ai) { return new CastDeathPactAction(ai); }
			static Action* death_rune_mastery(PlayerbotAI* ai) { return new CastDeathRuneMasteryAction(ai); }
			//static Action* hysteria(PlayerbotAI* ai) { return new CastHysteriaAction(ai); }
			static Action* dancing_weapon(PlayerbotAI* ai) { return new CastDancingWeaponAction(ai); }
			static Action* dark_command(PlayerbotAI* ai) { return new CastDarkCommandAction(ai); }
            static Action* mind_freeze_on_enemy_healer(PlayerbotAI* ai) { return new CastMindFreezeOnEnemyHealerAction(ai); }
			
        };
    };
};



DKAiObjectContext::DKAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::DK::StrategyFactoryInternal());
    strategyContexts.Add(new ai::DK::CombatStrategyFactoryInternal());
    strategyContexts.Add(new ai::DK::DKBuffStrategyFactoryInternal());
    actionContexts.Add(new ai::DK::AiObjectContextInternal());
    triggerContexts.Add(new ai::DK::TriggerFactoryInternal());
}
