#include "bot_ai.h"
#include "botmgr.h"
#include "botspell.h"
#include "bottext.h"
#include "bottraits.h"
#include "Containers.h"
#include "Group.h"
#include "Item.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

#include "Formulas.h"
/*
Warrior NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - 98%
TODO:
*/

enum WarriorBaseSpells
{
    BATTLE_STANCE_1                         = 2457,
    DEFENSIVE_STANCE_1                      = 71,
    BERSERKER_STANCE_1                      = 2458,

    INTIMIDATING_SHOUT_1                    = 5246,
    ENRAGED_REGENERATION_1                  = 55694,
    CHARGE_1                                = 100,
    OVERPOWER_1                             = 7384,
    TAUNT_1                                 = 355,
    BLOODRAGE_1                             = 2687,
    BERSERKER_RAGE_1                        = 18499,
    INTERCEPT_1                             = 20252,
    CLEAVE_1                                = 845,
    HAMSTRING_1                             = 1715,
    INTERVENE_1                             = 3411,
    WHIRLWIND_1                             = 1680,
    BLADESTORM_1                            = 46924,
    BATTLE_SHOUT_1                          = 6673,
    REND_1                                  = 772,
    EXECUTE_1                               = 5308,
    PUMMEL_1                                = 6552,
    BLOODTHIRST_1                           = 23881,
    MORTAL_STRIKE_1                         = 12294,
    SLAM_1                                  = 1464,
    SUNDER_ARMOR_1                          = 7386,
    SWEEPING_STRIKES_1                      = 12328,
    RECKLESSNESS_1                          = 1719,
    RETALIATION_1                           = 20230,
    DEATH_WISH_1                            = 12292,
    VICTORY_RUSH_1                          = 34428,
    THUNDER_CLAP_1                          = 6343,
    LAST_STAND_1                            = 12975,
    REVENGE_1                               = 6572,
    SHIELD_BLOCK_1                          = 2565,
    SHIELD_SLAM_1                           = 23922,
    SPELL_REFLECTION_1                      = 23920,
    DISARM_1                                = 676,
    SHIELD_WALL_1                           = 871,
    SHIELD_BASH_1                           = 72,
    HEROIC_THROW_1                          = 57755,
    CONCUSSION_BLOW_1                       = 12809,
    VIGILANCE_1                             = 50720,
    DEVASTATE_1                             = 20243,
    MOCKING_BLOW_1                          = 694,
    SHOCKWAVE_1                             = 46968,
    PIERCING_HOWL_1                         = 12323,
    HEROIC_STRIKE_1                         = 78,
    CHALLENGING_SHOUT_1                     = 1161,
    COMMANDING_SHOUT_1                      = 469,
    SHATTERING_THROW_1                      = 64382,
    DEMORALIZING_SHOUT_1                    = 1160,
    HEROIC_FURY_1                           = 60970
};
enum WarriorPassives
{
//Talents
    ARMORED_TO_THE_TEETH                    = 61222,//rank 3
    SHIELD_SPECIALIZATION                   = 12727,//rank 5
    DEEP_WOUNDS_1                           = 12834,
    DEEP_WOUNDS_2                           = 12849,
    DEEP_WOUNDS_3                           = 12867,
    BLOOD_CRAZE1                            = 16487,
    BLOOD_CRAZE2                            = 16489,
    BLOOD_CRAZE3                            = 16492,
    TOUGHNESS                               = 12764,//rank 5
    TWO_HANDED_WEAPON_SPECIALIZATION        = 12712,//rank 3
    TASTE_FOR_BLOOD1                        = 56636,
    TASTE_FOR_BLOOD2                        = 56637,
    TASTE_FOR_BLOOD3                        = 56638,
    DUAL_WIELD_SPECIALIZATION               = 23588,//rank 5
    IMPROVED_SPELL_REFLECTION               = 59089,//rank 2
    SWORD_SPEC1                             = 12281,
    SWORD_SPEC2                             = 12812,
    SWORD_SPEC3                             = 12813,
    SWORD_SPEC4                             = 12814,
    SWORD_SPEC5                             = 12815,
    IMPROVED_HAMSTRING                      = 23695,//rank 3
    TRAUMA1                                 = 46854,
    TRAUMA2                                 = 46855,
    FLURRY1                                 = 12319,
    FLURRY2                                 = 12971,
    FLURRY3                                 = 12972,
    FLURRY4                                 = 12973,
    FLURRY5                                 = 12974,
    ONE_HANDED_WEAPON_SPECIALIZATION        = 16542,//rank 5
    SECOND_WIND                             = 29838,//rank 2
    IMPROVED_DEFENSIVE_STANCE               = 29594,//rank 2
    JUGGERNAUGHT                            = 64976,
    FURIOUS_ATTACKS                         = 46911,//rank 2
    SAFEGUARD                               = 46949,//rank 2
    SUDDEN_DEATH                            = 29724,//rank 3
    ENDLESS_RAGE                            = 29623,
    BLOOD_FRENZY                            = 29859,
    RAMPAGE                                 = 29801,
    BLOODSURGE                              = 46915,//rank 3
    WARBRINGER                              = 57499,
    CRITICAL_BLOCK                          = 47296,//rank 3
    WRECKING_CREW                           = 56614,//rank 5
    DAMAGE_SHIELD                           = 58874,//rank 2
//other
    GLYPH_HEROIC_STRIKE                     = 58357,
    GLYPH_REVENGE                           = 58364,
    GLYPH_EXECUTION                         = 58367,
    GLYPH_BLOCKING                          = 58375,
    GLYPH_VIGILANCE                         = 63326,
    GLYPH_DEVASTATE                         = 58388,

    WARRIOR_T10_PROT_4P                     = 70844 //bloodrage absorb
};
enum WarriorSpecial
{
    STANCE_NONE                             = 0,
    STANCE_BATTLE                           = 1,
    STANCE_DEFENSIVE                        = 2,
    STANCE_BERSERKER                        = 3,

    TASTE_FOR_BLOOD_BUFF                    = 60503,
    SWORD_AND_BOARD_BUFF                    = 50227,
    BLOODSURGE_BUFF                         = 46916,//"Slam!"
    JUGGERNAUGHT_BUFF                       = 65156,
    GLYPH_REVENGE_BUFF                      = 58363,
    UNRELENTING_ASSAULT_SPELL               = 64850,
    VICTORIOUS_SPELL                        = 32216,
    REVENGE_STUN_SPELL                      = 12798,
    //SWORD_SPECIALIZATION_TRIGGERED          = 16459,
    VIGILANCE_PROC                          = 50725,
    IMPROVED_BERSERKER_RAGE_EFFECT          = 23691,//rank 2
    UNBRIDLED_WRATH_EFFECT                  = 12964,
    SUNDER_ARMOR_DEBUFF                     = 58567,
    GAG_ORDER_DEBUFF                        = 18498,//silence
    //SUDDEN_DEATH_BUFF                       = 52437,
    BLOODRAGE_PERIODIC_EFFECT               = 29131,

    //VICTORIOUS_STATE_PASSIVE              = 32215,
    BERSERKER_STANCE_PASSIVE                = 7381
};

static  uint32 Warrior_spells_damage_arr[] =
{ BLADESTORM_1, BLOODTHIRST_1, CLEAVE_1, CONCUSSION_BLOW_1, DEVASTATE_1, EXECUTE_1, HEROIC_STRIKE_1, HEROIC_THROW_1,
INTERCEPT_1, MOCKING_BLOW_1, MORTAL_STRIKE_1, OVERPOWER_1, REND_1, RETALIATION_1, REVENGE_1, SHATTERING_THROW_1,
SHIELD_SLAM_1, SHOCKWAVE_1, SLAM_1, THUNDER_CLAP_1, VICTORY_RUSH_1, WHIRLWIND_1 };

static  uint32 Warrior_spells_cc_arr[] =
{ CHARGE_1, INTERCEPT_1, INTIMIDATING_SHOUT_1, CONCUSSION_BLOW_1, DISARM_1, HAMSTRING_1, PIERCING_HOWL_1,
SHIELD_BASH_1, SHOCKWAVE_1 };

static  uint32 Warrior_spells_support_arr[] =
{ BATTLE_SHOUT_1, COMMANDING_SHOUT_1, CHALLENGING_SHOUT_1, DEMORALIZING_SHOUT_1, BERSERKER_RAGE_1, BLOODRAGE_1,
DEATH_WISH_1, ENRAGED_REGENERATION_1, HEROIC_FURY_1, INTERVENE_1, LAST_STAND_1, PUMMEL_1, RECKLESSNESS_1,
RETALIATION_1, SHIELD_BASH_1, SHIELD_BLOCK_1, SHIELD_WALL_1, SPELL_REFLECTION_1, SUNDER_ARMOR_1, SWEEPING_STRIKES_1,
TAUNT_1, VIGILANCE_1 };

static const std::vector<uint32> Warrior_spells_damage(FROM_ARRAY(Warrior_spells_damage_arr));
static const std::vector<uint32> Warrior_spells_cc(FROM_ARRAY(Warrior_spells_cc_arr));
static const std::vector<uint32> Warrior_spells_support(FROM_ARRAY(Warrior_spells_support_arr));

static float rageIncomeMult;
static float rageLossMult;

class warrior_bot : public CreatureScript
{
public:
    warrior_bot() : CreatureScript("warrior_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new warrior_botAI(creature);
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
    struct warrior_botAI : public bot_ai
    {
        warrior_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_WARRIOR;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        uint8 GetBotStance() const override
        {
            if (_inStance(1))
                return WARRIOR_BATTLE_STANCE;
            else if (_inStance(2))
                return WARRIOR_DEFENSIVE_STANCE;
            else if (_inStance(3))
                return WARRIOR_BERSERKER_STANCE;

            return BOT_STANCE_NONE;
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override
        {
            //Victorious State spell
            //only on targets which give xp or honor
            if (u->GetLevel() > Trinity::XP::GetGrayLevel(me->GetLevel()))
                me->CastSpell(me, VICTORIOUS_SPELL, true);

            bot_ai::KilledUnit(u);
        }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        //void modrage(int32 mod, bool set = false)
        //{
        //    if (set && mod < 0)
        //        return;
        //    if (mod < 0 && rage < abs(mod))
        //    {
        //        //debug set rage to 0
        //        mod = 0;
        //        set = true;
        //        return;
        //    }

        //    if (set)
        //        rage = mod ? mod*10 : 0;
        //    else
        //        rage += mod*10;

        //    me->SetPower(POWER_RAGE, rage);
        //}

        void getrage()
        {
            rage = me->GetPower(POWER_RAGE);
            if (me->FindCurrentSpellBySpellId(GetSpell(CLEAVE_1)))
                rage = std::max<int32>(rage - 200, 0);
            else if (me->FindCurrentSpellBySpellId(GetSpell(HEROIC_STRIKE_1)))
                rage = std::max<int32>(rage - rcost(HEROIC_STRIKE_1), 0);
        }

        int32 rcost(uint32 spellId) const
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
                return spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask());
            return 0;
        }

        void BreakCC(uint32 diff) override
        {
            if (IsSpellReady(HEROIC_FURY_1, diff) && Rand() < 55 &&
                (CCed(me, true) || me->HasAuraWithMechanic(1<<MECHANIC_SNARE)))
            {
                if (doCast(me, GetSpell(HEROIC_FURY_1)))
                    return;
            }
            if (IsSpellReady(BERSERKER_RAGE_1, diff) && Rand() < 45 &&
                !me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_WARRIOR, 0x0, 0x20000, 0x0) &&
                /*!me->HasAura(ENRAGED_REGENERATION_1)*/
                me->HasAuraWithMechanic((1<<MECHANIC_FEAR)|(1<<MECHANIC_SAPPED)|(1<<MECHANIC_KNOCKOUT)))
            {
                if (doCast(me, GetSpell(BERSERKER_RAGE_1)))
                    return;
            }
            bot_ai::BreakCC(diff);
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->IsAlive())
            {
                if (ragetimer2 <= diff)
                {
                    ragetimer2 = 3000;
                    //Anger Management
                    if (me->IsInCombat() && me->GetLevel() >= 20)
                    {
                        if (me->GetPower(POWER_RAGE) < 990)
                            me->SetPower(POWER_RAGE, me->GetPower(POWER_RAGE) + uint32(10.f * rageIncomeMult)); //1 rage per 3 sec
                        else
                            me->SetPower(POWER_RAGE, 1000); //max
                    }
                }
                if (ragetimer <= diff)
                {
                    ragetimer = 1500;
                    if (!me->IsInCombat() &&
                        !me->HasAuraTypeWithFamilyFlags(SPELL_AURA_PERIODIC_ENERGIZE, SPELLFAMILY_WARRIOR, 0x100))
                    {
                        if (me->GetPower(POWER_RAGE) > uint32(10.f * rageLossMult))
                            me->SetPower(POWER_RAGE, me->GetPower(POWER_RAGE) - uint32(10.f * rageLossMult)); //-1 rage per 1.5 sec
                        else
                            me->SetPower(POWER_RAGE, 0); //min
                    }
                }
                getrage();
            }

            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            if (IsPotionReady())
            {
                if (GetHealthPCT(me) < 40)
                    DrinkPotion(false);
            }

