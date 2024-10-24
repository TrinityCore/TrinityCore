#include "bot_ai.h"
#include "botmgr.h"
#include "bottext.h"
#include "bottraits.h"
#include "Creature.h"
#include "Group.h"
#include "Item.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "WorldSession.h"
/*
Rogue NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - 90%
TODO:
*/

enum RogueBaseSpells
{
    KICK_1                              = 1766,
    EXPOSE_ARMOR_1                      = 8647, //NYI
    FEINT_1                             = 1966,
    DISMANTLE_1                         = 51722,

    BACKSTAB_1                          = 53,
    SINISTER_STRIKE_1                   = 1752,
    EVISCERATE_1                        = 2098,
    ENVENOM_1                           = 32645,
    RUPTURE_1                           = 1943,
    MUTILATE_1                          = 1329,
    HEMORRHAGE_1                        = 16511,
    GHOSTLY_STRIKE_1                    = 14278,
    RIPOSTE_1                           = 14251,
    DEADLY_THROW_1                      = 26679,
    FAN_OF_KNIVES_1                     = 51723,

    SPRINT_1                            = 2983,
    EVASION_1                           = 5277,
    BLIND_1                             = 2094,
    VANISH_1                            = 1856,
    COLD_BLOOD_1                        = 14177,
    HUNGER_FOR_BLOOD_1                  = 51662,
    ADRENALINE_RUSH_1                   = 13750,
    KILLING_SPREE_1                     = 51690,
    PREPARATION_1                       = 14185,
    PREMEDITATION_1                     = 14183,

    GOUGE_1                             = 1776,

    KIDNEY_SHOT_1                       = 408,
    SLICE_DICE_1                        = 5171,
    BLADE_FLURRY_1                      = 13877,
    SHADOWSTEP_1                        = 36554,
    CLOAK_OF_SHADOWS_1                  = 31224,
    TRICKS_OF_THE_TRADE_1               = 57934,
    SHADOW_DANCE_1                      = 51713,

    STEALTH_1                           = 1784,
    SAP_1                               = 6770, //NYI
    GARROTE_1                           = 703,
    CHEAP_SHOT_1                        = 1833,
    AMBUSH_1                            = 8676,

    DISTRACT_1                          = 1725, //NYI
    DISARM_TRAP_1                       = 1842, //Unused, see bot_ai::ProcessImmediateNonAttackTarget()

    //Poisons
    CRIPPLING_POISON_1                  = 3408,
    INSTANT_POISON_1                    = 8679,
    DEADLY_POISON_1                     = 2823,
    WOUND_POISON_1                      = 13219,
    MIND_NUMBING_POISON_1               = 5761, //manual use only
    ANESTHETIC_POISON_1                 = 26785,

    PICK_LOCK_1                         = 1804
};

enum RoguePassives
{
    //Talents
    SEAL_FATE1                          = 14189,
    SEAL_FATE2                          = 14190,
    SEAL_FATE3                          = 14193,
    SEAL_FATE4                          = 14194,
    SEAL_FATE5                          = 14195,
    COMBAT_POTENCY1                     = 35541,
    COMBAT_POTENCY2                     = 35550,
    COMBAT_POTENCY3                     = 35551,
    COMBAT_POTENCY4                     = 35552,
    COMBAT_POTENCY5                     = 35553,
    QUICK_RECOVERY1                     = 31244,
    QUICK_RECOVERY2                     = 31245,
    //BLADE_TWISTING1                     = 31124,
    //BLADE_TWISTING2                     = 31126,
    DEADLY_BREW                         = 51626,//rank 2
    IMPROVED_KIDNEY_SHOT                = 14176,//rank 3
    VIGOR                               = 14983,
    REMORSELESS_ATTACKS                 = 14148,//rank 2
    FLEET_FOOTED                        = 31209,//rank 2
    MURDER                              = 14159,//rank 2
    OVERKILL                            = 58426,
    FOCUSED_ATTACKS                     = 51636,//rank 3
    MASTER_POISONER                     = 58410,//rank 3
    DUAL_WIELD_SPECIALIZATION           = 13852,//rank 5
    IMPROVED_KICK                       = 13867,//rank 2
    IMPROVED_SPRINT                     = 13875,//rank 2
    HACK_AND_SLASH                      = 13964,//rank 5
    VITALITY                            = 61329,//rank 3
    NERVES_OF_STEEL                     = 31131,//rank 2
    THROWING_SPECIALIZATION             = 51679,//rank 2
    //SAVAGE_COMBAT                       = 58413,//rank 2
    UNFAIR_ADVANTAGE                    = 51674,//rank 2
    SURPRISE_ATTACKS                    = 32601,
    PREY_ON_THE_WEAK                    = 51689,//rank 5
    MASTER_OF_DECEPTION                 = 13971,//rank 3
    SETUP                               = 14071,//rank 3
    INITIATIVE                          = 13980,//rank 3
    DIRTY_DEEDS                         = 14083,//rank 2
    MASTER_OF_SUBTLETY                  = 31223,//rank 3
    CHEAT_DEATH                         = 31230,//rank 3
    ENVELOPING_SHADOWS                  = 31213,//rank 3
    TURN_THE_TABLES                     = 51629,//rank 3
    HONOR_AMONG_THIEVES                 = 51701,//rank 3

    //Other
    VIGOR_GLADIATOR                     = 21975,
    GLYPH_BACKSTAB                      = 56800,

    ROGUE_PASSIVE_DND                   = 21184 //from playercreateinfo_spell
};

enum RogueSpecial
{
    MUTILATE_DAMAGE_MAINHAND_1          = 5374,
    MUTILATE_DAMAGE_OFFHAND_1           = 27576,

    //TURN_THE_TABLES_BUFF                = 52910,//'rank 3'
    HUNGER_FOR_BLOOD_BUFF               = 63848,
    WAYLAY_DEBUFF                       = 51693,
    REMORSELESS_ATTACKS_BUFF            = 14149,
    CHEATING_DEATH_BUFF                 = 45182, //hidden
    TRICKS_OF_THE_TRADE_BUFF            = 57933,

    RELENTLESS_STRIKES_EFFECT           = 14181,
    RUTHLESSNESS_EFFECT                 = 14157,
    SEAL_FATE_EFFECT                    = 14189,
    SETUP_EFFECT                        = 15250,
    INITIATIVE_EFFECT                   = 13977,
    HONOR_AMONG_THIEVES_EFFECT          = 51699,

    VANISH_TRIGGERED_1                  = 11327,
    VANISH_TRIGGERED_2                  = 11329,
    VANISH_TRIGGERED_3                  = 26888,

    //Poisons
    CRIPPLING_POISON_PROC_1             = 3409,
    //INSTANT_POISON_PROC_1               = 8680,
    DEADLY_POISON_PROC_1                = 2818,
    WOUND_POISON_PROC_1                 = 13218,
    MIND_NUMBING_POISON_PROC_1          = 5760,
    //ANESTHETIC_POISON_PROC_1            = 26688,

    THISTLE_TEA                         = 9512 //'Restore Energy' 1 min cd
};

static const uint32 Rogue_spells_damage_arr[] =
{ AMBUSH_1, BACKSTAB_1, DEADLY_THROW_1, EVISCERATE_1, ENVENOM_1, FAN_OF_KNIVES_1, GARROTE_1, GHOSTLY_STRIKE_1, GOUGE_1,
HEMORRHAGE_1, KILLING_SPREE_1, MUTILATE_1, RIPOSTE_1, RUPTURE_1, SINISTER_STRIKE_1 };

static const uint32 Rogue_spells_cc_arr[] =
{ BLIND_1, CHEAP_SHOT_1, /*DEADLY_THROW_1, */DISMANTLE_1, GOUGE_1, KICK_1, KIDNEY_SHOT_1, /*SAP_1*/ };

static const uint32 Rogue_spells_support_arr[] =
{ /*EXPOSE_ARMOR_1, DISTRACT_1, PICK_LOCK_1,*/ STEALTH_1, ADRENALINE_RUSH_1, BLADE_FLURRY_1, CLOAK_OF_SHADOWS_1,
COLD_BLOOD_1, DISMANTLE_1, EVASION_1, FEINT_1, HUNGER_FOR_BLOOD_1, PREMEDITATION_1, PREPARATION_1, SHADOW_DANCE_1,
SHADOWSTEP_1, SLICE_DICE_1, SPRINT_1, TRICKS_OF_THE_TRADE_1, VANISH_1, DISARM_TRAP_1, THISTLE_TEA,
/*CRIPPLING_POISON_1, INSTANT_POISON_1, DEADLY_POISON_1, WOUND_POISON_1, MIND_NUMBING_POISON_1, ANESTHETIC_POISON_1*/ };

static const std::vector<uint32> Rogue_spells_damage(FROM_ARRAY(Rogue_spells_damage_arr));
static const std::vector<uint32> Rogue_spells_cc(FROM_ARRAY(Rogue_spells_cc_arr));
static const std::vector<uint32> Rogue_spells_support(FROM_ARRAY(Rogue_spells_support_arr));

class rogue_bot : public CreatureScript
{
public:
    rogue_bot() : CreatureScript("rogue_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new rogue_botAI(creature);
    }
/*
    bool OnGossipHello(Player* player, Creature* creature)
    {
        return creature->GetBotAI()->OnGossipHello(player, 0);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelect(player, creature, sender, action);
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelectCode(player, creature, sender, action, code);
        return true;
    }
*/
    struct rogue_botAI : public bot_ai
    {
        rogue_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_ROGUE;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { comboPoints = 0; bot_ai::JustDied(u); }

        void getenergy()
        {
            energy = me->GetPower(POWER_ENERGY);
        }

        int32 ecost(uint32 spellId) const
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
                return spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask());
            return 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (combopointsSpent)
            {
                combopointsSpent = false;
                comboPoints = 0;
            }

            getenergy();

            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            if (IsPotionReady())
            {
                if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }

            CheckRacials(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (IsCasting())
                return;

            if (ProcessImmediateNonAttackTarget())
                return;

            CheckUsableItems(diff);

            CheckSprint(diff);
            CheckCloakOfShadows(diff);
            CheckVanish(diff);

            if (!CheckAttackTarget())
            {
                if (!me->IsInCombat() && Rand() < 5 && me->HasAuraType(SPELL_AURA_MOD_STEALTH) &&
                    !me->GetAuraEffect(SPELL_AURA_MOD_INCREASE_SPEED, SPELLFAMILY_ROGUE, 0x800, 0x0, 0x0) && //vanish
                    !(!HasRole(BOT_ROLE_DPS) && GetLastWMOArea() == 29476))
                    me->RemoveAurasDueToSpell(STEALTH_1);
                return;
            }

            CheckBlind(diff);
            CheckPreparation(diff);
            CheckTricksOfTheTrade(diff);

            Attack(diff);
        }

