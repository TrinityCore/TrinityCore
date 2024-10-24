#include "bot_ai.h"
#include "bpet_ai.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "Player.h"
/*
Hunter NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Complete - 100%
TODO:
*/
//talent tiers 20-32-44-56-68-80
enum HunterPetBaseSpells
{
    //common
    GROWL_1                             = 2649,//1
    COWER_1                             = 1742,//20
    //semi-common
    //attack
    BITE_1                              = 17253,//1 cost 25, Bat, Boar, Carrion Bird, Chimaera, Core Hound, Crocolisk, Devilsaur, Dragonhawk, Hyena, Nether Ray, Ravager, Serpent, Wolf, Worm
    CLAW_1                              = 16827,//1 cost 25, Bear, Bird of Prey, Cat, Crab, Raptor, Scorpid, Silithid, Spirit Beast, Tallstrider
    SMACK_1                             = 49966,//1 cost 25, Gorilla, Sporebat, Moth, Rhino, Wasp
    //movement
    //charge
    SWOOP_1                             = 52825,//44 cost 35 Carrion Bird, Wasp, Teromoth
    CHARGE_1                            = 61685,//20/44 cost 35 Bear, Boar, Cat, Core Hound, Crab, Crocolisk, Devilsaur, Gorilla, Hyena, Raptor, Rhino, Scorpid, Spirit Beast, Tallstrider, Turtle, Warp Stalker, Wolf, Worm
    //sprint
    DASH_1                              = 61684,//20/44 cost 30 Cat, Core Hound, Devilsaur, Hyena, Raptor, Ravager, Serpent, Silithid, Spider, Spirit Beast, Tallstrider, Warp Stalker, Wolf
    DIVE_1                              = 23145,//20 cost 30 Bat, Bird of Prey, Carrion Bird, Chimaera, Dragonhawk, Moth, Nether Ray, Sporebat, Wasp, Wind Serpent
    //talents cunning
    CARRION_FEEDER_1                    = 54045,//44 triggered spell
    WOLVERINE_BITE_1                    = 53508,//68 after crit (any time for bot)
    ROAR_OF_RECOVERY_1                  = 53517,//68 mana regen
    BULLHEADED_1                        = 53490,//68 movement imparing remove
    //talents ferocity
    //HEART_OF_THE_PHOENIX_1              = 55709,
    RABID_1                             = 53401,//68 attack increase proc
    LICK_YOUR_WOUNDS_1                  = 53426,//68 full heal over 5, channeled
    CALL_OF_THE_WILD_1                  = 53434,//68 10% AP for pet and hunter
    //talents tenacity
    THUNDERSTOMP_1                      = 63900,//44
    LAST_STAND_1                        = 53478,//68 30%
    TAUNT_1                             = 53477,//68 3 min cd 126 sec improved
    ROAR_OF_SACRIFICE_1                 = 53480,//68
    INTERVENE_1                         = 53476,//68
    //pet-specific
    //cunning
    SONIC_BLAST_1                       = 50519,//bat c80 dmg/stun 20y cd60
    SNATCH_1                            = 50541,//birdop c20 dmg/disarm 5y cd60
    FROSTSTORM_BREATH_1                 = 54644,//chimera c20 dmg/slow 30y cd10
    FIRE_BREATH_1                       = 34889,//dhawk c20 dmg/dot 20y cd10
    NETHER_SHOCK_1                      = 50479,//nray c20 dmg/interrupt 20y cd40
    RAVAGE_1                            = 50518,//ravager c0 (bug?) dmg/stun 5y cd40
    POISON_SPIT_1                       = 35387,//serpent c20 dot/slowcast 30y cd10
    VENOM_WEB_SPRAY_1                   = 54706,//silithid c0 dot/root 30y cd40
    WEB_1                               = 4167,//spider c0 root 30y cd40
    SPORE_CLOUD_1                       = 50274,//sporebat c20 aoedot/-armorpct 6yd cd10
    LIGHTNING_BREATH_1                  = 24844,//wserpent c20 dmg 20y cd10
    //ferocity
    DEMORALIZING_SCREECH_1              = 24423,//cbird c20 dmg/aoe-ap 5y cd10
    PROWL_1                             = 24450,//cat,spbeast c0 stealth 0y cd10
    LAVA_BREATH_1                       = 58604,//chound c20 dmg/slowcast 30y cd10
    MONSTROUS_BITE_1                    = 54680,//dsaur c20 dmg/buff 5y cd10
    TENDON_RIP_1                        = 50271,//hyena c20 dmg/snare 5y cd20
    SERENITY_DUST_1                     = 50318,//tmoth c0 hot/buff+ap 0y cd60
    SAVAGE_REND_1                       = 50498,//raptor c20 dmg/dot 5y cd60
    SPIRIT_STRIKE_1                     = 61193,//spbeast c20 dmg/dot 30y cd10
    DUST_CLOUD_1                        = 50285,//tstrider c20 aoe-100hit 10y cd40 lvl6
    STING_1                             = 56626,//wasp c20 dmg/-5%armor 5y cd6
    FURIOUS_HOWL_1                      = 24604,//wolf c20 buff+ap 100y cd40
    //tenacity
    SWIPE_1                             = 50256,//bear c20 dmg 5y cd5
    GORE_1                              = 35290,//boar c20 dmg 5y cd10
    PIN_1                               = 50245,//crab c0 root/dot 5y cd40
    PUMMEL_1                            = 26090,//gorilla c20 interrupt 5y cd30
    STAMPEDE_1                          = 57386,//rhino c0 dmg/debuff+bleed 5y cd60
    SCORPID_POISON_1                    = 24640,//scorpid c20 threat/dot 5y cd10
    SHELL_SHIELD_1                      = 26064,//turtle c0 buff%dmgtaken 0y cd60
    WARP_1                              = 35346,//wstalker c0 tp/buff50%avoid 30y cd15
    ACID_SPIT_1                         = 55749,//worm c20 dmg/debuff-10%armor 30y cd10