            CheckRacials(diff);

            CheckShouts(diff);
            CheckVigilance(diff);
            CheckIntervene(diff);
            CheckSpellReflect(diff);

            if (me->IsInCombat())
                CheckShatteringThrow(diff);
            else
                DoNonCombatActions(diff);

            if (IsCasting())
                return;

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
            {
                if (!me->IsInCombat() && stancetimer <= diff && Rand() < 5 && me->getAttackers().empty() && rage <= 250)
                {
                    uint8 mystance = 0;
                    if (IsTank())
                    {
                        if (!_inStance(2))
                            mystance = 2;
                    }
                    else
                        mystance = 1;

                    if (mystance)
                        stanceChange(diff, mystance);
                }
                return;
            }

            CheckUsableItems(diff);

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

            bool const isFury = GetSpec() == BOT_SPEC_WARRIOR_FURY;
            bool const isArms = GetSpec() == BOT_SPEC_WARRIOR_ARMS;

            //Keep stance in combat
            if (stancetimer <= diff && Rand() < 10 + 15 * (me->GetPower(POWER_RAGE) <= 250))
            {
                uint8 mystance;
                if (IsTank())
                    mystance = 2;
                else if (isFury && me->GetLevel() >= 30)
                    mystance = 3;
                else
                    mystance = 1;

                stanceChange(diff, mystance);
            }