        void Attack(uint32 diff)
        {
            Unit* mytar = opponent ? opponent : disttarget ? disttarget : nullptr;
            if (!mytar)
                return;

            StartAttack(mytar, IsMelee());

            CheckAttackState();
            if (!me->IsAlive() || !mytar->IsAlive())
                return;

            float dist = me->GetDistance(mytar);

            //Stealth (for Cooldown handling see bot_ai::ReleaseSpellCooldown)
            //we don't want rogue to swith into stealth for no purpose
            if (IsSpellReady(STEALTH_1, diff, false) && !me->IsInCombat() && !IsTank() && Rand() < 50 && dist < 28 &&
                (!me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) || (mytar->GetTypeId() == TYPEID_PLAYER && dist < 6)) &&
                (me->GetLevel() >= 35 || (energy >= 40 && me->GetLevel() >= 30) || dist > 8) && !IsFlagCarrier(me))
            {
                if (doCast(me, GetSpell(STEALTH_1)))
                {}
            }

            if (!CanAffectVictimAny(mytar, SPELL_SCHOOL_NORMAL))
                return;

            bool stealthed = me->HasAuraType(SPELL_AURA_MOD_STEALTH);
            bool shadowdance = me->HasAuraType(SPELL_AURA_MOD_IGNORE_SHAPESHIFT);