    //from hunter's talents
    SPIRIT_BOND_PET                     = 24529,
    KINDRED_SPIRITS_PET                 = 57475,
    INTIMIDATION_1                      = 24394,
    BESTIAL_WRATH_1                     = 19574,
    BEAST_WITHIN_1                      = 34471
};

enum HunterPetPassives
{
    //common
    AVOIDANCE                           = 65220,
    //pet talents
    COBRA_REFLEXES                      = 61683,//rank 2
    //BOARS_SPEED                         = 19596,
    BLOOD_OF_THE_RHINO                  = 53482,//rank 2
    OWLS_FOCUS                          = 53516,//rank 2
    CULLING_THE_HERD                    = 52858,//rank 3
    GRACE_OF_THE_MANTIS                 = 53451,//rank 2
    CORNERED                            = 53497,//rank 2
    FEEDING_FRENZY                      = 53512,//rank 2
    SILVERBACK                          = 62765,//rank 2
    //special
    //Catlike Reflexes and Serpent's Swiftness replacement
    HASTE_DODGE_PASSIVE                 = 13789,//Lightning Reflexes rank 3 6 dodge 10 haste
};

enum HunterPetSpecial
{
    PET_CATEGORY_CUNNING                = 1,
    PET_CATEGORY_FEROCITY               = 2,
    PET_CATEGORY_TENACITY               = 3,

    GO_FOR_THE_THROAT_ENERGIZE          = 34953,
    FRENZY_BUFF                         = 19615,
    //HEART_OF_THE_PHOENIX_TRIGGERED      = 54114,//resurrect pet effect
    //HEART_OF_THE_PHOENIX_DEBUFF         = 55711 //Weakened Heart dummy eff 0 icon 2787
};

class hunter_pet_bot : public CreatureScript
{
public:
    hunter_pet_bot() : CreatureScript("hunter_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new hunter_botpetAI(creature);
    }

    struct hunter_botpetAI : public bot_pet_ai
    {
        hunter_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