            if (IsSpellReady(BLOODRAGE_1, diff, false) && me->IsInCombat() && rage < 600 && Rand() < 20 &&
                !me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_WARRIOR, 0x0, 0x20000, 0x0)
                /*!me->HasAura(ENRAGED_REGENERATION_1)*/)
            {
                if (doCast(me, GetSpell(BLOODRAGE_1)))
                    getrage();
            }

            getrage();

            //SelfHeal
            if (IsSpellReady(ENRAGED_REGENERATION_1, diff) && Rand() < 80 && GetHealthPCT(me) < 40 &&
                rage >= rcost(ENRAGED_REGENERATION_1) && me->HasAuraWithMechanic(1u<<MECHANIC_ENRAGED))
            {
                if (doCast(me, GetSpell(ENRAGED_REGENERATION_1)))
                    return;
            }

            Unit::AttackerSet const& b_attackers = me->getAttackers();
            float dist = me->GetDistance(mytar);

            //FEAR
            if (IsSpellReady(INTIMIDATING_SHOUT_1, diff) && Rand() < 70 && rage >= rcost(INTIMIDATING_SHOUT_1))
            {
                if (mytar->IsNonMeleeSpellCast(false, false, true) && dist < 5 &&
                    mytar->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                {
                    if (doCast(mytar, GetSpell(INTIMIDATING_SHOUT_1)))
                        return;
                }
                Unit::AttackerSet const& m_attackers = master->getAttackers();
                Unit* fearTarget = nullptr;
                uint8 tCount = 0;
                //fear master's attackers
                if (!m_attackers.empty() &&
                    ((master->GetClass() != BOT_CLASS_DEATH_KNIGHT &&
                    master->GetClass() != BOT_CLASS_WARRIOR &&
                    master->GetClass() != BOT_CLASS_PALADIN) ||
                    GetHealthPCT(master) < 70))
                {
                    for (Unit::AttackerSet::const_iterator iter = m_attackers.begin(); iter != m_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetDistance((*iter)) < 7.5f)
                            ++tCount;
                        if (!fearTarget && me->GetDistance((*iter)) < 5)
                            fearTarget = (*iter);
                        if (fearTarget && tCount > 1)
                            break;
                    }
                    if (fearTarget && tCount > 1 && doCast(fearTarget, GetSpell(INTIMIDATING_SHOUT_1)))
                        return;
                }
                //Defend myself
                if (b_attackers.size() > 1 && (!IsTank() || GetHealthPCT(me) < 50))
                {
                    tCount = 0;
                    fearTarget = nullptr;
                    for (Unit::AttackerSet::const_iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetDistance((*iter)) < 7.5f)
                            ++tCount;
                        if (!fearTarget && me->GetDistance((*iter)) < 5)
                            fearTarget = (*iter);
                        if (fearTarget && tCount > 1)
                            break;
                    }
                    if (fearTarget && tCount > 1 && doCast(fearTarget, GetSpell(INTIMIDATING_SHOUT_1)))
                        return;
                }
            }//end FEAR

            //LAST STAND
            if (IsSpellReady(LAST_STAND_1, diff, false) &&
                GetHealthPCT(me) < (30 + 20 * (b_attackers.size() > 1) + 10 * me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)))
            {
                if (doCast(me, GetSpell(LAST_STAND_1)))
                    return;
            }

            Unit const* u = mytar->GetVictim();

            //TAUNT //No GCD
            if (IsSpellReady(TAUNT_1, diff, false) && u && u != me && Rand() < 50 && dist < 30 &&
                mytar->CanHaveThreatList() && !CCed(mytar) && !mytar->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (IsTank() && GetHealthPCT(me) > 67 &&
                (GetHealthPCT(u) < 30 || (IsOffTank() && !IsOffTank(u) && IsPointedOffTankingTarget(mytar)) ||
                (!IsOffTank() && IsOffTank(u) && IsPointedTankingTarget(mytar))))) &&
                ((!IsTankingClass(u->GetClass()) && (GetHealthPCT(u) < 80 || _inStance(2))) || IsTank()) &&
                IsInBotParty(u) &&
                (_inStance(2) || (stancetimer <= diff && stanceChange(diff, 2))))
            {
                if (doCast(mytar, GetSpell(TAUNT_1)))
                    return;
            }
            //TAUNT 2 (distant)
            if (IsSpellReady(TAUNT_1, diff, false) && !IAmFree() && u == me && Rand() < 35 && IsTank() &&
                (IsOffTank() || master->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_TANK_OFF) == 0) &&
                !(me->GetLevel() >= 40 && mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())) &&
                (_inStance(2) || stancetimer <= diff))
            {
                Unit* tUnit = FindDistantTauntTarget();
                if (tUnit && (_inStance(2) || (stancetimer <= diff && stanceChange(diff, 2))))
                {
                    if (doCast(tUnit, GetSpell(TAUNT_1)))
                        return;
                }
            }
            //CHARGE (warbringer)
            if (IsSpellReady(CHARGE_1, diff, false) && !HasRole(BOT_ROLE_RANGED) && Rand() < 70 &&
                !HasBotCommandState(BOT_COMMAND_STAY) &&
                !(IsTank() && mytar->GetTypeId() == TYPEID_UNIT && mytar->ToCreature()->isWorldBoss()) &&
                dist > 8 && dist < CalcSpellMaxRange(CHARGE_1) &&
                ((IsTank() && me->GetLevel() >= 50) ||
                (!me->IsInCombat() && (_inStance(1) || (stancetimer <= diff && stanceChange(diff, 1))))))
            {
                if (doCast(mytar, GetSpell(CHARGE_1)))
                    return;
            }
            //INTERCEPT (warbringer)
            if (IsSpellReady(INTERCEPT_1, diff, false) && !HasRole(BOT_ROLE_RANGED) && HasRole(BOT_ROLE_DPS) &&
                !HasBotCommandState(BOT_COMMAND_STAY) &&
                !(IsTank() && mytar->GetTypeId() == TYPEID_UNIT && mytar->ToCreature()->isWorldBoss()) &&
                //!me->HasUnitState(UNIT_STATE_CHARGING) &&
                !(me->GetMotionMaster()->GetCurrentMovementGenerator() && me->GetMotionMaster()->GetCurrentMovementGenerator()->BaseUnitState == UNIT_STATE_CHARGING) && //not charging
                (me->IsInCombat() || !IsSpellReady(CHARGE_1, diff, false)) &&
                Rand() < 60 && dist > 10 && dist < 25 && !CCed(mytar) && rage >= rcost(INTERCEPT_1) &&
                ((IsTank() && me->GetLevel() >= 50) ||
                (!IsTank() && (_inStance(3) || (stancetimer <= diff && stanceChange(diff, 3))))))
            {
                if (doCast(mytar, GetSpell(INTERCEPT_1)))
                    return;
            }
            //CHALLENGING SHOUT
            if (IsSpellReady(CHALLENGING_SHOUT_1, diff) && Rand() < 40 &&
                !(u == me && me->GetLevel() >= 40 && mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())) &&
                rage >= rcost(CHALLENGING_SHOUT_1))
            {
                if (IsTank())
                {
                    std::list<Unit*> targets;
                    GetNearbyTargetsList(targets, 9.f, 1);
                    uint8 count = 0;
                    for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        if (!((*itr)->GetVictim() && IsTank((*itr)->GetVictim())))
                            if (++count > 1)
                                break;
                    }
                    if (count > 1 && doCast(me, GetSpell(CHALLENGING_SHOUT_1)))
                        return;
                }
                if (u && u != me && !IsSpellReady(TAUNT_1, diff, false) && !IsTank(u) && !CCed(mytar) && dist < 9 &&
                    (!IsTankingClass(u->GetClass()) || IsTank()) && IsInBotParty(u))
                {
                    if (doCast(me, GetSpell(CHALLENGING_SHOUT_1)))
                        return;
                }
            }

            bool can_do_normal = CanAffectVictimAny(mytar, SPELL_SCHOOL_NORMAL);

            //BERSERKER RAGE (for rage)
            if (IsSpellReady(BERSERKER_RAGE_1, diff) && Rand() < 15 && rage < 80/* && me->GetLevel() >= 35*/)
            {
                if (doCast(me, GetSpell(BERSERKER_RAGE_1)))
                    return;
            }
            //MOCKING BLOW
            if (IsSpellReady(MOCKING_BLOW_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && Rand() < 70 && u && u != me &&
                !IsTank(u) && dist < 5 && rage >= rcost(MOCKING_BLOW_1) &&
                !CCed(mytar) && (!IsTankingClass(u->GetClass()) || IsTank()) && IsInBotParty(u) &&
                (_inStance(4) || (stancetimer <= diff && stanceChange(diff, 4))))
            {
                if (doCast(mytar, GetSpell(MOCKING_BLOW_1)))
                    return;
            }
            //SHIELD SLAM
            if (IsSpellReady(SHIELD_SLAM_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && CanBlock() &&
                (_inStance(4) || stancetimer <= diff) && dist <= 5 && rage >= rcost(SHIELD_SLAM_1) &&
                Rand() < (75 + 200*(me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_WARRIOR, 2780, 0) != nullptr)
                /*me->HasAura(SWORD_AND_BOARD_BUFF)*/))
            {
                //check Shield Block
                if (IsSpellReady(SHIELD_BLOCK_1, diff, false) && (_inStance(2) || (IsTank() && stanceChange(diff, 2))))
                {
                    if (doCast(me, GetSpell(SHIELD_BLOCK_1)))
                    {}
                }
                if (_inStance(4) || stanceChange(diff, 4))
                {
                    if (doCast(mytar, GetSpell(SHIELD_SLAM_1)))
                        return;
                }
            }
            //SHIELD BLOCK
            if (IsSpellReady(SHIELD_BLOCK_1, diff, false) && CanBlock() && Rand() < 70 &&
                (_inStance(2) || stancetimer <= diff) &&
                ((u == me && dist < 8) || (!b_attackers.empty() && me->GetDistance2d(*(b_attackers.begin())) < 8)) &&
                GetHealthPCT(me) < (65 + 8 * uint8(b_attackers.size())))
            {
                if ((_inStance(2) || stanceChange(diff, 2)) &&
                    doCast(me, GetSpell(SHIELD_BLOCK_1)))
                    return;
            }
            //SHOCKWAVE - frontal cone
            if (IsSpellReady(SHOCKWAVE_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && dist < 8.f && !CCed(mytar) &&
                rage >= rcost(SHOCKWAVE_1) && Rand() < (70 + 70 * mytar->IsNonMeleeSpellCast(false)) &&
                me->HasInArc(float(M_PI)/2, mytar) && mytar->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
            {
                if (doCast(me, GetSpell(SHOCKWAVE_1)))
                    return;
            }
            //HEROIC THROW
            if (IsSpellReady(HEROIC_THROW_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && dist < 30 &&
                (mytar->GetTypeId() == TYPEID_UNIT || dist > 6) &&
                Rand() < (20 - 15 * CanBlock() + 90 * mytar->IsNonMeleeSpellCast(false,false,true)))
            {
                if (doCast(mytar, GetSpell(HEROIC_THROW_1)))
                    return;
            }
            //THUNDER CLAP
            if (IsSpellReady(THUNDER_CLAP_1, diff) && HasRole(BOT_ROLE_DPS) && !isFury && Rand() < 40 &&
                (_inStance(4) || stancetimer <= diff) && dist < 7.5f && rage >= rcost(THUNDER_CLAP_1) &&
                ((IsTank() && b_attackers.size() > 1) ||
                (mytar->GetHealth() > me->GetMaxHealth() / 2 &&
                !mytar->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_MELEE_HASTE, SPELLFAMILY_WARRIOR, 0x80)) ||
                FindSplashTarget(7.5f, mytar, 15.f)))
            {
                if (_inStance(4) || (me->GetLevel() >= 20 && stanceChange(diff, 4)))
                {
                    if (doCast(me, GetSpell(THUNDER_CLAP_1)))
                        return;
                }
            }
            //REVENGE
            if (IsSpellReady(REVENGE_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && IsTank() && me->HasReactive(REACTIVE_DEFENSE) &&
                Rand() < 150 && (_inStance(2) || stancetimer <= diff) && dist < 5 && rage >= rcost(REVENGE_1))
            {
                if (_inStance(2) || stanceChange(diff, 2))
                {
                    if (doCast(mytar, GetSpell(REVENGE_1)))
                        return;
                }
            }
            //CONCUSSION BLOW
            if (IsSpellReady(CONCUSSION_BLOW_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !CCed(mytar) &&
                dist < 5 && rage >= rcost(CONCUSSION_BLOW_1) &&
                mytar->GetDiminishing(DIMINISHING_STUN) <= DIMINISHING_LEVEL_2 &&
                Rand() < (30 + 60 * mytar->IsNonMeleeSpellCast(false,false,true)))
            {
                if (doCast(mytar, GetSpell(CONCUSSION_BLOW_1)))
                    return;
            }

            MoveBehind(mytar);

            //SHIELD BASH - shared cd with pummel
            if (IsSpellReady(SHIELD_BASH_1, diff, false) && can_do_normal && CanBlock() && Rand() < 80 &&
                (_inStance(4) || stancetimer <= diff) &&
                dist < 5 && rage >= rcost(SHIELD_BASH_1) && mytar->IsNonMeleeSpellCast(false,false,true))
            {
                if ((_inStance(4) || stanceChange(diff, 4)) &&
                    doCast(mytar, GetSpell(SHIELD_BASH_1)))
                    return;
            }
            //PUMMEL - shared cd with shield bash
            if (IsSpellReady(PUMMEL_1, diff, false) && can_do_normal && !IsTank() && !CanBlock() && Rand() < 80 &&
                dist < 5 && (_inStance(3) || stancetimer <= diff) &&
                rage >= rcost(PUMMEL_1) && mytar->IsNonMeleeSpellCast(false,false,true))
            {
                if ((_inStance(3) || stanceChange(diff, 3)) &&
                    doCast(mytar, GetSpell(PUMMEL_1)))
                    return;
            }
            //HAMSTRING
            if (IsSpellReady(HAMSTRING_1, diff) && can_do_normal && Rand() < 70 && (_inStance(5) || stancetimer <= diff) &&
                (!GetSpell(PIERCING_HOWL_1) || mytar->GetTypeId() == TYPEID_PLAYER) &&
                (mytar->isMoving() || mytar->GetTypeId() == TYPEID_PLAYER) && dist < 5 && rage >= rcost(HAMSTRING_1) &&
                !mytar->HasAuraWithMechanic(1<<MECHANIC_SNARE))
            {
                if (_inStance(5) || (me->GetLevel() >= 15 && stanceChange(diff, 5)))
                    if (doCast(mytar, GetSpell(HAMSTRING_1)))
                        return;
            }
            //PIERCING HOWL
            if (IsSpellReady(PIERCING_HOWL_1, diff) && can_do_normal && mytar->isMoving() && Rand() < 80 &&
                dist < 9 && rage >= rcost(PIERCING_HOWL_1) && !mytar->HasAuraWithMechanic(1<<MECHANIC_SNARE))
            {
                if (doCast(me, GetSpell(PIERCING_HOWL_1)))
                    return;
            }
            //DISARM
            if (IsSpellReady(DISARM_1, diff) && can_do_normal && dist < 5 && (_inStance(2) || stancetimer <= diff) &&
                Rand() < (35 + 55*mytar->HasAuraType(SPELL_AURA_ALLOW_ONLY_ABILITY)) &&
                !mytar->HasAuraType(SPELL_AURA_MOD_DISARM) &&
                mytar->GetHealth() > me->GetMaxHealth() / 8 * (1 + mytar->getAttackers().size()) &&
                rage >= rcost(DISARM_1))
            {
                //check weapons
                bool hasWeapon = true;
                if (mytar->GetTypeId() == TYPEID_UNIT && !mytar->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID))
                    hasWeapon = false;
                else if (Player const* pla = mytar->ToPlayer())
                    if (!pla->GetWeaponForAttack(BASE_ATTACK) || !pla->IsUseEquipedWeapon(true))
                        hasWeapon = false;

                if (hasWeapon && (_inStance(2) || stanceChange(diff, 2)) &&
                    doCast(mytar, GetSpell(DISARM_1)))
                    return;
            }
            //DEMORALIZING SHOUT
            if (IsSpellReady(DEMORALIZING_SHOUT_1, diff) && can_do_normal && Rand() < 15 + 25 * IsTank() && dist < 10 &&
                (mytar->GetClass() == CLASS_WARRIOR || mytar->GetClass() == CLASS_ROGUE ||
                (mytar->GetTypeId() == TYPEID_UNIT && mytar->ToCreature()->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL)) &&
                mytar->GetHealth() > me->GetMaxHealth() / 8 * (1 + mytar->getAttackers().size()) &&
                rage >= rcost(DEMORALIZING_SHOUT_1) &&
                !mytar->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_ATTACK_POWER, SPELLFAMILY_WARRIOR, 0x20000))
            {
                if (doCast(me, GetSpell(DEMORALIZING_SHOUT_1)))
                    return;
            }

            //UBERS
            //Shield Wall
            if (IsSpellReady(SHIELD_WALL_1, diff, false) && CanBlock() &&
                GetHealthPCT(me) < (30 + 4 * b_attackers.size() + 20 * (mytar->GetTypeId() == TYPEID_UNIT && mytar->ToCreature()->isWorldBoss())) &&
                (_inStance(2) || stanceChange(diff, 2)))
            {
                if (doCast(me, GetSpell(SHIELD_WALL_1)))
                    return;
            }
            //Retaliation
            if (IsSpellReady(RETALIATION_1, diff) && HasRole(BOT_ROLE_DPS) && !CanBlock() && Rand() < 40 &&
                !me->HasAuraType(SPELL_AURA_MOD_DISARM) && b_attackers.size() > 4 &&
                (_inStance(1) || stanceChange(diff, 1)))
            {
                if (doCast(me, GetSpell(RETALIATION_1)))
                    return;
            }
            //Recklessness
            if (IsSpellReady(RECKLESSNESS_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !CanBlock() && !IsTank() && Rand() < 60 &&
                GetHealthPCT(me) > 50 && (_inStance(3) || stancetimer <= diff) && b_attackers.size() < 2 &&
                (mytar->GetHealth() > me->GetHealth()/2 * (1 + mytar->getAttackers().size()) || mytar->IsControlledByPlayer()) &&
                !me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_WARRIOR, 0x0, 0x20000, 0x0)
                /*!me->HasAura(ENRAGED_REGENERATION_1)*/ &&
                (_inStance(3) || stanceChange(diff, 3)))
            {
                if (doCast(me, GetSpell(RECKLESSNESS_1)))
                    return;
            }
            //DEATHWISH
            if (IsSpellReady(DEATH_WISH_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !IsTank() && Rand() < 70 &&
                dist < 15 && rage >= rcost(DEATH_WISH_1) &&
                mytar->GetHealth() > me->GetHealth()/4 * (1 + mytar->getAttackers().size()) &&
                !me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_WARRIOR, 0x0, 0x20000, 0x0)
                /*!me->HasAura(ENRAGED_REGENERATION_1)*/)
            {
                if (doCast(me, GetSpell(DEATH_WISH_1)))
                    return;
            }

            //VICTORY RUSH
            if (IsSpellReady(VICTORY_RUSH_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && Rand() < 70 && dist < 5 && _inStance(5) &&
                me->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_WARRIOR, 0x0, 0x40000, 0x0))
            {
                if (doCast(mytar, GetSpell(VICTORY_RUSH_1)))
                    return;
            }
            //DEVASTATE - only with shield
            if (IsSpellReady(DEVASTATE_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && CanBlock() && Rand() < 100 &&
                dist < 5 && rage >= rcost(DEVASTATE_1))
            {
                if (doCast(mytar, GetSpell(DEVASTATE_1)))
                    return;
            }
            //SUNDER ARMOR
            if (IsSpellReady(SUNDER_ARMOR_1, diff) && !IAmFree() && can_do_normal && dist < 5 && Rand() < 45 &&
                (IsTank() ? (mytar->GetHealth() > me->GetMaxHealth()) : (Rand() < 25 && mytar->GetHealth() > me->GetMaxHealth() * 2)) &&
                (!HasRole(BOT_ROLE_DPS) || !CanBlock() || !GetSpell(DEVASTATE_1)) &&
                (IsTank() || master->GetBotMgr()->HasBotWithSpec(BOT_SPEC_WARRIOR_PROTECTION, false)) && rage >= rcost(SUNDER_ARMOR_1))
            {
                AuraEffect const* sunder = mytar->GetAuraEffect(SUNDER_ARMOR_DEBUFF, 0);
                if ((!sunder || sunder->GetBase()->GetStackAmount() < 5 || sunder->GetBase()->GetDuration() < 20000) &&
                    doCast(mytar, GetSpell(SUNDER_ARMOR_1)))
                    return;
            }
            //SWEEPING STRIKES //no GCD
            if (IsSpellReady(SWEEPING_STRIKES_1, diff, false) && HasRole(BOT_ROLE_DPS) && !IsTank() && Rand() < 65 &&
                (_inStance(5) || stancetimer <= diff) && rage >= rcost(SWEEPING_STRIKES_1) &&
                (b_attackers.size() > 1 || FindSplashTarget(7, mytar)))
            {
                if ((_inStance(5) || stanceChange(diff, 5)) &&
                    doCast(me, GetSpell(SWEEPING_STRIKES_1)))
                    getrage();
            }
            //REND
            if (IsSpellReady(REND_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && Rand() < 80 &&
                mytar->GetHealth() > me->GetMaxHealth() / 4 * (1 + mytar->getAttackers().size()) &&
                (isArms || mytar->GetClass() == CLASS_ROGUE || mytar->GetShapeshiftForm() == FORM_CAT) &&
                dist < 5 && rage >= rcost(REND_1) && mytar->GetCreatureType() != CREATURE_TYPE_MECHANICAL &&
                !(mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->GetCreatureTemplate()->MechanicImmuneMask & (1<<(MECHANIC_BLEED-1)))) &&
                !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARRIOR, 0x20, 0x0, 0x0, me->GetGUID()) &&
                (_inStance(4) || (me->GetLevel() >= 15 && stanceChange(diff, 4))))
            {
                if (doCast(mytar, GetSpell(REND_1)))
                    return;
            }
            //BLOODTHIRST
            if (IsSpellReady(BLOODTHIRST_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) &&
                dist < 5 && rage >= rcost(BLOODTHIRST_1))
            {
                if (doCast(mytar, GetSpell(BLOODTHIRST_1)))
                    return;
            }
            //MORTAL STRIKE
            if (IsSpellReady(MORTAL_STRIKE_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !CanBlock() &&
                dist < 5 && rage >= rcost(MORTAL_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(MORTAL_STRIKE_1)))
                    return;
            }
            //OVERPOWER
            if (IsSpellReady(OVERPOWER_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !IsTank() && (!isFury || rage < 250) &&
                (_inStance(1) || stancetimer <= diff) && dist < 5 && rage >= rcost(OVERPOWER_1) &&
                (me->HasReactive(REACTIVE_OVERPOWER) ||
                me->GetAuraEffect(SPELL_AURA_ABILITY_IGNORE_AURASTATE, SPELLFAMILY_WARRIOR, 2961, 0)
                /*me->HasAura(TASTE_FOR_BLOOD_BUFF)*/))
            {
                if (_inStance(1) || (me->GetLevel() >= 15 && stanceChange(diff, 1)))
                {
                    if (doCast(mytar, GetSpell(OVERPOWER_1)))
                        return;
                }
            }
            //BLADESTORM
            if (IsSpellReady(BLADESTORM_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !IsTank() && !CanBlock() &&
               dist < 10 && rage >= rcost(BLADESTORM_1) &&
               (b_attackers.size() > 1 || mytar->GetHealth() > me->GetHealth() / 3 * (1 + mytar->getAttackers().size()) ||
               mytar->IsControlledByPlayer()) &&
               (Rand() < 50 || me->HasAuraTypeWithFamilyFlags(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_WARRIOR, 0x10)
               /*me->HasAura(RECKLESSNESS_1)*/) &&
               (me->GetMap()->IsDungeon() || mytar->GetMaxHealth() > me->GetMaxHealth() * 8 || CCed(mytar, true) || mytar->HasAuraWithMechanic(1<<MECHANIC_SNARE)))
            {
                if (doCast(me, GetSpell(BLADESTORM_1)))
                    return;
            }
            //WHIRLWIND
            if (IsSpellReady(WHIRLWIND_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !IsTank() && !CanBlock() && Rand() < 80 &&
                (isFury || mytar->IsControlledByPlayer() || me->GetLevel() < 60 || !me->GetMap()->IsDungeon()) &&
                (_inStance(3) || stancetimer <= diff) && dist < 6.f &&
                rage >= rcost(WHIRLWIND_1) && (isFury || rage >= 500 || FindSplashTarget(7.f, mytar, 15.f)))
            {
                if ((_inStance(3) || stanceChange(diff, 3)) &&
                    doCast(me, GetSpell(WHIRLWIND_1)))
                    return;
            }
            //EXECUTE
            if (IsSpellReady(EXECUTE_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !IsTank() && Rand() < 110 &&
                (isFury || !me->GetMap()->IsRaid()) &&
                (mytar->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT) ||
                me->GetAuraEffect(SPELL_AURA_ABILITY_IGNORE_AURASTATE, SPELLFAMILY_WARRIOR, 0x0, 0x2000000, 0x0)) &&
                dist < 5 && rage >= rcost(EXECUTE_1) &&
                (_inStance(5) || (stancetimer <= diff && stanceChange(diff, 5))))
            {
                if (doCast(mytar, GetSpell(EXECUTE_1)))
                    return;
            }
            //SLAM only with improved, has SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS
            if (IsSpellReady(SLAM_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && !IsTank() && !CanBlock() &&
                me->GetLevel() >= 40 && dist < 5 && rage >= rcost(SLAM_1) &&
                ((isArms && !mytar->isMoving() && me->getAttackTimer(BASE_ATTACK) > 500) ||
                me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_WARRIOR, 0x0, 0x1000000, 0x0))
                /*me->HasAura(BLOODSURGE_BUFF)*/)
            {
                if (doCast(mytar, GetSpell(SLAM_1)))
                    return;
            }

            //skip if already have cleave of heroic strike casted
            if (me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                return;

            //CLEAVE //no GCD
            if (IsSpellReady(CLEAVE_1, diff, false) && can_do_normal && HasRole(BOT_ROLE_DPS) && Rand() < 70 &&
                dist < 5 && (!IsTank() || rage >= 500) && rage >= rcost(CLEAVE_1) && FindSplashTarget())
            {
                if (doCast(mytar, GetSpell(CLEAVE_1)))
                    return;
            }
            //HEROIC STRIKE
            if (IsSpellReady(HEROIC_STRIKE_1, diff, false) && can_do_normal && HasRole(BOT_ROLE_DPS) && Rand() < 55 && rage >= 350 &&
                dist < 5 && (isFury || IsTank() || rage >= 650) && rage >= rcost(HEROIC_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(HEROIC_STRIKE_1)))
                    return;
            }
        }

        void CheckShouts(uint32 diff)
        {
            if (shoutCheckTimer > diff || GC_Timer > diff || Rand() > 35 || (IAmFree() && !IsWanderer()) || me->IsMounted() || IsCasting() ||
                (rage < rcost(BATTLE_SHOUT_1) && !IsSpellReady(BLOODRAGE_1, diff, false)))
                return;

            shoutCheckTimer = urand(3000, 5000);

            if (IAmFree())
            {
                if (GetSpell(BATTLE_SHOUT_1) &&
                    !me->GetAuraEffect(SPELL_AURA_MOD_RANGED_ATTACK_POWER, SPELLFAMILY_WARRIOR, 0x10000, 0x0, 0x0) &&
                    !me->GetAuraEffect(SPELL_AURA_MOD_RANGED_ATTACK_POWER, SPELLFAMILY_PALADIN, 0x2, 0x0, 0x0))
                {
                    if (rage < rcost(BATTLE_SHOUT_1))
                    {
                        if (IsSpellReady(BLOODRAGE_1, diff, false))
                        {
                            if (doCast(me, GetSpell(BLOODRAGE_1)))
                            {}
                            else
                                return;
                        }
                        else
                            return;
                    }
                    if (doCast(me, GetSpell(BATTLE_SHOUT_1)))
                        return;
                }

                return;
            }

            if (me->GetDistance(master) > 30)
                return;

            //ignore Blood Pact
            AuraEffect const* bs = me->GetAuraEffect(SPELL_AURA_MOD_RANGED_ATTACK_POWER, SPELLFAMILY_WARRIOR, 0x10000, 0x0, 0x0);
            AuraEffect const* cs = me->GetAuraEffect(SPELL_AURA_230, SPELLFAMILY_WARRIOR, 0x0, 0x80, 0x0);
            AuraEffect const* bm = me->GetAuraEffect(SPELL_AURA_MOD_RANGED_ATTACK_POWER, SPELLFAMILY_PALADIN, 0x2, 0x0, 0x0);

            bool hasBS = bs && (bs->GetBase()->GetDuration() >= 30000 || bs->GetBase()->GetCasterGUID() != me->GetGUID()) && bs->GetBase()->GetId() >= GetSpell(BATTLE_SHOUT_1);
            bool hasCS = cs && (cs->GetBase()->GetDuration() >= 30000 || cs->GetBase()->GetCasterGUID() != me->GetGUID()) && cs->GetBase()->GetId() >= GetSpell(COMMANDING_SHOUT_1);
            bool hasBM = bm != nullptr;

            if (hasCS && (hasBS || hasBM))
                return;

            bool battleshout = !hasBM && !hasBS && (!cs || cs->GetBase()->GetCasterGUID() != me->GetGUID()) &&
                (!IsTank(me) || !GetSpell(COMMANDING_SHOUT_1)) && GetSpell(BATTLE_SHOUT_1);
            bool commandingshout = !hasCS && (!bs || bs->GetBase()->GetCasterGUID() != me->GetGUID()) &&
                GetSpell(COMMANDING_SHOUT_1);

            if (battleshout && !hasCS && !HasRole(BOT_ROLE_DPS) && GetSpell(COMMANDING_SHOUT_1))
            {
                battleshout = false;
                commandingshout = true;
            }

            if (battleshout || commandingshout)
            {
                if (rage < rcost(BATTLE_SHOUT_1) && IsSpellReady(BLOODRAGE_1, diff, false) &&
                    doCast(me, GetSpell(BLOODRAGE_1)))
                    getrage();

                if ((battleshout && doCast(me, GetSpell(BATTLE_SHOUT_1))) ||
                    (commandingshout && doCast(me, GetSpell(COMMANDING_SHOUT_1))))
                    return;
            }
        }

        void CheckVigilance(uint32 diff)
        {
            if (vigiCheckTimer > diff || Rand() > 30 || !IsSpellReady(VIGILANCE_1, diff) || me->IsInCombat() || me->IsMounted() || IsCasting())
                return;

            vigiCheckTimer = urand(1500, 3000);
            uint32 VIGILANCE = GetSpell(VIGILANCE_1);

            if (Unit* u = vigilanceTargetGuid ? ObjectAccessor::GetUnit(*me, vigilanceTargetGuid) : nullptr)
            {
                bool myVig = u->HasAura(VIGILANCE, me->GetGUID());
                if (!IsTank() || !myVig)
                {
                    if (myVig)
                        u->RemoveAura(VIGILANCE, me->GetGUID(), 0, AURA_REMOVE_BY_EXPIRE);
                    vigilanceTargetGuid = ObjectGuid::Empty;
                }
                return;
            }
            else if (vigilanceTargetGuid)
                vigilanceTargetGuid = ObjectGuid::Empty;

            if (!IAmFree() && !IsTank())
                return;

            Unit* target = nullptr;
            if (Group const* gr = GetGroup())
            {
                std::set<Unit*> targets;
                for (uint8 i = 0; i < 4 && !targets.empty(); ++i)
                {
                    for (Unit* member : BotMgr::GetAllGroupMembers(gr))
                    {
                        if (!(!(i & 1) ? member->IsPlayer() : member->IsNPCBot()) || me->GetMap() != member->FindMap() ||
                            !member->IsAlive() || me->GetDistance(member) > 30 ||
                            (member->IsNPCBot() && member->ToCreature()->IsTempBot()) ||
                            (i < 2 && !(i == 0 ? IsTankingClass(member->GetClass()) : IsTank(member))) ||
                            (i == 3 && !member->ToCreature()->GetBotAI()->HasRole(BOT_ROLE_DPS)) ||
                            member->HasAura(VIGILANCE) || member->HasAura(DAMAGE_REDUCTION))
                            continue;
                        targets.insert(member);
                    }
                }

                if (!targets.empty())
                    target = targets.size() == 1 ? *targets.begin() : Trinity::Containers::SelectRandomContainerElement(targets);
            }

            if (!target && !IAmFree() && master->IsAlive() && me->IsWithinDistInMap(master, 30) && !master->HasAura(VIGILANCE))
                target = master;

            if (target && doCast(target, VIGILANCE))
                return;
        }

        void CheckIntervene(uint32 diff)
        {
            if (!IsSpellReady(INTERVENE_1, diff, false) || HasBotCommandState(BOT_COMMAND_STAY) || me->IsMounted() ||
                Rand() > (IsTank() ? 40 : 80) || rage < rcost(INTERVENE_1) || IsCasting() ||
                !(_inStance(2) || stancetimer <= diff || (GetSpec() == BOT_SPEC_WARRIOR_PROTECTION && me->GetLevel() >= 50)))
                return;

            Unit* target = nullptr;
            if (!me->GetVictim() && master->getAttackers().empty() && master->isMoving())
            {
                float mydist = me->GetDistance(master);
                if (mydist < 25 && mydist > 18)
                    target = master;
            }

            Group const* gr = GetGroup();
            if (!target && !gr)
            {
                if (GetHealthPCT(master) < 95 && !master->getAttackers().empty() &&
                    me->getAttackers().size() <= master->getAttackers().size())
                {
                    float mydist = me->GetDistance(master);
                    if (mydist < 25 && mydist > 8)
                        target = master;
                }
            }
            if (!target && gr && (!IsTank() || !me->GetVictim()))
            {
                std::set<Unit*> targets;
                for (Unit* member : BotMgr::GetAllGroupMembers(gr))
                {
                    if (me->GetMap() == member->FindMap() && member->IsAlive() && GetHealthPCT(member) <= 70 &&
                        !member->HasAuraType(SPELL_AURA_ADD_CASTER_HIT_TRIGGER) &&
                        member->getAttackers().size() >= me->getAttackers().size() &&
                        !(member->IsNPCBot() && member->ToCreature()->IsTempBot()))
                    {
                        float dist = me->GetDistance(member);
                        if (dist < 25 && dist > 8)
                            targets.insert(member);
                    }
                }
                if (!targets.empty())
                    target = targets.size() == 1u ? *targets.begin() : Trinity::Containers::SelectRandomContainerElement(targets);
            }

            if (target && (_inStance(2) || (GetSpec() == BOT_SPEC_WARRIOR_PROTECTION && me->GetLevel() >= 50) || stanceChange(diff, 2)) &&
                doCast(target, GetSpell(INTERVENE_1)))
                return;

            SetSpellCooldown(INTERVENE_1, 500); //fail
        }

        void CheckSpellReflect(uint32 diff)
        {
            if (!IsSpellReady(SPELL_REFLECTION_1, diff, false) || me->IsMounted() || IsCasting() ||
                !CanBlock() || !(_inStance(4) || stancetimer <= diff) ||
                rage < rcost(SPELL_REFLECTION_1) || Rand() > 75)
                return;

            //use first match (covers most cases)
            if (Unit const* target = FindCastingTarget(70))
            {
                if (Spell const* spell = target->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                {
                    if (spell->GetTimer() < 500/*(4500 - 4000 * (target->GetTypeId() == TYPEID_PLAYER))*/ &&
                        !spell->GetSpellInfo()->IsChanneled() &&
                        spell->GetSpellInfo()->DmgClass == SPELL_DAMAGE_CLASS_MAGIC &&
                        !(spell->GetSpellInfo()->Attributes & (SPELL_ATTR0_ABILITY|SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)) &&
                        !(spell->GetSpellInfo()->AttributesEx & SPELL_ATTR1_CANT_BE_REFLECTED) &&
                        !spell->GetSpellInfo()->IsPassive() && !spell->GetSpellInfo()->IsPositive())
                    {
                        if (Unit const* u = spell->m_targets.GetUnitTarget())
                        {
                            if ((IAmFree() ? (u == me) : (master->GetGroup() && master->GetGroup()->IsMember(spell->m_targets.GetObjectTargetGUID()))) &&
                                me->GetTotalAuraModifier(SPELL_AURA_REFLECT_SPELLS) < 100)
                            {
                                if ((_inStance(4) || (stancetimer <= diff && stanceChange(diff, 4))) &&
                                    doCast(me, GetSpell(SPELL_REFLECTION_1)))
                                    return;
                            }
                        }
                    }
                }
            }

            SetSpellCooldown(SPELL_REFLECTION_1, urand(250, 500)); //fail
        }

        void CheckShatteringThrow(uint32 diff)
        {
            if (!IsSpellReady(SHATTERING_THROW_1, diff) || shatterCheckTimer > diff ||
                !(_inStance(1) || stancetimer <= diff) || rage < rcost(SHATTERING_THROW_1) ||
                me->getAttackers().size() > 2 || Rand() > 50)
                return;

            shatterCheckTimer = urand(500, 1000);

            Unit* unit = FindImmunityShieldDispelTarget();
            if (unit && me->GetDistance(unit) < 30 && (_inStance(1) || (stancetimer <= diff && stanceChange(diff, 1))))
                if (doCast(unit, GetSpell(SHATTERING_THROW_1)))
                    return;
        }

        bool stanceChange(uint32 diff, uint8 stance)
        {
            if (stancetimer > diff)
                return false;

            if (stance == 5)
                stance = (me->GetLevel() >= 30 && !IsTank()) ? 3 : 1;
            else if (stance == 4)
                stance = me->GetLevel() >= 10 && IsTank() ? 2 : 1;

            if (stance == 2 && me->GetLevel() < 10)
                return false;
            if (stance == 3 && me->GetLevel() < 30)
                return false;

            if (_inStance(stance))
                return true;

            rage = me->GetPower(POWER_RAGE);
            switch (stance)
            {
                case 1:
                    return doCast(me, BATTLE_STANCE_1);
                case 2:
                    return doCast(me, DEFENSIVE_STANCE_1);
                case 3:
                    return doCast(me, BERSERKER_STANCE_1);
                default:
                    return false;
            }
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& damageinfo) const override
        {
            float pctbonus = 1.0f;

            if (damageinfo.HitOutCome == MELEE_HIT_CRIT)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Poleaxe Specialization: 5% additional critical damage for all attacks
                if (GetSpec() == BOT_SPEC_WARRIOR_ARMS && me->GetLevel() >= 30)
                    if (Item const* weap = GetEquips(uint8(damageinfo.AttackType)))
                        if (ItemTemplate const* proto = weap->GetTemplate())
                            if (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE || proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 ||
                                proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
                                pctbonus *= 1.025f;
            }

            damageinfo.Damages[0].Damage *= pctbonus;
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask /*schoolMask*/, WeaponAttackType attackType) const override
        {
            if (spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
                return;

            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Recklessness: 100% additional critical chance for damaging abilities
            if (AuraEffect const* eff = me->GetAuraEffect(RECKLESSNESS_1, EFFECT_0))
                if (eff->IsAffectingSpell(spellInfo))
                    crit_chance += 100.f;
            //Juggernaught: 25 additional critical chance for Mortal Strike and Slam
            if (lvl >= 45 && (baseId == SLAM_1 || baseId == MORTAL_STRIKE_1))
                if (AuraEffect const* jugg = me->GetAuraEffect(JUGGERNAUGHT_BUFF, 0))
                    if (jugg->IsAffectingSpell(spellInfo))
                        crit_chance += 25.f;

            //Poleaxe Specialization: 5% additional critical chance for all attacks
            if (GetSpec() == BOT_SPEC_WARRIOR_ARMS && lvl >= 30)
                if (Item const* weap = GetEquips(uint8(attackType)))
                    if (ItemTemplate const* proto = weap->GetTemplate())
                        if (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE || proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 ||
                            proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
                            crit_chance += 5.f;

            //Incite: 15% additional critical chance for Cleave, Heroic Strike and Thunder Clap
            if (((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION && lvl >= 15) ||
                ((GetSpec() == BOT_SPEC_WARRIOR_ARMS || GetSpec() == BOT_SPEC_WARRIOR_FURY) && lvl >= 75)) &&
                (baseId == CLEAVE_1 || baseId == HEROIC_STRIKE_1 || baseId == THUNDER_CLAP_1))
                crit_chance += 15.f;
            //Improved Overpower: 50% additional critical chance for Overpower
            if ((GetSpec() == BOT_SPEC_WARRIOR_ARMS) && lvl >= 20 && baseId == OVERPOWER_1)
                crit_chance += 50.f;
            //Critical Block: 15% additional critical chance for Shield Slam
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) &&
                lvl >= 50 && baseId == SHIELD_SLAM_1)
                crit_chance += 15.f;
            //Sword and Board: 15% additional critical chance for Devastate
            if (lvl >= 55 && baseId == DEVASTATE_1)
                crit_chance += 15.f;

            //Glypg of Victory Rush: 30% additional critical chance for Victory Rush
            if (lvl >= 15 && baseId == VICTORY_RUSH_1)
                crit_chance += 30.f;

            //Warrior T8 Protection Bonus (id: 64933): 10% additional critical chance for Devastate (tanks only)
            if (lvl >= 78 && baseId == DEVASTATE_1)
                crit_chance += 10.f;
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType attackType, bool iscrit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            // apply bonus damage mods
            float pctbonus = 1.0f;
            if (iscrit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Impale: 20% crit damage bonus for all abilities
                if (lvl >= 20)
                    pctbonus *= 1.1f;
                //Poleaxe Specialization: 5% additional critical damage for all attacks
                if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) && lvl >= 30)
                    if (Item const* weap = GetEquips(uint8(attackType)))
                        if (ItemTemplate const* proto = weap->GetTemplate())
                            if (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE || proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 ||
                                proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
                                pctbonus *= 1.025f;
            }

            //Improved Shield Slam (id: 38407): 10% bonus damage for Shield Slam
            //if (lvl >= 50 && baseId == SHIELD_SLAM_1)
            //    pctbonus *= 1.1f;
            //Shield Slam Damage Up (id: 60173): 10% bonus damage for Shield Slam
            //if (lvl >= 70 && baseId == SHIELD_SLAM_1)
            //    pctbonus *= 1.1f;

            //Improved Rend: 20% bonus damage for Rend
            if (lvl >= 10 && baseId == REND_1)
                pctbonus *= 1.2f;
            //Improved Thunder Clap (part 2): 30% bonus damage for Thunder Clap
            if (lvl >= 10 && baseId == THUNDER_CLAP_1)
                pctbonus *= 1.3f;
            //Improved Revenge (part 1): 60% bonus damage for Revenge
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) && lvl >= 20 && baseId == REVENGE_1)
                pctbonus *= 1.6f;
            //Gag Order (part 2): 10% bonus damage for Shield Slam
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) && lvl >= 30 && baseId == SHIELD_SLAM_1)
                pctbonus *= 1.1f;
            //Improved Whirlwind: 20% bonus damage for Whirlwind
            if ((GetSpec() == BOT_SPEC_WARRIOR_FURY) && lvl >= 40 && baseId == WHIRLWIND_1)
                pctbonus *= 1.2f;
            //Improved Mortal Strike (part 1): 10% bonus damage for Mortal Strike
            if (lvl >= 45 && baseId == MORTAL_STRIKE_1)
                pctbonus *= 1.1f;
            //Unrelenting Assault (part 2): 20% bonus damage for Overpower and Revenge
            if ((GetSpec() == BOT_SPEC_WARRIOR_ARMS) &&
                lvl >= 45 && (baseId == OVERPOWER_1 || baseId == REVENGE_1))
                pctbonus *= 1.2f;
            //Unending Fury: 10% bonus damage for Whirlwind, Slam and Bloodthirst
            if ((GetSpec() == BOT_SPEC_WARRIOR_FURY) &&
                lvl >= 55 && (baseId == WHIRLWIND_1 || baseId == SLAM_1 || baseId == BLOODTHIRST_1))
                pctbonus *= 1.1f;

            //Glyph of Mocking Blow: 25% bonus damage for Mocking Blow
            if (lvl >= 16 && baseId == MOCKING_BLOW_1)
                pctbonus *= 1.25f;
            //Glyph of Mortal Strike: 10% bonus damage for Mortal Strike
            if (lvl >= 40 && baseId == MORTAL_STRIKE_1)
                pctbonus *= 1.1f;

            //Warrior T9 Protection 2P Bonus (id: 67269): 5% bonus damage for Devastate
            if (lvl >= 77 && baseId == DEVASTATE_1)
                pctbonus *= 1.05f;
            //Warrior T10 Protection 2P Bonus (id: 70843): 20% bonus damage for Shield Slam and Shockwave
            if (lvl >= 78 && (baseId == SHIELD_SLAM_1 || baseId == SHOCKWAVE_1))
                pctbonus *= 1.2f;

            //Improved Cleave: 120% increased '!bonus damage!' done by Cleave (flat mod)
            if ((GetSpec() == BOT_SPEC_WARRIOR_FURY) && lvl >= 25 && baseId == CLEAVE_1)
            {
                float bp = spellInfo->_effects[EFFECT_0].BasePoints; //SPELL_EFFECT_WEAPON_DAMAGE (values: 15 - 222)
                fdamage += bp * 1.2;
            }

            damage = int32(fdamage * pctbonus);
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            //float pctbonus = 1.0f;

            //100% mods
            //Sword and Board: -100% rage cost for Shield Slam
            if (baseId == SHIELD_SLAM_1 && me->HasAura(SWORD_AND_BOARD_BUFF))
                fcost = 0;

            //Glyph of Bloodrage: -100% health cost for Bloodrage
            if (lvl >= 15 && baseId == BLOODRAGE_1)
                fcost = 0;
            //Glyph of Revenge: -100% rage cost for Heroic Strike
            if (lvl >= 15 && baseId == HEROIC_STRIKE_1 && me->HasAura(GLYPH_REVENGE_BUFF))
                fcost = 0;
            //Glyph of Sweeping Strikes: -100% rage cost for Sweeping Strikes
            if (lvl >= 30 && baseId == SWEEPING_STRIKES_1)
                fcost = 0;

            //flat mods
            //Improved Hamstring (id: 24428): -2 rage cost for Hamstring
            if (lvl >= 25 && baseId == HAMSTRING_1)
                fcost -= 20;
            //Bloodthirst and Mortal Strike Discount (id: 37535): -5 rage cost for Bloodthirst and Mortal Strike
            if (lvl >= 40 && (baseId == BLOODTHIRST_1 || baseId == MORTAL_STRIKE_1))
                fcost -= 50;

            //Improved Heroic Strike: -3 rage cost for Heroic Strike
            if (lvl >= 10 && baseId == HEROIC_STRIKE_1)
                fcost -= 30;
            //Improved Thunder Clap (part 1): -4 rage cost for Thunder Clap
            if (lvl >= 10 && baseId == THUNDER_CLAP_1)
                fcost -= 40;
            //Improved Execute: -5 rage cost for Execute
            if ((GetSpec() == BOT_SPEC_WARRIOR_FURY) &&
                lvl >= 25 && baseId == EXECUTE_1)
                fcost -= 50;
            //Puncture: -3 rage cost for Sunder Armor and Devastate
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) &&
                lvl >= 25 && (baseId == SUNDER_ARMOR_1 || baseId == DEVASTATE_1))
                fcost -= 30;
            //Focused Rage: -3 rage cost for all offensive abilities (using rage)
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) &&
                lvl >= 40 && ((spellInfo->SpellFamilyFlags[0] & 0x6E6E4EEE) || (spellInfo->SpellFamilyFlags[1] & 0x40E664)))
                fcost -= 30;

            //Glyph of Resonating Power: -5 rage cost for Thunder Clap
            if (lvl >= 15 && baseId == THUNDER_CLAP_1)
                fcost -= 50;
            //Glyph of Shockwave: -3 rage cost for Shockwave
            if (lvl >= 60 && baseId == SHOCKWAVE_1)
                fcost -= 30;

            //cost can be < 0
            cost = int32(fcost/* * pctbonus*/);
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const override
        {
            //casttime is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            //int32 timebonus = 0;
            //float pctbonus = 0.0f;

            //100% mods
            //Bloodsurge: -100% cast time for Slam
            if (baseId == SLAM_1 && me->HasAura(BLOODSURGE_BUFF))
                casttime = 0;

            //flat mods
            //Improved Slam: -1.0 sec cast time for Slam
            if ((GetSpec() == BOT_SPEC_WARRIOR_ARMS) &&
                lvl >= 40 && baseId == SLAM_1)
                casttime -= 1000;

            casttime = std::max<int32>(casttime, 0);
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //pct mods
            //Intensify Rage: -33% cooldown for Bloodrage, Berserker Rage, Recklessness and Death Wish
            if ((GetSpec() == BOT_SPEC_WARRIOR_FURY) && lvl >= 40 &&
                (baseId == BLOODRAGE_1 || baseId == BERSERKER_RAGE_1 || baseId == RECKLESSNESS_1 || baseId == DEATH_WISH_1))
                pctbonus *= 0.67f;

            //flat mods
            //zzzOLDImproved Challenging Shout (id: 12327): -2 min cooldown for Challenging Shout (tanks only)
            if (lvl >= 30 && IsTank() && baseId == CHALLENGING_SHOUT_1)
                cooldown -= 120000;

            //Shield Mastery (part 2): -20 sec cooldown for Shield Block
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) &&
                lvl >= 20 && baseId == SHIELD_BLOCK_1)
                cooldown -= 20000;
            //Improved Disciplines: -60 sec cooldown for Shield Wall, Retaliation and Recklessness
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) &&
                lvl >= 35 && (baseId == SHIELD_WALL_1 || baseId == RETALIATION_1 || baseId == RECKLESSNESS_1))
                cooldown -= 60000;

            //Glyph of Bladestorm: -15 sec cooldown for Bladestorm
            if (lvl >= 60 && baseId == BLADESTORM_1)
                cooldown -= 15000;
            //Glyph of Spell Reflection: -1 sec cooldown for Spell Reflection
            if (lvl >= 64 && baseId == SPELL_REFLECTION_1)
                cooldown -= 1000;

            cooldown = std::max<float>(cooldown * pctbonus, 0.f);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //pct bonuses
            //Glyph of Rapid Charge: -7% cooldown for Charge
            if (lvl >= 15 && baseId == CHARGE_1)
                pctbonus *= 0.93f;

            //flat bonuses
            //Improved Disarm part 1: -20 sec cooldown for Disarm
            if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) &&
                lvl >= 25 && baseId == DISARM_1)
                cooldown -= 20000;
            //Improved Intercept: -10 sec cooldown for Intercept
            if ((GetSpec() == BOT_SPEC_WARRIOR_FURY) &&
                lvl >= 30 && baseId == INTERCEPT_1)
                cooldown -= 10000;
            //Improved Mortal Strike (part 2): -1 sec cooldown for Mortal Strike
            if (lvl >= 45 && baseId == MORTAL_STRIKE_1)
                cooldown -= 1000;
            //Unrelenting Assault (part 1): -4 sec cooldown for Overpower and Revenge
            if ((GetSpec() == BOT_SPEC_WARRIOR_ARMS) &&
                lvl >= 45 && (baseId == OVERPOWER_1 || baseId == REVENGE_1))
                cooldown -= 4000;

            //Glyph of Last Stand: -1 min cooldown for Last Stand
            if (lvl >= 20 && baseId == LAST_STAND_1)
                cooldown -= 60000;
            //Glyph of Whirlwind: -2 sec cooldown for Whirlwind
            if (lvl >= 36 && baseId == WHIRLWIND_1)
                cooldown -= 2000;

            //Warrior T9 2P Bonus (id: 67269): -2 sec cooldown for Taunt (tanks only)
            if (lvl >= 80 && IsTank() && baseId == TAUNT_1)
                cooldown -= 2000;

            cooldown = std::max<float>(cooldown * pctbonus, 0.f);
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();

            //Unrelenting Assault (part 1, special): -0.5 sec global cooldown for Overpower and Revenge
            if ((GetSpec() == BOT_SPEC_WARRIOR_ARMS) &&
                lvl >= 45 && (baseId == OVERPOWER_1 || baseId == REVENGE_1))
                cooldown -= 500.f;
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //pct mods
            //Booming Voice part 1 (doubled for bots)
            if (lvl >= 10 && ((spellInfo->SpellFamilyFlags[0] & 0x30000) || (spellInfo->SpellFamilyFlags[1] & 0x80)))
                pctbonus *= 2.0f; //1.5f

            //flat mods
            //Glyph of Thunder Clap (doubled for tanks)
            if (lvl >= 15 && (spellInfo->SpellFamilyFlags[0] & 0x80))
                radius += IsTank() ? 4.f : 2.f;

            radius = radius * pctbonus;
        }

        void ApplyClassSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //pct mods
            //Holy Reach: +20% range for Holy Spells
            //if (lvl >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x100080))
            //    pctbonus *= 1.2f;

            //flat mods
            //Glyph of Charge: +5 yd range for Charge
            if (baseId == CHARGE_1 && lvl >= 15)
                maxrange += 5.f;

            maxrange = maxrange * pctbonus;
        }

        void ApplyClassSpellMaxTargetsMods(SpellInfo const* spellInfo, uint32& targets) const override
        {
            //uint32 bonusTargets = 0;
            uint8 lvl = me->GetLevel();

            //Improved Revenge: +1 target (actually 2 in dbc)
            if (lvl >= 20 && (spellInfo->SpellFamilyFlags[0] & 0x400))
                targets += 1;

            //Glyph of Sunder Armor: +1 target
            if (lvl >= 15 && (spellInfo->SpellFamilyFlags[0] & 0x4000))
                targets += 1;
            //Glyph of Cleaving: +1 target
            if (lvl >= 20 && (spellInfo->SpellFamilyFlags[0] & 0x400000))
            {
                targets += 1;
                //double for non-tanks
                if (!IsTank())
                    targets += 1;
            }
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //Improved Rend: 20% increased effect
            if (baseId == REND_1 && effIndex == EFFECT_0 && lvl >= 10)
                pctbonus *= 1.2f;
            //Improved Bloodrage: 50% increased effect
            if ((baseId == BLOODRAGE_1 || baseId == BLOODRAGE_PERIODIC_EFFECT) && effIndex == EFFECT_0 && lvl >= 10)
                pctbonus *= 1.5f;
            //Improved Charge: +10 rage generated
            if (baseId == CHARGE_1 && effIndex == EFFECT_1 && lvl >= 15)
                value += 100.f;
            //Glyph of Bloodthirst: +100% healing
            if (baseId == BLOODTHIRST_1 && effIndex == EFFECT_1 && lvl >= 40)
                pctbonus *= 2.0f;

            value = value * pctbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == LAST_STAND_1 && !IAmFree())
                ReportSpellCast(baseId, LocalizedNpcText(master, BOT_TEXT__USED), master);
            if (baseId == SHIELD_WALL_1 && !IAmFree())
                ReportSpellCast(baseId, LocalizedNpcText(master, BOT_TEXT__USED), master);
            if (baseId == ENRAGED_REGENERATION_1 && !IAmFree())
                ReportSpellCast(baseId, LocalizedNpcText(master, BOT_TEXT__USED), master);

            if (baseId == SLAM_1)
                me->RemoveAura(BLOODSURGE_BUFF);
            if (baseId == HEROIC_STRIKE_1)
                me->RemoveAura(GLYPH_REVENGE_BUFF);
            if (baseId == SHIELD_SLAM_1)
                me->RemoveAura(SWORD_AND_BOARD_BUFF);
            if (baseId == OVERPOWER_1 && !me->HasReactive(REACTIVE_OVERPOWER))
                me->RemoveAura(TASTE_FOR_BLOOD_BUFF);
            if (baseId == BERSERKER_RAGE_1)
            {
                //Improved Berserker Rage: 20 rage bonus when used
                if (me->GetLevel() >= 35)
                    me->CastSpell(me, IMPROVED_BERSERKER_RAGE_EFFECT, true);
            }
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            if (baseId == VIGILANCE_1)
                vigilanceTargetGuid = target->GetGUID();

            //Recklessness: handle charge drop
            AuraEffect const* reck = me->GetAuraEffect(RECKLESSNESS_1, EFFECT_0);
            if (reck && reck->IsAffectingSpell(spell))
                reck->GetBase()->DropCharge();
            //Juggernaught: consume buff
            if (baseId == SLAM_1 || baseId == MORTAL_STRIKE_1)
                if (AuraEffect const* jugg = me->GetAuraEffect(JUGGERNAUGHT_BUFF, 0))
                    if (jugg->IsAffectingSpell(spell))
                        me->RemoveAurasDueToSpell(JUGGERNAUGHT_BUFF);

            if (baseId == THUNDER_CLAP_1 && lvl >= 10)
            {
                if (AuraEffect* clap = target->GetAuraEffect(spellId, EFFECT_1, me->GetGUID()))
                {
                    int32 amount = clap->GetAmount();
                    //Improved Thunder Clap (part 3): 10% extra slow
                    amount += (-10);
                    //Conqueror Thunder Clap Bonus: 50% increased effect
                    if ((GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) && lvl >= 60)
                        amount = amount + amount / 2;

                    clap->ChangeAmount(amount);
                }
            }
            if (baseId == DEMORALIZING_SHOUT_1 && lvl >= 15)
            {
                if (AuraEffect* demo = target->GetAuraEffect(spellId, 0, me->GetGUID()))
                    demo->ChangeAmount(demo->GetAmount() + demo->GetAmount() * 2 / 5);
            }
            if (baseId == BATTLE_SHOUT_1 || baseId == COMMANDING_SHOUT_1 || baseId == DEMORALIZING_SHOUT_1)
            {
                if (Aura* shout = target->GetAura(spellId, me->GetGUID()))
                {
                    //Booming Voice part 2
                    //Buffs duration 10 min for bots
                    uint32 dur = baseId == DEMORALIZING_SHOUT_1 ? shout->GetDuration() * 3 / 2 : 600000;
                    shout->SetDuration(dur);
                    shout->SetMaxDuration(dur);

                    if (baseId == BATTLE_SHOUT_1 || baseId == COMMANDING_SHOUT_1)
                    {
                        if (lvl >= 20)
                        {
                            //Commanding Presence: +25% increased effect (melee AP / HP)
                            AuraEffect* bamm = shout->GetEffect(EFFECT_0);
                            if (bamm)
                                bamm->ChangeAmount(bamm->GetAmount() * 5 / 4);
                        }
                    }
                    else if (baseId == DEMORALIZING_SHOUT_1)
                    {
                        if (lvl >= 15)
                        {
                            //Improved Demoralization Shout: +40% effect
                            AuraEffect* demo = shout->GetEffect(EFFECT_0);
                            if (demo)
                                demo->ChangeAmount(demo->GetAmount() * 7 / 5);
                        }
                    }
                }
            }
            if (baseId == REVENGE_1)
            {
                //zzzOLD Revenge Stun (25% chance): skip players
                if (lvl >= 25 && target->GetTypeId() != TYPEID_PLAYER && urand(1,100) <= 25)
                    me->CastSpell(target, REVENGE_STUN_SPELL, true);
            }
            if (baseId == DISARM_1 && (GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) && lvl >= 25)
            {
                //Improved Disarm part 2
                if (AuraEffect* disa = target->GetAuraEffect(spellId, 1, me->GetGUID()))
                    disa->ChangeAmount(disa->GetAmount() + 10);
            }
            if (baseId == OVERPOWER_1)
            {
                me->ClearReactive(REACTIVE_OVERPOWER);
                //Unrelenting Assault (part 3): reduce spells efficiency on players
                if (lvl >= 45 && (GetSpec() == BOT_SPEC_WARRIOR_ARMS) &&
                    target->GetTypeId() == TYPEID_PLAYER && target->IsNonMeleeSpellCast(false, false, true))
                {
                    CastSpellExtraArgs args(true);
                    args.SetOriginalCaster(me->GetGUID());
                    target->CastSpell(target, UNRELENTING_ASSAULT_SPELL, args);
                }
            }
            if (baseId == REND_1 && lvl >= 15)
            {
                //Glyph of Rending + 6 sec duration
                if (Aura* rend = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = rend->GetDuration() + 6000;
                    rend->SetDuration(dur);
                    rend->SetMaxDuration(dur);
                }
            }
            if (baseId == INTERVENE_1)
            {
                //Glyph of Intervene + 1 bonus charge
                if (Aura* vene = target->GetAura(spellId, me->GetGUID()))
                    vene->SetCharges(vene->GetCharges() + 1);
            }
            if (baseId == PIERCING_HOWL_1)
            {
                //Piercing Howl: 4 sec duraion increase (exclude players controlled)
                if (!target->IsControlledByPlayer())
                {
                    if (Aura* howl = target->GetAura(spellId, me->GetGUID()))
                    {
                        uint32 dur = howl->GetDuration() + 4000;
                        howl->SetDuration(dur);
                        howl->SetMaxDuration(dur);
                    }
                }
            }
            if (baseId == SHIELD_BASH_1 && (GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) && lvl >= 30)
            {
                //Gag Order part 1: silence target
                me->CastSpell(target, GAG_ORDER_DEBUFF, true);
            }
            if (baseId == VICTORY_RUSH_1)
            {
                //Victory rush disable helper
                me->RemoveAura(VICTORIOUS_SPELL);
            }
            if ((baseId == DEVASTATE_1 || baseId == REVENGE_1) &&
                (GetSpec() == BOT_SPEC_WARRIOR_PROTECTION) &&
                lvl >= 55 && urand(1,100) <= 30)
            {
                //Sword and Board: trigger
                me->CastSpell(me, SWORD_AND_BOARD_BUFF, true);
                //Sword And Board: remove Shield Slam cooldown
                ResetSpellCooldown(SHIELD_SLAM_1);
            }

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Stances helper
            if (spellId == BATTLE_STANCE_1 || spellId == DEFENSIVE_STANCE_1 || spellId == BERSERKER_STANCE_1)
            {
                stancetimer = 1000;

                //stance mastery, tactical mastery
                uint32 temprage = 0;
                if (lvl >= 20)
                    temprage = rage > 250 ? 250 : rage;
                else if (lvl >= 15)
                    temprage = rage > 150 ? 150 : rage;

                _stance =
                    spellId == BATTLE_STANCE_1 ? STANCE_BATTLE :
                    spellId == DEFENSIVE_STANCE_1 ? STANCE_DEFENSIVE :
                    spellId == BERSERKER_STANCE_1 ? STANCE_BERSERKER : STANCE_NONE;

                me->SetPower(POWER_RAGE, temprage);
                //Update stength bonus from Improved Berserker Stance
                //if (lvl >= 45)
                //    SetStats(false);
            }

            //Iron Will: -20% duration for stuns and charms
            if ((GetSpec() == BOT_SPEC_WARRIOR_ARMS || GetSpec() == BOT_SPEC_WARRIOR_FURY) &&
                lvl >= 15 && !spell->IsPositive() && (spell->Mechanic == MECHANIC_STUN || spell->Mechanic == MECHANIC_CHARM))
            {
                if (Aura* chun = me->GetAura(spellId, caster->GetGUID()))
                {
                    uint32 dur = chun->GetDuration() - chun->GetDuration() / 5;
                    chun->SetDuration(dur);
                    chun->SetMaxDuration(dur);
                }
            }
            //Glyph of Enduring Victory: +5 sec duration
            if (lvl >= 62 && baseId == VICTORIOUS_SPELL)
            {
                if (Aura* vict = me->GetAura(spellId))
                {
                    uint32 dur = vict->GetDuration() + 5000;
                    vict->SetDuration(dur);
                    vict->SetMaxDuration(dur);
                }
            }
            //Improved Berserker Stance part 2: threat mod
            if (baseId == BERSERKER_STANCE_PASSIVE)
            {
                if (AuraEffect* pass = me->GetAuraEffect(spellId, EFFECT_2))
                    pass->ChangeAmount(pass->GetAmount() - 10);
            }
            if (baseId == RETALIATION_1)
            {
                //Increase duration by 3 sec for bot
                if (Aura* ret = me->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = ret->GetDuration() + 3000;
                    ret->SetDuration(dur);
                    ret->SetMaxDuration(dur);
                }
            }
            if (baseId == VIGILANCE_PROC) //confirmed right place
            {
                //Vigilance: remove Taunt cooldown
                ResetSpellCooldown(TAUNT_1);
            }
            if (baseId == SHIELD_WALL_1)
            {
                //Shield Wall Duration (id: 60175): 3 sec increased Shield Wall duration
                if (Aura* wall = me->GetAura(spellId))
                {
                    int32 dur = wall->GetDuration() + 3000;
                    wall->SetDuration(dur);
                    wall->SetMaxDuration(dur);
                }
            }

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            //Unbridled Wrath
            if ((GetSpec() == BOT_SPEC_WARRIOR_FURY || GetSpec() == BOT_SPEC_WARRIOR_ARMS) &&
                damage && me->GetLevel() >= 15 && me->CanDualWield() &&
                (damageType == DIRECT_DAMAGE || damageType == SPELL_DIRECT_DAMAGE))
            {
                if (roll_chance_f(me->GetPPMProcChance(me->GetFloatValue(UNIT_FIELD_BASEATTACKTIME), 15.f, nullptr)))
                    me->CastSpell(me, UNBRIDLED_WRATH_EFFECT, true);
            }
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

        void SetAIMiscValue(uint32 data, uint32 /*value*/) override
        {
            switch (data)
            {
                case BOTAI_MISC_WEAPON_SPEC:
                {
                    //AXE and MACE specs are handled elsewhere
                    _checkSwordSpec();
                    break;
                }
                default:
                    break;
            }
        }

        void Reset() override
        {
            stancetimer = 0;
            ragetimer = 1500;
            ragetimer2 = 3000;
            shoutCheckTimer = 5000;
            shatterCheckTimer = 5000;
            vigiCheckTimer = 5000;

            vigilanceTargetGuid = ObjectGuid::Empty;

            _stance = STANCE_NONE;

            rageIncomeMult = sWorld->getRate(RATE_POWER_RAGE_INCOME);
            rageLossMult = sWorld->getRate(RATE_POWER_RAGE_LOSS);
            rage = 0;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (stancetimer > diff)                 stancetimer -= diff;
            if (ragetimer > diff)                   ragetimer -= diff;
            if (ragetimer2 > diff)                  ragetimer2 -= diff;
            if (shoutCheckTimer > diff)             shoutCheckTimer -= diff;
            if (shatterCheckTimer > diff)           shatterCheckTimer -= diff;
            if (vigiCheckTimer > diff)              vigiCheckTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_RAGE);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            bool isArms = GetSpec() == BOT_SPEC_WARRIOR_ARMS;
            bool isFury = GetSpec() == BOT_SPEC_WARRIOR_FURY;
            bool isProt = GetSpec() == BOT_SPEC_WARRIOR_PROTECTION;

            InitSpellMap(BATTLE_STANCE_1);
   /*Quest*/lvl >= 10 ? InitSpellMap(DEFENSIVE_STANCE_1) : RemoveSpell(DEFENSIVE_STANCE_1);
   /*Quest*/lvl >= 30 ? InitSpellMap(BERSERKER_STANCE_1) : RemoveSpell(BERSERKER_STANCE_1);

   /*Quest*/lvl >= 10 ? InitSpellMap(TAUNT_1) : RemoveSpell(TAUNT_1);
   /*Quest*/lvl >= 10 ? InitSpellMap(SUNDER_ARMOR_1) : RemoveSpell(SUNDER_ARMOR_1);
            InitSpellMap(INTIMIDATING_SHOUT_1);
            InitSpellMap(ENRAGED_REGENERATION_1);
            InitSpellMap(CHARGE_1);
            InitSpellMap(OVERPOWER_1);
            InitSpellMap(BLOODRAGE_1);
            InitSpellMap(BERSERKER_RAGE_1);
            InitSpellMap(INTERCEPT_1);
            InitSpellMap(CLEAVE_1);
            InitSpellMap(HAMSTRING_1);
            InitSpellMap(INTERVENE_1);
            InitSpellMap(WHIRLWIND_1);
            InitSpellMap(BATTLE_SHOUT_1);
            InitSpellMap(REND_1);
            InitSpellMap(EXECUTE_1);
            InitSpellMap(PUMMEL_1);
            InitSpellMap(SLAM_1);
            InitSpellMap(RECKLESSNESS_1);
            InitSpellMap(RETALIATION_1);
            InitSpellMap(VICTORY_RUSH_1);
            InitSpellMap(THUNDER_CLAP_1);
            InitSpellMap(REVENGE_1);
            InitSpellMap(SHIELD_BLOCK_1);
            InitSpellMap(SHIELD_SLAM_1);
            InitSpellMap(SPELL_REFLECTION_1);
            InitSpellMap(DISARM_1);
            InitSpellMap(SHIELD_WALL_1);
            InitSpellMap(SHIELD_BASH_1);
            InitSpellMap(HEROIC_THROW_1);
            InitSpellMap(MOCKING_BLOW_1);
            InitSpellMap(HEROIC_STRIKE_1);
            InitSpellMap(CHALLENGING_SHOUT_1);
            InitSpellMap(COMMANDING_SHOUT_1);
            InitSpellMap(SHATTERING_THROW_1);
            InitSpellMap(DEMORALIZING_SHOUT_1);

  /*Talent*/lvl >= 30 && isArms ? InitSpellMap(SWEEPING_STRIKES_1) : RemoveSpell(SWEEPING_STRIKES_1);
  /*Talent*/lvl >= 40 && isArms ? InitSpellMap(MORTAL_STRIKE_1) : RemoveSpell(MORTAL_STRIKE_1);
  /*Talent*/lvl >= 60 && isArms ? InitSpellMap(BLADESTORM_1) : RemoveSpell(BLADESTORM_1);

  /*Talent*/lvl >= (isFury ? 20 : isArms ? 70 : 99) ? InitSpellMap(PIERCING_HOWL_1) : RemoveSpell(PIERCING_HOWL_1);
  /*Talent*/lvl >= 30 && isFury ? InitSpellMap(DEATH_WISH_1) : RemoveSpell(DEATH_WISH_1);
  /*Talent*/lvl >= 40 && isFury ? InitSpellMap(BLOODTHIRST_1) : RemoveSpell(BLOODTHIRST_1);
  /*Talent*/lvl >= 50 && isFury ? InitSpellMap(HEROIC_FURY_1) : RemoveSpell(HEROIC_FURY_1);

  /*Talent*/lvl >= 20 && isProt ? InitSpellMap(LAST_STAND_1) : RemoveSpell(LAST_STAND_1);
  /*Talent*/lvl >= 30 && isProt ? InitSpellMap(CONCUSSION_BLOW_1) : RemoveSpell(CONCUSSION_BLOW_1);
  /*Talent*/lvl >= 40 && isProt ? InitSpellMap(VIGILANCE_1) : RemoveSpell(VIGILANCE_1);
  /*Talent*/lvl >= 50 && isProt ? InitSpellMap(DEVASTATE_1) : RemoveSpell(DEVASTATE_1);
  /*Talent*/lvl >= 60 && isProt ? InitSpellMap(SHOCKWAVE_1) : RemoveSpell(SHOCKWAVE_1);
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isArms = GetSpec() == BOT_SPEC_WARRIOR_ARMS;
            bool isFury = GetSpec() == BOT_SPEC_WARRIOR_FURY;
            bool isProt = GetSpec() == BOT_SPEC_WARRIOR_PROTECTION;

            RefreshAura(DEEP_WOUNDS_3, (isArms || isFury) && level >= 24 ? 1 : 0);
            RefreshAura(DEEP_WOUNDS_2, (isArms || isFury) && level >= 23 && level < 24 ? 1 : 0);
            RefreshAura(DEEP_WOUNDS_1, (isArms || isFury) && level >= 22 && level < 23 ? 1 : 0);
            RefreshAura(TWO_HANDED_WEAPON_SPECIALIZATION, isArms && level >= 25 ? 1 : 0);
            RefreshAura(TASTE_FOR_BLOOD3, isArms && level >= 27 ? 1 : 0);
            RefreshAura(TASTE_FOR_BLOOD2, isArms && level >= 26 && level < 27 ? 1 : 0);
            RefreshAura(TASTE_FOR_BLOOD1, isArms && level >= 25 && level < 26 ? 1 : 0);
            RefreshAura(IMPROVED_HAMSTRING, isArms && level >= 15 ? 1 : 0);
            RefreshAura(TRAUMA2, isArms && level >= 36 ? 1 : 0);
            RefreshAura(TRAUMA1, isArms && level >= 35 && level < 36 ? 1 : 0);
            RefreshAura(SECOND_WIND, isArms && level >= 40 ? 1 : 0);
            RefreshAura(JUGGERNAUGHT, isArms && level >= 45 ? 1 : 0);
            RefreshAura(SUDDEN_DEATH, isArms && level >= 50 ? 1 : 0);
            RefreshAura(ENDLESS_RAGE, isArms && level >= 50 ? 1 : 0);
            RefreshAura(BLOOD_FRENZY, isArms && level >= 50 ? 1 : 0);
            RefreshAura(WRECKING_CREW, isArms && level >= 55 ? 1 : 0);
            _checkSwordSpec();

            RefreshAura(ARMORED_TO_THE_TEETH, level >= 10 ? 1 : 0);
            RefreshAura(BLOOD_CRAZE3, (isArms || isFury) && level >= 22 ? 1 : 0);
            RefreshAura(BLOOD_CRAZE2, (isArms || isFury) && level >= 21 && level < 22 ? 1 : 0);
            RefreshAura(BLOOD_CRAZE1, (isArms || isFury) && level >= 20 && level < 21 ? 1 : 0);
            RefreshAura(DUAL_WIELD_SPECIALIZATION, level >= 25 ? 1 : 0);
            RefreshAura(FLURRY5, isFury && level >= 39 ? 1 : 0);
            RefreshAura(FLURRY4, isFury && level >= 38 && level < 39 ? 1 : 0);
            RefreshAura(FLURRY3, isFury && level >= 37 && level < 38 ? 1 : 0);
            RefreshAura(FLURRY2, isFury && level >= 36 && level < 37 ? 1 : 0);
            RefreshAura(FLURRY1, isFury && level >= 35 && level < 36 ? 1 : 0);
            RefreshAura(FURIOUS_ATTACKS, isFury && level >= 45 ? 1 : 0);
            RefreshAura(RAMPAGE, !IAmFree() && isFury && level >= 50 ? 1 : 0);
            RefreshAura(BLOODSURGE, isFury && level >= 50 ? 1 : 0);

            RefreshAura(SHIELD_SPECIALIZATION, isProt && level >= 10 ? 1 : 0);
            RefreshAura(TOUGHNESS, isProt && level >= 20 ? 1 : 0);
            RefreshAura(IMPROVED_SPELL_REFLECTION, isProt && level >= 25 ? 1 : 0);
            RefreshAura(ONE_HANDED_WEAPON_SPECIALIZATION, isProt && level >= 35 ? 1 : 0);
            RefreshAura(IMPROVED_DEFENSIVE_STANCE, isProt && level >= 40 ? 1 : 0);
            RefreshAura(SAFEGUARD, isProt && level >= 45 ? 1 : 0);
            RefreshAura(WARBRINGER, isProt && level >= 50 ? 1 : 0);
            RefreshAura(CRITICAL_BLOCK, isProt && level >= 50 ? 1 : 0);
            RefreshAura(DAMAGE_SHIELD, isProt && level >= 55 ? 1 : 0);

            RefreshAura(GLYPH_HEROIC_STRIKE, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_REVENGE, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_EXECUTION, level >= 24 ? 1 : 0);
            RefreshAura(GLYPH_BLOCKING, level >= 40 ? 1 : 0);
            RefreshAura(GLYPH_VIGILANCE, level >= 40 ? 1 : 0);
            RefreshAura(GLYPH_DEVASTATE, level >= 50 ? 1 : 0);

            RefreshAura(WARRIOR_T10_PROT_4P, level >= 70 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case BLOODRAGE_1:
                case BERSERKER_RAGE_1:
                case BATTLE_SHOUT_1:
                case COMMANDING_SHOUT_1:
                case DEATH_WISH_1:
                    return true;
                case ENRAGED_REGENERATION_1:
                    return me->HasAuraWithMechanic(1u<<MECHANIC_ENRAGED);
                case BATTLE_STANCE_1:
                    return !_inStance(1);
                case DEFENSIVE_STANCE_1:
                    return !_inStance(2);
                case BERSERKER_STANCE_1:
                    return !_inStance(3);
                case SWEEPING_STRIKES_1:
                    return _inStance(5);
                case RETALIATION_1:
                    return _inStance(1);
                case RECKLESSNESS_1:
                    return _inStance(3);
                case SHIELD_WALL_1:
                    return CanBlock() && _inStance(2);
                case SHIELD_BLOCK_1:
                    return CanBlock();
                case LAST_STAND_1:
                case VIGILANCE_1:
                    return true;
                default:
                    return false;
            }
        }

        float GetBotArmorPenetrationCoef() const override
        {
            float bonus = 0.0f;

            if (_inStance(1))
            {
                bonus += 10.f;
                //Warrior T10 4P Bonus (part 1): 6% additional armor penetration in Battle Stance
                if (me->GetLevel() >= 75)
                    bonus += 6.f;
            }

            //Mace Specialization: 15% armor penetration
            if (GetSpec() == BOT_SPEC_WARRIOR_ARMS && me->GetLevel() >= 30)
                if (Item const* weap = GetEquips(BOT_SLOT_MAINHAND))
                    if (ItemTemplate const* proto = weap->GetTemplate())
                        if (proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE || proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE2)
                            bonus += 15.f;

            return bonus + bot_ai::GetBotArmorPenetrationCoef();
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Warrior_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Warrior_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &Warrior_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Warrior_spells_support;
        }

    private:
        bool _inStance(uint8 stance) const
        {
            switch (stance)
            {
                case 1: return _stance == STANCE_BATTLE;
                case 2: return _stance == STANCE_DEFENSIVE;
                case 3: return _stance == STANCE_BERSERKER;
                case 4: return _stance == STANCE_BATTLE || _stance == STANCE_DEFENSIVE;
                case 5: return _stance == STANCE_BATTLE || _stance == STANCE_BERSERKER;
                default: return false;
            }
        }

        void _checkSwordSpec() const
        {
            uint8 level = me->GetLevel();
            bool isArms = GetSpec() == BOT_SPEC_WARRIOR_ARMS;
            Item const* mhWeap = GetEquips(BOT_SLOT_MAINHAND);
            uint32 weaponSubClass = mhWeap ? mhWeap->GetTemplate()->SubClass : uint32(ITEM_SUBCLASS_WEAPON_WAND);
            bool sword = (weaponSubClass == ITEM_SUBCLASS_WEAPON_SWORD || weaponSubClass == ITEM_SUBCLASS_WEAPON_SWORD2);
            RefreshAura(SWORD_SPEC5, isArms && sword && level >= 34 ? 1 : 0);
            RefreshAura(SWORD_SPEC4, isArms && sword && level >= 33 && level < 34 ? 1 : 0);
            RefreshAura(SWORD_SPEC3, isArms && sword && level >= 32 && level < 33 ? 1 : 0);
            RefreshAura(SWORD_SPEC2, isArms && sword && level >= 31 && level < 32 ? 1 : 0);
            RefreshAura(SWORD_SPEC1, isArms && sword && level >= 30 && level < 31 ? 1 : 0);
        }

/*tmrs*/uint32 stancetimer, ragetimer, ragetimer2, shoutCheckTimer, shatterCheckTimer, vigiCheckTimer;
/*misc*/int32 rage;
/*misc*/ObjectGuid vigilanceTargetGuid;
/*stnc*/uint8 _stance;
    };
};

void AddSC_warrior_bot()
{
    new warrior_bot();
}
