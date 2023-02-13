#include "botpch.h"
#include "../../playerbot.h"
#include "WarriorActions.h"
#include "WarriorAiObjectContext.h"
#include "GenericWarriorNonCombatStrategy.h"
#include "TankWarriorStrategy.h"
#include "ArmsWarriorStrategy.h"
#include "FuryWarriorStrategy.h"
#include "../generic/PullStrategy.h"
#include "WarriorTriggers.h"
#include "../NamedObjectContext.h"

using namespace ai;


namespace ai
{
    namespace warrior
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["nc"] = &warrior::StrategyFactoryInternal::nc;
                creators["pull"] = &warrior::StrategyFactoryInternal::pull;
                creators["tank aoe"] = &warrior::StrategyFactoryInternal::tank_aoe;
                creators["fury aoe"] = &warrior::StrategyFactoryInternal::fury_aoe;
                creators["arms aoe"] = &warrior::StrategyFactoryInternal::arms_aoe;
            }

        private:
            static Strategy* nc(PlayerbotAI* ai) { return new GenericWarriorNonCombatStrategy(ai); }
            static Strategy* tank_aoe(PlayerbotAI* ai) { return new TankWarriorAoeStrategy(ai); }
            static Strategy* arms_aoe(PlayerbotAI* ai) { return new ArmsWarriorAoeStrategy(ai); }
            static Strategy* fury_aoe(PlayerbotAI* ai) { return new FuryWarriorAoeStrategy(ai); }
            static Strategy* pull(PlayerbotAI* ai) { return new PullStrategy(ai, "shoot"); }
        };

        class CombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            CombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["tank"] = &warrior::CombatStrategyFactoryInternal::tank;
                creators["arms dps"] = &warrior::CombatStrategyFactoryInternal::arms_dps;
                creators["fury dps"] = &warrior::CombatStrategyFactoryInternal::fury_dps;
            }

        private:
            static Strategy* tank(PlayerbotAI* ai) { return new TankWarriorStrategy(ai); }
            static Strategy* arms_dps(PlayerbotAI* ai) { return new ArmsWarriorStrategy(ai); }
            static Strategy* fury_dps(PlayerbotAI* ai) { return new FuryWarriorStrategy(ai); }
        };
    };
};

namespace ai
{
    namespace warrior
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()
            {
                creators["hamstring"] = &TriggerFactoryInternal::hamstring;
                creators["victory rush"] = &TriggerFactoryInternal::victory_rush;
                creators["death wish"] = &TriggerFactoryInternal::death_wish;
                creators["battle shout"] = &TriggerFactoryInternal::battle_shout;
                creators["rend"] = &TriggerFactoryInternal::rend;
                creators["rend on attacker"] = &TriggerFactoryInternal::rend_on_attacker;
                creators["bloodrage"] = &TriggerFactoryInternal::bloodrage;
                creators["shield bash"] = &TriggerFactoryInternal::shield_bash;
                creators["disarm"] = &TriggerFactoryInternal::disarm;
                creators["concussion blow"] = &TriggerFactoryInternal::concussion_blow;
                creators["shield bash on enemy healer"] = &TriggerFactoryInternal::shield_bash_on_enemy_healer;
                creators["rampage"] = &TriggerFactoryInternal::rampage;
                creators["pummel"] = &TriggerFactoryInternal::pummel;
                creators["pummel on enemy healer"] = &TriggerFactoryInternal::pummel_on_enemy_healer;
                creators["intercept"] = &TriggerFactoryInternal::intercept;

            }

        private:
            static Trigger* intercept(PlayerbotAI* ai) { return new WarriorCanInterceptTrigger(ai); }
            static Trigger* pummel_on_enemy_healer(PlayerbotAI* ai) { return new PummelInterruptEnemyHealerSpellTrigger(ai); }
            static Trigger* pummel(PlayerbotAI* ai) { return new PummelInterruptSpellTrigger(ai); }
            static Trigger* rampage(PlayerbotAI* ai) { return new RampageAvailableTrigger(ai); }
            static Trigger* hamstring(PlayerbotAI* ai) { return new HamstringTrigger(ai); }
            static Trigger* victory_rush(PlayerbotAI* ai) { return new VictoryRushTrigger(ai); }
            static Trigger* death_wish(PlayerbotAI* ai) { return new DeathWishTrigger(ai); }
            static Trigger* battle_shout(PlayerbotAI* ai) { return new BattleShoutTrigger(ai); }
            static Trigger* rend(PlayerbotAI* ai) { return new RendDebuffTrigger(ai); }
            static Trigger* rend_on_attacker(PlayerbotAI* ai) { return new RendDebuffOnAttackerTrigger(ai); }
            static Trigger* bloodrage(PlayerbotAI* ai) { return new BloodrageDebuffTrigger(ai); }
            static Trigger* shield_bash(PlayerbotAI* ai) { return new ShieldBashInterruptSpellTrigger(ai); }
            static Trigger* disarm(PlayerbotAI* ai) { return new DisarmDebuffTrigger(ai); }
            static Trigger* concussion_blow(PlayerbotAI* ai) { return new ConcussionBlowTrigger(ai); }
            static Trigger* shield_bash_on_enemy_healer(PlayerbotAI* ai) { return new ShieldBashInterruptEnemyHealerSpellTrigger(ai); }
        };
    };
};