        void JustEnteredCombat(Unit* u) override { bot_pet_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_pet_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_pet_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_pet_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { bot_pet_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_pet_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void DoPetActions(uint32 diff)
        {
            if (GetSpell(SPIRIT_BOND_PET) && IsSpellReady(SPIRIT_BOND_PET, diff, false) &&
                !petOwner->GetAuraEffect(SPELL_AURA_MOD_HEALING_PCT, SPELLFAMILY_GENERIC, 960, 1))
            {
                me->CastSpell(me, SPIRIT_BOND_PET, true);
                SetSpellCooldown(SPIRIT_BOND_PET, uint32(-1));
            }
            if (GetSpell(KINDRED_SPIRITS_PET) && IsSpellReady(KINDRED_SPIRITS_PET, diff, false) &&
                !petOwner->GetAuraEffect(SPELL_AURA_MOD_INCREASE_SPEED, SPELLFAMILY_GENERIC, 3559, 0))
            {
                me->CastSpell(me, KINDRED_SPIRITS_PET, true);
                SetSpellCooldown(KINDRED_SPIRITS_PET, uint32(-1));
            }

            //Ignoring pet category

            if (IsSpellReady(CARRION_FEEDER_1, diff, false) && !me->isMoving() && GetHealthPCT(me) <= 80 &&
                !me->IsInCombat() && !me->GetVictim() && me->getAttackers().empty() &&
                !me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && Rand() < 20)
            {
                WorldObject* result = nullptr;
                Trinity::AnyDeadUnitSpellTargetInRangeCheck check(me, 5.f, sSpellMgr->GetSpellInfo(CARRION_FEEDER_1), TARGET_CHECK_ENEMY);
                Trinity::WorldObjectSearcher<Trinity::AnyDeadUnitSpellTargetInRangeCheck> searcher(me, result, check);
                Cell::VisitWorldObjects(me, searcher, 5.f);

                if (result)
                {
                    me->CastSpell(me, GetSpell(CARRION_FEEDER_1), false);
                    SetSpellCooldown(CARRION_FEEDER_1, 21000);
                    return;
                }
            }

            if (IsSpellReady(LICK_YOUR_WOUNDS_1, diff, false) && !me->isMoving() && !me->GetVictim() &&
                me->getAttackers().empty() && GetHealthPCT(me) <= 50 + 30 * me->IsInCombat() &&
                !me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && Rand() < 40)
            {
                me->CastSpell(me, GetSpell(LICK_YOUR_WOUNDS_1), false);
                SetSpellCooldown(LICK_YOUR_WOUNDS_1, 126000);
                return;
            }

            if (IsSpellReady(ROAR_OF_RECOVERY_1, diff, false) && petOwner->IsInCombat() && opponent &&
                GetManaPCT(petOwner) < 65 && petOwner->GetDistance(me) < 40)
            {
                me->CastSpell(me, GetSpell(ROAR_OF_RECOVERY_1), false);
                SetSpellCooldown(ROAR_OF_RECOVERY_1, 126000);
                return;
            }

            if (IsSpellReady(INTERVENE_1, diff, false) && GetHealthPCT(petOwner) < 95 && !petOwner->getAttackers().empty() &&
                me->getAttackers().size() <= petOwner->getAttackers().size())
            {
                float petdist = me->GetDistance(petOwner);
                if (petdist < 25 && petdist > 8)
                {
                    me->CastSpell(petOwner, GetSpell(INTERVENE_1), false);
                    SetSpellCooldown(INTERVENE_1, 21000);
                    return;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            DoPetActions(diff);
            //CheckDrainMana(diff);

            if (!CheckAttackTarget())
                return;

            if (IsCasting())
                return;

            DoPetAttack(diff);
        }

        void DoPetAttack(uint32 diff)
        {
            StartAttack(opponent, IsPetMelee());

            Unit const* u = opponent->GetVictim();
            float dist = me->GetDistance(opponent);
            uint32 focus = me->GetPower(POWER_FOCUS);
            bool canDPS = petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS);

            //improved + Longevity applied to cds

            if (IsSpellReady(BESTIAL_WRATH_1, diff, false) && canDPS && opponent && dist < 10 &&
                (opponent->GetHealth() > petOwner->GetMaxHealth()/4 * (1 + opponent->getAttackers().size()) ||
                opponent->GetTypeId() == TYPEID_PLAYER))
            {
                if (petOwner->AddAura(GetSpell(BESTIAL_WRATH_1), me))
                {
                    if (GetSpell(BEAST_WITHIN_1))
                        petOwner->AddAura(GetSpell(BEAST_WITHIN_1), petOwner);

                    SetSpellCooldown(BESTIAL_WRATH_1, 70000);
                    return;
                }
            }

            //LAST STAND
            if (IsSpellReady(LAST_STAND_1, diff, false) &&
                GetHealthPCT(me) < (30 + 20 * (opponent->getAttackers().size() > 1) + 10 * me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)))
            {
                me->CastSpell(me, GetSpell(LAST_STAND_1), false);
                SetSpellCooldown(LAST_STAND_1, 252000);
            }

            if (IsSpellReady(INTIMIDATION_1, diff, false) && !CCed(opponent) && me->IsWithinMeleeRange(opponent))
            {
                me->CastSpell(opponent, GetSpell(INTIMIDATION_1), false);
                SetSpellCooldown(INTIMIDATION_1, 60000);
                return;
            }

            if (IsSpellReady(GROWL_1, diff, false) && u && u != me && focus >= 15 && me->IsWithinMeleeRange(opponent) &&
                opponent->CanHaveThreatList() && !CCed(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (GetHealthPCT(u) < 30 && GetHealthPCT(me) > 50)) && IsInBotParty(u))
            {
                me->CastSpell(opponent, GetSpell(GROWL_1), false);
                SetSpellCooldown(GROWL_1, 3500);
                return;
            }

            if (IsSpellReady(TAUNT_1, diff, false) && u && u != me && me->IsWithinMeleeRange(opponent) &&
                opponent->CanHaveThreatList() && !CCed(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (GetHealthPCT(u) < 30 && GetHealthPCT(me) > 50)) && IsInBotParty(u))
            {
                me->CastSpell(opponent, GetSpell(TAUNT_1), false);
                SetSpellCooldown(TAUNT_1, 126000);
                return;
            }

            if (IsSpellReady(COWER_1, diff, false) && !me->getAttackers().empty() &&
                me->GetDistance(*me->getAttackers().begin()) < 7 && GetHealthPCT(me) < 90)
            {
                me->CastSpell(me, GetSpell(COWER_1), false);
                SetSpellCooldown(COWER_1, 31500);
                return;
            }

            if (IsSpellReady(BULLHEADED_1, diff, false) && GetHealthPCT(me) < 90 &&
                ((!me->getAttackers().empty() && me->GetDistance(*me->getAttackers().begin()) < 7) ||
                (dist > 3 && !opponent->HasInArc(float(M_PI)/2, me) &&
                (CCed(me, true) || me->HasAuraWithMechanic(1<<MECHANIC_SNARE)))))
            {
                me->CastSpell(me, GetSpell(BULLHEADED_1), false);
                SetSpellCooldown(BULLHEADED_1, 31500);
                return;
            }

            uint32 SPRINT = IsPetTypeSpell(DASH_1) ? DASH_1 : IsPetTypeSpell(DIVE_1) ? DIVE_1 : 0;
            if (SPRINT && GetSpell(SPRINT) && IsSpellReady(SPRINT, diff, false) && dist > 10 && dist < 30 &&
                !HasBotCommandState(BOT_COMMAND_STAY))
            {
                me->CastSpell(opponent, GetSpell(SPRINT), false);
                SetSpellCooldown(SPRINT, 17500);
                return;
            }

            if (IsSpellReady(CALL_OF_THE_WILD_1, diff, false) && canDPS && opponent && dist < 10)
            {
                me->CastSpell(me, GetSpell(CALL_OF_THE_WILD_1), false);
                SetSpellCooldown(CALL_OF_THE_WILD_1, 210000);
                return;
            }

            if (IsSpellReady(RABID_1, diff, false) && canDPS && dist < 10)
            {
                me->CastSpell(me, GetSpell(RABID_1), false);
                SetSpellCooldown(RABID_1, 31500);
                return;
            }

            if (IsSpellReady(THUNDERSTOMP_1, diff, false) && canDPS && focus >= 20 &&
                me->IsWithinMeleeRange(opponent) && me->getAttackers().size() > 1)
            {
                me->CastSpell(opponent, GetSpell(THUNDERSTOMP_1), false);
                SetSpellCooldown(THUNDERSTOMP_1, 7000);
                return;
            }

            if (myType == BOT_PET_BAT)
            {
                if (IsSpellReady(SONIC_BLAST_1, diff, false) && canDPS && focus >= 80 &&
                    dist < 20 && opponent->IsNonMeleeSpellCast(false, false, true))
                {
                    me->CastSpell(opponent, GetSpell(SONIC_BLAST_1), false);
                    SetSpellCooldown(SONIC_BLAST_1, 42000);
                    return;
                }
            }
            else if (myType == BOT_PET_BIRDOFPREY)
            {
                if (IsSpellReady(SNATCH_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_DISARM) &&
                    ((opponent->GetTypeId() == TYPEID_PLAYER) ? opponent->ToPlayer()->GetWeaponForAttack(BASE_ATTACK) != nullptr :
                    opponent->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID) != 0))
                {
                    me->CastSpell(opponent, GetSpell(SNATCH_1), false);
                    SetSpellCooldown(SNATCH_1, 42000);
                    return;
                }
            }
            else if (myType == BOT_PET_CHIMAERA)
            {
                if (IsSpellReady(FROSTSTORM_BREATH_1, diff, false) && canDPS && focus >= 20 && dist < 30)
                {
                    me->CastSpell(opponent, GetSpell(FROSTSTORM_BREATH_1), false);
                    SetSpellCooldown(FROSTSTORM_BREATH_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_DRAGONHAWK)
            {
                if (IsSpellReady(FIRE_BREATH_1, diff, false) && canDPS && focus >= 20 && dist < 20)
                {
                    me->CastSpell(opponent, GetSpell(FIRE_BREATH_1), false);
                    SetSpellCooldown(FIRE_BREATH_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_NETHERRAY)
            {
                if (IsSpellReady(NETHER_SHOCK_1, diff, false) && canDPS && focus >= 20 && dist < 20 &&
                    opponent->IsNonMeleeSpellCast(false, false, true))
                {
                    me->CastSpell(opponent, GetSpell(NETHER_SHOCK_1), false);
                    SetSpellCooldown(NETHER_SHOCK_1, 28000);
                    return;
                }
            }
            else if (myType == BOT_PET_RAVAGER)
            {
                if (IsSpellReady(RAVAGE_1, diff, false) && canDPS/* && focus >= 0*/ &&
                    me->IsWithinMeleeRange(opponent) && opponent->IsNonMeleeSpellCast(false, false, true))
                {
                    me->CastSpell(opponent, GetSpell(RAVAGE_1), false);
                    SetSpellCooldown(RAVAGE_1, 28000);
                    return;
                }
            }
            else if (myType == BOT_PET_SERPENT)
            {
                if (IsSpellReady(POISON_SPIT_1, diff, false) && canDPS && focus >= 20 && dist < 30)
                {
                    me->CastSpell(opponent, GetSpell(POISON_SPIT_1), false);
                    SetSpellCooldown(POISON_SPIT_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_SILITHID)
            {
                if (IsSpellReady(VENOM_WEB_SPRAY_1, diff, false) && canDPS/* && focus >= 0*/ && dist < 30 &&
                    !CCed(opponent, true))
                {
                    me->CastSpell(opponent, GetSpell(VENOM_WEB_SPRAY_1), false);
                    SetSpellCooldown(VENOM_WEB_SPRAY_1, 28000);
                    return;
                }
            }
            else if (myType == BOT_PET_SPIDER)
            {
                if (IsSpellReady(WEB_1, diff, false)/* && focus >= 0*/ && dist < 30 && !CCed(opponent, true))
                {
                    me->CastSpell(opponent, GetSpell(WEB_1), false);
                    SetSpellCooldown(WEB_1, 28000);
                    return;
                }
            }
            else if (myType == BOT_PET_SPOREBAT)
            {
                if (IsSpellReady(SPORE_CLOUD_1, diff, false) && canDPS && focus >= 20 && dist < 5)
                {
                    me->CastSpell(opponent, GetSpell(SPORE_CLOUD_1), false);
                    SetSpellCooldown(SPORE_CLOUD_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_WINDSERPENT)
            {
                if (IsSpellReady(LIGHTNING_BREATH_1, diff, false) && canDPS && focus >= 20 && dist < 20)
                {
                    me->CastSpell(opponent, GetSpell(LIGHTNING_BREATH_1), false);
                    SetSpellCooldown(LIGHTNING_BREATH_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_CARRIONBIRD)
            {
                if (IsSpellReady(DEMORALIZING_SCREECH_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(DEMORALIZING_SCREECH_1), false);
                    SetSpellCooldown(DEMORALIZING_SCREECH_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_CAT)
            {
                if (IsSpellReady(PROWL_1, diff, false) && !me->IsInCombat() && !me->HasStealthAura() &&
                    /*focus >= 0 && */dist < 20 && dist > 5)
                {
                    me->CastSpell(opponent, GetSpell(PROWL_1), false);
                    SetSpellCooldown(PROWL_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_COREHOUND)
            {
                if (IsSpellReady(LAVA_BREATH_1, diff, false) && canDPS && focus >= 20 && dist < 30)
                {
                    me->CastSpell(opponent, GetSpell(LAVA_BREATH_1), false);
                    SetSpellCooldown(LAVA_BREATH_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_DEVILSAUR)
            {
                if (IsSpellReady(MONSTROUS_BITE_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(MONSTROUS_BITE_1), false);
                    SetSpellCooldown(MONSTROUS_BITE_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_HYENA)
            {
                if (IsSpellReady(TENDON_RIP_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(TENDON_RIP_1), false);
                    SetSpellCooldown(TENDON_RIP_1, 14000);
                    return;
                }
            }
            else if (myType == BOT_PET_TEROMOTH)
            {
                if (IsSpellReady(SERENITY_DUST_1, diff, false) && (canDPS || GetHealthPCT(me) < 90) &&
                    /*focus >= 0 && */dist < 7)
                {
                    me->CastSpell(me, GetSpell(SERENITY_DUST_1), false);
                    SetSpellCooldown(SERENITY_DUST_1, 42000);
                    return;
                }
            }
            else if (myType == BOT_PET_RAPTOR)
            {
                if (IsSpellReady(SAVAGE_REND_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(SAVAGE_REND_1), false);
                    SetSpellCooldown(SAVAGE_REND_1, 42000);
                    return;
                }
            }
            else if (myType == BOT_PET_SPIRITBEAST)
            {
                if (IsSpellReady(PROWL_1, diff, false) && !me->IsInCombat() && !me->HasStealthAura() &&
                    /*focus >= 0 && */dist < 30 && dist > 5)
                {
                    me->CastSpell(opponent, GetSpell(PROWL_1), false);
                    SetSpellCooldown(PROWL_1, 10000); //custom
                    return;
                }
                if (IsSpellReady(SPIRIT_STRIKE_1, diff, false) && canDPS && !me->HasStealthAura() &&
                    focus >= 20 && dist < 30)
                {
                    me->CastSpell(opponent, GetSpell(SPIRIT_STRIKE_1), false);
                    SetSpellCooldown(SPIRIT_STRIKE_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_TALLSTRIDER)
            {
                if (IsSpellReady(DUST_CLOUD_1, diff, false) && focus >= 20 && me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(DUST_CLOUD_1), false);
                    SetSpellCooldown(DUST_CLOUD_1, 28000);
                    return;
                }
            }
            else if (myType == BOT_PET_WASP)
            {
                if (IsSpellReady(STING_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(STING_1), false);
                    SetSpellCooldown(STING_1, 4000);
                    return;
                }
            }
            else if (myType == BOT_PET_WOLF)
            {
                if (IsSpellReady(FURIOUS_HOWL_1, diff, false) && canDPS && focus >= 20)
                {
                    me->CastSpell(me, GetSpell(FURIOUS_HOWL_1), false);
                    SetSpellCooldown(FURIOUS_HOWL_1, 28000);
                    return;
                }
            }
            else if (myType == BOT_PET_BEAR)
            {
                if (IsSpellReady(SWIPE_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(SWIPE_1), false);
                    SetSpellCooldown(SWIPE_1, 3500);
                    return;
                }
            }
            else if (myType == BOT_PET_BOAR)
            {
                if (IsSpellReady(GORE_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(GORE_1), false);
                    SetSpellCooldown(GORE_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_CRAB)
            {
                if (IsSpellReady(PIN_1, diff, false) && canDPS/* && focus >= 0*/ &&
                    me->IsWithinMeleeRange(opponent) && !CCed(opponent, true))
                {
                    me->CastSpell(opponent, GetSpell(PIN_1), false);
                    SetSpellCooldown(PIN_1, 28000);
                    return;
                }
            }
            else if (myType == BOT_PET_GORILLA)
            {
                if (IsSpellReady(PUMMEL_1, diff, false) && focus >= 20 && me->IsWithinMeleeRange(opponent) &&
                    opponent->IsNonMeleeSpellCast(false,false,true))
                {
                    me->CastSpell(opponent, GetSpell(PUMMEL_1), false);
                    SetSpellCooldown(PUMMEL_1, 21000);
                    return;
                }
            }
            else if (myType == BOT_PET_RHINO)
            {
                if (IsSpellReady(STAMPEDE_1, diff, false) && canDPS/* && focus >= 0*/ &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(STAMPEDE_1), false);
                    SetSpellCooldown(STAMPEDE_1, 42000);
                    return;
                }
            }
            else if (myType == BOT_PET_SCORPID)
            {
                if (IsSpellReady(SCORPID_POISON_1, diff, false) && canDPS && focus >= 20 &&
                    me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(SCORPID_POISON_1), false);
                    SetSpellCooldown(SCORPID_POISON_1, 7000);
                    return;
                }
            }
            else if (myType == BOT_PET_TURTLE)
            {
                if (IsSpellReady(SHELL_SHIELD_1, diff, false)/* && focus >= 0*/ && dist < 7 &&
                    !me->getAttackers().empty())
                {
                    me->CastSpell(me, GetSpell(SHELL_SHIELD_1), false);
                    SetSpellCooldown(SHELL_SHIELD_1, 42000);
                    return;
                }
            }
            else if (myType == BOT_PET_WARPSTALKER)
            {
                if (IsSpellReady(WARP_1, diff, false)/* && focus >= 0*/ && dist < 10)
                {
                    me->CastSpell(opponent, GetSpell(WARP_1), false);
                    SetSpellCooldown(WARP_1, 10500);
                    return;
                }
            }
            else if (myType == BOT_PET_WORM)
            {
                if (IsSpellReady(ACID_SPIT_1, diff, false) && canDPS && focus >= 20 && dist < 30)
                {
                    me->CastSpell(opponent, GetSpell(ACID_SPIT_1), false);
                    SetSpellCooldown(ACID_SPIT_1, 7000);
                    return;
                }
            }

            uint32 CHARGE = IsPetTypeSpell(SWOOP_1) ? SWOOP_1 : IsPetTypeSpell(CHARGE_1) ? CHARGE_1 : 0;
            if (CHARGE && GetSpell(CHARGE) && IsSpellReady(CHARGE, diff, false) && !CCed(opponent, true) && !me->HasStealthAura() &&
                !(opponent->GetTypeId() == TYPEID_UNIT && opponent->ToCreature()->isWorldBoss()) &&
                !HasBotCommandState(BOT_COMMAND_STAY) &&
                dist > 8 && dist < 25)
            {
                me->CastSpell(opponent, GetSpell(CHARGE), false);
                SetSpellCooldown(CHARGE, 17500);
                return;
            }

            if (GetSpell(WOLVERINE_BITE_1) && canDPS && me->IsWithinMeleeRange(opponent))
            {
                me->CastSpell(opponent, GetSpell(WOLVERINE_BITE_1), false);
                SetSpellCooldown(WOLVERINE_BITE_1, 7000);
                return;
            }

            uint32 ATTACK_1 = IsPetTypeSpell(BITE_1) ? BITE_1 : IsPetTypeSpell(CLAW_1) ? CLAW_1 : SMACK_1;
            if (GetSpell(ATTACK_1) && IsSpellReady(ATTACK_1, diff) && canDPS && focus >= 25 && me->IsWithinMeleeRange(opponent))
            {
                me->CastSpell(opponent, GetSpell(ATTACK_1), false);
                return;
            }
        }

        void OnPetClassSpellGo(SpellInfo const* /*spellInfo*/) override
        {
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(WorldObject* /*wtarget*/, SpellInfo const* /*spell*/) override
        {
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_pet_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
        {
            if (!u)
                return;
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void OwnerAttackedBy(Unit* u) override
        {
            if (!u)
                return;
            OnOwnerDamagedBy(u);
        }

        void Reset() override
        {
        }

        void InitPetSpells() override
        {
            uint8 lvl = me->GetLevel();
            bool isBeas = Spec() == BOT_SPEC_HUNTER_BEASTMASTERY;

            InitSpellMap(GROWL_1);
            InitSpellMap(COWER_1);

            InitSpellMap(BITE_1);
            InitSpellMap(CLAW_1);
            InitSpellMap(SMACK_1);

            //talents
  /*Talent*/IsPetTypeSpell(SWOOP_1) ? InitSpellMap(SWOOP_1, true) : RemoveSpell(SWOOP_1);
  /*Talent*/IsPetTypeSpell(CHARGE_1) ? InitSpellMap(CHARGE_1, true) : RemoveSpell(CHARGE_1);
  /*Talent*/IsPetTypeSpell(DASH_1) ? InitSpellMap(DASH_1, true) : RemoveSpell(DASH_1);
  /*Talent*/IsPetTypeSpell(DIVE_1) ? InitSpellMap(DIVE_1, true) : RemoveSpell(DIVE_1);
            //talents cunning
  /*Talent*/lvl >= 44 ? InitSpellMap(CARRION_FEEDER_1, true) : RemoveSpell(CARRION_FEEDER_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(WOLVERINE_BITE_1, true) : RemoveSpell(WOLVERINE_BITE_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(ROAR_OF_RECOVERY_1, true) : RemoveSpell(ROAR_OF_RECOVERY_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(BULLHEADED_1, true) : RemoveSpell(BULLHEADED_1);
            //talents ferocity
  ///*Talent*/lvl >= 68 ? InitSpellMap(HEART_OF_THE_PHOENIX_1, true) : RemoveSpell(HEART_OF_THE_PHOENIX_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(RABID_1, true) : RemoveSpell(RABID_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(LICK_YOUR_WOUNDS_1, true) : RemoveSpell(LICK_YOUR_WOUNDS_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(CALL_OF_THE_WILD_1, true) : RemoveSpell(CALL_OF_THE_WILD_1);
            //talents tenacity
  /*Talent*/lvl >= 44 ? InitSpellMap(THUNDERSTOMP_1, true) : RemoveSpell(THUNDERSTOMP_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(LAST_STAND_1, true) : RemoveSpell(LAST_STAND_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(TAUNT_1, true) : RemoveSpell(TAUNT_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(ROAR_OF_SACRIFICE_1, true) : RemoveSpell(ROAR_OF_SACRIFICE_1);
  /*Talent*/lvl >= 68 ? InitSpellMap(INTERVENE_1, true) : RemoveSpell(INTERVENE_1);
            //pet-specific
            InitSpellMap(SONIC_BLAST_1);
            InitSpellMap(SNATCH_1);
            InitSpellMap(FROSTSTORM_BREATH_1);
            InitSpellMap(FIRE_BREATH_1);
            InitSpellMap(NETHER_SHOCK_1);
            InitSpellMap(RAVAGE_1);
            InitSpellMap(POISON_SPIT_1);
            InitSpellMap(VENOM_WEB_SPRAY_1);
            InitSpellMap(WEB_1);
            InitSpellMap(SPORE_CLOUD_1);
            InitSpellMap(LIGHTNING_BREATH_1);
            InitSpellMap(DEMORALIZING_SCREECH_1);
            InitSpellMap(PROWL_1);
            InitSpellMap(LAVA_BREATH_1);
            InitSpellMap(MONSTROUS_BITE_1);
            InitSpellMap(TENDON_RIP_1);
            InitSpellMap(SERENITY_DUST_1);
            InitSpellMap(SAVAGE_REND_1);
            InitSpellMap(SPIRIT_STRIKE_1);
            InitSpellMap(DUST_CLOUD_1);
            InitSpellMap(STING_1);
            InitSpellMap(FURIOUS_HOWL_1);
            InitSpellMap(SWIPE_1);
            InitSpellMap(GORE_1);
            InitSpellMap(PIN_1);
            InitSpellMap(PUMMEL_1);
            InitSpellMap(STAMPEDE_1);
            InitSpellMap(SCORPID_POISON_1);
            InitSpellMap(SHELL_SHIELD_1);
            InitSpellMap(WARP_1);
            InitSpellMap(ACID_SPIT_1);

  /*Talent*/lvl >= 30 && isBeas ? InitSpellMap(SPIRIT_BOND_PET, true) : RemoveSpell(SPIRIT_BOND_PET);
  /*Talent*/lvl >= 55 && isBeas ? InitSpellMap(KINDRED_SPIRITS_PET, true) : RemoveSpell(KINDRED_SPIRITS_PET);
  /*Talent*/lvl >= 30 && isBeas ? InitSpellMap(INTIMIDATION_1, true) : RemoveSpell(INTIMIDATION_1);
  /*Talent*/lvl >= 40 && isBeas ? InitSpellMap(BESTIAL_WRATH_1, true) : RemoveSpell(BESTIAL_WRATH_1);
  /*Talent*/lvl >= 50 && isBeas ? InitSpellMap(BEAST_WITHIN_1, true) : RemoveSpell(BEAST_WITHIN_1);
        }

        void ApplyPetPassives() const override
        {
            uint8 lvl = me->GetLevel();

            RefreshAura(AVOIDANCE, lvl >= 60);
            //ignore pet type
            RefreshAura(COBRA_REFLEXES, lvl >= 20);
            RefreshAura(BLOOD_OF_THE_RHINO, lvl >= 32);
            RefreshAura(OWLS_FOCUS, lvl >= 32);
            RefreshAura(CULLING_THE_HERD, lvl >= 32);
            RefreshAura(GRACE_OF_THE_MANTIS, lvl >= 44);
            RefreshAura(CORNERED, lvl >= 44);
            RefreshAura(FEEDING_FRENZY, lvl >= 44);
            RefreshAura(SILVERBACK, lvl >= 80);

            RefreshAura(HASTE_DODGE_PASSIVE, lvl >= 45);
        }

    private:
        bool IsPetTypeSpell(uint32 basespell) const
        {
            switch (basespell)
            {
                case BITE_1: //lvl 1
                    switch (myType)
                    {
                        case BOT_PET_BAT:
                        case BOT_PET_BOAR:
                        case BOT_PET_CARRIONBIRD:
                        case BOT_PET_CROCOLISK:
                        case BOT_PET_DRAGONHAWK:
                        case BOT_PET_HYENA:
                        case BOT_PET_NETHERRAY:
                        case BOT_PET_RAVAGER:
                        case BOT_PET_SERPENT:
                        case BOT_PET_WOLF:

                        case BOT_PET_CHIMAERA:
                        case BOT_PET_COREHOUND:
                        case BOT_PET_DEVILSAUR:
                        case BOT_PET_WORM:
                            return true;
                        default:
                            return false;
                    }
                case CLAW_1: //lvl 1
                    switch (myType)
                    {
                        case BOT_PET_BEAR:
                        case BOT_PET_BIRDOFPREY:
                        case BOT_PET_CAT:
                        case BOT_PET_CRAB:
                        case BOT_PET_RAPTOR:
                        case BOT_PET_SCORPID:
                        case BOT_PET_TALLSTRIDER:

                        case BOT_PET_SILITHID:
                        case BOT_PET_SPIRITBEAST:
                            return true;
                        default:
                            return false;
                    }
                case SMACK_1: //lvl 1
                    switch (myType)
                    {
                        case BOT_PET_GORILLA:
                        case BOT_PET_SPOREBAT:
                        case BOT_PET_TEROMOTH:
                        case BOT_PET_WASP:

                        case BOT_PET_RHINO:
                            return true;
                        default:
                            return false;
                    }
                case SWOOP_1: //fliers ferocity lvl 44
                    switch (myType)
                    {
                        case BOT_PET_CARRIONBIRD:
                        case BOT_PET_WASP:
                        case BOT_PET_TEROMOTH:
                            return me->GetLevel() >= 44;
                        default:
                            return false;
                    }
                case CHARGE_1: //non-fliers tenacity/ferocity lvl 20/44
                    switch (myType)
                    {
                        case BOT_PET_BEAR:
                        case BOT_PET_BOAR:
                        case BOT_PET_CAT:
                        case BOT_PET_CRAB:
                        case BOT_PET_CROCOLISK:
                        case BOT_PET_GORILLA:
                        case BOT_PET_HYENA:
                        case BOT_PET_RAPTOR:
                        case BOT_PET_SCORPID:
                        case BOT_PET_TALLSTRIDER:
                        case BOT_PET_TURTLE:
                        case BOT_PET_WARPSTALKER:
                        case BOT_PET_WOLF:

                        case BOT_PET_COREHOUND:
                        case BOT_PET_DEVILSAUR:
                        case BOT_PET_RHINO:
                        case BOT_PET_SPIRITBEAST:
                        case BOT_PET_WORM:
                            return me->GetLevel() >= (IsPetCategory(PET_CATEGORY_FEROCITY) ? 44 : 20);
                        default:
                            return false;
                    }
                case DASH_1: //non-fliers ferocity/cunning lvl 20/44
                    switch (myType)
                    {
                        case BOT_PET_CAT:
                        case BOT_PET_HYENA:
                        case BOT_PET_RAPTOR:
                        case BOT_PET_RAVAGER:
                        case BOT_PET_SERPENT:
                        case BOT_PET_SPIDER:
                        case BOT_PET_TALLSTRIDER:
                        case BOT_PET_WARPSTALKER:
                        case BOT_PET_WOLF:

                        case BOT_PET_COREHOUND:
                        case BOT_PET_DEVILSAUR:
                        case BOT_PET_SILITHID:
                        case BOT_PET_SPIRITBEAST:
                            return me->GetLevel() >= (IsPetCategory(PET_CATEGORY_CUNNING) ? 44 : 20);
                        default:
                            return false;
                    }
                case DIVE_1: //fliers lvl 20
                    switch (myType)
                    {
                        case BOT_PET_BAT:
                        case BOT_PET_BIRDOFPREY:
                        case BOT_PET_CARRIONBIRD:
                        case BOT_PET_DRAGONHAWK:
                        case BOT_PET_TEROMOTH:
                        case BOT_PET_NETHERRAY:
                        case BOT_PET_SPOREBAT:
                        case BOT_PET_WASP:
                        case BOT_PET_WINDSERPENT:

                        case BOT_PET_CHIMAERA:
                            return me->GetLevel() >= 20;
                        default:
                            return false;
                    }
                default:
                    return true;
            }
        }

        bool IsPetCategory(uint8 category) const
        {
            switch (myType)
            {
                case BOT_PET_SPIDER:
                case BOT_PET_SERPENT:
                case BOT_PET_BIRDOFPREY:
                case BOT_PET_BAT:
                case BOT_PET_WINDSERPENT:
                case BOT_PET_RAVAGER:
                case BOT_PET_DRAGONHAWK:
                case BOT_PET_NETHERRAY:
                case BOT_PET_SPOREBAT:

                case BOT_PET_SILITHID:
                case BOT_PET_CHIMAERA:
                    return category == PET_CATEGORY_CUNNING;
                case BOT_PET_CARRIONBIRD:
                case BOT_PET_RAPTOR:
                case BOT_PET_WOLF:
                case BOT_PET_TALLSTRIDER:
                case BOT_PET_CAT:
                case BOT_PET_HYENA:
                case BOT_PET_WASP:
                case BOT_PET_TEROMOTH:

                case BOT_PET_SPIRITBEAST:
                case BOT_PET_COREHOUND:
                case BOT_PET_DEVILSAUR:
                    return category == PET_CATEGORY_FEROCITY;
                case BOT_PET_SCORPID:
                case BOT_PET_TURTLE:
                case BOT_PET_GORILLA:
                case BOT_PET_BEAR:
                case BOT_PET_BOAR:
                case BOT_PET_CRAB:
                case BOT_PET_CROCOLISK:
                case BOT_PET_WARPSTALKER:

                case BOT_PET_RHINO:
                case BOT_PET_WORM:
                    return category == PET_CATEGORY_TENACITY;
                default:
                    return false;
            }
        }
    };
};

void AddSC_hunter_bot_pets()
{
    new hunter_pet_bot();
}