            //Hunger for Blood
            if (IsSpellReady(HUNGER_FOR_BLOOD_1, diff) && !shadowdance && HasRole(BOT_ROLE_DPS) && Rand() < 50 && dist < 30 &&
                mytar->HasAuraState(AURA_STATE_BLEEDING) && energy >= ecost(HUNGER_FOR_BLOOD_1) &&
                !me->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_ROGUE, 0x0, 0x1000000, 0x0))
            {
                if (doCast(mytar, GetSpell(HUNGER_FOR_BLOOD_1)))
                    return;
            }
            //Premeditation
            if (IsSpellReady(PREMEDITATION_1, diff, false) && (stealthed || shadowdance) &&
                HasRole(BOT_ROLE_DPS) && comboPoints < 4 && dist < 15 &&
                (comboPoints == 0 || mytar->GetHealth() > me->GetMaxHealth() / 4))
            {
                if (doCast(mytar, GetSpell(PREMEDITATION_1)))
                {}
            }
            //Kick
            if (IsSpellReady(KICK_1, diff, false) && !stealthed && dist <= 5 && Rand() < 70 &&
                energy >= ecost(KICK_1) && mytar->IsNonMeleeSpellCast(false,false,true))
            {
                if (doCast(mytar, GetSpell(KICK_1)))
                    getenergy();
            }
            //Killing Spree
            if (IsSpellReady(KILLING_SPREE_1, diff) && !stealthed && !shadowdance && HasRole(BOT_ROLE_DPS) &&
                Rand() < (70 - energy) && dist < 10 && GetHealthPCT(me) > 25 && (!CCed(mytar) || dist > 5) &&
                (mytar->getAttackers().size() < 4 || mytar->GetMaxHealth() > me->GetMaxHealth() * 2) &&
                (mytar->GetHealth() > me->GetMaxHealth() / 2 || me->getAttackers().size() > 1))
            {
                if (doCast(mytar, GetSpell(KILLING_SPREE_1)))
                    return;
            }
             //Gouge: if mytar is trying to attack/cast on us he will always try to face us
            if (IsSpellReady(GOUGE_1, diff) && !stealthed && !shadowdance && HasRole(BOT_ROLE_DPS) && dist <= 5 &&
                Rand() < 30 && !CCed(mytar) && energy >= ecost(GOUGE_1) &&
                ((energy < 55 && mytar->getAttackers().size() <= 1 && !mytar->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) ||
                mytar->IsNonMeleeSpellCast(false,false,true)) && mytar->HasInArc(float(M_PI), me))
            {
                if (doCast(mytar, GetSpell(GOUGE_1)))
                    return;
            }
            //Blind: in pvp only for restealth
            if (IsSpellReady(BLIND_1, diff) && !stealthed && !shadowdance && dist <= 15 && Rand() < 30 &&
                !CCed(mytar) && !mytar->IsTotem() && energy >= ecost(BLIND_1) &&
                ((energy <= 30 && mytar->GetTarget() == me->GetGUID() &&
                mytar->getAttackers().size() <= 1 &&
                !mytar->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) &&
                !me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) ||
                (mytar->GetTypeId() == TYPEID_UNIT &&
                !IsSpellReady(KICK_1, diff) && !IsSpellReady(GOUGE_1, diff) &&
                mytar->IsNonMeleeSpellCast(false,false,true))))
            {
                if (doCast(mytar, GetSpell(BLIND_1)))
                    return;
            }
            //Blade Flurry
            if (IsSpellReady(BLADE_FLURRY_1, diff) && HasRole(BOT_ROLE_DPS) && !stealthed && !shadowdance &&
                dist <= 5 && Rand() < 50 && energy >= ecost(BLADE_FLURRY_1) && !CCed(mytar) &&
                !me->GetAuraEffect(SPELL_AURA_MOD_MELEE_HASTE, SPELLFAMILY_ROGUE, 0x40000000, 0x800, 0x0) &&
                (mytar->GetTypeId() == TYPEID_PLAYER || mytar->GetHealth() > me->GetHealth() || FindSplashTarget(7, mytar)))
            {
                if (doCast(me, GetSpell(BLADE_FLURRY_1)))
                    return;
            }
            //Slice and Dice
            if (IsSpellReady(SLICE_DICE_1, diff) && !shadowdance && HasRole(BOT_ROLE_DPS) && comboPoints > 0 &&
                Rand() < 110 && energy >= ecost(SLICE_DICE_1) && dist < 10 &&
                (me->getAttackers().size() <= 1 || !IsSpellReady(BLADE_FLURRY_1, diff)) &&
                !me->GetAuraEffect(SPELL_AURA_MOD_MELEE_HASTE, SPELLFAMILY_ROGUE, 0x40000, 0x0, 0x0))
            {
                if (doCast(mytar, GetSpell(SLICE_DICE_1)))
                    return;
            }
            //Dismantle
            if (IsSpellReady(DISMANTLE_1, diff) && !stealthed && !shadowdance &&
                mytar->GetHealth() >= me->GetHealth() / 2 && energy >= ecost(DISMANTLE_1) && dist <= 5 &&
                !CCed(mytar) && Rand() < (30 + 90*mytar->HasAuraType(SPELL_AURA_ALLOW_ONLY_ABILITY)) &&
                !mytar->HasAuraType(SPELL_AURA_MOD_DISARM) &&
                (mytar->GetTypeId() == TYPEID_PLAYER ?
                mytar->ToPlayer()->GetWeaponForAttack(BASE_ATTACK) && mytar->ToPlayer()->IsUseEquipedWeapon(true) :
                mytar->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID) && mytar->CanUseAttackType(BASE_ATTACK)))
            {
                if (doCast(mytar, GetSpell(DISMANTLE_1)))
                    return;
            }
            //Shadowstep
            if (IsSpellReady(SHADOWSTEP_1, diff, false) && !IsTank() && HasRole(BOT_ROLE_DPS) &&
                Rand() < 50 && dist < 25 && energy >= ecost(SHADOWSTEP_1) &&
                (mytar->GetTypeId() != TYPEID_PLAYER || dist > 12 || CCed(me, true)) &&
                (mytar->GetTypeId() == TYPEID_PLAYER || mytar->GetVictim() != me) &&
                ((!stealthed && !shadowdance) || me->HasAuraWithMechanic(1<<MECHANIC_SNARE)))
            {
                if (doCast(mytar, GetSpell(SHADOWSTEP_1)))
                    getenergy();
            }
            //Sprint (no GCD)
            if (IsSpellReady(SPRINT_1, diff, false) && !HasBotCommandState(BOT_COMMAND_STAY) &&
                ((me->GetLevel() >= 20 && CCed(me, true) && Rand() < 35) ||
                (Rand() < (25 + 10*stealthed + 40*shadowdance) && dist > (20 - (5*stealthed + 10*shadowdance)))) &&
                !me->GetAuraEffect(SPELL_AURA_MOD_INCREASE_SPEED, SPELLFAMILY_ROGUE, 0x40, 0x0, 0x0))
            {
                if (doCast(me, GetSpell(SPRINT_1)))
                {}
            }
            //Evasion (no GCD)
            if (IsSpellReady(EVASION_1, diff, false) && !stealthed && Rand() < 65 && !me->getAttackers().empty() &&
                GetHealthPCT(me) < 65 + 10 * me->getAttackers().size() &&
                !me->GetAuraEffect(SPELL_AURA_MOD_DODGE_PERCENT, SPELLFAMILY_ROGUE, 0x20, 0x0, 0x0))
            {
                if (doCast(me, GetSpell(EVASION_1)))
                    return; //custom: do not skip animation
            }
            //Deadly Throw
            if (IsSpellReady(DEADLY_THROW_1, diff) && !stealthed && !shadowdance && HasRole(BOT_ROLE_DPS) &&
                comboPoints > 0 && Rand() < 55 && dist < 30 && dist > 5 && energy >= ecost(DEADLY_THROW_1) &&
                ((_spec != BOT_SPEC_ROGUE_COMBAT) || mytar->IsNonMeleeSpellCast(false,false,true)))
            {
                Item const* thrown = GetEquips(BOT_SLOT_RANGED);
                if (thrown && thrown->GetTemplate()->Class == ITEM_CLASS_WEAPON &&
                    thrown->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_THROWN &&
                    doCast(mytar, GetSpell(DEADLY_THROW_1)))
                    return;
            }

            //if target is affected by gouge or blind just try to regen some energy
            bool hasnormalstun = false;
            int32 duration = 0;
            //sizes of theese are typically 1, sometimes maybe 2
            Unit::AuraEffectList const& stunAuras = mytar->GetAuraEffectsByType(SPELL_AURA_MOD_STUN);
            for (Unit::AuraEffectList::const_iterator itr = stunAuras.begin(); itr != stunAuras.end(); ++itr)
            {
                if (!((*itr)->GetSpellInfo()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_TAKE_DAMAGE) &&
                    (*itr)->GetBase()->GetDuration() > 2000)
                {
                    hasnormalstun = true;
                    break;
                }
                if ((*itr)->GetBase()->GetDuration() > duration)
                    duration = (*itr)->GetBase()->GetDuration();
            }
            if (!hasnormalstun)
            {
                Unit::AuraEffectList const& confuseAuras = mytar->GetAuraEffectsByType(SPELL_AURA_MOD_CONFUSE);
                for (Unit::AuraEffectList::const_iterator itr = confuseAuras.begin(); itr != confuseAuras.end(); ++itr)
                {
                    if (!((*itr)->GetSpellInfo()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_TAKE_DAMAGE) &&
                        (*itr)->GetBase()->GetDuration() > 2000)
                    {
                        hasnormalstun = true;
                        break;
                    }
                    if ((*itr)->GetBase()->GetDuration() > duration)
                        duration = (*itr)->GetBase()->GetDuration();
                }
            }

            if (mytar->IsControlledByPlayer() || me->GetHealthPct() < 25.f)
            {
                //Vanish (no GCD)
                if (IsSpellReady(VANISH_1, diff, false) && !stealthed && !shadowdance && !IsTank() && Rand() < 45 && !me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE))
                {
                    bool cast = false;
                    //case 1: restealth for opener
                    if (!hasnormalstun && duration < 500 && me->IsInCombat() && dist <= 5)
                        cast = true;
                    //case 2: evade casted spell
                    if (!cast)
                    {
                        if (Spell const* spell = mytar->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                        {
                            if (spell->m_targets.GetUnitTarget() == me && spell->GetTimer() < 500 &&
                                spell->GetSpellInfo()->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE))
                                cast = true;
                        }
                    }
                    //case 3: reset threat / evade in CheckVanish (regardless of mytar availability)
                    if (cast && doCast(me, GetSpell(VANISH_1)))
                        return; //custom: do not skip animation
                }
            }

            if (dist > 5)
            {
                //if (mytar->IsPolymorphed())
                //    TC_LOG_ERROR("entities.player", "rogue_bot: cannot attack target (dist)...");
                return;
            }

            MoveBehind(mytar);

            if (IsSpellReady(THISTLE_TEA, diff, false) && !hasnormalstun && duration < 1000 &&
                energy <= std::max<int32>(me->GetMaxPower(POWER_ENERGY) - 110, 10))
            {
                if (doCast(me, THISTLE_TEA))
                    getenergy();
            }

            //No IsSpellReady checks for spells with no cd below
            if (GC_Timer > diff)
                return;

            //Feint
            if (mytar->CanHaveThreatList())
            {
                if (IsSpellReady(FEINT_1, diff) && !stealthed && !IsTank() && mytar->GetVictim() == me && Rand() < 35 &&
                    energy >= ecost(FEINT_1) && int32(mytar->GetThreatManager().GetThreatListSize()) > 1 &&
                    int32(mytar->getAttackers().size()) > 1)
                {
                    if (doCast(mytar, GetSpell(FEINT_1)))
                        return;
                }
            }

            //Adrenaline Rush
            if (GetSpell(ADRENALINE_RUSH_1) && !stealthed && !shadowdance && HasRole(BOT_ROLE_DPS) && (hasnormalstun || duration < 1300) && Rand() < 40 &&
                energy < 50 && GetHealthPCT(me) > 35 &&
                (mytar->getAttackers().size() < 3 || mytar->GetMaxHealth() > me->GetMaxHealth() * 2) &&
                (mytar->GetHealth() > me->GetMaxHealth() / 2 || me->getAttackers().size() > 1))
            {
                if (doCast(me, GetSpell(ADRENALINE_RUSH_1)))
                    return;
            }

            DiminishingLevels const stunDivider = mytar->GetDiminishing(DIMINISHING_OPENING_STUN);

            bool hasHunger = me->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_ROGUE, 0x0, 0x1000000, 0x0);

            //Rupture: little troll with applying rupture on target without breaking gouge (creatures only, pvp - restealth)
            if (GetSpell(RUPTURE_1) && !stealthed && !shadowdance && HasRole(BOT_ROLE_DPS) &&
                comboPoints > ((hasHunger || !GetSpell(HUNGER_FOR_BLOOD_1)) ? 1 : 0) &&
                !(hasHunger && GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && GetSpell(ENVENOM_1)) &&
                (hasnormalstun || (mytar->CanHaveThreatList() && duration < 2000)) &&
                (comboPoints < 4 || !GetSpell(KIDNEY_SHOT_1) || stunDivider > DIMINISHING_LEVEL_2) &&
                energy >= ecost(RUPTURE_1) && mytar->GetHealth() > me->GetMaxHealth() / 4 * (1 + mytar->getAttackers().size()) &&
                Rand() < (40 + 40 * (mytar->GetTypeId() == TYPEID_PLAYER && IsMeleeClass(mytar->GetClass()))) &&
                !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x100000, 0x0, 0x0, me->GetGUID()))
            {
                if (doCast(mytar, GetSpell(RUPTURE_1)))
                    return;
            }

            if (!hasnormalstun && duration > 300 && uint32(energy) < me->GetMaxPower(POWER_ENERGY))
            {
                //TC_LOG_ERROR("entities.player", "bot_rogue: delaying attacks on gouged or blinded target...");
                return;
            }

            //Finishers
            if (comboPoints > 0)
            {
                //Kidney Shot
                if (GetSpell(KIDNEY_SHOT_1) && !stealthed && stunDivider < DIMINISHING_LEVEL_4 &&
                    Rand() < 80 && !CCed(mytar) &&
                    !IsImmunedToMySpellEffect(mytar, sSpellMgr->GetSpellInfo(KIDNEY_SHOT_1), EFFECT_0) &&
                    ((comboPoints >= 4 && stunDivider < DIMINISHING_LEVEL_3 &&
                    (mytar->GetHealth() > me->GetMaxHealth() / 2 || mytar->GetTypeId() == TYPEID_PLAYER)) ||
                    mytar->IsNonMeleeSpellCast(false,false,true)) &&
                    energy >= ecost(KIDNEY_SHOT_1))
                {
                    if (doCast(mytar, GetSpell(KIDNEY_SHOT_1)))
                        return;
                }
                //Envenom / Eviscerate
                uint32 envescerate = (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && GetSpell(ENVENOM_1) &&
                    (mytar->GetHealth() > me->GetMaxHealth() / 5 || !GetSpell(EVISCERATE_1))) ? ENVENOM_1 : GetSpell(EVISCERATE_1) ? EVISCERATE_1 : 0;
                if (envescerate && IsSpellReady(envescerate, diff) && !stealthed && !shadowdance && HasRole(BOT_ROLE_DPS) &&
                    (comboPoints >= 4  || (envescerate == EVISCERATE_1 && mytar->GetHealth() < me->GetMaxHealth() / 4)) &&
                    (envescerate != ENVENOM_1 ||
                    (mytar->GetAuraEffect(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE, SPELLFAMILY_ROGUE, 0x10000, 0x0, 0x0, me->GetGUID()) &&
                    (energy >= 110 || !me->HasAuraTypeWithFamilyFlags(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_ROGUE, 0x800000)))) &&
                    energy >= ecost(envescerate) && Rand() < (70 + comboPoints * 20))
                {
                    //Cold Blood (no GCD)
                    if (IsSpellReady(COLD_BLOOD_1, diff, false) && comboPoints > 3 && Rand() > 50 + 100*(comboPoints == 5))
                        if (doCast(me, GetSpell(COLD_BLOOD_1)))
                        {}
                    if (doCast(mytar, GetSpell(envescerate)))
                        return;
                }
            }

            //Shadow Dance: if have energy or under effect of Adrenaline Rush
            if (IsSpellReady(SHADOW_DANCE_1, diff, false) && !stealthed && HasRole(BOT_ROLE_DPS) && Rand() < 55 &&
                GetHealthPCT(me) > 40 && (stunDivider == DIMINISHING_LEVEL_1 || CCed(mytar)) &&
                (energy >= 60 || (energy >= 40 && me->GetAuraEffect(SPELL_AURA_MOD_POWER_REGEN_PERCENT, SPELLFAMILY_ROGUE, 0x0, 0x80, 0x0))) &&
                (mytar->GetTypeId() == TYPEID_PLAYER || mytar->GetHealth() > (me->GetMaxHealth() / 4) * mytar->getAttackers().size()))
            {
                if (doCast(me, GetSpell(SHADOW_DANCE_1)))
                {}
            }

            //Openers
            if (stealthed || shadowdance)
            {
                uint32 opener =
                    GetSpell(CHEAP_SHOT_1) &&
                    !mytar->HasAuraType(SPELL_AURA_MOD_STUN) && stunDivider < DIMINISHING_LEVEL_3 &&
                    (mytar->GetTypeId() == TYPEID_PLAYER || (!IAmFree() && master->GetNpcBotsCount() > 1)) ? CHEAP_SHOT_1 :
                    GetSpell(GARROTE_1) && HasRole(BOT_ROLE_DPS) && mytar->GetHealth() > me->GetMaxHealth() / 4 &&
                    !IsImmunedToMySpellEffect(mytar, sSpellMgr->GetSpellInfo(GARROTE_1), EFFECT_0) &&
                    (!isdaggerMH || (mytar->GetTypeId() == TYPEID_PLAYER &&
                    (mytar->GetClass() == CLASS_MAGE || mytar->GetClass() == CLASS_PRIEST || mytar->GetClass() == CLASS_WARLOCK))) &&
                    !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x100, 0x0, 0x0, me->GetGUID()) ? GARROTE_1 :
                    GetSpell(AMBUSH_1) && HasRole(BOT_ROLE_DPS) && isdaggerMH ? AMBUSH_1 :
                    GetSpell(BACKSTAB_1) && HasRole(BOT_ROLE_DPS) && isdaggerMH ? BACKSTAB_1 : 0;

                //all opener spells disabled/unusable
                if (!opener)
                {
                    if (stealthed && HasRole(BOT_ROLE_DPS))
                        me->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                    //if (shadowdance)
                    //    me->RemoveAurasByType(SPELL_AURA_MOD_IGNORE_SHAPESHIFT);

                    return;
                }
                //openers from behind (backstab too)
                if (opener != CHEAP_SHOT_1 && mytar->HasInArc(float(M_PI), me))
                    return;

                //We do not check combo points amount
                if (energy >= ecost(opener))
                {
                    if (doCast(mytar, GetSpell(opener)))
                        return;
                }

                return;
            }

            if (!HasRole(BOT_ROLE_DPS))
                return;

            //Fan of Knives
            if (GetSpell(FAN_OF_KNIVES_1) && energy >= ecost(FAN_OF_KNIVES_1) &&
                Rand() < 35
                + 40*(me->GetAuraEffect(SPELL_AURA_MOD_POWER_REGEN_PERCENT, SPELLFAMILY_ROGUE, 0x0, 0x80, 0x0) != nullptr)
                + 50*(me->GetAuraEffect(SPELL_AURA_MOD_MELEE_HASTE, SPELLFAMILY_ROGUE, 0x40000000, 0x0, 0x0) != nullptr)
                /*Adrenaline Rush and Blade Flurry*/)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 7.f, 1);
                if (targets.size() > 2 && doCast(me, GetSpell(FAN_OF_KNIVES_1)))
                    return;
            }

            //Combo points generating
            //Riposte: only after parry
            if (IsSpellReady(RIPOSTE_1, diff) && comboPoints < 5 && me->HasReactive(REACTIVE_DEFENSE) &&
                energy >= ecost(RIPOSTE_1))
            {
                if (doCast(mytar, GetSpell(RIPOSTE_1)))
                    return;
            }
            //Ghostly Strike: tank mode only
            if (IsSpellReady(GHOSTLY_STRIKE_1, diff) && comboPoints < 5 && IsTank() && !me->getAttackers().empty() &&
                energy >= ecost(GHOSTLY_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(GHOSTLY_STRIKE_1)))
                    return;
            }
            //Hemorrhage: does not stack from different casters
            if (GetSpell(HEMORRHAGE_1) && !isdaggerMH && comboPoints < 5 && !IsTank() && energy >= ecost(HEMORRHAGE_1) &&
                !mytar->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_TAKEN, SPELLFAMILY_ROGUE, 0x800000, 0x0, 0x0))
            {
                if (doCast(mytar, GetSpell(HEMORRHAGE_1)))
                    return;
            }
            //Sinister Strike: tank mode
            if (GetSpell(SINISTER_STRIKE_1) && comboPoints < 5 &&
                (!isdaggerMH || IsTank() || (mytar->GetVictim() == me && energy >= 60 && mytar->HasInArc(float(M_PI), me)) || !GetSpell(BACKSTAB_1)) &&
                energy >= ecost(SINISTER_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(SINISTER_STRIKE_1)))
                    return;
            }
            //Backstab/Mutilate
            uint32 mutistab =
                isdaggerMH && isdaggerOH && GetSpell(MUTILATE_1) ? MUTILATE_1 :
                isdaggerMH && GetSpell(BACKSTAB_1) ? BACKSTAB_1 : 0;
            if (mutistab && comboPoints < 4 && energy >= ecost(mutistab) && (mutistab == MUTILATE_1 || !mytar->HasInArc(float(M_PI), me)))
            {
                if (doCast(mytar, GetSpell(mutistab)))
                    return;
            }
        }

        void BreakCC(uint32 diff) override
        {
            if (me->IsInCombat() && Rand() < 25)
            {
                bool canVanish = IsSpellReady(VANISH_1, diff, false);
                bool canSprint = (GetSpec() == BOT_SPEC_ROGUE_COMBAT) && me->GetLevel() >= 25 && !HasBotCommandState(BOT_COMMAND_STAY) && IsSpellReady(SPRINT_1, diff, false);
                if ((canVanish || canSprint) && me->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT)))
                {
                    uint32 Spanish = canSprint ? SPRINT_1 : VANISH_1;
                    if (doCast(me, GetSpell(Spanish)))
                        return;
                }
            }
            bot_ai::BreakCC(diff);
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting() || Rand() > 25)
                return;

            if (mhEnchantExpireTimer > 0 && mhEnchantExpireTimer <= diff)
                RemoveItemClassEnchantment(BOT_SLOT_MAINHAND);
            if (ohEnchantExpireTimer > 0 && ohEnchantExpireTimer <= diff)
                RemoveItemClassEnchantment(BOT_SLOT_OFFHAND);

            // Weapon Enchants
            if (me->isMoving())
                return;
            uint8 lvl = me->GetLevel();
            if (lvl < 20)
                return;

            Item* mhWeapon = GetEquips(BOT_SLOT_MAINHAND);
            Item* ohWeapon = GetEquips(BOT_SLOT_OFFHAND);

            bool mhReady = mhWeapon && !mhWeapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT);
            bool ohReady = ohWeapon && !ohWeapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT);
            if (!mhReady && !ohReady)
                return; //no ecnhantable weapons

            //OK choose the poisons
            //MH 20+ Instant, 32+ Wound, envenom Instant
            //OH 20+ Crippling, 40+ Instant (deadly brew inc), 68+ Anesthetic, envenom Deadly
            if (needChooseMHEnchant && mhReady)
                mhEnchant = (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && GetSpell(ENVENOM_1)) ? INSTANT_POISON_1 :
                    lvl >= 32 ? WOUND_POISON_1 :
                    lvl >= 20 ? INSTANT_POISON_1 : 0;

            if (needChooseOHEnchant && ohReady)
                ohEnchant = (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && GetSpell(ENVENOM_1)) ? DEADLY_POISON_1 :
                    lvl >= 68 ? ANESTHETIC_POISON_1 :
                    lvl >= 40 ? INSTANT_POISON_1 :
                    lvl >= 20 ? CRIPPLING_POISON_1 : 0;

            uint32 MhPoison = !mhReady ? 0 : GetSpell(mhEnchant);
            uint32 OhPoison = !ohReady ? 0 : GetSpell(ohEnchant);

            SpellInfo const* MhPoisonInfo = mhReady && MhPoison ? sSpellMgr->GetSpellInfo(MhPoison) : nullptr;
            SpellInfo const* OhPoisonInfo = ohReady && OhPoison ? sSpellMgr->GetSpellInfo(OhPoison) : nullptr;

            Item* targetWeapon = nullptr;
            SpellInfo const* targetInfo = nullptr;

            if (mhReady && MhPoison && mhWeapon->IsFitToSpellRequirements(MhPoisonInfo))
            {
                targetWeapon = mhWeapon;
                targetInfo = MhPoisonInfo;
            }
            if (!targetWeapon && ohReady && OhPoison && ohWeapon->IsFitToSpellRequirements(OhPoisonInfo))
            {
                targetWeapon = ohWeapon;
                targetInfo = OhPoisonInfo;
            }
            if (targetWeapon)
            {
                Spell* spell = new Spell(me, targetInfo, TRIGGERED_NONE);
                SpellCastTargets targets;
                targets.SetItemTarget(targetWeapon);
                spell->prepare(targets);
                return;
            }
        }

        void CheckVanish(uint32 diff)
        {
            if (!IsSpellReady(VANISH_1, diff, false) || !me->IsInCombat() || me->IsMounted() || IsTank() || Rand() > 50 ||
                me->getAttackers().empty() || IsFlagCarrier(me) || me->HasAuraType(SPELL_AURA_MOD_STEALTH) ||
                me->HasAuraType(SPELL_AURA_ALLOW_ONLY_ABILITY) || me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE))
                return;

            if (GetHealthPCT(me) < 30 + 20*me->getAttackers().size() ||
                (!IAmFree() && GetHealthPCT(me) < 70 && master->GetNpcBotsCount() > 1))
            {
                //Unit* victim = me->GetVictim();
                if (doCast(me, GetSpell(VANISH_1)))
                    return;
            }
        }

        void CheckCloakOfShadows(uint32 diff)
        {
            if (!IsSpellReady(CLOAK_OF_SHADOWS_1, diff) || !me->IsInCombat() || me->IsMounted() ||
                Rand() > 40 + 60 * me->GetMap()->IsDungeon())
                return;

            uint32 count = 0;

            //dispel debuffs
            uint32 const dispelMask = DISPEL_ALL_MASK;
            Unit::AuraApplicationMap const& Auras = me->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator iter = Auras.begin(); iter != Auras.end(); ++iter)
            {
                // remove all harmful spells on you...
                SpellInfo const* spellInfo = iter->second->GetBase()->GetSpellInfo();
                if ((spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC || (spellInfo->GetDispelMask() & dispelMask)) &&
                    !iter->second->IsPositive() && !iter->second->GetBase()->IsPassive())
                {
                    if (spellInfo->HasAura(SPELL_AURA_PERIODIC_DAMAGE) ||
                        spellInfo->HasAura(SPELL_AURA_MOD_SPEED_SLOW_ALL) ||
                        spellInfo->HasAura(SPELL_AURA_HASTE_SPELLS))
                        if (++count > 1)
                            break;
                }
            }

            //defend from enemy cast cast
            if (Unit const* target = FindCastingTarget(50))
            {
                if (Spell const* spell = target->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                {
                    if (spell->GetTimer() < 1000 && !spell->GetSpellInfo()->IsPassive() && !spell->GetSpellInfo()->IsPositive() &&
                        !(spell->GetSpellInfo()->Attributes & (SPELL_ATTR0_ABILITY|SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)))
                    {
                        //direct spell
                        if (spell->m_targets.GetUnitTarget() == me &&
                            spell->GetSpellInfo()->DmgClass == SPELL_DAMAGE_CLASS_MAGIC &&
                            me->IsWithinLOSInMap(target, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                        {
                            count += 2;
                        }
                        //area spell
                        if ((spell->GetSpellInfo()->_effects[0].IsEffect() &&
                            spell->GetSpellInfo()->_effects[0].TargetB.GetSelectionCategory() == TARGET_SELECT_CATEGORY_NEARBY) ||
                            (spell->GetSpellInfo()->_effects[1].IsEffect() &&
                            spell->GetSpellInfo()->_effects[1].TargetB.GetSelectionCategory() == TARGET_SELECT_CATEGORY_NEARBY))
                        {
                            count += 2;
                        }
                    }
                }
            }

            if (!(count > 1))
                return;

            if (doCast(me, GetSpell(CLOAK_OF_SHADOWS_1)))
                return;
        }

        void CheckBlind(uint32 diff)
        {
            if (!IsSpellReady(BLIND_1, diff) || !me->IsInCombat() || me->IsMounted() || IsTank() || Rand() > 40 ||
                me->HasAuraType(SPELL_AURA_MOD_STEALTH) || me->HasAuraType(SPELL_AURA_ALLOW_ONLY_ABILITY) ||
                IsSpellReady(BLADE_FLURRY_1, diff, false) || IsSpellReady(EVASION_1, diff, false) ||
                me->GetAuraEffect(SPELL_AURA_MOD_DODGE_PERCENT, SPELLFAMILY_ROGUE, 0x20, 0x0, 0x0) ||//evasion
                me->GetAuraEffect(SPELL_AURA_MOD_MELEE_HASTE, SPELLFAMILY_ROGUE, 0x40000000, 0x800, 0x0))
                return;

            Unit* u = FindStunTarget(15); //improved always (base 10, improved 15)
            if (!u)
                u = FindCastingTarget(15, 0, BLIND_1);

            if (u && doCast(u, GetSpell(BLIND_1)))
                return;
        }

        void CheckPreparation(uint32 diff)
        {
            if (!IsSpellReady(PREPARATION_1, diff) || !me->IsInCombat() || me->IsMounted() || Rand() > 30)
                return;

            //TODO: recheck priorities
            uint32 needFactor = 0;
            uint32 cooldown;
            cooldown = GetSpellCooldown(EVASION_1);
            needFactor += !cooldown ? 0 : 3 * cooldown / 1200; //1-100 x3
            cooldown = GetSpellCooldown(SPRINT_1);
            needFactor += !cooldown ? 0 : 1 * cooldown / 1200; //1-100
            cooldown = GetSpellCooldown(VANISH_1);
            needFactor += !cooldown ? 0 : 3 * cooldown / 1200; //1-100 x3
            cooldown = GetSpellCooldown(COLD_BLOOD_1);
            needFactor += !cooldown ? 0 : 2 * cooldown / 1800; //1-100 x2
            cooldown = GetSpellCooldown(SHADOWSTEP_1);
            needFactor += !cooldown ? 0 : 2 * cooldown / 200;  //1-100 x2
            cooldown = GetSpellCooldown(BLADE_FLURRY_1);
            needFactor += !cooldown ? 0 : 1 * cooldown / 1200; //1-100
            cooldown = GetSpellCooldown(DISMANTLE_1);
            needFactor += !cooldown ? 0 : 1 * cooldown / 600;  //1-100
            //0-1300
            //ignore Kick

            if (needFactor >= 800 && doCast(me, GetSpell(PREPARATION_1)))
                return;
        }

        void CheckTricksOfTheTrade(uint32 diff)
        {
            if (!IsSpellReady(TRICKS_OF_THE_TRADE_1, diff) || !me->IsInCombat() || me->IsMounted() || IAmFree() ||
                IsTank() || Rand() > 30 || !me->GetMap()->IsDungeon() ||
                me->HasAuraType(SPELL_AURA_MOD_STEALTH) || me->HasAuraType(SPELL_AURA_ALLOW_ONLY_ABILITY))
                return;

            Group const* group = master->GetGroup();
            if (!group)
                return;
            Unit* victim = me->GetVictim();
            if (!victim)
                return;

            Unit* target = nullptr;
            for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* player = itr->GetSource();
                if (!player || !player->IsInWorld() || !player->IsAlive() || me->GetMap() != player->FindMap() ||
                    me->GetDistance(player) > 20)
                    continue;

                if (IsTank(player) || player->GetVictim() == victim)
                {
                    if (!victim->CanHaveThreatList() ||
                        victim->GetThreatManager().GetThreat(player) < victim->GetThreatManager().GetThreat(me) * 0.75f)
                    {
                        target = player;
                        break;
                    }
                }
            }

            if (target)
                if (doCast(target, GetSpell(TRICKS_OF_THE_TRADE_1)))
                    return;
        }

        void CheckSprint(uint32 diff)
        {
            if (!IsSpellReady(SPRINT_1, diff) || (!IAmFree() && !HasBotCommandState(BOT_COMMAND_FOLLOW)) || Rand() > 35 || me->IsMounted())
                return;

            if (IAmFree())
            {
                InstanceTemplate const* instt = sObjectMgr->GetInstanceTemplate(me->GetMap()->GetId());
                bool map_allows_mount = (!me->GetMap()->IsDungeon() || me->GetMap()->IsBattlegroundOrArena()) && (!instt || instt->AllowMount);
                if (me->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD) &&
                    (!me->GetVictim() ? (!map_allows_mount || me->IsInCombat() || IsFlagCarrier(me)) : !me->IsWithinDist(me->GetVictim(), 8.0f)))
                {
                    if (doCast(me, GetSpell(SPRINT_1)))
                        return;
                }

                return;
            }

            if (me->GetExactDist2d(master) > std::max<uint8>(master->GetBotMgr()->GetBotFollowDist(), 45))
            {
                if (doCast(me, GetSpell(SPRINT_1)))
                    return;
            }
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const override
        {
            if (spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
                return;

            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Cold Blood
            if (AuraEffect const* bloo = me->GetAuraEffect(COLD_BLOOD_1, 0, me->GetGUID()))
                if (bloo->IsAffectingSpell(spellInfo))
                    crit_chance += 100.f;

            //Puncturing Wounds:
            if (lvl >= 15)
            {
                //30% additional critical chance for Backstab
                if (baseId == BACKSTAB_1)
                    crit_chance += 30.f;
                //Puncturing Wounds: 15% additional critical chance for Mutilate
                else if (baseId == MUTILATE_1 ||
                    baseId == MUTILATE_DAMAGE_MAINHAND_1 || baseId == MUTILATE_DAMAGE_OFFHAND_1)
                    crit_chance += 15.f;
            }
            //Glyph of Eviscerate: 10% additional critical chance for Eviscerate
            if (lvl >= 15 && baseId == EVISCERATE_1)
                crit_chance += 10.f;
            //Improved Ambush: 50% additional critical chance for Ambush
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) && lvl >= 25 && baseId == AMBUSH_1)
                crit_chance += 50.f;
            //Turn the Tables:
            if (lvl >= 50 &&
                ((spellInfo->SpellFamilyFlags[0] & 0x2600070E) || (spellInfo->SpellFamilyFlags[1] & 0x7900106)) &&
                me->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_ROGUE, 0x0, 0x200000, 0x0))
                crit_chance += 6.f;
            //Remorseless Attacks:
            if (AuraEffect const* remo = me->GetAuraEffect(REMORSELESS_ATTACKS_BUFF, 0, me->GetGUID()))
                if (remo->IsAffectingSpell(spellInfo))
                    crit_chance += 40.f;
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Lethality: 30% crit damage bonus for non-stealth combo-generating abilities (on 25 lvl)
                if (lvl >= 25 &&
                    (baseId == SINISTER_STRIKE_1 || baseId == BACKSTAB_1 || baseId == MUTILATE_1 || baseId == RIPOSTE_1 ||
                    baseId == GOUGE_1 || baseId == HEMORRHAGE_1 || baseId == GHOSTLY_STRIKE_1
                    /*|| baseId == SHIV_1*/ || baseId == MUTILATE_DAMAGE_MAINHAND_1 || baseId == MUTILATE_DAMAGE_OFFHAND_1))
                    pctbonus += 0.15f;
            }

            //DeathDealer set bonus: 15% damage bonus for Eviscerate
            if (lvl >= 60 && baseId == EVISCERATE_1)
                pctbonus += 0.15f;
            //Find Weakness: 6% bonus damage to all abilities
            if ((GetSpec() == BOT_SPEC_ROGUE_ASSASINATION) && lvl >= 45)
                pctbonus += 0.06f;
            //Improved Eviscerate: 20% damage bonus for Eviscerate
            if (lvl >= 10 && baseId == EVISCERATE_1)
                pctbonus += 0.2f;
            //Opportunity: 20% damage bonus for Backstab, Mutilate, Garrote and Ambush
            if (lvl >= 10 &&
                (baseId == BACKSTAB_1 || baseId == MUTILATE_1 || baseId == MUTILATE_DAMAGE_MAINHAND_1 ||
                baseId == MUTILATE_DAMAGE_OFFHAND_1 || baseId == GARROTE_1 || baseId == AMBUSH_1))
                pctbonus += 0.2f;
            //Aggression: 15% damage bonus for Sinister Strike, Backstab and Eviscerate
            if ((GetSpec() == BOT_SPEC_ROGUE_COMBAT) &&
                lvl >= 25 && (baseId == SINISTER_STRIKE_1 || baseId == BACKSTAB_1 || baseId == EVISCERATE_1))
                pctbonus += 0.15f;
            //Blood Spatter: 30% bonus damage for Rupture and Garrote
            if (lvl >= 15 && (baseId == RUPTURE_1 || baseId == GARROTE_1))
                pctbonus += 0.3f;
            //Vile Poisons: 20% damage bonus for Poisons and Envenom
            if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x10012000) || (spellInfo->SpellFamilyFlags[1] & 0x18)))
                pctbonus += 0.2f;
            //Serrated Blades part 2: 30% bonus damage for Rupture
            if (lvl >= 20 && baseId == RUPTURE_1)
                pctbonus += 0.3f;
            //Surprise Attacks: 10% bonus damage for Sinister Strike, Backstab, Shiv, Hemmorhage and Gouge
            if ((GetSpec() == BOT_SPEC_ROGUE_COMBAT) &&
                lvl >= 50 && (baseId == SINISTER_STRIKE_1 || baseId == BACKSTAB_1 ||
                /*baseId == SHIV_1 || */baseId == HEMORRHAGE_1 || baseId == GOUGE_1))
                pctbonus += 0.1f;
            //Blade Twisting: 10% bonus damage for Sinister Strike and Backstab
            if ((GetSpec() == BOT_SPEC_ROGUE_COMBAT) && lvl >= 35 && (baseId == SINISTER_STRIKE_1 || baseId == BACKSTAB_1))
                pctbonus += 0.1f;
            //Sinister Calling: 10% bonus percentage damage for Backstab and Hemorrhage
            //We add bonus damage pct because SpellMods are not handled
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) && lvl >= 45 && (baseId == BACKSTAB_1 || baseId == HEMORRHAGE_1))
                pctbonus += 0.1f;
            //Glyph of Fan of Knives: 20% bonus damage for Fan of Knives
            if (lvl >= 80 && baseId == FAN_OF_KNIVES_1)
                pctbonus += 0.2f;

            //Glyph of Sinister Strike: 50% chance to add 1 cp on crit
            if (baseId == SINISTER_STRIKE_1)
                glyphSSProc = iscrit && lvl >= 15 && urand(1,100) <= 50;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            int32 flatbonus = 0;
            float pctbonus = 0.0f;

            //100% mods
            //Glyph of Blade Flurry: -100% cost for Blade Flurry
            if (lvl >= 30 && baseId == BLADE_FLURRY_1)
                pctbonus += 1.0f;

            //percent mods
            //Dirty Tricks: -50% cost for Blind and Sap
            if (lvl >= 15 && (baseId == BLIND_1 || baseId == SAP_1))
                pctbonus += 0.5f;

            //flat mods
            //Improved Expose Armor: -10 energy cost for Expose Armor
            if (lvl >= 20 && baseId == EXPOSE_ARMOR_1)
                flatbonus += 10;
            //Improved Sinister Strike: -5 energy cost for Sinister Strike
            if (lvl >= 10 && baseId == SINISTER_STRIKE_1)
                flatbonus += 5;
            //Dirty Deeds part 1: -20 energy cost for Cheap Shot and Garrote
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) && lvl >= 30 && (baseId == CHEAP_SHOT_1 || baseId == GARROTE_1))
                flatbonus += 20;
            //Filthy Tricks part 2: -10 energy cost for Tricks of the Trade, Distract and Shadowstep
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) &&
                lvl >= 50 && (baseId == TRICKS_OF_THE_TRADE_1 || baseId == DISTRACT_1 || baseId == SHADOWSTEP_1))
                flatbonus += 10;
            //Slaugher from the Shadows part 1: -20 energy cost for Backstab and Ambush
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) && lvl >= 55 && (baseId == BACKSTAB_1 || baseId == AMBUSH_1))
                flatbonus += 20;
            //Slaugher from the Shadows part 2: -5 energy cost for Hemorrhage
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) && lvl >= 55 && baseId == HEMORRHAGE_1)
                flatbonus += 5;
            //Glyph of Feint: -20 energy cost for Feint
            if (lvl >= 16 && baseId == FEINT_1)
                flatbonus += 20;
            //Glyph of Gouge: -15 energy cost for Gouge
            if (lvl >= 15 && baseId == GOUGE_1)
                flatbonus += 15;
            //Glyph of Mutilate: -5 energy cost for Mutilate
            if (lvl >= 50 && baseId == MUTILATE_1)
                flatbonus += 5;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus)) - flatbonus;
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const override
        {
            //casttime is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            //float pctbonus = 0.0f;

            //100% mods
            //Improved Slam: -100% cast time for Slam
            //if (lvl >= 40 && spellId == GetSpell(SLAM_1) && me->HasAura(BLOODSURGE_BUFF))
            //    timebonus += casttime;

            //flat mods
            //Glyph of Pick Lock: 100% cast time for Pick Lock (reduced for bots)
            if (lvl >= 16 && baseId == PICK_LOCK_1)
                timebonus += 4000;

            casttime = std::max<int32>(casttime - timebonus, 0);
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Intensify Rage: -33% cooldown for Bloodrage, Berserker Rage, Recklessness and Death Wish
            //if (lvl >= 40 &&
            //    (spellId == GetSpell(BLOODRAGE_1) || spellId == GetSpell(BERSERKERRAGE_1) ||
            //    spellId == GetSpell(RECKLESSNESS_1) || spellId == GetSpell(DEATHWISH_1)))
            //    pctbonus += 0.33f;

            //flat mods
            //Elusiveness part 2: -60 sec cooldown for Blind
            if (lvl >= 20 && baseId == BLIND_1)
                timebonus += 60000;
            //Elusiveness part 3: -30 sec cooldown for Cloak of Shadows
            if (lvl >= 20 && baseId == CLOAK_OF_SHADOWS_1)
                timebonus += 30000;
            //Filthy Tricks part 1: -10 sec cooldown for Tricks of the Trade, Distract and Shadowstep
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) &&
                lvl >= 50 && (baseId == TRICKS_OF_THE_TRADE_1 || baseId == DISTRACT_1 || baseId == SHADOWSTEP_1))
                timebonus += 10000;
            //Filthy Tricks part 3: -3 min cooldown for Preparation
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) && lvl >= 50 && baseId == PREPARATION_1)
                timebonus += 180000;
            //Glyph of Killing Spree: -45 sec cooldown for Killing Spree
            if (lvl >= 60 && baseId == KILLING_SPREE_1)
                timebonus += 45000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //Endurance: -1 min cooldown for Sprint and Evasion
            if (lvl >= 20 && (baseId == SPRINT_1 || baseId == EVASION_1))
                timebonus += 60000;
            //Elusiveness part 1: -60 sec cooldown for Vanish
            if (lvl >= 20 && baseId == VANISH_1)
                timebonus += 60000;
            //Camouflage part 2: -6 sec cooldown for Stealth
            if (lvl >= 15 && baseId == STEALTH_1)
                timebonus += 6000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* /*spellInfo*/, float& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float timebonus = 0.0f;
            float pctbonus = 0.0f;

            //Unrelenting Assault (part 1, special): -0.5 sec global cooldown for Overpower and Revenge (not for tanks)
            //if (lvl >= 50 && !IsTank() && (spellId == GetSpell(OVERPOWER_1) || spellId == GetSpell(REVENGE_1)))
            //    timebonus += 500.f;

            cooldown = (cooldown * (1.0f - pctbonus)) - timebonus;
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* /*spellInfo*/, float& radius) const override
        {
            //uint32 spellId = spellInfo->Id;
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Booming Voice
            //if (lvl >= 10 && ((spellInfo->SpellFamilyFlags[0] & 0x30000) || (spellInfo->SpellFamilyFlags[1] & 0x80)))
            //    pctbonus += 1.0f;

            //flat mods
            //Glyph of Thunder Clap
            //if (spellInfo->SpellFamilyFlags[0] & 0x80)
            //    flatbonus += 4.f;

            radius = radius * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Booming Voice
            //if (lvl >= 10 && ((spellInfo->SpellFamilyFlags[0] & 0x30000) || (spellInfo->SpellFamilyFlags[1] & 0x80)))
            //    pctbonus += 1.0f;

            //flat mods
            //Throwing Specialization: + 4 yd range for Deadly Throw
            if ((GetSpec() == BOT_SPEC_ROGUE_COMBAT) && lvl >= 45 && baseId == DEADLY_THROW_1)
                flatbonus += 4.f;
            //Dirty Tricks: + 5 yd range for Blind and Sap
            if (lvl >= 15 && (baseId == BLIND_1 || baseId == SAP_1))
                flatbonus += 5.f;
            //Glyph of Ambush: + 5 yd range for Ambush
            if (/*lvl >= 18 && */baseId == AMBUSH_1)
                flatbonus += 5.f;
            if (baseId == DISARM_TRAP_1)
                flatbonus += 10.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellMaxTargetsMods(SpellInfo const* /*spellInfo*/, uint32& targets) const override
        {
            uint32 bonusTargets = 0;

            //Improved Revenge: +1 target (actually 2 in dbc)
            //if (spellInfo->SpellFamilyFlags[0] & 0x400)
            //    bonusTargets += 1;

            targets = targets + bonusTargets;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Thistle Tea: cooldown
            if (baseId == THISTLE_TEA)
                SetSpellCooldown(THISTLE_TEA, 300000); //5 min (item cd)

            //Remorseless Attacks: proc consume buff
            if (AuraEffect const* remo = me->GetAuraEffect(REMORSELESS_ATTACKS_BUFF, 0, me->GetGUID()))
                if (remo->IsAffectingSpell(spellInfo))
                    me->RemoveAurasDueToSpell(REMORSELESS_ATTACKS_BUFF);

            //Relentless Strikes
            if (spellInfo->NeedsComboPoints() && comboPoints)
            {
                if (lvl >= 10)
                {
                    if (irand(1,100) <= 20 * comboPoints)
                    {
                        me->CastSpell(me, RELENTLESS_STRIKES_EFFECT, true);
                        //TC_LOG_ERROR("entities.player", "rogue_bot CP SPEND1: RS proc!");
                    }
                }
            }

            //Item enchant
            //We don't know which item is targeted
            //Actually it is mh, then oh
            if (baseId == CRIPPLING_POISON_1 || baseId == INSTANT_POISON_1 || baseId == DEADLY_POISON_1 ||
                baseId == WOUND_POISON_1 || baseId == ANESTHETIC_POISON_1 || baseId == MIND_NUMBING_POISON_1)
            {
                //We set duration to 2 seconds to prevent exploiting unequip mechanic
                //to get enchanted weapons for player (for non-shaman bots it won't work)
                uint32 slot = TEMP_ENCHANTMENT_SLOT;
                uint32 duration = 2 * IN_MILLISECONDS;
                uint32 charges = 0;
                uint32 enchant_id = spellInfo->_effects[0].MiscValue;
                //SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                Item* mh = GetEquips(BOT_SLOT_MAINHAND);
                Item* oh = GetEquips(BOT_SLOT_OFFHAND);
                Item* item = nullptr;
                uint8 itemSlot = 0;

                if (mh && !mh->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT)/* && mh->IsFitToSpellRequirements(spellInfo)*/)
                {
                    item = mh;
                    itemSlot = BOT_SLOT_MAINHAND;
                }
                else if (oh && !oh->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT)/* && oh->IsFitToSpellRequirements(spellInfo)*/)
                {
                    item = oh;
                    itemSlot = BOT_SLOT_OFFHAND;
                }
                else
                    ASSERT(false, "rogue bot attempted to enchant his weapons but cannot find a weapon to apply it!");

                if (!IAmFree())
                    master->GetSession()->SendEnchantmentLog(me->GetGUID(), me->GetGUID(), item->GetEntry(), enchant_id);

                item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_ID_OFFSET, enchant_id);
                item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_DURATION_OFFSET, duration);
                item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_CHARGES_OFFSET, charges);
                ApplyItemEnchantment(item, TEMP_ENCHANTMENT_SLOT, itemSlot);
                if (itemSlot == BOT_SLOT_MAINHAND)
                    mhEnchantExpireTimer = ITEM_ENCHANTMENT_EXPIRE_TIMER;
                else if (itemSlot == BOT_SLOT_OFFHAND)
                    ohEnchantExpireTimer = ITEM_ENCHANTMENT_EXPIRE_TIMER;
                //GC_Timer = 1500; //needed
            }
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;

            //Vanish: handle stealth add
            if (baseId == VANISH_TRIGGERED_1 || baseId == VANISH_TRIGGERED_2 || baseId == VANISH_TRIGGERED_3)
            {
                if (!me->GetAuraEffect(SPELL_AURA_MOD_SHAPESHIFT, SPELLFAMILY_ROGUE, 0x400000, 0x0, 0x0))
                {
                    //SetSpellCooldown(STEALTH_1, 0);
                    me->CastSpell(me, STEALTH_1, true);
                }
            }
            //Cheat Death: assume resilience bonus
            if (baseId == CHEATING_DEATH_BUFF)
            {
                if (AuraEffect* chea = me->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_GENERIC, 2109, 0))
                {
                    chea->ChangeAmount(-100);
                }
            }
            //Camouflage part 1: +15% speed while stealthed
            if (baseId == STEALTH_1 && me->GetLevel() >= 15)
            {
                if (AuraEffect* stea = me->GetAuraEffect(spell->Id, 2))
                {
                    stea->ChangeAmount(stea->GetAmount() + 15);
                }
            }

            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Cold Blood: handle proc
            if (AuraEffect const* bloo = me->GetAuraEffect(COLD_BLOOD_1, 0, me->GetGUID()))
                if (bloo->IsAffectingSpell(spell))
                    me->RemoveAurasDueToSpell(COLD_BLOOD_1);

            //Combo point generating from effects
            if (baseId == SEAL_FATE_EFFECT || baseId == RUTHLESSNESS_EFFECT ||
                baseId == SETUP_EFFECT || baseId == INITIATIVE_EFFECT || baseId == HONOR_AMONG_THIEVES_EFFECT)
            {
                ++comboPoints;
                //TC_LOG_ERROR("entities.player", "rogue_bot CP GEN2: {} adds 1, now {}", spell->SpellName[0], uint32(comboPoints));
                if (comboPoints > 5)
                {
                    comboPoints = 5;
                    //TC_LOG_ERROR("entities.player", "rogue_bot CP NOR2: now {}", uint32(comboPoints));
                }
            }
            //Combo point generating from spells
            if (baseId == SINISTER_STRIKE_1 || baseId == BACKSTAB_1 || baseId == MUTILATE_1 ||
                baseId == GOUGE_1 || baseId == HEMORRHAGE_1 || baseId == GHOSTLY_STRIKE_1 ||
                baseId == RIPOSTE_1 || baseId == PREMEDITATION_1 ||
                baseId == AMBUSH_1 || baseId == GARROTE_1 || baseId == CHEAP_SHOT_1/* || baseId == SHIV_1*/)
            {
                (baseId == MUTILATE_1 || baseId == PREMEDITATION_1 || baseId == CHEAP_SHOT_1) ?
                    comboPoints += 2 : ++comboPoints;

                //TC_LOG_ERROR("entities.player", "rogue_bot CP GEN1: {} adds {}, now {}",
                //    spell->SpellName[0], (baseId == MUTILATE_1 || baseId == PREMEDITATION_1 || baseId == CHEAP_SHOT_1) ?
                //    2 : 1, uint32(comboPoints));

                //Glyph of Sinister Strike: handle proc
                if (baseId == SINISTER_STRIKE_1 && glyphSSProc)
                {
                    ++comboPoints;
                    //TC_LOG_ERROR("entities.player", "rogue_bot CP GEN1: glyphSS proc, now {}", uint32(comboPoints));
                }

                if (comboPoints > 5)
                {
                    comboPoints = 5;
                    //TC_LOG_ERROR("entities.player", "rogue_bot CP NOR1: now {}", uint32(comboPoints));
                }
            }
            //if (spellId == EVISCERATE || spellId == KIDNEY_SHOT || spellId == SLICE_DICE || spellId == RUPTURE || spellId == EXPOSE_ARMOR || spellId == ENVENOM)
            //some abilities like relentless strikes require combo points thus tries to proc itself
            else if (spell->NeedsComboPoints() && comboPoints)
            {
                //uint32 tempCP = comboPoints;
                //comboPoints = 0;
                combopointsSpent = true; //envenom problem - cps spent before aura application

                //TC_LOG_ERROR("entities.player", "rogue_bot CP SPEND1: {} to 0", tempCP);

                //Relentless Strikes: moved to OnClassSpellGo (triggered even without hitting the target)

                //Ruthlessness
                if (lvl >= 15)
                {
                    if (urand(1,100) <= 60)
                    {
                        me->CastSpell(target, RUTHLESSNESS_EFFECT, true);
                        //TC_LOG_ERROR("entities.player", "rogue_bot CP SPEND1: RU proc!");
                    }
                }
            }

            //Preparation: handle effect
            if (baseId == PREPARATION_1)
            {
                //TC_LOG_ERROR("entities.player", "rogue_bot Preparation hit!");
                if (GetSpell(EVASION_1))
                    SetSpellCooldown(EVASION_1, 0);
                if (GetSpell(SPRINT_1))
                    SetSpellCooldown(SPRINT_1, 0);
                if (GetSpell(VANISH_1))
                    SetSpellCooldown(VANISH_1, 0);
                if (GetSpell(COLD_BLOOD_1))
                    SetSpellCooldown(COLD_BLOOD_1, 0);
                if (GetSpell(SHADOWSTEP_1))
                    SetSpellCooldown(SHADOWSTEP_1, 0);

                //Glyph of Preparation
                //if (lvl >= 30) // same level as spell itself
                {
                    if (GetSpell(BLADE_FLURRY_1))
                        SetSpellCooldown(BLADE_FLURRY_1, 0);
                    if (GetSpell(DISMANTLE_1))
                        SetSpellCooldown(DISMANTLE_1, 0);
                    if (GetSpell(KICK_1))
                        SetSpellCooldown(KICK_1, 0);
                }
            }

            //Glyph of Garrote
            if (lvl >= 15 && baseId == GARROTE_1)
            {
                if (Aura* garr = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = garr->GetMaxDuration() - 3000;
                    garr->SetDuration(dur);
                    garr->SetMaxDuration(dur);
                    if (AuraEffect* garrEff = garr->GetEffect(0))
                    {
                        garrEff->ChangeAmount(int32(garrEff->GetAmount() * 1.44f)); //not a mistake
                    }
                }
            }
            //Glyph of Deadly Throw
            if (lvl >= 64 && baseId == DEADLY_THROW_1)
            {
                if (AuraEffect* thro = target->GetAuraEffect(spellId, 1, me->GetGUID()))
                {
                    thro->ChangeAmount(thro->GetAmount() - 20);
                }
            }
            //Glyph of Hunger for Blood
            if (lvl >= 60 && baseId == HUNGER_FOR_BLOOD_BUFF)
            {
                if (AuraEffect* hung = me->GetAuraEffect(spellId, 0))
                {
                    hung->ChangeAmount(hung->GetAmount() + 3);
                }
            }
            //Glyph of Cloak of Shadows
            if (lvl >= 66 && baseId == CLOAK_OF_SHADOWS_1)
            {
                if (AuraEffect* cloa = me->GetAuraEffect(spellId, 2))
                {
                    cloa->ChangeAmount(cloa->GetAmount() - 40);
                }
            }
            //Glyph of Sprint
            if (lvl >= 15 && baseId == SPRINT_1)
            {
                if (AuraEffect* spri = me->GetAuraEffect(spellId, 0))
                {
                    spri->ChangeAmount(spri->GetAmount() + 30);
                }
            }
            //Glyph of Vanish
            if (lvl >= 22 && baseId == VANISH_1)
            {
                if (AuraEffect* vani = me->GetAuraEffect(spellId, 2))
                {
                    vani->ChangeAmount(vani->GetAmount() + 30);
                }
            }
            //Glyph of Adrenaline Rush
            if (lvl >= 40 && baseId == ADRENALINE_RUSH_1)
            {
                if (Aura* rush = me->GetAura(spellId))
                {
                    uint32 dur = rush->GetMaxDuration() + 5000;
                    rush->SetDuration(dur);
                    rush->SetMaxDuration(dur);
                }
            }
            //Glyph of Evasion
            if (lvl >= 15 && baseId == EVASION_1)
            {
                if (Aura* evas = me->GetAura(spellId))
                {
                    uint32 dur = evas->GetMaxDuration() + 5000;
                    evas->SetDuration(dur);
                    evas->SetMaxDuration(dur);
                }
            }
            //Glyph of Slice and Dice
            //Improved Slice and Dice
            if (lvl >= 15 && baseId == SLICE_DICE_1)
            {
                if (Aura* dice = me->GetAura(spellId))
                {
                    uint32 dur = dice->GetMaxDuration() + 3000;
                    dur = dur + dur / 2;
                    dice->SetDuration(dur);
                    dice->SetMaxDuration(dur);
                }
            }
            //Glyph of Shadow Dance: 4 sec for bots
            if (lvl >= 60 && baseId == SHADOW_DANCE_1)
            {
                if (Aura* danc = me->GetAura(spellId))
                {
                    uint32 dur = danc->GetMaxDuration() + 4000;
                    danc->SetDuration(dur);
                    danc->SetMaxDuration(dur);
                }
            }
            //Glyph of Rupture
            if (lvl >= 20 && baseId == RUPTURE_1)
            {
                if (Aura* rupt = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = rupt->GetMaxDuration() + 4000;
                    rupt->SetDuration(dur);
                    rupt->SetMaxDuration(dur);
                }
            }
            //Glyph of Expose Armor
            if (lvl >= 15 && baseId == EXPOSE_ARMOR_1)
            {
                if (Aura* expo = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = expo->GetMaxDuration() + 12000;
                    expo->SetDuration(dur);
                    expo->SetMaxDuration(dur);
                }
            }
            //Improved Gouge: Increased duration by 1.5 sec
            if (lvl >= 10 && baseId == GOUGE_1)
            {
                if (Aura* goug = target->GetAura(spellId, me->GetGUID()))
                {
                    int32 duration = goug->GetMaxDuration() + 1500;
                    goug->SetDuration(duration);
                    goug->SetMaxDuration(duration);
                }
            }
            //Glyph of Tricks of Trade
            if (lvl >= 75 && baseId == TRICKS_OF_THE_TRADE_BUFF)
            {
                if (Aura* tric = target->GetAura(spellId, me->GetGUID()))
                {
                    int32 duration = tric->GetMaxDuration() + 4000;
                    tric->SetDuration(duration);
                    tric->SetMaxDuration(duration);
                }
            }
            //Cut to the Chase: Eviscerate and Envenom will refresh Slice and Dice duration as for 5 points
            if (GetSpec() == BOT_SPEC_ROGUE_ASSASINATION && lvl >= 55 && (baseId == EVISCERATE_1 || baseId == ENVENOM_1) && GetSpell(SLICE_DICE_1))
            {
                if (Aura* dice = me->GetAura(GetSpell(SLICE_DICE_1)))
                {
                    int32 duration = 21000 + 3000 + 12000; //base + glyph + improved
                    dice->SetDuration(duration);
                    dice->SetMaxDuration(duration);
                }
            }
            //Waylay
            if ((GetSpec() == BOT_SPEC_ROGUE_SUBTLETY) && lvl >= 45 && (baseId == BACKSTAB_1 || baseId == AMBUSH_1))
                me->CastSpell(target, WAYLAY_DEBUFF, true);

            //Stun: move behind
            if (baseId == CHEAP_SHOT_1 || baseId == KIDNEY_SHOT_1 || baseId == GOUGE_1)
                if (target == opponent)
                    MoveBehind(target);

            OnSpellHitTarget(target, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
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

        void CheckAttackState() override
        {
            if (me->GetVictim() && HasRole(BOT_ROLE_DPS) && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) &&
                (me->isAttackReady() || me->isAttackReady(OFF_ATTACK)) &&
                (!me->GetVictim()->GetAuraEffect(SPELL_AURA_MOD_STUN, SPELLFAMILY_ROGUE, 0x8, 0x0, 0x0) &&
                !me->GetVictim()->GetAuraEffect(SPELL_AURA_MOD_CONFUSE, SPELLFAMILY_ROGUE, 0x01000000, 0x0, 0x0)))
                DoMeleeAttackIfReady();
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_COMBO_POINTS:
                    return comboPoints;
                case BOTAI_MISC_ENCHANT_IS_AUTO_MH:
                    return needChooseMHEnchant;
                case BOTAI_MISC_ENCHANT_IS_AUTO_OH:
                    return needChooseOHEnchant;
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH:
                    return mhEnchantExpireTimer;
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH:
                    return ohEnchantExpireTimer;
                case BOTAI_MISC_ENCHANT_CURRENT_MH:
                    return mhEnchant;
                case BOTAI_MISC_ENCHANT_CURRENT_OH:
                    return ohEnchant;
                case BOTAI_MISC_ENCHANT_AVAILABLE_1:
                    return GetSpell(CRIPPLING_POISON_1) ? CRIPPLING_POISON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_2:
                    return GetSpell(INSTANT_POISON_1) ? INSTANT_POISON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_3:
                    return GetSpell(MIND_NUMBING_POISON_1) ? MIND_NUMBING_POISON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_4:
                    return GetSpell(DEADLY_POISON_1) ? DEADLY_POISON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_5:
                    return GetSpell(WOUND_POISON_1) ? WOUND_POISON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_6:
                    return GetSpell(ANESTHETIC_POISON_1) ? ANESTHETIC_POISON_1 : 0;
                default:
                    return 0;
            }
        }

        void SetAIMiscValue(uint32 data, uint32 value) override
        {
            switch (data)
            {
                case BOTAI_MISC_DAGGER_MAINHAND:
                    isdaggerMH = bool(value);
                    break;
                case BOTAI_MISC_DAGGER_OFFHAND:
                    isdaggerOH = bool(value);
                    break;
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH:
                    if (value)
                        mhEnchantExpireTimer = 0;
                    break;
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH:
                    if (value)
                        ohEnchantExpireTimer = 0;
                    break;
                case BOTAI_MISC_ENCHANT_CURRENT_MH:
                    mhEnchant = value;
                    needChooseMHEnchant = value ? false : true;
                    break;
                case BOTAI_MISC_ENCHANT_CURRENT_OH:
                    ohEnchant = value;
                    needChooseOHEnchant = value ? false : true;
                    break;
                default:
                    break;
            }
        }

        void Reset() override
        {
            energy = 0;
            comboPoints = 0;
            combopointsSpent = false;
            glyphSSProc = false;

            mhEnchantExpireTimer = 1;
            ohEnchantExpireTimer = 1;

            DefaultInit();

            mhEnchant = 0;
            ohEnchant = 0;
            needChooseMHEnchant = true;
            needChooseOHEnchant = true;

            //after InitEquips
            Item const* mh = GetEquips(BOT_SLOT_MAINHAND);
            Item const* oh = GetEquips(BOT_SLOT_OFFHAND);
            isdaggerMH = mh && mh->GetTemplate()->Class == ITEM_CLASS_WEAPON && mh->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER;
            isdaggerOH = oh && oh->GetTemplate()->Class == ITEM_CLASS_WEAPON && oh->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER;
        }

        void ReduceCD(uint32 diff) override
        {
            if (mhEnchantExpireTimer > diff)            mhEnchantExpireTimer -= diff;
            if (ohEnchantExpireTimer > diff)            ohEnchantExpireTimer -= diff;
        }

        void InitPowers() override
        {
            //Hack for power
            me->SetPowerType(POWER_ENERGY);

            if (energy)
                me->SetPower(POWER_ENERGY, energy);
            else
                me->SetPower(POWER_ENERGY, me->GetMaxPower(POWER_ENERGY));
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            bool isAssa = GetSpec() == BOT_SPEC_ROGUE_ASSASINATION;
            bool isComb = GetSpec() == BOT_SPEC_ROGUE_COMBAT;
            bool isSubt = GetSpec() == BOT_SPEC_ROGUE_SUBTLETY;

            InitSpellMap(KICK_1);
            //InitSpellMap(EXPOSE_ARMOR_1);
            InitSpellMap(DISMANTLE_1);
            InitSpellMap(FEINT_1);
            InitSpellMap(DISARM_TRAP_1);

            InitSpellMap(BACKSTAB_1);
            InitSpellMap(SINISTER_STRIKE_1);
            InitSpellMap(EVISCERATE_1);
            InitSpellMap(ENVENOM_1);
            InitSpellMap(RUPTURE_1);
            InitSpellMap(DEADLY_THROW_1);
            InitSpellMap(FAN_OF_KNIVES_1);

            InitSpellMap(SPRINT_1);
            InitSpellMap(EVASION_1);
            InitSpellMap(BLIND_1);
            InitSpellMap(VANISH_1);

            InitSpellMap(GOUGE_1);

            InitSpellMap(KIDNEY_SHOT_1);
            InitSpellMap(SLICE_DICE_1);
            InitSpellMap(CLOAK_OF_SHADOWS_1);
            InitSpellMap(TRICKS_OF_THE_TRADE_1);

            InitSpellMap(STEALTH_1);
            //InitSpellMap(SAP_1);
            InitSpellMap(GARROTE_1);
            InitSpellMap(CHEAP_SHOT_1);
            InitSpellMap(AMBUSH_1);

            lvl >= 30 && isAssa ? InitSpellMap(COLD_BLOOD_1) : RemoveSpell(COLD_BLOOD_1);
            lvl >= 50 && isAssa ? InitSpellMap(MUTILATE_1) : RemoveSpell(MUTILATE_1);
            lvl >= 60 && isAssa ? InitSpellMap(HUNGER_FOR_BLOOD_1) : RemoveSpell(HUNGER_FOR_BLOOD_1);

            lvl >= 20 && isComb ? InitSpellMap(RIPOSTE_1) : RemoveSpell(RIPOSTE_1);
            lvl >= 30 && isComb ? InitSpellMap(BLADE_FLURRY_1) : RemoveSpell(BLADE_FLURRY_1);
            lvl >= 40 && isComb ? InitSpellMap(ADRENALINE_RUSH_1) : RemoveSpell(ADRENALINE_RUSH_1);
            lvl >= 60 && isComb ? InitSpellMap(KILLING_SPREE_1) : RemoveSpell(KILLING_SPREE_1);

            lvl >= 20 && isSubt ? InitSpellMap(GHOSTLY_STRIKE_1) : RemoveSpell(GHOSTLY_STRIKE_1);
            lvl >= 30 && isSubt ? InitSpellMap(HEMORRHAGE_1) : RemoveSpell(HEMORRHAGE_1);
            lvl >= 30 && isSubt ? InitSpellMap(PREPARATION_1) : RemoveSpell(PREPARATION_1);
            lvl >= 40 && isSubt ? InitSpellMap(PREMEDITATION_1) : RemoveSpell(PREMEDITATION_1);
            lvl >= 50 && isSubt ? InitSpellMap(SHADOWSTEP_1) : RemoveSpell(SHADOWSTEP_1);
            lvl >= 60 && isSubt ? InitSpellMap(SHADOW_DANCE_1) : RemoveSpell(SHADOW_DANCE_1);

            //InitSpellMap(DISTRACT_1);

            InitSpellMap(CRIPPLING_POISON_1);
            InitSpellMap(INSTANT_POISON_1);
            InitSpellMap(DEADLY_POISON_1);
            InitSpellMap(WOUND_POISON_1);
            InitSpellMap(MIND_NUMBING_POISON_1);
            InitSpellMap(ANESTHETIC_POISON_1);

            lvl >= 10 ? InitSpellMap(THISTLE_TEA) : RemoveSpell(THISTLE_TEA);
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isAssa = GetSpec() == BOT_SPEC_ROGUE_ASSASINATION;
            bool isComb = GetSpec() == BOT_SPEC_ROGUE_COMBAT;
            bool isSubt = GetSpec() == BOT_SPEC_ROGUE_SUBTLETY;

            RefreshAura(REMORSELESS_ATTACKS, level >= 10 ? 1 : 0);
            RefreshAura(VIGOR, level >= 20 ? 1 : 0);
            RefreshAura(QUICK_RECOVERY2, isAssa && level >= 35 ? 1 : 0);
            RefreshAura(QUICK_RECOVERY1, isAssa && level >= 30 && level < 35 ? 1 : 0);
            RefreshAura(IMPROVED_KIDNEY_SHOT, isAssa && level >= 30 ? 1 : 0);
            RefreshAura(FLEET_FOOTED, isAssa && level >= 30 ? 1 : 0);
            RefreshAura(SEAL_FATE5, isAssa && level >= 45 ? 1 : 0);
            RefreshAura(SEAL_FATE4, isAssa && level >= 42 && level < 45 ? 1 : 0);
            RefreshAura(SEAL_FATE3, isAssa && level >= 39 && level < 42 ? 1 : 0);
            RefreshAura(SEAL_FATE2, isAssa && level >= 37 && level < 39 ? 1 : 0);
            RefreshAura(SEAL_FATE1, isAssa && level >= 35 && level < 37 ? 1 : 0);
            RefreshAura(MURDER, isAssa && level >= 35 ? 1 : 0);
            RefreshAura(DEADLY_BREW, isAssa && level >= 40 ? 1 : 0);
            RefreshAura(OVERKILL, isAssa && level >= 40 ? 1 : 0);
            //RefreshAura(FOCUSED_ATTACKS, isAssa && level >= 45 ? 1 : 0);
            RefreshAura(MASTER_POISONER, isAssa && level >= 50 ? 1 : 0);

            RefreshAura(DUAL_WIELD_SPECIALIZATION, level >= 10 ? 1 : 0);
            RefreshAura(IMPROVED_KICK, isComb && level >= 25 ? 1 : 0);
            RefreshAura(IMPROVED_SPRINT, isComb && level >= 25 ? 1 : 0);
            RefreshAura(HACK_AND_SLASH, isComb && level >= 30 ? 1 : 0);
            //RefreshAura(BLADE_TWISTING1, isComb && level >= 35 ? 1 : 0);
            RefreshAura(VITALITY, isComb && level >= 40 ? 1 : 0);
            RefreshAura(NERVES_OF_STEEL, isComb && level >= 40 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY5, isComb && level >= 55 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY4, isComb && level >= 52 && level < 55 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY3, isComb && level >= 49 && level < 52 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY2, isComb && level >= 47 && level < 49 ? 1 : 0);
            RefreshAura(COMBAT_POTENCY1, isComb && level >= 45 && level < 47 ? 1 : 0);
            RefreshAura(THROWING_SPECIALIZATION, isComb && level >= 45 ? 1 : 0);
            //RefreshAura(SAVAGE_COMBAT, isComb && level >= 50 ? 1 : 0);
            RefreshAura(UNFAIR_ADVANTAGE, isComb && level >= 50 ? 1 : 0);
            RefreshAura(SURPRISE_ATTACKS, isComb && level >= 50 ? 1 : 0);
            RefreshAura(PREY_ON_THE_WEAK, isComb && level >= 55 ? 1 : 0);

            RefreshAura(MASTER_OF_DECEPTION, level >= 10 ? 1 : 0);
            RefreshAura(SETUP, isSubt && level >= 25 ? 1 : 0);
            RefreshAura(INITIATIVE, isSubt && level >= 25 ? 1 : 0);
            RefreshAura(DIRTY_DEEDS, isSubt && level >= 30 ? 1 : 0);
            RefreshAura(MASTER_OF_SUBTLETY, isSubt && level >= 35 ? 1 : 0);
            RefreshAura(CHEAT_DEATH, isSubt && level >= 40 ? 1 : 0);
            RefreshAura(ENVELOPING_SHADOWS, isSubt && level >= 40 ? 1 : 0);
            RefreshAura(TURN_THE_TABLES, !IAmFree() && isSubt && level >= 55 ? 1 : 0);
            //RefreshAura(HONOR_AMONG_THIEVES, isSubt && level >= 55 ? 1 : 0);

            RefreshAura(VIGOR_GLADIATOR, level >= 70 ? 1 : 0);

            RefreshAura(GLYPH_BACKSTAB, level >= 15 ? 1 : 0);

            RefreshAura(ROGUE_PASSIVE_DND);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case STEALTH_1:
                case SPRINT_1:
                case VANISH_1:
                case BLADE_FLURRY_1:
                case FAN_OF_KNIVES_1:
                case TRICKS_OF_THE_TRADE_1:
                case PREPARATION_1:
                    return true;
                default:
                    return false;
            }
        }

        float GetBotArmorPenetrationCoef() const override
        {
            float bonus = 0.0f;

            //Serrated Blades part 1
            if (me->GetLevel() >= 20)
                bonus += 9.f;

            //Mace Specialization: 15% armor penetration
            if (me->GetLevel() >= 30)
                if (Item const* weap = GetEquips(BOT_SLOT_MAINHAND))
                    if (weap->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_MACE)
                        bonus += 15.f;

            return bonus + bot_ai::GetBotArmorPenetrationCoef();
        }

        bool HasAbilitiesSpecifics() const override { return true; }
        void FillAbilitiesSpecifics(Player const* player, std::list<std::string> &specList) override
        {
            uint32 textId1, textId2;
            switch (mhEnchant)
            {
                case CRIPPLING_POISON_1:    textId1 = BOT_TEXT_CRIPPLING;   break;
                case INSTANT_POISON_1:      textId1 = BOT_TEXT_INSTANT;     break;
                case DEADLY_POISON_1:       textId1 = BOT_TEXT_DEADLY;      break;
                case WOUND_POISON_1:        textId1 = BOT_TEXT_WOUND;       break;
                case MIND_NUMBING_POISON_1: textId1 = BOT_TEXT_MINDNUMBING; break;
                case ANESTHETIC_POISON_1:   textId1 = BOT_TEXT_ANESTHETIC;  break;
                default:                    textId1 = BOT_TEXT_NOTHING_C;   break;
            }
            switch (ohEnchant)
            {
                case CRIPPLING_POISON_1:    textId2 = BOT_TEXT_CRIPPLING;   break;
                case INSTANT_POISON_1:      textId2 = BOT_TEXT_INSTANT;     break;
                case DEADLY_POISON_1:       textId2 = BOT_TEXT_DEADLY;      break;
                case WOUND_POISON_1:        textId2 = BOT_TEXT_WOUND;       break;
                case MIND_NUMBING_POISON_1: textId2 = BOT_TEXT_MINDNUMBING; break;
                case ANESTHETIC_POISON_1:   textId2 = BOT_TEXT_ANESTHETIC;  break;
                default:                    textId2 = BOT_TEXT_NOTHING_C;   break;
            }
            specList.push_back(LocalizedNpcText(player, BOT_TEXT_SLOT_MH) + ": " + LocalizedNpcText(player, textId1));
            specList.push_back(LocalizedNpcText(player, BOT_TEXT_SLOT_OH) + ": " + LocalizedNpcText(player, textId2));
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Rogue_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Rogue_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &Rogue_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Rogue_spells_support;
        }

    private:
        mutable bool glyphSSProc;
        int32 energy;
        uint8 comboPoints;
        bool combopointsSpent;
        bool isdaggerMH, isdaggerOH;
        uint32 mhEnchantExpireTimer, ohEnchantExpireTimer;
        uint32 mhEnchant, ohEnchant;
        bool needChooseMHEnchant, needChooseOHEnchant;
    };
};

void AddSC_rogue_bot()
{
    new rogue_bot();
}