namespace ai
{
    namespace warrior
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
            ///generic
                creators["heroic strike"] = &AiObjectContextInternal::heroic_strike;
                creators["overpower"] = &AiObjectContextInternal::overpower;
                creators["charge"] = &AiObjectContextInternal::charge;
                creators["intercept"] = &AiObjectContextInternal::intercept;
                creators["mocking blow"] = &AiObjectContextInternal::mocking_blow;
                creators["victory rush"] = &AiObjectContextInternal::victory_rush;
                creators["execute"] = &AiObjectContextInternal::execute;
                    //stances
                creators["defensive stance"] = &AiObjectContextInternal::defensive_stance;
                creators["battle stance"] = &AiObjectContextInternal::battle_stance;
                creators["berserker stance"] = &AiObjectContextInternal::berserker_stance;
                    //cd
                creators["last stand"] = &AiObjectContextInternal::last_stand;
                creators["retaliation"] = &AiObjectContextInternal::retaliation;
                    //buffs
                creators["bloodrage"] = &AiObjectContextInternal::bloodrage;
                creators["death wish"] = &AiObjectContextInternal::death_wish;
                creators["recklessness"] = &AiObjectContextInternal::recklessness;
                creators["berserker rage"] = &AiObjectContextInternal::berserker_rage;
                    //shouts
                creators["intimidating shout"] = &AiObjectContextInternal::intimidating_shout;
                creators["demoralizing shout"] = &AiObjectContextInternal::demoralizing_shout;
                creators["challenging shout"] = &AiObjectContextInternal::challenging_shout;
                creators["battle shout"] = &AiObjectContextInternal::battle_shout;
                    //debuff
                creators["rend on attacker"] = &AiObjectContextInternal::rend_on_attacker;
                creators["rend"] = &AiObjectContextInternal::rend;
                creators["hamstring"] = &AiObjectContextInternal::hamstring;
                    //aoe
                creators["thunder clap"] = &AiObjectContextInternal::thunder_clap;
                creators["cleave"] = &AiObjectContextInternal::cleave;
                creators["whirlwind"] = &AiObjectContextInternal::whirlwind;
                creators["sweeping strikes"] = &AiObjectContextInternal::sweeping_strike;
                    //interrupt
                creators["pummel"] = &AiObjectContextInternal::pummel;
                creators["concussion blow"] = &AiObjectContextInternal::concussion_blow;
            ///arms
                creators["slam"] = &AiObjectContextInternal::slam;
                creators["mortal strike"] = &AiObjectContextInternal::mortal_strike;
            ///fury
                creators["bloodthirst"] = &AiObjectContextInternal::bloodthirst;
                creators["rampage"] = &AiObjectContextInternal::rampage;
            ///defensive
                creators["devastate"] = &AiObjectContextInternal::devastate;
                creators["shield bash"] = &AiObjectContextInternal::shield_bash;
                creators["shield block"] = &AiObjectContextInternal::shield_block;
                creators["shield slam"] = &AiObjectContextInternal::shield_slam;
                creators["taunt"] = &AiObjectContextInternal::taunt;
                creators["revenge"] = &AiObjectContextInternal::revenge;
                    //debuff
                creators["disarm"] = &AiObjectContextInternal::disarm;
                creators["sunder armor"] = &AiObjectContextInternal::sunder_armor;
                    //cd
                creators["shield wall"] = &AiObjectContextInternal::shield_wall;
                creators["spell reflection"] = &AiObjectContextInternal::spell_reflection;
                    //interrupt
                creators["shield bash on enemy healer"] = &AiObjectContextInternal::shield_bash_on_enemy_healer;

            }

        private:

            static Action* heroic_strike(PlayerbotAI* ai) { return new CastHeroicStrikeAction(ai); }
            static Action* overpower(PlayerbotAI* ai) { return new CastOverpowerAction(ai); }
            static Action* charge(PlayerbotAI* ai) { return new CastChargeAction(ai); }
            static Action* intercept(PlayerbotAI* ai) { return new CastInterceptAction(ai); }
            static Action* mocking_blow(PlayerbotAI* ai) { return new CastMockingBlowAction(ai); }
            static Action* victory_rush(PlayerbotAI* ai) { return new CastVictoryRushAction(ai); }
            static Action* execute(PlayerbotAI* ai) { return new CastExecuteAction(ai); }

            static Action* defensive_stance(PlayerbotAI* ai) { return new CastDefensiveStanceAction(ai); }
            static Action* battle_stance(PlayerbotAI* ai) { return new CastBattleStanceAction(ai); }
            static Action* berserker_stance(PlayerbotAI* ai) { return new CastBerserkerStanceAction(ai); }

            static Action* last_stand(PlayerbotAI* ai) { return new CastLastStandAction(ai); }
            static Action* retaliation(PlayerbotAI* ai) { return new CastRetaliationAction(ai); }

            static Action* bloodrage(PlayerbotAI* ai) { return new CastBloodrageAction(ai); }
            static Action* death_wish(PlayerbotAI* ai) { return new CastDeathWishAction(ai); }
            static Action* recklessness(PlayerbotAI* ai) { return new CastRecklessnessAction(ai); }
            static Action* berserker_rage(PlayerbotAI* ai) { return new CastBerserkerRageAction(ai); }

            static Action* intimidating_shout(PlayerbotAI* ai) { return new CastIntimidatingShoutAction(ai); }
            static Action* demoralizing_shout(PlayerbotAI* ai) { return new CastDemoralizingShoutAction(ai); }
            static Action* challenging_shout(PlayerbotAI* ai) { return new CastChallengingShoutAction(ai); }
            static Action* battle_shout(PlayerbotAI* ai) { return new CastBattleShoutAction(ai); }

            static Action* rend(PlayerbotAI* ai) { return new CastRendAction(ai); }
            static Action* rend_on_attacker(PlayerbotAI* ai) { return new CastRendOnAttackerAction(ai); }
            static Action* hamstring(PlayerbotAI* ai) { return new CastHamstringAction(ai); }

            static Action* thunder_clap(PlayerbotAI* ai) { return new CastThunderClapAction(ai); }
            static Action* cleave(PlayerbotAI* ai) { return new CastCleaveAction(ai); }
            static Action* whirlwind(PlayerbotAI* ai) { return new CastWhirlwindAction(ai); }
            static Action* sweeping_strike(PlayerbotAI* ai) { return new CastSweepingStrikeAction(ai); }

            static Action* pummel(PlayerbotAI* ai) { return new CastPummelAction(ai); }
            static Action* concussion_blow(PlayerbotAI* ai) { return new CastConcussionBlowAction(ai); }

            static Action* slam(PlayerbotAI* ai) { return new CastSlamAction(ai); }
            static Action* mortal_strike(PlayerbotAI* ai) { return new CastMortalStrikeAction(ai); }

            static Action* bloodthirst(PlayerbotAI* ai) { return new CastBloodthirstAction(ai); }
            static Action* rampage(PlayerbotAI* ai) { return new CastRampageAction(ai); }

            static Action* devastate(PlayerbotAI* ai) { return new CastDevastateAction(ai); }
            static Action* shield_slam(PlayerbotAI* ai) { return new CastShieldSlamAction(ai); }
            static Action* shield_bash(PlayerbotAI* ai) { return new CastShieldBashAction(ai); }
            static Action* shield_block(PlayerbotAI* ai) { return new CastShieldBlockAction(ai); }
            static Action* taunt(PlayerbotAI* ai) { return new CastTauntAction(ai); }
            static Action* revenge(PlayerbotAI* ai) { return new CastRevengeAction(ai); }
            static Action* disarm(PlayerbotAI* ai) { return new CastDisarmAction(ai); }
            static Action* sunder_armor(PlayerbotAI* ai) { return new CastSunderArmorAction(ai); }
            static Action* spell_reflection(PlayerbotAI* ai) { return new CastSpellReflectionAction(ai); }
            static Action* shield_wall(PlayerbotAI* ai) { return new CastShieldWallAction(ai); }
            static Action* shield_bash_on_enemy_healer(PlayerbotAI* ai) { return new CastShieldBashOnEnemyHealerAction(ai); }

        };
    };
};

WarriorAiObjectContext::WarriorAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::warrior::StrategyFactoryInternal());
    strategyContexts.Add(new ai::warrior::CombatStrategyFactoryInternal());
    actionContexts.Add(new ai::warrior::AiObjectContextInternal());
    triggerContexts.Add(new ai::warrior::TriggerFactoryInternal());
}
